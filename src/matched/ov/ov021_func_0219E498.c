/*
 * function: func_0219E498
 * address:  0x0219E498
 * packet:   pkt_ov021_0219E498
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D530  0x0216D530  thumb  ov010
 *   func_021BB480  0x021BB480  thumb  ov021
 *   func_021B7D38  0x021B7D38  thumb  ov021
 *   func_021B7C38  0x021B7C38  thumb  ov021
 *   func_0207C768  0x0207C768  arm
 *   func_0216DD1C  0x0216DD1C  thumb  ov010
 *   func_0216D55C  0x0216D55C  thumb  ov010
 *   func_0219E348  0x0219E348  thumb  ov021
 *   func_021B8040  0x021B8040  thumb  ov021
 *   func_021B8038  0x021B8038  thumb  ov021
 *   func_021B7E60  0x021B7E60  thumb  ov021
 *   func_021B7ED4  0x021B7ED4  thumb  ov021
 *   func_021B83B0  0x021B83B0  thumb  ov021
 * Addresses are Black-image addresses.
 * EXACT* is the 2-byte alignment pad after the last pop.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef signed int     s32;
struct Ctx;
struct Rec;
extern void *func_0216D67C(void *a0);
extern void *func_0216D530(void *p);
extern void *func_021BB480(void *p);
extern void func_021B7D38();
extern int func_021B7C38(u8 *o);
extern u32 func_0207C768(u32 a, u32 b);
extern int func_0216DD1C(struct Ctx *c, struct Rec **out, u32 *iter);
extern int func_0216D55C(int a0, int a1);
extern void *func_0219E348(void *a);
extern u8 func_021B8040(u8 *p);
extern u8 func_021B8038(u8 *p);
extern void func_021B7E60();
extern void func_021B7ED4();
extern int func_021B83B0(const s32 *a, const s32 *b, s32 r);

int func_0219E498(u32 o, u32 k)
{
    u32 t;
    u32 h;
    u32 m;
    u8 rec[12];
    u8 tA[12];
    u32 cur;
    u32 st;
    u32 lim;
    u32 s;
    int z;

    s = (u32)func_0216D67C((void *)o);
    h = (u32)func_021BB480(func_0216D530((void *)s));
    st = 0;
    func_021B7D38(h, k, rec);
    m = func_0207C768(func_021B7C38((u8 *)h), 0x4000);
    while (func_0216DD1C((struct Ctx *)s, (struct Rec **)(&cur), &st) == 1) {
        lim = 0x4000 >> 1;
        if (cur == o) {
            continue;
        }
        if (func_0216D55C(cur, 0x80) != 0) {
            continue;
        }
        z = (func_0216D55C(cur, lim) == 0);
        if (!z) {
            t = (u32)func_0219E348((void *)cur);
            if (func_021B8040((u8 *)t)) {
                func_021B7E60(t, func_021B8038((u8 *)t), 0, tA);
                if (func_021B83B0((const s32 *)rec, (const s32 *)tA, m)) {
                    return 1;
                }
            }
            func_021B7ED4(t, tA);
            if (func_021B83B0((const s32 *)rec, (const s32 *)tA, m)) {
                return 1;
            }
        }
    }
    return 0;
}
