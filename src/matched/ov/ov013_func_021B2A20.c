/*
 * function: VCT_SESSION_FindPeer
 * address:  0x021B2A20
 * packet:   pkt_ov013_021B2A20
 * region:   ov013
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gVctSession  0x021B60D8  data  a4
 *   gVctPeerPool  0x021B4BE0  data  a4
 *   d_021B4C0C  0x021B4C0C  data  a4
 */

#include "../include/G_Sess.h"
#include "../include/G_N.h"

typedef unsigned char u8;

typedef struct N N;

typedef struct {
    int x;
    N *head;
    int pad[9];
    int flag;
    u8 id;
} G;

extern struct Sess gVctSession;
extern G gVctPeerPool;
extern struct N d_021B4C0C;

N *VCT_SESSION_FindPeer(int id)
{
    N *n;

    n = gVctPeerPool.head;
    if (((int *)&gVctSession)[4] == 2) {
        if (gVctPeerPool.flag != 0 && gVctPeerPool.id == id)
            return &d_021B4C0C;
        return 0;
    }
    while (n) {
        if (n->a != 0 && n->id == id)
            return n;
        n = n->next;
    }
    return 0;
}
