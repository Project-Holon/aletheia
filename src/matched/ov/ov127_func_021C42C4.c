/*
 * function: WIFI_2DCHAR_StepActorAnim
 * address: 0x021C42C4
 * packet: pkt_ov127_021C42C4
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFI_2DCHAR_StepActorAnimDispatch 0x021C4634 thumb ov127
 *   sWifi2dcharAnimFrameCount 0x021C5FB0 data a4
 */
#include "../include/Obj10465.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern const u8 sWifi2dcharAnimFrameCount[];
extern void WIFI_2DCHAR_StepActorAnimDispatch(u8 *);
void WIFI_2DCHAR_StepActorAnim(u8 *p) { int flag; int n; flag=0; n=sWifi2dcharAnimFrameCount[((struct Obj10465 *)p)->fC]; if(n==255) flag=1; else if(n>=((struct Obj10465 *)p)->f14+1) flag=1; if(flag==1) { WIFI_2DCHAR_StepActorAnimDispatch(p); ((struct Obj10465 *)p)->f14+=1; } }
