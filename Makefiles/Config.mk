algorithms = insertion_sort bubble_sort selection_sort shell_sort quick_sort heap_sort

# we use foreach for the sake of readability
algorithms_files = $(foreach file, $(algorithms), algorithms/$(file))
src_files = algorithms logic
utils_files = utils/print utils/read utils/time
interface_files = interface/input interface/output

commands = sort generate results

out_dir_paths = out/ out/src/ out/src/utils/ out/src/interface/ out/src/algorithms/
results_dir_path = results/
tools_dir_path = tools/out/

clean_targets = *.o sort out tools/out data results build

INC=-I./headers