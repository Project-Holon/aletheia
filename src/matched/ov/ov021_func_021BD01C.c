/*
 * function: func_021BD01C
 * address:  0x021BD01C
 * packet:   pkt_ov021_021BD01C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BD090  0x021BD090  thumb  ov021
 */

typedef struct {
    char pad[0x24];
    void *f24;
} Obj;

extern unsigned short func_021BD090(Obj *p);
extern void *func_020450F0(int a, int b, int c, int d, int e, int f, int g);

void func_021BD01C(Obj *p)
{
    func_021BD090(p);
    p->f24 = func_020450F0(3, 0, 1, 0x20, 2, 0, 0);
}
