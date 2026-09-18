/*
 * function: func_0206B780
 * address:  0x0206B780
 * packet:   pkt_0206AF08
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * blocker:  DIFF, 3 bytes: the function pointer lands in r1 in the original (`blx r1`), in r0 in every spelling tried (pointer local, split declaration/assignment, struct member, assignment-in-condition, u32 cast)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206B780.c \
 *       --func func_0206B780 --addr 0x0206B780 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

void func_0206B780(char *p)
{
    int (*fn)(void) = *(int (**)(void))(p + 12);

    if (fn != 0)
        fn();
    *(u32 *)p += 1;
}
