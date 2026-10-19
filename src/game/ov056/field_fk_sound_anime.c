/*
 * file:     field_fk_sound_anime.c
 * unit:     yes
 * function: FIELD_FK_SOUND_ANIME_InitFrameSound, FIELD_FK_SOUND_ANIME_UpdateFrameSound, FIELD_FK_SOUND_ANIME_InitAmbientSoundA, FIELD_FK_SOUND_ANIME_ExitAmbientSoundA, FIELD_FK_SOUND_ANIME_UpdateAmbientSoundA, FIELD_FK_SOUND_ANIME_InitAmbientSoundB, FIELD_FK_SOUND_ANIME_ExitAmbientSoundB, FIELD_FK_SOUND_ANIME_UpdateAmbientSoundB, FIELD_FK_SOUND_ANIME_Create, FIELD_FK_SOUND_ANIME_Delete, FIELD_FK_SOUND_ANIME_Step, FIELD_FK_SOUND_ANIME_PlaySe, FIELD_FK_SOUND_ANIME_StopSe
 * address:  0x021F3E94
 * region:   ov056
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   FIELDMAP_GetG3dMapper  0x02188C98  thumb  ov021
 *   FIELD_G3D_MAPPER_GetBuildModel  0x0218DC6C  thumb  ov021
 *   FIELD_BUILDMODEL_GetFirstEntryNearPos  0x0218C654  thumb  ov021
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetBgmInfo  0x02012A30  thumb
 *   gFkFrameSoundModelPos     0x021F4284  data  a4
 *   FIELD_BUILDMODEL_GetEntrySlotFrame  0x0218C6F4  thumb  ov021
 *   FIELD_SOUND_SYSTEM_ClaimSlot  0x02028A7C  thumb
 *   gFkFrameSoundFrame  0x021F425C  data  ov056  a4
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   ZONEDATA_GetEventWorkAddress  0x020143CC  thumb
 *   FIELD_SOUND_SYSTEM_ReleaseSlot  0x02028B50  thumb
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   ICA_ANIME_CreateStream  0x02011510  thumb
 *   MI_CpuCopy8  0x02082D44  arm
 *   gFkSoundAnimeSourceFile  0x021F4400  data  ov056  a1
 *   ICA_ANIME_Delete  0x02011558  thumb
 *   GFL_HEAP_Free   0x020307B0  arm
 *   ICA_ANIME_GetFrameNum  0x02011608  thumb
 *   ICA_ANIME_SetFrame  0x020115EC  thumb
 *   ICA_ANIME_GetTranslate  0x02011610  thumb
 *   ICA_ANIME_GetScale  0x02011660  thumb
 *   ICA_ANIME_GetRotate  0x02011638  thumb
 *   FIELD_FK_SOUND_ANIME_StopSe  0x021F423C  thumb  ov056
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   GFL_USE_GetSeSlot  0x02006148  thumb
 *   GFL_USE_StopSeSlot  0x020061F8  thumb
 */
#include "field_fk_demo_types.h"

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MI_CpuCopy8(const void *src, void *dst, int size);
extern u32 GFL_HEAP_Free(void *memory);
extern struct IcaAnime *ICA_ANIME_CreateStream(u16 heapId, u32 arcId, u32 dataId, u32 bufFrameNum);
extern u32 ICA_ANIME_GetTranslate(struct IcaAnime *anime, VecFx32 *translate);
extern u32 ICA_ANIME_GetScale(struct IcaAnime *anime, VecFx32 *scale);
extern u32 ICA_ANIME_GetRotate(struct IcaAnime *anime, VecFx32 *rotate);
extern void GFL_USE_PlaySeDefaultVolume(u32 seId);

void FIELD_FK_SOUND_ANIME_InitFrameSound(struct FieldSubproc *proc, struct FieldMap *fieldMap, FkFrameSoundWork *work);
void FIELD_FK_SOUND_ANIME_ExitFrameSound(struct FieldSubproc *proc, struct FieldMap *fieldMap, FkFrameSoundWork *work);
void FIELD_FK_SOUND_ANIME_UpdateFrameSound(struct FieldSubproc *proc, struct FieldMap *fieldMap, FkFrameSoundWork *work);
void FIELD_FK_SOUND_ANIME_InitAmbientSoundA(struct FieldSubproc *proc, struct FieldMap *fieldMap, FkAmbientSoundWork *work);
void FIELD_FK_SOUND_ANIME_ExitAmbientSoundA(struct FieldSubproc *proc, struct FieldMap *fieldMap, FkAmbientSoundWork *work);
void FIELD_FK_SOUND_ANIME_UpdateAmbientSoundA(struct FieldSubproc *proc, struct FieldMap *fieldMap, FkAmbientSoundWork *work);
void FIELD_FK_SOUND_ANIME_InitAmbientSoundB(struct FieldSubproc *proc, struct FieldMap *fieldMap, FkAmbientSoundWork *work);
void FIELD_FK_SOUND_ANIME_ExitAmbientSoundB(struct FieldSubproc *proc, struct FieldMap *fieldMap, FkAmbientSoundWork *work);
void FIELD_FK_SOUND_ANIME_UpdateAmbientSoundB(struct FieldSubproc *proc, struct FieldMap *fieldMap, FkAmbientSoundWork *work);
#include "../types.h"
extern int GFL_USE_GetSeSlot(u32 seId);
extern void GFL_USE_StopSeSlot(int seSlot);

/*
 * Init of the proc that plays a sound at listed frames of a building
 * animation (template gFkFrameSoundTemplate). Remembers the building model and the
 * sound system.
 *
 * note:     first entry of the callback triple at 0x021F4364
 *           {0x021F3E95, 0x021F3EC9, 0x021F3ECD}; r0 is unused. The second
 *           entry, FIELD_FK_SOUND_ANIME_ExitFrameSound, is an unlabelled empty callback (bx lr)
 *           right after the lead's pool, then 2 bytes of padding.
 */
void FIELD_FK_SOUND_ANIME_InitFrameSound(struct FieldSubproc *proc, struct FieldMap *fieldMap, FkFrameSoundWork *work)
{
    struct BuildModelMan *man;

    man = FIELD_G3D_MAPPER_GetBuildModel(FIELDMAP_GetG3dMapper(fieldMap));
    work->entry = FIELD_BUILDMODEL_GetFirstEntryNearPos(man, 0, &gFkFrameSoundModelPos);
    work->man = man;
    work->soundSys = GAME_DATA_GetBgmInfo(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap)));
}

/* Exit of that proc: nothing to undo. */
void FIELD_FK_SOUND_ANIME_ExitFrameSound(struct FieldSubproc *proc, struct FieldMap *fieldMap, FkFrameSoundWork *work)
{
}

/*
 * Update of that proc: when the building animation is at one of the listed
 * frames it plays the hit sound and starts a countdown; when the countdown
 * ends it plays the closing sound.
 */
void FIELD_FK_SOUND_ANIME_UpdateFrameSound(struct FieldSubproc *proc, struct FieldMap *fieldMap, FkFrameSoundWork *work)
{
    int i;
    int frame;

    i = 0;
    frame = FIELD_BUILDMODEL_GetEntrySlotFrame(work->man, work->entry, 0);
    for (; i < 2; i++) {
        if (frame == gFkFrameSoundFrame[i]) {
            FIELD_SOUND_SYSTEM_ClaimSlot(work->soundSys, FK_SE_FRAME_HIT);
            work->hitActive = 1;
            work->hitCountdown = 0x1f;
            break;
        }
    }
    if (work->hitActive != 0) {
        work->hitCountdown = work->hitCountdown - 1;
        if (work->hitCountdown <= 0) {
            FIELD_SOUND_SYSTEM_ClaimSlot(work->soundSys, FK_SE_FRAME_HIT_END);
            work->hitActive = 0;
            work->hitCountdown = 0;
        }
    }
}

/*
 * Init of the proc that plays an ambient sound (template gFkAmbientSoundATemplate) until the
 * script work variable FK_AMBIENT_STOP_WORK_ID is not 0.
 */
void FIELD_FK_SOUND_ANIME_InitAmbientSoundA(struct FieldSubproc *proc, struct FieldMap *fieldMap, FkAmbientSoundWork *work)
{
    struct GameData *gameData;

    gameData = GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap));
    work->eventWork = GAME_DATA_GetEventWork(gameData);
    work->soundSys = GAME_DATA_GetBgmInfo(gameData);
    work->stopVar = ZONEDATA_GetEventWorkAddress(work->eventWork, FK_AMBIENT_STOP_WORK_ID);
    if (*work->stopVar == 0) {
        FIELD_SOUND_SYSTEM_ClaimSlot(work->soundSys, FK_SE_AMBIENT_A);
        work->stopped = 0;
        return;
    }
    work->stopped = 1;
}

/* Exit of that proc: stops the sound if it still plays. */
void FIELD_FK_SOUND_ANIME_ExitAmbientSoundA(struct FieldSubproc *proc, struct FieldMap *fieldMap, FkAmbientSoundWork *work)
{
    if (work->stopped == 0) {
        FIELD_SOUND_SYSTEM_ReleaseSlot(work->soundSys, FK_SE_AMBIENT_A);
    }
}

/* Update of that proc: stops the sound when the script variable is set. */
void FIELD_FK_SOUND_ANIME_UpdateAmbientSoundA(struct FieldSubproc *proc, struct FieldMap *fieldMap, FkAmbientSoundWork *work)
{
    if (*work->stopVar != 0 && work->stopped == 0) {
        FIELD_SOUND_SYSTEM_ReleaseSlot(work->soundSys, FK_SE_AMBIENT_A);
        work->stopped = 1;
    }
}

/* Same as FIELD_FK_SOUND_ANIME_InitAmbientSoundA for the second ambient sound (template gFkAmbientSoundBTemplate). */
void FIELD_FK_SOUND_ANIME_InitAmbientSoundB(struct FieldSubproc *proc, struct FieldMap *fieldMap, FkAmbientSoundWork *work)
{
    struct GameData *gameData;

    gameData = GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap));
    work->eventWork = GAME_DATA_GetEventWork(gameData);
    work->soundSys = GAME_DATA_GetBgmInfo(gameData);
    work->stopVar = ZONEDATA_GetEventWorkAddress(work->eventWork, FK_AMBIENT_STOP_WORK_ID);
    if (*work->stopVar == 0) {
        FIELD_SOUND_SYSTEM_ClaimSlot(work->soundSys, FK_SE_AMBIENT_B);
        work->stopped = 0;
        return;
    }
    work->stopped = 1;
}

void FIELD_FK_SOUND_ANIME_ExitAmbientSoundB(struct FieldSubproc *proc, struct FieldMap *fieldMap, FkAmbientSoundWork *work)
{
    if (work->stopped == 0) {
        FIELD_SOUND_SYSTEM_ReleaseSlot(work->soundSys, FK_SE_AMBIENT_B);
    }
}

void FIELD_FK_SOUND_ANIME_UpdateAmbientSoundB(struct FieldSubproc *proc, struct FieldMap *fieldMap, FkAmbientSoundWork *work)
{
    if (*work->stopVar != 0 && work->stopped == 0) {
        FIELD_SOUND_SYSTEM_ReleaseSlot(work->soundSys, FK_SE_AMBIENT_B);
        work->stopped = 1;
    }
}

/*
 * Allocates a 0x1C-byte record from the heap, starts the ICA animation of
 * the file (arcId, dataId) and copies the 0x12 bytes of sound ids into it at +8.
 * The u16 heap is re-read with ldrh from its stack slot before each call,
 * so both callees take it as u16 (see
 * a-u16-stack-parameter-reloaded-per-call-means-u16-callee-parameters.md);
 * with u32 callee parameters the heap stayed in r5 and the other arguments spilled.
 */
FkSoundAnime *FIELD_FK_SOUND_ANIME_Create(const void *soundIds, u32 arcId, u32 dataId, u32 bufFrameNum, u16 heapId)
{
    FkSoundAnime *sound;

    sound = GFL_HEAP_Alloc(heapId, sizeof(FkSoundAnime), 1, gFkSoundAnimeSourceFile, 0x4d);
    sound->frame = 0;
    sound->anime = ICA_ANIME_CreateStream(heapId, arcId, dataId, bufFrameNum);
    MI_CpuCopy8(soundIds, sound->soundId, 0x12);
    return sound;
}

/*
 * Deletes the sound anime.
 *
 * extent:   EXACT* covers only the 2-byte alignment pad at 0x021F409E;
 *           the follower 0x021F40A0 is separately matched (pkt_021F40A0).
 */
void FIELD_FK_SOUND_ANIME_Delete(FkSoundAnime *sound)
{
    ICA_ANIME_Delete(sound->anime);
    GFL_HEAP_Free(sound);
}

/*
 * Steps the sound anime by one frame and acts on its nine channels (three
 * translation, three scale, three rotation values): a channel at
 * FK_SOUND_CHANNEL_PLAY starts the sound of that channel, one at
 * FK_SOUND_CHANNEL_STOP stops it. Returns 1 on the last frame.
 *
 * Unblocked (2026-09-26 recursive MATCH unblocker, arm9 0x0200..0x0202):
 *   both wildcarded relocations are now `matched`.
 *   - ICA_ANIME_GetFrameNum: EXACT, src/matched/ICA_ANIME_GetFrameNum.c (pkt_02011608).
 *   - ICA_ANIME_GetScale: already an EXACT member of the game_unit
 *     src/matched/unit_02011610.c (pkt_020113F0); that unit's `function:`
 *     header now lists all three copies, so the manifest covers 0x02011660.
 *   All 23 relocations resolve; EXACT* because the extent runs to the next
 *   unlabelled follower.
 */
int FIELD_FK_SOUND_ANIME_Step(FkSoundAnime *sound)
{
    int done;
    VecFx32 translate, scale, rotate;
    int length = ICA_ANIME_GetFrameNum(sound->anime) << 12;

    if (length <= sound->frame) {
        done = 1;
        sound->frame = length - 0x1000;
    } else {
        done = 0;
    }
    ICA_ANIME_SetFrame(sound->anime, sound->frame);
    ICA_ANIME_GetTranslate(sound->anime, &translate);
    ICA_ANIME_GetScale(sound->anime, &scale);
    ICA_ANIME_GetRotate(sound->anime, &rotate);
    if (translate.x == FK_SOUND_CHANNEL_PLAY) FIELD_FK_SOUND_ANIME_PlaySe(sound, 0); else if (translate.x == FK_SOUND_CHANNEL_STOP) FIELD_FK_SOUND_ANIME_StopSe(sound, 0);
    if (translate.y == FK_SOUND_CHANNEL_PLAY) FIELD_FK_SOUND_ANIME_PlaySe(sound, 1); else if (translate.y == FK_SOUND_CHANNEL_STOP) FIELD_FK_SOUND_ANIME_StopSe(sound, 1);
    if (translate.z == FK_SOUND_CHANNEL_PLAY) FIELD_FK_SOUND_ANIME_PlaySe(sound, 2); else if (translate.z == FK_SOUND_CHANNEL_STOP) FIELD_FK_SOUND_ANIME_StopSe(sound, 2);
    if (scale.x == FK_SOUND_CHANNEL_PLAY) FIELD_FK_SOUND_ANIME_PlaySe(sound, 3); else if (scale.x == FK_SOUND_CHANNEL_STOP) FIELD_FK_SOUND_ANIME_StopSe(sound, 3);
    if (scale.y == FK_SOUND_CHANNEL_PLAY) FIELD_FK_SOUND_ANIME_PlaySe(sound, 4); else if (scale.y == FK_SOUND_CHANNEL_STOP) FIELD_FK_SOUND_ANIME_StopSe(sound, 4);
    if (scale.z == FK_SOUND_CHANNEL_PLAY) FIELD_FK_SOUND_ANIME_PlaySe(sound, 5); else if (scale.z == FK_SOUND_CHANNEL_STOP) FIELD_FK_SOUND_ANIME_StopSe(sound, 5);
    if (rotate.x == FK_SOUND_CHANNEL_PLAY) FIELD_FK_SOUND_ANIME_PlaySe(sound, 6); else if (rotate.x == FK_SOUND_CHANNEL_STOP) FIELD_FK_SOUND_ANIME_StopSe(sound, 6);
    if (rotate.y == FK_SOUND_CHANNEL_PLAY) FIELD_FK_SOUND_ANIME_PlaySe(sound, 7); else if (rotate.y == FK_SOUND_CHANNEL_STOP) FIELD_FK_SOUND_ANIME_StopSe(sound, 7);
    if (rotate.z == FK_SOUND_CHANNEL_PLAY) FIELD_FK_SOUND_ANIME_PlaySe(sound, 8); else if (rotate.z == FK_SOUND_CHANNEL_STOP) FIELD_FK_SOUND_ANIME_StopSe(sound, 8);
    sound->frame += 0x1000;
    return done;
}

/* Plays the sound effect of a channel, if it has one. */
void FIELD_FK_SOUND_ANIME_PlaySe(FkSoundAnime *sound, u32 channel)
{
    u16 seId = sound->soundId[channel];

    if (seId != FK_SOUND_NONE) {
        GFL_USE_PlaySeDefaultVolume(seId);
    }
}

/* Stops the sound effect of a channel, if it has one (the stop twin of FIELD_FK_SOUND_ANIME_PlaySe). */
void FIELD_FK_SOUND_ANIME_StopSe(FkSoundAnime *sound, u32 channel)
{
    u16 seId = sound->soundId[channel];

    if (seId != 0xffff) {
        GFL_USE_StopSeSlot(GFL_USE_GetSeSlot(seId));
    }
}
