/*
 * function: BILLBOARD_ACT_SetEntryPaletteFromSlot
 * address:  0x02050894
 * packet:   pkt_02050894
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   BILLBOARD_ACT_UploadSlotPalette   0x02050738  arm
 *
 * PROMOTED from src/pending/BILLBOARD_ACT_SetEntryPaletteFromSlot.c: it was parked at MATCH because
 * the only branch in the image to 0x02050738 is the one inside this function.
 * 0x02050738 (88 bytes, pkt_02050340) is now matched, so the site resolves by
 * the `matched` class with no change to the C.  The file's packet id is
 * corrected from pkt_02050340 to pkt_02050894, which is the packet the
 * worklist gives 0x02050894.
 *
 * Moves one word between two parallel record arrays of the object: the index
 * is read out of the 40-byte record table at p+24, the value out of the
 * 8-byte-pair array at p+12, the value is stored back into the record the
 * index names, and the record is handed to BILLBOARD_ACT_UploadSlotPalette.
 *
 * The listing's extent runs 140 bytes because the follower at 0x020508C4 is an
 * unlabelled leaf accessor (no prologue that saves lr).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BILLBOARD_ACT_SetEntryPaletteFromSlot.c \
 *       --func BILLBOARD_ACT_SetEntryPaletteFromSlot --addr 0x02050894 --cc 1.1p1 --arm
 */
#include "../include/Obj11456.h"

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

extern u32 BILLBOARD_ACT_UploadSlotPalette(void *p, void *q);

int BILLBOARD_ACT_SetEntryPaletteFromSlot(void *p, int idx, int j)
{
    struct S8  *arr = *(struct S8 * *)&((struct Obj11456 *)p)->fC;
    struct S40 *rec = *(struct S40 * *)&((struct Obj11456 *)p)->f18;
    u16 e = rec[idx].f4;
    u32 v = arr[j].w;

    arr[e].w = v;
    return BILLBOARD_ACT_UploadSlotPalette(p, &arr[e]);
}
