/*
 * function: FIELD_G3DOBJ_InitResDesc
 * address:  0x021C6AE0
 * packet:   pkt_021C6AE0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call with a zero first argument and a constant size.
 *
 * symbols:
 *   MIi_CpuClear32  0x02082A7C  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void MIi_CpuClear32(u32 a, u32 b, u32 c);

void FIELD_G3DOBJ_InitResDesc(u32 a)
{
    MIi_CpuClear32(0, a, 0x24);
}
