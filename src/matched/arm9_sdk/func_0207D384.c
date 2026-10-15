/*
 * function: GX_SetVCountEqVal
 * address:  0x0207D384
 * packet:   pkt_0207D384
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      GX_SetVCountEqVal (libgx.TWL.HYB.a gx.o)
 *
 * symbols:
 *   (none)
 */

typedef long fx32;
typedef long s32;
typedef unsigned short u16;
typedef unsigned long u32;
typedef int BOOL;
typedef volatile u16 vu16;
typedef volatile u32 vu32;

#define reg_GX_DISPSTAT (*(vu16 *)0x04000004)

void GX_SetVCountEqVal(s32 val)
{
    reg_GX_DISPSTAT = (u16)((reg_GX_DISPSTAT & 0x3f) | ((val & 0xff) << 8) | ((val & 0x100) >> 1));
}
