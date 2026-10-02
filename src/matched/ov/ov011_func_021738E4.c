/*
 * function: func_021738E4
 * address:  0x021738E4
 * packet:   pkt_ov011_021738E4
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021736D8  0x021736D8  thumb ov011
 *   func_02039338  0x02039338  arm
 *   func_020399A8  0x020399A8  arm
 *   func_021738BC  0x021738BC  thumb ov011
 *   func_0203D3A8  0x0203D3A8  arm
 */

typedef unsigned short u16;

int func_021736D8(void);
int func_02039338(void);
void *func_020399A8(void);
void func_021738BC(int a, int b, int *c, int d, void *e);
int func_0203D3A8(void *a, u16 b, u16 c, void *d);

int func_021738E4(int a, int b, int c, int d)
{
    int h;

    if (func_021736D8() == 0) {
        h = func_02039338();
        func_021738BC(h, 4, &b, a, func_020399A8());
        return 1;
    }
    return func_0203D3A8(func_020399A8(), 0x204, 4, &b);
}
