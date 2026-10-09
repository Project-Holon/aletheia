# comm_player (ov010)

Round 3 (lane r3_ov03): the greedy merge with the call-argument harmonizer was re-run; the parts below are what is left. Every part verifies byte-exact on its own.

11 parts (was 14). The greedy run with the harmonizer joined p01..p03 and p04..p05.
Boundaries left (new numbering, see the part headers for functions):
- p03|p04: struct Obj_02167BFC is missing the bitfield members b724 / b725 in one view.
- later boundaries: `int` passed where a callee takes struct U16Vec * / struct Obj_0216959C * /
  unsigned char * / void *; one is a syntax error from a hoisted prototype; p10, p12, p13 are DIFF
  (inlining or pool changes when merged).
- Struct views with different member names for one object (species/form/item, nature/hpIv/atkIv,
  f0C/f10/f20) and struct Entry with two layouts.
- Gaps where no matched function exists also separate some files.

Parts: comm_player_p01.c, comm_player_p02.c, comm_player_p03.c, comm_player_p04.c, comm_player_p05.c, comm_player_p06.c, comm_player_p07.c, comm_player_p08.c, comm_player_p09.c, comm_player_p10.c, comm_player_p11.c
