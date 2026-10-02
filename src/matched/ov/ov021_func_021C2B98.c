/*
 * function: func_021C2B98
 * address:  0x021C2B98
 * packet:   pkt_ov021_021C2B98
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_0204E720  0x0204E720  arm
 *   func_0204E804  0x0204E804  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern void func_020124E4(void);
extern void *func_0201210C(void *p);
extern void func_0204E720(int, int, int, int);
extern int func_0204E804(void);

int func_021C2B98(void *a, u32 *p)
{
    func_020124E4();
    func_0201210C();
    switch (p[0]) {
    case 0:
        func_0204E720(3, 0x10, 0, 0);
        p[0]++;
        break;
    case 1:
        if (func_0204E804() == 0)
            return 1;
        break;
    }
    return 0;
}
