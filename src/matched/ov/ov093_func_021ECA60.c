/*
 * function: BTLV_SCU_RunOwnSendOutDoublePartner
 * address: 0x021ECA60
 * packet: pkt_ov093_021ECA60
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTLV_SCU_GetBallStates 0x021EE104 thumb ov093
 *   BTLV_EFFECT_CreatePartyBallBar 0x021F823C thumb ov094
 *   BTLV_EFFECT_IsBusy 0x021F7EB4 thumb ov094
 *   BTLV_EFFECT_StartEffect 0x021F7998 thumb ov094
 *   BTLV_EFFECT_IsPartyBallBarActive 0x021F827C thumb ov094
 *   BTL_MAIN_GetOwnClientId 0x021B8FF4 thumb ov093
 *   BTL_MAIN_IsOwnClientSecondTeam 0x021B8FE4 thumb ov093
 *   BTL_MAIN_GetSlotFromViewPos 0x021B8ED8 thumb ov093
 *   BTL_SIDE_GetPokeAtPos 0x021B98AC thumb ov093
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTL_MAIN_IsTrainerSlotNpc 0x021B9F70 thumb ov093
 *   BTL_MSG_FormatArgs 0x021EEE24 thumb ov093
 *   BTLV_SCU_StartMessage 0x021ECEB8 thumb ov093
 *   BTLV_SCU_UpdateMessage 0x021ECF68 thumb ov093
 *   BTLV_EFFECT_DeletePartyBallBar 0x021F8260 thumb ov094
 *   BTLV_SCU_StartMsgWinFadeOut 0x021ED798 thumb ov093
 *   BTLV_SCU_UpdateMsgWinFade 0x021ED814 thumb ov093
 *   BTL_POKEPARAM_GetDisplayMon 0x021D5864 thumb ov093
 *   BTLV_EFFECT_SetPokeSpriteKey 0x021F7EE8 thumb ov094
 *   BTLV_SCU_ShowMonSlot 0x021EDA04 thumb ov093
 */
#include "../include/Obj00027.h"
#include "../include/Obj01523.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void BTLV_SCU_GetBallStates(u8 *, u32 *, u32, u32, u32);
extern void BTLV_EFFECT_CreatePartyBallBar(u32 *);
extern int BTLV_EFFECT_IsBusy(void);
extern void BTLV_EFFECT_StartEffect(u32);
extern int BTLV_EFFECT_IsPartyBallBarActive(u32);
extern u8 BTL_MAIN_GetOwnClientId(u8 *);
extern u8 BTL_MAIN_IsOwnClientSecondTeam(u8 *);
extern u8 BTL_MAIN_GetSlotFromViewPos(u8 *p, u8 k);
extern u8 *BTL_SIDE_GetPokeAtPos(char *const *q, u8 b);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
struct Work;
extern int BTL_MAIN_IsTrainerSlotNpc(u8 *p, int i);
extern void BTL_MSG_FormatArgs(u32, u16, u32, ...);
extern void BTLV_SCU_StartMessage(u8 *, u32, u16, u32);
struct E;
struct S;
struct T;
extern int BTLV_SCU_UpdateMessage(struct T *p);
extern void BTLV_EFFECT_DeletePartyBallBar(u32 i);
extern void BTLV_SCU_StartMsgWinFadeOut(struct S *s);
extern int BTLV_SCU_UpdateMsgWinFade(struct S *s);
extern void *BTL_POKEPARAM_GetDisplayMon(struct Work *p);
extern void BTLV_EFFECT_SetPokeSpriteKey(void *, int);
extern void BTLV_SCU_ShowMonSlot(struct E *e);
int BTLV_SCU_RunOwnSendOutDoublePartner(u8 *p, int *state, u32 a, u8 c)
{
    u8 *b = p + 0xf0;
    unsigned long i;
    u32 buf[7];
    u8 side;
    u8 winner;
    u16 msg;
    switch (*state) {
    case 0:
        if (a < c) BTLV_SCU_GetBallStates(p, buf, a, c, 0);
        else BTLV_SCU_GetBallStates(p, buf, c, a, 0);
        BTLV_EFFECT_CreatePartyBallBar(buf);
        (*state)++;
        break;
    case 1:
        if (!BTLV_EFFECT_IsBusy()) {
            BTLV_EFFECT_StartEffect(0x233);
            (*state)++;
        }
        break;
    case 2:
        if (!BTLV_EFFECT_IsBusy() && !BTLV_EFFECT_IsPartyBallBarActive(0)) {
            b[10] = 2;
            b[11] = 4;
            b[15] = BTL_MAIN_GetOwnClientId(*(u8 * *)&((struct Obj00027 *)p)->f134);
            side = BTL_MAIN_IsOwnClientSecondTeam(*(u8 * *)&((struct Obj00027 *)p)->f134) ^ 1;
            for (i = 0; i < 2U; i++) {
                b[8 + i] = BTL_MAIN_GetSlotFromViewPos(*(u8 * *)&((struct Obj00027 *)p)->f134, b[10 + i]);
                ((u8 **)b)[i] = (u8 *)BTL_SIDE_GetPokeAtPos(*(char *const * *)&((struct Obj00027 *)p)->f138, b[8 + i]);
                b[12 + i] = BTL_POKEPARAM_GetPokeId(((u8 **)b)[i]);
            }
            msg = BTL_MAIN_IsTrainerSlotNpc(((struct Obj00027 *)p)->f134, c) ? 14 : 17;
            BTL_MSG_FormatArgs(((struct Obj00027 *)p)->f34, msg, 2, c, (b + side)[12]);
            BTLV_SCU_StartMessage(p, ((struct Obj00027 *)p)->f34, 0x50, 0);
            (*state)++;
        }
        break;
    case 3:
        if (BTLV_SCU_UpdateMessage((struct T *)p)) {
            BTLV_EFFECT_DeletePartyBallBar(0);
            BTLV_SCU_StartMsgWinFadeOut((struct S *)(p + 0x154));
            (*state)++;
        }
        break;
    case 4:
        if (BTLV_SCU_UpdateMsgWinFade((struct S *)(p + 0x154))) {
            winner = BTL_MAIN_IsOwnClientSecondTeam(*(u8 * *)&((struct Obj00027 *)p)->f134);
            BTLV_EFFECT_SetPokeSpriteKey(BTL_POKEPARAM_GetDisplayMon(*(void **)b), b[10]);
            BTLV_EFFECT_SetPokeSpriteKey(BTL_POKEPARAM_GetDisplayMon(((struct Obj01523 *)b)->f4), b[11]);
            BTLV_EFFECT_StartEffect(0x234);
            BTL_MSG_FormatArgs(((struct Obj00027 *)p)->f34, 11, 1, (b + winner)[12]);
            BTLV_SCU_StartMessage(p, ((struct Obj00027 *)p)->f34, 0x50, 0);
            (*state)++;
        }
        break;
    case 5:
        if (BTLV_SCU_UpdateMessage((struct T *)p)) {
            BTLV_SCU_StartMsgWinFadeOut((struct S *)(p + 0x154));
            (*state)++;
        }
        break;
    case 6:
        if (BTLV_SCU_UpdateMsgWinFade((struct S *)(p + 0x154)) && !BTLV_EFFECT_IsBusy()) {
            BTLV_SCU_ShowMonSlot((struct E *)(p + 0x48 + b[8] * 12));
            BTLV_SCU_ShowMonSlot((struct E *)(p + 0x48 + b[9] * 12));
            return 1;
        }
        break;
    }
    return 0;
}
