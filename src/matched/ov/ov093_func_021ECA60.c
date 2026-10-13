/*
 * function: func_021ECA60
 * address: 0x021ECA60
 * packet: pkt_ov093_021ECA60
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTLV_SCU_GetBallStates 0x021EE104 thumb ov093
 *   func_021F823C 0x021F823C thumb ov094
 *   func_021F7EB4 0x021F7EB4 thumb ov094
 *   func_021F7998 0x021F7998 thumb ov094
 *   func_021F827C 0x021F827C thumb ov094
 *   BTL_MAIN_GetOwnClientId 0x021B8FF4 thumb ov093
 *   BTL_MAIN_IsOwnClientSecondTeam 0x021B8FE4 thumb ov093
 *   BTL_MAIN_GetSlotFromViewPos 0x021B8ED8 thumb ov093
 *   BTL_SIDE_GetPokeAtPos 0x021B98AC thumb ov093
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTL_MAIN_IsTrainerSlotNpc 0x021B9F70 thumb ov093
 *   BTL_MSG_FormatArgs 0x021EEE24 thumb ov093
 *   func_021ECEB8 0x021ECEB8 thumb ov093
 *   func_021ECF68 0x021ECF68 thumb ov093
 *   func_021F8260 0x021F8260 thumb ov094
 *   func_021ED798 0x021ED798 thumb ov093
 *   func_021ED814 0x021ED814 thumb ov093
 *   BTL_POKEPARAM_GetDisplayMon 0x021D5864 thumb ov093
 *   func_021F7EE8 0x021F7EE8 thumb ov094
 *   func_021EDA04 0x021EDA04 thumb ov093
 */
#include "../include/Obj00027.h"
#include "../include/Obj01523.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void BTLV_SCU_GetBallStates(u8 *, u32 *, u32, u32, u32);
extern void func_021F823C(u32 *);
extern int func_021F7EB4(void);
extern void func_021F7998(u32);
extern int func_021F827C(u32);
extern u8 BTL_MAIN_GetOwnClientId(u8 *);
extern u8 BTL_MAIN_IsOwnClientSecondTeam(u8 *);
extern u8 BTL_MAIN_GetSlotFromViewPos(u8 *p, u8 k);
extern u8 *BTL_SIDE_GetPokeAtPos(char *const *q, u8 b);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
struct Work;
extern int BTL_MAIN_IsTrainerSlotNpc(u8 *p, int i);
extern void BTL_MSG_FormatArgs(u32, u16, u32, ...);
extern void func_021ECEB8(u8 *, u32, u16, u32);
struct E;
struct S;
struct T;
extern int func_021ECF68(struct T *p);
extern void func_021F8260(u32 i);
extern void func_021ED798(struct S *s);
extern int func_021ED814(struct S *s);
extern void *BTL_POKEPARAM_GetDisplayMon(struct Work *p);
extern void func_021F7EE8(void *, int);
extern void func_021EDA04(struct E *e);
int func_021ECA60(u8 *p, int *state, u32 a, u8 c)
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
        func_021F823C(buf);
        (*state)++;
        break;
    case 1:
        if (!func_021F7EB4()) {
            func_021F7998(0x233);
            (*state)++;
        }
        break;
    case 2:
        if (!func_021F7EB4() && !func_021F827C(0)) {
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
            func_021ECEB8(p, ((struct Obj00027 *)p)->f34, 0x50, 0);
            (*state)++;
        }
        break;
    case 3:
        if (func_021ECF68((struct T *)p)) {
            func_021F8260(0);
            func_021ED798((struct S *)(p + 0x154));
            (*state)++;
        }
        break;
    case 4:
        if (func_021ED814((struct S *)(p + 0x154))) {
            winner = BTL_MAIN_IsOwnClientSecondTeam(*(u8 * *)&((struct Obj00027 *)p)->f134);
            func_021F7EE8(BTL_POKEPARAM_GetDisplayMon(*(void **)b), b[10]);
            func_021F7EE8(BTL_POKEPARAM_GetDisplayMon(((struct Obj01523 *)b)->f4), b[11]);
            func_021F7998(0x234);
            BTL_MSG_FormatArgs(((struct Obj00027 *)p)->f34, 11, 1, (b + winner)[12]);
            func_021ECEB8(p, ((struct Obj00027 *)p)->f34, 0x50, 0);
            (*state)++;
        }
        break;
    case 5:
        if (func_021ECF68((struct T *)p)) {
            func_021ED798((struct S *)(p + 0x154));
            (*state)++;
        }
        break;
    case 6:
        if (func_021ED814((struct S *)(p + 0x154)) && !func_021F7EB4()) {
            func_021EDA04((struct E *)(p + 0x48 + b[8] * 12));
            func_021EDA04((struct E *)(p + 0x48 + b[9] * 12));
            return 1;
        }
        break;
    }
    return 0;
}
