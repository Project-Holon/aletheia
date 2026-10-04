/*
 * function: func_021EEA04
 * address:  0x021EEA04
 * packet:   pkt_ov027_021EEA04
 * region:   ov027
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Twin of ov025 func_021EEE04: `extern const` tables read as `tbl[k]` at
 * each use in a plain for loop. Holding them in locals, hoisted by hand
 * behind an explicit guard, left the two pool loads split (9 bytes out);
 * see a-table-load-hoisted-past-the-loop-guard-names-a-const-extern-table.md.
 *
 * symbols:
 *   func_020056EC  0x020056EC  thumb
 *   func_0204B908  0x0204B908  arm
 *   func_021A21B8  0x021A21B8  thumb  ov021
 *   func_021A21C8  0x021A21C8  thumb  ov021
 *   func_021A2630  0x021A2630  thumb  ov021
 *   func_021A2638  0x021A2638  thumb  ov021
 *   func_021A2654  0x021A2654  thumb  ov021
 *   d_021EEB68     0x021EEB68  data  a4
 *   d_021EEB48     0x021EEB48  data  ov027  a4
 */

typedef unsigned short u16;
typedef signed short s16;

typedef unsigned int   u32;
extern u32 func_020056EC(u32 range);
extern void func_0204B908(int a, u16 b);
extern int *func_021A21B8(int *p);
extern int func_021A21C8(int, int);
extern unsigned char *func_021A2630(unsigned char *o);
extern unsigned int func_021A2638(unsigned char *o);
extern void func_021A2654(int, s16 *);
extern const int d_021EEB68[];
extern const int d_021EEB48[];

void func_021EEA04(int a, int n, int idx)
{
    int *w;
    int k;
    int i;
    int q;
    int obj;
    int *e;
    int s;
    s16 pt[2];

    w = func_021A21B8((int *)a);
    w[1] = (w[1] + 1) % 320;
    k = w[1] / 40;
    for (i = 0; i < n; i++) {
        obj = func_021A21C8(a, idx);
        if (obj == 0) {
            return;
        }
        e = (int *)func_021A2630((unsigned char *)obj);
        q = func_021A2638((unsigned char *)obj);
        e[0] = 0;
        e[1] = func_020056EC(20) + 15;
        s = 3 - (e[1] - 15) / 6;
        e[2] = (s + 1) * d_021EEB68[k];
        e[4] = (s + 1) * d_021EEB48[k];
        e[3] = 0;
        e[5] = d_021EEB48[k];
        if (func_020056EC(1000) == 777) {
            s = 4;
            e[2] = e[2] + e[2] / 2;
        }
        func_0204B908(q, s);
        pt[0] = -6 - func_020056EC(24);
        pt[1] = func_020056EC(192) - 64;
        func_021A2654(obj, pt);
    }
}
