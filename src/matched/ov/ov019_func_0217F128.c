/*
 * function: UNION_MSG_DeleteTalkWindow
 * address:  0x0217F128
 * packet:   pkt_ov019_0217F128
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_MSGBG_OpenPlainWin  0x0219160C  thumb  ov021
 *   FIELD_MSGBG_DeletePlainWin  0x021915B4  thumb  ov021
 *   STRBUF_Delete  0x02045808  arm
 *   UNION_MSG_DeleteWordSet  0x0217F044  thumb  ov019
 *   FIELD_MSGBG_DeleteMsgData  0x021904C8  thumb  ov021
 */
#include "../include/Obj00033.h"

struct U16Vec;
extern void FIELD_MSGBG_OpenPlainWin(int *p);
typedef unsigned int   u32;
struct Rec;
extern int FIELD_MSGBG_DeletePlainWin(void *a);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void UNION_MSG_DeleteWordSet(unsigned char *p);
extern u32 FIELD_MSGBG_DeleteMsgData(struct Rec *a0);

void UNION_MSG_DeleteTalkWindow(unsigned char *base)
{
    if (*(int *)&((struct Obj00033 *)base)->f280C != 0) {
        FIELD_MSGBG_OpenPlainWin((int *)(*(int *)&((struct Obj00033 *)base)->f280C));
        FIELD_MSGBG_DeletePlainWin((void *)(*(int *)&((struct Obj00033 *)base)->f280C));
        *(int *)&((struct Obj00033 *)base)->f280C = 0;
        *(base + 0x2828) = 0;
        STRBUF_Delete((struct U16Vec *)(((struct Obj00033 *)base)->f2820));
        STRBUF_Delete((struct U16Vec *)(((struct Obj00033 *)base)->f2824));
        ((struct Obj00033 *)base)->f2820 = 0;
        ((struct Obj00033 *)base)->f2824 = 0;
    }
    if (((struct Obj00033 *)base)->f2808 != 0) {
        UNION_MSG_DeleteWordSet(base);
        FIELD_MSGBG_DeleteMsgData((struct Rec *)(((struct Obj00033 *)base)->f2808));
        ((struct Obj00033 *)base)->f2808 = 0;
    }
}
