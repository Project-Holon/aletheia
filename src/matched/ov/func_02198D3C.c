/*
 * function: FLDMMDL_ACMD_WalkUp3F
 * address:  0x02198D3C
 * packet:   pkt_02198D3C
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Calls func_02198C08(its own argument 1, 0x0, 0x3, 0x7) and returns 0x1.
 *
 * symbols:
 *   func_02198C08  0x02198C08  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int BOOL;

extern void func_02198C08(u32 a1, u32 a2, u32 a3, u32 a4);

u32 FLDMMDL_ACMD_WalkUp3F(u32 a1)
{
    func_02198C08(a1, 0x0, 0x3, 0x7);

    return 0x1;
}

