/*
 * function: func_02068E78
 * address:  0x02068E78
 * packet:   pkt_02068808
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * blocker:  DIFF, 40 bytes compiled against 40: mwccarm pushes {r4,lr} and merges two adjacent stores into an stm; the original is a frameless leaf with nine separate stores. Four statement orders tried, all merge
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02068E78.c \
 *       --func func_02068E78 --addr 0x02068E78 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

/* r0=p, then four register args; the three stack words at [sp+0], [sp+4],
 * [sp+8] are arguments 5, 6 and 7.  Argument 6 lands at +20 and argument 7 at
 * +16, so the parameter order below is spelled to match the stores. */
void func_02068E78(char *p, u32 a1, u32 a2, u32 a3, unsigned char a5, u32 a6, u32 a7)
{
    *(u32 *)(p + 4) = a2;
    *(u32 *)(p + 8) = a3;
    *(unsigned char *)(p + 12) = a5;
    *(u32 *)p = a1;
    *(u32 *)(p + 20) = a6;
    *(u32 *)(p + 16) = a7;
}
