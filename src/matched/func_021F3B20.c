/*
 * function: func_021F3B20
 * address:  0x021F3B20
 * packet:   pkt_021F3B20
 * region:   ov055
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef unsigned char u8;

u8 *func_021F3B20(u8 *p)
{
    int i;

    for (i = 0; i < 0x20; i++) {
        int off = i * 0x18;

        if (p[off + 8] == 0) {
            return (u8 *)(p + 8) + off;
        }
    }
    return 0;
}
