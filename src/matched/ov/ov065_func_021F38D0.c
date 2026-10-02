/*
 * function: func_021F38D0
 * address:  0x021F38D0
 * packet:   pkt_021F38D0
 * region:   ov065
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unblocked by matching the leaf at 0x021897BC in ov021 (region hint added
 * to the symbols line); the bl at +0x0E now resolves via `matched`.
 *
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_021897BC  0x021897BC  thumb
 */

extern void *func_020124E4(void *task);
extern int func_0201210C(void *p);
extern int *func_021897BC(int, int);

int func_021F38D0(void *task)
{
    int a;
    int r;
    a = func_0201210C(func_020124E4(task));
    r = 1;
    if (*func_021897BC(a, 1) != 0)
        r = 0;
    return r;
}
