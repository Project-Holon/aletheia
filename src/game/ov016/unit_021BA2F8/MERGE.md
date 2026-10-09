# unit_021BA2F8 merge status

The unit is 11 part files (unit_021BA2F8_p01.c to p11.c). Every part is EXACT.
The parts cannot become one file: the unit changes compiler and flags along the way.

- p01 (0x021BA2F8..0x021BA804): ../2.0/sp1p2, -O4,p, Thumb. Was 2 parts, merged.
- p02 (0x021BA804): ../2.0/sp1p2 with -ipa file.
- p03 (0x021BABE8): ../2.0/sp1p2, -O4,p.
- p04 (0x021BBB98): 1.1p1.
- p05 (0x021BBBC0): ../2.0/sp1p2.
- p06 (0x021BC500): 1.1p1.
- p07 (0x021BC52C): ../2.0/sp1p2.
- p08 (0x021BC5A0): 1.1p1. Was 2 parts, merged.
- p09 (0x021BC5D4): ../2.0/sp1p2. Was 2 parts, merged.
- p10 (0x021BC7F0): 1.1p1.
- p11 (0x021BC804): ../2.0/sp1p2.

Adjacent parts with the same compiler and flags are already merged.
