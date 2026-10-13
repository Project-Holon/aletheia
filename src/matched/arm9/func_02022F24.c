/*
 * function: WIPE_SUB_RequestLineMaskHBlankEnd
 * address:  0x02022F24
 * packet:   pkt_02022F0C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIPE_RequestClearHBlankSlot  0x02022568  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;


extern void WIPE_RequestClearHBlankSlot(u32 a0, u32 a1, u32 a2);

void WIPE_SUB_RequestLineMaskHBlankEnd(u32 a0, u8 *a1, u32 a2)
{
    WIPE_RequestClearHBlankSlot(a0, a1[0x309], a2);
}
