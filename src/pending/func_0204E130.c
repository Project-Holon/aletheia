/*
 * function: func_0204E130
 * address:  0x0204E130
 * packet:   pkt_0204D768
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 *
 * status:   MATCH
 * note:     re-verified 2026-09-20: MATCH; see verify output
 *
 * symbols:
 *   g_02146A78         0x02146A78  data
 *   func_020461F4      0x020461F4  arm
 *   func_02030734      0x02030734  arm
 *   func_0204E130_File 0x020A7F80  data
 *
 * Idempotent one-time init of the singleton at 0x02146A78: if it is already
 * live, return; otherwise run func_020461F4 and allocate a 0x26-byte record
 * from heap 0 into the global.
 *
 * The guard's load landing in r1 rather than r0 is the arity tell: the
 * incoming parameter is still live in r0 because it is forwarded unchanged
 * to func_020461F4, so the global's load has to go somewhere else.  Written
 * `void func_0204E130(void)` with `func_020461F4()`, the load takes r0 and
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
 * Byte-correct, capped at MATCH: the PC24 at +0x1c (func_020461F4) has no
 * witness outside 0204E130..0204E180.  This function is 0x020461F4's only
 * caller image-wide, so the `label` class is unavailable, the two are far
 * apart so no unit can make the site `local`, and there is no EXACT entry
 * for 0x020461F4 to serve as a `matched` witness.  It unsticks when
 * 0x020461F4 is decompiled to EXACT (it is a seven-register-push function
 * in another packet, not reachable inside this run's territory).
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0204E130.c \
 *       --func func_0204E130 --addr 0x0204E130 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern const char func_0204E130_File[];

extern void *g_02146A78;

extern void  func_020461F4(u32 a);
extern void *func_02030734(u32 heap, u32 size, u32 align, const char *file,
                           u32 line);

void func_0204E130(u32 a)
{
    if (g_02146A78 == 0) {
        func_020461F4(a);
        g_02146A78 = func_02030734(0, 0x26, 0, func_0204E130_File, 51);
    }
}
