/*
 * function: FIELD_PLAYER_CORE_StoreKeyDirs
 * address:  0x021A3C24
 * packet:   pkt_ov021_021A3C24
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_PLAYER_CORE_GetHorzDirFromKeys  0x021A3C3C  thumb  ov021
 *   FIELD_PLAYER_CORE_GetVertDirFromKeys  0x021A3C54  thumb  ov021
 */
#include "../include/Obj12731.h"

typedef unsigned char  u8;
typedef unsigned short u16;

typedef unsigned int   u32;
int FIELD_PLAYER_CORE_GetHorzDirFromKeys(u32 keys);
int FIELD_PLAYER_CORE_GetVertDirFromKeys(u32 keys);

void FIELD_PLAYER_CORE_StoreKeyDirs(u8 *p, int a)
{
    ((struct Obj12731 *)p)->f20 = FIELD_PLAYER_CORE_GetHorzDirFromKeys(a);
    ((struct Obj12731 *)p)->f22 = FIELD_PLAYER_CORE_GetVertDirFromKeys(a);
}
