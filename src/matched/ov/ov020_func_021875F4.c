/*
 * function: func_021875F4
 * address:  0x021875F4
 * packet:   pkt_ov020_021875F4
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_0216FC4C  0x0216FC4C  thumb  ov010
 *   func_0216FAB4  0x0216FAB4  thumb  ov010
 *   d_02187EDC     0x02187EDC  data  ov020  a4
 */

typedef unsigned short u16;
typedef unsigned int u32;

struct P {
    u16 a;
    u16 x0;
    u16 b;
    u16 x1;
    u16 c;
    u16 x2;
};

struct L {
    u16 a;
    u16 b;
    int c;
    int d;
    int e;
    int f;
};

extern void *func_02030734(u32, u32, int, const char *, u16);
extern int func_0216FC4C(void);
extern int func_0216FAB4(int, int, int, int, int, int, int, int, int, struct L *);
extern int d_02187EDC;

int *func_021875F4(int a0, int a1, int a2, int a3, struct P e)
{
    struct L l;
    int *p;

    p = func_02030734(((u16 *)&e)[4], 0x1c, 1, (const char *)&d_02187EDC, 0x19c);
    p[0] = 0;
    *(u16 *)((char *)p + 4) = func_0216FC4C() - 1;
    *(u16 *)((char *)p + 6) = func_0216FC4C() - 1;
    p[4] = -1;
    p[5] = -1;
    if (func_0216FAB4(a0, a1, 0, a2, a3, ((u16 *)&e)[0], ((u16 *)&e)[2], 0xC40, ((u16 *)&e)[4], &l) != 0) {
        p[2] = l.c;
        p[3] = l.d;
        p[4] = l.e;
        *(u16 *)((char *)p + 4) = l.a;
        *(u16 *)((char *)p + 6) = l.b;
        p[5] = l.f;
        p[6] = 0;
    }
    return p;
}
