/*
 * function: INTRUDE_SUBDISP_MainRequestAnswerSeq
 * address:  0x0217C914
 * packet:   pkt_ov018_0217C914
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   EVENT_COMM_COMMON_PrintMsg  0x0217F3C4  thumb  ov018
 *   INTRUDE_COMM_SendRequest  0x02173A2C  thumb  ov011
 *   INTRUDE_COMM_TakeRequestResult  0x02175514  thumb  ov011
 *   EVENT_COMM_COMMON_IsPrintFinished  0x0217F40C  thumb  ov018
 *   func_020362DC  0x020362DC  arm
 *   INTRUDE_COMM_SendAnswer  0x02173B9C  thumb  ov011
 *   INTRUDE_COMM_NextRequestToken  0x021753B8  thumb  ov011
 *   EVENT_COMM_COMMON_IsKeyTrg  0x0217F420  thumb  ov018
 *   INTRUDE_COMM_SendReply  0x02173AE0  thumb  ov011
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void EVENT_COMM_COMMON_PrintMsg(u8 *, int);
struct T;
extern int INTRUDE_COMM_SendRequest(unsigned char *p, int b, struct T *c, int d);
extern int INTRUDE_COMM_TakeRequestResult(u8 *);
extern int EVENT_COMM_COMMON_IsPrintFinished(u8 *);
extern u32 func_020362DC(void);
extern int INTRUDE_COMM_SendAnswer(int a, int b);
extern void INTRUDE_COMM_NextRequestToken(u8 *);
extern int EVENT_COMM_COMMON_IsKeyTrg(void);
extern int INTRUDE_COMM_SendReply(int a, int b, int c, int d);

int INTRUDE_SUBDISP_MainRequestAnswerSeq(u8 *v, u8 *w, u8 *state)
{
    switch (*state) {
    case 0:
        EVENT_COMM_COMMON_PrintMsg(w + 0x10, 0);
        (*state)++;
        break;
    case 1:
        if (INTRUDE_COMM_SendRequest(v, v[0x154], (struct T *)(w + 0x44), w[0x41]) == 1)
            (*state)++;
        break;
    case 2:
        switch (INTRUDE_COMM_TakeRequestResult(v)) {
        case 1:
            *state = 6;
            break;
        case 2:
        case 3:
            *state = 3;
            break;
        default:
            if (EVENT_COMM_COMMON_IsPrintFinished(w + 0x10) == 1) {
                if ((func_020362DC() & 2) && INTRUDE_COMM_SendAnswer(v[0x154], v[0x158]) == 1) {
                    INTRUDE_COMM_NextRequestToken(v);
                    *state = 9;
                }
            }
            break;
        }
        break;
    case 3:
        if (EVENT_COMM_COMMON_IsPrintFinished(w + 0x10) == 1) {
            EVENT_COMM_COMMON_PrintMsg(w + 0x10, 2);
            (*state)++;
        }
        break;
    case 4:
        if (EVENT_COMM_COMMON_IsPrintFinished(w + 0x10) == 1)
            (*state)++;
        break;
    case 5:
        if (EVENT_COMM_COMMON_IsKeyTrg() == 1)
            *state = 8;
        break;
    case 6:
        if (INTRUDE_COMM_SendReply((int)v, v[0x154], 1, v[0x158]) == 1)
            *state = 7;
        break;
    case 7:
        if (EVENT_COMM_COMMON_IsPrintFinished(w + 0x10) == 1)
            return 1;
        break;
    case 8:
        return 2;
    case 9:
        return 3;
    }
    return 0;
}
