/*
 * function: func_021FB648
 * address:  0x021FB648
 * packet:   pkt_ov094_021FB648
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201134C  0x0201134C  thumb
 *   func_02030734  0x02030734  arm
 *   func_02040588  0x02040588  arm
 *   func_02030DA8  0x02030DA8  arm
 *   func_021F896C  0x021F896C  thumb  ov094
 *   func_021FE79C  0x021FE79C  thumb  ov094
 *   func_021FE8AC  0x021FE8AC  thumb  ov094
 *   d_0220AE68     0x0220AE68  data   ov094  a1
 */
typedef unsigned short u16;

extern char d_0220AE68[];

extern int func_0201134C(int a);
extern int *func_02030734(u16 heap, unsigned int size, unsigned int clear, const char *file, unsigned int line);
extern void func_02040588(int a, int b);
extern int func_02030DA8(int a, void (*fn)(void), int *p, int d);
extern void func_021F896C(int a, void (*fn)(void), int b);
extern void func_021FE79C(void);
extern void func_021FE8AC(void);

int func_021FB648(int a, char *b)
{
    int *p;

    p = func_02030734((*(u16 *)(b + 0x238) & 0x7fff) | 0x8000, 0x28, 1, d_0220AE68, 0xd88);
    p[0] = (int)b;
    p[2] = func_0201134C(a);
    p[3] = func_0201134C(a);
    p[4] = func_0201134C(a);
    p[5] = func_0201134C(a);
    p[6] = func_0201134C(a);
    p[8] = func_0201134C(a);
    p[9] = func_0201134C(a);
    func_02040588(1, 0);
    func_02040588(2, 0);
    func_021F896C(func_02030DA8(*(int *)(b + 8), func_021FE79C, p, 0), func_021FE8AC, 1);
    *(unsigned int *)b |= 0x100;
    return *(int *)(b + 0x23c);
}
