/*
 * function: func_021BC048
 * address:  0x021BC048
 * packet:   pkt_ov021_021BC048
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216E1C4  0x0216E1C4  thumb  ov010
 *   func_0216DC34  0x0216DC34  thumb  ov010
 *   func_0216D7A8  0x0216D7A8  thumb  ov010
 *   func_0216E3C4  0x0216E3C4  thumb  ov010
 *   func_021AC154  0x021AC154  thumb  ov021
 *   func_0219C928  0x0219C928  thumb  ov021
 *   func_0219C9E0  0x0219C9E0  thumb  ov021
 *   func_021BC138  0x021BC138  thumb  ov021
 *
 * The zeroed V3 is a block-scope declaration with an initialiser: that is
 * what materialises `add r6, sp, #0xc` before the three stores and keeps r6
 * across the func_0216E3C4 call (plain element stores fold to sp-relative).
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { int x, y, z; } V3;

typedef struct Obj {
    int f0;
    int f4;
    int f8;
    int fC;
    u8 b10;
    u8 b11;
    u8 pad12[0x1c - 0x12];
    u32 f1c;
    u32 f20;
    u8 pad24[4];
    u16 h28;
    u16 h2a;
    u8 f2c[4];
} Obj;

extern int func_0216E1C4(int a0, int a1);
extern int func_0216DC34(void *a0);
extern int func_0216D7A8(void *p, unsigned int v);
extern void *func_0216E3C4(void *p);
extern u32 func_021AC154(u32 a);
extern int func_0219C928(u32 a, const u8 *b, u16 *c, V3 *d, u32 s0, u32 s1);
extern void func_0219C9E0(u32 a, u16 *b, u16 *c);
extern void func_021BC138(void);

void func_021BC048(u32 a0, Obj *p)
{
    u16 s[2];
    int h;

    if (func_0216E1C4(p->f1c, (int)p->f2c) == 0 || func_0216DC34((void *)p->f1c) == 0) {
        func_021AC154(a0);
        return;
    }
    h = func_0216D7A8((void *)p->f1c, 0);
    if (p->b10 == 0) {
        if (h == 0xFFFF) return;
        {
            V3 v = {0, 0, 0};
            func_0219C928(p->f20, func_0216E3C4((void *)p->f1c), &p->h28, &v,
                          (u32)func_021BC138, (u32)p);
        }
        p->b10 = 1;
    }
    if (p->h2a == 0xFFFF) return;
    if (p->b11 == 0) {
        int t;
        func_0219C9E0(p->f1c, &s[1], &s[0]);
        t = s[1];
        p->f0 = t;
        p->f4 = s[0];
        p->f8 = t;
        p->b11 = 1;
    }
    p->f8 += p->fC;
    if (p->f8 >= p->f0 + 0x400) {
        p->f8 = p->f0 + 0x400;
        p->fC = -p->fC;
        return;
    }
    if (p->f8 <= p->f0 - 0x400) {
        p->f8 = p->f0 - 0x400;
        p->fC = -p->fC;
    }
}
