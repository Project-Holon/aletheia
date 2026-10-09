# unit_021B1498 (ov013)

7 parts (from 7 plus 4 folder members, none merged). Left: d_021B4BB8 and d_021B60D8 views differ, func_02087988 and func_0208799C prototypes differ between members, struct Node and Sess defined two ways, p01+p02 and p03+p04 give code DIFF.

Round 4 (r4_ov05): greedy pass, per boundary: p01|p02 DIFF; p02|p03 and p03|p04 Node_ADDR structs differ; p04|p05 and p05|p06 Node/Sess redefined; p06|p07 Sess against Ctx. d_021B60D8 and g_021B60D8 (same address) and d_021B4BD0 and g_021B4BD0 are declared in different parts under both names; one canonical Sess, Pool, Node, Chan, Stats block is needed.
