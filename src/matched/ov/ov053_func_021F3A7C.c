/*
 * function: GIMMICK53_UpdateBgmFade
 * address: 0x021F3A7C
 * packet: pkt_ov053_021F3A7C
 * region: ov053
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GIMMICK53_GetBgmTargetVolume 0x021F3AA0 thumb ov053
 *   GIMMICK53_RaiseBgmVolume 0x021F3B10 thumb ov053
 *   GIMMICK53_LowerBgmVolume 0x021F3B20 thumb ov053
 */
#include "../include/Obj03650.h"

extern int GIMMICK53_GetBgmTargetVolume(char *, int);
extern void GIMMICK53_RaiseBgmVolume(char *,int);
extern void GIMMICK53_LowerBgmVolume(char *,int);
void GIMMICK53_UpdateBgmFade(char *p, int a) { int v=GIMMICK53_GetBgmTargetVolume(p,a); if (((struct Obj03650 *)p)->f64<v) GIMMICK53_RaiseBgmVolume(p,v); else if(v<((struct Obj03650 *)p)->f64) GIMMICK53_LowerBgmVolume(p,v); }
