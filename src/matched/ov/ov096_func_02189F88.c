/*
 * function: TR_AI_CmdIfNotEqual
 * address: 0x02189F88
 * packet: pkt_ov096_02189F88
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TR_AI_CompareGeneric 0x02189F98 thumb ov096
 */
#include "../include/Obj21982.h"
extern int TR_AI_CompareGeneric(unsigned char *, unsigned char *, int);
int TR_AI_CmdIfNotEqual(unsigned char *a, unsigned char *b) { TR_AI_CompareGeneric(a,b,3); return ((struct Obj21982 *)b)->fC4; }
