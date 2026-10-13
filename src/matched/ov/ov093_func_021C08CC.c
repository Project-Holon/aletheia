/*
 * function: BTL_SERVER_FLOW_DecrementMovePP
 * address:  0x021C08CC
 * packet:   pkt_ov093_021C08CC
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_MAIN_ReturnZero  0x021B911C  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_POKEPARAM_DecrementMovePP  0x021D5608  thumb  ov093
 *   BTL_SERVER_CMD_Push  0x021CD4B0  thumb  ov093
 *   BTL_POKEPARAM_MarkMoveUsed  0x021D56CC  thumb  ov093
 */
#include "../include/Obj09966.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_MAIN_ReturnZero(void *p, int k);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
struct UtilWork;
extern void BTL_POKEPARAM_DecrementMovePP(struct UtilWork *p, int i, u8 n);
extern void BTL_SERVER_CMD_Push(void *w, volatile u32 id, ...);
struct Work;
extern void BTL_POKEPARAM_MarkMoveUsed(struct Work *p, int i);

void BTL_SERVER_FLOW_DecrementMovePP(u8 *p, u8 *a, int b, u8 c)
{
    u32 n;
    if (BTL_MAIN_ReturnZero(((struct Obj09966 *)p)->f4, 5) == 0) {
        n = BTL_POKEPARAM_GetPokeId(a);
        BTL_POKEPARAM_DecrementMovePP((struct UtilWork *)a, b, c);
        BTL_SERVER_CMD_Push(((struct Obj09966 *)p)->fC, 4, n, b, c);
        BTL_POKEPARAM_MarkMoveUsed((struct Work *)a, b);
        BTL_SERVER_CMD_Push(((struct Obj09966 *)p)->fC, 6, n, b);
    }
}
