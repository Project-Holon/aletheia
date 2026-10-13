/*
 * function: IRC_RHYTHM_StateTapping
 * address: 0x021B829C
 * packet: pkt_ov104_021B829C
 * region: ov104
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Enum subblock offset and grouped offset arithmetic retain the far-field register.
 * symbols:
 *   IRC_APPBAR_IsBusy 0x021B727C thumb ov101
 *   IRC_APPBAR_GetResult 0x021B7250 thumb ov101
 *   COMPATIBLE_IRC_SYS_GetValueDifference 0x021B6480 thumb ov101
 *   IRC_RHYTHM_GetTouchTap 0x021B884C thumb ov104
 *   IRC_RHYTHM_JudgeTap 0x021B86A0 thumb ov104
 *   IRC_RHYTHM_SpawnBurst 0x021B8C3C thumb ov104
 *   IRC_RHYTHM_RecordTap 0x021B8624 thumb ov104
 *   IRC_RHYTHM_IsRecordFull 0x021B8614 thumb ov104
 *   IRC_RHYTHM_PrintMessage 0x021B7F1C thumb ov104
 *   IRC_RHYTHM_StateResult 0x021B8384 thumb ov104
 *   IRC_RHYTHM_Finish 0x021B818C thumb ov104
 *   IRC_RHYTHM_SetState 0x021B817C thumb ov104
 *   IRC_RHYTHM_StateAbort 0x021B8528 thumb ov104
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 */
#include "../include/Obj05275.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
extern int IRC_APPBAR_IsBusy(int);
extern int IRC_APPBAR_GetResult(int *);
extern int COMPATIBLE_IRC_SYS_GetValueDifference(int *);
extern int IRC_RHYTHM_GetTouchTap(u32 *p);
extern int IRC_RHYTHM_JudgeTap(u8 *);
extern void IRC_RHYTHM_SpawnBurst(u8 *p, const void *a, int color);
extern void IRC_RHYTHM_RecordTap(u8 *);
extern int IRC_RHYTHM_IsRecordFull(u8 *);
extern void IRC_RHYTHM_PrintMessage(u8 *,void *,int,int,s16);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void IRC_RHYTHM_StateResult(u8 *,u16 *);
extern void IRC_RHYTHM_Finish(u8 *);
extern void IRC_RHYTHM_SetState(char *p, u32 v);
extern void IRC_RHYTHM_StateAbort(u8 *,u16 *);
#define CTX(p) (*(u8 **)((p)+0x8b0))
typedef enum { BASE=0x814 } Offset;
void IRC_RHYTHM_StateTapping(u8 *p,u16 *state) {
 Offset base=BASE;
 int point[2];
 *(u32 *)(p+(base+0x98))=0;
 if(!IRC_APPBAR_IsBusy(*(int *)(p+(base-0x68)))) {
  if(IRC_RHYTHM_GetTouchTap((u32 *)point)) {
   IRC_RHYTHM_SpawnBurst(p+0x278,point,IRC_RHYTHM_JudgeTap(p+base));
   if(!*(u16 *)(p+(base+0x8c))) IRC_RHYTHM_RecordTap(p+base);
   ((struct Obj05275 *)p)->f8AC=1;
  }
 }
 if(IRC_RHYTHM_IsRecordFull(p+base)) {
  if(!((struct Obj05275 *)p)->f89C) {
   IRC_RHYTHM_PrintMessage(p+0xcc,p+0xbc,1,0,0);
   GFL_USE_PlaySeDefaultVolume(0x654);
   ((struct Obj05275 *)p)->f89C=1;
  }
  if(((struct Obj05275 *)p)->f89C) IRC_RHYTHM_StateResult(p,(u16 *)(p+0x8a0));
 }
 if(!((struct Obj05275 *)p)->f89C) {
  if(IRC_APPBAR_GetResult(*(int * *)&((struct Obj05275 *)p)->f7AC)==1) { *(u32 *)(CTX(p)+0xc)=1; IRC_RHYTHM_Finish(p); }
  if(COMPATIBLE_IRC_SYS_GetValueDifference(*(int **)(CTX(p)+4))) IRC_RHYTHM_SetState((char *)p,(u32)IRC_RHYTHM_StateAbort);
 }
}
