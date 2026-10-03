/*
 * function: func_020385C4
 * address:  0x020385C4
 * packet:   pkt_020385C4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0203D788  0x0203D788  arm
 *   func_0203D798  0x0203D798  arm
 *   func_02034714  0x02034714  arm
 *   func_02037224  0x02037224  arm
 *   func_02037258  0x02037258  arm
 *   func_02038380  0x02038380  arm
 *   func_02038524  0x02038524  arm
 *   func_02038570  0x02038570  arm
 *   func_02038AE0  0x02038AE0  arm
 *   func_02039160  0x02039160  arm
 *   str_020A7A24   0x020A7A24  data
 *   str_020A7A54   0x020A7A54  data
 *   g_020A7A20     0x020A7A20  data
 *   g_021469D0     0x021469D0  data
 *
 * net_system.c.  The outer per-frame entry: it dispatches on the link-state
 * byte at +0x65 of the 0x0203D798 object, in two two-wide bands written as
 * unsigned-wrapped range tests ((u8)(s - 1) <= 1 and (u8)(s - 3) <= 1), and
 * falls through to func_02038380 in both of the middle bands.
 * func_02037224 takes the caller's __LINE__ as its second argument; the four
 * line numbers are 0x4d5, 0x4da, 0x4e1 and 0x4f4.  The assert at +0x50 is
 * the usual func_02034714(file, line, expr) triple.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ctx {
    u8   pad00[0x340];
    u32 *f340;
};

struct Oth {
    u8 pad00[0x64];
    u8 f64;
    u8 f65;
};

extern void *func_0203D788(void);
extern void *func_0203D798(void);
extern void func_02034714(const u8 *file, u32 line, const u8 *expr);
extern void func_02037224(u32 state, u32 line);
extern u32  func_02037258(void);
extern void func_02038380(void);
extern int  func_02038524(void);
extern void func_02038570(void);
extern void func_02038AE0(u32 a, u8 *b, u32 c, u32 d);
extern int  func_02039160(u32 a);
extern const u8 str_020A7A24[];
extern const u8 str_020A7A54[];
extern u8   g_020A7A20[];
extern u32 *g_021469D0;

void func_020385C4(void)
{
    struct Ctx *c = func_0203D788();
    struct Oth *o = func_0203D798();
    u8 s = o->f65;

    if ((u8)(s + 0xff) <= 1) {
        if (func_02039160(0) == 0)
            return;
        if (o->f64 != 0)
            func_02034714(str_020A7A24, 0x4d5, str_020A7A54);
        if (g_020A7A20[0] == 4 && *(u32 *)((u8 *)g_021469D0 + 0x1ac) != 0
            && func_02038524() != 0)
            func_02037224(1, 0x4da);
        if (g_020A7A20[0] != 1)
            return;
        {
            u32 t = func_02037258();
            if (((int (*)(u32, u32, u32, u32))c->f340[0x64 / 4])(
                    ((u32 *)g_021469D0)[2], t, 0, 0) == 0)
                return;
        }
        func_02037224(4, 0x4e1);
        func_02038570();
        return;
    }
    if ((u8)(s + 0xfd) <= 1) {
        if (g_020A7A20[0] == 4) {
            u8 *g = (u8 *)g_021469D0;
            u32 t = func_02037258();

            func_02038AE0(*(u32 *)(g + 8), g + 0xf4, t, g[0x1d4]);
            g = (u8 *)g_021469D0;
            g[0x1d4] = (u8)(g[0x1d4] + 1);
            func_02037224(1, 0x4f4);
        }
        func_02038380();
        return;
    }
    if (((int (*)(void))c->f340[0x70 / 4])() == 0)
        return;
    if (func_02038524() == 0)
        return;
    if (g_020A7A20[0] == 4) {
        u8 *g = (u8 *)g_021469D0;
        u32 t = func_02037258();

        func_02038AE0(*(u32 *)(g + 8), g + 0xf4, t, g[0x1d4]);
        g = (u8 *)g_021469D0;
        g[0x1d4] = (u8)(g[0x1d4] + 1);
        func_02037224(1, 0x501);
    }
    func_02038380();
}
