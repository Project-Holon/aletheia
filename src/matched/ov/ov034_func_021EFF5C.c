/*
 * function: REPORT_ShowPartyIcons
 * address:  0x021EFF5C
 * packet:   pkt_ov034_021EFF5C
 * region:   ov034
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   REPORT_ShowPartyIcons 0x021EFF5C thumb
 *   PRINTSYS_QUE_IsFinished 0x0201C6B4 thumb
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_DATA_GetMyParty 0x02012934 thumb
 *   POKEPARTY_GetCount 0x0201AA18 thumb
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 */

typedef unsigned int   u32;
struct Ctx;
struct PrintSys;
extern u32 PRINTSYS_QUE_IsFinished(const struct PrintSys *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
struct BigObj;
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern unsigned int POKEPARTY_GetCount(void *);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *, unsigned int);

void REPORT_ShowPartyIcons(int *p)
{
    unsigned int i;
    void *n;

    if (!(p[0x4A] & 1) && PRINTSYS_QUE_IsFinished((const struct PrintSys *)p[2]) == 1) {
        n = GAME_DATA_GetMyParty(GAMESYSTEM_GetGameData((const struct Ctx *)p[0]));
        for (i = 0; i < POKEPARTY_GetCount(n); i++)
            CLACT_SetActorDrawEnable((struct Obj *)p[0x15 + i], 1);
        p[0x4A] |= 1;
    }
}
