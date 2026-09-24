/*
 * function: func_021C2748
 * address:  0x021C2748
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C28A4  0x021C28A4  thumb  ov217
 *   func_021C28BC  0x021C28BC  thumb  ov217
 *
 * Pushes the +0x10 body through func_0204B3DC, then the +0x14 body when
 * func_021C28BC() is busy, the +0x18 body when either query fires, and the
 * +0x1c body unconditionally.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 func_0204B3DC();
extern u32 func_021C28A4();
extern u32 func_021C28BC();
void func_021C2748(u32 a0, u32 a1)
{
    func_0204B3DC(*(u32*)(((u8*)a0) + 16), a1);
    if (func_021C28BC(a0) != 0) {
    func_0204B3DC(*(u32*)(((u8*)a0) + 20), a1);
    }
    if (func_021C28BC(a0) != 0 || func_021C28A4(a0) != 0) {
    func_0204B3DC(*(u32*)(((u8*)a0) + 24), a1);
    }
    func_0204B3DC(*(u32*)(((u8*)a0) + 28), a1);
}
