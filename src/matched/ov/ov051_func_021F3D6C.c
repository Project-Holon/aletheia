/*
 * function: FIELD_GIMMICK_D06_GetWork
 * address: 0x021F3D6C
 * packet: pkt_ov051_021F3D6C
 * region: ov051
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
 *   FIELD_GIMMICK_D06_GetGimmickId 0x021F3D94 thumb ov051
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
extern int FIELD_GIMMICK_D06_GetGimmickId(int);

void *FIELD_GIMMICK_D06_GetWork(int a)
{
    unsigned h = (unsigned int)GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem((void *)a)));
    return *(void **)(GIMMICK_WORK_GetSaveArea(h, FIELD_GIMMICK_D06_GetGimmickId(FIELDMAP_GetZoneId((u8 *)a))) + 4);
}
