/*
 * function: TR_AI_CmdIfNoPartyMajorStatus
 * address: 0x02188FBC
 * packet: pkt_ov096_02188FBC
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TR_AI_ComparePartyMajorStatus 0x02188FCC thumb ov096
 */
#include "../include/Obj21947.h"
struct Cursor;
extern void TR_AI_ComparePartyMajorStatus(struct Cursor *a, int b, int c);
int TR_AI_CmdIfNoPartyMajorStatus(struct Cursor *a, unsigned char *b) { TR_AI_ComparePartyMajorStatus(a,(int)b,3); return ((struct Obj21947 *)b)->fC4; }
