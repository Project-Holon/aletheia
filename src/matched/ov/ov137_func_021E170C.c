/*
 * function: GURU2_MAIN_CountReadyMembers
 * address: 0x021E170C
 * packet: pkt_ov137_021E170C
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
#include "../include/Obj01753.h"
#include "../include/Obj23806.h"

int GURU2_MAIN_CountReadyMembers(char *p) { int count; unsigned int x; count=0;x=((struct Obj23806 *)(*(char * *)&((struct Obj01753 *)p)->fDC))->f42;while(x) { count+=x&1; x>>=1; }return count; }
