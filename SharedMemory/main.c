#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <time.h>

#define thread_id 1 

void chunkFile();
void sortFile();
void *sort();
void mergeFile();
void *merge();
long num_chunks, chunkid, num_file, num_merge, fileid, newnum_file, newchunkid;  
char command[20];
char file1[20];
char file2[20];


int main(int argc, const char * argv[]) {
    int i;
    
    struct timespec sta_time, end_time; 
    clock_gettime(CLOCK_REALTIME, &sta_time);

    chunkFile();
    sortFile();
    mergeFile();

    clock_gettime(CLOCK_REALTIME, &end_time);
    double startTime = sta_time.tv_sec;
    double endTime = end_time.tv_sec;
    double totalTime = endTime - startTime; // total time in sec

    printf("For 128GB data, the total computing time is %10lf s\n", totalTime);
    
    return 0;
}

//chunk the test by 2MB or other size
void chunkFile() {   
   
    FILE *fp;
    fp = fopen("test", "r+");
	 if (fp == NULL) {
         printf("cannot open the data file.\n");
         exit(1);
      }    

// get the size of the data file
    fseek(fp, 0L, SEEK_END);
    double length=ftell(fp);
    fseek(fp, 0L, SEEK_SET);

//get the number of chunks
    num_chunks = length/2000000;
    
    long i=0;
    char *str = malloc(2000000);
//chunk the file
      while(i<num_chunks){
        char buffer[20];
	snprintf(buffer, 20, "%ld", i+1);

        FILE *newfp = fopen(buffer, "w+");
	fread(str, 2000000, 1, fp);
	fwrite(str, 2000000,1, newfp);        
        fclose(newfp);
        i++;
    }

}


//sort chunked files
void sortFile(){
//sort by threads
    pthread_t pthreads[thread_id];
    int i;
    for(i=0; i<thread_id; i++)
        pthread_create(&pthreads[i],NULL, sort, NULL);
    
    for(i=0; i<thread_id; i++)
        pthread_join(pthreads[i], NULL);

}

void *sort() {

    for (chunkid=0; chunkid <num_chunks;chunkid++)
    {

	snprintf(command, 20, "./sort %ld", chunkid);
        system(command);
    }
    return 0;
}

//merge files
void mergeFile() {
    fileid = 1; 
    num_file = num_chunks;
       
    while(num_file!=1){
        fileid = -1 * fileid;
        num_merge = num_file;
        num_file = 0;
 
//run threads to merge files
        pthread_t pthreads[thread_id];
        int i;
        for(i=0; i<thread_id; i++)
            pthread_create(&pthreads[i],NULL, merge, NULL);
        
        for(i=0; i<thread_id; i++)
            pthread_join(pthreads[i], NULL);
    }

    if(num_file == 1) {
	char filename[20];
	snprintf(filename, 20,"%ld", fileid);
//rename the file output file to "output"
        rename(filename, "output");
        }

}


void *merge() {

for(chunkid=0; chunkid<num_merge;chunkid++){
        newnum_file=num_file+1;
	newchunkid=chunkid+1;
        if(num_merge%2!=0&&newchunkid == num_merge) {
	    snprintf(file2, 20, "%ld", (fileid)*(newnum_file));
	    snprintf(file1, 20, "%ld", -1*(fileid)*(newchunkid));	    
            rename(file1, file2);
            
        }
        else {
	    sprintf(command, "./merge %ld %ld %ld", fileid, num_file, chunkid);            
	    chunkid++;
            system(command);
	}
         num_file++;
    }
    return 0;
}
