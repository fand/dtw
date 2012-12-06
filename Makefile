# Makefile
# 2012/11/26
# fand

CC      = g++
OBJS    = file.o FastDtw.o dtw.o watch.o


# 生成規則部
dtw.exe: $(OBJS)           # $(OBJS) → "sub1.o sub2.o"
	$(CC) -g -o $@ $(OBJS)    # $@ → "a.out", $(CC) → "cc"

.cpp.o:
	$(CC) -c $<


.PHONY: clean
clean:
	rm -f *.o
