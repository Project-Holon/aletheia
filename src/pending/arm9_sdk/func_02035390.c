/*
 * function: func_02035390
 * address:  0x02035390
 * packet:   pkt_02035390
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * symbols:
 *   d_02FFA8   0x02FFA8  data  a2
 *
 * byte-correct (32 == 32) but capped at MATCH: the pool word naming
 * 0x0002FFA8 (the hardware register holding the SCFG/EXMEM bit-15 latch) has
 * no witness anywhere else in the image, so the ABS32 stays wildcarded.
 * The `and #0x8000; asrs #0xf` pair is the signed-16-bit sign-bit test, so
 * the C spells the shift explicitly rather than `(x & 0x8000) != 0` (which
 * gives `tst`, 28 bytes, SIZE).
 */

typedef unsigned short u16;

extern u16 d_02FFA8;

int func_02035390(void)
{
    return ((int)(d_02FFA8 & 0x8000) >> 15) != 0;
}
