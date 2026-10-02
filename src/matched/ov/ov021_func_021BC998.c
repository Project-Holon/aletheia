/*
 * function: func_021BC998
 * address:  0x021BC998
 * packet:   pkt_ov021_021BC998
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BD090  0x021BD090  thumb  ov021
 */

typedef struct {
    char pad[0x30];
    void *f30;
    int f34;
} Obj;

extern int func_021BD090(Obj *p);
extern void *func_02025538(unsigned int a0, void *a1);

void func_021BC998(Obj *p)
{
    p->f30 = func_02025538(func_021BD090(p), p->f34);
}
