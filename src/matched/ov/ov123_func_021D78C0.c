/*
 * function: GSYNC_STATE_StateMusicalSaveRetry
 * address: 0x021D78C0
 * packet: pkt_ov123_021D78C0
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GSYNC_STATE_ChangeState 0x021D6EE0 thumb ov123
 *   GSYNC_STATE_StateExtraSaveLoadStart 0x021D75D0 thumb ov123
 *   GSYNC_STATE_StateExtraSaveLoadStartSecond 0x021D76F0 thumb ov123
 *   GSYNC_DISP_GetPokeIconActor 0x021D5D8C thumb ov123
 *   GSYNC_STATE_StateMusicalSaveCreate 0x021D77C4 thumb ov123
 */
#include "../include/Obj02837.h"
extern int GSYNC_DISP_GetPokeIconActor(int);
extern void GSYNC_STATE_StateMusicalSaveCreate(int,int);
extern void GSYNC_STATE_StateExtraSaveLoadStart(int a);
extern void GSYNC_STATE_StateExtraSaveLoadStartSecond(int a);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void GSYNC_STATE_ChangeState(u8 *p, u32 v, int unused);
void GSYNC_STATE_StateMusicalSaveRetry(int a)
{
    switch(((struct Obj02837 *)a)->fA7) {
    case 0: GSYNC_STATE_ChangeState((u8 *)a,(int)GSYNC_STATE_StateExtraSaveLoadStart,0x3cb); break;
    case 1: GSYNC_STATE_StateMusicalSaveCreate(a,GSYNC_DISP_GetPokeIconActor(((struct Obj02837 *)a)->f8)-2); break;
    case 2: GSYNC_STATE_ChangeState((u8 *)a,(int)GSYNC_STATE_StateExtraSaveLoadStartSecond,0x3d1); break;
    }
}
