/*
 * function: IRC_RHYTHM_StateResult
 * address: 0x021B8384
 * packet: pkt_ov104_021B8384
 * region: ov104
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   IRC_APPBAR_GetResult 0x021B7250 thumb ov101
 *   COMPATIBLE_IRC_SYS_ResetStep 0x021B63BC thumb ov101
 *   COMPATIBLE_IRC_SYS_StepShareValue 0x021B630C thumb ov101
 *   COMPATIBLE_IRC_SYS_SetOwnValue 0x021B63CC thumb ov101
 *   COMPATIBLE_IRC_SYS_SendOwnValue 0x021B6424 thumb ov101
 *   IRC_APPBAR_SetActive 0x021B72A0 thumb ov101
 *   COMPATIBLE_IRC_SYS_GetValueDifference 0x021B6480 thumb ov101
 *   IRC_RHYTHM_Finish 0x021B818C thumb ov104
 *   IRC_RHYTHM_PrintMessage 0x021B7F1C thumb ov104
 *   IRC_RHYTHM_SendRecord 0x021B8768 thumb ov104
 *   IRC_RHYTHM_CalcSyncScore 0x021B8880 thumb ov104
 *   IRC_RHYTHM_GetPartnerRecord 0x021B87F4 thumb ov104
 *   IRC_RHYTHM_SetState 0x021B817C thumb ov104
 *   IRC_RHYTHM_StateAbort 0x021B8528 thumb ov104
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 */
#include "../include/Obj04432.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef struct {int words[33];} Block;
extern int IRC_APPBAR_GetResult(int *);
extern void COMPATIBLE_IRC_SYS_ResetStep(int *);
extern int COMPATIBLE_IRC_SYS_StepShareValue(int *,int);
extern void COMPATIBLE_IRC_SYS_SetOwnValue(int *,int);
extern int COMPATIBLE_IRC_SYS_SendOwnValue(int);
extern void IRC_APPBAR_SetActive(int,int);
extern int COMPATIBLE_IRC_SYS_GetValueDifference(int *);
extern void IRC_RHYTHM_Finish(u8 *);
extern void IRC_RHYTHM_PrintMessage(u8 *,void *,int,int,s16);
extern int IRC_RHYTHM_SendRecord(u8 *,const Block *);
extern int IRC_RHYTHM_CalcSyncScore(u8 *);
extern void IRC_RHYTHM_GetPartnerRecord(u8 *,Block *);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void IRC_RHYTHM_SetState(char *p, u32 v);
extern void IRC_RHYTHM_StateAbort(u8 *,u16 *);
#define CTX(p) (*(u8 **)((p)+0x8b0))
void IRC_RHYTHM_StateResult(u8 *p,u16 *state) {
 Block data; int diff;
 if(*state<5 && IRC_APPBAR_GetResult(*(int * *)&((struct Obj04432 *)p)->f7AC)==1) {
  COMPATIBLE_IRC_SYS_ResetStep(*(int **)(CTX(p)+4));
  *(u32 *)(CTX(p)+0xc)=1;
  IRC_RHYTHM_Finish(p);
  return;
 }
 switch(*state) {
 case 0: if(COMPATIBLE_IRC_SYS_StepShareValue(*(int **)(CTX(p)+4),2)) *state=1; break;
 case 1: IRC_RHYTHM_PrintMessage(p+0xcc,p+0xbc,2,0,0); *state=2; break;
 case 2: if(IRC_RHYTHM_SendRecord(p+0xe0,(Block *)(p+0x814))) *state=3; break;
 case 3: COMPATIBLE_IRC_SYS_SetOwnValue(*(int **)(CTX(p)+4),2); if(COMPATIBLE_IRC_SYS_SendOwnValue(*(int *)(CTX(p)+4))) *state=4; break;
 case 4: if(COMPATIBLE_IRC_SYS_StepShareValue(*(int **)(CTX(p)+4),3)) { IRC_APPBAR_SetActive(*(int *)&((struct Obj04432 *)p)->f7AC,0); *state=5; } break;
 case 5: if(((struct Obj04432 *)p)->f80A>=60) { GFL_USE_PlaySeDefaultVolume(0x64b); IRC_RHYTHM_PrintMessage(p+0xcc,p+0xbc,3,0,0); *state=6; } break;
 case 6:
  if((((struct Obj04432 *)p)->f8A2)++<30) return;
  CTX(p)[0x10]=IRC_RHYTHM_CalcSyncScore(p);
  IRC_RHYTHM_GetPartnerRecord(p+0xe0,&data);
  diff=((struct Obj04432 *)p)->f88E-*(u16 *)((u8 *)&data+122);
  if(diff<0) diff=-diff;
  *(int *)(CTX(p)+0x14)=diff;
  *(int *)(CTX(p)+0xc)=0;
  *state=7; return;
 case 7: IRC_RHYTHM_Finish(p); return;
 }
 if(*state>=1 && *state<=5) { if(((struct Obj04432 *)p)->f80A<=60) ++((struct Obj04432 *)p)->f80A; }
 if(*state<3) { if(COMPATIBLE_IRC_SYS_GetValueDifference(*(int **)(CTX(p)+4))) IRC_RHYTHM_SetState((char *)p,(u32)IRC_RHYTHM_StateAbort); }
}
