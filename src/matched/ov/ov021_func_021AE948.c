/*
 * function: func_021AE948
 * address:  0x021AE948
 * packet:   pkt_ov021_021AE948
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159124  0x02159124  thumb  ov010
 *   func_0215A5CC  0x0215A5CC  thumb  ov010
 *   func_021AE454  0x021AE454  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern void *func_0215A5F4(void *p);
typedef unsigned short u16;
extern int func_02158F58(int a0);
extern unsigned int func_02159B10(void *a0, void *a1);
extern char *func_02159124(char *p, int i);
extern u16 func_0215A5CC(void *a0);
extern u32 func_021AE454(void *a, u32 b, u32 *c, u32 d);

int func_021AE948(u32 a, u32 b)
{
    u32 k;
    void *p;
    u32 *q;
    u32 *e;

    p = func_0215A5F4((void *)b);
    q = (u32 *)func_02158F58((int)p);
    k = func_02159B10((void *)a, (void *)b);
    if (k == 0) {
        e = (u32 *)func_02159124(p, 0);
    } else if (k == 1) {
        e = (u32 *)func_02159124(p, 1);
    }
    e[6] = func_021AE454((void *)func_0215A5CC((void *)b), q[1], e, k);
    return 0;
}
