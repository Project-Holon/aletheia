/*
 * function: func_02185378
 * address:  0x02185378
 * packet:   pkt_ov023_02185378
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02039338  0x02039338  arm
 *   func_021861C4  0x021861C4  thumb  ov023
 *   func_02186444  0x02186444  thumb  ov023
 *   func_02186480  0x02186480  thumb  ov023
 *   func_020061E4  0x020061E4  thumb
 *   func_0207D658  0x0207D658  arm
 *   func_02185354  0x02185354  thumb  ov023
 */

extern int func_02039338(void);
extern void func_021861C4(char *p, int a, int b);
extern void func_02186444(char *p, int v);
extern void func_02186480(char *p);
extern void func_020061E4(int a);
extern void func_0207D658(int a, int b, int c);
extern void func_02185354(char *p);

int func_02185378(char *p, int x)
{
    if (*(int *)(p + 0x1b4) == func_02039338())
        func_021861C4(p, 0xd, 0);
    else
        func_021861C4(p, 0, 0);
    func_02186444(p, 2);
    func_02186480(p);
    func_020061E4(0x54c);
    func_0207D658(0x04000050, 14, -6);
    func_02185354(p);
    return x;
}
