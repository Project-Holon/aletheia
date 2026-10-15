/*
 * function: RESEARCH_LIST_ClearResources
 * address:  0x021BCDDC
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Clear seven u32 slots at +0xf8.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void RESEARCH_LIST_ClearResources(void *p)
{
    int i;
    for (i = 0; i < 7; i++)
        *(u32 *)((char *)p + i * 4 + 0xf8) = 0;
}
