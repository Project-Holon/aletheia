/*
 * function: TR_AI_CmdLoadMoveParam28
 * address: 0x02188F14
 * packet: pkt_ov096_02188F14
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   TR_AI_GetMoveParam 0x0218A378 thumb ov096
 */
#include "../include/Obj10179.h"
extern int TR_AI_GetMoveParam(int,int,int);
int TR_AI_CmdLoadMoveParam28(int a, unsigned char *b) { ((struct Obj10179 *)b)->f38=TR_AI_GetMoveParam((int)b,((struct Obj10179 *)b)->f2,28); return ((struct Obj10179 *)b)->fC4; }
