/*
 * function: FIELD_FK_BUILD_SOUND_Update
 * address:  0x021F3E54
 * packet:   pkt_ov056_021F3E54
 * region:   ov056
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_BUILDMODEL_GetEntrySlotFrame  0x0218C6F4  thumb  ov021
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetBgmInfo  0x02012A30  thumb
 *   FIELD_SOUND_SYSTEM_ClaimSlot  0x02028A7C  thumb
 *   gFkBuildSoundTriggerFrame  0x021F4258  data  ov056  a4
 */

typedef unsigned int u32;

struct Ctx;
struct SoundSys2;
extern int FIELD_BUILDMODEL_GetEntrySlotFrame(unsigned char *p, int b, int id);
extern void *FIELDMAP_GetGameSystem(void *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
struct BigObj;
extern u32 GAME_DATA_GetBgmInfo(const struct BigObj *p);
extern void FIELD_SOUND_SYSTEM_ClaimSlot(struct SoundSys2 *s, u32 id);
extern int gFkBuildSoundTriggerFrame[];

void FIELD_FK_BUILD_SOUND_Update(int unused, int b, u32 *c)
{
    int r;

    if (c[2] == FIELD_BUILDMODEL_GetEntrySlotFrame((unsigned char *)c[0], c[1], 1)) {
        r = GAME_DATA_GetBgmInfo((const struct BigObj *)GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem((void *)b)));
        c[3] = 0;
        c[2] = gFkBuildSoundTriggerFrame[c[3]];
        FIELD_SOUND_SYSTEM_ClaimSlot((struct SoundSys2 *)r, 0x692);
    }
}
