# Wave 10, bmp.c third lane: report

**Result: 8 new EXACT, 2 still DIFF, nothing committed.**

## Filed EXACT (src/matched, dsi/1.1p1 -O4,p, ARM, full headers)

| address | size | file | shard |
|---|---|---|---|
| 0x02043B98 | 948 (940 + pool) | src/matched/func_02043B98.c | pkt_02043B98 |
| 0x02043F4C | 816 (808 + pool) | src/matched/func_02043F4C.c | pkt_02043B98 |
| 0x020445F4 | 864 | src/matched/func_020445F4.c | pkt_020445F4 |
| 0x02044954 | 668 | src/matched/func_02044954.c | pkt_020445F4 |
| 0x02044BF0 | 240 | src/matched/func_02044BF0.c | pkt_020445F4 |
| 0x02044CE0 | 168 | src/matched/func_02044CE0.c | pkt_020445F4 |
| 0x02044D88 | 308 | src/matched/func_02044D88.c | pkt_020445F4 |
| 0x02044EBC | 168 | src/matched/func_02044EBC.c | pkt_020445F4 |

Gate: `manifest --verify --shard pkt_020445F4` gives all 11 entries EXACT, the 6 new ones plus the 5 already there. `manifest --verify --shard pkt_02043B98` creates the shard with 2 entries, both EXACT. None of the functions have relocations.

Data-flow checks on every accepted source:
- The signed left/top clipping guards (`cmp/cmpge/blt`) are kept in all four fill workers.
- The clip helper in the kind != 2 blits keeps signed origin tests and unsigned extent tests, as the image does (bge/bgt against movhi/subhi).
- No `--types` narrowing was adopted anywhere. The permuter's `srow: s32 -> u8` (F4C) and `sTileY -> u16` would have changed semantics, so both were rejected.

## Still DIFF (appended to the existing notes)

- **0x02044F64**: 292/292 bytes, 6 out, unchanged. The residue is one swapped f04/f06 load-register pair.
  - Permuter: `--explain`, then hill 800 `--types` (0 of 248 single mutations improve), then anneal 2000 `--types` (flat).
  - 11 hand spellings also measured; none beat 6.
  - Section added to docs/notes/pkt_020445F4.c.txt, with the best-source marker and the permuter line.
- **0x0204427C**: 888/888 bytes, 277 out. The clip and the plain loop reproduce. The residue is the keyed loop's spill choice: the image spills the source in-tile row and uses a 0x28 frame.
  - Permuter: hill 500 and hill 1500, plateau at 274 via a noise `copy()` mutation, which was not adopted.
  - New section in docs/notes/pkt_02043B98.c.txt, with the best source.

## Levers, now recorded in docs/families/bmp.h

1. **Integer address sum (opened six workers).** The pixel address is one integer sum over `(u32)s->pixels`, evaluated inside the guarded body. Only the tile-row mask goes into a function-scope local.
   - This form stops the compiler folding the tile-row product and the in-tile row into one `mla`.
   - Every "missing spill / tenth register" near-miss from earlier passes came from that fold. Pointer or subscript spellings, and per-row locals, all allow it (CE0: 81 → 0).
2. **`p += row` as a separate statement** where the image addresses `[p, row]` (BF0: 6 → 0). Written as a fifth term of the sum, it gives `[row, p]` instead.
3. **One tile-row local per address per loop.** The two-loop blits need four; sharing them across the plain and keyed loops costs about 150 bytes.
4. **Clip helper** shared by the kind != 2 blits:
   - It is an inlined `static inline s32 ClipRect(src, const dst, s32 *x, *y, *dx, *dy, u32 *w, *h)`.
   - `const` on dst forces the post-clip re-read of dst->width. Without it the function is 4 bytes short.
   - `*h` must be read before `*w` (88 out the other way).
5. **Fresh temporary in the kind == 2 clip.** Reusing xend/yend for the difference puts the reused variable first in the conditional add. A fresh `t` fixes it; on 954 it only works together with u16 x/y parameters.
6. **Per-function levers:**
   - BF0: `hi = value << 4` assigned inside the guarded body. LICM then hoists the shift out of both loops but the u8 narrowing out of only one, which produces the image's two-slot frame.
   - D88: u16 `hi`/`lo` locals of a u32 halfword read; the even arm written first; `right` clamped before `bottom` is computed.
   - 954: in the odd arm, `d -= 1` comes before the loads.
   - B98: the store is written `(v << sh) | (*p & (0xf0 >> sh))`, and the source is read through a pointer `q` computed before `p`.
   - F4C: the keyed loop reads the source through a pointer `q` and tests `*q`, and the loop-header increment order clears a three-register rotation.

## Prototype corrections, all proven by EXACT sources (bmp.h updated)

- **Surface order.** The blit workers read r0 and write r1, so the first surface is the source. The dispatcher's (dst, src) names were never evidenced.
- **Key type.** The key is u16 on the worker side in all five keyed workers.
- **Fill workers:** `(b, s32 x, s32 y, s32 w, u16 h, value)`. The value is u32 in BF0 (word load) and u8 in CE0, D88 and EBC.
- **0x0204427C:** `(src, dst, s32, s32, s32, s32, u32, u32, u16 key, u8 pal)`. Here the key is only a mode switch: 0xFFFF stores every pixel, anything else skips nibble 0.

## Files changed (not committed)

- **New sources:** src/matched/func_02043B98.c, func_02043F4C.c, func_020445F4.c, func_02044954.c, func_02044BF0.c, func_02044CE0.c, func_02044D88.c, func_02044EBC.c
- **Shards:** layout/matched/arm9/pkt_020445F4.json (rewritten by verify), layout/matched/arm9/pkt_02043B98.json (new)
- **Notes:**
  - docs/notes/pkt_020445F4.c.txt: wave-10 closure section plus the F64 DIFF section.
  - docs/notes/pkt_02043B98.c.txt: closure of B98/F4C plus the 27C DIFF section.
  - docs/notes/sub_02044CE0.c.txt: closure.
- **Family header:** docs/families/bmp.h. Worker prototypes replaced; new sections on the address lever, the clip helper and the conditional-add operand order.

## Process note

One permuter run (B98 hill, budget 1200) went over the 5-minute foreground limit and the harness moved it to the background. It finished on its own; nothing was left running.
