/*
 * function: func_021C0358
 * address:  0x021C0358
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reconstructed from the listing (.inst decoded).
 *
 * symbols:
 *   func_021C0358  0x021C0358  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 func_0204A8D4();
extern u32 func_0204ADA4();
extern u32 func_0204AFD8();
u32 func_021C0358(u32 a0)
{
    func_0204A8D4(*(u32*)(((u8*)a0) + 872));
    func_0204ADA4(*(u32*)(((u8*)a0) + 876));
    func_0204ADA4(*(u32*)(((u8*)a0) + 884));
    return func_0204AFD8(*(u32*)(((u8*)a0) + 880));
}

