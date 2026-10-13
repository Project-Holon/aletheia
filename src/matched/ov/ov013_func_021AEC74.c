/*
 * function: VCT_MAIN_RequestConnection
 * address: 0x021AEC74
 * packet: pkt_ov013_021AEC74
 * region: ov013
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: 2026-10-05 the call to VCT_SESSION_SendGroupCommand is written in each arm of the
 *   null test (new allocation, existing node); the compiler cross-jumps the
 *   shared tail and the first arm uses the call result register directly.
 * symbols:
 *   gVctWork 0x021B3C80 data ov013 a4
 *   VCT_SESSION_AllocPeerRecord 0x021B1F2C arm ov013
 *   VCT_SESSION_SendGroupCommand 0x021B20B0 arm ov013
 *   VCT_SESSION_FreePeerRecord 0x021B1F54 arm ov013
 */

#include "../include/G_Work.h"

typedef unsigned char u8;
struct Node;

extern struct Work *gVctWork;

extern struct Node *VCT_SESSION_AllocPeerRecord(unsigned int i);
extern int VCT_SESSION_SendGroupCommand(int p, int x);
extern int VCT_SESSION_FreePeerRecord(struct Node *p);

int VCT_MAIN_RequestConnection(int i)
{
    struct Node *p = gVctWork->f1A1C;
    int r;

    if (p == 0) {
        p = VCT_SESSION_AllocPeerRecord(i);
        if (p == 0) {
            return 0;
        }
        r = VCT_SESSION_SendGroupCommand((int)p, 0);
    } else {
        r = VCT_SESSION_SendGroupCommand((int)p, 0);
    }
    if (r != 0) {
        VCT_SESSION_FreePeerRecord(p);
        gVctWork->f1A1C = 0;
        return 0;
    }
    gVctWork->f1A1C = p;
    return 1;
}
