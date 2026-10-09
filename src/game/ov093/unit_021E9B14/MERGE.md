# unit_021E9B14.c (ov093)

Split into 2 parts. Each boundary is a linker veneer (`bx pc` ARM veneer, 16 bytes): veneers just before 0x021E9CE0. Veneers are not matchable code, so each part is a file boundary. All hidden setters and thunks between parts were written as functions and merged.

Parts, in address order:

- `unit_021E9B14_p01.c` 0x021E9B14: func_021E9B14, func_021E9B20
- `unit_021E9B14_p02.c` 0x021E9CE0: func_021E9CE0, func_021E9D04
