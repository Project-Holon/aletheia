# tree_ov208_5 (ov208)

## Tree

Root 0x021BF9B0 (1112 B, ten-state proc) is EXACT, along with 17 functions under it: 14 listed callees, one second-level callee each for 0x021C0714 and 0x021C0C50/0C8C, and three unlabelled seeds.

## Verdicts (19 EXACT/EXACT*, 1 DIFF; each shard verified twice, second pass 0 rewritten)

- 021BF9B0 EXACT. The bg-table helpers take `u8` parameters, so the u32 `bg` field is truncated at each call and not once. Case 9 needs its own loop variable (`k`); reusing `j` swaps r4/r5.
- Seeds: 021C0130 (empty; the tail of 0090's extent), 021C2228 (`p[0x414] = 3`) and 021C2234 (empty). The last two sit inside 21D0's extent; 1810 calls them. All three are EXACT.
- Callees, all EXACT or EXACT*: 0090, 0450, 0714, 0740, 0788, 08E8, 0A8C, 0B10, 0C14, 0C50, 0C8C, 1810, 23BC, 2458, 24A4, 24F0, 252C.
  - 0740, 0788: element addresses written as `p + i * 4 + off`.
  - 0C14: the 0xff default is assigned after the inner two calls.
  - 23BC: `+ 0x400u` makes the wrap test unsigned.
- 021C0544 DIFF, 2 bytes. The call result is moved to r1 before the 0xffff compare. Filed in pending with a note. 0x021C4F78 has the same shape.

## Files

src/matched/ov/ov208_func_{021BF9B0, 021C0090, 021C0130, 021C0450, 021C0714, 021C0740, 021C0788, 021C08E8, 021C0A8C, 021C0B10, 021C0C14, 021C0C50, 021C0C8C, 021C1810, 021C2228, 021C2234, 021C23BC, 021C2458, 021C24A4, 021C24F0, 021C252C}.c. Shards: layout/matched/ov208/pkt_ov208_<same addresses>.json. src/pending/ov/ov208_func_021C0544.c. Notes: docs/notes/pkt_ov208_021C0544.c.txt (new) and pkt_ov208_021BD634.c.txt (appended). `manifest --check` is clean. No new idiom file.

## Next lane

021C0134 (656), 021C10B8 (920), 021C1AD4 (568), 021C0544 (the DIFF above), and the near misses 021C53F4, 021BD634 (store reorders tried: 12 and 23 bytes, worse), 021C5CF0, 021C4F78.

## Seeds

0x021C255C: `strh r1, [r0]; bx lr`, inside 252C's extent. No witness found.

## Integrator

Permuter seed 10901 was used on 0544 and found nothing better. Its `--out` must be a file path; a directory fails at write.
