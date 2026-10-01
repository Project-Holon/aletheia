/*
 * function: func_0218D104
 * address:  0x0218D104
 * packet:   pkt_ov021_0218D104
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0218D0D8  0x0218D0D8  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 func_02046DB8(u32 a, u32 b);
extern void func_020470A8(u32 a);
extern int func_0218D0D8(u32 a, void *b);

void func_0218D104(u8 *a, u8 *b, void *c)
{
    u32 v = *(u32 *)(b + 0x20);
    if (v != 0) {
        if (v == 1) {
            u32 *q = (u32 *)(b + 0x24);
            *(u32 *)(a + 0x60) = func_02046DB8(q[0], q[1]);
            if (c != 0)
                func_0218D0D8(*(u32 *)(a + 0x60), c);
            func_020470A8(*(u32 *)(a + 0x60));
        }
    } else {
        *(u32 *)(a + 0x60) = 0;
    }
}
