/*
 * function: func_02168BF0
 * address:  0x02168BF0
 * packet:   pkt_ov010_02168BF0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02012934  0x02012934  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200BAC8  0x0200BAC8  thumb
 *   func_0200BAF4  0x0200BAF4  thumb
 *   func_02168C74  0x02168C74  thumb ov010
 */

typedef unsigned int u32;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
    int f18;
    int f1c;
    u32 pad[4];
    int f30;
} R;

extern int func_020120F4(int);
extern int func_020122C0(int, int, void *, int);
extern R *func_020124E8(int);
extern int func_0201210C(int);
extern int func_02012934(int);
extern int func_02012EBC(int);
extern int func_0200BAC8(int);
extern int func_0200BAF4(int, int);
extern void func_02168C74(void);

int func_02168BF0(int a, int b, int c, int d, int e)
{
    int hd;
    int h;
    R *p;
    int v;
    h = func_020120F4(a);
    hd = func_020122C0(a, 0, func_02168C74, 0x34);
    p = func_020124E8(hd);
    p->f0 = a;
    p->f4 = func_0201210C(a);
    p->fc = e;
    p->f30 = b;
    if (c == 0x14 || c == 0x15) {
        if (c == 0x14) {
            p->f10 = 0;
            v = 0x14;
        } else {
            p->f10 = 1;
            v = 0x15;
        }
    } else {
        p->f10 = 0;
        v = 0x14;
    }
    p->f14 = v;
    if (d == 0) {
        p->f1c = 0;
        v = func_02012934(h);
    } else {
        v = func_0200BAF4(func_0200BAC8(func_02012EBC(h)), 5);
        p->f1c = v;
    }
    p->f18 = v;
    return hd;
}
