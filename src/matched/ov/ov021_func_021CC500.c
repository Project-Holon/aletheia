/*
 * function: func_021CC500
 * address:  0x021CC500
 * packet:   pkt_ov021_021CC500
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02012934  0x02012934  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_021CC390  0x021CC390  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Task {
    u32 f0;
    u32 f4;
    u32 f8;
    u8 fC;
    u8 fD;
    u8 padE[0x58 - 0xE];
    u32 f58;
} Task;

extern u32 func_020120F4(void);
extern u32 func_02012934(u32 a);
extern u32 func_020122C0(u32 a, u32 b, void *c, u32 d);
extern Task *func_020124E8(u32 h);
extern int func_021CC390(u32 a, u32 b, u32 c);

u32 func_021CC500(u32 a, u32 b, u32 c)
{
    u32 t;
    u32 x;
    u32 h;
    Task *p;

    t = func_020120F4();
    x = func_02012934(t);
    h = func_020122C0(a, 0, (void *)func_021CC390, 0x5c);
    p = func_020124E8(h);
    p->f0 = a;
    p->f4 = t;
    p->f8 = x;
    p->fC = b;
    p->fD = c;
    p->f58 = 0;
    return h;
}
