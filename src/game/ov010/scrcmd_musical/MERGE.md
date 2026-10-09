# scrcmd_musical.c (ov010)

Translation unit 0215D34C..0215EC54. Now 2 parts (was 8 parts plus 3 folder members); every part is EXACT.

Left to do: p02 and p03 define local struct `Work` with different field sets and one field typed u32 in one part and int in the other (+0 f00), so the two views cannot be unified without casts. Also func_0200A640 returns `Flags *` in one part and `void *` in the other; func_0215DE58 and func_0215E740 have local-struct parameter views.
