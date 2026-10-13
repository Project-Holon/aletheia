/*
 * function: NAMEIN_SETUP_RunNameBalloonEvent
 * address:  0x0216C680
 * packet:   pkt_ov010_0216C680
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_MSGBG_TalkWinMain  0x02191388  thumb  ov021
 *   FIELD_MSGBG_TalkWinDrawCursor  0x021914CC  thumb  ov021
 *   func_020362DC  0x020362DC  arm
 *   func_020061E4  0x020061E4  thumb
 *   FIELD_MSGBG_DeleteTalkWin  0x021912D8  thumb  ov021
 *   FIELD_MSGBG_WaitTalkWinClose  0x021912F8  thumb  ov021
 *   STRBUF_Delete  0x02045808  arm
 */

typedef unsigned int u32;

struct S;
struct U16Vec;
extern u32 FIELD_MSGBG_TalkWinMain(u32 *a);
extern void FIELD_MSGBG_TalkWinDrawCursor(struct S *s);
extern u32 func_020362DC(void);
extern void func_020061E4(u32 a);
extern int FIELD_MSGBG_DeleteTalkWin(u32 a);
extern int FIELD_MSGBG_WaitTalkWinClose(u32 a, u32 b, u32 c, u32 d);
extern void STRBUF_Delete(struct U16Vec *vec);

int NAMEIN_SETUP_RunNameBalloonEvent(int a, int *st, int *o, u32 a3)
{
    switch (*st) {
    case 0:
        if (!FIELD_MSGBG_TalkWinMain((u32 *)o[5]))
            break;
        (*st)++;
    case 1:
        FIELD_MSGBG_TalkWinDrawCursor((struct S *)o[5]);
        if ((func_020362DC() & 3) == 0)
            break;
        func_020061E4(0x547);
        FIELD_MSGBG_DeleteTalkWin(o[5]);
        (*st)++;
        break;
    case 2:
        if (FIELD_MSGBG_WaitTalkWinClose(o[5], (u32)st, (u32)o, a3) == 1) {
            STRBUF_Delete((struct U16Vec *)o[6]);
            return 1;
        }
        break;
    }
    return 0;
}
