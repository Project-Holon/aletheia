/*
 * function: BTL_CLIENT_StepAskYesNo
 * address:  0x021D0CC4
 * packet:   pkt_ov093_021D0CC4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021EAF18  0x021EAF18  thumb  ov093
 *   BTLV_CORE_StartYesNoMenu  0x021EABC4  thumb  ov093
 *   BTLV_CORE_PollYesNoMenu  0x021EAC54  thumb  ov093
 */
#include "../include/Obj05202.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    void *battle;         /* 0x00 */
    u8 unk04[0x50];
    void *msgWin;         /* 0x54 */
    u8 msg[0x14E];        /* 0x58 */
    u8 unk1A6;            /* 0x1A6 */
} BattleSeq;

struct L;
extern void func_021EAF18(struct L *p, int kind, int id);
extern void BTLV_CORE_StartYesNoMenu(u8 *a, u32 x, u32 y, u32 z);
extern int BTLV_CORE_PollYesNoMenu(void *win, int *out);

int BTL_CLIENT_StepAskYesNo(BattleSeq *s, int *state)
{
    int t;
    u8 *q;
    u8 f;

    switch (*state) {
    case 0:
        func_021EAF18((struct L *)s->msg, 3, 5);
        func_021EAF18((struct L *)((u8 *)s + 0x7c), 3, 1);
        BTLV_CORE_StartYesNoMenu(s->msgWin, (u32)s->msg, (u32)((u8 *)s + 0x7c), 0);
        (*state)++;
        break;
    case 1:
        if (BTLV_CORE_PollYesNoMenu(s->msgWin, &t)) {
            f = 0;
            if (t != 0)
                f = 1;
            q = (u8 *)s + 0x1ac;
            *q = f;
            *(u8 * *)&((struct Obj05202 *)s)->fD8 = q;
            ((struct Obj05202 *)s)->fDC = 1;
            return 1;
        }
        break;
    }
    return 0;
}
