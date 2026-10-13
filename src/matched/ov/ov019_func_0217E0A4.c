/*
 * function: UNION_ONESELF_ColosseumLeavePosMain
 * address:  0x0217E0A4
 * packet:   pkt_ov019_0217E0A4
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
 *   UNION_ONESELF_CheckNetErrorExit  0x0217BB20  thumb  ov019
 *   UNION_MSG_CloseAllWindows  0x0217F074  thumb  ov019
 *   COLOSSEUM_SetMyChoice  0x021750B0  thumb  ov012
 *   COLOSSEUM_SendChoiceRequest  0x02174CE4  thumb  ov012
 *   COLOSSEUM_GetMyChoiceReply  0x021750D0  thumb  ov012
 *   FLDMMDL_CheckPossibleAcmd  0x0216D3CC  thumb  ov010
 *   UNION_MSG_GetCategoryTableValue  0x0217F060  thumb  ov019
 *   COLOSSEUM_GetStandPosIndex  0x0217FE44  thumb  ov019
 *   FLDMMDL_SetAcmd  0x0216D410  thumb  ov010
 *   FLDMMDL_CheckEndAcmd  0x0216D454  thumb  ov010
 *   FLDMMDL_EndAcmd  0x0216D480  thumb  ov010
 *   UNION_ONESELF_SetNextPlayCategory  0x0217B8E4  thumb  ov019
 */
#include "../include/Obj19424.h"

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 pad00[0x2d];
    u8 f2d;
} Obj;

struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern void *FIELD_PLAYER_GetMmdl(u8 *p);
extern int UNION_ONESELF_CheckNetErrorExit(char *p);
extern void UNION_MSG_CloseAllWindows(void *ctx);
extern void COLOSSEUM_SetMyChoice(u8 *p, int v);
typedef unsigned int   u32;
extern u32 COLOSSEUM_SendChoiceRequest(char *p);
extern u8 COLOSSEUM_GetMyChoiceReply(u8 *p);
extern int FLDMMDL_CheckPossibleAcmd(int a0);
extern int UNION_MSG_GetCategoryTableValue(int i);
extern int COLOSSEUM_GetStandPosIndex(int a, int mode, unsigned *out);
extern void FLDMMDL_SetAcmd(void *h, u16 v);
extern int FLDMMDL_CheckEndAcmd(void *h);
extern int FLDMMDL_EndAcmd(char *p);
extern int UNION_ONESELF_SetNextPlayCategory(char *p, int v);

int UNION_ONESELF_ColosseumLeavePosMain(void *ctx, Obj *obj, int a2, u8 *state)
{
    void *w = ((struct Obj19424 *)ctx)->f355C;
    void *h;
    unsigned out;

    h = FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer((void *)a2));
    if (UNION_ONESELF_CheckNetErrorExit(ctx) == 1) {
        UNION_MSG_CloseAllWindows(ctx);
        return 1;
    }

    switch (*state) {
    case 0:
        COLOSSEUM_SetMyChoice(w, 0xff);
        (*state)++;
        break;
    case 1:
        if (COLOSSEUM_SendChoiceRequest(w) == 1)
            (*state)++;
        break;
    case 2:
        if (COLOSSEUM_GetMyChoiceReply(w) != 0xff)
            (*state)++;
        break;
    case 3:
        UNION_MSG_CloseAllWindows(ctx);
        (*state)++;
        break;
    case 4:
        if (FLDMMDL_CheckPossibleAcmd((int)h) == 1) {
            COLOSSEUM_GetStandPosIndex(a2, UNION_MSG_GetCategoryTableValue(obj->f2d), &out);
            FLDMMDL_SetAcmd(h, (out & 1) ? 0xb : 0xa);
            (*state)++;
        }
        break;
    case 5:
        if (FLDMMDL_CheckEndAcmd(h) == 1) {
            FLDMMDL_EndAcmd(h);
            UNION_ONESELF_SetNextPlayCategory(ctx, 0x2a);
            return 1;
        }
        break;
    }
    return 0;
}
