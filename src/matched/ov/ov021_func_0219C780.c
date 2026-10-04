/*
 * function: func_0219C780
 * address:  0x0219C780
 * packet:   pkt_ov021_0219C780
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0219C6B8  0x0219C6B8  thumb  ov021
 *   func_0216D520  0x0216D520  thumb  ov010
 *   func_02050894  0x02050894  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef struct { int x, y, z; } V3;
extern u32 func_0219C6B8(u32 a, V3 *b, int c, u32 d, u16 e);
extern u32 func_0216D520(void *p);
extern int func_02050894(void *p, int idx, int j);

u32 func_0219C780(u32 a, V3 *b, int c, u32 d, u16 e, u16 g)
{
    u32 r = func_0219C6B8(a, b, c, d, e);
    if (g != 0xFFFF) {
        func_02050894((void *)(*(u32 *)(func_0216D520((void *)a) + 4)), r, g);
    }
    return r;
}
