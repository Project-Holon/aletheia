/*
 * function: func_021B9CCC
 * address:  0x021B9CCC
 * packet:   pkt_021B9CCC
 * region:   ov221
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 */

struct Obj;
extern void func_0204B3B4(struct Obj *p);
typedef unsigned int   u32;
extern void func_0204AFD8(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204ADA4(u32 i);

void func_021B9CCC(char *p)
{
    func_0204B3B4(*(void **)(p + 0x54));
    func_0204AFD8((u32)(*(void **)(p + 0x50)));
    func_0204A8D4((u32)(*(void **)(p + 0x48)));
    func_0204ADA4((u32)(*(void **)(p + 0x4c)));
}
