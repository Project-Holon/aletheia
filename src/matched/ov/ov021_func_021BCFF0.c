/*
 * function: func_021BCFF0
 * address:  0x021BCFF0
 * packet:   pkt_ov021_021BCFF0
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
    char pad[0x14];
    void *f14;
} Obj;

extern unsigned short func_021BD090(Obj *p);
extern void *func_02045B38(int a, int b, int c, int d);

void func_021BCFF0(Obj *p)
{
    p->f14 = func_02045B38(0, 2, 0x59, func_021BD090(p));
}
