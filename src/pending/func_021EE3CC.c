/*
 * function: func_021EE3CC
 * address:  0x021EE3CC
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocker:  02025D14
 *
 * symbols:
 *
 * Run and clear the +0x2c/+0x70 handle when it is present.
 *
 * MATCH, not EXACT: the only call site is `bl 0x02025D14` and that address has
 * no witness in the image outside this function (match.py: "unresolved:
 * 02025D14 ... has no witness").  Its sibling func_021DD238, which calls
 * 0x020260F0/0x020260F4, is EXACT, and its first call is a blx to a global
 * that does resolve.  All 24 bytes reproduce.
 */

extern void func_02025D14(void *);

void func_021EE3CC(char *p)
{
    if (*(void **)(*(char **)(p + 0x2c) + 0x70) != 0) {
        func_02025D14(*(void **)(*(char **)(p + 0x2c) + 0x70));
        *(int *)(*(char **)(p + 0x2c) + 0x70) = 0;
    }
}
