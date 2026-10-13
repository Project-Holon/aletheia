/*
 * function: FIELD_FK_BUILD_SOUND_Init
 * address:  0x021F3DCC
 * packet:   pkt_ov056_021F3DCC
 * region:   ov056
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetG3dMapper  0x02188C98  thumb  ov021
 *   FIELD_G3D_MAPPER_GetBuildModel  0x0218DC6C  thumb  ov021
 *   FIELD_BUILDMODEL_GetFirstEntryNearPos  0x0218C654  thumb  ov021
 *   FIELD_BUILDMODEL_GetEntrySlotFrame  0x0218C6F4  thumb  ov021
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetBgmInfo  0x02012A30  thumb
 *   FIELD_SOUND_SYSTEM_ClaimSlot  0x02028A7C  thumb
 *   gFkBuildSoundModelPos  0x021F4278  data  ov056  a4
 *   gFkBuildSoundTriggerFrame  0x021F4258  data  ov056  a4
 */

typedef unsigned int u32;

typedef struct { u32 a, b, c; } Ent;

typedef unsigned char  u8;
struct Ctx;
struct SoundSys2;
extern u32 FIELDMAP_GetG3dMapper(u8 *p);
extern u32 FIELD_G3D_MAPPER_GetBuildModel(u8 *p);
extern int FIELD_BUILDMODEL_GetFirstEntryNearPos(int a, int b, int c);
extern int FIELD_BUILDMODEL_GetEntrySlotFrame(unsigned char *p, int b, int id);
extern void *FIELDMAP_GetGameSystem(void *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
struct BigObj;
extern u32 GAME_DATA_GetBgmInfo(const struct BigObj *p);
extern void FIELD_SOUND_SYSTEM_ClaimSlot(struct SoundSys2 *s, u32 id);
extern Ent gFkBuildSoundModelPos;
extern int gFkBuildSoundTriggerFrame[];

void FIELD_FK_BUILD_SOUND_Init(int unused, int b, u32 *c)
{
    int r7;
    u32 i;
    int r;

    r7 = FIELD_G3D_MAPPER_GetBuildModel((u8 *)FIELDMAP_GetG3dMapper((u8 *)b));
    i = 0;
    c[1] = FIELD_BUILDMODEL_GetFirstEntryNearPos(r7, 0, (int)(&gFkBuildSoundModelPos));
    c[0] = r7;
    r = FIELD_BUILDMODEL_GetEntrySlotFrame((unsigned char *)r7, c[1], 1);
    c[2] = 0x6000;
    c[3] = i;
    for (; i < 1; i++) {
        if (r < gFkBuildSoundTriggerFrame[i]) {
            c[2] = gFkBuildSoundTriggerFrame[i];
            c[3] = i;
            break;
        }
    }
    FIELD_SOUND_SYSTEM_ClaimSlot((struct SoundSys2 *)GAME_DATA_GetBgmInfo((const struct BigObj *)GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem((void *)b))), 0x746);
}
