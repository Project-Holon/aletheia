/*
 * function: func_021A9810
 * address:  0x021A9810
 * packet:   pkt_ov021_021A9810
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A99A8  0x021A99A8  thumb
 */

typedef unsigned short u16;

struct Entry8;
extern const struct Entry8 *func_021A99A8(void *p);

u16 func_021A9810(int a)
{
    u16 *p = (u16 *)func_021A99A8((void *)a);
    if (p == 0) {
        return 0xffff;
    }
    return *p;
}
