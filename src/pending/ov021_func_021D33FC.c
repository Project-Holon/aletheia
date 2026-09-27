/*
 * function: func_021D33FC
 * address:  0x021D33FC
 * packet:   pkt_ov021_021D33FC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * Recursive MATCH unblocker attempt: non-SDK dep of the matched func_021D33A8
 * (its +0010 branch target in the field_palace_sys.c tree).  Every relocation
 * resolves (0x0215850C / 0x02158468 as EXACT ov010 `matched`, 0x021D3478 as
 * `sole-ref`), the size is exact, and the logic is recovered.  The 13-byte
 * residue is scheduling only: (a) the image spills a1/a2 ahead of the a0 copy
 * and the first `ldr [r5]`, mwcc loads first; (b) the image sets r1 = state
 * before the outgoing stack word and loads a1 after it.  Not promotable to
 * EXACT with this front end; needs a scheduler lever.
 *
 * symbols:
 *   func_02012138  0x02012138  thumb
 *   func_02013D74  0x02013D74  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_021D3554  0x021D3554  thumb  ov021
 *   func_0215850C  0x0215850C  thumb  ov010
 *   func_02158468  0x02158468  thumb  ov010
 *   func_021D3478  0x021D3478  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern void *func_02012138(void *);
extern int func_02013D74(int);
extern void *func_020120F4(void *);
extern int func_021D3554(void *, int);
extern int func_0215850C(int, void *);
extern int func_02158468(int);
extern void func_021D3478(void *, int, int, int, int);

void func_021D33FC(void *a0, int a1, int a2)
{
    int r6;
    int r7;
    void *r4;
    int t;
    int s;

    r6 = (int)func_02012138(*(void **)a0);
    if (func_02013D74(a1) != 1)
        return;
    if (r6 == 0)
        return;
    r4 = func_020120F4(*(void **)a0);
    r7 = func_021D3554(r4, a1);
    t = func_0215850C(r6, r4);
    s = 0xffff;
    if (t == 2) {
        if (r7 == 1)
            s = 1;
        else
            s = 0;
    } else if (t == 1) {
        if (r7 == 1)
            s = 3;
        else
            s = 2;
    }
    if (s == 0xffff)
        return;
    func_021D3478(a0, s, a1, func_02158468(r6), a2);
}
