# game_beacon_search (ov010)

Round 3 (lane r3_ov03): the greedy merge with the call-argument harmonizer was re-run; the parts below are what is left. Every part verifies byte-exact on its own.

Four parts (was 5). Done this round: struct Hdr in p02 is now struct Ent (same layout as p01's
Ent), so func_02164F9C has one prototype and p02 is still EXACT.
p01|p02: with that fix the merge compiles but is DIFF. The first difference is a literal-pool word
that points at func_02164FD0: in the merged build the code before it is 0x14 bytes smaller, the
cause is func_02164F9C (called from the func_0203CF10 loop in p01, defined later in p02), probably
inlined or compiled differently once it shares a file with its caller. Not resolved.
p02|p03: func_021656F8 is declared with `u8 *` in one part and called with `char *` (g_02146940 + 4)
in the other: one prototype needed.
p03|p04: struct Rec and struct S are declared twice with different field sets (bitfield members).

Parts: game_beacon_search_p01.c, game_beacon_search_p02.c, game_beacon_search_p03.c, game_beacon_search_p04.c
