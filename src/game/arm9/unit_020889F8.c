/*
 * file:     unit_020889F8.c
 * function: RTCEXi_GetCommonCallback
 * address:  0x020889F8
 * packet:   pkt_020889F8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Unlabelled 12-byte ARM pointer thunk in a .word run:
 *   ldr r0, [pc, #0]; bx lr; .word func_0215142C
 * Same shape as MICEXi_GetLimitedSamplingCallback and, for the same reason, witnessable only as a
 * `matched` entry.  It unblocks the TWL park src/pending/RTCEXi_CommonCallback.c.
 * The pointer word resolves `literal x1` against the duplicate 0x0215142C
 * word at 0x02088EE8.
 *
 * symbols:
 *   func_0215142C  0x0215142C  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern void func_0215142C(void);

void *RTCEXi_GetCommonCallback(void)
{
    return (void *)func_0215142C;
}
