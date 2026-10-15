/*
 * function: ZKNSEARCH_MAIN_ReleaseActorRes
 * address: 0x021BF080
 * packet: pkt_ov210_021BF080
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * tail: 021BF0DA..021BF0DC is zero alignment padding.
 * symbols:
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 */
typedef unsigned char u8;
extern void CLACT_ReleaseCharacter(unsigned);
extern void CLACT_ReleasePalette(unsigned);
extern void CLACT_ReleaseCellAnim(unsigned);
void ZKNSEARCH_MAIN_ReleaseActorRes(u8 *p)
{
    unsigned i;
    for (i = 0; i < 6; i++) {
        unsigned v = *(unsigned *)(p + i * 4 + 0x10c);
        if (v != -1) CLACT_ReleaseCharacter(v);
    }
    for (i = 0; i < 6; i++) {
        unsigned v = *(unsigned *)(p + i * 4 + 0x124);
        if (v != -1) CLACT_ReleasePalette(v);
    }
    for (i = 0; i < 4; i++) {
        unsigned v = *(unsigned *)(p + i * 4 + 0x13c);
        if (v != -1) CLACT_ReleaseCellAnim(v);
    }
}
