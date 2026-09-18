/*
 * function: func_0206A17C
 * address:  0x0206A17C
 * packet:   pkt_0206A12C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * blocker:  DIFF, 4 bytes: the original loads the word at +44 *after* the strh and reuses r2 for it; every spelling tried hoists the load above the strh and uses r3
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206A17C.c \
 *       --func func_0206A17C --addr 0x0206A17C --cc 1.1p1 --arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

u32 func_0206A17C(char *p)
{
    u32 r;

    *(u16 *)(p + 50) = (u16)(*(u16 *)(p + 50) & ~1);
    r = *(u32 *)(p + 44);
    *(u32 *)(p + 44) = 0;
    return r;
}
