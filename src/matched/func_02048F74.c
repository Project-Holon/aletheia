/*
 * function: func_02048F74
 * address:  0x02048F74
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
 * The five-argument entry point of the same read: a pure forwarder to
 * func_02048D00 that copies the caller's one stack argument down into its own
 * outgoing stack area (`ldr ip, [sp, #8]` reads it across the two words this
 * function pushed) and leaves r0-r3 untouched.
 *
 * Kept in its own file so the branch to func_02048D00 is witnessed from
 * outside this range by src/matched/func_02048F4C.c.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02048F74.c \
 *       --func func_02048F74 --addr 0x02048F74 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern void func_02048D00(void *dst, u32 archive_id, u32 member, u32 mode,
                          u32 *size_out);

void func_02048F74(void *dst, u32 archive_id, u32 member, u32 mode,
                   u32 *size_out)
{
    func_02048D00(dst, archive_id, member, mode, size_out);
}
