/*
 * function: func_021D43C8
 * address:  0x021D43C8
 * packet:   pkt_ov118_021D43C8
 * region:   ov118
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned short u16;

extern void *func_020490F4(unsigned int id, u16 heap);
typedef signed int     s32;
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *);

void func_021D43C8(void *p)
{
    void *h = func_020490F4(0x67, *(u16 *)((char *)p + 0x5F4));
    *(u32 *)((char *)p + 0x8A8) = func_0204A6C8(h, 2, 0, 0, *(u16 *)((char *)p + 0x5F4));
    *(u32 *)((char *)p + 0x88C) = func_0204AC18(h, 3, 0, 0xE0, 0, 1, *(u16 *)((char *)p + 0x5F4));
    *(u32 *)((char *)p + 0x8BC) = func_0204AF28(h, 1, 0, *(u16 *)((char *)p + 0x5F4));
    func_02049238(h);
    *(u32 *)((char *)*(void **)((char *)p + 0xc) + 0xb0) = 0;
}
