/*
 * function: func_021EEA18
 * address:  0x021EEA18
 * packet:   pkt_ov026_021EEA18
 * region:   ov026
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021EEA18  0x021EEA18  thumb  ov026
 *   func_020056EC  0x020056EC  thumb
 *   _u32_div_f     0x0209C2B0  arm
 *   func_0204B908  0x0204B908  arm
 *   func_021A21B8  0x021A21B8  thumb  ov021
 *   func_021A21C8  0x021A21C8  thumb  ov021
 *   func_021A2630  0x021A2630  thumb  ov021
 *   func_021A2638  0x021A2638  thumb  ov021
 *   func_021A26C4  0x021A26C4  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

typedef struct {
    s16 x;
    s16 y;
} Pt;

extern u32 func_020056EC(u32 v);
extern void func_0204B908(int a0, int a1);
extern int *func_021A21B8(int *p);
extern void *func_021A21C8(void *p, int a1);
extern unsigned char *func_021A2630(unsigned char *o);
extern unsigned int func_021A2638(unsigned char *o);
extern int func_021A26C4(u32 a, u32 b);

void func_021EEA18(int a, int n, int idx)
{
    int i;
    int obj;
    int *e;
    int h;
    u32 r;
    u32 m;
    int k;
    Pt pt;

    func_021A21B8((int *)a);
    for (i = 0; i < n; i++) {
        obj = (int)func_021A21C8((void *)a, idx);
        if (obj == 0) {
            return;
        }
        e = (int *)func_021A2630((unsigned char *)obj);
        h = func_021A2638((unsigned char *)obj);
        r = func_020056EC(0);
        e[0] = 0;
        m = r % 3;
        func_0204B908(h, (u16)m);
        k = r % 20;
        e[2] = k + (m + 1) * 16;
        if (m == 2) {
            e[2] += 16;
        }
        e[4] = k / 8 + (m + 1) * 8;
        if (m == 2) {
            e[4] += 8;
        }
        e[3] = 0;
        e[1] = (r & 1) + 1;
        pt.x = (u8)r + (m * 15 - 0x48);
        pt.y = -0x60;
        func_021A26C4(obj, (u32)(&pt));
        e[4] = e[4] * 2;
        e[2] = e[2] * 2;
        e[5] = func_020056EC(10);
    }
}
