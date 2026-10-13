/*
 * function: NAMEIN_SETUP_RunNameBalloonWaitEvent
 * address:  0x0216CAF4
 * packet:   pkt_0216CAF4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_MSGBG_TalkWinMain  0x02191388  thumb
 *   KEY_GetTrg  0x020362DC  arm
 *   FIELD_MSGBG_DeleteTalkWin  0x021912D8  thumb
 *   FIELD_MSGBG_WaitTalkWinClose  0x021912F8  thumb
 *   STRBUF_Delete  0x02045808  arm
 */
#include "../include/Obj07205.h"
#include "../include/Obj09165.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int FIELD_MSGBG_TalkWinMain();
extern u32 KEY_GetTrg(void);
extern int FIELD_MSGBG_DeleteTalkWin();
extern int FIELD_MSGBG_WaitTalkWinClose();
extern int STRBUF_Delete();

int NAMEIN_SETUP_RunNameBalloonWaitEvent(int a0, int a1, int a2)
{
    int t4;
    int t5;

t5 = a1 + 0;
a0 = ((struct Obj09165 *)((char *)t5))->f0;
t4 = a2 + 0;
    if (a0 == 0) goto loc_0216CB0A;
loc_0216CB00:
    if (a0 == 1) goto loc_0216CB1C;
loc_0216CB04:
    if (a0 == 2) goto loc_0216CB2E;
loc_0216CB08:
    goto loc_0216CB42;
loc_0216CB0A:
a0 = ((struct Obj07205 *)t4)->f14;
    a0 = FIELD_MSGBG_TalkWinMain(a0);
loc_0216CB10:
    if (a0 != 1) goto loc_0216CB42;
loc_0216CB14:
a0 = ((struct Obj09165 *)((char *)t5))->f0;
a0 = a0 + 1;
((struct Obj09165 *)((char *)t5))->f0 = a0;
    goto loc_0216CB42;
loc_0216CB1C:
    a0 = KEY_GetTrg();
loc_0216CB20:
a1 = 3;
    if ((a0 & a1) == 0) goto loc_0216CB42;
loc_0216CB26:
a0 = ((struct Obj07205 *)t4)->f14;
    a0 = FIELD_MSGBG_DeleteTalkWin(a0);
loc_0216CB2C:
    goto loc_0216CB14;
loc_0216CB2E:
a0 = ((struct Obj07205 *)t4)->f14;
    a0 = FIELD_MSGBG_WaitTalkWinClose(a0);
loc_0216CB34:
    if (a0 != 1) goto loc_0216CB42;
loc_0216CB38:
a0 = ((struct Obj07205 *)t4)->f18;
    a0 = STRBUF_Delete(a0);
loc_0216CB3E:
a0 = 1;
    return a0;
loc_0216CB42:
a0 = 0;
    return a0;}
