/*
 * function: TR_AI_CompareMoveParam28
 * address: 0x0218908C
 * packet: pkt_ov096_0218908C
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * return: TR_AI_GetMoveParam's r0 is consumed by original caller, overriding its void forwarder declaration.
 * symbols:
 *   VM_GetU32 0x0201134C thumb
 *   TR_AI_GetMoveParam 0x0218A378 thumb ov096
 *   TR_AI_Compare 0x0218A0F4 thumb ov096
 */
#include "../include/Obj21950.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Cursor;
extern u32 VM_GetU32(struct Cursor *);
extern int TR_AI_GetMoveParam(int, int, int);
extern int TR_AI_Compare(u8 *, int, int, int, int);
void TR_AI_CompareMoveParam28(u8 *a, int b, int c)
{
    int t0, t1;
    t0 = VM_GetU32((struct Cursor *)a);
    t1 = VM_GetU32((struct Cursor *)a);
    TR_AI_Compare(a, c, TR_AI_GetMoveParam(b, ((struct Obj21950 *)b)->f2, 28), t0, t1);
}
