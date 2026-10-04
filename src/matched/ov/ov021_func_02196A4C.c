/*
 * function: func_02196A4C
 * address:  0x02196A4C
 * packet:   pkt_ov021_02196A4C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020221A4  0x020221A4  thumb
 *   func_02051C88  0x02051C88  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern u32 func_020221A4(void);
typedef signed int     s32;
struct Ctx;
extern s32 func_02051C88(struct Ctx *c);

void func_02196A4C(u8 *a)
{
    if (func_020221A4() != 0) {
        func_02051C88((struct Ctx *)(*(u32 *)(a + 0x24)));
    }
}
