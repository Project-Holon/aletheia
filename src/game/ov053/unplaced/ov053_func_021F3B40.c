/*
 * function: func_021F3B40
 * address:  0x021F3B40
 * packet:   pkt_ov053_021F3B40
 * region:   ov053
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Called from func_021F3778 with (&work->slideSe, camera, func_02188CB4(fieldMap)).
 * Two spellings carry it:
 *   - the state range test is `(u16)(o->state + 0xffff) <= 1` (the image
 *     adds a pooled 0xFFFF); `(u16)(o->state - 1)` gives subs #1, and a
 *     switch or `>= 1 && <= 2` gives a compare pair;
 *   - the difference is `d = o->prev; d = v[2] - d;` (self-recompute): the
 *     plain `v[2] - o->prev`, a copy into another local, or an abs macro or
 *     inline all load v[2] before o->prev.
 * The 576-byte handed extent is this function (0x17C bytes with its pool)
 * plus data that follows it.
 *
 * symbols:
 *   func_02006148  0x02006148  thumb
 *   func_02006224  0x02006224  thumb
 *   func_020061F8  0x020061F8  thumb
 *   GFL_USE_SetSeSlotVolume  0x020062BC  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_0218ECE4  0x0218ECE4  thumb  ov021
 *   func_021A34EC  0x021A34EC  thumb  ov021
 */

/*
 * Sliding sound of unit_021F36C0.c. Types of that file, as far as this
 * function uses them.
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct FieldCamera;
struct FieldPlayer;

typedef struct VecFx32 {
    int x;
    int y;
    int z;
} VecFx32;

#define SLIDE_HISTORY 32
#define SLIDE_IDLE 0
#define SLIDE_PLAYING 1
#define SLIDE_FADING 2

typedef struct SlideSe {
    int prevZ;
    int cameraY[SLIDE_HISTORY];
    short head;
    short count;
    short volume;
    u16 state;
    u16 seId;
    u8 reserved8E[2];
} SlideSe;

extern int func_02006148(u32 seId);
extern int func_02006224(u32 slot);
extern void func_020061F8(int slot);
extern void GFL_USE_SetSeSlotVolume(int slot, u32 volume);
extern void func_020061E4(u32 seId);
extern void func_0218ECE4(struct FieldCamera *camera, VecFx32 *eye);
extern int func_021A34EC(struct FieldPlayer *fieldPlayer);

/*
 * Plays and fades a sound effect while the camera slides down. The effect
 * starts when the camera crosses one of two lines in z and its height fell
 * by 0x64000 over the last frames; which line and effect depends on the
 * player (func_021A34EC). It fades out when the camera stops past 0x718000.
 */
void func_021F3B40(SlideSe *slideSe, struct FieldCamera *camera, struct FieldPlayer *fieldPlayer)
{
    VecFx32 eye;
    int zDelta;
    int i;
    int volume;
    int lineZ;
    u32 seId;

    if ((u16)(slideSe->state + 0xffff) <= 1) {
        if (func_02006224(func_02006148(0x7eb)) == 0) {
            slideSe->state = SLIDE_IDLE;
        }
        if (slideSe->state == SLIDE_FADING) {
            slideSe->volume -= 16;
            volume = slideSe->volume;
            if (volume < 0) {
                func_020061F8(func_02006148(slideSe->seId));
                slideSe->state = SLIDE_IDLE;
            } else {
                GFL_USE_SetSeSlotVolume(func_02006148(slideSe->seId), volume);
            }
        }
    }
    func_0218ECE4(camera, &eye);
    zDelta = slideSe->prevZ;
    zDelta = eye.z - zDelta;
    if (zDelta < 0) {
        zDelta = -zDelta;
    }
    if (zDelta > 0) {
        volume = slideSe->count;
        if (volume < SLIDE_HISTORY) {
            i = (slideSe->head + volume) % SLIDE_HISTORY;
            slideSe->count = volume + 1;
        } else {
            i = slideSe->head;
            slideSe->head = (i + 1) % SLIDE_HISTORY;
        }
        slideSe->cameraY[i] = eye.y;
    } else {
        slideSe->count = 0;
        slideSe->head = 0;
        if (slideSe->state == SLIDE_PLAYING && eye.z > 0x718000) {
            slideSe->state = SLIDE_FADING;
            slideSe->volume = 0x7f;
        }
    }
    if (slideSe->count > 0) {
        if (func_021A34EC(fieldPlayer) == 0) {
            lineZ = 0x75c000;
            seId = 0x7ed;
        } else {
            lineZ = 0x7bc000;
            seId = 0x7eb;
        }
        if ((eye.z < lineZ && slideSe->prevZ > lineZ) || (eye.z > lineZ && slideSe->prevZ < lineZ)) {
            if (slideSe->cameraY[slideSe->head] - eye.y >= 0x64000) {
                func_020061E4(seId);
                slideSe->state = SLIDE_PLAYING;
                slideSe->seId = seId;
            }
        }
    }
    slideSe->prevZ = eye.z;
}
