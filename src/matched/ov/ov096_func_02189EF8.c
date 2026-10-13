/*
 * function: TR_AI_CmdJumpIfSubstitute
 * address: 0x02189EF8
 * packet: pkt_ov096_02189EF8
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   VM_GetU32 0x0201134C thumb
 *   VM_Jump 0x020113B0 thumb
 *   TR_AI_GetPosition 0x0218A160 thumb ov096
 *   TR_AI_GetPoke 0x0218A2FC thumb ov096
 *   BTL_POKEPARAM_HasSubstitute 0x021D6D7C thumb ov093
 */
#include "../include/Obj00005.h"
#include "../include/Obj21978.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
struct Cur;
extern void VM_Jump(struct Cur *c, u32 v);
extern u8 TR_AI_GetPosition(u8 *p, int k);
extern u8 *TR_AI_GetPoke(u8 *p, u8 i);
extern u32 BTL_POKEPARAM_HasSubstitute(u8 *p);
int TR_AI_CmdJumpIfSubstitute(struct Cursor *a, u8 *b)
{
    int t; u32 n; u8 s; t = VM_GetU32(a); n = VM_GetU32(a); s = TR_AI_GetPosition(b,t); if (BTL_POKEPARAM_HasSubstitute(TR_AI_GetPoke(b,s))) VM_Jump((struct Cur *)a, *(u32 *)&((struct Obj00005 *)a)->f14 + n); return ((struct Obj21978 *)b)->fC4;
}
