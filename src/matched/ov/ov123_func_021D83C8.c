/*
 * function: GSYNC_STATE_StateWaitInputClearWindow
 * address: 0x021D83C8
 * packet: pkt_ov123_021D83C8
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   KEY_GetTrg 0x020362DC arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   func_020092E0 0x020092E0 thumb
 *   GSYNC_MESSAGE_ClearWindow 0x021D5A60 thumb ov123
 *   GSYNC_STATE_ChangeState 0x021D6EE0 thumb ov123
 *   GSYNC_STATE_StateSendFinalRequest 0x021D8958 thumb ov123
 */
#include "../include/Obj10447.h"

typedef unsigned int u32;
extern u32 KEY_GetTrg(void);
extern int TOUCHPANEL_GetTrg(void);
extern void GSYNC_MESSAGE_ClearWindow(char *);
struct Sub02009448Obj;
extern struct Sub02009448Obj *func_02009448(void *sys);
typedef unsigned char  u8;
struct Sub02009210Obj;
extern void func_020092E0(struct Sub02009210Obj *obj, u8 value);
extern void GSYNC_STATE_ChangeState(u8 *p, u32 v, int unused);
extern void GSYNC_STATE_StateSendFinalRequest(char *p);
void GSYNC_STATE_StateWaitInputClearWindow(char *p)
{
    if (KEY_GetTrg() != 0 || TOUCHPANEL_GetTrg() != 0) {
        GSYNC_MESSAGE_ClearWindow(*(char * *)&((struct Obj10447 *)p)->f18);
        func_020092E0((struct Sub02009210Obj *)func_02009448(((struct Obj10447 *)p)->f28), 1);
        p[0xaf] = 1;
        GSYNC_STATE_ChangeState((u8 *)p, (int)GSYNC_STATE_StateSendFinalRequest, 0x6a2);
    }
}
