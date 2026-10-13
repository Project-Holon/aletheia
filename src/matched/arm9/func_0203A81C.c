/*
 * function: GFL_NET_COMMAND_GetHugeBuffer
 * address:  0x0203A81C
 * packet:   pkt_0203A81C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * symbols:
 *   GFL_NET_COMMAND_GetSizeFunc  0x0203A748  arm
 *   GFL_NET_COMMAND_GetCommandWork  0x0203A730  arm
 *
 * Indirect dispatch: the first argument names a slot whose function pointer
 * comes back from GFL_NET_COMMAND_GetSizeFunc; a null slot answers 0 with the conditional
 * `moveq`/`popeq` pair, and otherwise the pointer is called with the second
 * argument, the current value GFL_NET_COMMAND_GetCommandWork reports and the third argument.
 * GFL_NET_COMMAND_GetCommandWork's own body ignores its parameter, but the caller still loads
 * one, so the source declares it with a parameter.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_COMMAND_GetHugeBuffer.c \
 *       --func GFL_NET_COMMAND_GetHugeBuffer --addr 0x0203A81C --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern int GFL_NET_COMMAND_GetSizeFunc(u32 idx);
extern u32  GFL_NET_COMMAND_GetCommandWork(u32 a0);

u32 GFL_NET_COMMAND_GetHugeBuffer(u32 a0, u32 a1, u32 a2)
{
    u32 (*f)(u32, u32, u32) = (u32 (*)(u32, u32, u32))GFL_NET_COMMAND_GetSizeFunc(a0);

    if (f == 0)
        return 0;
    return f(a1, GFL_NET_COMMAND_GetCommandWork(a0), a2);
}
