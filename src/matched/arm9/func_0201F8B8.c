/*
 * function: BMP_MENUWORK_FindFreeEntry
 * address:  0x0201F8B8
 * packet:   pkt_0201F5BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Claims a slot in the same eight-byte-stride table func_0201F8F4 walks: it
 * scans for the first empty entry, gives up if the 0xFFFFFFFF terminator
 * arrives first, then runs on to the terminator record and hands its tag word
 * back through the out-parameter.  The empty slot is the return value, null on
 * a full table.
 *
 * Both loops read the word once per iteration and share the load between the
 * zero test and the terminator test, which is why this function needs no
 * union where func_0201F8F4 does: here both tests are u32.  The terminator
 * constant is rematerialised with its own `movs`/`mvns` pair in each of the
 * two blocks that needs it rather than kept live across the first loop; see
 * docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md.
 *
 * It is a leaf, so `push {r3, r4}` / `pop {r3, r4}` + `bx lr` rather than a
 * pop into pc, and disasm.py never labels it.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_MENUWORK_FindFreeEntry.c \
 *       --func BMP_MENUWORK_FindFreeEntry --addr 0x0201F8B8 --cc 1.1p1 --thumb
 */
typedef unsigned int u32;

struct Slot {
    union {
        u32   raw;
        void *ptr;
    } u;
    u32 tag;
};

struct Slot *BMP_MENUWORK_FindFreeEntry(struct Slot *s, u32 *tag_out)
{
    struct Slot *free_slot;

    while (s->u.raw != 0) {
        if (s->u.raw == 0xFFFFFFFF)
            return 0;
        s++;
    }
    free_slot = s;
    while (s->u.raw != 0xFFFFFFFF)
        s++;
    *tag_out = s->tag;
    return free_slot;
}
