/*
 * function: func_02191084
 * address:  0x02191084
 * packet:   pkt_ov021_02191084
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02190D2C  0x02190D2C  thumb  ov021
 *   func_02190D48  0x02190D48  thumb  ov021
 *   func_02193210  0x02193210  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

typedef struct Fx {
    u16 f00;
    u16 f02;
    u16 f04;
    u16 f06;
} Fx;

typedef struct P {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    Fx *f14;
} P;

extern int func_02190D48(void *a);
extern u32 func_02193210(u8 *p);
extern u32 *func_02190D2C(u32 *a, u32 b, u32 c, u32 d, u16 e, u32 f);

void func_02191084(P *p, u32 b, u16 c, u32 d)
{
    if (p->f04 != 0)
        func_02190D48((void *)p->f04);
    p->f04 = (u32)func_02190D2C((u32 *)p->f14, d, p->f00, (u16)(b + 8), c, func_02193210((u8 *)p->f14 + 0x160));
}
