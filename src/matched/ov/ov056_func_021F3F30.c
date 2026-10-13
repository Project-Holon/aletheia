/*
 * function: FIELD_FK_SOUND_ANIME_InitAmbientSoundA
 * address:  0x021F3F30
 * packet:   pkt_ov056_021F3F30
 * region:   ov056
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   GAME_DATA_GetBgmInfo  0x02012A30  thumb
 *   ZONEDATA_GetEventWorkAddress  0x020143CC  thumb
 *   FIELD_SOUND_SYSTEM_ClaimSlot  0x02028A7C  thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u16 *f0;
    u16 f4;
    u32 f8;
    int fc;
} S3F30;

struct BigObj;
struct Ctx;
struct SoundSys2;
extern void *FIELDMAP_GetGameSystem(void *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u32 GAME_DATA_GetEventWork(const struct BigObj *p);
struct BigObj;
extern u32 GAME_DATA_GetBgmInfo(const struct BigObj *p);
extern u32 ZONEDATA_GetEventWorkAddress(u32 a, u32 b);
extern void FIELD_SOUND_SYSTEM_ClaimSlot(struct SoundSys2 *s, u32 id);

void FIELD_FK_SOUND_ANIME_InitAmbientSoundA(int a, int b, S3F30 *c)
{
    int r5;

    r5 = (int)GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem((void *)b));
    c->f8 = GAME_DATA_GetEventWork((const struct BigObj *)r5);
    c->fc = GAME_DATA_GetBgmInfo((const struct BigObj *)r5);
    c->f0 = (u16 *)ZONEDATA_GetEventWorkAddress(c->f8, 0x4001);
    if (*c->f0 == 0) {
        FIELD_SOUND_SYSTEM_ClaimSlot((struct SoundSys2 *)c->fc, 0x756);
        c->f4 = 0;
        return;
    }
    c->f4 = 1;
}
