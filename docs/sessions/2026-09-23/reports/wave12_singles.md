# Wave 12: upper-half singles and pairs

**Result: 9 of 13 rows closed (8 EXACT and 1 EXACT\*). 3 rows are still DIFF. The pending 0x02062B30 is also closed.** Nothing is committed.

## Closed

| addr | size | packet | compiler | file | what closed it |
|---|---|---|---|---|---|
| 0x02091E44 | 448 | pkt_02091AE8 | 1.1p1 | src/matched/func_02091E44.c | Status is EXACT\* because the listing extent is still 4 bytes. Two changes: the f08 state is a bitfield member that is assigned (`p->f08.mode = 2/0`), and the window test is written as a disjunction whose then-arm is the kept `b`. |
| 0x020698F8 | 460 | pkt_020694D8 | ../2.0/sp2 | src/matched/func_020698F8.c | Three levels of `static inline` helper. The leaf helpers are written `if (r && cond) return 1; return 0;`. |
| 0x02062D4C | 436 | pkt_02062D4C (the worklist id; the packet was given as pkt_02062D08) | ../2.0/sp2 | src/matched/func_02062D4C.c | NitroSystem NNS_G2dTickAnimCtrl shape with inline helpers. The loop test is the if-return form. The edge test binds only `cur` to a local. |
| 0x020754C4 | 156 | pkt_02075404 | ../2.0/sp2 | src/matched/func_020754C4.c | The permuter found the declaration order i, e, j. The slot index is `int` in the callee prototypes too (func_02072DE8's first parameter). |
| 0x02075698 | 252 | pkt_02075404 | ../2.0/sp2 | src/matched/func_02075698.c | Written first time as a sibling of func_02075794. |
| 0x02062688 | 336 | pkt_02062688 | ../2.0/sp2 | src/matched/func_02062688.c | Under 2.0 the note's a9 spelling emits the `ldmib`. Also needed: a `void *` frame-data field, natural `nodes[k]` indexing, and a guarded do-while for the inner walk. |
| 0x02062B30 | 52 | pkt_02062688 | ../2.0/sp2 | src/matched/func_02062B30.c | The positive accessor spelling. The pending file is removed. |
| 0x02060CD0 | 352 | pkt_02060C5C | ../2.0/sp2 | src/matched/func_02060CD0.c | The plain NitroSystem free-list search loop. No volatile is needed. |
| 0x02061EB8 | 320 | pkt_02061D0C | ../2.0/sp2 | src/matched/func_02061EB8.c | Four changes: `if (alignment > 1)` comes first, the locals have no initialisers, NitroSystem inline helpers, and the permuter found the mask spelling and declaration order. |

The recurring finding is that 1.1p1 "walls" in this range were often the wrong compiler. Seven of the closures pin to ../2.0/sp2, and each one is also EXACT under sp2p2.

## Still DIFF (appended to the notes, with best source and permuter line)

- **0x02051C88**: 352/352, 19 bytes out, 1.1p1. One new size lever: remove the (s32) casts so both compares are unsigned. The remaining residue is an ip/lr swap between the slot index and the slots base. Permuter hill and anneal are both flat. Details are in docs/notes/pkt_02051C88.c.txt.
- **0x02071104**: 124/124, 6 bytes out, sp2. This reproduces the previous lane's result. Six new spellings were measured and none helped.
- **0x020712A8**: 184/184, 4 bytes out under every front end. The permuter hill is flat, and every single-expression spelling folds. Both of these rows are in docs/notes/pkt_02071104.c.txt.

## Headers

- Updated: cluster_02091AE8, 020694D8, 02062688 (its "no pin" claim is withdrawn), 02060C5C, 02061D0C and 02070B64.
- New: docs/families/cluster_02062D08.h, cluster_02075404.h and cluster_02051B84.h.

## Shards verified

pkt_02091AE8, pkt_020694D8, pkt_02062D4C, pkt_02075404, pkt_02062688, pkt_02060C5C and pkt_02061D0C are all EXACT. The one exception is 0x02091E44, which is EXACT\*.

## For the integrator

- The seed for 0x02091E44 is in function_starts, but the listing still labels 0x02091E48. Regenerate it so the extent becomes 448.
- src/matched/func_02092004.c (pkt_02091D38) now verifies as EXACT, because func_02091E44 is its witness. Re-verify pkt_02091D38.
- pkt_02062D08 has no worklist or shard of its own. I filed 0x02062D4C under the worklist's pkt_02062D4C.

## Integrator: seed

None new. 0x02091E44 is already seeded; see the first item above.
