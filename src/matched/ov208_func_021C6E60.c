/*
 * function: ov208_func_021C6E60
 * address:  0x021C6E60
 * packet:   pkt_ov208_021C6E60
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 */

typedef unsigned char  u8;
typedef unsigned short u16;

u16 ov208_func_021C6E60(void *unused, u8 *p, int unused2, u16 skip, u16 want)
{
    u16 r = 0;
    u16 j = 0;
    u16 i;

    for (i = 0; i < *(u16 *)(p + 0x548); i++) {
        if (i != skip) {
            if (j == want) {
                r = i;
                break;
            }
            j++;
        }
    }
    return r;
}
