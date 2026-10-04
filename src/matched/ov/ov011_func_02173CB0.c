/*
 * function: func_02173CB0
 * address:  0x02173CB0
 * packet:   pkt_ov011_02173CB0
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02026478  0x02026478  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200BE48  0x0200BE48  thumb
 *   func_021736D8  0x021736D8  thumb ov011
 *   func_02175648  0x02175648  thumb ov011
 *   func_020399A8  0x020399A8  arm
 *   func_0203D4D0  0x0203D4D0  arm
 */

int func_02026478(int a);
int func_02012EBC(int p);
int func_0200BE48(int sys);
int func_021736D8(void);
void func_02175648(int a, void *b);
struct Entry;
extern struct Entry *func_020399A8(void);
int func_0203D4D0(int a, int b, int c, int d, void *e, int f, int g, int h);

int func_02173CB0(int *a, int b)
{
    int v;
    int buf[4];

    v = func_02026478(a[1]);
    func_0200BE48(func_02012EBC(v));
    if (func_021736D8() == 0) {
        return 1;
    }
    func_02175648(v, buf);
    return func_0203D4D0((int)func_020399A8(), (unsigned char)b, 0x20D, 0x10, buf, 0, 0, 0);
}
