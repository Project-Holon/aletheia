/*
 * function: B_PLIST_MAIN_ApplyMode7
 * address:  0x02210234
 * packet:   pkt_02210234
 * region:   ov198
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   B_PLIST_MAIN_ApplyMode  0x02210C88  thumb  ov198
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern int B_PLIST_MAIN_ApplyMode(u8 *p, unsigned mode);

u32 B_PLIST_MAIN_ApplyMode7(u32 a)
{
    if (B_PLIST_MAIN_ApplyMode((u8 *)a, 7) == 0) {
        return 0x11;
    }
    return 0x1a;
}

