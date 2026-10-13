/*
 * function: GIMMICK53_UpdateSlideSe
 * address:  0x021F3B40
 * packet:   pkt_ov053_021F3B40
 * region:   ov053
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Called from GIMMICK53_Update with (p + 0x1a, h, FIELDMAP_GetFieldPlayer(a)).
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
 *   GFL_USE_GetSeSlot  0x02006148  thumb
 *   GFL_USE_IsSeSlotBusy  0x02006224  thumb
 *   GFL_USE_StopSeSlot  0x020061F8  thumb
 *   GFL_USE_SetSeSlotVolume  0x020062BC  thumb
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   FIELD_CAMERA_GetEyeRaw  0x0218ECE4  thumb  ov021
 *   FIELD_PLAYER_GetFormSlot  0x021A34EC  thumb  ov021
 */

typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

typedef struct Obj {
    int prev;
    int hist[32];
    s16 head;
    s16 count;
    s16 vol;
    u16 state;
    u16 se;
} Obj;

extern int GFL_USE_GetSeSlot(u32 a0);
extern int GFL_USE_IsSeSlotBusy(u32 a0);
extern void GFL_USE_StopSeSlot(int i);
extern void GFL_USE_SetSeSlotVolume(int i, u32 level);
extern void GFL_USE_PlaySeDefaultVolume(u32 id);
extern void FIELD_CAMERA_GetEyeRaw(int, int *);
typedef unsigned char  u8;
extern int FIELD_PLAYER_GetFormSlot(u8 *p);

void GIMMICK53_UpdateSlideSe(Obj *o, int h, u8 *a2)
{
    int v[3];
    int d;
    int i;
    int n;
    int t;
    u32 se;

    if ((u16)(o->state + 0xffff) <= 1) {
        if (GFL_USE_IsSeSlotBusy(GFL_USE_GetSeSlot(0x7eb)) == 0) {
            o->state = 0;
        }
        if (o->state == 2) {
            o->vol -= 16;
            n = o->vol;
            if (n < 0) {
                GFL_USE_StopSeSlot(GFL_USE_GetSeSlot(o->se));
                o->state = 0;
            } else {
                GFL_USE_SetSeSlotVolume(GFL_USE_GetSeSlot(o->se), n);
            }
        }
    }
    FIELD_CAMERA_GetEyeRaw(h, v);
    d = o->prev;
    d = v[2] - d;
    if (d < 0) {
        d = -d;
    }
    if (d > 0) {
        n = o->count;
        if (n < 32) {
            i = (o->head + n) % 32;
            o->count = n + 1;
        } else {
            i = o->head;
            o->head = (i + 1) % 32;
        }
        o->hist[i] = v[1];
    } else {
        o->count = 0;
        o->head = 0;
        if (o->state == 1 && v[2] > 0x718000) {
            o->state = 2;
            o->vol = 0x7f;
        }
    }
    if (o->count > 0) {
        if (FIELD_PLAYER_GetFormSlot(a2) == 0) {
            t = 0x75c000;
            se = 0x7ed;
        } else {
            t = 0x7bc000;
            se = 0x7eb;
        }
        if ((v[2] < t && o->prev > t) || (v[2] > t && o->prev < t)) {
            if (o->hist[o->head] - v[1] >= 0x64000) {
                GFL_USE_PlaySeDefaultVolume(se);
                o->state = 1;
                o->se = se;
            }
        }
    }
    o->prev = v[2];
}
