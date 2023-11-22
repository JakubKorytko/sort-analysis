paths = $(src_files) $(utils_files) $(interface_files) $(algorithms_files)

out_paths = $(foreach path, $(paths), out/src/$(path).o)

out_dir:
	@mkdir -p $(out_dir_paths)

results_dir:
	@mkdir -p $(results_dir_path)

tools_dir:
	@mkdir -p $(tools_dir_path)

$(paths): %: out_dir src/%.c headers/%.h
	$(info Compiling $@.c...)
	@gcc $(INC) -c src/$@.c -lm -o out/src/$@.o
	$(info Done!)

main: out_dir main.c
	$(info Compiling main.c...)
	@gcc $(INC) -c main.c -lm -o out/main.o
	$(info Done!)