/*
 * function: func_020221A4
 * address:  0x020221A4
 * packet:   pkt_02022174
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * "Is the dual-screen text cluster idle?", the image's most-called predicate
 * on this object (fan-in 111, mostly from overlay script code): it reports 1
 * when the live counter at +0x14C is zero.  It is a leaf that saves no lr, so
 * disasm.py never labels it and it prints as an anonymous run between two
 * literal pools; see
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * It deliberately does not share a file with func_02022174 above it: a unit
 * records only its start address, and this address has 111 call sites that
 * need a manifest entry here.
 *
 * symbols:
 *   g_021467A4  0x021467A4  data
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020221A4.c \
 *       --func func_020221A4 --addr 0x020221A4 --cc 1.1p1 --thumb
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct G {
    u8  pad00[0x14C];
    u16 f14C;
};

extern struct G g_021467A4;

u32 func_020221A4(void)
{
    if (g_021467A4.f14C == 0)
        return 1;
    return 0;
}
