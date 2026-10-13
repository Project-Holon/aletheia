/*
 * function: TR_AI_CmdIfGreater
 * address: 0x02189F68
 * packet: pkt_ov096_02189F68
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TR_AI_CompareGeneric 0x02189F98 thumb ov096
 */
#include "../include/Obj21980.h"
extern int TR_AI_CompareGeneric(unsigned char *, unsigned char *, int);
int TR_AI_CmdIfGreater(unsigned char *a, unsigned char *b) { TR_AI_CompareGeneric(a,b,1); return ((struct Obj21980 *)b)->fC4; }
