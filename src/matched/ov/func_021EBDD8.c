/*
 * function: BOX2_SEQ_DeleteBox2UiScene
 * address:  0x021EBDD8
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BOX2_UI_DeleteBmpOam  0x021EE200  thumb  ov170
 *   BOX2_SEQ_DeleteAllActors  0x021EBF50  thumb  ov170
 *   BOX2_SEQ_ReleaseBoxGraphics  0x021EBE4C  thumb  ov170
 *   CLACT_ExitSystem  0x0204A5AC  arm  arm9
 *
 * Three teardown steps then the SDK pool release.
 */


extern void BOX2_UI_DeleteBmpOam(char *);
extern void BOX2_SEQ_DeleteAllActors(char *);
extern void BOX2_SEQ_ReleaseBoxGraphics(char *);
extern void CLACT_ExitSystem(void);
void BOX2_SEQ_DeleteBox2UiScene(char *p)
{
    BOX2_UI_DeleteBmpOam(p);
    BOX2_SEQ_DeleteAllActors(p);
    BOX2_SEQ_ReleaseBoxGraphics(p);
    CLACT_ExitSystem();
}
