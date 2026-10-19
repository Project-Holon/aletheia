/*
 * function: UNION_ONESELF_ColosseumReadyWaitMain
 * address:  0x0217E378
 * packet:   pkt_ov019_0217E378
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   UNION_ONESELF_HandleNetErrorExit  0x0217BB20  thumb  ov019
 *   UNION_MSG_CloseAllWindows  0x0217F074  thumb  ov019
 *   UNION_ONESELF_SetNextPlayCategory  0x0217B8E4  thumb  ov019
 *   UNION_MSG_SetupPrintTalkMsg  0x0217F210  thumb  ov019
 *   UNION_MSG_CheckTalkPrintEnd  0x0217F1EC  thumb  ov019
 *   COLOSSEUM_SendReady  0x02174E20  thumb  ov012
 *   COLOSSEUM_SendReadyCancel  0x02174E64  thumb  ov012
 *   KEY_GetTrg  0x020362DC  arm
 */
#include "../include/Obj19428.h"

typedef unsigned char u8;
typedef unsigned int u32;

int UNION_ONESELF_HandleNetErrorExit(char *p);
void UNION_MSG_CloseAllWindows(void *p);
int UNION_ONESELF_SetNextPlayCategory(char *p, int v);
void UNION_MSG_SetupPrintTalkMsg(u8 *p, u8 *a, u32 b);
u32 UNION_MSG_CheckTalkPrintEnd(u8 *p);
u32 COLOSSEUM_SendReady(void);
u32 COLOSSEUM_SendReadyCancel(void);
u32 KEY_GetTrg(void);

int UNION_ONESELF_ColosseumReadyWaitMain(u8 *w, void *obj, u8 *a2, u8 *state)
{
    u8 *p;

    p = *(u8 * *)&((struct Obj19428 *)w)->f355C;
    if (UNION_ONESELF_HandleNetErrorExit((char *)w) == 1) {
        UNION_MSG_CloseAllWindows(w);
        return 1;
    }
    if (p[0xcb] == 1) {
        UNION_ONESELF_SetNextPlayCategory((char *)w, 0x2f);
        p[0xcb] = 0;
        p[0xdf] = 0;
        return 1;
    }
    switch (*state) {
    case 0:
        UNION_MSG_SetupPrintTalkMsg(w, a2, 0x116);
        (*state)++;
        break;
    case 1:
        if (COLOSSEUM_SendReady() == 1) {
            p[0xdf] = 1;
            (*state)++;
        }
        break;
    case 2:
        if (UNION_MSG_CheckTalkPrintEnd(w) == 1 && (KEY_GetTrg() & 2))
            *state = 100;
        break;
    case 100:
        if (COLOSSEUM_SendReadyCancel() == 1)
            (*state)++;
        break;
    case 101:
        if (p[0xdf] == 0) {
            UNION_ONESELF_SetNextPlayCategory((char *)w, 0x2c);
            return 1;
        }
        break;
    }
    return 0;
}
