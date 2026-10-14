/*
 * function: GSYNC_STATE_StateTrainerRecordSaveStart
 * address: 0x021D8B7C
 * packet: pkt_ov123_021D8B7C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: GAME_DATA_GetTrainerRecord leaves its return in r0 for func_02008DF0.
 * symbols:
 *   func_0203F4E4 0x0203F4E4 arm
 *   func_020093D8 0x020093D8 thumb
 *   func_02009428 0x02009428 thumb
 *   func_020093F0 0x020093F0 thumb
 *   GSYNC_STATE_ChangeState 0x021D6EE0 thumb ov123
 *   GSYNC_STATE_StateSaveErrorExit 0x021D8B0C thumb ov123
 *   GAME_DATA_SaveStart  0x02012DAC  thumb  arm9
 *   GAME_DATA_GetTrainerRecord  0x02012F2C  thumb  arm9
 */
#include "../include/Obj05369.h"
typedef unsigned int u32;
struct RtcDate { u32 year, month, day, week; };
struct Sub02009210Obj;
struct Sub02009448Obj;
extern struct Sub02009448Obj *func_02009448(void *sys);
extern void func_0203F4E4(struct RtcDate *);
extern void func_020093CC(struct Sub02009210Obj *obj, u32 value);
extern u32 func_020093D8(const struct Sub02009210Obj *obj);
extern void func_02009428(struct Sub02009210Obj *obj, int value);
extern void func_020093F0(struct Sub02009210Obj *obj, int value);
struct Sub02008C20Obj;
extern void *GAME_DATA_GetTrainerRecord(int *p);
extern u32 func_02008DF0(struct Sub02008C20Obj *obj, int i);
extern int GAME_DATA_SaveStart(int a0);
typedef unsigned char  u8;
extern void GSYNC_STATE_ChangeState(u8 *p, u32 v, int unused);
extern void GSYNC_STATE_StateSaveErrorExit(char *p);
void GSYNC_STATE_StateTrainerRecordSaveStart(char *p)
{
    void *q;
    struct RtcDate date;
    q=func_02009448(((struct Obj05369 *)p)->f28);
    p[0xaa]=0;
    func_0203F4E4(&date);
    func_020093CC(q, (date.year << 24) | ((date.month & 255) << 16) | ((date.day & 255) << 8) | date.week);
    if (func_020093D8(q)!=127) {
        func_02009428(q,1);
        func_020093F0(q,126);
    }
    ((struct Obj05369 *)p)->f70=50;
    func_02008DF0(GAME_DATA_GetTrainerRecord(((struct Obj05369 *)p)->f2C),119);
    p[0xad]=1;
    GAME_DATA_SaveStart((int)(((struct Obj05369 *)p)->f2C));
    GSYNC_STATE_ChangeState((u8 *)p,(int)GSYNC_STATE_StateSaveErrorExit,0x914);
}
