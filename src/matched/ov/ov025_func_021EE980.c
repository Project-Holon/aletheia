/*
 * function: func_021EE980
 * address:  0x021EE980
 * packet:   pkt_ov025_021EE980
 * region:   ov025
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021EE980  0x021EE980  thumb  ov025
 *   func_021A2630  0x021A2630  thumb  ov021
 *   func_021A2638  0x021A2638  thumb  ov021
 *   func_021A2640  0x021A2640  thumb  ov021
 *   func_021A2654  0x021A2654  thumb  ov021
 *   func_021A21E0  0x021A21E0  thumb  ov021
 *   _u32_div_f  0x0209C2B0  arm
 *   d_021EF790  0x021EF790  data  ov025  a1
 */

typedef signed short s16;

typedef struct {
    s16 x;
    s16 y;
} Pt;

typedef unsigned int   u32;
extern unsigned char *func_021A2630(unsigned char *o);
extern unsigned int func_021A2638(unsigned char *o);
struct PtS;
extern void func_021A2640(unsigned char *, struct PtS *);
extern void func_021A2654(int obj, unsigned short *src);
extern void func_021A21E0(u32 *p);
extern signed char d_021EF790[];

void func_021EE980(int a)
{
    int *p;
    int s;
    int *q;
    Pt pt;

    p = (int *)func_021A2630((unsigned char *)a);
    func_021A2638((unsigned char *)a);
    s = p[8];
    q = (int *)p[7];
    if (s == 0) {
        if (*q != 0) {
            p[8] = s + 1;
        }
    } else {
        p[9] = p[9] - 1;
        if (p[9] < 0) {
            func_021A21E0((u32 *)a);
            return;
        }
    }
    func_021A2640((unsigned char *)a, (struct PtS *)&pt);
    pt.x = pt.x + d_021EF790[p[5]];
    if (p[4] > p[3]) {
        pt.y = pt.y + 1;
        p[4] = p[4] % p[3];
    }
    func_021A2654(a, (short unsigned int *)(&pt));
    p[4] = p[4] + 8;
    p[5] = (unsigned)(p[5] + 1) % 337u;
    if ((pt.y < -284 && pt.y > -296) || (pt.y > 212 && pt.y < 232)) {
        *(int *)p[0] = 1;
        func_021A21E0((u32 *)a);
    }
}
