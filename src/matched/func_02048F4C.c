/*
 * function: func_02048F4C
 * address:  0x02048F4C
 * packet:   pkt_02048F4C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02048D00  0x02048D00  arm
 *
 * "Read one archive sub-file into a caller-supplied buffer", the defaulting
 * wrapper around func_02048D00.  func_02048D00 takes five arguments
 * (dst, archive id, member, mode, size_out); this entry point supplies zero
 * for the last two, which is why the body is a single `mov r3, #0` doing
 * double duty: the same zero reaches r3 (the fourth argument) and the one
 * word of outgoing stack area (the fifth).  The `push {r3, lr}` is the home
 * slot for that stack argument, not a saved register.
 *
 * func_02048D00 itself opens a temporary archive handle with func_02048DDC,
 * sizes the member with func_02048E34, reads it and closes the handle again.
 *
 * Kept in its own file so that the branch to func_02048D00 is witnessed from
 * outside this range by src/matched/func_02048F74.c, which calls the same
 * target (docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02048F4C.c \
 *       --func func_02048F4C --addr 0x02048F4C --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern void func_02048D00(void *dst, u32 archive_id, u32 member, u32 mode,
                          u32 *size_out);

void func_02048F4C(void *dst, u32 archive_id, u32 member)
{
    func_02048D00(dst, archive_id, member, 0, 0);
}
