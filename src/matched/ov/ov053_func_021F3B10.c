/*
 * function: FIELD_GIMMICK_SOUND_OBJS_RaiseBgmVolume
 * address: 0x021F3B10
 * packet: pkt_ov053_021F3B10
 * region: ov053
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 */
#include "../include/Obj03650.h"

void FIELD_GIMMICK_SOUND_OBJS_RaiseBgmVolume(char *p, int target) { ((struct Obj03650 *)p)->f64 += 16; if (target < ((struct Obj03650 *)p)->f64) ((struct Obj03650 *)p)->f64=target; }
