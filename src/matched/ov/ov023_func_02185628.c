/*
 * function: func_02185628
 * address:  0x02185628
 * packet:   pkt_ov023_02185628
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_02039338  0x02039338  arm
 *   func_020399A8  0x020399A8  arm
 *   func_0203D3A8  0x0203D3A8  arm
 *   func_02186444  0x02186444  thumb  ov023
 *   func_02185354  0x02185354  thumb  ov023
 */

typedef unsigned char u8;

extern void func_02082BCC(void *p, int v, int n);
extern int func_02039338(void);
extern int func_020399A8(void);
extern int func_0203D3A8(void *a, unsigned int b, unsigned int c, void *d);
extern void func_02186444(char *p, int v);
extern void func_02185354(char *p);

int func_02185628(char *p, int x)
{
    u8 b[4];

    func_02082BCC(b, 0, 4);
    b[2] = 1;
    b[0] = func_02039338();
    if (func_0203D3A8(func_020399A8(), 0x2905, 4, (void *)b))
        func_02186444(p, 12);
    func_02185354(p);
    return x;
}
