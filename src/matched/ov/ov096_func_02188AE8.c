/*
 * function: TR_AI_CmdIfMoveNotEqual
 * address: 0x02188AE8
 * packet: pkt_ov096_02188AE8
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TR_AI_CompareMove 0x02188AF8 thumb ov096
 */
#include "../include/Obj21943.h"
struct Cursor;
extern int TR_AI_CompareMove(struct Cursor *a, unsigned char *b, int c);
int TR_AI_CmdIfMoveNotEqual(void *a, unsigned char *b) { TR_AI_CompareMove(a,b,3); return ((struct Obj21943 *)b)->fC4; }
