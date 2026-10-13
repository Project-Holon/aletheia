/*
 * function: FIELD_PLAYER_CORE_SelectMoveDir
 * address:  0x021A3BB4
 * packet:   pkt_ov021_021A3BB4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_PLAYER_CORE_GetHorzDirFromKeys  0x021A3C3C  thumb  ov021
 *   FIELD_PLAYER_CORE_GetVertDirFromKeys  0x021A3C54  thumb  ov021
 *   FIELD_PLAYER_CORE_GetMmdl  0x021A3960  thumb  ov021
 *   FLDMMDL_GetDirMove  0x0216D608  thumb  ov010
 */
#include "../include/Obj12730.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int FIELD_PLAYER_CORE_GetHorzDirFromKeys(u32 keys);
extern int FIELD_PLAYER_CORE_GetVertDirFromKeys(u32 keys);
extern void *FIELD_PLAYER_CORE_GetMmdl(u8 *p);
extern u16 FLDMMDL_GetDirMove(void *p);

u16 FIELD_PLAYER_CORE_SelectMoveDir(u8 *p, u32 keys)
{
    u32 a;
    u32 b;
    u32 c;
    u32 h1;
    u32 h2;

    a = FIELD_PLAYER_CORE_GetHorzDirFromKeys(keys);
    b = FIELD_PLAYER_CORE_GetVertDirFromKeys(keys);
    if (a == 9) {
        return b;
    }
    if (b == 9) {
        return a;
    }
    c = FLDMMDL_GetDirMove(FIELD_PLAYER_CORE_GetMmdl(p));
    h1 = ((struct Obj12730 *)p)->f20;
    h2 = ((struct Obj12730 *)p)->f22;
    if (c != 9) {
        if (a == h1 && b == h2) {
            if (b == c) {
                return b;
            }
            if (a == c) {
                return a;
            }
        }
        if (b != h2) {
            return b;
        }
        return a;
    }
    return b;
}
