/*
 * function: func_021BD378
 * address:  0x021BD378
 * packet:   pkt_021BD368
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BD404 0x021BD404  thumb  ov208
 *   func_021BD7FC 0x021BD7FC  thumb  ov208
 */

extern int func_021BD404(int, int);
struct Obj;
extern void func_021BD7FC(struct Obj **p, unsigned int v);

void func_021BD378(int a, int b, int c)
{
    func_021BD7FC((struct Obj **)func_021BD404(a, b), c);
}

