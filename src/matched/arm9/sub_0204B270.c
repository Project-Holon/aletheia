/*
 * unit:     no
 * function: CLACT_SetUnitDefaultRenderer
 * address:  0x0204B270
 * packet:   pkt_0204B0C8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_ClactSystem     0x02146A74  data
 *
 * The companion of CLACT_SetUnitRenderer in src/matched/unit_0204B22C.c: point the
 * bank at the shared default block 0x40 bytes into whatever 0x02146A74 holds
 * and clear the low nibble of the flag byte at +0x0e back to source 0, where
 * CLACT_SetUnitRenderer sets it to 1 for a caller-supplied pointer.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_SetUnitDefaultRenderer.c \
 *       --func CLACT_SetUnitDefaultRenderer --addr 0x0204B270 --cc 1.1p1 --arm
 */

#include "../include/G_Mgr.h"

typedef unsigned char u8;

struct Bank {
    u8    pad_00[8];
    void *unk_08;
    u8    pad_0c[2];
    u8    source : 4;
    u8    mode   : 4;
    u8    pad_0f[9];
};

extern struct Mgr *g_ClactSystem;

void CLACT_SetUnitDefaultRenderer(struct Bank *bank)
{
    bank->unk_08 = ((u8 *)g_ClactSystem) + 0x40;
    bank->source = 0;
}
