all: debug

debug: 
	cd scripts; ./install.sh

clean:
	$(RM) -r build/ lib_desparbes/
