/*
 * function: func_021CF3DC
 * address:  0x021CF3DC
 * packet:   pkt_021CF3DC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   func_0203D378  0x0203D378  arm
 *   func_021CEADC  0x021CEADC  thumb  ov021
 *   func_021CEB04  0x021CEB04  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0203D378(void);
extern u8 *func_021CEADC(u8 *p);
extern u32 func_021CEB04(u32, u32);

int func_021CF3DC(u32 a, u32 b, u32 c, u8 *d)
{
if (func_0203D378() == 1) {
    return (int)func_021CEADC(d);
}
return func_021CEB04((u32)d, c);
}

