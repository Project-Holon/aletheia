/*
 * function: func_021EEA34
 * address:  0x021EEA34
 * packet:   pkt_ov025_021EEA34
 * region:   ov025
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_020056EC  0x020056EC  thumb
 *   func_0204B908  0x0204B908  arm
 *   func_021A21B8  0x021A21B8  thumb  ov021
 *   func_021A21C8  0x021A21C8  thumb  ov021
 *   func_021A2630  0x021A2630  thumb  ov021
 *   func_021A2638  0x021A2638  thumb  ov021
 *   func_021A2654  0x021A2654  thumb  ov021
 */

typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

typedef struct {
    s16 x;
    s16 y;
} Pt;

extern u32 func_020056EC(u32 v);
extern void func_0204B908(int, u16);
extern int *func_021A21B8(int *p);
extern int func_021A21C8(int, int);
extern unsigned char *func_021A2630(unsigned char *o);
extern unsigned int func_021A2638(unsigned char *o);
extern void func_021A2654(int, Pt *);

void func_021EEA34(int a, int n, int idx)
{
    int *q;
    int i;
    int obj;
    int *e;
    int h;
    Pt pt;

    q = func_021A21B8((int *)a);
    for (i = 0; i < n; i++) {
        obj = func_021A21C8(a, idx);
        if (obj == 0) {
            return;
        }
        e = (int *)func_021A2630((unsigned char *)obj);
        h = func_021A2638((unsigned char *)obj);
        func_0204B908(h, func_020056EC(4));
        e[4] = 0;
        e[5] = 0;
        e[8] = 0;
        e[9] = (int)func_020056EC(0) % 30 + 2;
        e[3] = func_020056EC(8) + 12;
        e[0] = (int)(q + 1);
        e[7] = (int)(q + 2);
        pt.x = func_020056EC(0x19E) - 0x20;
        if (q[1] == 1 && i >= n / 2) {
            pt.y = -8 - 0x20 - func_020056EC(0x14);
        } else {
            pt.y = -8 - func_020056EC(0x14);
        }
        func_021A2654(obj, &pt);
    }
}
