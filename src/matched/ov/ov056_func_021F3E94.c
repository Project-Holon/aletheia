/*
 * unit:     yes
 * function: FIELD_FK_SOUND_ANIME_InitFrameSound, FIELD_FK_SOUND_ANIME_ExitFrameSound
 * address:  0x021F3E94
 * packet:   pkt_ov056_021F3E94
 * region:   ov056
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     first entry of the callback triple at 0x021F4364
 *           {0x021F3E95, 0x021F3EC9, 0x021F3ECD}; r0 is unused. The second
 *           entry, FIELD_FK_SOUND_ANIME_ExitFrameSound, is an unlabelled empty callback (bx lr)
 *           right after the lead's pool, then 2 bytes of padding.
 * symbols:
 *   FIELDMAP_GetG3dMapper  0x02188C98  thumb  ov021
 *   FIELD_G3D_MAPPER_GetBuildModel  0x0218DC6C  thumb  ov021
 *   FIELD_BUILDMODEL_GetFirstEntryNearPos  0x0218C654  thumb  ov021
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetBgmInfo  0x02012A30  thumb
 *   gFkFrameSoundModelPos     0x021F4284  data  a4
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

struct Ctx;
struct BigObj;
extern u32 FIELDMAP_GetG3dMapper(u8 *p);
extern u32 FIELD_G3D_MAPPER_GetBuildModel(u8 *p);
extern int FIELD_BUILDMODEL_GetFirstEntryNearPos(int a, int b, int c);
extern void *FIELDMAP_GetGameSystem(void *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u32 GAME_DATA_GetBgmInfo(const struct BigObj *p);
extern u8 gFkFrameSoundModelPos[];

void FIELD_FK_SOUND_ANIME_InitFrameSound(void *unused, u8 *b, u8 *c)
{
    u32 r;

    r = FIELD_G3D_MAPPER_GetBuildModel((u8 *)FIELDMAP_GetG3dMapper(b));
    *(int *)(c + 0x4) = FIELD_BUILDMODEL_GetFirstEntryNearPos((int)r, 0, (int)gFkFrameSoundModelPos);
    *(u32 *)(c + 0x0) = r;
    *(u32 *)(c + 0xC) = GAME_DATA_GetBgmInfo((const struct BigObj *)GAMESYSTEM_GetGameData((const struct Ctx *)FIELDMAP_GetGameSystem(b)));
}

void FIELD_FK_SOUND_ANIME_ExitFrameSound(void *unused, u8 *b, u8 *c)
{
}
