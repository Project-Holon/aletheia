/*
 * function: BTL_SERVER_FLOW_GetSlotTableEntry
 * address:  0x021CC8B8
 * packet:   pkt_021CC8B8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_SERVER_FLOW_GetSlotTableEntry   0x021CC8B8  thumb ov093
 *
 * indexed load
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

u32 BTL_SERVER_FLOW_GetSlotTableEntry(u32 *p, u32 i)
{
    return p[i];
}
