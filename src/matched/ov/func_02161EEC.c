/*
 * function: func_02161EEC
 * address:  0x02161EEC
 * packet:   pkt_02161EEC
 * region:   ov010
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Fills ten halfwords with 0xFFFF.  A leaf with no lr-saving prologue,
 * called only from arm9 (func_0200A848), so the listing emits it as data.
 */

typedef unsigned short u16;

void func_02161EEC(u16 *buf)
{
    int i;
    for (i = 0; i < 10; i++)
        buf[i] = 0xffff;
}
