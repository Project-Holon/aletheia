/*
 * function: GURU2_MAIN_CountContinueVotes
 * address: 0x021E1954
 * packet: pkt_ov137_021E1954
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: 30-byte body followed by two bytes of zero alignment padding.
 * lever: Initialize count before loading x; declare count before x.
 * Existing result-before-input and declaration-order idioms cover this.
 */
#include "../include/Obj06536.h"
#include "../include/Obj23811.h"

int GURU2_MAIN_CountContinueVotes(char *p) { int count; unsigned int x; count=0;x=((struct Obj23811 *)(*(char * *)&((struct Obj06536 *)p)->fDC))->f4A;while(x) { count+=x&1; x>>=1; }return count; }
