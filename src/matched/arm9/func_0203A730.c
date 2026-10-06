/*
 * function: func_0203A730
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
 *   func_0203A67C  0x0203A67C  arm
 *
 * The null-tolerant third word of the object func_0203A67C caches: the
 * conditional `ldrne` / `moveq` pair is exactly the `? :` form, not an
 * if/return, which would have needed a second epilogue.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203A730.c \
 *       --func func_0203A730 --addr 0x0203A730 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

struct BaseTable;
extern struct BaseTable *func_0203A67C(u32 cmd);

u32 func_0203A730(u32 cmd)
{
    u32 *p = (u32 *)func_0203A67C(cmd);

    return p != 0 ? p[2] : 0;
}
