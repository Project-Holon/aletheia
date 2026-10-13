/*
 * function: BTL_SERVER_FLOW_PushMoveEffectiveness
 * address:  0x021C5798
 * packet:   pkt_ov093_021C5798
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_SERVER_FLOW_SubtractHp  0x021C604C  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_SERVER_CMD_Push  0x021CD4B0  thumb  ov093
 *   BTL_SERVER_CMD_WriteU8Wrapper  0x021CD63C  thumb  ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_SERVER_CMD_Push(void *w, volatile u32 id, ...);
extern void BTL_SERVER_CMD_WriteU8Wrapper(void *p, int v);
extern void BTL_SERVER_FLOW_SubtractHp(u8 *p, u8 *a, int n);

void BTL_SERVER_FLOW_PushMoveEffectiveness(u8 *p, u16 *a, u32 n, int *arr, u8 **ptrs, u16 *vals, u8 *unused1, int unused2)
{
    u32 i;
    u8 hi;
    u8 lo;
    int k;
    lo = 0;
    hi = 0;
    for (i = 0; i < n; i++) {
        BTL_SERVER_FLOW_SubtractHp(p, ptrs[i], vals[i]);
        if (arr[i] > 3) hi++;
        if (arr[i] < 3) lo++;
    }
    if (hi) k = 2;
    else if (lo) k = 3;
    else k = 1;
    BTL_SERVER_CMD_Push(((struct Obj00003 *)p)->fC, 0x33, (u8)n, (u8)k, *a);
    for (i = 0; i < n; i++) {
        BTL_SERVER_CMD_WriteU8Wrapper(((struct Obj00003 *)p)->fC, BTL_POKEPARAM_GetPokeId(ptrs[i]));
    }
}
