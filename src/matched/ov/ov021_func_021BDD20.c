/*
 * function: func_021BDD20
 * address:  0x021BDD20
 * packet:   pkt_ov021_021BDD20
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BE1C4  0x021BE1C4  thumb  ov021
 *   func_0218FF00  0x0218FF00  thumb  ov021
 */

typedef struct {
    char pad[0x54];
    void *f54;
} Obj;

typedef unsigned int   u32;
extern int func_021BE1C4(u32 a);
extern void func_0218FF00(void *a);

void func_021BDD20(Obj *p)
{
    if (func_021BE1C4((u32)p)) {
        func_0218FF00(p->f54);
    }
}
