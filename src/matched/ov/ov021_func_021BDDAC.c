/*
 * function: func_021BDDAC
 * address:  0x021BDDAC
 * packet:   pkt_ov021_021BDDAC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0218FE98  0x0218FE98  thumb  ov021
 */

typedef struct {
    char pad[0x54];
    void *f54;
} Obj;

extern void func_0218FE98(void *a);

void func_021BDDAC(Obj *p)
{
    if (p->f54 != 0) {
        func_0218FE98(p->f54);
        p->f54 = 0;
    }
}
