/*
 * function: BOX2_SEQ_ReleaseBoxGraphics
 * address: 0x021EBE4C
 * packet: pkt_ov170_021EBE4C
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 */
typedef unsigned int   u32;
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
void BOX2_SEQ_ReleaseBoxGraphics(char *p)
{
    unsigned i;
    for (i = 0; i < 0x45; i++)
        if (*(int *)(p + i * 4 + 0x9FF4) != -1)
            CLACT_ReleaseCharacter(*(int *)(p + i * 4 + 0x9FF4));
    for (i = 0; i < 0xB; i++)
        if (*(int *)(p + i * 4 + 0xA108) != -1)
            CLACT_ReleasePalette(*(int *)(p + i * 4 + 0xA108));
    for (i = 0; i < 0xC; i++)
        if (*(int *)(p + i * 4 + 0xA134) != -1)
            CLACT_ReleaseCellAnim(*(int *)(p + i * 4 + 0xA134));
}
