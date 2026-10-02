/*
 * function: func_021CCC50
 * address:  0x021CCC50
 * packet:   pkt_ov021_021CCC50
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   func_02027694  0x02027694  thumb
 *   func_0204AC18  0x0204AC18  arm
 *   func_0202769C  0x0202769C  thumb
 *   func_020276A0  0x020276A0  thumb
 *   func_0204AF28  0x0204AF28  arm
 *   func_02027698  0x02027698  thumb
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_02049238  0x02049238  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_020490F4(unsigned int id, u16 heap);
extern u32 func_02027694(void);
extern u32 func_0204AC18(void *h, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern u32 func_0202769C(u32 a);
extern u32 func_020276A0(u32 a);
extern u32 func_0204AF28(void *h, u32 a, u32 b, u32 c);
extern u32 func_02027698(void);
extern u32 func_0204A6C8(void *h, u32 a, u32 b, u32 c, u32 d);
extern void func_02049238(void *h);

void func_021CCC50(u8 *p)
{
    void *h;
    u32 a;
    u32 b;

    h = func_020490F4(0x53, *(u16 *)(p + 0xc));
    *(u16 *)(p + 0x98) = func_0204AC18(h, func_02027694(), 0, 0xc0, 0, 1, *(u16 *)(p + 0xc));
    a = func_0202769C(1);
    b = func_020276A0(1);
    *(u16 *)(p + 0x9a) = func_0204AF28(h, a, b, *(u16 *)(p + 0xc));
    *(u16 *)(p + 0x9c) = func_0204A6C8(h, func_02027698(), 0, 0, *(u16 *)(p + 0xc));
    func_02049238(h);
}
