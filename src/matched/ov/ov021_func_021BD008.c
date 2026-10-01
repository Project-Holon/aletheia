/*
 * function: func_021BD008
 * address:  0x021BD008
 * packet:   pkt_ov021_021BD008
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
    char pad[0x1C];
    void *f1C;
} Obj;

extern int func_021BD090(Obj *p);
extern void *func_020457B0(int a, int b);

void func_021BD008(Obj *p)
{
    p->f1C = func_020457B0(0x21, func_021BD090(p));
}
