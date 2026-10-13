/*
 * function: TOWNMAP_GRH_ExitSprites
 * address:  0x021BBAB4
 * packet:   pkt_ov072_021BBAB4
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm
 *   CLACT_ReleasePalette  0x0204ADA4  arm
 *   CLACT_DeleteUnit  0x0204B1CC  arm
 *   CLACT_ExitSystem  0x0204A5AC  arm
 *   func_02082BCC  0x02082BCC  arm
 */
typedef unsigned int u32;

struct Bank;
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
extern void CLACT_ReleaseCellAnim(u32 a);
extern void CLACT_ReleaseCharacter(u32 a);
extern void CLACT_ReleasePalette(u32 a);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
extern void func_02082BCC(void *p, int v, int n);

void TOWNMAP_GRH_ExitSprites(u32 *p)
{
    int i;

    for (i = 0; i < 4; i++) {
        if (p[i + 1] != 0) {
            CLACT_DeleteActor((struct Obj *)p[i + 1]);
        }
    }
    CLACT_ReleaseCellAnim(p[7]);
    CLACT_ReleaseCharacter(p[6]);
    CLACT_ReleasePalette(p[8]);
    if (p[0] != 0) {
        CLACT_DeleteUnit((struct Bank *)p[0]);
    }
    CLACT_ExitSystem();
    func_02082BCC(p, 0, 0x24);
}
