CXX = g++
CFLAGS = -g -Wall -std=c++11
NOMAIN = product.o
MAINOBJ = main.o
TESTOBJ = test.o
OBJS = $(MAINOBJ) $(NOMAIN)
TESTOBJS = $(TESTOBJ) $(NOMAIN)


a.out: $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o $@

$(MAINOBJ): main.cc product.h
	$(CXX) $(CFLAGS) -c main.cc -o $@

product.o: product.cc product.h
	$(CXX) $(CFLAGS) -c product.cc -o $@


test: $(TESTOBJS)
	$(CXX) $(CFLAGS) $(TESTOBJS) -o $@

$(TESTOBJ): test.cc
	$(CXX) $(CFLAGS) -c test.cc -o $@


.PHONY: clean
clean:
	rm -rf $(NOMAIN) $(MAINOBJ) $(TESTOBJ) a.out
