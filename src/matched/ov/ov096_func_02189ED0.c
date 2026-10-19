/*
 * function: TR_AI_CmdLoadCurrentAbility
 * address: 0x02189ED0
 * packet: pkt_ov096_02189ED0
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   VM_GetU32 0x0201134C thumb
 *   TR_AI_GetPosition 0x0218A160 thumb ov096
 *   TR_AI_GetPoke 0x0218A2FC thumb ov096
 *   BTL_POKEPARAM_GetValue 0x021D59B4 thumb ov093
 */
#include "../include/Obj13667.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern u8 TR_AI_GetPosition(u8 *p, int k);
extern u8 *TR_AI_GetPoke(u8 *p, u8 i);
extern int BTL_POKEPARAM_GetValue(u8 *p, int k);
int TR_AI_CmdLoadCurrentAbility(struct Cursor *a, u8 *b)
{
    int t; u8 s; t = VM_GetU32(a); s = TR_AI_GetPosition(b,t); ((struct Obj13667 *)b)->f38 = BTL_POKEPARAM_GetValue(TR_AI_GetPoke(b,s),17); return ((struct Obj13667 *)b)->fC4;
}
