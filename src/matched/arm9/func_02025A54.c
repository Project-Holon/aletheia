/*
 * function: func_02025A54
 * address:  0x02025A54
 * packet:   pkt_0202590C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B6F4  0x0204B6F4  arm
 */

typedef signed char    s8;
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct Obj;
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);

void func_02025A54(u8 *g, u32 a)
{
    int i;
    int j;

    for (i = 0; i < *(u8 *)(g + 0xCB); i++) {
        for (j = 0; j < *(u8 *)(g + 0xCA); j++) {
            func_0204B6F4(*(void **)(g + 4 + (i * *(u8 *)(g + 0xCA) + j) * 4), a, 0);
        }
    }
}
