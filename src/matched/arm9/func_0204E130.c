/*
 * function: TEXTPRINT_Init
 * address:  0x0204E130
 * packet:   pkt_0204D768
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 *
 * status:   EXACT
 *
 * symbols:
 *   g_TextPrintWork         0x02146A78  data
 *   SYSTEMFONT_Load      0x020461F4  arm
 *   func_02030734      0x02030734  arm
 *   func_0204E130_File 0x020A7F80  data
 *
 * Idempotent one-time init of the singleton at 0x02146A78: if it is already
 * live, return; otherwise run SYSTEMFONT_Load and allocate a 0x26-byte record
 * from heap 0 into the global.
 *
 * The guard's load landing in r1 rather than r0 is the arity tell: the
 * incoming parameter is still live in r0 because it is forwarded unchanged
 * to SYSTEMFONT_Load, so the global's load has to go somewhere else.  Written
 * `void TEXTPRINT_Init(void)` with `SYSTEMFONT_Load()`, the load takes r0 and
 * two bytes are wrong; an unused parameter does not do it either, since a
 * dead parameter frees its register immediately.  The caller at 0x020055BA
 * sets `movs r0, #0` before the `blx`, confirming the one argument.  The
 * heap id the allocator gets is a freshly materialised 0, not that
 * parameter, which is why the parameter is not saved across the call.
 *
 * The file string at 0x020A7F80 is "textprint.c", __LINE__ = 51.  The
 * alignment argument is `mov r2, r0`, the heap id's zero re-used, so heap
 * and align must both be spelled 0 with heap first.
 *
 * Byte-correct, capped at MATCH: the PC24 at +0x1c (SYSTEMFONT_Load) has no
 * witness outside 0204E130..0204E180.  This function is 0x020461F4's only
 * caller image-wide, so the `label` class is unavailable, the two are far
 * apart so no unit can make the site `local`, and there is no EXACT entry
 * for 0x020461F4 to serve as a `matched` witness.  It unsticks when
 * 0x020461F4 is decompiled to EXACT (it is a seven-register-push function
 * in another packet, not reachable inside this run's territory).
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/TEXTPRINT_Init.c \
 *       --func TEXTPRINT_Init --addr 0x0204E130 --cc 1.1p1 --arm
 */

#include "../include/G_TextCtx.h"

typedef unsigned int u32;

extern const char func_0204E130_File[];

extern struct TextCtx *g_TextPrintWork;

extern void  SYSTEMFONT_Load(u32 a);
typedef unsigned short u16;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

void TEXTPRINT_Init(u32 a)
{
    if (g_TextPrintWork == 0) {
        SYSTEMFONT_Load(a);
        g_TextPrintWork = func_02030734(0, 0x26, 0, func_0204E130_File, 51);
    }
}
