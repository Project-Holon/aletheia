/*
 * function: func_02188FAC
 * address: 0x02188FAC
 * packet: pkt_ov096_02188FAC
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02188FCC 0x02188FCC thumb ov096
 */
#include "../include/Obj21946.h"
struct Cursor;
extern void func_02188FCC(struct Cursor *a, int b, int c);
int func_02188FAC(struct Cursor *a, unsigned char *b) { func_02188FCC(a,(int)b,2); return ((struct Obj21946 *)b)->fC4; }
