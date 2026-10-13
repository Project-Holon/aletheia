/*
 * function: VCT_SESSION_AllocPeer
 * address:  0x021B24FC
 * packet:   pkt_ov013_021B24FC
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gVctSession  0x021B60D8  data  ov013  a4
 *   gVctPeerPool  0x021B4BE0  data  a4
 *   VCT_SESSION_InitPeer  0x021B2724  arm  ov013
 */

#include "../include/G_Pool.h"

typedef unsigned char u8;

typedef struct Ctx {
    u8 b0;
} Ctx;

typedef struct Node {
    char pad[0x14];
    struct Node *next;
} Node;

typedef struct Pool Pool;

extern Ctx gVctSession;
extern struct Pool gVctPeerPool;
extern void VCT_SESSION_InitPeer(Node *n, unsigned int idx);

Node *VCT_SESSION_AllocPeer(unsigned int idx)
{
    Node *n;

    if (idx >= 0x20)
        return 0;
    if (idx == gVctSession.b0)
        return 0;
    n = gVctPeerPool.nodes;
    if (n == 0)
        return 0;
    gVctPeerPool.nodes = n->next;
    VCT_SESSION_InitPeer(n, idx);
    n->next = gVctPeerPool.head;
    gVctPeerPool.head = n;
    return n;
}
