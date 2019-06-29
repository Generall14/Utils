KAT = ../
INCL_SRCT = KWTest.cpp KWTester.cpp
INCL_OBJ = $(INCL_SRCT:.cpp=.o)
INCL_H = $(INCL_SRCT:.cpp=.hpp)
INCL_SRC := $(addprefix $(KAT), ${INCL_SRCT})
VPATH = $(KAT)
INCL_PATH = "../../../KWCLib/KWCLib/KWCLib/include/"
LIB_PATH = "../../../KWCLib/KWCLib/KWCLib/library/"

#CXXFLAGS = -std=c++11
CXXFLAGS += -I$(INCL_PATH) -L$(LIB_PATH)

#.cpp.o: ../LF_SSNu.hpp
%.o: %.cpp %.hpp
	$(CXX) -c $(CXXFLAGS) $(CPPFLAGS)$<
	cp $@ objs/$@

%.so: %.o
	$(CXX) -shared -o $@ $<
	cp $@ library/lib$@

%.a: %.o
	ar rcs $@ $<
	cp $@ library/lib$@

%.dll: %.o
	$(CXX) -shared -o $@ $<
	cp $@ library/lib$@

all: main libso liba libdll
	cp $(addprefix $(KAT), ${INCL_H}) ./include/

main: main.o $(INCL_OBJ) $(INCL_H)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o main main.o $(INCL_OBJ) -lKWCLib
	cp ./main ../main

libso: $(INCL_SRCT:.cpp=.so)

liba: $(INCL_SRCT:.cpp=.a)

libdll: $(INCL_SRCT:.cpp=.dll)

clean:
	rm -r $(shell ls -I "Makefile")
	mkdir library objs include
