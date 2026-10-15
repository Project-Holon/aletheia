/*
 * function: B_PLIST_MAIN_RecreateCursor
 * address:  0x022119F8
 * packet:   pkt_022119F8
 * region:   ov198
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   B_PLIST_MAIN_DeleteCursor  0x022119E8  thumb  ov198
 *   B_PLIST_MAIN_CreateCursor  0x02211998  thumb  ov198
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 B_PLIST_MAIN_DeleteCursor(u8 *p);
extern void B_PLIST_MAIN_CreateCursor(u8 *, u32, u32);

void B_PLIST_MAIN_RecreateCursor(u8 *p, u32 a, u32 b)
{
    B_PLIST_MAIN_DeleteCursor(p);
    B_PLIST_MAIN_CreateCursor(p, a, b);
}

