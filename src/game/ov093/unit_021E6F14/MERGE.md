# unit_021E6F14.c (ov093)

Split into 2 parts. Each boundary is a linker veneer (`bx pc` ARM veneer, 16 bytes): 0x021E6F7C. Veneers are not matchable code, so each part is a file boundary. All hidden setters and thunks between parts were written as functions and merged.

Parts, in address order:

- `unit_021E6F14_p01.c` 0x021E6F14: func_021E6F14, func_021E6F30, func_021E6F3C
- `unit_021E6F14_p02.c` 0x021E6F8C: func_021E6F8C, func_021E6F98, func_021E6FBC
