/*
 * unit:     no
 * function: func_02091C40
 * address:  0x02091C40
 * packet:   pkt_02091C40
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   __tolower_map  0x020A60DC  data
 *
 * Bounded case-insensitive string compare (the `strncmp` twin of
 * src/matched/stricmp.c, which is the unbounded `strcmp`): each byte is
 * mapped through the 256-byte table at 0x020A60DC when it is below 0x80, then
 * compared as unsigned, for at most n bytes.
 *
 * Three spellings are load-bearing, and docs/notes/pkt_02091C40.c.txt records
 * a whole earlier pass that got the first two but not the third:
 *
 *  - the guard is `if (n > 0) { <loop> } return 0;`, not `if (n <= 0)
 *    return 0;`.  The early-return spelling predicates the guard
 *    (`movle r0,#0` / `pople`) and is 128 bytes; the block spelling branches
 *    to the single shared epilogue the image has at 0x02091CB0.
 *  - the two byte temps are the interleaved `int c1; u8 m1; int c2; u8 m2;`
 *    of the sibling, which is what colours the masked c1 into r4 and the raw
 *    c2 into r5.  Declaring the two masks together swaps those registers.
 *    Writing the masks as `c1 &= 0xff` on the `int`s instead (the earlier
 *    pass's spelling) leaves the same 26-byte register swap that note
 *    describes: lr/ip carry the loop counter and the table there, r4/ip here.
 *  - THE TABLE BASE IS ASSIGNED INSIDE THE GUARD.  `const u8 *tab =
 *    __tolower_map;` at the top of the function hoists its pool load above the
 *    `ble`, which is the last 12-byte residue: the image emits
 *    `mov lr,#0 / ble / ldr ip,[pc,#0x60]`, i.e. the table is not loaded at
 *    all on the n <= 0 path.  Declaring it at the top and assigning it in
 *    the block reproduces that order exactly.
 *
 * Also measured by the earlier pass, and still true: mwccarm 1.1p1 in
 * `-lang c99` mode REJECTS a C99 for-statement declaration
 * (`for (int i = 0; ...)` -> "expression syntax error"), so the counter is
 * declared at block scope.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02091C40.c \
 *       --func func_02091C40 --addr 0x02091C40 --arm --cc 1.1p1
 */

typedef unsigned char u8;

extern const u8 __tolower_map[];

int func_02091C40(const u8 *s1, const u8 *s2, int n)
{
    const u8 *tab;
    int i = 0;
    int c1;
    u8 m1;
    int c2;
    u8 m2;

    if (n > 0)
    {
        tab = __tolower_map;
        do
        {
            c1 = *s1++;
            if (c1 >= 0 && c1 < 0x80)
                c1 = tab[c1];
            m1 = (u8)c1;

            c2 = *s2++;
            if (c2 >= 0 && c2 < 0x80)
                c2 = tab[c2];
            m2 = (u8)c2;

            if (m1 < m2)
                return -1;
            if (m1 > m2)
                return 1;
            if (m1 == 0)
                return 0;
            i++;
        } while (i < n);
    }
    return 0;
}
