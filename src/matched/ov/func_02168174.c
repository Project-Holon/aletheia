/*
 * function: FLD_BTL_INST_TOOL_TrainerMsgEventMain
 * address:  0x02168174
 * packet:   pkt_02168174
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_MSGBG_TalkWinMain  0x02191388  thumb
 *   func_020362DC  0x020362DC  arm
 *   FIELD_MSGBG_DeleteTalkWin  0x021912D8  thumb
 *   FIELD_MSGBG_WaitTalkWinClose  0x021912F8  thumb
 *   STRBUF_Delete  0x02045808  arm
 */
#include "../include/Obj07204.h"
#include "../include/Obj09162.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int FIELD_MSGBG_TalkWinMain();
extern u32 func_020362DC(void);
extern int FIELD_MSGBG_DeleteTalkWin();
extern int FIELD_MSGBG_WaitTalkWinClose();
extern int STRBUF_Delete();

int FLD_BTL_INST_TOOL_TrainerMsgEventMain(int a0, int a1, int a2)
{
    int t4;
    int t5;

t5 = a1 + 0;
a0 = ((struct Obj09162 *)((char *)t5))->f0;
t4 = a2 + 0;
    if (a0 == 0) goto loc_0216818A;
loc_02168180:
    if (a0 == 1) goto loc_0216819C;
loc_02168184:
    if (a0 == 2) goto loc_021681AE;
loc_02168188:
    goto loc_021681C2;
loc_0216818A:
a0 = ((struct Obj07204 *)t4)->f10;
    a0 = FIELD_MSGBG_TalkWinMain(a0);
loc_02168190:
    if (a0 != 1) goto loc_021681C2;
loc_02168194:
a0 = ((struct Obj09162 *)((char *)t5))->f0;
a0 = a0 + 1;
((struct Obj09162 *)((char *)t5))->f0 = a0;
    goto loc_021681C2;
loc_0216819C:
    a0 = func_020362DC();
loc_021681A0:
a1 = 3;
    if ((a0 & a1) == 0) goto loc_021681C2;
loc_021681A6:
a0 = ((struct Obj07204 *)t4)->f10;
    a0 = FIELD_MSGBG_DeleteTalkWin(a0);
loc_021681AC:
    goto loc_02168194;
loc_021681AE:
a0 = ((struct Obj07204 *)t4)->f10;
    a0 = FIELD_MSGBG_WaitTalkWinClose(a0);
loc_021681B4:
    if (a0 != 1) goto loc_021681C2;
loc_021681B8:
a0 = ((struct Obj07204 *)t4)->f14;
    a0 = STRBUF_Delete(a0);
loc_021681BE:
a0 = 1;
    return a0;
loc_021681C2:
a0 = 0;
    return a0;}
