/*
 * function: func_02209C30
 * address:  0x02209C30
 * packet:   pkt_ov094_02209C30
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * 2026-10-01: 4 bytes short. Arms, stack slots and pool are right; the
 * original treats the f28 store as possibly aliasing f18 (case 1 reloads
 * f18 after `f28 = 1`, case 2 loads it after `f28 = 0`), so the dispatch
 * clobbers r0. Tried: int/u32/volatile f18, int f28, array fields, a
 * pointer to f18, an inline Next() helper, `+= 1`. volatile f18 gets case 1
 * right but not case 2's order.
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 f0;
    void *h;
    u32 f8;
    u32 fc;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u32 f28;
    u16 f2c;
} P;

typedef struct {
    u16 a;
    u16 b;
    void *p;
    void *cb;
} Msg;

extern void func_0204B878(void *h, int v);
extern void func_0204B3DC(void *h, int v);
extern void func_0204BA00(void *h, Msg *m);

void func_02209C30(P *p)
{
    Msg m0;
    Msg m1;

    switch (p->f18) {
    case 0:
        if (--p->f1c == 0) {
            func_0204B878(p->h, 1);
            p->f18++;
            m0.p = p;
            m0.a = 1;
            m0.b = p->f20;
            m0.cb = (void *)func_02209C30;
            func_0204BA00(p->h, &m0);
            return;
        }
        break;
    case 1:
        p->f28 = 1;
        p->f18++;
        m1.p = p;
        m1.a = 2;
        m1.b = 0;
        m1.cb = (void *)func_02209C30;
        func_0204BA00(p->h, &m1);
        return;
    case 2:
        func_0204B3DC(p->h, 0);
        p->f28 = 0;
        p->f18++;
        break;
    case 3:
        break;
    }
}
