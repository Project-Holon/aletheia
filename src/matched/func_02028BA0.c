/*
 * function: func_02028BA0
 * address:  0x02028BA0
 * packet:   pkt_02028B50
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_020061F8(u32 v);

void func_02028BA0(u8 *o, u32 v)
{
    int i;

    if (*(u32 *)(o + 0xb4) == 0) {
        for (i = 0; i < 2; i++) {
            if (*(u16 *)(o + 0xac + i * 2) != 0xffff) {
                func_020061F8(i + 1);
            }
        }
    }
    *(u32 *)(o + 0xb4) |= v;
}
