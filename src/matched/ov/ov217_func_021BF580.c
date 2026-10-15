/*
 * function: RESEARCH_GRAPH_SetOamEnabled
 * address:  0x021BF580
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Indexed getter + passthrough, tail call to ARM BMP_OAM_SetEnabled.
 *
 * symbols:
 *   BMP_OAM_SetEnabled  0x02025774  thumb  

 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void BMP_OAM_SetEnabled(u8 *g, u32 a);
void RESEARCH_GRAPH_SetOamEnabled(u8 *p, u32 i, u32 j)
{
    BMP_OAM_SetEnabled((u8 *)(*(u32 *)(p + i * 4 + 0x3a8)), j);
}

