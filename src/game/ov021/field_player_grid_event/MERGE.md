# field_player_grid_event (ov021)

Two files remain: `field_player_grid_event_p01.c` (021BEE74 on, now ends with the two hidden
functions func_021C0808 and func_021C080C, `movs r0,#1; bx lr` each, so the old 8-byte gap is covered)
and `field_player_grid_event_p02.c` (021C0810 onward).

Round 4 (r4_ov06): with the hidden functions the two files no longer have uncovered code between
them, but the merge is still DIFF. The first differing bytes are not at the join: they are at
+073C of the merged file (021BF5B0, the literal pool word of func_021BF58C, which holds the
address of func_021BF694). In the merged build that pool word is not where it is in p01 alone, so
something in p02 changes how that pool is laid out (func_020124E8 / func_020122C0 prototypes
differ between the parts and the harmonizer casts them). Next step: give func_020124E8 and
func_020122C0 one prototype (the definition's) in both parts without casts, then retry.

Notes: func_021BF564 is declared and defined without a parameter list (`void func_021BF564()`),
because callers in the TU pass one argument and others pass none. func_021C0598 takes an unused
fourth parameter (`int unused`) because a caller passes four arguments.
