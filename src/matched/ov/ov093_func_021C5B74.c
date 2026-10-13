/*
 * function: BTL_SERVER_FLOW_ChangeHp
 * address:  0x021C5B74
 * packet:   pkt_ov093_021C5B74
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_POKEPARAM_AddHp  0x021D5FA4  thumb  ov093
 *   BTL_SERVER_CMD_Push  0x021CD4B0  thumb  ov093
 *   BTL_SERVER_FLOW_SubtractHp  0x021C604C  thumb  ov093
 *   func_021C5BD4  0x021C5BD4  thumb  ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
struct Unk021D5FA4;
extern void BTL_POKEPARAM_AddHp(struct Unk021D5FA4 *p, u16 n);
extern void BTL_SERVER_CMD_Push(void *w, volatile u32 id, ...);
extern void BTL_SERVER_FLOW_SubtractHp(u8 *p, u8 *a, int n);
extern int func_021C5BD4(void *p, int v);

void BTL_SERVER_FLOW_ChangeHp(u8 *p, u8 *a, int c, int d)
{
    u8 n = BTL_POKEPARAM_GetPokeId(a);
    if (c > 0) {
        BTL_POKEPARAM_AddHp((struct Unk021D5FA4 *)a, (u16)c);
        BTL_SERVER_CMD_Push(((struct Obj00003 *)p)->fC, 2, n, (u16)c);
    } else if (c < 0) {
        BTL_SERVER_FLOW_SubtractHp(p, a, -c);
    }
    if (d) {
        if (func_021C5BD4(p + 0x1AB8, n) != 6) {
            BTL_SERVER_CMD_Push(((struct Obj00003 *)p)->fC, 0x41, n);
        }
    }
}
