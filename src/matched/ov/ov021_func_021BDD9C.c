/*
 * function: func_021BDD9C
 * address:  0x021BDD9C
 * packet:   pkt_ov021_021BDD9C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0218FE80  0x0218FE80  thumb  ov021
 */

typedef struct {
    void *f0;
    char pad[0x50];
    void *f54;
} Obj;

extern void *func_0218FE80(void *a);

void func_021BDD9C(Obj *p)
{
    p->f54 = func_0218FE80(p->f0);
}
