/*
 * function: BTL_SERVER_CMD_ReadU8Wrapper
 * address:  0x021CD644
 * packet:   pkt_021CD644
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_CMD_ReadU8   0x021CCAD4  thumb ov093
 *   BTL_SERVER_CMD_ReadU8Wrapper   0x021CD644  thumb ov093
 *
 * tail-call thunk to BTL_SERVER_CMD_ReadU8
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern u8 BTL_SERVER_CMD_ReadU8(u8 *p);

u8 BTL_SERVER_CMD_ReadU8Wrapper(u8 *p)
{
    return BTL_SERVER_CMD_ReadU8(p);
}
