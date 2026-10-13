/*
 * function: BTL_EVENT_ResetVarStack
 * address: 0x021D74C8
 * packet: pkt_ov093_021D74C8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gBtlEventVarStack 0x021F3ECC data a4
 */

#include "../include/G_Tbl.h"

typedef struct { unsigned int count; unsigned short keys[0x60]; } Tbl;
extern struct Tbl gBtlEventVarStack;
void BTL_EVENT_ResetVarStack(void) { Tbl *p = ((Tbl *)&gBtlEventVarStack); unsigned int i; p->count = 0; for (i = 0; i < 0x60; i++) p->keys[i] = 0; }
