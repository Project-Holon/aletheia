/*
 * function: func_021F3734
 * address:  0x021F3734
 * packet:   pkt_ov053_021F3734
 * region:   ov053
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Blocker: site +0008 (func_021897BC) has no ARM9 func_ label (unlabelled
 * leaf) and only overlapping-overlay code; needs a function_starts seed.
 * Site +0030 (func_021C4DA8) now resolves with the ov021 hint below.
 * Every other byte is right.
 *
 * symbols:
 *   func_021897BC  0x021897BC  thumb
 *   func_0202B914  0x0202B914  thumb
 *   func_02005F24  0x02005F24  thumb
 *   func_021F39D0  0x021F39D0  thumb  ov053
 *   func_021C4DA8  0x021C4DA8  thumb  ov021
 *   func_021897A0  0x021897A0  thumb
 */

extern void *func_021897BC(int, int);
extern void func_0202B914(int, int);
extern void func_02005F24(int, int);
extern void func_021F39D0(void *, int);
extern void func_021C4DA8(int);
extern void func_021897A0(int, int);

void func_021F3734(int a)
{
    int i;
    char *p = (char *)func_021897BC(a, 0);
    func_0202B914(*(int *)(p + 4), 0);
    func_02005F24(*(unsigned short *)(p + 0x58), 0);
    func_021F39D0(p, a);
    for (i = 0; i < 5; i++)
        func_021C4DA8(*(int *)(p + i * 4 + 8));
    func_021897A0(a, 0);
}
