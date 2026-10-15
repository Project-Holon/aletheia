/*
 * function: gti2UnrecognizedMessageCallback
 * address:  0x021954F4
 * packet:   pkt_02156B70
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Bracket a call to the object's +0x30 hook with the +0x1c counter: clear the
 * caller's output word, zero the last two arguments when either is zero, bump
 * the counter, call the hook with all five arguments, store the result back
 * through the pointer, drop the counter and report whether the object still
 * has work outstanding.
 */

extern void func_02197FDC(char *p);

typedef int (*Hook)(char *p, int a1, int a2, int a3, int a4);

int gti2UnrecognizedMessageCallback(char *p, int a1, int a2, int a3, int a4, int *a5)
{
    int r;

    *a5 = 0;
    if (p == 0)
        return 1;
    if (*(int *)(p + 0x30) == 0)
        return 1;

    if (a4 == 0 || a3 == 0) {
        a3 = 0;
        a4 = 0;
    }

    *(int *)(p + 0x1c) += 1;
    r = (*(Hook *)(p + 0x30))(p, a1, a2, a3, a4);
    *a5 = r;

    *(int *)(p + 0x1c) -= 1;
    if (*(int *)(p + 0x14) != 0 && *(int *)(p + 0x1c) == 0) {
        func_02197FDC(p);
        return 0;
    }
    return 1;
}
