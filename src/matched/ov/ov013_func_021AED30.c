/*
 * function: VCT_MAIN_OnEventPair
 * address:  0x021AED30
 * packet:   pkt_ov013_021AED30
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   VCT_SESSION_SendPeerReply  0x021B2180  arm  ov013
 *   VCT_SESSION_AddMember  0x021B0614  arm  ov013
 *   VCT_SESSION_FreePeerRecord  0x021B1F54  arm  ov013
 *   VCT_MAIN_ReleasePeer  0x021AEDEC  thumb  ov013
 *   gVctWork     0x021B3C80  data  ov013
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct W {
    u8 pad0[0x19A8];
    u32 f19A8;
    u32 f19AC;
    u8 pad1[0x1A1C - 0x19B0];
    u32 f1A1C;
};

extern struct W *gVctWork;

struct Node;
extern int VCT_SESSION_SendPeerReply(int a, int b);
extern int VCT_SESSION_AddMember(void *p);
extern int VCT_SESSION_FreePeerRecord(struct Node *p);
extern void VCT_MAIN_ReleasePeer(struct Node *p);

void VCT_MAIN_OnEventPair(int a, int code, u32 *p)
{
    switch (code) {
    case 1:
        if (gVctWork->f1A1C != 0) {
            VCT_SESSION_SendPeerReply((int)p, 3);
            VCT_SESSION_FreePeerRecord((struct Node *)p);
            return;
        }
        gVctWork->f1A1C = (u32)p;
        return;
    case 8:
        VCT_SESSION_SendPeerReply((int)p, 0);
        VCT_MAIN_ReleasePeer((struct Node *)p);
        return;
    case 9:
        VCT_MAIN_ReleasePeer((struct Node *)p);
        return;
    case 4:
        VCT_SESSION_SendPeerReply((int)p, 4);
        VCT_MAIN_ReleasePeer((struct Node *)p);
        return;
    case 7:
        if (*p != gVctWork->f19A8) {
            VCT_MAIN_ReleasePeer((struct Node *)p);
            return;
        }
        if (VCT_SESSION_AddMember(p) != 0) {
            gVctWork->f19AC = 2;
            return;
        }
        break;
    case 2:
        VCT_MAIN_ReleasePeer((struct Node *)p);
        return;
    case 3:
    case 11:
    case 12:
        VCT_MAIN_ReleasePeer((struct Node *)p);
        break;
    }
}
