/*
 * function: INTRUDE_COMM_RecvPeerLeft
 * address: 0x021738BC
 * packet: pkt_ov011_021738BC
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   COMM_PLAYER_Del 0x02167658 thumb ov010
 * The index loaded from c remains live in r1 into 02167658.
 */
#include "../include/Obj09343.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { void *sys; void *obj; } Work;
extern void COMM_PLAYER_Del(Work *, int);
void INTRUDE_COMM_RecvPeerLeft(int a, int b, int *c, u8 *d, void *e)
{
    int i;
    u32 bit;
    u8 mask;
    i = *c;
    bit = 1u << i;
    mask = d[0x8fb];
    if (mask & bit) {
        d[0x8fb] = mask ^ (u8)bit;
        COMM_PLAYER_Del(*(Work * *)&((struct Obj09343 *)d)->f8, i);
    }
}
