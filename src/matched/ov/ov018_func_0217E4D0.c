/*
 * function: INTRUDE_SUBDISP_UpdateButtonActors
 * address:  0x0217E4D0
 * packet:   pkt_ov018_0217E4D0
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetIntrudeCount  0x02012B70  thumb
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   BMP_OAM_SetEnabled  0x02025774  thumb
 */

typedef unsigned char u8;

typedef unsigned int   u32;
struct BigObj;
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern int GAME_DATA_GetIntrudeCount(const struct BigObj *p);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *, unsigned int);
extern void BMP_OAM_SetEnabled(u8 *g, u32 a);

void INTRUDE_SUBDISP_UpdateButtonActors(int *p, int a1)
{
    int h;

    h = (int)GAMESYSTEM_GetGameData((const struct Ctx *)p[0]);
    if (*((u8 *)p + 0xe9) == 0 && GAME_DATA_GetIntrudeCount((const struct BigObj *)h) == 1) {
        switch (p[0xdc / 4]) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
            CLACT_SetActorDrawEnable((struct Obj *)p[0x9c / 4], 0);
            BMP_OAM_SetEnabled((u8 *)p[0xc0 / 4], 0);
            break;
        }
    }
}
