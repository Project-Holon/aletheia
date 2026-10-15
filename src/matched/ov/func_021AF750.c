/*
 * function: SCRCMD_GetItemMachineFlag
 * address:  0x021AF750
 * packet:   pkt_021AF750
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
 *   FILE_UTIL_Check1288  0x02021288  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 FILE_UTIL_Check1288(u32 id);

int SCRCMD_GetItemMachineFlag(u32 a)
{
return ((FILE_UTIL_Check1288(a) << 16) >> 16);
}

