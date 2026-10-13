/*
 * function: REPORT_ExitActors
 * address:  0x021F0930
 * packet:   pkt_ov034_021F0930
 * region:   ov034
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   REPORT_ExitActors 0x021F0930 thumb
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_DATA_GetMyParty 0x02012934 thumb
 *   func_0201AA18 0x0201AA18 thumb
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 */

struct Bank;
struct Ctx;
struct Obj;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
typedef unsigned int   u32;
struct BigObj;
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern unsigned int func_0201AA18(void *);
extern void CLACT_DeleteActor(struct Obj *p);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);

void REPORT_ExitActors(int *p)
{
    unsigned int i;
    void *n;

    n = GAME_DATA_GetMyParty(GAMESYSTEM_GetGameData((const struct Ctx *)p[0]));
    for (i = 0; i < func_0201AA18(n); i++) {
        CLACT_DeleteActor((struct Obj *)p[0x15 + i]);
        CLACT_ReleaseCharacter(p[0x25 + i]);
    }
    for (i = 6; i <= 15; i++)
        CLACT_DeleteActor((struct Obj *)p[0x15 + i]);
    CLACT_ReleaseCharacter(p[0x2B]);
    CLACT_ReleasePalette(p[0x34]);
    CLACT_ReleasePalette(p[0x35]);
    CLACT_ReleaseCellAnim(p[0x41]);
    CLACT_ReleaseCellAnim(p[0x42]);
    CLACT_DeleteUnit((struct Bank *)p[0x14]);
    BG_SYS_SetSubPlaneVisible(0x10, 0);
}
