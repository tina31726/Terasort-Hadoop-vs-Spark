from pyspark import SparkContext
import sys

sc = SparkContext("local","Spark Sort")
        # Read input and output path

lines = sc.textFile("hdfs:///user/test/part-m-00000")
words = lines.flatMap(lambda line: line.split("\n"))
wordPairs = words.map(lambda word:((word[:10]).encode('utf-8'),(word[10:]).encode('utf-8')))
counts = wordPairs.sortByKey().reduce(lambda a,b:a+b)
sc.parallelize(counts).saveAsTextFile("hdfs:///user/terasort-output")