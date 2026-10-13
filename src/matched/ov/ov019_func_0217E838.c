/*
 * function: UNION_ONESELF_ColosseumLeaveConfirmMain
 * address:  0x0217E838
 * packet:   pkt_ov019_0217E838
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   UNION_ONESELF_CheckNetErrorExit  0x0217BB20  thumb  ov019
 *   UNION_MSG_CloseAllWindows  0x0217F074  thumb  ov019
 *   UNION_MSG_SetupPrintTalkMsg  0x0217F210  thumb  ov019
 *   UNION_MSG_CheckTalkPrintEnd  0x0217F1EC  thumb  ov019
 *   UNION_MSG_SetupYesNo  0x0217F22C  thumb  ov019
 *   UNION_MSG_SelectYesNo  0x0217F268  thumb  ov019
 *   UNION_MSG_DeleteYesNo  0x0217F24C  thumb  ov019
 *   UNION_ONESELF_SetNextPlayCategory  0x0217B8E4  thumb  ov019
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FLDMMDL_CheckPossibleAcmd  0x0216D3CC  thumb  ov010
 *   FLDMMDL_SetAcmd  0x0216D410  thumb  ov010
 *   FLDMMDL_CheckEndAcmd  0x0216D454  thumb  ov010
 *   FLDMMDL_EndAcmd  0x0216D480  thumb  ov010
 */

typedef unsigned char u8;

int UNION_ONESELF_CheckNetErrorExit(char *p);
typedef unsigned short u16;
typedef unsigned int   u32;
void UNION_MSG_CloseAllWindows(void *p);
void UNION_MSG_SetupPrintTalkMsg(u8 *p, u8 *a, u32 b);
u32 UNION_MSG_CheckTalkPrintEnd(u8 *p);
void UNION_MSG_SetupYesNo(u8 *p, u32 a);
int UNION_MSG_SelectYesNo(char *p, u32 *out);
void UNION_MSG_DeleteYesNo(u8 *w);
int UNION_ONESELF_SetNextPlayCategory(char *p, int v);
struct Obj00020;
void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
void *FIELD_PLAYER_GetMmdl(u8 *p);
int FLDMMDL_CheckPossibleAcmd(int a0);
void FLDMMDL_SetAcmd(void *a0, u16 a1);
int FLDMMDL_CheckEndAcmd(void *h);
int FLDMMDL_EndAcmd(char *p);

int UNION_ONESELF_ColosseumLeaveConfirmMain(u8 *w, void *obj, void *a2, u8 *state)
{
    void *h;
    int flag;

    h = FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(a2));
    if (UNION_ONESELF_CheckNetErrorExit((char *)w) == 1) {
        UNION_MSG_CloseAllWindows(w);
        return 1;
    }
    switch (*state) {
    case 0:
        UNION_MSG_SetupPrintTalkMsg(w, (u8 *)a2, 0x14e);
        (*state)++;
        break;
    case 1:
        if (UNION_MSG_CheckTalkPrintEnd(w) != 0) {
            UNION_MSG_SetupYesNo(w, (u32)a2);
            (*state)++;
        }
        break;
    case 2:
        if (UNION_MSG_SelectYesNo((char *)w, (u32 *)(&flag)) == 1) {
            UNION_MSG_DeleteYesNo(w);
            if (flag == 0) {
                *state = 3;
            } else {
                UNION_ONESELF_SetNextPlayCategory((char *)w, 0x32);
                return 1;
            }
        }
        break;
    case 3:
        if (FLDMMDL_CheckPossibleAcmd((int)h) == 1) {
            FLDMMDL_SetAcmd(h, 8);
            (*state)++;
        }
        break;
    case 4:
        if (FLDMMDL_CheckEndAcmd(h) == 1) {
            FLDMMDL_EndAcmd(h);
            UNION_ONESELF_SetNextPlayCategory((char *)w, 0x2a);
            return 1;
        }
        break;
    }
    return 0;
}
