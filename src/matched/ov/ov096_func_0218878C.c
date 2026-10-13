/*
 * function: TR_AI_CmdAddScore
 * address: 0x0218878C
 * packet: pkt_ov096_0218878C
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   VM_GetU32 0x0201134C thumb
 */
#include "../include/Obj07919.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Cursor;
extern u32 VM_GetU32(struct Cursor *);
int TR_AI_CmdAddScore(struct Cursor *a, u8 *b)
{
    u32 value;
    value = VM_GetU32(a);
    *(u32 *)((u32)b + 4 + b[1] * 4) += value;
    if (*(int *)((u32)b + 4 + b[1] * 4) < 0)
        *(int *)((u32)b + 4 + b[1] * 4) = 0;
    return ((struct Obj07919 *)b)->fC4;
}
