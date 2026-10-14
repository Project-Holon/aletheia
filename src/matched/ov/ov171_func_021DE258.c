/*
 * function: DENDOU_VIEW_ReleaseResources
 * address: 0x021DE258
 * packet: pkt_ov171_021DE258
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   DENDOU_VIEW_ReleaseCharacter 0x021DE1F8 thumb ov171
 *   DENDOU_VIEW_ReleasePalette 0x021DE218 thumb ov171
 *   DENDOU_VIEW_ReleaseCellAnim 0x021DE238 thumb ov171
 */
extern void DENDOU_VIEW_ReleaseCharacter(char *, int);
extern void DENDOU_VIEW_ReleasePalette(char *, int);
extern void DENDOU_VIEW_ReleaseCellAnim(char *, int);
void DENDOU_VIEW_ReleaseResources(char *p)
{
    unsigned i;
    for(i=0;i<13;i++)DENDOU_VIEW_ReleaseCharacter(p,i);
    for(i=0;i<13;i++)DENDOU_VIEW_ReleasePalette(p,i);
    for(i=0;i<13;i++)DENDOU_VIEW_ReleaseCellAnim(p,i);
}
