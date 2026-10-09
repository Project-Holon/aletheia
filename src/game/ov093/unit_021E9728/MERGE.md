# unit_021E9728.c (ov093)

Split into 4 parts. Each boundary is a linker veneer (`bx pc` ARM veneer, 16 bytes): 0x021E97F8, 0x021E9848, 0x021E9874 (1 veneer per boundary). Veneers are not matchable code, so each part is a file boundary. All hidden setters and thunks between parts were written as functions and merged.

Parts, in address order:

- `unit_021E9728_p01.c` 0x021E9728: func_021E9728, func_021E9730, func_021E9738, func_021E9760, func_021E979C, func_021E97A4, func_021E97BC
- `unit_021E9728_p02.c` 0x021E9808: func_021E9808
- `unit_021E9728_p03.c` 0x021E9858: func_021E9858
- `unit_021E9728_p04.c` 0x021E9884: func_021E9884
