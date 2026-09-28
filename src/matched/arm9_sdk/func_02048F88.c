/*
 * function: func_02048F88
 * address:  0x02048F88
 * packet:   pkt_02048F4C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02048D54  0x02048D54  arm
 *
 * The five-argument entry point of the allocating load: a pure forwarder to
 * func_02048D54, with the caller's single stack argument copied down through
 * ip exactly as func_02048F74 does for func_02048D00.
 *
 * Kept in its own file so the branch to func_02048D54 is witnessed from
 * outside this range by src/matched/func_02048F60.c.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02048F88.c \
 *       --func func_02048F88 --addr 0x02048F88 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern void *func_02048D54(u32 archive_id, u32 member, u32 heap, u32 mode,
                           u32 *size_out);

void *func_02048F88(u32 archive_id, u32 member, u32 heap, u32 mode,
                    u32 *size_out)
{
    return func_02048D54(archive_id, member, heap, mode, size_out);
}
