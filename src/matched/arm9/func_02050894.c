/*
 * function: func_02050894
 * address:  0x02050894
 * packet:   pkt_02050894
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * symbols:
 *   func_02050738   0x02050738  arm
 *
 * PROMOTED from src/pending/func_02050894.c: it was parked at MATCH because
 * the only branch in the image to 0x02050738 is the one inside this function.
 * 0x02050738 (88 bytes, pkt_02050340) is now matched, so the site resolves by
 * the `matched` class with no change to the C.  The file's packet id is
 * corrected from pkt_02050340 to pkt_02050894, which is the packet the
 * worklist gives 0x02050894.
 *
 * Moves one word between two parallel record arrays of the object: the index
 * is read out of the 40-byte record table at p+24, the value out of the
 * 8-byte-pair array at p+12, the value is stored back into the record the
 * index names, and the record is handed to func_02050738.
 *
 * The listing's extent runs 140 bytes because the follower at 0x020508C4 is an
 * unlabelled leaf accessor (no prologue that saves lr).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02050894.c \
 *       --func func_02050894 --addr 0x02050894 --cc 1.1p1 --arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct S8 {
    u16 h;
    u16 pad;
    u32 w;
};

struct S40 {
    u32 f0;
    u16 f4;
    u16 f6;
    u32 f8;
    u32 f12;
    u32 f16;
    u32 f20;
    u32 f24;
    u32 f28;
    u32 f32;
    u32 f36;
};

extern u32 func_02050738(void *p, void *q);

int func_02050894(void *p, int idx, int j)
{
    struct S8  *arr = *(struct S8 **)((char *)p + 12);
    struct S40 *rec = *(struct S40 **)((char *)p + 24);
    u16 e = rec[idx].f4;
    u32 v = arr[j].w;

    arr[e].w = v;
    return func_02050738(p, &arr[e]);
}
