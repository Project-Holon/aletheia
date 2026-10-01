/*
 * function: func_021BC794
 * address:  0x021BC794
 * packet:   pkt_ov021_021BC794
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
    char pad[0x34];
    void *f34;
} Obj;

extern unsigned short func_021BD090(Obj *p);
extern void *func_0204B100(int a, int b, int c);
extern void func_0204B22C(void *a, int b);

void func_021BC794(Obj *p)
{
    p->f34 = func_0204B100(0x1E, 1, func_021BD090(p));
    func_0204B22C(p->f34, 1);
}
