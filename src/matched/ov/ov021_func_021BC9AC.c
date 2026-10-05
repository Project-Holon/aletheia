/*
 * function: func_021BC9AC
 * address:  0x021BC9AC
 * packet:   pkt_ov021_021BC9AC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef struct {
    char pad[0x30];
    void *f30;
} Obj;

extern void func_02025588(void *a);

void func_021BC9AC(Obj *p)
{
    if (p->f30 != 0) {
        func_02025588(p->f30);
        p->f30 = 0;
    }
}
