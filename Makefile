.PHONY: test

all: debug

test:
	cd build/debug; make test

debug: 
	cd scripts; ./install.sh

clean:
	$(RM) -r build/ lib_desparbes/
