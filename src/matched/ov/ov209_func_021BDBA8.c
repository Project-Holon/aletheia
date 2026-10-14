/*
 * function: ZUKAN_LIST_ReleaseActorResources
 * address: 0x021BDBA8
 * packet: pkt_ov209_021BDBA8
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 */
extern void CLACT_ReleaseCharacter(unsigned);
extern void CLACT_ReleasePalette(unsigned);
extern void CLACT_ReleaseCellAnim(unsigned);
void ZUKAN_LIST_ReleaseActorResources(char *p)
{
    unsigned i;
    for(i=0;i<36;i++)if(*(unsigned *)(p+i*4+0xb64)!=-1)CLACT_ReleaseCharacter(*(unsigned *)(p+i*4+0xb64));
    for(i=0;i<6;i++)if(*(unsigned *)(p+i*4+0xbf4)!=-1)CLACT_ReleasePalette(*(unsigned *)(p+i*4+0xbf4));
    for(i=0;i<6;i++)if(*(unsigned *)(p+i*4+0xc0c)!=-1)CLACT_ReleaseCellAnim(*(unsigned *)(p+i*4+0xc0c));
}
