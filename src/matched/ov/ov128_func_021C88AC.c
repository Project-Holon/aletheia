/*
 * function: Wf2dmapFriend_CopyPos
 * address:  0x021C88AC
 * packet:   pkt_ov128_021C88AC
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

void Wf2dmapFriend_CopyPos(u16 *d, u16 *unused, u16 *s, u32 unused2, u16 heap)
{
    d[0] = s[0];
    d[1] = s[1];
    d[2] = s[2];
}
