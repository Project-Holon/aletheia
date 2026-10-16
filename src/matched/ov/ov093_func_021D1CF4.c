/*
 * function: BTL_CLIENT_StepSendOutMon
 * address: 0x021D1CF4
 * packet: pkt_ov093_021D1CF4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: append-id and send are written in every message arm; the inline
 * helper includes that tail. Factoring it outside the conditional merges
 * the initialisation call too early and loses 16 bytes.
 * symbols:
 *   BTL_SIDE_GetClientPoke 0x021B9920 thumb ov093
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTL_MAIN_IsOpposingPos 0x021B8CE8 thumb ov093
 *   BTL_CLIENT_PickSendOutMessageId 0x021D1DF4 thumb ov093
 *   BTLV_SCU_InitMessage 0x021EAF18 thumb ov093
 *   BTL_MAIN_IsTrainerSlotNpc 0x021B9F70 thumb ov093
 *   BTLV_SCU_AppendMessageArg 0x021EAF50 thumb ov093
 *   BTLV_CORE_BuildAndPrintMessage 0x021EA614 thumb ov093
 *   BTLV_CORE_WaitMessage 0x021EA710 thumb ov093
 *   BTL_MAIN_GetClientTrainerIndex 0x021B8BEC thumb ov093
 *   BTLV_CORE_StartMonSwap 0x021EA488 thumb ov093
 *   BTLV_CORE_WaitMonSwap 0x021EA4C4 thumb ov093
 *   BTL_CLIENT_StoreMonParam 0x021CDECC thumb ov093
 */
#include "../include/Obj01691.h"
#include "../include/Obj21146.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct S;
extern u8 *BTL_SIDE_GetClientPoke(void *p, u32 i, u8 j);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern int BTL_MAIN_IsOpposingPos(int a, int b, int c);
extern int BTL_CLIENT_PickSendOutMessageId(void *);
struct L;
extern void BTLV_SCU_InitMessage(struct L *p, int kind, int id);
extern int BTL_MAIN_IsTrainerSlotNpc(u8 *p, int i);
struct H;
struct L;
extern void BTLV_SCU_AppendMessageArg(struct L *p, u32 val);
extern void BTLV_CORE_BuildAndPrintMessage(char *p, struct H *h);
extern int BTLV_CORE_WaitMessage(u32 *p);
extern u8 BTL_MAIN_GetClientTrainerIndex(u8 *, u32, u8);
extern void BTLV_CORE_StartMonSwap(struct S *s, u8 a, u8 b, u8 c);
extern int BTLV_CORE_WaitMonSwap(struct S *s);
extern void BTL_CLIENT_StoreMonParam(u8 *p);
static inline void message(u8 *p, int code, u32 value, u32 id)
{
    BTLV_SCU_InitMessage((struct L *)(p + 0x58), 1, code);
    BTLV_SCU_AppendMessageArg((struct L *)(p + 0x58), value);
    BTLV_SCU_AppendMessageArg((struct L *)(p + 0x58), id);
    BTLV_CORE_BuildAndPrintMessage(((struct Obj21146 *)p)->f54, (struct H *)(p + 0x58));
}
int BTL_CLIENT_StepSendOutMon(u8 *p, int *state, const u32 *params)
{
    u8 a = params[0];
    u8 b = params[1];
    u8 flag = params[3];
    u8 id;
    switch (*state) {
    case 0:
        if (flag != 0) {
            id = BTL_POKEPARAM_GetPokeId(BTL_SIDE_GetClientPoke(((struct Obj01691 *)p)->f4, a, b));
            if (BTL_MAIN_IsOpposingPos((int)(((struct Obj01691 *)p)->f0), p[0x1A6], a) == 0) {
                if (p[0x1A6] == a) {
                    BTLV_SCU_InitMessage((struct L *)(p + 0x58), 1, BTL_CLIENT_PickSendOutMessageId(p));
                    BTLV_SCU_AppendMessageArg((struct L *)(p + 0x58), id);
                    BTLV_CORE_BuildAndPrintMessage(((struct Obj01691 *)p)->f54, (struct H *)(p + 0x58));
                } else {
                    message(p, 0x11, a, id);
                }
            } else if (BTL_MAIN_IsTrainerSlotNpc(((struct Obj01691 *)p)->f0, a) != 0) {
                message(p, 0xE, a, id);
            } else {
                message(p, 0x11, a, id);
            }
        }
        (*state)++;
        break;
    case 1:
        if (BTLV_CORE_WaitMessage(((struct Obj01691 *)p)->f54) != 0) {
            BTLV_CORE_StartMonSwap(((struct Obj01691 *)p)->f54, BTL_MAIN_GetClientTrainerIndex(*(u8 * *)&((struct Obj01691 *)p)->f0, a, b), a, b);
            (*state)++;
        }
        break;
    case 2:
        if (BTLV_CORE_WaitMonSwap(((struct Obj01691 *)p)->f54) != 0) {
            BTL_CLIENT_StoreMonParam(p);
            return 1;
        }
        break;
    }
    return 0;
}
