/*
 * function: B_PLIST_MAIN_IsBattleSlot
 * address:  0x02210F04
 * packet:   pkt_02210F04
 * region:   ov198
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   B_PLIST_MAIN_GetOwnerFlag18  0x02210EFC  thumb  ov198
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern int B_PLIST_MAIN_GetOwnerFlag18(char **p);

u32 B_PLIST_MAIN_IsBattleSlot(u32 a, u32 b)
{
    if (B_PLIST_MAIN_GetOwnerFlag18((char **)a) == 1 && b >= 3) {
        return 1;
    }
    return 0;
}

