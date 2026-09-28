/*
 * function: ov208_func_021C6E30
 * address:  0x021C6E30
 * packet:   pkt_ov208_021C6E30
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 */

typedef unsigned char  u8;
typedef unsigned short u16;

u16 ov208_func_021C6E30(void *unused, u8 *p, int unused2, u16 skip, u16 stop)
{
    u16 n = 0;
    u16 i;

    for (i = 0; i < *(u16 *)(p + 0x548); i++) {
        if (i == skip)
            continue;
        if (i == stop)
            break;
        n++;
    }
    return n;
}
