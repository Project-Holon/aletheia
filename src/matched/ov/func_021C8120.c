/*
 * function: BTL_SERVER_FLOW_GetScratchBuffer
 * address:  0x021C8120
 * packet:   pkt_021C8120
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_FLOW_GetScratchBuffer   0x021C8120  thumb ov093
 *
 * pointer add #0x1fec
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

u8 *BTL_SERVER_FLOW_GetScratchBuffer(u8 *p, int b)
{
    return p + 0x1fec;
}
