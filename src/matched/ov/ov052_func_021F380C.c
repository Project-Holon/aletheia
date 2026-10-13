/*
 * function: FIELD_GIMMICK_BSUBWAY_GetTrainEffect
 * address: 0x021F380C
 * packet: pkt_ov052_021F380C
 * region: ov052
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FIELDMAP_GetGameSystem 0x02188C80 thumb ov021
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_DATA_GetFieldSave 0x02012EC4 thumb
 *   FIELDMAP_GetZoneId 0x02188C9C thumb ov021
 *   GIMMICK_WORK_GetSaveArea 0x0200B3A4 thumb
 *   FIELDMAP_GetHeapId 0x02188C84 thumb ov021
 *   FIELD_GIMMICK_BSUBWAY_FindZoneEntry 0x021F3998 thumb ov052
 */

typedef unsigned short u16;
typedef unsigned char  u8;
struct Big;
struct Ctx;
extern void *FIELDMAP_GetGameSystem(void *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetFieldSave(struct Big *p);
extern u16 FIELDMAP_GetZoneId(u8 *p);
extern char *GIMMICK_WORK_GetSaveArea(unsigned, int);
extern u16 FIELDMAP_GetHeapId(u8 *p);
extern void FIELD_GIMMICK_BSUBWAY_FindZoneEntry(int, int *, int *);

int FIELD_GIMMICK_BSUBWAY_GetTrainEffect(int a)
{
    int y, x;
    unsigned h;
    FIELDMAP_GetHeapId((u8 *)a);
    h = (unsigned int)GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem((void *)a)));
    FIELD_GIMMICK_BSUBWAY_FindZoneEntry(FIELDMAP_GetZoneId((u8 *)a), &x, &y);
    return **(int **)(GIMMICK_WORK_GetSaveArea(h, x) + 0x24);
}
