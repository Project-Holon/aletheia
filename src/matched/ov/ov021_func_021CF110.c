/*
 * function: COMM_ENTRY_StoreJoinReply
 * address:  0x021CF110
 * packet:   pkt_ov021_021CF110
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MYSTATUS_Copy  0x02008494  thumb
 */
#include "../include/Obj20269.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void MYSTATUS_Copy(void *a, void *b);

void COMM_ENTRY_StoreJoinReply(u8 *p, u32 v, void *a)
{
    ((struct Obj20269 *)p)->f52C = v;
    MYSTATUS_Copy(a, p + 0x530);
}
