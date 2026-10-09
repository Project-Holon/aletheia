# unit_021E65B0.c (ov093)

Split into 3 parts. Each boundary is a linker veneer (`bx pc` ARM veneer, 16 bytes): 0x021E67E4 and 0x021E6908 (1 veneer per boundary). Veneers are not matchable code, so each part is a file boundary. All hidden setters and thunks between parts were written as functions and merged.

Parts, in address order:

- `unit_021E65B0_p01.c` 0x021E65B0: func_021E65B0, func_021E6654, func_021E666C, func_021E66A8, func_021E66C0, func_021E66CC, func_021E6710, func_021E6728
- `unit_021E65B0_p02.c` 0x021E67F4: func_021E67F4, func_021E6800, func_021E6840
- `unit_021E65B0_p03.c` 0x021E6918: func_021E6918, func_021E6924, func_021E6950, func_021E695C, func_021E6988
