# unit_021E072C.c (ov093)

Split into 2 parts. Each boundary is a linker veneer (`bx pc` ARM veneer, 16 bytes): 0x021E08E0 and 0x021E08F0 (2 veneers). Veneers are not matchable code, so each part is a file boundary. All hidden setters and thunks between parts were written as functions and merged.

Parts, in address order:

- `unit_021E072C_p01.c` 0x021E072C: func_021E072C, func_021E0818, func_021E0838, func_021E0850
- `unit_021E072C_p02.c` 0x021E0900: func_021E0900, func_021E0914, func_021E0920, func_021E0944, func_021E098C, func_021E0998
