/*
 * unit:     yes
 * function: G3D_SYSTEM_ResetObjectAnimeFrame, G3D_SYSTEM_GetObjectAnimeFrame
 * address:  0x02047804
 * packet:   pkt_02047804
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Two siblings of G3D_SYSTEM_SetObjectAnimeFrame over the same slot table at +8: a null slot
 * returns 0; otherwise the first clears the slot object's frame and the
 * second stores it to *frame, and both return 1.  Seeded from ov021
 * 0x0218C064 and 0x0218C486 (blx).
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

u32 G3D_SYSTEM_ResetObjectAnimeFrame(struct AnmCtl *c, u16 idx)
{
    struct AnmSlot *s = c->slots[idx];

    if (s == 0) {
        return 0;
    }
    s->obj->frame = 0;
    return 1;
}

u32 G3D_SYSTEM_GetObjectAnimeFrame(struct AnmCtl *c, u32 idx, s32 *frame)
{
    struct AnmSlot *s = c->slots[idx];

    if (s == 0) {
        return 0;
    }
    *frame = s->obj->frame;
    return 1;
}
