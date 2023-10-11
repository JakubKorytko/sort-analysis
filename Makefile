all: sort

out_dir:
	mkdir -p out/src

src = algorithms logic menu print read time
tools_src = algorithms read time print

paths = $(addprefix out/src/, $(addsuffix .o, $(src)))
tools_paths = $(addprefix out/src/, $(addsuffix .o, $(tools_src)))

$(src): %: out_dir src/%.c headers/%.h
	$(info Compiling $@.c...)
	gcc -c src/$@.c -o out/src/$@.o
	$(info Done!)

main.o: out_dir main.c
	$(info Compiling main.c...)
	gcc -c main.c -o out/main.o
	$(info Done!)
	
sort: $(src) main.o
	$(info Linking...)
	gcc $(paths) out/main.o -o sort
	$(info Done!)

generate:
	$(info Compiling generate.c...)
	mkdir -p tools/out
	gcc tools/generate.c -o tools/out/generate
	$(info Done!)

results: read algorithms print time
	$(info Compiling results.c...)
	mkdir -p tools/out
	mkdir -p results
	gcc $(tools_paths) tools/results.c -o tools/out/results
	$(info Done!)

clean:
	$(info Cleaning up...)
	rm -f *.o
	rm -f *.exe
	rm -rf out
	rm -rf tools/out
	rm -f data
	rm -rf results
	rm -rf build