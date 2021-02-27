.PHONY: build test clean

build:
	cd metadata-builder	&& \
	npm run compile && \
	node out/src/index.js

test:
	mkdir -p build
	cd build && cmake .. && make -j2 && make test && cd -

clean:
	rm -rf build
	rm -rf metadata-builder/node_modules
	rm -rf metadata-builder/out
