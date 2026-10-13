/*
 * function: TR_AI_CmdIfMoveEqual
 * address: 0x02188AD8
 * packet: pkt_ov096_02188AD8
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TR_AI_CompareMove 0x02188AF8 thumb ov096
 */
#include "../include/Obj21942.h"
struct Cursor;
extern int TR_AI_CompareMove(struct Cursor *a, unsigned char *b, int c);
int TR_AI_CmdIfMoveEqual(void *a, unsigned char *b) { TR_AI_CompareMove(a,b,2); return ((struct Obj21942 *)b)->fC4; }
