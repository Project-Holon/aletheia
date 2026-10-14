/*
 * function: BTLV_SCU_ProcEntrySingleWild
 * address: 0x021EB690
 * packet: pkt_ov093_021EB690
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTLV_SCU_ProcQuickEntrySingle 0x021EB660 thumb ov093
 *   BTL_MAIN_GetSlotFromViewPos 0x021B8ED8 thumb ov093
 *   BTL_SIDE_GetPokeAtPos 0x021B98AC thumb ov093
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTLV_SCU_StartMsgWinFadeOut 0x021ED798 thumb ov093
 *   BTLV_SCU_UpdateMsgWinFade 0x021ED814 thumb ov093
 *   BTL_POKEPARAM_GetDisplayMon 0x021D5864 thumb ov093
 *   BTLV_EFFECT_SetPokeSpriteKey 0x021F7EE8 thumb ov094
 *   BTLV_EFFECT_StartEffectOnPoke 0x021F7A28 thumb ov094
 *   BTLV_SCU_StartBrightnessFade 0x021EB584 thumb ov093
 *   BTLV_EFFECT_IsBusy 0x021F7EB4 thumb ov094
 *   BTLV_SCU_GetEntryMessageId 0x021EB820 thumb ov093
 *   BTL_MSG_FormatArgs 0x021EEE24 thumb ov093
 *   BTLV_SCU_StartMessage 0x021ECEB8 thumb ov093
 *   BTLV_SCU_UpdateMessage 0x021ECF68 thumb ov093
 *   BTLV_SCU_ShowMonSlot 0x021EDA04 thumb ov093
 *   BTL_MAIN_GetCompetitor 0x021B86B8 thumb ov093
 *   BTLV_EFFECT_StartEffect 0x021F7998 thumb ov094
 */
#include "../include/Obj00765.h"
#include "../include/Obj02793.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct S { int h, x, y, dx, dy; u8 state, cnt; };
extern int BTLV_SCU_ProcQuickEntrySingle(u8 *, int *);
extern u8 BTL_MAIN_GetSlotFromViewPos(u8 *p, u8 k);
extern u8 *BTL_SIDE_GetPokeAtPos(char *const *q, u8 b);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
struct E;
struct T;
extern void BTLV_SCU_StartMsgWinFadeOut(struct S *s);
extern int BTLV_SCU_UpdateMsgWinFade(struct S *);
struct Work;
extern void *BTL_POKEPARAM_GetDisplayMon(struct Work *p);
extern void BTLV_EFFECT_SetPokeSpriteKey(void *, int);
extern void BTLV_EFFECT_StartEffectOnPoke(int, u32);
extern void BTLV_SCU_StartBrightnessFade(int);
extern int BTLV_EFFECT_IsBusy(void);
extern int BTLV_SCU_GetEntryMessageId(u8 *);
extern void BTL_MSG_FormatArgs(u32, u32, u32, ...);
extern void BTLV_SCU_StartMessage(u8 *, u32, u16, u32);
extern int BTLV_SCU_UpdateMessage(struct T *p);
extern void BTLV_SCU_ShowMonSlot(struct E *e);
extern void *BTL_MAIN_GetCompetitor(void ***);
extern void BTLV_EFFECT_StartEffect(u32);
int BTLV_SCU_ProcEntrySingleWild(int *state, u8 *p)
{
    u8 *b = p + 0xf0;
    if (p[0x150]) return BTLV_SCU_ProcQuickEntrySingle(p, state);
    switch (*state) {
    case 0:
        b[5] = 1;
        b[4] = BTL_MAIN_GetSlotFromViewPos(*(u8 * *)&((struct Obj02793 *)p)->f134, b[5]);
        *(u8 * *)&((struct Obj00765 *)b)->f0 = BTL_SIDE_GetPokeAtPos(*(char *const * *)&((struct Obj02793 *)p)->f138, b[4]);
        b[6] = BTL_POKEPARAM_GetPokeId(*(u8 * *)&((struct Obj00765 *)b)->f0);
        BTLV_SCU_StartMsgWinFadeOut((struct S *)(p + 0x154));
        (*state)++;
        break;
    case 1:
        if (BTLV_SCU_UpdateMsgWinFade((struct S *)(p + 0x154))) {
            BTLV_EFFECT_SetPokeSpriteKey(BTL_POKEPARAM_GetDisplayMon(((struct Obj00765 *)b)->f0), b[5]);
            BTLV_EFFECT_StartEffectOnPoke(b[5], 0x231);
            BTLV_SCU_StartBrightnessFade(2);
            (*state)++;
        }
        break;
    case 2:
        if (!BTLV_EFFECT_IsBusy()) {
            BTL_MSG_FormatArgs(((struct Obj02793 *)p)->f34, BTLV_SCU_GetEntryMessageId(p), 1, b[6]);
            BTLV_SCU_StartMessage(p, ((struct Obj02793 *)p)->f34, 0x50, 0);
            (*state)++;
        }
        break;
    case 3:
        if (BTLV_SCU_UpdateMessage((struct T *)p)) {
            BTLV_SCU_ShowMonSlot((struct E *)(p + 0x48 + b[4] * 12));
            BTLV_SCU_StartMsgWinFadeOut((struct S *)(p + 0x154));
            (*state)++;
        }
        break;
    case 4:
        if (BTLV_SCU_UpdateMsgWinFade((struct S *)(p + 0x154))) {
            if ((int)BTL_MAIN_GetCompetitor(*(void *** *)&((struct Obj02793 *)p)->f134) == 4) BTLV_EFFECT_StartEffect(0x23c);
            else BTLV_EFFECT_StartEffect(0x232);
            (*state)++;
        }
        break;
    case 5:
        if (!BTLV_EFFECT_IsBusy()) {
            b[5] = 0;
            b[4] = BTL_MAIN_GetSlotFromViewPos(*(u8 * *)&((struct Obj02793 *)p)->f134, b[5]);
            *(u8 * *)&((struct Obj00765 *)b)->f0 = BTL_SIDE_GetPokeAtPos(*(char *const * *)&((struct Obj02793 *)p)->f138, b[4]);
            b[6] = BTL_POKEPARAM_GetPokeId(*(u8 * *)&((struct Obj00765 *)b)->f0);
            BTLV_EFFECT_SetPokeSpriteKey(BTL_POKEPARAM_GetDisplayMon(((struct Obj00765 *)b)->f0), b[5]);
            BTLV_EFFECT_StartEffect(0x234);
            BTL_MSG_FormatArgs(((struct Obj02793 *)p)->f34, 11, 1, b[6]);
            BTLV_SCU_StartMessage(p, ((struct Obj02793 *)p)->f34, 0x50, 0);
            (*state)++;
        }
        break;
    case 6:
        if (BTLV_SCU_UpdateMessage((struct T *)p)) {
            BTLV_SCU_StartMsgWinFadeOut((struct S *)(p + 0x154));
            (*state)++;
        }
        break;
    case 7:
        if (BTLV_SCU_UpdateMsgWinFade((struct S *)(p + 0x154))) (*state)++;
        break;
    case 8:
        if (!BTLV_EFFECT_IsBusy()) {
            BTLV_SCU_ShowMonSlot((struct E *)(p + 0x48 + b[4] * 12));
            return 1;
        }
        break;
    }
    return 0;
}
