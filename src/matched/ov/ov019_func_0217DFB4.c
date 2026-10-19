/*
 * function: UNION_ONESELF_ColosseumStandPosMain
 * address:  0x0217DFB4
 * packet:   pkt_ov019_0217DFB4
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   UNION_ONESELF_HandleNetErrorExit  0x0217BB20  thumb  ov019
 *   UNION_MSG_CloseAllWindows  0x0217F074  thumb  ov019
 *   UNION_MSG_CheckTalkPrintEnd  0x0217F1EC  thumb  ov019
 *   COLOSSEUM_SendChoiceRequest  0x02174CE4  thumb  ov012
 *   COLOSSEUM_GetMyChoiceReply  0x021750D0  thumb  ov012
 *   FLDMMDL_CheckPossibleAcmd  0x0216D3CC  thumb  ov010
 *   UNION_MSG_GetCategoryTableValue  0x0217F060  thumb  ov019
 *   COLOSSEUM_IsOnStandPos  0x0217FE44  thumb  ov019
 *   FLDMMDL_SetAcmd  0x0216D410  thumb  ov010
 *   FLDMMDL_CheckEndAcmd  0x0216D454  thumb  ov010
 *   FLDMMDL_EndAcmd  0x0216D480  thumb  ov010
 *   UNION_ONESELF_SetNextPlayCategory  0x0217B8E4  thumb  ov019
 */
#include "../include/Obj19422.h"

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 pad00[0x2d];
    u8 f2d;
} Obj;

struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
typedef unsigned int   u32;
extern void *FIELD_PLAYER_GetMmdl(u8 *p);
extern int UNION_ONESELF_HandleNetErrorExit(char *p);
extern void UNION_MSG_CloseAllWindows(void *ctx);
extern u32 UNION_MSG_CheckTalkPrintEnd(u8 *p);
extern u32 COLOSSEUM_SendChoiceRequest(char *p);
extern u8 COLOSSEUM_GetMyChoiceReply(u8 *p);
extern int FLDMMDL_CheckPossibleAcmd(int a0);
extern int UNION_MSG_GetCategoryTableValue(int i);
extern int COLOSSEUM_IsOnStandPos(int a, int mode, unsigned *out);
extern void FLDMMDL_SetAcmd(void *h, u16 v);
extern int FLDMMDL_CheckEndAcmd(void *h);
extern int FLDMMDL_EndAcmd(char *p);
extern int UNION_ONESELF_SetNextPlayCategory(char *p, int v);

int UNION_ONESELF_ColosseumStandPosMain(void *ctx, Obj *obj, int a2, u8 *state)
{
    void *w = ((struct Obj19422 *)ctx)->f355C;
    void *h;
    unsigned out;
    int r;

    if (UNION_ONESELF_HandleNetErrorExit(ctx) == 1) {
        UNION_MSG_CloseAllWindows(ctx);
        return 1;
    }

    switch (*state) {
    case 0:
        (*state)++;
        break;
    case 1:
        if (COLOSSEUM_SendChoiceRequest(w) == 1)
            (*state)++;
        break;
    case 2:
        if (UNION_MSG_CheckTalkPrintEnd(ctx) != 0) {
            r = COLOSSEUM_GetMyChoiceReply(w);
            if (r == 1) {
                (*state)++;
            } else if (r == 0) {
                UNION_ONESELF_SetNextPlayCategory(ctx, 0x2c);
                return 1;
            }
        }
        break;
    case 3:
        h = FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer((void *)a2));
        if (FLDMMDL_CheckPossibleAcmd((int)h) == 1) {
            COLOSSEUM_IsOnStandPos(a2, UNION_MSG_GetCategoryTableValue(obj->f2d), &out);
            FLDMMDL_SetAcmd(h, (out & 1) ? 2 : 3);
            (*state)++;
        }
        break;
    case 4:
        h = FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer((void *)a2));
        if (FLDMMDL_CheckEndAcmd(h) == 1) {
            FLDMMDL_EndAcmd(h);
            UNION_ONESELF_SetNextPlayCategory(ctx, 0x2d);
            return 1;
        }
        break;
    }
    return 0;
}
