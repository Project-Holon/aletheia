/*
 * function: BTLV_SCU_ProcEntryDoubleWild
 * address: 0x021EBB20
 * packet: pkt_ov093_021EBB20
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * match-note: The loop stores and reads each call result through the same
 * pointer-typed lvalue. Integer-store/pointer-reload gave 628 bytes; a named
 * integer temporary gave 620 and lost the index spill; pointer lvalues gave
 * EXACT 624 bytes. Evidence: B10/BB20-r1.log through BB20-r3.log.
 * symbols:
 *   BTL_MAIN_GetClientTrainerIndex 0x021B8BEC thumb ov093
 *   BTL_MAIN_GetEnemyLanePosFromWork 0x021B8C50 thumb ov093
 *   BTL_MAIN_GetViewPosOfSlot 0x021B8E70 thumb ov093
 *   BTL_MAIN_GetOwnClientId 0x021B8FF4 thumb ov093
 *   BTLV_SCU_ProcQuickEntryDouble 0x021EB670 thumb ov093
 *   BTL_MAIN_GetSlotFromViewPos 0x021B8ED8 thumb ov093
 *   BTL_SIDE_GetPokeAtPos 0x021B98AC thumb ov093
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTLV_SCU_StartMsgWinFadeOut 0x021ED798 thumb ov093
 *   BTLV_SCU_UpdateMsgWinFade 0x021ED814 thumb ov093
 *   BTL_POKEPARAM_GetDisplayMon 0x021D5864 thumb ov093
 *   func_021F7EE8 0x021F7EE8 thumb ov094
 *   func_021F7A28 0x021F7A28 thumb ov094
 *   BTLV_SCU_StartBrightnessFade 0x021EB584 thumb ov093
 *   func_021F7EB4 0x021F7EB4 thumb ov094
 *   BTLV_SCU_GetEntryMessageId 0x021EB820 thumb ov093
 *   BTL_MSG_FormatArgs 0x021EEE24 thumb ov093
 *   BTLV_SCU_StartMessage 0x021ECEB8 thumb ov093
 *   BTLV_SCU_UpdateMessage 0x021ECF68 thumb ov093
 *   BTLV_SCU_ShowMonSlot 0x021EDA04 thumb ov093
 *   BTL_MAIN_GetCompetitor 0x021B86B8 thumb ov093
 *   func_021F7998 0x021F7998 thumb ov094
 */
#include "../include/Obj00406.h"
#include "../include/Obj01377.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct S { int h, x, y, dx, dy; u8 state, cnt; };
extern int BTLV_SCU_ProcQuickEntryDouble(u8 *, int *);
extern u8 BTL_MAIN_GetSlotFromViewPos(u8 *p, u8 k);
extern u8 *BTL_SIDE_GetPokeAtPos(char *const *q, u8 b);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
struct E;
struct T;
extern void BTLV_SCU_StartMsgWinFadeOut(struct S *s);
extern int BTLV_SCU_UpdateMsgWinFade(struct S *);
struct Work;
extern void *BTL_POKEPARAM_GetDisplayMon(struct Work *p);
extern void func_021F7EE8(void *, int);
extern void func_021F7A28(int, u32);
extern void BTLV_SCU_StartBrightnessFade(int);
extern int func_021F7EB4(void);
extern int BTLV_SCU_GetEntryMessageId(u8 *);
extern void BTL_MSG_FormatArgs(u32 a, u16 k, u32 n, ...);
extern void BTLV_SCU_StartMessage(u8 *, u32, u16, u32);
extern int BTLV_SCU_UpdateMessage(struct T *p);
extern void BTLV_SCU_ShowMonSlot(struct E *e);
extern void *BTL_MAIN_GetCompetitor(void ***);
extern void func_021F7998(u32);
extern u8 BTL_MAIN_GetClientTrainerIndex(u8 *, u32, u8);
extern u8 BTL_MAIN_GetEnemyLanePosFromWork(char **p, u32 v, int k);
extern u8 BTL_MAIN_GetViewPosOfSlot(u8 *, u32);
extern u8 BTL_MAIN_GetOwnClientId(u8 *);
int BTLV_SCU_ProcEntryDoubleWild(int *state, u8 *p)
{
    u8 *b = p + 0xf0;
    u32 a;
    unsigned i;
    u8 *q;
    if (p[0x150]) return BTLV_SCU_ProcQuickEntryDouble(p, state);
    switch (*state) {
    case 0:
        a = BTL_MAIN_GetClientTrainerIndex(*(u8 * *)&((struct Obj01377 *)p)->f134, p[0x140], 0);
        b[10] = BTL_MAIN_GetEnemyLanePosFromWork(((struct Obj01377 *)p)->f134, a, 0);
        *(u8 * *)&((struct Obj00406 *)b)->f0 = BTL_SIDE_GetPokeAtPos(*(char *const * *)&((struct Obj01377 *)p)->f138, b[10]);
        b[8] = BTL_POKEPARAM_GetPokeId(*(u8 * *)&((struct Obj00406 *)b)->f0);
        b[11] = BTL_MAIN_GetEnemyLanePosFromWork(((struct Obj01377 *)p)->f134, a, 1);
        *(u8 * *)&((struct Obj00406 *)b)->f4 = BTL_SIDE_GetPokeAtPos(*(char *const * *)&((struct Obj01377 *)p)->f138, b[11]);
        b[9] = BTL_POKEPARAM_GetPokeId(*(u8 * *)&((struct Obj00406 *)b)->f4);
        BTLV_SCU_StartMsgWinFadeOut((struct S *)(p + 0x154));
        (*state)++;
        break;
    case 1:
        if (BTLV_SCU_UpdateMsgWinFade((struct S *)(p + 0x154))) {
            a = BTL_MAIN_GetViewPosOfSlot(*(u8 * *)&((struct Obj01377 *)p)->f134, b[10]);
            func_021F7EE8(BTL_POKEPARAM_GetDisplayMon(((struct Obj00406 *)b)->f0), a);
            (*state)++;
        }
        break;
    case 2:
        if (!func_021F7EB4()) {
            a = BTL_MAIN_GetViewPosOfSlot(*(u8 * *)&((struct Obj01377 *)p)->f134, b[11]);
            func_021F7EE8(BTL_POKEPARAM_GetDisplayMon(((struct Obj00406 *)b)->f4), a);
            func_021F7A28(a, 0x231);
            BTLV_SCU_StartBrightnessFade(2);
            (*state)++;
        }
        break;
    case 3:
        if (!func_021F7EB4()) {
            BTL_MSG_FormatArgs(((struct Obj01377 *)p)->f34, 2, 2, b[8], b[9]);
            BTLV_SCU_StartMessage(p, ((struct Obj01377 *)p)->f34, 0x50, 0);
            (*state)++;
        }
        break;
    case 4:
        if (BTLV_SCU_UpdateMessage((struct T *)p)) {
            BTLV_SCU_ShowMonSlot((struct E *)(p + 0x48 + b[10] * 12));
            BTLV_SCU_ShowMonSlot((struct E *)(p + 0x48 + b[11] * 12));
            BTLV_SCU_StartMsgWinFadeOut((struct S *)(p + 0x154));
            (*state)++;
        }
        break;
    case 5:
        if (BTLV_SCU_UpdateMsgWinFade((struct S *)(p + 0x154))) {
            func_021F7998(0x232);
            (*state)++;
        }
        break;
    case 6:
        if (!func_021F7EB4()) {
            b[12] = 2;
            b[13] = 4;
            b[15] = BTL_MAIN_GetOwnClientId(*(u8 * *)&((struct Obj01377 *)p)->f134);
            for (i = 0; i < 2; i++) {
                q = b + i;
                q[10] = BTL_MAIN_GetSlotFromViewPos(*(u8 * *)&((struct Obj01377 *)p)->f134, q[12]);
                ((u8 **)b)[i] = (u8 *)BTL_SIDE_GetPokeAtPos(*(char *const * *)&((struct Obj01377 *)p)->f138, q[10]);
                if (((u8 **)b)[i]) q[8] = BTL_POKEPARAM_GetPokeId(((u8 **)b)[i]);
            }
            func_021F7EE8(BTL_POKEPARAM_GetDisplayMon(((struct Obj00406 *)b)->f0), b[12]);
            func_021F7EE8(BTL_POKEPARAM_GetDisplayMon(((struct Obj00406 *)b)->f4), b[13]);
            func_021F7998(0x234);
            BTL_MSG_FormatArgs(((struct Obj01377 *)p)->f34, 12, 2, b[8], b[9]);
            BTLV_SCU_StartMessage(p, ((struct Obj01377 *)p)->f34, 0x50, 0);
            (*state)++;
        }
        break;
    case 7:
        if (BTLV_SCU_UpdateMessage((struct T *)p)) {
            BTLV_SCU_StartMsgWinFadeOut((struct S *)(p + 0x154));
            (*state)++;
        }
        break;
    case 8:
        if (BTLV_SCU_UpdateMsgWinFade((struct S *)(p + 0x154)) && !func_021F7EB4()) {
            BTLV_SCU_ShowMonSlot((struct E *)(p + 0x48 + b[10] * 12));
            BTLV_SCU_ShowMonSlot((struct E *)(p + 0x48 + b[11] * 12));
            (*state)++;
        }
        break;
    case 9:
        if (!func_021F7EB4()) return 1;
        break;
    }
    return 0;
}
