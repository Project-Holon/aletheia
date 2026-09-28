/*
 * function: func_02037E60
 * address:  0x02037E60
 * packet:   pkt_02037E60
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0203D788  0x0203D788  arm
 *   func_0203D6BC  0x0203D6BC  arm
 *   func_02039338  0x02039338  arm
 *   func_02039160  0x02039160  arm
 *   func_02038A48  0x02038A48  arm
 *   func_020387A0  0x020387A0  arm
 *   g_020A7A20     0x020A7A20  data
 *   g_021469D0     0x021469D0  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Vtbl {
    u8   pad00[0x64];
    u32 (*f64)(u32, u32, u32, void *);   /* 0x64 */
    u8   pad68[0x70 - 0x68];
    u32 (*f70)(void);                    /* 0x70 */
};

struct Ctx {
    u8           pad00[0x340];
    struct Vtbl *f340;                   /* 0x340 */
};

struct State {
    u32 f0;                              /* 0x00 */
    u8  pad04[0x1b0 - 0x04];
    u32 f1b0;                            /* 0x1b0 */
};

extern struct Ctx   *func_0203D788(void);
extern u32           func_0203D6BC(void);
extern u32           func_02039338(u32 a);
extern u32           func_02039160(u32 a);
extern int           func_02038A48(u32 a);
extern void          func_020387A0(u32 a, u32 b, u32 c);
extern u8            g_020A7A20[];
extern struct State *g_021469D0;

void func_02037E60(void)
{
    struct Ctx *c = func_0203D788();
    u32 v = func_0203D6BC();
    u32 r;

    r = c->f340->f70();
    if (r == 0)
        return;
    r = func_02039338(r);
    r = func_02039160(r);
    if (r == 0)
        return;
    if (g_020A7A20[1] != 0)
        return;
    if (func_02039338(g_020A7A20[1]) != 0) {
        r = c->f340->f64(g_021469D0->f0, v, 0, func_02038A48);
        if (r == 0)
            return;
        g_020A7A20[1] = 2;
        g_021469D0->f1b0 = g_021469D0->f1b0 + 1;
    } else {
        g_020A7A20[1] = 2;
        func_02038A48(1);
        func_020387A0(0, g_021469D0->f0, (u16)v);
        g_021469D0->f1b0 = g_021469D0->f1b0 + 1;
    }
}
