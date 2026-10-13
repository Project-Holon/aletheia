/*
 * function: TR_AI_CmdIfMoveParam28Equal
 * address: 0x0218906C
 * packet: pkt_ov096_0218906C
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TR_AI_CompareMoveParam28 0x0218908C thumb ov096
 */
#include "../include/Obj21948.h"
typedef unsigned char  u8;
extern void TR_AI_CompareMoveParam28(u8 *a, int b, int c);
int TR_AI_CmdIfMoveParam28Equal(void *a, unsigned char *b) { TR_AI_CompareMoveParam28(a,(int)b,2); return ((struct Obj21948 *)b)->fC4; }
