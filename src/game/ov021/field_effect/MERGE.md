# field_effect (ov021): 17 parts (was 19)

Round 6 (g021): hidden functions func_021AC660 (`func_021C6628(q->f4, q->f8)`) and func_021AC688
(empty leaf) closed old p17|p18 and p18|p19; the last three parts are now p17.
Old p17 (func_021AC62C) still does not join the part before it: `D` is declared as two different structs.

Remaining boundaries, all type conflicts or DIFF:
- p01..p03, p05, p08, p11, p15: merged file is DIFF.
- p04: struct Obj_021A8E78 redefined with different fields; p07: `Entry` redefined; p14, p16, p17: `D`, `T` typedef clashes.
- p06, p09, p10, p12, p13: u32 against struct pointer or array arguments; void against int returns (func_02082BCC, func_021AB37C, func_021ABB54).

Note: the p-numbers in the list of remaining boundaries come from the greedy log and use the numbering before this round's renumbering (re-run the greedy driver to refresh the pairs).
