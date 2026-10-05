/*
 * function: func_0201F878
 * address:  0x0201F878
 * packet:   pkt_0201F5BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Claims a slot through func_0201F8B8 and, if one was free, fills it with the
 * handle func_02045EC0 returns and the caller's tag.  The tag word the
 * claim function writes back is never used here; it lands in the pushed r3
 * home slot at sp+0, which is exactly why the prologue pushes r3 at all.
 * A failed claim is silent.
 *
 * symbols:
 *   func_0201F8B8  0x0201F8B8  thumb
 *   func_02045EC0  0x02045EC0  arm
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201F878.c  *       --func func_0201F878 --addr 0x0201F878 --cc 1.1p1 --thumb
 */
typedef unsigned int u32;

struct Slot {
    union {
        u32   raw;
        void *ptr;
    } u;
    u32 tag;
};

extern struct Slot *func_0201F8B8(struct Slot *s, u32 *tag_out);
struct MsgBank;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);

void func_0201F878(struct Slot *table, u32 a, u32 b, u32 tag, u32 heap)
{
    struct Slot *slot;
    u32          unused;

    slot = func_0201F8B8(table, &unused);
    if (slot != 0) {
        slot->u.ptr = func_02045EC0((struct MsgBank *)a, b);
        slot->tag = tag;
    }
}
