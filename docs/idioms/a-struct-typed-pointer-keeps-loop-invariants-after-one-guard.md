# A struct-typed pointer keeps loop invariants after one guard

summary: reading fields through a struct-typed object pointer (and `p->cnt[i]++`) gives the original's single guard; raw `char *` plus byte offsets duplicates the guard, hoists invariants between the guards and CSEs the else-arm load.

Found in: src/matched/ov/ov055_func_021F3F30.c, src/matched/ov/ov055_func_021F405C.c

Spelling: declare `struct S { short lim[6]; u8 n; u8 pad[13]; E ent[2]; short cnt[2]; }` and take
`S *p`, updating counters as `p->cnt[i]++` (or `+= 1`).

Other spellings: `*(short *)(p + off)` accesses gave a doubled guard, hoisted the invariant
loads between the two guards, and reused the first load in the else arm.
