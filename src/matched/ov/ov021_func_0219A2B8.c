/*
 * function: func_0219A2B8
 * address:  0x0219A2B8
 * packet:   pkt_ov021_0219A2B8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D69C  0x0216D69C  thumb  ov010
 *   func_0216DA50  0x0216DA50  thumb  ov010
 *   func_0216DA7C  0x0216DA7C  thumb  ov010
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_02197E7C  0x02197E7C  thumb  ov021
 *   func_0216D438  0x0216D438  thumb  ov010
 *   func_02197EDC  0x02197EDC  thumb  ov021
 *   func_0219B0F0  0x0219B0F0  thumb  ov021
 *   func_0219B104  0x0219B104  thumb  ov021
 *   func_0216D60C  0x0216D60C  thumb  ov010
 *   func_0219A4CC  0x0219A4CC  thumb  ov021
 *   func_021639C0  0x021639C0  thumb  ov010
 *   func_0216DA44  0x0216DA44  thumb  ov010
 *   d_021D4FA4     0x021D4FA4  data  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef struct {
    s16 state;
    s16 timer;
    int mode;
    u32 arg;
    u32 v;
} St;
extern St *func_0216D69C(u32);
extern void func_0216DA50(u32);
extern void func_0216DA7C(u32);
extern u32 func_0216D5F8(u32);
extern u32 func_02197E7C(u16, u16);
extern void func_0216D438(u32, u16);
extern int func_02197EDC(u32);
extern u16 func_0219B0F0(void *, int);
extern u32 func_0219B104(u32, u32);
extern void func_0216D60C(u32, u16);
extern int func_0219A4CC(u32, u32);
extern int func_021639C0(u32, u16);
extern void func_0216DA44(u32);
extern u8 d_021D4FA4[];

void func_0219A2B8(u32 a)
{
    St *p;
    u32 r;
    int f;

    p = func_0216D69C(a);
    switch (p->state) {
    case 0:
        func_0216DA50(a);
        func_0216DA7C(a);
        func_0216D438(a, func_02197E7C(func_0216D5F8(a), 0));
        p->state++;
        break;
    case 1:
        if (func_02197EDC(a) == 0)
            break;
        p->timer = func_0219B0F0(d_021D4FA4, -1);
        p->state++;
    case 2:
        p->timer--;
        if (p->timer != 0)
            break;
        p->state++;
    case 3:
        r = func_0219B104(p->v, 9);
        func_0216D60C(a, r);
        if (p->mode == 1 && func_0219A4CC(a, r) == 0) {
            p->state = 0;
            return;
        }
        f = func_021639C0(a, r);
        if (f != 0) {
            if (p->mode == 2) {
                if (f & 1) {
                    p->state = 0;
                    return;
                }
            } else {
                p->state = 0;
                return;
            }
        }
        func_0216D438(a, func_02197E7C(r, p->arg));
        func_0216DA44(a);
        p->state++;
    case 4:
        if (func_02197EDC(a) != 0) {
            func_0216DA50(a);
            p->state = 0;
        }
        break;
    }
}
