#
# Makefile that builds build_kdtree and query_kdtree
# 
CC = g++

all: build_kdtree query_kdtree

build_kdtree: build_kdtree.cpp exporter.cpp importer.cpp math.cpp tree.cpp exporter.h importer.h math.h tree.h
	$(CC) -o build_kdtree build_kdtree.cpp exporter.cpp importer.cpp math.cpp tree.cpp

query_kdtree: query_kdtree.cpp exporter.cpp importer.cpp math.cpp tree.cpp exporter.h importer.h math.h tree.h
	$(CC) -o query_kdtree query_kdtree.cpp exporter.cpp importer.cpp math.cpp tree.cpp

clean:
	rm -f *.o build_kdtree query_kdtree *~


