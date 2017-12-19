sudo apt-get update
sudo apt-get install default-jdk

wget http://apache.claz.org/hadoop/common/hadoop-2.7.4/hadoop-2.7.4.tar.gz
tar xvzf hadoop-2.7.4.tar.gz
rm hadoop-2.7.4.tar.gz
mv hadoop-2.7.4/ hadoop



echo "export JAVA_HOME=/usr/lib/jvm/java-8-openjdk-amd64" 
>> ~/hadoop/etc/hadoop/hadoop-env.sh



