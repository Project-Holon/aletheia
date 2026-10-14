/*
 * function: GSYNC_STATE_StateShowEmptyMessage
 * address: 0x021D834C
 * packet: pkt_ov123_021D834C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GSYNC_MESSAGE_ClearStream 0x021D584C thumb ov123
 *   GSYNC_DISP_CreateSlotActor 0x021D62B4 thumb ov123
 *   GSYNC_MESSAGE_PrintStreamId 0x021D57B8 thumb ov123
 *   GSYNC_STATE_ChangeState 0x021D6EE0 thumb ov123
 *   GSYNC_STATE_StateOpenConfirmMenu 0x021D8304 thumb ov123
 */
#include "../include/Obj03797.h"
extern void GSYNC_MESSAGE_ClearStream(char *);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Sub02009210Obj;
extern void GSYNC_DISP_CreateSlotActor(u8 *p, unsigned int i);
struct Sub02009448Obj;
extern struct Sub02009448Obj *func_02009448(void *sys);
extern u32 func_02009370(const struct Sub02009210Obj *obj);
extern void GSYNC_MESSAGE_PrintStreamId(char *, int);
extern void GSYNC_STATE_ChangeState(u8 *p, u32 v, int unused);
extern void GSYNC_STATE_StateOpenConfirmMenu(char *p);
void GSYNC_STATE_StateShowEmptyMessage(char *p)
{
    GSYNC_MESSAGE_ClearStream(*(char * *)&((struct Obj03797 *)p)->f18);
    GSYNC_DISP_CreateSlotActor((u8 *)(*(char * *)&((struct Obj03797 *)p)->f14), 0);
    GSYNC_DISP_CreateSlotActor((u8 *)(*(char * *)&((struct Obj03797 *)p)->f14), 12);
    GSYNC_DISP_CreateSlotActor((u8 *)(*(char * *)&((struct Obj03797 *)p)->f14), 6);
    GSYNC_DISP_CreateSlotActor((u8 *)(*(char * *)&((struct Obj03797 *)p)->f14), 8);
    if (func_02009370((const struct Sub02009210Obj *)func_02009448(((struct Obj03797 *)p)->f28)))
        GSYNC_MESSAGE_PrintStreamId(*(char * *)&((struct Obj03797 *)p)->f18, 21);
    else
        GSYNC_MESSAGE_PrintStreamId(*(char * *)&((struct Obj03797 *)p)->f18, 10);
    GSYNC_STATE_ChangeState((u8 *)p, (int)GSYNC_STATE_StateOpenConfirmMenu, 0x64c);
}
