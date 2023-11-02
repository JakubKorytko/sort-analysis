all: main

src_files = algorithms logic
utils_files = utils/print utils/read utils/time
interface_files = interface/input interface/output

# we use foreach for the sake of readability
algorithms = insertion_sort bubble_sort selection_sort shell_sort quick_sort heap_sort
algorithms_files = $(foreach file, $(algorithms), algorithms/$(file))

paths = $(src_files) $(utils_files) $(interface_files) $(algorithms_files)
out_paths = $(foreach path, $(paths), out/src/$(path).o)

commands = main generate results 

out_dir:
	@mkdir -p out/src/
	@mkdir -p out/src/utils/
	@mkdir -p out/src/interface/
	@mkdir -p out/src/algorithms/

results_dir:
	@mkdir -p results

tools_dir:
	@mkdir -p tools/out

$(paths): %: out_dir src/%.c headers/%.h
	$(info Compiling $@.c...)
	@gcc -c src/$@.c -o out/src/$@.o
	$(info Done!)

### Available commands ###

main: $(paths) out_dir main.c
	$(info Compiling main.c...)
	@gcc -c main.c -o out/main.o
	$(info Done!)

	$(info Linking...)
	@gcc $(out_paths) out/main.o -o sort
	$(info Done!)

generate: tools_dir
	$(info Compiling generate.c...)
	@gcc tools/generate.c -o tools/out/generate
	$(info Done!)

results: tools_dir results_dir $(paths)
	$(info Compiling results.c...)
	@gcc $(out_paths) tools/results.c -o tools/out/results
	$(info Done!)

clean:
	$(info Cleaning up...)
	@rm -f *.o
	@rm -f sort
	@rm -rf out
	@rm -rf tools/out
	@rm -f data
	@rm -rf results
	@rm -rf build
