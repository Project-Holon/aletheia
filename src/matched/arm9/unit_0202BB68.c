/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x0202BB68
 * packet:   pkt_0202BB68
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: ISS_3DS_SYS_StepSourceVolume, ISS_3DS_SYS_StepSourcePan
 *
 * iss_3ds_sys.c, the per-slot twins that ISS_3DS_SYS_UpdateImpl steps: for a live
 * entry (0x1c-byte stride at +0x24), run the entry's comparator and move the
 * slot's s32 level (+0x1E4 or +0x224, indexed by i) toward the result through
 * the clamp helpers of unit_0202BC48 / ISS_3DS_SYS_RampPanDown / ISS_3DS_SYS_RampPanUp, which
 * take the comparator result as their third argument.  ISS_3DS_SYS_StepSourcePan's
 * comparator takes the extra sub-object at +0x18, and its two compares are
 * the mirror of ISS_3DS_SYS_StepSourceVolume's.
 *
 * What closed them (wave 17, from 37 and 36 out): callee arity read from
 * the callee bodies.  Both clamp helpers compare against r2
 * (src/matched/unit_0202BC48.c, ISS_3DS_SYS_RampPanDown.c, ISS_3DS_SYS_RampPanUp.c are
 * (obj, index, cap)); declaring them with two parameters dropped the
 * image's `adds r2, r0, #0` copy of the comparator result, the one
 * instruction the note had chased as a register-order problem.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202BB68.c \
 *       --addr 0x0202BB68 --thumb
 *
 * symbols:
 *   ISS_3DS_SYS_CalcSourceVolume  0x0202BBFC  thumb
 *   ISS_3DS_SYS_CalcSourcePan  0x0202BCA0  thumb
 *   ISS_3DS_SYS_RampVolumeUp  0x0202BC48  thumb
 *   ISS_3DS_SYS_RampPanDown  0x0202BDD0  thumb
 *   ISS_3DS_SYS_RampPanUp  0x0202BDE8  thumb
 *   ISS_3DS_SYS_RampVolumeDown  0x0202BC60  thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;
typedef signed int    s32;

struct Listener;
struct Rec;
struct Vec;
extern s32 ISS_3DS_SYS_CalcSourceVolume(struct Rec *r, const struct Vec *p);
extern s32 ISS_3DS_SYS_CalcSourcePan(const struct Listener *l, const struct Vec *ps, const struct Vec *pp);
extern void ISS_3DS_SYS_RampVolumeUp(void *obj, u32 index, s32 cap);
extern void ISS_3DS_SYS_RampVolumeDown(void *obj, u32 index, s32 cap);
extern void ISS_3DS_SYS_RampPanDown(void *obj, u32 index, s32 cap);
extern void ISS_3DS_SYS_RampPanUp(void *obj, u32 index, s32 cap);

void ISS_3DS_SYS_StepSourceVolume(u8 *o, int i)
{
    u8 *e = o + 0x24;
    s32 v;
    s32 lv;

    if (*(u32 *)(e + i * 0x1c) == 0) {
        return;
    }
    v  = ISS_3DS_SYS_CalcSourceVolume((struct Rec *)(e + i * 0x1c), (const struct Vec *)(o + 0xc));
    lv = *(s32 *)(o + i * 4 + 0x1e4);
    if (lv < v) {
        ISS_3DS_SYS_RampVolumeUp(o, i, v);
        return;
    }
    if (v < lv) {
        ISS_3DS_SYS_RampVolumeDown(o, i, v);
    }
}

void ISS_3DS_SYS_StepSourcePan(u8 *o, int i)
{
    u8 *e = o + 0x24;
    s32 v;
    s32 lv;

    if (*(u32 *)(e + i * 0x1c) == 0) {
        return;
    }
    v  = ISS_3DS_SYS_CalcSourcePan((const struct Listener *)(e + i * 0x1c), (const struct Vec *)(o + 0xc), (const struct Vec *)(o + 0x18));
    lv = *(s32 *)(o + i * 4 + 0x224);
    if (v < lv) {
        ISS_3DS_SYS_RampPanDown(o, i, v);
        return;
    }
    if (lv < v) {
        ISS_3DS_SYS_RampPanUp(o, i, v);
    }
}
