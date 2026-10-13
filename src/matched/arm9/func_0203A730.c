/*
 * function: GFL_NET_COMMAND_GetCommandWork
 * address:  0x0203A730
 * packet:   pkt_0203A574
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_COMMAND_GetCommandTable  0x0203A67C  arm
 *
 * The null-tolerant third word of the object GFL_NET_COMMAND_GetCommandTable caches: the
 * conditional `ldrne` / `moveq` pair is exactly the `? :` form, not an
 * if/return, which would have needed a second epilogue.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_COMMAND_GetCommandWork.c \
 *       --func GFL_NET_COMMAND_GetCommandWork --addr 0x0203A730 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

struct BaseTable;
extern struct BaseTable *GFL_NET_COMMAND_GetCommandTable(u32 cmd);

u32 GFL_NET_COMMAND_GetCommandWork(u32 cmd)
{
    u32 *p = (u32 *)GFL_NET_COMMAND_GetCommandTable(cmd);

    return p != 0 ? p[2] : 0;
}
