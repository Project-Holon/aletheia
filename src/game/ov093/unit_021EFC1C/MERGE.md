# unit_021EFC1C.c (ov093)

func_021EFCE4 (0x021EFCE4) is its own file here. It follows a 16 byte linker
veneer at 0x021EFCD4 that no function covers, so it cannot join the TU file
unit_021EFC1C.c without breaking the layout (the TU compare is DIFF with it merged).

Verified alone: EXACT. Merge it back into unit_021EFC1C.c when the veneer gap is
modelled (the veneer sits between func_021EFC78 and func_021EFCE4).
