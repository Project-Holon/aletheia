/*
 * function: BTLV_SCU_PhaseOpponentSendOutSingle
 * address: 0x021EC200
 * packet: pkt_ov093_021EC200
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_MAIN_GetOwnClientId 0x021B8FF4 thumb ov093
 *   BTL_MAIN_GetOpponentClient 0x021B9064 thumb ov093
 *   BTL_MAIN_GetSlotFromViewPos 0x021B8ED8 thumb ov093
 *   BTL_SIDE_GetPokeAtPos 0x021B98AC thumb ov093
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTL_POKEPARAM_GetDisplayMon 0x021D5864 thumb ov093
 *   BTLV_SCU_GetSendOutMessageId 0x021ECE08 thumb ov093
 *   BTL_MSG_FormatArgs 0x021EEE24 thumb ov093
 *   BTLV_SCU_StartMessage 0x021ECEB8 thumb ov093
 *   BTLV_SCU_UpdateMessage 0x021ECF68 thumb ov093
 *   BTLV_SCU_StartMsgWinFadeOut 0x021ED798 thumb ov093
 *   BTLV_SCU_UpdateMsgWinFade 0x021ED814 thumb ov093
 *   BTLV_SCU_ShowMonSlot 0x021EDA04 thumb ov093
 *   func_021F7EE8 0x021F7EE8 thumb ov094
 *   func_021F7A28 0x021F7A28 thumb ov094
 *   func_021F8260 0x021F8260 thumb ov094
 *   func_021F7EB4 0x021F7EB4 thumb ov094
 */
#include "../include/Obj00027.h"
#include "../include/Obj01696.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct S { int h, x, y, dx, dy; u8 state, cnt; };
extern u8 BTL_MAIN_GetOwnClientId(u8 *);
struct Work;
extern u32 BTL_MAIN_GetOpponentClient(u8 *p, int k, int x);
extern u8 BTL_MAIN_GetSlotFromViewPos(u8 *p, u8 k);
extern u8 *BTL_SIDE_GetPokeAtPos(char *const *q, u8 b);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void *BTL_POKEPARAM_GetDisplayMon(struct Work *p);
extern u16 BTLV_SCU_GetSendOutMessageId(u8 *, int);
extern void BTL_MSG_FormatArgs(u32, u16, u32, ...);
extern void BTLV_SCU_StartMessage(u8 *, u32, u16, u32);
struct E;
struct T;
extern int BTLV_SCU_UpdateMessage(struct T *p);
extern void BTLV_SCU_StartMsgWinFadeOut(struct S *s);
extern int BTLV_SCU_UpdateMsgWinFade(struct S *);
extern void BTLV_SCU_ShowMonSlot(struct E *e);
extern void func_021F7EE8(void *, int);
extern void func_021F7A28(int, u32);
extern void func_021F8260(u32 i);
extern int func_021F7EB4(void);
int BTLV_SCU_PhaseOpponentSendOutSingle(u8 *p, int *state)
{
    u8 *b = p + 0xf0;
    switch (*state) {
    case 0:
        b[5] = 1;
        b[8] = BTL_MAIN_GetOpponentClient(*(u8 * *)&((struct Obj00027 *)p)->f134, BTL_MAIN_GetOwnClientId(*(u8 * *)&((struct Obj00027 *)p)->f134), 0);
        b[4] = BTL_MAIN_GetSlotFromViewPos(*(u8 * *)&((struct Obj00027 *)p)->f134, b[5]);
        *(u8 * *)&((struct Obj01696 *)b)->f0 = BTL_SIDE_GetPokeAtPos(*(char *const * *)&((struct Obj00027 *)p)->f138, b[4]);
        b[6] = BTL_POKEPARAM_GetPokeId(*(u8 * *)&((struct Obj01696 *)b)->f0);
        BTL_MSG_FormatArgs(((struct Obj00027 *)p)->f34, BTLV_SCU_GetSendOutMessageId(p, 1), 2, b[8], b[6]);
        BTLV_SCU_StartMessage(p, ((struct Obj00027 *)p)->f34, 0x50, 0);
        (*state)++;
        break;
    case 1:
        if (BTLV_SCU_UpdateMessage((struct T *)p)) {
            BTLV_SCU_StartMsgWinFadeOut((struct S *)(p + 0x154));
            (*state)++;
        }
        break;
    case 2:
        func_021F7EE8(BTL_POKEPARAM_GetDisplayMon(((struct Obj01696 *)b)->f0), b[5]);
        func_021F7A28(b[5], 0x239);
        func_021F8260(1);
        (*state)++;
        break;
    case 3:
        if (BTLV_SCU_UpdateMsgWinFade((struct S *)(p + 0x154)) && !func_021F7EB4()) {
            BTLV_SCU_ShowMonSlot((struct E *)(p + 0x48 + b[4] * 12));
            (*state)++;
        }
        break;
    case 4:
        return 1;
    }
    return 0;
}
