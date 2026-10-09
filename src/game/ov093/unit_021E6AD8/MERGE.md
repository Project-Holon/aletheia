# unit_021E6AD8.c (ov093)

Split into 2 parts. Each boundary is a linker veneer (`bx pc` ARM veneer, 16 bytes): 0x021E6CC0. Veneers are not matchable code, so each part is a file boundary. All hidden setters and thunks between parts were written as functions and merged.

Parts, in address order:

- `unit_021E6AD8_p01.c` 0x021E6AD8: func_021E6AD8, func_021E6B14, func_021E6B20, func_021E6BAC, func_021E6BE8, func_021E6BF4
- `unit_021E6AD8_p02.c` 0x021E6CD0: func_021E6CD0, func_021E6CDC
