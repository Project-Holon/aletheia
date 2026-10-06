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
 * function: func_0202BB68, func_0202BBB0
 *
 * iss_3ds_sys.c, the per-slot twins that func_0202BAF4 steps: for a live
 * entry (0x1c-byte stride at +0x24), run the entry's comparator and move the
 * slot's s32 level (+0x1E4 or +0x224, indexed by i) toward the result through
 * the clamp helpers of unit_0202BC48 / sub_0202BDD0 / sub_0202BDE8, which
 * take the comparator result as their third argument.  func_0202BBB0's
 * comparator takes the extra sub-object at +0x18, and its two compares are
 * the mirror of func_0202BB68's.
 *
 * What closed them (wave 17, from 37 and 36 out): callee arity read from
 * the callee bodies.  Both clamp helpers compare against r2
 * (src/matched/unit_0202BC48.c, sub_0202BDD0.c, sub_0202BDE8.c are
 * (obj, index, cap)); declaring them with two parameters dropped the
 * image's `adds r2, r0, #0` copy of the comparator result, the one
 * instruction the note had chased as a register-order problem.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202BB68.c \
 *       --addr 0x0202BB68 --thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;
typedef signed int    s32;

struct Listener;
struct Rec;
struct Vec;
extern s32 func_0202BBFC(struct Rec *r, const struct Vec *p);
extern s32 func_0202BCA0(const struct Listener *l, const struct Vec *ps, const struct Vec *pp);
extern void sub_0202BC48(void *obj, u32 index, s32 cap);
extern void sub_0202BC60(void *obj, u32 index, s32 cap);
extern void sub_0202BDD0(void *obj, u32 index, s32 cap);
extern void sub_0202BDE8(void *obj, u32 index, s32 cap);

void func_0202BB68(u8 *o, int i)
{
    u8 *e = o + 0x24;
    s32 v;
    s32 lv;

    if (*(u32 *)(e + i * 0x1c) == 0) {
        return;
    }
    v  = func_0202BBFC((struct Rec *)(e + i * 0x1c), (const struct Vec *)(o + 0xc));
    lv = *(s32 *)(o + i * 4 + 0x1e4);
    if (lv < v) {
        sub_0202BC48(o, i, v);
        return;
    }
    if (v < lv) {
        sub_0202BC60(o, i, v);
    }
}

void func_0202BBB0(u8 *o, int i)
{
    u8 *e = o + 0x24;
    s32 v;
    s32 lv;

    if (*(u32 *)(e + i * 0x1c) == 0) {
        return;
    }
    v  = func_0202BCA0((const struct Listener *)(e + i * 0x1c), (const struct Vec *)(o + 0xc), (const struct Vec *)(o + 0x18));
    lv = *(s32 *)(o + i * 4 + 0x224);
    if (v < lv) {
        sub_0202BDD0(o, i, v);
        return;
    }
    if (lv < v) {
        sub_0202BDE8(o, i, v);
    }
}
