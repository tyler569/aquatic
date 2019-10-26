
.PHONY: all
all:
	mkdir -p build
	cd build; cmake ..
	make -C build

.PHONY: clean
clean:
	[ -d "build" ] && make -C build clean

