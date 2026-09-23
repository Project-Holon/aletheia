# Wave 13, bitmap families lane

**Result:** 7 of the 10 target functions are closed (4 EXACT, 3 EXACT*). A new unit also closes 7 unlabelled accessors, so 14 functions in total. bmp_menulist.c has no open function left. Nothing was committed.

## Filed in src/matched (all re-verified; every shard passes `manifest --verify`)

| file | packet | verdict | what closed it |
|---|---|---|---|
| unit_02020268.c (8 fns, 0x02020268..0x02020408, tu) | pkt_020202CC | EXACT | Written from scratch. It matched on the first compile. |
| func_02020970.c | pkt_02020970 | EXACT | All the scalar parameters are u8. The skip row is a `goto` to the top of the body. The switch arm is `case 0: default: return 1;`. |
| func_020200CC.c | pkt_020200CC | EXACT | The 2021 note misread the image: the f1Amid==2 arm tests **0x200/0x100** (L/R), not 0x40/0x80. Case 0 and default share one arm. |
| func_02020780.c | pkt_02020780 | EXACT* (2 bytes of padding) | Re-derived, because no source survived. `col` is an int, `rows` is read inside each arm, and the declaration order is ncol,col,rows,mid,row (the permuter found the row<->ncol swap). |
| func_02020408.c | pkt_02020408 | EXACT* (padding) | The colour is a masking macro `((l&0x1f)<<10)\|((s&0x1f)<<5)\|(b&0x1f)`. The image's fourth arm reads the override bytes; this looks like a slip in the original and is reproduced as written. |
| func_0202055C.c | pkt_02020408 | EXACT* (padding) | Three misreads fixed: the loop hook argument is the item value, not 0; the last argument of func_02020CA0 uses func_020437DC's width/8; x is an int. The permuter's `step:u8->int` then closed it. |
| func_02025A9C.c | pkt_02025A9C | EXACT | The 0x00200010 arm sets `mode = 0` itself and is written first. It is cross-jumped onto default. Found by a sweep of arm orders. |

**0x020202CC is not a function.** It is the middle of func_02020298, which is now in unit_02020268. It was seeded from a pending header that named the wrong tail-call target (see docs/notes/pkt_02022940.c.txt). The unit covers that range.

## Still open (DIFF, notes appended)

- **0x020255A0:** now 8 bytes out, down from 16. The first "scheduling swap" was really the width call reading `g->bmp`, the field it had just stored. Two single-instruction swaps are left. Hill (309 tried) and anneal (2000) both stayed flat at 8.
  - Note: docs/notes/pkt_020255A0.c.txt
  - Marker: `/* best source, 364 bytes against 364, 8 concrete bytes out, dsi/1.1p1 */`
- **0x0204427C:** unchanged at 888/888 and 276 out.
  - New reading: the two loops own disjoint stack slots.
  - Tried: block-scoped locals per arm, which give 896/507.
  - Tried: a focused hill run, which reached 197, but only through temporaries (noise). Frame and push are still one register short.
  - Note: appended to docs/notes/pkt_02043B98.c.txt.
- **0x020454E0:** skipped under your rule. It is a 2-byte parameter-copy allocator tie, and three lanes plus the permuter have already tried every lever.

## Docs

- **New:** docs/families/bmp_menulist.h. It documents the 0x50-byte list object and the 8-byte item record (value -3 means a separator), and gives every prototype and the colour macro.
- **Updated:** docs/families/bmp_oam.h, the entries for A9C (now EXACT) and 5A0 (now 8 bytes).
- **Notes:** each closed function's note now ends with a CLOSED line.

## Integrator: seed

- Add these function starts (all Thumb, all inside unit_02020268): 0x02020268, 0x02020298, 0x020202EC, 0x020202FC, 0x02020314, 0x02020324, 0x02020344, 0x02020350.
- Remove the bogus start 0x020202CC from layout/function_starts.txt (line 387).

## Manifest verify

These all pass: pkt_020202CC, pkt_02020970, pkt_020200CC, pkt_02020780 (EXACT*), pkt_02020408 (7 entries, two of them EXACT*), pkt_02025A9C.
