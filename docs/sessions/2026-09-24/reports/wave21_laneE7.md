# Wave 21, lane E7: blink_palanm 0x0202E1F0 (fresh draft)

Every verdict below comes from `tools/match.py one --diff` (dsi/1.1p1, -O4,p, Thumb). There were about 90
compiles, all written by hand, and the permuter was not used. Scratch files are in `/tmp/aletheia_laneE7`.

## Result

| function | before | after | where |
|---|---|---|---|
| 0x0202E1F0 blink_palanm (412 B) | DIFF 2 | DIFF 2 | `docs/notes/pkt_0202E1F0.c.txt`, section "wave 21 (lane E7)" |

Nothing was filed. No file was written to `src/matched/` or `src/pending/`, and no shard was touched.

## Approach

I wrote the function again from the listing. The types came from the callees' matched bodies and from the
caller, func_0202DC60. None of it came from the wave-19 source. This draft differs from earlier ones in
these ways:

- **func_0201D478 takes an argument.** The string handle returned by func_0202441C is passed in r0, so the
  line is `n = (u8)func_0201D478(str)`. Earlier drafts declared the function `(void)`.
- **The tail is one statement:** `func_02041B6C(func_02045730(wk->msg))`. func_02045730 is a u8 getter,
  and func_02041B6C takes the bit number.
- **`u8 pal` needs a u8 parameter in the 02043B5C and 02043AF4 prototypes.** With that,
  `ldr/str [sp,#0x6c]` copies pal onto its own slot. With u32 prototypes that copy disappears and the
  frame grows to 0x4c.
- **The structs are 8-byte MSGPARAM, BLINKPOS {x, y}, and 0x28-byte BLINKWORK.** BLINKWORK has `msg` at
  +0, `active` at +4, `act[2]` at +8, bitfields at +0x18 and `blink[2]` at +0x20.

## Measurements

| step | bytes out |
|---|---|
| first draft | 385 (frame 0x4c) |
| + u8 pal prototypes | 371 |
| + `heapID = *(u16 *)&heap` | 31 (o/w swapped, spill slots in a different order) |
| 39 declaration permutations | 31 each |
| g call passed `&mp` | 12 |
| + `int n = (u8)...` instead of `u8 n` | **2** (the +008E residue) |
| same draft, g call passed `param` | 21 (o=r7) |

The fresh draft reaches exactly the wave-19 residue. Its spelling is simpler: the plain
`const MSGPARAM *param` is reused as `param = &mp`, with no unsigned long and no wp copy, and the g call
is given `&mp`.

Other results:

- **Heap re-read.** The image reads heap twice. No spelling without an address-of reproduces that: u32 heap
  with u16 prototypes gave 420 bytes; u16 heap with u16 prototypes gave 408 bytes, with or without a local.
- **W as a local.** Both local-variable forms of W fold to the constant (400 bytes, 374 out). Typing W as
  `const u16 *` gave 21, and so did writing the def inside the 0202465C argument.
- **Degree and live range, checked from the 21 side.** Lane E5 only checked these from base. Tail
  temporaries that interfere with o only gave 416/56 and 428/73. Moving the bitfield stores ahead of the
  tail calls, so that o dies first, gave 412/60. o stayed in r7 in all three, so the o/w order depends on
  use cost alone.
- **Bitfield merging.** Storing `ready` twice gives 412/29 with o still in r7. The duplicate
  read-modify-write is merged before costing and adds no o unit.

## Conclusion

A draft written independently, with the parameter and callee widths read from matched bodies, lands on
the same 2-byte residue and the same one-unit o/w balance. The fresh-draft lever that closed the palanm pair
(0x0202173C/0x02021848) does not apply here: the widths change nothing. The notes carry the fresh source,
which is 2 out, as an alternative best source.
