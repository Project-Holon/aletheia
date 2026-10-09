# unit_021DB0E4: remaining boundary

Lane r2_01 closed the other boundaries by adding the hidden setters (func_021DB128, func_021DB404,
func_021DB410).

- unit_021DB0E4_p01 | p02 (starts 0x021DB1D4): 0x021DB1C4 to 0x021DB1D3 is a Thumb to ARM linker veneer
  (`bx pc; nop; ldr ip,[pc]; bx ip; .word`): file boundary.
