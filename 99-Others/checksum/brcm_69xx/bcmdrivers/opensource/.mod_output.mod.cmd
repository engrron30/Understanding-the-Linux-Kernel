savedcmd_mod_output.mod := printf '%s\n'   mod_entry.o | awk '!x[$$0]++ { print("./"$$0) }' > mod_output.mod
