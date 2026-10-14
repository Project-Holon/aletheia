/*
 * function: GSYNC_STATE_StateExtraSaveMain
 * address: 0x021D758C
 * packet: pkt_ov123_021D758C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020090F8 0x020090F8 thumb
 *   GSYNC_STATE_ChangeState 0x021D6EE0 thumb ov123
 *   GSYNC_STATE_StateFreeReceivedMon 0x021D7560 thumb ov123
 *   GAME_DATA_PartSaveMain  0x02012E7C  thumb  arm9
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb  arm9
 */
#include "../include/Obj13986.h"
struct Big;
struct Sub02009210Obj;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern int GAME_DATA_PartSaveMain(char *p, int a1);
struct Sub02007324Ctrl;
extern void func_0200734C(struct Sub02007324Ctrl *,unsigned int);
extern struct Sub02009210Obj *func_02009210(void *sys);
struct Sub020090B0Obj;
extern void func_020090F8(struct Sub020090B0Obj *obj, unsigned char value);
typedef unsigned char  u8;
extern void GSYNC_STATE_StateFreeReceivedMon(u8 *p);
typedef unsigned int   u32;
extern void GSYNC_STATE_ChangeState(u8 *p, u32 v, int unused);
void GSYNC_STATE_StateExtraSaveMain(u8 *a)
{
    int b = (int)GAME_DATA_GetSaveControl((struct Big *)(((struct Obj13986 *)a)->f2C));
    if(GAME_DATA_PartSaveMain((char *)(((struct Obj13986 *)a)->f2C),4)==2) {
        func_0200734C((struct Sub02007324Ctrl *)b,4);
        func_020090F8((struct Sub020090B0Obj *)func_02009210((void *)b),1);
        GSYNC_STATE_ChangeState(a,(int)GSYNC_STATE_StateFreeReceivedMon,0x333);
    }
}
