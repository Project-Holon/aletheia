/*
 * function: OPTION_MENU_ExitSprites
 * address:  0x021B9F70
 * packet:   pkt_ov068_021B9F70
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *   CLACT_ReleasePalette  0x0204ADA4  arm
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm
 *   CLACT_DeleteUnit  0x0204B1CC  arm
 *   CLACT_ExitSystem  0x0204A5AC  arm
 *   MI_CpuFill8  0x02082BCC  arm
 */

typedef unsigned int u32;

struct Bank;
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
extern void CLACT_ReleasePalette(u32 a);
extern void CLACT_ReleaseCharacter(u32 a);
extern void CLACT_ReleaseCellAnim(u32 a);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
extern void MI_CpuFill8(void *p, u32 a, u32 b);

void OPTION_MENU_ExitSprites(u32 *p)
{
    int i;

    for (i = 0; i < 14; i++) {
        if (p[i + 6] != 0) {
            CLACT_DeleteActor((struct Obj *)p[i + 6]);
        }
    }
    CLACT_ReleasePalette(p[1]);
    CLACT_ReleaseCharacter(p[2]);
    CLACT_ReleaseCellAnim(p[3]);
    CLACT_ReleaseCharacter(p[4]);
    CLACT_ReleaseCellAnim(p[5]);
    CLACT_DeleteUnit((struct Bank *)p[0]);
    CLACT_ExitSystem();
    MI_CpuFill8(p, 0, 0x54);
}
