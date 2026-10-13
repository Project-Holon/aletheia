/*
 * function: VCT_MAIN_ReleasePeer
 * address: 0x021AEDEC
 * packet: pkt_ov013_021AEDEC
 * region: ov013
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gVctWork 0x021B3C80 data ov013 a4
 *   VCT_SESSION_RemoveMember 0x021B074C arm ov013
 *   VCT_SESSION_FreePeerRecord 0x021B1F54 arm ov013
 *   DWC_RAP_CleanupVchat 0x02156400 thumb ov009
 */

#include "../include/G_Work.h"

typedef unsigned char u8;
extern struct Work *gVctWork;
struct Node;
extern void VCT_SESSION_RemoveMember(void *);
extern int VCT_SESSION_FreePeerRecord(struct Node *);
extern void DWC_RAP_CleanupVchat(void);
void VCT_MAIN_ReleasePeer(struct Node *p)
{
    VCT_SESSION_RemoveMember(p);
    VCT_SESSION_FreePeerRecord(p);
    *(int *)(((u8 *)gVctWork) + 0x1A1C) = 0;
    DWC_RAP_CleanupVchat();
}
