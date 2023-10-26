all: sort

out_dir:
	mkdir -p out/src
	mkdir -p out/src/algorithms

src = algorithms logic menu print read time
paths = $(addprefix out/src/, $(addsuffix .o, $(src)))

algorithms = insertion_sort bubble_sort selection_sort shell_sort quick_sort heap_sort
algorithms_paths = $(addprefix out/src/algorithms/, $(addsuffix .o, $(algorithms)))

tools_src = algorithms read time print
tools_paths = $(addprefix out/src/, $(addsuffix .o, $(tools_src)))

$(src): %: out_dir src/%.c headers/%.h
	$(info Compiling $@.c...)
	gcc -c src/$@.c -o out/src/$@.o
	$(info Done!)

$(algorithms): %: out_dir src/algorithms/%.c headers/algorithms/%.h
	$(info Compiling $@.c...)
	gcc -c src/algorithms/$@.c -o out/src/algorithms/$@.o
	$(info Done!)

main.o: out_dir main.c
	$(info Compiling main.c...)
	gcc -c main.c -o out/main.o
	$(info Done!)
	
sort: $(algorithms) $(src) main.o
	$(info Linking...)
	gcc $(algorithms_paths) $(paths) out/main.o -o sort
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