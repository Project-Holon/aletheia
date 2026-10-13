/*
 * function: WIH_SetJudgeAcceptFunc
 * address: 0x02179328
 * packet: pkt_ov014_02179328
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gWihWork 0x021797A8 data a4
 */

#include "../include/G_S.h"

typedef unsigned char u8;
extern struct S *gWihWork;
void WIH_SetJudgeAcceptFunc(void *v) { *(void **)(((u8 *)gWihWork) + 0x1E7C) = v; }
