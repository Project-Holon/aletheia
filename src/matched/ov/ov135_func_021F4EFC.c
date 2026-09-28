/*
 * function: func_021F4EFC
 * address:  0x021F4EFC
 * packet:   pkt_021F4EFC
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021FFCD4  0x021FFCD4  thumb
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_0204A5AC  0x0204A5AC  arm
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_021FFCD4(u8 *p);
extern void func_0204ADA4(u32 v);
extern void func_0204A8D4(u32 v);
extern void func_0204AFD8(u32 v);
extern void func_0204B1CC(u32 v);
extern void func_0204A5AC(void);

void func_021F4EFC(u8 *p)
{
    func_021FFCD4(p);
    func_0204ADA4(*(u32 *)(p + 0xbe0));
    func_0204A8D4(*(u32 *)(p + 0xbdc));
    func_0204AFD8(*(u32 *)(p + 0xbe4));
    func_0204ADA4(*(u32 *)(p + 0xbd4));
    func_0204A8D4(*(u32 *)(p + 0xbd0));
    func_0204AFD8(*(u32 *)(p + 0xbd8));
    func_0204ADA4(*(u32 *)(p + 0xbc8));
    func_0204A8D4(*(u32 *)(p + 0xbc4));
    func_0204AFD8(*(u32 *)(p + 0xbcc));
    func_0204A8D4(*(u32 *)(p + 0xbe8));
    func_0204AFD8(*(u32 *)(p + 0xbf0));
    func_0204B1CC(*(u32 *)(p + 0xbc0));
    *(u32 *)(p + 0xbc0) = 0;
    func_0204A5AC();
}
