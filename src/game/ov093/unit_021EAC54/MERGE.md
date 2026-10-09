# unit_021EAC54.c (ov093)

Split into 2 parts. Each boundary is a linker veneer (`bx pc` ARM veneer, 16 bytes): veneers just before 0x021EADA4. Veneers are not matchable code, so each part is a file boundary. All hidden setters and thunks between parts were written as functions and merged.

Parts, in address order:

- `unit_021EAC54_p01.c` 0x021EAC54: func_021EAC54, func_021EAC64, func_021EAC80
- `unit_021EAC54_p02.c` 0x021EADA4: func_021EADA4, func_021EADB4, func_021EADC4, func_021EADD4, func_021EADE4, func_021EADF4, func_021EAE04, func_021EAE14, func_021EAE24, func_021EAE34, func_021EAE44, func_021EAE54, func_021EAE64, func_021EAE74
