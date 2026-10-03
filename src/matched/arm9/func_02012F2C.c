/*
 * function: func_02012F2C
 * address:  0x02012F2C
 * packet:   pkt_02012F2C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

struct Sub020071CCCtrl;
extern void *func_020071CC(struct Sub020071CCCtrl *ctrl, unsigned int id);
void *func_02012F2C(int *p)
{
    return func_020071CC((struct Sub020071CCCtrl *)*p, 0x26);
}
