# Makefile to build build_kdtree and query_kdtree

CXX = g++
CFLAGS  = -g -Wall

default: build_kdtree 

# To create the executable file count we need the object files
# countwords.o, counter.o, and scanner.o:
#
build_kdtree:  build_kdtree.o math.o tree.o importer.o exporter.o
	$(CXX) $(CFLAGS) -o build_kdtree build_kdtree.o math.o tree.o importer.o exporter.o
query_kdtree:  query_kdtree.o math.o tree.o importer.o exporter.o
	$(CXX) $(CFLAGS) -o query_kdtree query_kdtree.o math.o tree.o importer.o exporter.o

build_kdtree.o: build_kdtree.cpp math.h tree.h importer.h exporter.h
		$(CXX) $(CFLAGS) -c build_kdtree.cpp
query_kdtree.o: query_kdtree.cpp math.h tree.h importer.h exporter.h
		$(CXX) $(CFLAGS) -c query_kdtree.cpp
math.o: math.cpp math.h 
	$(CXX) $(CFLAGS) -c math.cpp
tree.o: tree.cpp math.h tree.h
	$(CXX) $(CFLAGS) -c tree.cpp
importer.o : importer.cpp math.h tree.h importer.h
	$(CXX) $(CFLAGS) -c importer.cpp
exporter.o : exporter.cpp math.h tree.h importer.h
	$(CXX) $(CFLAGS) -c exporter.cpp
	
clean: 
	$(RM) count *.o *~