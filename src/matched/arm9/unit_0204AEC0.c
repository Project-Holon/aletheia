/*
 * unit:     yes
 * function: CLACT_GetPaletteProxy
 * address:  0x0204AEC0
 * packet:   pkt_0204ADEC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_ClactSystem     0x02146A74  data
 *   NNSi_G2dGetVramHandleEx  0x02063800  arm
 *
 * A getter and its one caller.  CLACT_GetPaletteProxy copies the 0x14-byte record
 * out of slot `idx` of the 0x18-byte-stride table at +0x110 of the
 * singleton behind 0x02146A74; the copy is an inlined `ldm`/`stm` pair plus
 * a trailing word, which is what a whole-struct assignment of this size
 * compiles to (docs/idioms/aggregate-assignment-is-ldm-stm.md).
 * CLACT_GetPaletteVramAddress takes that copy on its own stack and submits it to
 * NNSi_G2dGetVramHandleEx under selector 1 or 2.
 *
 * Kept as one unit so the `bl` at CLACT_GetPaletteVramAddress+0x1c is `local`:
 * CLACT_GetPaletteVramAddress is CLACT_GetPaletteProxy's only caller image-wide, so split into two
 * files the site would have no witness of any class.
 */

#include "../include/G_Mgr.h"

typedef unsigned char u8;
typedef unsigned int  u32;

struct Record {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0c;
    u32 unk_10;
};

struct Slot {
    struct Record record;
    u32           unk_14;
};

extern struct Mgr *g_ClactSystem;

extern int NNSi_G2dGetVramHandleEx(char *p, int i);

void CLACT_GetPaletteProxy(u32 idx, struct Record *dest)
{
    *dest = ((struct Slot *)g_ClactSystem->owner_slots2)[idx].record;
}

int CLACT_GetPaletteVramAddress(u32 idx, u32 alternate)
{
    struct Record record;
    u32 selector;

    selector = 1;
    if (alternate != 0) {
        selector = 2;
    }

    CLACT_GetPaletteProxy(idx, &record);
    return NNSi_G2dGetVramHandleEx((char *)(&record), selector);
}
