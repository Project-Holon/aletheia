/*
 * function: TR_AI_CmdLoadSpecies
 * address: 0x02189F34
 * packet: pkt_ov096_02189F34
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   VM_GetU32 0x0201134C thumb
 *   TR_AI_GetPosition 0x0218A160 thumb ov096
 *   TR_AI_GetPoke 0x0218A2FC thumb ov096
 *   BTL_POKEPARAM_GetSpecies 0x021D5444 thumb ov093
 */
#include "../include/Obj13668.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern u8 TR_AI_GetPosition(u8 *p, int k);
extern u8 *TR_AI_GetPoke(u8 *p, u8 i);
struct QF;
extern u16 BTL_POKEPARAM_GetSpecies(struct QF *p);
int TR_AI_CmdLoadSpecies(struct Cursor *a, u8 *b)
{
    int t; u8 s; t = VM_GetU32(a); s = TR_AI_GetPosition(b,t); ((struct Obj13668 *)b)->f38 = BTL_POKEPARAM_GetSpecies((struct QF *)TR_AI_GetPoke(b,s)); return ((struct Obj13668 *)b)->fC4;
}
