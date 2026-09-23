/*
 * function: func_02040EC0
 * address:  0x02040EC0
 * packet:   pkt_02040EC0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * symbols:
 *   func_02040E78  0x02040E78  arm
 *
 * STATUS CORRECTED 2026-09-21: this header read "status: EXACT" but the file
 * has never compiled to EXACT.  As written below it is DIFF, 44 bytes against
 * an original of 32, 37 concrete bytes out: taking the address of the
 * parameter a0 forces the "push {r0, r1, r2, r3}" home-area prologue
 * (docs/idioms/address-of-a-register-parameter-is-a-push-of-all-four.md),
 * which the original does NOT have.  Left in src/pending as DIFF rather than
 * promoted; it must not be filed to src/matched on the strength of the old
 * status line.
 *
 * BEST SHAPE FOUND (32 bytes, exact size, 21 concrete bytes out):
 *
 *     void func_02040EC0(u32 a0, u32 a1, u32 a2, u32 a3)
 *     {
 *         u32 v[4];
 *         func_02040E78(a0, &v[3], 2, 0);
 *     }
 *
 * That reproduces the size and the trailing "add sp, sp, #0x10" exactly.
 * The two residues are: the original has NO "sub sp, sp, #0x10" (its 16-byte
 * frame comes from the caller, which is the varargs home area), and it
 * returns with "pop {r3, lr}" + "bx lr" rather than "pop {r3, pc}".
 * Both say this is a VARARGS function whose va_list is built over the
 * caller's home area.  mwccarm dsi/1.1p1 ships no stdarg.h in this tree, and
 * a hand-rolled va_list (char * into &a0 + 4) goes the wrong way, 52 bytes
 * with the home-area push back.  Blocker: no way found to spell "frame comes
 * from the caller" without also taking an address that triggers the push.
 *
 * 2026-09-23 wave 15: these bytes are already EXACT from the real entry
 * 0x02040EBC (src/matched/unit_02040E78.c member sub_02040EBC, and
 * src/matched/func_02040EBC.c, shard pkt_02040DA8).  0x02040EC0 is four
 * bytes into that function; no C can start there.  The open worklist row is
 * a listing-label artefact for the integrator, not decompilation work.
 */

typedef unsigned int u32;

extern void func_02040E78(u32 a0, u32 *out, u32 a2, u32 a3);

void func_02040EC0(u32 a0, ...)
{
    func_02040E78(a0, (u32 *)((char *)&a0 + 0xc), 2, 0);
}
