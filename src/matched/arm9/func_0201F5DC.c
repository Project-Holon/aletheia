/*
 * function: func_0201F5DC
 * address:  0x0201F5DC
 * packet:   pkt_0201F5DC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201F5DC.c \
 *       --func func_0201F5DC --addr 0x0201F5DC --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed char s8;

extern u8 func_0201F53C(int i);
extern void *func_020496E4(u32 a0, u32 a1, u32 a2, u32 a3, u32 a5, u32 a6);
extern void func_0201F57C(u32 a, u32 b, u32 c, u32 d);

void *func_0201F5DC(void *a0, u32 a1, u32 a2, u32 a3)
{
    void *r = func_020496E4(5, func_0201F53C(a2), (u32)a0, 0, 0, a3);

    func_0201F57C((u32)a0, a1, a2, a3);
    return r;
}
