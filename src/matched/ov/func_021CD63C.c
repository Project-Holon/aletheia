/*
 * function: BTL_SERVER_CMD_WriteU8Wrapper
 * address:  0x021CD63C
 * packet:   pkt_021CD63C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_CMD_WriteU8   0x021CCAA8  thumb ov093
 *   BTL_SERVER_CMD_WriteU8Wrapper   0x021CD63C  thumb ov093
 *
 * tail-call thunk to BTL_SERVER_CMD_WriteU8
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern void BTL_SERVER_CMD_WriteU8(void *p, int v);

void BTL_SERVER_CMD_WriteU8Wrapper(void *p, int v)
{
    BTL_SERVER_CMD_WriteU8(p, v);
}
