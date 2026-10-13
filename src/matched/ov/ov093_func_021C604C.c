/*
 * function: BTL_SERVER_FLOW_SubtractHp
 * address: 0x021C604C
 * packet: pkt_ov093_021C604C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTL_SERVER_CMD_Push 0x021CD4B0 thumb ov093
 *   func_021B911C 0x021B911C thumb ov093
 *   BTL_POKEPARAM_SubHp 0x021D5F90 thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_SERVER_CMD_Push(void *w, volatile u32 id, ...);
extern int func_021B911C(void *, int);
extern void BTL_POKEPARAM_SubHp(u8 *, u16);
void BTL_SERVER_FLOW_SubtractHp(u8 *p, u8 *a, int n)
{
    if (func_021B911C(((struct Obj00003 *)p)->f4, 4) == 0) {
        BTL_POKEPARAM_SubHp(a, n);
        BTL_SERVER_CMD_Push(((struct Obj00003 *)p)->fC, 1, BTL_POKEPARAM_GetPokeId(a), (u16)n);
    }
}
