/*
 * function: FIELD_PLAYER_CORE_RememberKeyDirs
 * address:  0x021A3AC4
 * packet:   pkt_021A3AC4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Widens the second argument to 16 bits before the tail call.
 *
 * symbols:
 *   FIELD_PLAYER_CORE_StoreKeyDirs  0x021A3C24  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void FIELD_PLAYER_CORE_StoreKeyDirs(u8 *p, int a);

void FIELD_PLAYER_CORE_RememberKeyDirs(u32 a, u32 v)
{
    FIELD_PLAYER_CORE_StoreKeyDirs((u8 *)a, (u16)v);
}
