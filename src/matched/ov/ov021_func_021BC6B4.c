/*
 * function: func_021BC6B4
 * address:  0x021BC6B4
 * packet:   pkt_ov021_021BC6B4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef struct {
    char pad[0x14C];
    void *f14C;
    int f150;
} Obj;

extern void func_020307B0(void *a);

void func_021BC6B4(Obj *p)
{
    if (p->f14C != 0) {
        func_020307B0(p->f14C);
        p->f14C = 0;
        p->f150 = 0;
    }
}
