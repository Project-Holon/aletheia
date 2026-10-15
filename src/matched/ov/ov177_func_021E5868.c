/*
 * function: func_021E5868
 * address: 0x021E5868
 * packet: pkt_ov177_021E5868
 * region: ov177
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 *
 * symbols:
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm  arm9
 *   CLACT_ReleasePalette  0x0204ADA4  arm  arm9
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm  arm9
 *   BG_SYS_SetTileUnit  0x02040DA8  arm  arm9
 */
typedef unsigned int   u32;
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
extern void BG_SYS_SetTileUnit(u32 idx, u32 count, u32 tile);
extern u32 func_020307B0(void *p);
typedef struct { int a, b, c, d, e, f; } S5868;
void func_021E5868(S5868 *p)
{
    CLACT_ReleasePalette(p->a);
    CLACT_ReleaseCharacter(p->c);
    CLACT_ReleaseCellAnim(p->e);
    CLACT_ReleasePalette(p->b);
    CLACT_ReleaseCharacter(p->d);
    CLACT_ReleaseCellAnim(p->f);
    BG_SYS_SetTileUnit(0, 1, 0);
    func_020307B0(p);
}
