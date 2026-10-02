/*
 * function: func_021B63D4
 * address:  0x021B63D4
 * packet:   pkt_ov021_021B63D4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02012934  0x02012934  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02166C4C  0x02166C4C  thumb  ov010
 *   func_0215897C  0x0215897C  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ctx;

extern u16 *func_02159AE8(void *a0, void *a1);
extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern void *func_0201210C(const struct Ctx *p);
extern void func_02188C84(void *);
extern void *func_020120F4(void *);
extern void func_02012944(void *);
extern void *func_02012934(void *p);
extern int func_0201AA18(void *);
extern void *func_0201AB28(void *, int);
extern u32 func_02017E1C(void *, u32, u32);
extern int func_02166C4C(void *, void *, void *);
extern void func_0215897C(void *, int);

u32 func_021B63D4(void *a, void *b)
{
    u16 *out = func_02159AE8(a, b);
    void *p10 = func_0215A5F4(b);
    void *pc = func_0215A5DC(b);
    void *t8 = func_0201210C(pc);
    void *t;
    void *party;
    int n;
    int i;

    func_02188C84(t8);
    t = func_020120F4(pc);
    func_02012944(t);
    party = func_02012934(t);
    n = func_0201AA18(party);
    for (i = 0; i < n; i++) {
        void *mon = func_0201AB28(party, i);
        u32 x = func_02017E1C(mon, 0x4c, 0);
        u32 y = func_02017E1C(mon, 3, 0);
        u32 z = func_02017E1C(mon, 9, 0);

        if (x != 0 && y == 0 && z == 0) {
            func_0215897C(p10, func_02166C4C(pc, t8, mon));
            *out = i;
            return 1;
        }
    }
    return 0;
}
