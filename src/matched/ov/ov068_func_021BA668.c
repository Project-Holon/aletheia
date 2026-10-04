/*
 * function: func_021BA668
 * address:  0x021BA668
 * packet:   pkt_021BA668
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02028230  0x02028230  thumb
 *   func_021BA694  0x021BA694  thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u32 func_02028230(u8 *p);
extern void func_021BA694(u8 *p);

u32 func_021BA668(u8 *p)
{
    u32 r = 0;

    if (*(u32 *)(p + 0x10) != 0) {
        u32 t = *(u32 *)(p + 0xc);

        if (t != 3) {
            r = func_02028230((u8 *)(*(u32 *)(p + t * 4 + 0x34)));
            if (r != 0) {
                func_021BA694(p);
            }
        }
    }
    return r;
}
