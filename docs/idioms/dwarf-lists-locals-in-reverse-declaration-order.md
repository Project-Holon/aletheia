# DWARF lists a function's locals in reverse declaration order

summary: when a vendor object carries DWARF, declare the locals in the reverse of the order `sdkobj.py` prints them; the forward order swaps callee-saved registers or stack slots.

Found in: src/matched/ov016_func_021B7774.c (0x021B7774), src/matched/ov016_func_021B83FC.c (0x021B83FC), src/matched/ov016_func_021B6D8C.c (0x021B6D8C)

`tools/sdkobj.py` prints the `variable` entries of a vendor object's DWARF in the
order the compiler emitted them, which for the Metrowerks 3.0.0.126 front end
(../2.0/sp1p2) is the reverse of the source declaration order. Declaring them in
the printed order gives the right instructions with two registers swapped: GetWPAData
(DWARF: `length r5, Data r4`) came out with `length` in r4 and `Data` in r5 until the
declarations were written `Data; length;`; Set_WLLA_BSS_INFO (`support_rate_count r1,
i r0`) likewise. AOSS_seq_data_copy (DWARF: `ret, aes, tkip, wep104, wep40, ptr`)
closed with `ptr, wep40, wep104, tkip, aes`, after the forward order had swapped the
two stack-held pointers and two callee-saved registers.

The register and frame offset DWARF prints next to each local confirm the result:
after reversing, every local lands where the DWARF says.
