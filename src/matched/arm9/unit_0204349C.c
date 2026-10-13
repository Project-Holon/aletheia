/*
 * unit:     yes
 * function: BG_SYS_ClearMainBgPlanes
 * address:  0x0204349C
 * packet:   pkt_02042B24
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02146A48     0x02146A48  data
 *
 * The tail of the packet: two one-line mask-downs of the same 32-bit word
 * at +4 of the object that starts at 0x02146A48, and the wrapper that runs
 * both.  Each accessor keeps only the bits its own half owns (0x10 for the
 * first, 0x0f for the second), so calling both in sequence clears the word
 * outright; the wrapper is the reset path.
 *
 * Kept as one unit so the two `bl` sites in BG_SYS_ClearMainPlanes are `local`: they
 * are that pair's only callers image-wide, and split into three files
 * neither could attest the other
 * (docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md in
 * reverse).
 */

#include "../include/G_Flags.h"

typedef unsigned int u32;

extern struct Flags g_02146A48;

void BG_SYS_ClearMainBgPlanes(void)
{
    g_02146A48.unk_04 = g_02146A48.unk_04 & 0x10;
}

void BG_SYS_ClearMainObjPlane(void)
{
    g_02146A48.unk_04 = g_02146A48.unk_04 & 0xf;
}

void BG_SYS_ClearMainPlanes(void)
{
    BG_SYS_ClearMainBgPlanes();
    BG_SYS_ClearMainObjPlane();
}
