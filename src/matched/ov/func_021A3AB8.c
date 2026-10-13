/*
 * function: FIELD_PLAYER_CORE_ChooseMoveDirFromKeys
 * address:  0x021A3AB8
 * packet:   pkt_021A3AB8
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
 *   FIELD_PLAYER_CORE_SelectMoveDir  0x021A3BB4  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 FIELD_PLAYER_CORE_SelectMoveDir(u8 *p, u32 keys);

u16 FIELD_PLAYER_CORE_ChooseMoveDirFromKeys(u32 a, u32 v)
{
    return FIELD_PLAYER_CORE_SelectMoveDir((u8 *)a, (u16)v);
}
