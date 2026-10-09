# unit_021E7164.c (ov093)

Split into 3 parts. Each boundary is a linker veneer (`bx pc` ARM veneer, 16 bytes): 0x021E7260 (p01/p02) and 0x021E72D4, 0x021E72E4 (p02/p03). Veneers are not matchable code, so each part is a file boundary. All hidden setters and thunks between parts were written as functions and merged.

Parts, in address order:

- `unit_021E7164_p01.c` 0x021E7164: func_021E7164, func_021E71D8, func_021E71E4
- `unit_021E7164_p02.c` 0x021E7270: func_021E7270, func_021E727C
- `unit_021E7164_p03.c` 0x021E72F4: func_021E72F4, func_021E7300, func_021E7320, func_021E732C, func_021E737C, func_021E7388, func_021E7414, func_021E7420
