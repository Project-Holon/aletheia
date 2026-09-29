/*
 * function: func_021A7B20
 * address:  0x021A7B20
 * packet:   pkt_ov021_021A7B20
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02012A30  0x02012A30  thumb
 *   func_021A80FC  0x021A80FC  thumb  ov021
 *   func_021BDC94  0x021BDC94  thumb  ov021
 *   func_021A810C  0x021A810C  thumb  ov021
 *   func_021A8214  0x021A8214  thumb  ov021
 *   func_021A7B88  0x021A7B88  thumb  ov021
 *   func_021A7CE8  0x021A7CE8  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Work {
    void *f00;
    void *f04;
    void *f08;
    void *f0C;
    int f10;
    int f14;
    u16 f18;
    u8 f1A;
    u8 pad1B[0x28 - 0x1B];
    int f28;
    u8 pad2C[0x36 - 0x2C];
    u8 f36;
} Work;

typedef struct Args {
    void *f00;
    void *f04;
    void *f08;
    void *f0C;
    void *f10;
    void *f14;
} Args;

extern void *func_020122C0(void *a, int b, void *cb, int size);
extern Work *func_020124E8(void *task);
extern void *func_02012A30(void *p);
extern u8 func_021A80FC(void *p);
extern void *func_021BDC94(void *p);
extern void func_021A810C(void *p, void *q);
extern void func_021A8214(Work *w);
extern void func_021A7B88(Work *w);
extern void func_021A7CE8(void);

void *func_021A7B20(Args *a)
{
    void *task;
    Work *w;

    task = func_020122C0(a->f04, 0, func_021A7CE8, 0x3C);
    w = func_020124E8(task);
    w->f00 = a;
    w->f04 = func_02012A30(a->f08);
    w->f28 = 0;
    w->f18 = 0;
    w->f1A = func_021A80FC(a->f0C);
    w->f36 = 0;
    w->f08 = func_021BDC94(a->f0C);
    w->f0C = a->f14;
    w->f10 = 1;
    w->f14 = 0;
    func_021A810C(a->f0C, (u8 *)w + 0x1C);
    func_021A8214(w);
    func_021A7B88(w);
    return task;
}
