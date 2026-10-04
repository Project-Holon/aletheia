/*
 * function: func_0219B75C
 * address:  0x0219B75C
 * packet:   pkt_ov021_0219B75C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021D5258     0x021D5258  data   ov021  a4
 *   func_0216D6B8  0x0216D6B8  thumb  ov010
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_02197E7C  0x02197E7C  thumb  ov021
 *   func_0216D438  0x0216D438  thumb  ov010
 *   func_02197EDC  0x02197EDC  thumb  ov021
 *   func_0216D5A8  0x0216D5A8  thumb  ov010
 *   func_0219B8A8  0x0219B8A8  thumb  ov021
 *   func_02164168  0x02164168  thumb  ov010
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 */

typedef unsigned char  u8;
typedef signed char    s8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Tbl24 { u32 w[2][4]; } Tbl24;

typedef struct St {
    u8 f0;
    u8 state;
    u8 f2;
    u8 f3;
    s8 f4;
    s8 f5;
    s8 f6;
    s8 f7;
    s8 f8;
} St;

extern Tbl24 d_021D5258;

extern void *func_0216D6B8(void *p);
extern u16 func_0216D5F8(void *p);
extern u32 func_02197E7C(u16 a, u16 b);
extern void func_0216D438(int a, u16 b);
extern u32 func_02197EDC(u8 *p);
extern u16 func_0216D5A8(int a);
extern int func_0219B8A8(void);
extern int func_02164168(int a);
extern void func_0216D5E0(int a0, int a1);

int func_0219B75C(int a)
{
    Tbl24 t = d_021D5258;
    St *p;
    int lim;
    int i;
    u16 v;
    u16 k;

    p = func_0216D6B8((void *)a);
    switch (p->state) {
    case 0:
        v = func_0216D5F8((void *)a);
        for (i = 0; i < 4 && v != t.w[p->f5][i]; i++) {
        }
        i++;
        p->f4 = v;
        p->f6 = i % 4;
        p->state++;
    case 1:
        func_0216D438(a, func_02197E7C(t.w[p->f5][p->f6], 0));
        p->state++;
    case 2:
        if (func_02197EDC((u8 *)a) == 0) {
            return 1;
        }
        p->state++;
    case 3:
        lim = 8;
        k = func_0216D5A8(a);
        if ((k == 15 || k == 16) && func_0219B8A8() == 1 && func_02164168(a) == 1) {
            lim = 4;
        }
        if (++p->f8 < lim) {
            return 1;
        }
        p->f8 = 0;
        if (++p->f7 < 4) {
            p->f6 = (p->f6 + 1) % 4;
            p->state = 1;
            return 1;
        }
        func_0216D5E0(a, p->f4);
        p->state++;
        p->f7 = 0;
        p->f0 = 0;
    }
    return 0;
}
