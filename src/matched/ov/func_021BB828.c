/*
 * function: BTL_SERVER_ClearClient
 * address:  0x021BB828
 * packet:   pkt_021BB828
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_SERVER_ClearClient   0x021BB828  thumb ov093
 *
 * store constant 0xff at #0xb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

void BTL_SERVER_ClearClient(u8 *p)
{
    *(u8 *)&p[0xb] = 0xff;
}
