/*
 * function: STA_ACT_EFFECT_GetSceneOwner
 * address: 0x021F9E44
 * packet: pkt_ov132_021F9E44
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
#include "../include/Obj23223.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
u32 STA_ACT_EFFECT_GetSceneOwner(u8 *p) { return ((struct Obj23223 *)p)->f1E8; }
