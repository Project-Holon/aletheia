/*
 * function: func_0219B390
 * address:  0x0219B390
 * packet:   pkt_ov021_0219B390
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216D55C  0x0216D55C  thumb  ov010
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_0216D548  0x0216D548  thumb  ov010
 *   d_021D4FCC     0x021D4FCC  data    a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;

extern u16 func_0216D5F8(void *p);
extern int func_0216D55C(int a, int b);
extern void func_0216D5E0(int a0, int a1);
extern u32 *func_0216D548(u32 *p, u32 v);
extern u32 d_021D4FCC[][4];

void func_0219B390(int a, s8 *b)
{
    int i;
    u32 v;
    u32 n;

    v = func_0216D5F8((void *)a);
    for (i = 0; i < 4 && v != d_021D4FCC[b[1]][i]; i++) {
    }
    i++;
    b[0] = v;
    i %= 4;
    n = d_021D4FCC[b[1]][i];
    if (func_0216D55C(a, 8) != 0) {
        b[2] = 1;
    } else {
        b[2] = 0;
    }
    func_0216D5E0(a, (u16)n);
    func_0216D548((u32 *)a, 8);
}
