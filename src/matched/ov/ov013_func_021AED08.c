/*
 * function: VCT_MAIN_OnEventGroup
 * address: 0x021AED08
 * packet: pkt_ov013_021AED08
 * region: ov013
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   VCT_MAIN_ReleasePeer 0x021AEDEC thumb ov013
 *   VCT_MIXER_AddMember 0x021B0614 arm ov013
 */
struct Node;
extern void VCT_MAIN_ReleasePeer(struct Node *p);
extern int VCT_MIXER_AddMember(void *);
void VCT_MAIN_OnEventGroup(int unused,int code,void *p)
{
    switch(code) {
    case 9: VCT_MAIN_ReleasePeer(p); break;
    case 7: VCT_MIXER_AddMember(p); break;
    case 12: VCT_MAIN_ReleasePeer(p); break;
    }
}
