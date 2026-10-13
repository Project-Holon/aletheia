/*
 * function: func_0201F898
 * address:  0x0201F898
 * packet:   pkt_0201F5BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Claims a slot through BMP_MENUWORK_FindFreeEntry and, if one was free, fills it with the
 * handle func_02045874 returns and the caller's third argument.  Note the
 * argument roles are not the same as in the neighbouring func_0201F878: here
 * the builder takes the caller's *fourth* argument and the slot's tag word
 * comes from the third, the mirror of that function.  The tag word the
 * claim function writes back is never used here; it lands in the pushed r3
 * home slot at sp+0, which is exactly why the prologue pushes r3 at all.
 * A failed claim is silent.
 *
 * symbols:
 *   BMP_MENUWORK_FindFreeEntry  0x0201F8B8  thumb
 *   func_02045874  0x02045874  arm
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201F898.c  *       --func func_0201F898 --addr 0x0201F898 --cc 1.1p1 --thumb
 */
typedef unsigned int u32;

struct Slot {
    union {
        u32   raw;
        void *ptr;
    } u;
    u32 tag;
};

extern struct Slot *BMP_MENUWORK_FindFreeEntry(struct Slot *s, u32 *tag_out);
struct U16Vec;
extern struct U16Vec *func_02045874(struct U16Vec *src, u32 heapId);

void func_0201F898(struct Slot *table, u32 a, u32 b, u32 tag)
{
    struct Slot *slot;
    u32          unused;

    slot = BMP_MENUWORK_FindFreeEntry(table, &unused);
    if (slot != 0) {
        slot->u.ptr = func_02045874((struct U16Vec *)a, tag);
        slot->tag = b;
    }
}
