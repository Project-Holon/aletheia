/*
 * function: FLDMMDL_ACMD_DashRight6F
 * address:  0x02198D14
 * packet:   pkt_02198D14
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Calls func_02198C08(its own argument 1, 0x3, 0x6, 0xb) and returns 0x1.
 *
 * symbols:
 *   func_02198C08  0x02198C08  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int BOOL;

extern void func_02198C08(u32 a1, u32 a2, u32 a3, u32 a4);

u32 FLDMMDL_ACMD_DashRight6F(u32 a1)
{
    func_02198C08(a1, 0x3, 0x6, 0xb);

    return 0x1;
}

