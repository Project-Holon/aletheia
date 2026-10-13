/*
 * function: VCT_SESSION_HandlePairedPacket
 * address:  0x021B2AA0
 * packet:   pkt_ov013_021B2AA0
 * region:   ov013
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021B4BE0     0x021B4BE0  data  a4
 *   VCT_SESSION_HandleAnnounce  0x021B2DD0  arm  ov013
 *   VCT_SESSION_FindPeer  0x021B2A20  arm  ov013
 *   VCT_SESSION_AdvancePhase  0x021B2894  arm  ov013
 *   VCT_SESSION_GetEventCode  0x021B279C  arm  ov013
 *   VCT_SESSION_AllocPeer  0x021B24FC  arm  ov013
 *   VCT_SESSION_InitPeer  0x021B2724  arm  ov013
 *   VCT_SESSION_SendReply  0x021B25B0  arm  ov013
 *   VCT_SESSION_FreePeerRecord  0x021B1F54  arm  ov013
 */

struct Node {
    unsigned int state;
    unsigned char f4;
    unsigned char f5;
    unsigned short f6;
    unsigned int f8;
    unsigned int fc;
    unsigned int f10;
    struct Node *next;
};

struct Pool {
    struct Node *nodes;
    unsigned int f4;
    void *tick;
    unsigned int mul;
    unsigned int add;
    struct Node freeList;
    struct Node active;
};

struct Pkt {
    unsigned char pad0[4];
    unsigned char f4;
    unsigned char f5;
    unsigned char f6;
    unsigned char f7;
    unsigned char f8;
    unsigned char f9;
    unsigned char fa;
    unsigned char fb;
    unsigned int fc;
};

struct Event {
    int type;
    struct Node *node;
};

extern struct Pool g_021B4BE0;
extern int VCT_SESSION_HandleAnnounce(struct Pkt *pkt, struct Event *ev);
struct N;
extern struct N *VCT_SESSION_FindPeer(int id);
typedef unsigned char  u8;
struct Ctx;
struct Msg;
struct Q;
extern int VCT_SESSION_AdvancePhase(struct Ctx *c, struct Msg *m);
extern int VCT_SESSION_GetEventCode(u8 *o, struct Q *q);
extern struct Node *VCT_SESSION_AllocPeer(unsigned int idx);
extern void VCT_SESSION_InitPeer(u8 *p, u8 v);
extern int VCT_SESSION_SendReply(int a, int b);
extern int VCT_SESSION_FreePeerRecord(struct Node *p);

int VCT_SESSION_HandlePairedPacket(struct Pkt *pkt, struct Event *ev)
{
    struct Node *node;
    int r;

    if (pkt->f4 == 0xFF) {
        if (pkt->f6 == 4)
            return VCT_SESSION_HandleAnnounce(pkt, ev);
        if (pkt->f6 == 3)
            return 0;
    }
    node = (struct Node *)VCT_SESSION_FindPeer(pkt->f8);
    if (node) {
        r = VCT_SESSION_AdvancePhase((struct Ctx *)node, (struct Msg *)pkt);
        switch (r) {
        case -1:
            return 0;
        case -2:
            ev->type = 0xC;
            node->state = 0;
            ev->node = node;
            return 1;
        }
        ev->type = VCT_SESSION_GetEventCode((u8 *)pkt, (struct Q *)node);
        ev->node = node;
        node->fc = r;
        return ev->type != 0;
    }
    node = VCT_SESSION_AllocPeer(pkt->f8);
    if (node == 0) {
        VCT_SESSION_InitPeer((u8 *)(&g_021B4BE0.freeList), pkt->f8);
        VCT_SESSION_SendReply((int)(&g_021B4BE0.freeList), 3);
        return 0;
    }
    r = VCT_SESSION_AdvancePhase((struct Ctx *)node, (struct Msg *)pkt);
    if (r == -2 || r == -1) {
        VCT_SESSION_FreePeerRecord(node);
        return 0;
    }
    ev->type = VCT_SESSION_GetEventCode((u8 *)pkt, (struct Q *)node);
    ev->node = node;
    node->fc = r;
    return ev->type != 0;
}
