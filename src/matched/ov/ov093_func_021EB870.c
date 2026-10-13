/*
 * function: BTLV_SCU_ProcEntrySingleTrainer
 * address: 0x021EB870
 * packet: pkt_ov093_021EB870
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_MAIN_GetSlotClientIdThunk 0x021B8DE4 thumb ov093
 *   BTL_MAIN_GetTrainerType 0x021BA020 thumb ov093
 *   func_021F7F58 0x021F7F58 thumb ov094
 *   BTLV_SCU_GetBallStates 0x021EE104 thumb ov093
 *   func_021F823C 0x021F823C thumb ov094
 *   BTL_MAIN_GetOwnClientId 0x021B8FF4 thumb ov093
 *   func_021F8260 0x021F8260 thumb ov094
 *   func_021F827C 0x021F827C thumb ov094
 *   BTLV_SCU_ProcQuickEntrySingle 0x021EB660 thumb ov093
 *   BTL_MAIN_GetSlotFromViewPos 0x021B8ED8 thumb ov093
 *   BTL_SIDE_GetPokeAtPos 0x021B98AC thumb ov093
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   func_021ED798 0x021ED798 thumb ov093
 *   func_021ED814 0x021ED814 thumb ov093
 *   BTL_POKEPARAM_GetDisplayMon 0x021D5864 thumb ov093
 *   func_021F7EE8 0x021F7EE8 thumb ov094
 *   func_021F7A28 0x021F7A28 thumb ov094
 *   BTLV_SCU_StartBrightnessFade 0x021EB584 thumb ov093
 *   func_021F7EB4 0x021F7EB4 thumb ov094
 *   BTLV_SCU_GetEntryMessageId 0x021EB820 thumb ov093
 *   BTL_MSG_FormatArgs 0x021EEE24 thumb ov093
 *   func_021ECEB8 0x021ECEB8 thumb ov093
 *   func_021ECF68 0x021ECF68 thumb ov093
 *   func_021EDA04 0x021EDA04 thumb ov093
 *   BTL_MAIN_GetCompetitor 0x021B86B8 thumb ov093
 *   func_021F7998 0x021F7998 thumb ov094
 */
#include "../include/Obj00579.h"
#include "../include/Obj01695.h"
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
extern void func_021ED798(struct S *s);
extern int func_021ED814(struct S *);
struct Work;
extern void *BTL_POKEPARAM_GetDisplayMon(struct Work *p);
extern void func_021F7EE8(void *, int);
extern void func_021F7A28(int, u32);
extern void BTLV_SCU_StartBrightnessFade(int);
extern int func_021F7EB4(void);
extern int BTLV_SCU_GetEntryMessageId(u8 *);
extern void BTL_MSG_FormatArgs(u32 a, u16 k, u32 n, ...);
extern void func_021ECEB8(u8 *, u32, u16, u32);
extern int func_021ECF68(struct T *p);
extern void func_021EDA04(struct E *e);
extern void *BTL_MAIN_GetCompetitor(void ***);
extern void func_021F7998(u32);
extern u8 BTL_MAIN_GetSlotClientIdThunk(char *p, int i);
extern u16 BTL_MAIN_GetTrainerType(char *, int);
extern void func_021F7F58(int, u32, u32, u32, u32);
extern void BTLV_SCU_GetBallStates(u8 *, u32 *, u32, u32, u32);
extern void func_021F823C(u32 *);
extern u8 BTL_MAIN_GetOwnClientId(u8 *);
extern void func_021F8260(u32);
extern int func_021F827C(u32);
int BTLV_SCU_ProcEntrySingleTrainer(int *state, u8 *p)
{
    u8 *b = p + 0xf0;
    u32 buf1[7];
    u32 buf2[7];
    u32 a, i;
    if (p[0x150]) return BTLV_SCU_ProcQuickEntrySingle(p, state);
    switch (*state) {
    case 0:
        a = BTL_MAIN_GetSlotFromViewPos(*(u8 * *)&((struct Obj01695 *)p)->f134, 1);
        i = BTL_MAIN_GetSlotClientIdThunk((char *)(*(u8 * *)&((struct Obj01695 *)p)->f134), a);
        func_021F7F58(BTL_MAIN_GetTrainerType(*(char * *)&((struct Obj01695 *)p)->f134, i), 9, 0, 0, 0);
        b[5] = 1;
        b[7] = i;
        b[4] = a;
        *(u8 * *)&((struct Obj00579 *)b)->f0 = BTL_SIDE_GetPokeAtPos(*(char *const * *)&((struct Obj01695 *)p)->f138, b[4]);
        b[6] = BTL_POKEPARAM_GetPokeId(*(u8 * *)&((struct Obj00579 *)b)->f0);
        func_021ED798((struct S *)(p + 0x154));
        (*state)++;
        break;
    case 1:
        if (func_021ED814((struct S *)(p + 0x154))) {
            func_021F7A28(b[5], 0x237);
            BTLV_SCU_StartBrightnessFade(2);
            (*state)++;
        }
        break;
    case 2:
        if (!func_021F7EB4()) {
            BTLV_SCU_GetBallStates(p, buf1, b[7], 4, 1);
            func_021F823C(buf1);
            BTL_MSG_FormatArgs(((struct Obj01695 *)p)->f34, 7, 1, b[7]);
            func_021ECEB8(p, ((struct Obj01695 *)p)->f34, 0x50, 0);
            (*state)++;
        }
        break;
    case 3:
        if (func_021ECF68((struct T *)p)) {
            func_021F7A28(b[5], 0x238);
            func_021ED798((struct S *)(p + 0x154));
            (*state)++;
        }
        break;
    case 4:
        if (func_021ED814((struct S *)(p + 0x154)) && !func_021F7EB4()) {
            BTL_MSG_FormatArgs(((struct Obj01695 *)p)->f34, 14, 2, 1, b[6]);
            func_021ECEB8(p, ((struct Obj01695 *)p)->f34, 0x50, 0);
            (*state)++;
        }
        break;
    case 5:
        if (func_021ECF68((struct T *)p)) {
            func_021F7EE8(BTL_POKEPARAM_GetDisplayMon(((struct Obj00579 *)b)->f0), b[5]);
            func_021F7A28(b[5], 0x239);
            func_021F8260(1);
            func_021ED798((struct S *)(p + 0x154));
            (*state)++;
        }
        break;
    case 6:
        if (func_021ED814((struct S *)(p + 0x154)) && !func_021F7EB4()) {
            BTLV_SCU_GetBallStates(p, buf2, BTL_MAIN_GetOwnClientId(*(u8 * *)&((struct Obj01695 *)p)->f134), 4, 0);
            func_021F823C(buf2);
            (*state)++;
        }
        break;
    case 7:
        func_021EDA04((struct E *)(p + 0x48 + b[4] * 12));
        func_021F7998(0x232);
        (*state)++;
        break;
    case 8:
        if (!func_021F7EB4() && !func_021F827C(0)) {
            b[5] = 0;
            b[4] = BTL_MAIN_GetSlotFromViewPos(*(u8 * *)&((struct Obj01695 *)p)->f134, b[5]);
            *(u8 * *)&((struct Obj00579 *)b)->f0 = BTL_SIDE_GetPokeAtPos(*(char *const * *)&((struct Obj01695 *)p)->f138, b[4]);
            b[6] = BTL_POKEPARAM_GetPokeId(*(u8 * *)&((struct Obj00579 *)b)->f0);
            func_021F7EE8(BTL_POKEPARAM_GetDisplayMon(((struct Obj00579 *)b)->f0), b[5]);
            func_021F7998(0x234);
            BTL_MSG_FormatArgs(((struct Obj01695 *)p)->f34, 11, 1, b[6]);
            func_021ECEB8(p, ((struct Obj01695 *)p)->f34, 0x50, 0);
            (*state)++;
        }
        break;
    case 9:
        if (func_021ECF68((struct T *)p)) {
            func_021F8260(0);
            func_021ED798((struct S *)(p + 0x154));
            (*state)++;
        }
        break;
    case 10:
        if (func_021ED814((struct S *)(p + 0x154))) (*state)++;
        break;
    case 11:
        if (!func_021F7EB4()) {
            func_021EDA04((struct E *)(p + 0x48 + b[4] * 12));
            return 1;
        }
        break;
    }
    return 0;
}
