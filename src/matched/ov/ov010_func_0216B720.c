/*
 * function: func_0216B720
 * address:  0x0216B720
 * packet:   pkt_ov010_0216B720
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200E394  0x0200E394  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0200E4F8  0x0200E4F8  thumb
 *   func_0200E4B0  0x0200E4B0  thumb
 *   d_0217219C     0x0217219C  data  ov010  a1
 *   d_021721BC     0x021721BC  data  ov010  a1
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Big;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5E4(void *a0);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200E394(void *a0);
extern int func_02159B10();
extern u16 *func_02159AE8(void *a0, void *a1);
extern int func_0200E4F8();
extern int func_0200E4B0();
extern u8 d_0217219C[];
extern u8 d_021721BC[];

int func_0216B720(int c, int vm)
{
    int i;
    int r5;
    void *r6;
    int best;
    u16 *dst;
    int out;
    int n;

    func_0215A5F4((void *)vm);
    r6 = func_0200E394(func_02012EBC((struct Big *)func_0215A5E4((void *)vm)));
    r5 = func_02159B10(c, vm);
    dst = func_02159AE8((void *)c, (void *)vm);
    n = d_0217219C[r5];
    best = -1;
    for (i = 0; i < n; i++) {
        int a = func_0200E4F8(r6, r5, i + 1);
        int b = func_0200E4B0(r6, r5, i + 1);
        int s = a + b;
        if (best < s) {
            best = s;
            out = d_021721BC[r5 * 17 + i];
        }
    }
    *dst = out;
    return 0;
}
