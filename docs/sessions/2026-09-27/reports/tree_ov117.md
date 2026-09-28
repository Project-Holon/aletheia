# tree_ov117 (ov117, ov118, ov111), relaunch

## Salvaged from the cut run (all re-verified; shards verified twice, second pass 0 rewritten)

- EXACT, src/matched: ov117_func_021D434C, 43C8, 4434, 49C4, 4A48; ov118_func_021D434C, 43C8, 4434, 49C4. Shards pkt_ov117_* and pkt_ov118_* for the same addresses.
- src/pending/ov117_func_021D49F4.c: still MATCH. It is blocked on 0x02015FBC, an unlabelled arm9 Thumb leaf.
- src/pending/ov117_func_021D4CE8.c (DRAFT, 8 bytes out) is now EXACT and in src/matched. The fix was that func_0202208C takes (0, 1, 1, ...), not (0, 0, 1, ...).

## Trees (all roots are real game code)

- ov117 root 0x021D4CE8: real extent 1268 B, the rest of the listing is rodata. EXACT.
- ov118 roots 0x021D4C40 (2224) and 0x021D5BB8 (2364): both EXACT. Each is a frame-script state step. What closed them was `v.x *= 1.2;` in place of `v.x = v.x * 1.2;`, which puts the operands of _dmul in the original order. That is the lever already documented in the soft-float compound idiom.
- ov111 root 0x021C842C: real code is 256 B, the rest is data. EXACT. Its callees 83DC and 8414 (EXACT*) are also done. New idiom: docs/idioms/an-inline-helper-writing-through-a-field-pointer-keeps-offset-constants-apart.md. I ran the permuter once, seed 7801; it gave no gain.

## New EXACT (51)

- ov117 (10): 4240, 4290, 449C, 4520, 4544, 4664, 4820, 48F0, 4B88, 4CE8. These cover every open ov117 function except 4BF4.
- ov118 (38): 4C40, 5BB8, 4A34, 4A94, 5930, 5990, 572C, 5888, 4AB4, 59B0, 4C08, 4C20, 5B74, 5B98, 7100, 7118, plus twins of ov117 functions filed under the ovNNN naming: 55AC, 5628, 5694, 56FC, 5748, 4240, 64F4, 4290, 54F0, 6544, 449C, 4520, 4544, 4664, 4820, 48F0, 6750, 67D4, 67F8, 6918, 6AD4, 6BA4.
- ov111 (3): 83DC, 8414, 842C.

## MATCH, in src/pending (all bytes right)

- ov117_func_021D4BF4: blocked on 0x021E3E40, an unlabelled ov119 Thumb tail-call wrapper that the listing shows as pool words.
- ov118_func_021D4A54, 58F0, 5950, 6E6C, 6ECC (MATCH*): all blocked on 0x02051A34, an unlabelled arm9 function.

## Seeds (unlabelled, each with a witness site)

- 0x02015FBC (arm9; witness ov117 0x021D49F4)
- 0x02051A34 (arm9; witness ov118 0x021D4A54)
- 0x021E3E40 (ov119; witness ov117 0x021D4BF4)

## Remaining for the next lane

- ov118: 4B14, 5A60, 6F2C, 6F90.
- ov111: about 135 open functions (0x021C3CC0..0x021C8414).
- ov118_func_021D6CC4.c is an old tracked DIFF, not touched.

## Integrator

Stage every file listed by `git status` matching `ov11[178]` plus the new idiom file. `manifest --check` reports only one duplicate, in ov010 (pkt_021605C0 and pkt_ov010_021605C0), which belongs to another lane. Regenerate the idiom index.
