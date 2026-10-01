# A transcription that is too big on a straight-line vendor listing is usually N copies of one image block; count the image's distinct call sites

summary: when a long SDK function compiles much larger than the image, the
source often spells out a setup/parse tail once per path where the image has a
single cross-jumped copy.  The number of copies is decidable without guessing:
count the decodable `bl` sites of each callee in the image's own listing and in
the object, and the callee whose object count exceeds the image count names the
duplicated block.  Write the source with the image's sharing (a shared label /
fall-through), not one copy per path.

Found in: `src/pending/ov_sdk/ov009_func_0217AB78.c` (`DWCi_Netcheck_Thread`,
0x0217AB78, ov009)

The image (3184 bytes) has exactly four `bl DWC_Http_Create`, four
`bl DWC_Http_FinishHeader`, four `bl DWC_Http_Add_PostBase64Item`, two
`bl DWC_Auth_GetCalInfoFromNVRAM` and three `bl DWC_Http_ParseResult`.  The
transcription contained a fifth setup block (`preauth:`) and a fourth parse
tail (`auth3:`) that duplicated the `stage2`-body setup and `parse_auth`
respectively; its object therefore had five Create/FinishHeader/AddPost sites
and four ParseResult sites, and compiled to 3408 bytes (+224).  Counting the
`bl` targets in `asm/overlays/ov009.s` over the function's own line range
(`func_0217AB78` to the next `.global func_`) is enough to see the extra copy.
Removing both fake blocks and pointing `stage2`'s `nc->0x1118 == 0` arm at
`parse_auth` (0x217af70) cut the object to 2988 and the concrete mismatches
from 2912 to 2546.

Two cautions:

- the same callee may legitimately be called more than once in one block (the
  setup calls `Add_PostBase64Item` twice), so compare *per callee* against the
  image total, and identify the duplicated block by its distinguishing
  arguments, not by the call alone.  Here `setup A` (0x217B144) is the items-5
  copy and `stage2` (0x217AE3C) is the items-7 copy; there is no items-7 copy
  with `p08 == 0x1000`, which is what proves `preauth` fake.
- a label with no `goto` to it is dead and is elided, so removing it changes
  nothing; only an *unreferenced-looking but still fall-through-reachable*
  block (a `preauth:` label that some earlier `goto` still names) does work.
