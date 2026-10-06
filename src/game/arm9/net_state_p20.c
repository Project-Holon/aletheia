/*
 * file:     net_state_p20.c
 * unit:     yes
 * function: func_02038570, func_020385C4, func_020387A0
 * address:  0x02038570
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_021469D0    0x021469D0  data
 *   func_0203D680 0x0203D680  arm
 *   func_02039160 0x02039160  arm
 *   func_0203D788  0x0203D788  arm
 *   func_0203D798  0x0203D798  arm
 *   func_02034714  0x02034714  arm
 *   func_02037224  0x02037224  arm
 *   func_02037258  0x02037258  arm
 *   func_02038380  0x02038380  arm
 *   func_02038524  0x02038524  arm
 *   func_02038AE0  0x02038AE0  arm
 *   str_020A7A24   0x020A7A24  data
 *   str_020A7A54   0x020A7A54  data
 *   g_020A7A20     0x020A7A20  data
 *   lbl_021469D0   0x021469D0  data
 *   func_0203D6BC  0x0203D6BC  arm
 *   func_0203F1FC  0x0203F1FC  arm
 *   func_02039548  0x02039548  arm
 *   func_0203CA98  0x0203CA98  arm
 *   func_0203C9AC  0x0203C9AC  arm
 *   func_02036428  0x02036428  arm
 */
#include "../../matched/include/Obj03447.h"
#include "../../matched/include/Obj03449.h"

struct Conn;
struct Hdr;
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

typedef signed int     s32;

extern u32 func_0203D680(void);
extern u32 func_02039160(u16 a);
extern void *func_0203D788(void);
extern void *func_0203D798(void);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_02037224(u8 v, int b);
extern u32  func_02037258(void);
extern void func_02038380(void);
extern int  func_02038524(void);
extern s32 func_02038AE0(struct Hdr *h, struct Conn *c, s32 len, u8 a3);
extern u32 func_0203D6BC(void);
extern u16 func_0203F1FC(const u8 *src, u32 len);
extern void func_02039548(void);
extern u32 func_0203CA98(void);
extern void func_0203C9AC(int a, u32 b, u32 c, u32 d);
extern void func_02036428(u8 *dst, u8 *src, s32 len);
void func_02038570(void);
void func_020385C4(void);
int func_020387A0(u32 i, u8 *p, s32 n);
extern u32 *g_021469D0;
extern const u8 str_020A7A24[];
extern const u8 str_020A7A54[];
extern u8   g_020A7A20[];
extern u8 *lbl_021469D0;


void func_02038570(void)
{
    int i;
    int n = func_0203D680();

    for (i = 0; i < n; i++) {
        if (func_02039160((u16)i) != 0) {
            *(u32 *)((u8 *)((u32 *)g_021469D0 + i) + 0x1b4) += 1;
        }
    }
}


/*
 * net_system.c.  The outer per-frame entry: it dispatches on the link-state
 * byte at +0x65 of the 0x0203D798 object, in two two-wide bands written as
 * unsigned-wrapped range tests ((u8)(s - 1) <= 1 and (u8)(s - 3) <= 1), and
 * falls through to func_02038380 in both of the middle bands.
 * func_02037224 takes the caller's __LINE__ as its second argument; the four
 * line numbers are 0x4d5, 0x4da, 0x4e1 and 0x4f4.  The assert at +0x50 is
 * the usual func_02034714(file, line, expr) triple.
 */
void func_020385C4(void)
{
    struct Ctx *c = func_0203D788();
    struct Oth *o = func_0203D798();
    u8 s = o->f65;

    if ((u8)(s + 0xff) <= 1) {
        if (func_02039160(0) == 0)
            return;
        if (o->f64 != 0)
            func_02034714((const char *)str_020A7A24, 0x4d5, (const char *)str_020A7A54);
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

            func_02038AE0((struct Hdr *)(((struct Obj03447 *)g)->f8), (struct Conn *)(g + 0xf4), t, g[0x1d4]);
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

        func_02038AE0((struct Hdr *)(((struct Obj03447 *)g)->f8), (struct Conn *)(g + 0xf4), t, g[0x1d4]);
        g = (u8 *)g_021469D0;
        g[0x1d4] = (u8)(g[0x1d4] + 1);
        func_02037224(1, 0x501);
    }
    func_02038380();
}


/*
 * The indexed twin of src/matched/func_02038924.c (the own-slot variant):
 * same receive/validate/copy shape, but every global offset is scaled by
 * the slot index -- the 0x1B4 credit counter by i*4, the 0x54 accepted
 * flag and the 0x4C payload by i*16, the 0x1D7 sequence byte by i.  The
 * extra middle block this one has and 0x02038924 does not is the sequence
 * check at 0x1D7+i with its own 0x3F3 error line.
 */
int func_020387A0(u32 i, u8 *p, s32 n)
{
    u8 *g;
    u8 *q;
    u32 v;
    s32 len;
    int r;

    func_0203D6BC();
    if (p == 0)
        return 0;
    g = lbl_021469D0;
    *(u32 *)(g + 0x1b4 + i * 4) = *(u32 *)(g + 0x1b4 + i * 4) - 1;
    if (i == 0)
        *(u16 *)(lbl_021469D0 + 0x100 + 0xe4) = p[3];
    v = p[4];
    if (v == 0xff)
        return 0;
    if (*(u32 *)(lbl_021469D0 + i * 16 + 0x54) == 0) {
        if (v & 2)
            return 0;
    }
    r = func_0203F1FC(p + 2, n - 2);
    if (p[0] != (u8)r || ((r & 0xff00) >> 8) != p[1]) {
        func_02039548();
        q = (u8 *)func_0203CA98();
        if (((struct Obj03449 *)q)->fC == 0)
            func_0203C9AC(((struct Obj03449 *)q)->f0, ((struct Obj03449 *)q)->f4, ((struct Obj03449 *)q)->f8, 0x3f2);
        return 0;
    }
    {
        u8 *s = lbl_021469D0 + 0xd7 + 0x100;
        if (s[i] != 0 && (u8)(p[5] - 1) != s[i]) {
            func_02039548();
            q = (u8 *)func_0203CA98();
            if (((struct Obj03449 *)q)->fC == 0)
                func_0203C9AC(((struct Obj03449 *)q)->f0, ((struct Obj03449 *)q)->f4, ((struct Obj03449 *)q)->f8, 0x3f3);
            return 0;
        }
        s[i] = p[5];
    }
    len = p[2];
    if (p[4] & 8)
        len += 0xff;
    func_02036428(lbl_021469D0 + 0x4c + i * 16, p + 7, len);
    *(u32 *)(lbl_021469D0 + i * 16 + 0x54) = 1;
    return 1;
}
