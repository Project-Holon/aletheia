/*
 * function: func_021BE4DC
 * address: 0x021BE4DC
 * packet: pkt_ov208_021BE4DC
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021BD208 0x021BD208 thumb
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 * tail: two zero alignment bytes after the function (listing extent is 2 bytes longer).
 */
struct Ov208Mgr;
struct Ov208Eff { char pad[0x30]; struct Ov208Mgr *mgr; char pad2[0x1c]; void *f50; void *f54; void *f58; };
extern void func_021BD208(struct Ov208Mgr *m);
typedef unsigned int   u32;
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
void func_021BE4DC(struct Ov208Eff *e)
{
    if (e->mgr != 0) {
        func_021BD208(e->mgr);
        CLACT_ReleasePalette((u32)e->f50);
        CLACT_ReleaseCharacter((u32)e->f54);
        CLACT_ReleaseCellAnim((u32)e->f58);
    }
    e->mgr = 0;
}
