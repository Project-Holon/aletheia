/*
 * function: BR_NET_StepUploadEntry
 * address: 0x021FF900
 * packet: pkt_ov186_021FF900
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GDS_RAP_RequestUploadEntry 0x021D67C8 thumb ov125
 *   func_02034714 0x02034714 arm
 *   BR_NET_SetStep 0x021FFB68 thumb ov186
 *   BR_NET_StepWaitRequest 0x021FF8E4 thumb ov186
 *   gBrNetAssertString 0x02200D98 data a1
 */
#include "../include/Obj14481.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct{int words[32];} Block128;
typedef struct{int words[108];} Block432;
extern int GDS_RAP_RequestUploadEntry(char*,const Block128*,const Block432*);
extern void func_02034714(const char*,u32,const char*);
extern void BR_NET_SetStep(char*,int);
extern void BR_NET_StepWaitRequest(void*,int,int);
extern const char gBrNetAssertString[];
void BR_NET_StepUploadEntry(char*p,int unused,char*q){if(!GDS_RAP_RequestUploadEntry(q,*(const Block128* *)&((struct Obj14481 *)q)->f5A8,*(const Block432* *)&((struct Obj14481 *)q)->f5B0))func_02034714(gBrNetAssertString,0,gBrNetAssertString);BR_NET_SetStep(p,(int)BR_NET_StepWaitRequest);}
