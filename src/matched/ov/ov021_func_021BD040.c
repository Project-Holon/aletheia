/*
 * function: func_021BD040
 * address:  0x021BD040
 * packet:   pkt_ov021_021BD040
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef struct {
    char pad[8];
    void *f8;
} Obj;

extern void func_0201ED04(void *a);

void func_021BD040(Obj *p)
{
    if (p->f8 != 0) {
        func_0201ED04(p->f8);
        p->f8 = 0;
    }
}
