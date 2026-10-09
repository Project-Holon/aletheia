# unit_021E7DB0.c (ov093)

Split into 2 parts. Each boundary is a linker veneer (`bx pc` ARM veneer, 16 bytes): 0x021E7DF0. Veneers are not matchable code, so each part is a file boundary. All hidden setters and thunks between parts were written as functions and merged.

Parts, in address order:

- `unit_021E7DB0_p01.c` 0x021E7DB0: func_021E7DB0
- `unit_021E7DB0_p02.c` 0x021E7E00: func_021E7E00, func_021E7E0C, func_021E7E4C
