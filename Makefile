
CFLAGS= -fPIC
CXXFLAGS= -fPIC

aquatic: aquatic.o open_tun.o
	c++ -o $@ $^

.PHONY: clean
clean:
	rm -f *.o aquatic
