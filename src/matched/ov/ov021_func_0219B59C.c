/*
 * function: func_0219B59C
 * address:  0x0219B59C
 * packet:   pkt_ov021_0219B59C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021D5238     0x021D5238  data   ov021  a4
 *   d_021D5248     0x021D5248  data   ov021  a4
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

typedef struct Tbl4 { u32 w[4]; } Tbl4;
typedef struct Tbl22 { u32 w[2][2]; } Tbl22;

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

extern Tbl4 d_021D5238;
extern Tbl22 d_021D5248;

extern St *func_0216D6B8(int a);
extern u16 func_0216D5F8(int a);
extern u32 func_02197E7C(u16 a, u16 b);
extern void func_0216D438(int a, u16 b);
extern u32 func_02197EDC(int a);
extern u16 func_0216D5A8(int a);
extern int func_0219B8A8(void);
extern int func_02164168(int a);
extern void func_0216D5E0(int a, u32 b);

int func_0219B59C(int a)
{
    St *p;
    int lim;

    p = func_0216D6B8(a);
    switch (p->state) {
    case 0: {
        Tbl4 t = d_021D5238;
        u16 v = func_0216D5F8(a);
        p->f4 = v;
        p->f5 = t.w[v];
        p->state++;
    }
    case 1: {
        Tbl22 t = d_021D5248;
        func_0216D438(a, func_02197E7C(t.w[p->f5][p->f6], 0));
        p->state++;
    }
    case 2:
        if (func_02197EDC(a) == 0) {
            return 1;
        }
        p->state++;
    case 3:
        lim = 8;
        if (func_0216D5A8(a) == 14 && func_0219B8A8() == 1 && func_02164168(a) == 1) {
            lim = 4;
        }
        if (++p->f8 < lim) {
            return 1;
        }
        p->f8 = 0;
        if (++p->f7 < 4) {
            p->f6 = (p->f6 + 1) & 1;
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
