/*
 * function: Wf2dmapFriend_GetEntryIndex
 * address:  0x021C87A0
 * packet:   pkt_021C87A0
 * region:   ov128
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

int Wf2dmapFriend_GetEntryIndex(s16 *p)
{
    int a = p[0] * 8;

    return a + p[2];
}
