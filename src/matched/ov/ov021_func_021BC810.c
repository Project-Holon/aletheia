/*
 * function: func_021BC810
 * address:  0x021BC810
 * packet:   pkt_ov021_021BC810
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
    char pad[0x10];
    void *f10;
} Obj;

extern int func_021BD090(Obj *p);
extern void *func_020490F4(unsigned int id, unsigned int heap);

void func_021BC810(Obj *p)
{
    p->f10 = func_020490F4(0x54, func_021BD090(p));
}
