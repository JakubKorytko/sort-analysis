include Makefiles/Config.mk

all: $(commands)
.PHONY = all clean $(commands)

include Makefiles/Pretargets.mk

### Available commands ###

sort: $(paths) out_dir main
	$(info Linking...)
	@gcc $(INC) $(out_paths) out/main.o -lm -o sort
	$(info Done!)

generate: tools_dir
	$(info Compiling generate.c...)
	@gcc $(INC) tools/generate.c -lm -o tools/out/generate
	$(info Done!)

results: tools_dir results_dir $(paths)
	$(info Compiling results.c...)
	@gcc $(INC) $(out_paths) tools/results.c -lm -o tools/out/results
	$(info Done!)

clean:
	$(info Cleaning up...)
	@rm -rf $(clean_targets)
