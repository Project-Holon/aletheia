/*
 * function: TR_AI_CmdIfMoveEffectSequenceEqual
 * address: 0x0218906C
 * packet: pkt_ov096_0218906C
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TR_AI_CompareMoveEffectSequence 0x0218908C thumb ov096
 */
#include "../include/Obj21948.h"
typedef unsigned char  u8;
extern void TR_AI_CompareMoveEffectSequence(u8 *a, int b, int c);
int TR_AI_CmdIfMoveEffectSequenceEqual(void *a, unsigned char *b) { TR_AI_CompareMoveEffectSequence(a,(int)b,2); return ((struct Obj21948 *)b)->fC4; }
