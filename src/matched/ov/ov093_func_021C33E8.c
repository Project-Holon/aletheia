/*
 * function: BTL_SERVER_FLOW_ApplyHpRecover
 * address:  0x021C33E8
 * packet:   pkt_ov093_021C33E8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   func_021C3428  0x021C3428  thumb  ov093
 *   BTL_SERVER_CMD_Push  0x021CD4B0  thumb  ov093
 *   BTL_SERVER_FLOW_ChangeHp  0x021C5B74  thumb  ov093
 */
#include "../include/Obj00003.h"

typedef unsigned char u8;
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern int func_021C3428(int, int);
typedef unsigned int   u32;
extern void BTL_SERVER_CMD_Push(void *w, volatile u32 id, ...);
extern void BTL_SERVER_FLOW_ChangeHp(u8 *p, u8 *a, int c, int d);

void BTL_SERVER_FLOW_ApplyHpRecover(int a, int b, int c)
{
    int v = func_021C3428(a + 0x1ab8, BTL_POKEPARAM_GetPokeId((u8 *)b));
    if (v != 6)
        BTL_SERVER_CMD_Push((void *)(*(int *)&((struct Obj00003 *)a)->fC), 0x4d, v, 0x263);
    BTL_SERVER_FLOW_ChangeHp((u8 *)a, (u8 *)b, c, 1);
}
