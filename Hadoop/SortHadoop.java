import java.io.IOException;
import java.util.StringTokenizer;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.Mapper;
import org.apache.hadoop.mapreduce.Reducer;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;

public class Terasort {

  public static class SortMapper extends Mapper<Object, Text, Text, Text>{

    private Text keys = new Text();
    private Text values = new Text();

    public void map(Object key, Text value, Context context) throws IOException, InterruptedException 
    {
      String key_string = value.toString().substring(1,10);
      String value_string = value.toString().substring(10);


        keys.set(key_string);
        values.set(value_string);
        context.write(keys, values);
    }
  }

  public static class SortReducer extends Reducer<Text,Text,Text,Text> {

    public void reduce(Text key, Text value,Context context) throws IOException, InterruptedException 
    {
      context.write(key, value);
    }
  }

  public static void main(String[] args) throws Exception {
    Configuration conf = new Configuration();
    Job job = Job.getInstance(conf, "Terasort");
    job.setJarByClass(Terasort.class);
    job.setMapperClass(SortMapper.class);
    job.setCombinerClass(SortReducer.class);
    job.setReducerClass(SortReducer.class);
    job.setOutputKeyClass(Text.class);
    job.setOutputValueClass(Text.class);
    FileInputFormat.addInputPath(job, new Path(args[0]));
    FileOutputFormat.setOutputPath(job, new Path(args[1]));
    System.exit(job.waitForCompletion(true) ? 0 : 1);
  }
}