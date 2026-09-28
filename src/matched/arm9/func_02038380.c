/*
 * function: func_02038380
 * address:  0x02038380
 * packet:   pkt_02038380
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
 *   func_0203D680  0x0203D680  arm
 *   func_0203D6BC  0x0203D6BC  arm
 *   func_020392B8  0x020392B8  arm
 *   func_02037224  0x02037224  arm
 *   func_02037258  0x02037258  arm
 *   func_02038570  0x02038570  arm
 *   func_02038924  0x02038924  arm
 *   func_02038A90  0x02038A90  arm
 *   g_020A7A20     0x020A7A20  data
 *   g_021469D0     0x021469D0  data
 *
 * net_system.c.  The per-frame step of the session state machine, driven by
 * the state byte at 0x020A7A20.  func_02037224 sets that byte and takes the
 * caller's __LINE__ as its second argument; the four line numbers here are
 * 0x46a, 0x46e, 0x475 and 0x48d, and the front end materialises 0x46a once
 * and derives 0x46e from it with `add r1, r4, #4`
 * (docs/idioms/consecutive-line-numbers-are-one-pool-word-and-adds.md).
 * 0x48d is spelled as `0x490 - 3` because the `3` is already live in r0 as
 * the state argument of the same call.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ctx {
    u8   pad00[0x340];
    u32 *f340;
};

struct Oth {
    u8 pad00[0x65];
    u8 f65;
};

extern struct Ctx *func_0203D788(void);
extern struct Oth *func_0203D798(void);
extern u32  func_0203D680(void);
extern u32  func_0203D6BC(void);
extern int  func_020392B8(void);
extern void func_02037224(u32 state, u32 line);
extern u32  func_02037258(void);
extern void func_02038570(void);
extern void func_02038924(u32 a, u32 b, u16 c);
extern void func_02038A90(u32 a);
extern u8   g_020A7A20[];
extern u32 *g_021469D0;

void func_02038380(void)
{
    struct Ctx *c = func_0203D788();

    func_0203D680();
    if (g_020A7A20[0] == 1) {
        if (func_020392B8() > 1) {
            func_02037224(2, 0x46a);
            if (((int (*)(void))c->f340[0x70 / 4])() != 0) {
                u32 t = func_02037258();
                if (((int (*)(u32, u32, u32, u32))c->f340[0x64 / 4])(
                        g_021469D0[2], t, 0, (u32)func_02038A90) != 0)
                    goto tail;
                func_02037224(1, 0x46a + 4);
                goto tail;
            }
            if (func_0203D798()->f65 != 3 && func_0203D798()->f65 != 4)
                goto tail;
            if (((int (*)(void))c->f340[0xa0 / 4])() == 0) {
                func_02037224(1, 0x475);
                goto tail;
            }
            if (*(u8 *)(g_021469D0[2] + 2) == 0)
                return;
            {
                u32 t = func_0203D6BC();
                ((void (*)(u32, u32, u32, u32))c->f340[0x64 / 4])(
                    g_021469D0[2], t, 0x64, 0);
            }
        }
    }
tail:
    if (g_020A7A20[0] == 2) {
        func_02038570();
        func_02038924(0, (u32)g_021469D0[2], (u16)func_02037258());
        func_02037224(3, 0x490 - 3);
    }
    if (((int (*)(void))c->f340[0x70 / 4])() == 0)
        goto last;
    if (func_0203D798()->f65 == 3)
        goto last;
    if (func_0203D798()->f65 != 4)
        return;
last:
    func_02037224(4, 0x492);
}
