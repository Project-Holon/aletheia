# intrude_subdisp (ov018)

Round 3 greedy with the ol024 harmonizer: 31 parts to 13, all EXACT. Open boundaries (adjacent parts):
- p01|p02, p03|p04, p05|p06..p07|p08: struct and prototype views of one object (Mon, V3, func_0217D870 arity, func_021802A8 and func_0218034C void * against int); unify with one canonical struct per object.
- p09|p10, p12|p13: DIFF without compile error (stand-in func_02182124 returns through void).
- p10|p11: func_02082D44 const void * against void *. p11|p12: illegal use of void in a stand-in.


Round 4 (r4_ov05): re-ran the harmonizer greedy pass, no pair merges. Current failure per boundary: p01|p02 DIFF; p02|p03 func_0217D870 arity (int argument against ()); p03|p04 struct pointer views; p04|p05, p05|p06, p06|p07 undefined identifier Mon; p07|p08 void * against int; p08|p09 members f78, f58, fA0 missing; p09|p10 const void * against void *; p10|p11 and p11|p12 DIFF; p12|p13 illegal use of void.
