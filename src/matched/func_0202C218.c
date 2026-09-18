/*
 * function: func_0202C218
 * address:  0x0202C218
 * packet:   pkt_0202C218
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u32  func_0202C2D8(u8 *p);
extern int  func_0202C250(u8 *p, u32 v);
extern void func_0202C2DC(u8 *p);
extern int  func_0202C204(u8 *p);

void func_0202C218(u8 *p, u32 v)
{
    if (func_0202C2D8(p) == 0) {
        return;
    }
    if (func_0202C250(p, v) != 0) {
        return;
    }
    func_0202C2DC(p);
    func_0202C204(p);
}
