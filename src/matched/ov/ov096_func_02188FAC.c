/*
 * function: TR_AI_CmdIfAnyPartyMajorStatus
 * address: 0x02188FAC
 * packet: pkt_ov096_02188FAC
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TR_AI_ComparePartyMajorStatus 0x02188FCC thumb ov096
 */
#include "../include/Obj21946.h"
struct Cursor;
extern void TR_AI_ComparePartyMajorStatus(struct Cursor *a, int b, int c);
int TR_AI_CmdIfAnyPartyMajorStatus(struct Cursor *a, unsigned char *b) { TR_AI_ComparePartyMajorStatus(a,(int)b,2); return ((struct Obj21946 *)b)->fC4; }
