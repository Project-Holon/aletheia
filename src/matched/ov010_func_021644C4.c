/*
 * function: func_021644C4
 * address:  0x021644C4
 * packet:   pkt_ov010_021644C4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Calls entry i of the handler table at 0x021714DC, or returns 1 when the
 * slot is empty.
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_020127A4  0x020127A4  thumb
 *   d_021714DC     0x021714DC  data
 */

typedef unsigned int u32;
typedef int (*Handler)(void *sys, void *b, void *save);

extern void *func_020120F4(void *p);
extern void *func_020127A4(void *p);
extern Handler d_021714DC[];

int func_021644C4(int i, void *a, void *b)
{
    void *sys;
    void *save;
    Handler fn;

    sys = func_020120F4(a);
    save = func_020127A4(sys);
    fn = d_021714DC[i];
    if (fn == 0)
        return 1;
    return fn(sys, b, save);
}
