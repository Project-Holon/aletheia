/*
 * function: STARTMENU_SpritesDelete
 * address:  0x021B9F70
 * packet:   pkt_ov088_021B9F70
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * note:     listing extent (36) runs 2 bytes past the compiled function (34);
 *           trailing alignment padding, no byte difference.
 *
 * symbols:
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm
 *   CLACT_ReleasePalette  0x0204ADA4  arm
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm
 *   CLACT_DeleteUnit  0x0204B1CC  arm
 *   CLACT_ExitSystem  0x0204A5AC  arm
 */

typedef unsigned int   u32;
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
struct Bank;
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);

void STARTMENU_SpritesDelete(int *p)
{
    CLACT_ReleaseCharacter(p[12]);
    CLACT_ReleasePalette(p[11]);
    CLACT_ReleaseCellAnim(p[13]);
    CLACT_DeleteUnit((struct Bank *)p[0]);
    CLACT_ExitSystem();
}
