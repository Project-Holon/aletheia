/*
 * function: BTL_SERVER_FLOW_RestoreMovePp
 * address:  0x021C6080
 * packet:   pkt_ov093_021C6080
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_POKEPARAM_RestoreRealMovePP  0x021D56A0  thumb  ov093
 *   BTL_POKEPARAM_RestoreMovePP  0x021D5674  thumb  ov093
 *   BTL_SERVER_CMD_Push  0x021CD4B0  thumb  ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_POKEPARAM_RestoreRealMovePP(u8 *a, int b, int c);
extern void BTL_POKEPARAM_RestoreMovePP(u8 *a, int b, int c);
extern void BTL_SERVER_CMD_Push(void *w, volatile u32 id, ...);

void BTL_SERVER_FLOW_RestoreMovePp(u8 *p, u8 *a, int b, int c, int d)
{
    u8 n = BTL_POKEPARAM_GetPokeId(a);
    if (d) {
        BTL_POKEPARAM_RestoreRealMovePP(a, b, c);
        BTL_SERVER_CMD_Push(((struct Obj00003 *)p)->fC, 8, n, b, c);
    } else {
        BTL_POKEPARAM_RestoreMovePP(a, b, c);
        BTL_SERVER_CMD_Push(((struct Obj00003 *)p)->fC, 7, n, b, c);
    }
}
