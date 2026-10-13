/*
 * function: BTL_SERVER_FLOW_ProcMemberIn
 * address: 0x021BD9D4
 * packet: pkt_ov093_021BD9D4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: 42-byte function followed by 2-byte zero alignment padding.
 * symbols:
 *   BTL_SERVER_FLOW_ProcMemberInCore 0x021BD8F0 thumb ov093
 *   BTL_SERVER_CMD_Push 0x021CD4B0 thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void BTL_SERVER_FLOW_ProcMemberInCore(u8 *, u8, u8, u8);
extern void BTL_SERVER_CMD_Push(void *w, volatile u32 id, ...);
void BTL_SERVER_FLOW_ProcMemberIn(u8 *p, u8 i, u8 a, u8 b, int c)
{
    BTL_SERVER_FLOW_ProcMemberInCore(p, i, a, b);
    BTL_SERVER_CMD_Push(((struct Obj00003 *)p)->fC, 61, i, a, b, (u8)c);
}
