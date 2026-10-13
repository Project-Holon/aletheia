/*
 * function: TR_AI_CmdIfEqual
 * address: 0x02189F78
 * packet: pkt_ov096_02189F78
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TR_AI_CompareGeneric 0x02189F98 thumb ov096
 */
#include "../include/Obj21981.h"
extern int TR_AI_CompareGeneric(unsigned char *, unsigned char *, int);
int TR_AI_CmdIfEqual(unsigned char *a, unsigned char *b) { TR_AI_CompareGeneric(a,b,2); return ((struct Obj21981 *)b)->fC4; }
