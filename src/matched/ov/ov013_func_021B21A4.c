/*
 * function: VCT_SESSION_AddPeer
 * address:  0x021B21A4
 * packet:   pkt_ov013_021B21A4
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * VCT_SESSION_FindPeer takes the id: r0 stays live through the guards, so their
 * loads use r1. id must be unsigned char (plain strb r4 stores).
 *
 * symbols:
 *   gVctSession     0x021B60D8  data  ov013  a4
 *   gVctGroup     0x021B4BD0  data  ov013  a4
 *   VCT_SESSION_FindPeer  0x021B2A20  arm   ov013
 *   VCT_SESSION_AllocPeerRecord  0x021B1F2C  arm   ov013
 */

struct Sess {
    unsigned char id;
    unsigned char pad[3];
    void (*cb)(int, int, void *, unsigned int);
    unsigned int arg;
    unsigned int pad2;
    int f10;
};

struct Chan {
    unsigned char pad[4];
    unsigned char f4;
    unsigned char f5;
    unsigned char pad6[2];
    unsigned int f8;
    int fc;
};

extern struct Sess gVctSession;
extern int gVctGroup;
struct N;
extern struct N *VCT_SESSION_FindPeer(int id);
struct Node;
extern struct Node *VCT_SESSION_AllocPeerRecord(unsigned int i);

int VCT_SESSION_AddPeer(unsigned char id)
{
    struct Chan *c;

    if (gVctSession.f10 != 3)
        return -2;
    if (gVctGroup == 3)
        return -6;
    if (id == gVctSession.id)
        return -1;
    if (VCT_SESSION_FindPeer(id))
        return 0;
    c = (struct Chan *)VCT_SESSION_AllocPeerRecord(id);
    if (c == 0)
        return -1;
    c->f4 = id;
    c->f5 = id;
    c->fc = 2;
    c->f8 = 1 << id;
    gVctSession.cb(id, 7, c, gVctSession.arg);
    gVctGroup++;
    return 0;
}
