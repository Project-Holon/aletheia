/*
 * function: G3D_SYSTEM_SetObjectAnimeFrame
 * address:  0x0204784C
 * packet:   pkt_0204784C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * ARM leaf, seeded 2026-09-27 from the ov195 call sites 0x02208B3E and
 * 0x02208B48 (func_02208AB0). Looks up slot idx of the table at +8; a
 * null slot returns 0. Otherwise it sets the slot object's frame to
 * *frame, clamped from above to numFrame << 12 (the u16 at +4 of the
 * object's resource), with a signed compare (strge/strlt), and returns 1.
 * Siblings at 0x02047804, 0x02047828, 0x020478B8 and 0x02047910 share the
 * slot lookup and are still unlabelled.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct AnmRes {
    u32 f0;
    u16 numFrame;       /* +4 */
};

struct AnmObj {
    s32 frame;          /* +0, fx32 */
    u32 f4;
    struct AnmRes *res; /* +8 */
};

struct AnmSlot {
    u32 f0;
    struct AnmObj *obj; /* +4 */
};

struct AnmCtl {
    u32 f0;
    u32 f4;
    struct AnmSlot **slots; /* +8 */
};

u32 G3D_SYSTEM_SetObjectAnimeFrame(struct AnmCtl *c, u16 idx, s32 *frame)
{
    struct AnmSlot *s = c->slots[idx];
    struct AnmObj *a;

    if (s == 0) {
        return 0;
    }
    a = s->obj;
    if (*frame >= (s32)(a->res->numFrame << 12)) {
        a->frame = a->res->numFrame << 12;
    } else {
        a->frame = *frame;
    }
    return 1;
}
