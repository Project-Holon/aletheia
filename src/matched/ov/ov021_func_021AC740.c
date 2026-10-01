/*
 * function: func_021AC740
 * address:  0x021AC740
 * packet:   pkt_ov021_021AC740
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct X { u32 f0; u32 f4; u16 h[8]; } X;

extern void func_02050278(u32 a, u32 b, u32 c);

void func_021AC740(X *x)
{
    int i;

    for (i = 0; i < 8; i++)
        func_02050278(x->f4, x->h[i], 1);
}
