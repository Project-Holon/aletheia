# The object's DWARF locals are the vendor's declaration list (and the listing is a spec)

Lane U57, 2026-09-30. `python tools/sdkobj.py <addr> --region <ovNNN>` prints, for the vendor
archive member behind a row: the DWARF prototype and **every local with its type and register**,
and the object's own instruction listing. For libssp/`jpegenc.o`-class rows the listing is
byte-identical to the image (sdkobj says "0 concrete mismatches"), so the listing is the target and
the DWARF is a spec of the source. Both levers below paid on ov172 and neither is ov172-specific.

## 1. A local with no DWARF entry is not a source local - spell it inline

The DWARF local list is complete for these objects, and it is listed (verified against an EXACT row,
ov172 0x021C12F4: DWARF `count, i` for a source that declares `i, sum`) in **reverse source
declaration order**. So: declare exactly the DWARF locals, in reverse-DWARF order, with the DWARF
types, and if a value the source obviously uses has *no* DWARF entry, do not name it - repeat the
expression at every use and let CSE place it.

Worked case, ov172 0x021C1AE4 `SSPi_JpegEncoderDoSign` (was parked at 103 concrete bytes, now
EXACT 680/680). DWARF gives six locals: `tag(u16,r3) i(int,r7) registrationNumber(u32,r2)
sign[28](fb) p(u8*,r0) offset(u32,r1)`. There is **no local for the `gBitLen[8]` bound** the function
guards against eight times, and no `base`. Rewriting the draft with `*(u32 *)(gBitLen + 8)` inline at
all eight guards (instead of a `limit` local) is what pins it in `ip` and leaves `r2` free for
`registrationNumber`; a `limit` local takes `r2` and the whole body rotates. The same rewrite drops
`base`: `offset` itself holds the IFD start, the `offset + 2` guard temporary is then reused by the
following `offset += 2`, and `p = dst + offset` next to a bare `dst[offset]` is what produces the
image's `ldr r0,[r0,#1]` / `ldr r0,[r5,r1]` load pair. 103 -> 0 in one pass, using only the listing
as a spec. An earlier lane had already tried "declaring n/tag/p/i in every order" - declaration order
was not the lever, the *set* of declarations was.

## 2. Read the listing for structure, not just for registers

Two things no amount of re-spelling finds:

- **A value read twice in the source.** ov172 0x021C131C: the image reloads
  `JpegZigZagInputOrderCodes[index]` and the halfword at +0x108/+0x114 (three instructions) because
  the vendor reads `du[JpegZigZagInputOrderCodes[index]]` once in the zero test and again inside the
  else arm. A draft with `value = du[...]` hoisted above the `if` is exactly those three
  instructions short.
- **Which arm the vendor wrote first.** The same row: with the one-statement arm first
  (`if (v == 0) { zerorun++; } else { ...big... }`) mwcc if-converts it to `addeq r5,r5,#1` plus a
  branch; with the arms swapped so the big body is the then-arm, the small arm is laid out as the
  loop-tail block the image has. Swapping the arms took the row from 480 B (size short) to 484/484
  size-exact and 282 -> 58 concrete bytes.

## Delivery note

A row can be *improved* without being filed: a better draft belongs in the same
`src/pending/ov_sdk/<region>_func_<ADDR>.c` (parked sources are the next wave's starting point),
while only an EXACT row gets a `src/matched/ov_sdk/` source and a shard.
