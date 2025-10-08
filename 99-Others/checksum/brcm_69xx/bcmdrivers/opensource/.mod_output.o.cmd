savedcmd_mod_output.o := ld -m elf_x86_64 -z noexecstack --no-warn-rwx-segments   -r -o mod_output.o @mod_output.mod 
