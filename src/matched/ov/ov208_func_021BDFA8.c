/*
 * function: ZUKAN_DETAIL_TOUCHBAR_ReleaseBarResources
 * address: 0x021BDFA8
 * packet: pkt_ov208_021BDFA8
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021BE1BC 0x021BE1BC thumb
 *   ZUKAN_DETAIL_TOUCHBAR_GetPaletteFlag 0x021BE16C thumb
 *   ZKND_TBAR_DeleteButtonList 0x021BD208 thumb
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 * tail: two zero alignment bytes after the function (listing extent is 2 bytes longer).
 */
struct Ov208Mgr;
struct Ov208Eff { char pad[0x30]; struct Ov208Mgr *mgr; char pad2[0x10]; void *f44; void *f48; void *f4c; };
extern void func_021BE1BC(struct Ov208Eff *e);
extern void ZUKAN_DETAIL_TOUCHBAR_GetPaletteFlag(struct Ov208Eff *e);
extern void ZKND_TBAR_DeleteButtonList(struct Ov208Mgr *m);
typedef unsigned int   u32;
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
void ZUKAN_DETAIL_TOUCHBAR_ReleaseBarResources(struct Ov208Eff *e)
{
    if (e->mgr != 0) {
        func_021BE1BC(e);
        ZUKAN_DETAIL_TOUCHBAR_GetPaletteFlag(e);
        ZKND_TBAR_DeleteButtonList(e->mgr);
        CLACT_ReleasePalette((u32)e->f44);
        CLACT_ReleaseCharacter((u32)e->f48);
        CLACT_ReleaseCellAnim((u32)e->f4c);
    }
    e->mgr = 0;
}
