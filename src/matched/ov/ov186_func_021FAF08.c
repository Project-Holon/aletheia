/*
 * function: func_021FAF08
 * address:  0x021FAF08
 * packet:   pkt_021FAF08
 * region:   ov186
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021FB7B0  0x021FB7B0  thumb  ov186
 *   func_021FB514  0x021FB514  thumb  ov186
 */

extern int func_021FB7B0(void *p, int i);
extern void func_021FB514(void *, short, int);

void func_021FAF08(char *p, int a1)
{
    short r = (short)func_021FB7B0((void *)(*(int *)(p + 0xc)), 0);

    func_021FB514(*(void **)(p + 8), r, a1);
}
