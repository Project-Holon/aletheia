# unit_021DA624: remaining boundary

Lane r2_01 closed the other boundaries by adding the hidden setters (func_021DA838, func_021DA89C,
func_021DABE8, func_021DAD20, func_021DAED8, func_021DB000) and one hidden predicate (func_021DAEC4).

- unit_021DA624_p01 | p02 (starts 0x021DAEAC): 0x021DAE94 to 0x021DAEAB holds two Thumb call thunks
  (`ldr r1,[pc,#4]; ldr r3,[pc,#8]; bx r3; nop; .word` to func_021D7320 and `ldr r3,[pc]; bx r3; .word`
  to func_021D7324). They are linker-style veneers, not compilable C: file boundary.
