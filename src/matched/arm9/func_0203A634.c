/*
 * function: GFL_NET_COMMAND_GetHeaderSize
 * address:  0x0203A634
 * packet:   pkt_0203A574
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_SYSTEM_GetCurrentAid  0x02039338  arm
 *
 * Bit test against a channel mask: 0xFF is always live, otherwise the bit of
 * the argument named by the index GFL_NET_SYSTEM_GetCurrentAid() reports decides, and a zero
 * index falls back to the 0x80 bit.  `1 << f()` is emitted as the shifted
 * register of a `tst`, and each success path is the conditional
 * `movne r0, #1` / `popne` pair, so the source is the return chain above a
 * final plain `return 0;`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_COMMAND_GetHeaderSize.c \
 *       --func GFL_NET_COMMAND_GetHeaderSize --addr 0x0203A634 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

typedef unsigned short u16;
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);

u32 GFL_NET_COMMAND_GetHeaderSize(u32 a0)
{
    if (a0 == 0xFF)
        return 1;
    if (a0 & (1 << GFL_NET_SYSTEM_GetCurrentAid()))
        return 1;
    if (GFL_NET_SYSTEM_GetCurrentAid() == 0 && (a0 & 0x80) != 0)
        return 1;
    return 0;
}
