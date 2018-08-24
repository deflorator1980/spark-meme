name := "spark-meme"

version := "1.0"

scalaVersion := "2.11.8"

libraryDependencies ++= Seq(
    "org.apache.spark" %% "spark-core" % "2.3.1" % "provided",
    "org.apache.spark" %% "spark-sql" % "2.3.1"
)

