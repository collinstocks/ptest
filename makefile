.PHONY: default
default: build/threads build/intercept.so


$(shell mkdir -p build/)


test: build/threads build/intercept.so
	LD_PRELOAD=build/intercept.so build/threads


build/threads: main.c
	gcc -o $@ $< -lpthread


build/intercept.so: intercept.c
	gcc -o $@ -shared -fPIC $< -ldl


.PHONY: clean
clean:
	rm -rf build/ tmp/
