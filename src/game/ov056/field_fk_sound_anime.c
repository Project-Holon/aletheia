/*
 * file:     field_fk_sound_anime.c
 * unit:     yes
 * function: func_021F3E94, func_021F3ECC, func_021F3F30, func_021F3F7C, func_021F3F94, func_021F3FB8, func_021F4004, func_021F401C, func_021F4040, func_021F408C, func_021F40A0, func_021F4224
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
 *   func_02188C98  0x02188C98  thumb  ov021
 *   func_0218DC6C  0x0218DC6C  thumb  ov021
 *   func_0218C654  0x0218C654  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012A30  0x02012A30  thumb
 *   d_021F4284     0x021F4284  data  a4
 *   func_0218C6F4  0x0218C6F4  thumb  ov021
 *   func_02028A7C  0x02028A7C  thumb
 *   d_021F425C  0x021F425C  data  ov056  a4
 *   func_0201296C  0x0201296C  thumb
 *   func_020143CC  0x020143CC  thumb
 *   func_02028B50  0x02028B50  thumb
 *   func_02030734  0x02030734  arm
 *   func_02011510  0x02011510  thumb
 *   func_02082D44  0x02082D44  arm
 *   d_021F4400  0x021F4400  data  ov056  a1
 *   func_02011558  0x02011558  thumb
 *   sub_020307B0   0x020307B0  arm
 *   ICA_ANIME_GetFrameNum  0x02011608  thumb
 *   func_020115EC  0x020115EC  thumb
 *   func_02011610  0x02011610  thumb
 *   ICA_ANIME_GetScale  0x02011660  thumb
 *   func_02011638  0x02011638  thumb
 *   func_021F423C  0x021F423C  thumb  ov056
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 */
#include "unit_021F36C0_types.h"

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082D44(const void *src, void *dst, int size);
extern u32 sub_020307B0(void *memory);
extern struct IcaAnime *func_02011510(u16 heapId, u32 arcId, u32 dataId, u32 bufFrameNum);
extern u32 func_02011610(struct IcaAnime *anime, VecFx32 *translate);
extern u32 ICA_ANIME_GetScale(struct IcaAnime *anime, VecFx32 *scale);
extern u32 func_02011638(struct IcaAnime *anime, VecFx32 *rotate);
extern void GFL_USE_PlaySeDefaultVolume(u32 seId);

void func_021F3E94(struct FieldSubproc *proc, struct FieldMap *fieldMap, FkFrameSoundWork *work);
void func_021F3EC8(struct FieldSubproc *proc, struct FieldMap *fieldMap, FkFrameSoundWork *work);
void func_021F3ECC(struct FieldSubproc *proc, struct FieldMap *fieldMap, FkFrameSoundWork *work);
void func_021F3F30(struct FieldSubproc *proc, struct FieldMap *fieldMap, FkAmbientSoundWork *work);
void func_021F3F7C(struct FieldSubproc *proc, struct FieldMap *fieldMap, FkAmbientSoundWork *work);
void func_021F3F94(struct FieldSubproc *proc, struct FieldMap *fieldMap, FkAmbientSoundWork *work);
void func_021F3FB8(struct FieldSubproc *proc, struct FieldMap *fieldMap, FkAmbientSoundWork *work);
void func_021F4004(struct FieldSubproc *proc, struct FieldMap *fieldMap, FkAmbientSoundWork *work);
void func_021F401C(struct FieldSubproc *proc, struct FieldMap *fieldMap, FkAmbientSoundWork *work);


/*
 * Init of the proc that plays a sound at listed frames of a building
 * animation (template d_021F435C). Remembers the building model and the
 * sound system.
 *
 * note:     first entry of the callback triple at 0x021F4364
 *           {0x021F3E95, 0x021F3EC9, 0x021F3ECD}; r0 is unused. The second
 *           entry, func_021F3EC8, is an unlabelled empty callback (bx lr)
 *           right after the lead's pool, then 2 bytes of padding.
 */
void func_021F3E94(struct FieldSubproc *proc, struct FieldMap *fieldMap, FkFrameSoundWork *work)
{
    struct BuildModelMan *man;

    man = func_0218DC6C(func_02188C98(fieldMap));
    work->entry = func_0218C654(man, 0, &d_021F4284);
    work->man = man;
    work->soundSys = func_02012A30(func_020120F4(func_02188C80(fieldMap)));
}


/* Exit of that proc: nothing to undo. */
void func_021F3EC8(struct FieldSubproc *proc, struct FieldMap *fieldMap, FkFrameSoundWork *work)
{
}


/*
 * Update of that proc: when the building animation is at one of the listed
 * frames it plays the hit sound and starts a countdown; when the countdown
 * ends it plays the closing sound.
 */
void func_021F3ECC(struct FieldSubproc *proc, struct FieldMap *fieldMap, FkFrameSoundWork *work)
{
    int i;
    int frame;

    i = 0;
    frame = func_0218C6F4(work->man, work->entry, 0);
    for (; i < 2; i++) {
        if (frame == d_021F425C[i]) {
            func_02028A7C(work->soundSys, FK_SE_FRAME_HIT);
            work->hitActive = 1;
            work->hitCountdown = 0x1f;
            break;
        }
    }
    if (work->hitActive != 0) {
        work->hitCountdown = work->hitCountdown - 1;
        if (work->hitCountdown <= 0) {
            func_02028A7C(work->soundSys, FK_SE_FRAME_HIT_END);
            work->hitActive = 0;
            work->hitCountdown = 0;
        }
    }
}


/*
 * Init of the proc that plays an ambient sound (template d_021F4374) until the
 * script work variable FK_AMBIENT_STOP_WORK_ID is not 0.
 */
void func_021F3F30(struct FieldSubproc *proc, struct FieldMap *fieldMap, FkAmbientSoundWork *work)
{
    struct GameData *gameData;

    gameData = func_020120F4(func_02188C80(fieldMap));
    work->eventWork = func_0201296C(gameData);
    work->soundSys = func_02012A30(gameData);
    work->stopVar = func_020143CC(work->eventWork, FK_AMBIENT_STOP_WORK_ID);
    if (*work->stopVar == 0) {
        func_02028A7C(work->soundSys, FK_SE_AMBIENT_A);
        work->stopped = 0;
        return;
    }
    work->stopped = 1;
}


/* Exit of that proc: stops the sound if it still plays. */
void func_021F3F7C(struct FieldSubproc *proc, struct FieldMap *fieldMap, FkAmbientSoundWork *work)
{
    if (work->stopped == 0) {
        func_02028B50(work->soundSys, FK_SE_AMBIENT_A);
    }
}


/* Update of that proc: stops the sound when the script variable is set. */
void func_021F3F94(struct FieldSubproc *proc, struct FieldMap *fieldMap, FkAmbientSoundWork *work)
{
    if (*work->stopVar != 0 && work->stopped == 0) {
        func_02028B50(work->soundSys, FK_SE_AMBIENT_A);
        work->stopped = 1;
    }
}


/* Same as func_021F3F30 for the second ambient sound (template d_021F438C). */
void func_021F3FB8(struct FieldSubproc *proc, struct FieldMap *fieldMap, FkAmbientSoundWork *work)
{
    struct GameData *gameData;

    gameData = func_020120F4(func_02188C80(fieldMap));
    work->eventWork = func_0201296C(gameData);
    work->soundSys = func_02012A30(gameData);
    work->stopVar = func_020143CC(work->eventWork, FK_AMBIENT_STOP_WORK_ID);
    if (*work->stopVar == 0) {
        func_02028A7C(work->soundSys, FK_SE_AMBIENT_B);
        work->stopped = 0;
        return;
    }
    work->stopped = 1;
}


void func_021F4004(struct FieldSubproc *proc, struct FieldMap *fieldMap, FkAmbientSoundWork *work)
{
    if (work->stopped == 0) {
        func_02028B50(work->soundSys, FK_SE_AMBIENT_B);
    }
}


void func_021F401C(struct FieldSubproc *proc, struct FieldMap *fieldMap, FkAmbientSoundWork *work)
{
    if (*work->stopVar != 0 && work->stopped == 0) {
        func_02028B50(work->soundSys, FK_SE_AMBIENT_B);
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
FkSoundAnime *func_021F4040(const void *soundIds, u32 arcId, u32 dataId, u32 bufFrameNum, u16 heapId)
{
    FkSoundAnime *sound;

    sound = func_02030734(heapId, sizeof(FkSoundAnime), 1, d_021F4400, 0x4d);
    sound->frame = 0;
    sound->anime = func_02011510(heapId, arcId, dataId, bufFrameNum);
    func_02082D44(soundIds, sound->soundId, 0x12);
    return sound;
}


/*
 * Deletes the sound anime.
 *
 * extent:   EXACT* covers only the 2-byte alignment pad at 0x021F409E;
 *           the follower 0x021F40A0 is separately matched (pkt_021F40A0).
 */
void func_021F408C(FkSoundAnime *sound)
{
    func_02011558(sound->anime);
    sub_020307B0(sound);
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
int func_021F40A0(FkSoundAnime *sound)
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
    func_020115EC(sound->anime, sound->frame);
    func_02011610(sound->anime, &translate);
    ICA_ANIME_GetScale(sound->anime, &scale);
    func_02011638(sound->anime, &rotate);
    if (translate.x == FK_SOUND_CHANNEL_PLAY) func_021F4224(sound, 0); else if (translate.x == FK_SOUND_CHANNEL_STOP) func_021F423C(sound, 0);
    if (translate.y == FK_SOUND_CHANNEL_PLAY) func_021F4224(sound, 1); else if (translate.y == FK_SOUND_CHANNEL_STOP) func_021F423C(sound, 1);
    if (translate.z == FK_SOUND_CHANNEL_PLAY) func_021F4224(sound, 2); else if (translate.z == FK_SOUND_CHANNEL_STOP) func_021F423C(sound, 2);
    if (scale.x == FK_SOUND_CHANNEL_PLAY) func_021F4224(sound, 3); else if (scale.x == FK_SOUND_CHANNEL_STOP) func_021F423C(sound, 3);
    if (scale.y == FK_SOUND_CHANNEL_PLAY) func_021F4224(sound, 4); else if (scale.y == FK_SOUND_CHANNEL_STOP) func_021F423C(sound, 4);
    if (scale.z == FK_SOUND_CHANNEL_PLAY) func_021F4224(sound, 5); else if (scale.z == FK_SOUND_CHANNEL_STOP) func_021F423C(sound, 5);
    if (rotate.x == FK_SOUND_CHANNEL_PLAY) func_021F4224(sound, 6); else if (rotate.x == FK_SOUND_CHANNEL_STOP) func_021F423C(sound, 6);
    if (rotate.y == FK_SOUND_CHANNEL_PLAY) func_021F4224(sound, 7); else if (rotate.y == FK_SOUND_CHANNEL_STOP) func_021F423C(sound, 7);
    if (rotate.z == FK_SOUND_CHANNEL_PLAY) func_021F4224(sound, 8); else if (rotate.z == FK_SOUND_CHANNEL_STOP) func_021F423C(sound, 8);
    sound->frame += 0x1000;
    return done;
}


/* Plays the sound effect of a channel, if it has one. */
void func_021F4224(FkSoundAnime *sound, u32 channel)
{
    u16 seId = sound->soundId[channel];

    if (seId != FK_SOUND_NONE) {
        GFL_USE_PlaySeDefaultVolume(seId);
    }
}
