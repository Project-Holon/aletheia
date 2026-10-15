/*
 * function: RESEARCH_LIST_IncKeyRepeatTimer
 * address:  0x021BC600
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Increment the u32 at +0x54.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void RESEARCH_LIST_IncKeyRepeatTimer(void *p)
{
    u32 *c = (u32 *)((char *)p + 0x54);
    *c += 1;
}
