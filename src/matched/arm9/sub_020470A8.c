/*
 * function: func_020470A8
 * address:  0x020470A8
 * packet:   pkt_02046EFC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02046FF8  0x02046FF8  arm
 *   func_02046FCC  0x02046FCC  arm
 *
 * "Build, then trim": run the builder at 0x02046FF8 over the tagged object
 * and, only if it reports success, shrink the buffer with 0x02046FCC.  The
 * zero return is predicated (`moveq`/`popeq`) rather than branched, which is
 * the whole body being two statements long.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020470A8.c \
 *       --func func_020470A8 --addr 0x020470A8 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern u32  func_02046FF8(void *p);
extern void func_02046FCC(void *p);

u32 func_020470A8(void *p)
{
    if (func_02046FF8(p) == 0) {
        return 0;
    }
    func_02046FCC(p);
    return 1;
}
