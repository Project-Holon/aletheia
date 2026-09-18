/*
 * function: func_0206EA2C
 * address:  0x0206EA2C
 * packet:   pkt_0206E9A4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * blocker:  DIFF, same if-conversion wall as func_0206EA00 (its +7/+10 twin)
 *
 * The 16-byte-stride sibling of func_0206EA00, counting with the byte at +7
 * and the halfword at +10.
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206EA2C.c \
 *       --func func_0206EA2C --addr 0x0206EA2C --cc 1.1p1 --arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

unsigned char *func_0206EA2C(unsigned char *p, u32 idx)
{
    if (p == 0)
        return 0;
    if (idx >= *(unsigned char *)(p + 7))
        return 0;
    return p + *(u16 *)(p + 10) + idx * 16;
}
