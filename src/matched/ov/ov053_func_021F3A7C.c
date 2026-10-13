/*
 * function: FIELD_GIMMICK_SOUND_OBJS_UpdateBgmFade
 * address: 0x021F3A7C
 * packet: pkt_ov053_021F3A7C
 * region: ov053
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FIELD_GIMMICK_SOUND_OBJS_GetBgmTargetVolume 0x021F3AA0 thumb ov053
 *   FIELD_GIMMICK_SOUND_OBJS_RaiseBgmVolume 0x021F3B10 thumb ov053
 *   FIELD_GIMMICK_SOUND_OBJS_LowerBgmVolume 0x021F3B20 thumb ov053
 */
#include "../include/Obj03650.h"

extern int FIELD_GIMMICK_SOUND_OBJS_GetBgmTargetVolume(char *, int);
extern void FIELD_GIMMICK_SOUND_OBJS_RaiseBgmVolume(char *,int);
extern void FIELD_GIMMICK_SOUND_OBJS_LowerBgmVolume(char *,int);
void FIELD_GIMMICK_SOUND_OBJS_UpdateBgmFade(char *p, int a) { int v=FIELD_GIMMICK_SOUND_OBJS_GetBgmTargetVolume(p,a); if (((struct Obj03650 *)p)->f64<v) FIELD_GIMMICK_SOUND_OBJS_RaiseBgmVolume(p,v); else if(v<((struct Obj03650 *)p)->f64) FIELD_GIMMICK_SOUND_OBJS_LowerBgmVolume(p,v); }
