/*
 * function: BTL_SERVER_FLOW_ProcFieldEffectsExpire
 * address: 0x021C4C24
 * packet: pkt_ov093_021C4C24
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * The extent continues into the existing SDK BTL_SERVER_FLOW_OnFieldEffectExpired at 021C4C40.
 * DWC_StartUtilityEx takes two full-word payloads; the original passes
 * the callback address and p unchanged in r0/r1.
 * symbols:
 *   BTL_FIELD_QueryStaticSlotC 0x021EF934 thumb ov093
 *   BTL_SERVER_CMD_Push 0x021CD4B0 thumb ov093
 *   func_021C4C40 0x021C4C40 thumb ov093
 */
#include "../include/Obj21096.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int BTL_FIELD_QueryStaticSlotC(int, int);
extern void BTL_SERVER_CMD_Push(void *w, volatile u32 id, ...);
extern void func_021C4C40(int, void *);
void BTL_SERVER_FLOW_ProcFieldEffectsExpire(u8 *p)
{
    BTL_FIELD_QueryStaticSlotC((int)func_021C4C40, (int)p);
    BTL_SERVER_CMD_Push(((struct Obj21096 *)p)->fC, 47, 0);
}
