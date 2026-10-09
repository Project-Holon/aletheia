# field_wfbc (ov021): 13 parts (was 14)

Round 6 (g021): hidden function func_021944BC (`return func_0216D684(a, 0x10);`) sat between old p04
and p05. The greedy pass with the harmonizer then joined them (old p04|p05 is now inside p04).
Hidden func_0219361C is in unit_02192CF0 (next TU).

Remaining boundaries (same causes as before, new numbering):
- p01|p02: func_02194038 returns a struct Cell where a u32 stand-in is used; harmonizer emits illegal casts.
- p02|p03: func_02082BCC u32 against void *; Cell views through unsigned char *.
- p03|p04: func_02194418 (u32) against (u32, int).
- p04..p07: u32 against void * / struct pointer arguments (func_0219545C, func_02048AFC, func_0206DF3C).
- p08|p09: void against int return; func_02196030 / func_02196034 argument lists differ.
- p09..p13: Obj_021966B0 / Obj_02196B24 / Obj_02196B94 / Obj_02196D24 / Obj_02196ECC are one heap
  object; `Req` is two different structs.

Note: the p-numbers in the list of remaining boundaries come from the greedy log and use the numbering before this round's renumbering (re-run the greedy driver to refresh the pairs).
