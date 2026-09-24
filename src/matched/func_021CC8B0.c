/*
 * function: func_021CC8B0
 * address:  0x021CC8B0
 * packet:   pkt_021CC8B0
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021CC8B0   0x021CC8B0  thumb ov093
 *
 * indexed store
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

void func_021CC8B0(u32 *p, u32 i, u32 b)
{
    *(u32 *)&p[i] = b;
}
