/*
 * function: func_021AC274
 * address:  0x021AC274
 * packet:   pkt_ov021_021AC274
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021ABE24  0x021ABE24  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct Tmpl { u32 res; u8 b4, b5, b6, b7; u32 w8; } Tmpl;
typedef struct Ctl { u32 f0; u32 f4; u32 f8; u32 fc; u32 f10; u32 f14; u32 f18; } Ctl;

extern u32 func_021ABE24(u32 a);
extern u32 func_02046E24(u32 a, u32 b);
extern u16 func_020500F0(u32 a, Tmpl *b, u32 c);

void func_021AC274(Ctl *p)
{
    Tmpl t;

    t.res = func_02046E24(func_021ABE24(p->f0), 0x2f);
    t.b4 = 2;
    t.b5 = 0x11;
    t.b6 = 0x10;
    t.b7 = 0x10;
    t.w8 = 1;
    p->f18 = func_020500F0(p->f10, &t, 1);
}
