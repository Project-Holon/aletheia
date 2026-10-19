/*
 * function: GFL_NET_IsWifiGameKind
 * address:  0x0200F300
 * packet:   pkt_0200F17C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GFL_NET_GetGameKind  0x0203D5D4  arm
 *
 * A membership test on GFL_NET_GetGameKind()'s result: true for a scattered set
 * of values (12-16, 28, 31, 37, 38, 48), false otherwise. The compiler
 * lowers the contiguous 12-16 run as a dense jump table (see
 * docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md), all five
 * entries landing on the same "return 1", and the rest as compare chains.
 * GFL_NET_GetGameKind has to be declared returning a signed int: an unsigned
 * return type turns every one of the range tests into an unsigned
 * compare (bhi/bhs instead of bgt/bge), which is the only thing that
 * differed on the first attempt.
 *
 * EXACT* because the 74 compiled bytes fall two short of the disasm.py
 * extent: a "movs r0, r0" alignment filler before the next label, the
 * ordinary inter-function padding, not a byte difference.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_IsWifiGameKind.c \
 *       --func GFL_NET_IsWifiGameKind --addr 0x0200F300 --cc 1.1p1
 */

extern int GFL_NET_GetGameKind(void);

int GFL_NET_IsWifiGameKind(void)
{
    switch (GFL_NET_GetGameKind()) {
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 28:
    case 31:
    case 37:
    case 38:
    case 48:
        return 1;
    default:
        return 0;
    }
}
