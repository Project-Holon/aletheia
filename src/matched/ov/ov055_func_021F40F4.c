/*
 * function: CROWD_GetWalkCmdBase
 * address:  0x021F40F4
 * packet:   pkt_021F40F4
 * region:   ov055
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef unsigned char u8;
typedef unsigned int  u32;

u32 CROWD_GetWalkCmdBase(u8 *p)
{
    u32 v = p[0x18];

    if (v == 2)  return 0x14;
    if (v == 4)  return 0x10;
    if (v == 6)  return 0x4c;
    if (v == 8)  return 0xc;
    if (v == 16) return 8;
    return 0xc;
}
