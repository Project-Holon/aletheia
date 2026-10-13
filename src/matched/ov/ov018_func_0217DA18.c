/*
 * function: INTRUDE_SUBDISP_ClactResourceUnload
 * address: 0x0217DA18
 * packet: pkt_ov018_0217DA18
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 */
typedef unsigned int u32;
extern u32 func_020307B0(void *p);
extern void CLACT_ReleasePalette(u32);
extern void CLACT_ReleaseCharacter(u32);
extern void CLACT_ReleaseCellAnim(u32);
void INTRUDE_SUBDISP_ClactResourceUnload(u32 *p)
{
    func_020307B0((void *)p[0xd0 / 4]);
    func_020307B0((void *)p[0xc8 / 4]);
    CLACT_ReleasePalette(p[3]);
    CLACT_ReleasePalette(p[2]);
    CLACT_ReleaseCharacter(p[1]);
    CLACT_ReleaseCharacter(p[5]);
    CLACT_ReleaseCellAnim(p[4]);
    CLACT_ReleaseCellAnim(p[6]);
}
