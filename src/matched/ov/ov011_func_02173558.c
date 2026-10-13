/*
 * function: INTRUDE_COMM_SuspendPlayers
 * address: 0x02173558
 * packet: pkt_ov011_02173558
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   COMM_PLAYER_Suspend 0x02167688 thumb ov010
 * Extent contains followers 02173568, already-filed 02173580, and 0217358C;
 * the lead stays separate to preserve the existing follower file.
 */
#include "../include/Obj19162.h"
typedef struct { void *sys; void *obj; } Work;
struct Work;
extern void COMM_PLAYER_Suspend(struct Work *w);
void INTRUDE_COMM_SuspendPlayers(int a, char *p)
{
    if (p != 0)
        COMM_PLAYER_Suspend((struct Work *)(*(Work * *)&((struct Obj19162 *)p)->f8));
}
