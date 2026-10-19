/*
 * function: GFL_NET_HANDLE_GetNetHandle
 * address:  0x0203996C
 * packet:   pkt_020398B4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_GetSession  0x0203D788  arm
 *
 * Resolves a slot index to one of the nine 0x50-byte entries at +0x70 of
 * GFL_NET_GetSession()'s record.  0xff is the "own slot" spelling and names entry
 * 8, which is why it is a separate constant add and not a folded index; every
 * other index is bounds-checked against nine and scaled with an `mla`,
 * 0x50 being too awkward for a shift pair.
 *
 * The record's own +0x340 field (see src/matched/GFL_NET_SYSTEM_GetCurrentAid.c) is exactly
 * where this table ends: 0x70 + 9 * 0x50.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_HANDLE_GetNetHandle.c \
 *       --func GFL_NET_HANDLE_GetNetHandle --addr 0x0203996C --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef signed int    s32;

struct Entry {
    u8 pad_00[0x50];
};

struct Owner {
    u8 pad_00[0x70];
    struct Entry table[9];
};

extern void *GFL_NET_GetSession(void);

struct Entry *GFL_NET_HANDLE_GetNetHandle(s32 idx)
{
    struct Owner *owner = GFL_NET_GetSession();

    if (owner != 0) {
        if (idx == 0xff) {
            return &owner->table[8];
        }
        if (idx < 9) {
            return &owner->table[idx];
        }
    }
    return 0;
}
