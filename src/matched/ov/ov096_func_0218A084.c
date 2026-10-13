/*
 * function: TR_AI_CmdCompareStat1
 * address: 0x0218A084
 * packet: pkt_ov096_0218A084
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TR_AI_CompareStat 0x0218A0A4 thumb ov096
 */
#include "../include/Obj21985.h"
typedef unsigned char  u8;
struct Cursor;
extern int TR_AI_CompareStat(struct Cursor *a, u8 *b, int c);
int TR_AI_CmdCompareStat1(struct Cursor *a, unsigned char *b) { TR_AI_CompareStat(a,b,1); return ((struct Obj21985 *)b)->fC4; }
