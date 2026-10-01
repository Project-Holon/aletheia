/*
 * function: func_021A1480
 * address:  0x021A1480
 * packet:   pkt_ov021_021A1480
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02034AC4  0x02034AC4  arm
 *   func_021F000C  0x021F000C  thumb  ov033
 *   abs_id_21      0x00000021  data
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern unsigned char abs_id_21[];
extern void func_02034AC4(const void *);
extern u32 func_021F000C(u32, u16, u32 *, u32);

void func_021A1480(u32 *p)
{
    func_02034AC4(abs_id_21);
    p[8] = func_021F000C(0x70, ((u16 *)p)[6], p, p[5]);
}
