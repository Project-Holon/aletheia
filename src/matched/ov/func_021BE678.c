/*
 * function: func_021BE678
 * address:  0x021BE678
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020061E4  0x020061E4  thumb
 *   func_021BE7D8  0x021BE7D8  thumb  ov217
 *   func_021BE934  0x021BE934  thumb  ov217
 *   func_021BEA3C  0x021BEA3C  thumb  ov217
 *   func_021BEAF8  0x021BEAF8  thumb  ov217
 *   func_021BEF98  0x021BEF98  thumb  ov217
 *   func_021BF08C  0x021BF08C  thumb  ov217
 *   func_021BF11C  0x021BF11C  thumb  ov217
 *   func_021BF13C  0x021BF13C  thumb  ov217
 *   func_021BF264  0x021BF264  thumb  ov217
 *   func_021BF2FC  0x021BF2FC  thumb  ov217
 *   func_021BF38C  0x021BF38C  thumb  ov217
 *   func_021BF47C  0x021BF47C  thumb  ov217
 *   func_021BF704  0x021BF704  thumb  ov217
 *   func_021BF76C  0x021BF76C  thumb  ov217
 *   func_021BF810  0x021BF810  thumb  ov217
 *   func_021BFC60  0x021BFC60  thumb  ov217
 *   func_021C116C  0x021C116C  thumb  ov217
 *
 * Per-frame step for the record's +0x3C8 sub-state; the tail is the
 * fixed-order call list that re-arms the sub-system (delta +1).
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 func_020061E4();
extern u32 func_021BE7D8();
extern u32 func_021BE934();
extern u32 func_021BEA3C();
extern u32 func_021BEAF8();
extern u32 func_021BEF98();
extern u32 func_021BF08C();
extern u32 func_021BF11C();
extern u32 func_021BF13C();
extern u32 func_021BF264();
extern u32 func_021BF2FC();
extern u32 func_021BF38C();
extern u32 func_021BF47C();
extern u32 func_021BF704();
extern u32 func_021BF76C();
extern u32 func_021BF810();
extern u32 func_021BFC60();
extern u32 func_021C116C();
u32 func_021BE678(u32 a0)
{
    if (*(u32*)(((u8*)a0) + 968) != 0) {
    if (func_021BF810(a0, *(u32*)(((u8*)a0) + 968)) != 0) {
    func_021BF76C(a0);
    func_021C116C();
    }
    }
    func_021BFC60(a0);
    func_021BF704(a0);
    func_021BEA3C(a0, 1);
    *(u32*)(((u8*)a0) + 968) = 0;
    func_021BF08C(a0);
    func_021BE934(a0);
    func_021BF11C(a0);
    func_021BF13C(a0);
    func_021BE7D8(a0);
    func_021BF264(a0);
    func_021BF2FC(a0);
    func_021BF38C(a0);
    func_021BEF98(a0);
    func_021BF47C(a0);
    func_021BEAF8(a0);
    return func_020061E4(1352);
}
