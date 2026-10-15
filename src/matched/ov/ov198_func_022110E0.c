/*
 * function: B_PLIST_MAIN_SetSelectionEntry
 * address:  0x022110E0
 * packet:   pkt_022110E0
 * region:   ov198
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   B_PLIST_MAIN_GetOrderIndex  0x022110D4  thumb  ov198
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern int B_PLIST_MAIN_GetOrderIndex(u8 *p, int i);

void B_PLIST_MAIN_SetSelectionEntry(u8 **p, u32 b, u32 c)
{
    u8 v = B_PLIST_MAIN_GetOrderIndex((u8 *)p, c);

    *(u8 *)(*p + b + 0x48) = v;
}

