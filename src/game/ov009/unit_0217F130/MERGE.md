# unit_0217F130 (ov009)

Two parts, address order:

- `unit_0217F130_p01.c` (func_0217F130, func_0217F150)
- `unit_0217F130_p02.c` (func_0217F1CC .. func_0217F21C)

Boundary is real: the 12 bytes at 0x0217F1C0 are a linker veneer
(`ldr ip, [pc]; bx ip` plus the pool word 0x0217EAE0 = func_0217EAE0). No C function
can produce them, and the compiler places func_0217F1CC straight after func_0217F150's
pool, so every later function would move by 12 bytes. The files stay split here.
