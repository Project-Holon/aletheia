/*
 * function: BTL_SERVER_FLOW_ProcOhkoSubstituteBroken
 * address:  0x021C3720
 * packet:   pkt_ov093_021C3720
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_POKEPARAM_GetSubstituteHp  0x021D6D90  thumb  ov093
 *   BTL_SERVER_CMD_Push  0x021CD4B0  thumb  ov093
 *   BTL_SERVER_FLOW_RemoveSubstitute  0x021C41C0  thumb  ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern int BTL_POKEPARAM_GetSubstituteHp(u8 *p);
extern void BTL_SERVER_CMD_Push(void *w, volatile u32 id, ...);
extern void BTL_SERVER_FLOW_RemoveSubstitute(u8 *p, u8 *a);

u16 BTL_SERVER_FLOW_ProcOhkoSubstituteBroken(u8 *p, u8 *a, u16 *b, int c)
{
    int i = BTL_POKEPARAM_GetPokeId(a);
    u16 v = BTL_POKEPARAM_GetSubstituteHp(a);
    BTL_SERVER_CMD_Push(((struct Obj00003 *)p)->fC, 0x34, i);
    BTL_SERVER_CMD_Push(((struct Obj00003 *)p)->fC, 0x32, i, (u8)c, *b);
    BTL_SERVER_FLOW_RemoveSubstitute(p, a);
    return v;
}
