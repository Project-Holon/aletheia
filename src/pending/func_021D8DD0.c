/*
 * function: func_021D8DD0
 * address:  0x021D8DD0
 * packet:   pkt_021D8980
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF (parked)
 *
 * DIFF: tail of the function. The image issues bl 0x0201AB28 then bl 0x020185F4 and returns the second result; ours differs in the call sequence/argument setup. Blocking site: the 0x020185F4 tail call.
 *
 * Slot lookup with a callback fallback when the two indices disagree.
 *
 * symbols:
 *   (none)
 */

extern int func_02007A18(int a, int b, int c, void *p);
extern int func_0201AA18(int m);
extern void func_0201AB28(int m, int c);
extern int func_020185F4(void);

int func_021D8DD0(int a, int b, int c, char *p)
{
    int n, m;

    if (b == -1)
        return 0;
    n = *(int *)(p + 0x630);
    if (b > n)
        return 0;
    if (b != n && c != -1)
        return func_02007A18(a, b, c, p);
    m = *(int *)(p + 0x838);
    if (c >= func_0201AA18(m))
        return 0;
    if (c == -1)
        return 0;
    func_0201AB28(m, c);
    return func_020185F4();
}

