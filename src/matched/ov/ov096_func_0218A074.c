/*
 * function: TR_AI_CmdCompareStat0
 * address: 0x0218A074
 * packet: pkt_ov096_0218A074
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TR_AI_CompareStat 0x0218A0A4 thumb ov096
 */
#include "../include/Obj21984.h"
typedef unsigned char  u8;
struct Cursor;
extern int TR_AI_CompareStat(struct Cursor *a, u8 *b, int c);
int TR_AI_CmdCompareStat0(struct Cursor *a, unsigned char *b) { TR_AI_CompareStat(a,b,0); return ((struct Obj21984 *)b)->fC4; }
