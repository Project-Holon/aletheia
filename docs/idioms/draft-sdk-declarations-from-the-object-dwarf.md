# Draft an SDK function's declarations from the object DWARF, not the disassembly

summary: for an open SDK row, `python tools/sdkobj.py <addr> --brief` prints the
defining object's DWARF prototype and the exact local-variable list with each
variable's type and frame offset/register; declaring the function from that list
pins the frame size, stack slots and callee-saved registers in one step, where a
reconstruction drafted from the disassembly alone gets the semantics right and
the allocation wrong everywhere.

Found in: src/pending/ov_sdk/ov172_func_021BE5C4.c (0x021BE5C4)

`Mel_JPEGDecode` (0x021BE5C4, jpegdec.o) is a 2548-byte decoder driver. A prior
lane had rebuilt the whole marker walker from the listing: correct control flow,
all 21 relocations resolving, but 2098 of ~2400 concrete bytes wrong, and the
frame 8 bytes short (`sub sp,#0x348` against the original `#0x350`).

`sdkobj.py --brief` delivers what the listing cannot:

```
static int Mel_JPEGDecode(unsigned char * d, unsigned char * a,
                          unsigned long length, long maxWidth,
                          long maxHeight, int option);
  param  d          [fb+4]     param  a          [fb+8]
  param  length     r5         param  maxWidth   [fb+12]
  variable result r0    huffsize [fb+76]  huffcode [fb+334]
  variable b r0  RSTn_work [fb+24]  RSTn_intr [fb+28]
  variable y r14  x r12  s r0  q r0  p [fb+72]  m r1
  variable j r0  i r0  g r4  h r6  dy [fb+32]  dx [fb+36]
```

The frame is fixed by the list: `huffcode` (`u16[257]`, 0x14E) sits above
`huffsize` (`char[257]`, 0x4C) at the top of the frame, 0x14E+0x202 = 0x350. The
reconstruction had declared `huffsize` first, so the arrays were inverted and
the frame came out 0x348. Simply spelling `huffcode` before `huffsize` moved the
frame to 0x350 and the entry prologue matched (mismatch 2098 -> 2092); the same
list supplies `dx`/`dy` as the width/height locals (`[fb+36]`/`[fb+32]`, the
SOF fields stored there), `p` at `[fb+72]`, and the callee-saved colours
(`bcode2` base in r4, `h` in r6). Note the DWARF order is the *printed* order;
combine with dwarf-lists-locals-in-reverse-declaration-order when it disagrees
with the slot addresses.

This is the first lever to pull on any large open SDK function: it costs one
command and removes the entire class of "right body, wrong allocation" blank
diff.
