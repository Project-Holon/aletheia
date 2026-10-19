/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * function: GFL_NET_HANDLE_SetTimingSyncRange, GFL_NET_HANDLE_IsTimingSync, GFL_NET_HANDLE_IsTimingSyncRange
 * address:  0x02039C68
 * packet:   pkt_020399B8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_HANDLE_GetNetHandleID  0x020395EC  arm
 *
 * The setter and the two matchers for the packed 16-bit key at +0x44/+0x46
 * of the link record: the key is always assembled as `lo + (hi << 8)` from a
 * pair of separate arguments rather than passed whole.
 *
 * GFL_NET_HANDLE_IsTimingSync has no label in the listing: it is a leaf that saves nothing,
 * so disasm.py prints it inside GFL_NET_HANDLE_SetTimingSyncRange's extent (see
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).  Keeping the
 * three in one unit is what reproduces its bytes at all.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02039C68.c \
 *       --addr 0x02039C68 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Link {
    u8 pad_00[0x44];
    u16 unk44;
    u16 unk46;
    u8 unk48;
    u8 unk49;
};

struct Entry;
extern int GFL_NET_HANDLE_GetNetHandleID(struct Entry *a);

void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *p, u32 lo, u32 hi)
{
    if (p == 0) {
        return;
    }

    p->unk46 = lo + (hi << 8);
    p->unk48 = 0xff;

    if (GFL_NET_HANDLE_GetNetHandleID((struct Entry *)p) == 0xff) {
        p->unk49 = 0;
    } else {
        p->unk49 = 1;
    }
}

u32 GFL_NET_HANDLE_IsTimingSync(struct Link *p, u32 key)
{
    return p->unk44 == key;
}

u32 GFL_NET_HANDLE_IsTimingSyncRange(struct Link *p, u32 lo, u32 hi)
{
    if (p == 0) {
        return 1;
    }
    return p->unk44 == lo + (hi << 8);
}
