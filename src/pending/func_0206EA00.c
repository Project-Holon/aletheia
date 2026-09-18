/*
 * function: func_0206EA00
 * address:  0x0206EA00
 * packet:   pkt_0206E964
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * blocker:  DIFF, 40 compiled against 44: if-conversion wall - mwccarm predicates the 3-instruction body (and the shared `return 0`) for every spelling tried (two returns, goto, `||`, ternary, if/else); the original keeps both `beq`/`bcs` branches with the fail block last
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206EA00.c \
 *       --func func_0206EA00 --addr 0x0206EA00 --cc 1.1p1 --arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

unsigned char *func_0206EA00(unsigned char *p, u32 idx)
{
    if (p == 0)
        return 0;
    if (idx >= *(unsigned char *)(p + 6))
        return 0;
    return p + *(u16 *)(p + 8) + idx * 16;
}
