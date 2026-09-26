/*
 * function: func_0200E008
 * address:  0x0200E008
 * packet:   pkt_0200E008
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf: increment a clamped u16 counter.  Each record of the
 * table is six bytes; the counter for (a, idx) sits at base + a*6 + idx*2 and
 * is bumped by one only while it is below 0xFFFF.
 */

typedef unsigned char  u8;
typedef unsigned short u16;

void func_0200E008(u8 *base, int a, int idx)
{
    u16 *p = (u16 *)(base + a * 6 + idx * 2);

    if (*p < 0xFFFFu) {
        *p = (u16)(*p + 1);
    }
}
