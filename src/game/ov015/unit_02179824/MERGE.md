# unit_02179824 (ov015)

Round 4 (r4_ov05): 3 parts. p03 now holds the three former uncovered leaves
func_021799FC, func_02179A08 and func_02179A18 (hidden functions) and is merged with the old p04.
Remaining boundaries are linker veneers (ldr r3,[pc]; bx r3; .word target, 8 bytes each),
so they are real file boundaries:
- p01|p02: eight veneers 0x02179860..0x021798A0.
- p02|p03: veneers 0x021798B4..0x021798D4 (plus 2 bytes padding at 0x021798B2).