/*
 * function: func_021F7964
 * address:  0x021F7964
 * packet:   pkt_021F7964
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *

 * Release the +0xbf8, +0xd2c and +0xd30 handles.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed short s16;
struct Obj;
extern void func_0204B3B4(struct Obj *p);

void func_021F7964(u8 *p)
{
    func_0204B3B4((struct Obj *)(*(u32 *)(p + 0xbf8)));
    func_0204B3B4((struct Obj *)(*(u32 *)(p + 0xd2c)));
    func_0204B3B4((struct Obj *)(*(u32 *)(p + 0xd30)));
}
