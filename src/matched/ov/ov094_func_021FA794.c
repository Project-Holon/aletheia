/*
 * function: func_021FA794
 * address: 0x021FA794
 * packet: pkt_ov094_021FA794
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_02030734 0x02030734 arm
 *   func_020307B0 0x020307B0 arm
 *   func_020515CC 0x020515CC arm
 *   func_021FE38C 0x021FE38C thumb ov094
 *   func_021FD1A8 0x021FD1A8 thumb ov094
 *   func_021FD1CC 0x021FD1CC thumb ov094
 *   d_0220AE68 0x0220AE68 data ov094 a1
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern char d_0220AE68[];
extern u32 func_0201134C(void *);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void func_020307B0(void *);
extern int func_020515CC(int *, int, void (*)(void), int *);
extern unsigned int func_021FE38C(char *, unsigned int);
extern int func_021FD1A8(char *p, int v);
extern void func_021FD1CC(void);

int func_021FA794(void *a, char *s)
{
    int *p;
    int slot;
    int arg;

    p = func_02030734((u16)((*(u16 *)(s + 0x238) & 0x7fff) | 0x8000), 0x5c, 1, d_0220AE68, 0x868);
    slot = func_021FD1A8(s, func_021FE38C(s, func_0201134C(a)));
    arg = func_0201134C(a);
    p[0] = (int)a;
    p[8] = func_0201134C(a);
    p[1] = func_0201134C(a);
    p[2] = func_0201134C(a);
    p[3] = 0;
    p[4] = func_0201134C(a);
    p[5] = 0;
    p[9] = func_0201134C(a);
    p[7] = func_0201134C(a);
    p[17] = 0x1000;
    p[18] = func_0201134C(a);
    p[19] = 0x1000;
    p[20] = func_0201134C(a);
    p[21] = func_0201134C(a);
    if (p[21] == 0)
        p[21] = 1;
    if (slot != 16) {
        if (func_020515CC(*(int **)(s + 12 + slot * 4), arg, func_021FD1CC, p) == -1)
            func_020307B0(p);
    } else {
        func_020307B0(p);
    }
    return *(int *)(s + 0x23c);
}
