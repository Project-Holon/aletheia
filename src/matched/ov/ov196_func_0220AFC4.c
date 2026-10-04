/*
 * function: func_0220AFC4
 * address:  0x0220AFC4
 * packet:   pkt_0220AFC4
 * region:   ov196
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct Obj;
extern void func_0204B3B4(struct Obj *p);

void func_0220AFC4(u8 *p)
{
    u32 i;

    for (i = 0; i < 4; i++) {
        func_0204B3B4((struct Obj *)(*(u32 *)(p + i * 4)));
    }
}

