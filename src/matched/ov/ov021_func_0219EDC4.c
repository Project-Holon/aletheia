/*
 * function: func_0219EDC4
 * address:  0x0219EDC4
 * packet:   pkt_ov021_0219EDC4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D69C  0x0216D69C  thumb  ov010
 *   func_0216D5D4  0x0216D5D4  thumb  ov010
 *   func_021642A4  0x021642A4  thumb  ov010
 *   func_0216D60C  0x0216D60C  thumb  ov010
 *   func_0219E2F4  0x0219E2F4  thumb  ov021
 *   func_0216D608  0x0216D608  thumb  ov010
 *   func_0219E418  0x0219E418  thumb  ov021
 *   func_0219E664  0x0219E664  thumb  ov021
 *   func_0219E9A8  0x0219E9A8  thumb  ov021
 *   func_02197E7C  0x02197E7C  thumb  ov021
 *   func_0216D438  0x0216D438  thumb  ov010
 *   func_0216DA44  0x0216DA44  thumb  ov010
 *   func_02197EDC  0x02197EDC  thumb  ov021
 *   func_0216DA50  0x0216DA50  thumb  ov010
 *   func_0219EA78  0x0219EA78  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

typedef struct {
    u16 a;
    u16 b;
    s16 c;
    u16 d;
} T;

typedef struct {
    u8  pad[0xc];
    u8  state;
    u8  d;
    s8  e;
    u8  f;
} E;

extern E *func_0216D69C(u32);
extern u16 func_0216D5D4(void *p);
extern u32 func_021642A4(u16);
extern void func_0216D60C(u32, u16);
extern void func_0219E2F4(u32, T *);
extern u16 func_0216D608(void *p);
extern u32 func_0219E418(u32, u16);
extern void func_0219E664(u32, u16, T *);
extern int func_0219E9A8(u32, u32, s32, T *);
extern u32 func_02197E7C(u16, u16);
extern void func_0216D438(u32, u16);
extern void func_0216DA44(u32);
extern u32 func_02197EDC(u8 *p);
extern void func_0216DA50(u8 *p);
extern int func_0219EA78(E *, u32);

int func_0219EDC4(u32 o)
{
    E *e;
    u32 s;
    u32 k;
    u32 z;
    int r;
    T c;
    T b;

    e = func_0216D69C(o);
    switch (e->state) {
    case 0:
        k = func_0216D5D4((void *)o);
        if (e->d == 1) {
            k = func_021642A4(k);
        }
        func_0216D60C(o, k);
        e->state = 1;
    case 1:
        func_0219E2F4(o, &c);
        if (e->d != 0 && e->f == c.d && e->e == c.c) {
            func_0216D60C(o, func_021642A4(func_0216D608((void *)o)));
            e->d = 0;
        }
        z = 0;
        k = func_0216D608((void *)o);
        s = func_0219E418(o, k);
        func_0219E664(o, k, &b);
        r = func_0219E9A8(o, e->f, e->e, &b);
        if (c.a != b.a) {
            z = 1;
        }
        if ((s & 1) || r || z) {
            e->d = 1;
            k = func_021642A4(k);
            s = func_0219E418(o, k);
            func_0219E664(o, k, &b);
        }
        func_0216D438(o, func_02197E7C(k, s == 0 ? 0xc : 0x20));
        func_0216DA44(o);
        e->state = 2;
        break;
    case 2:
        if (func_02197EDC((u8 *)o) == 1) {
            func_0216DA50((u8 *)o);
            e->state = 0;
        }
        break;
    }
    return func_0219EA78(e, o);
}
