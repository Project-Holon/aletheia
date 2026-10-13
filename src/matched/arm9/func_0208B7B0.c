/*
 * function: MICEXi_GetLimitedSamplingCallback
 * address:  0x0208B7B0
 * packet:   pkt_0208B7B0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Unlabelled 12-byte ARM pointer thunk in a .word run:
 *   ldr r0, [pc, #0]; bx lr; .word func_02152FE4
 * It is not one of the two linker-veneer encodings the `veneer` class
 * recognises (it loads r0 and returns through lr rather than branching through
 * ip/pc), so only a `matched` entry can witness it.  Matching it lets the two
 * TWL parks src/pending/MICEXi_StartLimitedSamplingAsync.c and src/pending/MICEXi_StopLimitedSamplingAsync.c
 * resolve their `bl` sites.  The pointer word resolves `literal x1` against
 * the duplicate 0x02152FE4 word at 0x0208B7AC.
 *
 * symbols:
 *   func_02152FE4  0x02152FE4  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern void func_02152FE4(void);

void *MICEXi_GetLimitedSamplingCallback(void)
{
    return (void *)func_02152FE4;
}
