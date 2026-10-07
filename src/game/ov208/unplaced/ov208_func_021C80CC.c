/*
 * function: func_021C80CC
 * address:  0x021C80CC
 * packet:   pkt_ov208_021C80CC
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Region-qualified name: many overlays share this load address; this is
 * ov208's function. It is the last labelled function in ov208, so `show`
 * reports a 0x40 stub extent and a naive next-label scan reports the whole
 * 0xDB4 tail to 0x021C8E80. The true extent is 18 bytes, ending at the
 * `bx lr` on 0x021C80DC (2 pad bytes follow, then a data/pool run).
 *
 * 12-byte aggregate copy out of base[index].field at +8.
 */

typedef struct { unsigned int f0; unsigned int f1; unsigned int f2; } Blk12;

void func_021C80CC(char *base, int index, Blk12 *dst)
{
    *dst = *(Blk12 *)(base + index * 12 + 8);
}
