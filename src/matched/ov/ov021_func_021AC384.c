/*
 * function: func_021AC384
 * address:  0x021AC384
 * packet:   pkt_ov021_021AC384
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct H { u32 f0, f4, f8, fc, f10; } H;
typedef struct W { u32 f0; H *h; u32 f8, fc, f10; u32 f14; } W;

struct BbActSys;
extern void func_02050468(struct BbActSys *o, u16 first, u32 count);

void func_021AC384(u32 a, W *w)
{
    if (w->f14 != 0xFFFF)
        func_02050468((struct BbActSys *)w->h->f10, (u16)w->f14, 1);
}
