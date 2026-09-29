/*
 * function: func_02172E48
 * address:  0x02172E48
 * packet:   pkt_ov012_02172E48
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02172D7C  0x02172D7C  thumb  ov012
 *   func_0203CD98  0x0203CD98  arm
 *   func_0217778C  0x0217778C  thumb  ov014
 *   func_021730C8  0x021730C8  thumb  ov012
 *   func_0217303C  0x0217303C  thumb  ov012
 *   func_02172FF0  0x02172FF0  thumb  ov012
 *   func_02172EEC  0x02172EEC  thumb  ov012
 *   func_0200FB24  0x0200FB24  thumb
 *   func_0203D378  0x0203D378  arm
 *   func_02172D38  0x02172D38  thumb  ov012
 */

typedef unsigned char u8;

typedef struct {
    u8 pad[0xC8];
    u8 f0 : 1;
    u8 f1 : 1;
} Obj;

typedef struct {
    u8 pad[0x2829];
    u8 f2829;
    u8 pad2[0x2831 - 0x282A];
    u8 f2831;
    u8 pad3[0x355C - 0x2832];
    Obj *obj;
} Work;

extern int func_02172D7C(Work *w);
extern int func_0203CD98(void);
extern void func_0217778C(void);
extern void func_021730C8(Work *w);
extern void func_0217303C(Work *w);
extern void func_02172FF0(Work *w);
extern void func_02172EEC(Work *w);
extern int func_0200FB24(void);
extern int func_0203D378(void);
extern void func_02172D38(Work *w);

void func_02172E48(int a, int b, Work *w)
{
    if (func_02172D7C(w) == 1) {
        return;
    }
    if (func_0203CD98() == 0) {
        return;
    }
    if (w->f2829 == 1) {
        func_0217778C();
        w->f2829 = 0;
    }
    func_021730C8(w);
    func_0217303C(w);
    func_02172FF0(w);
    func_02172EEC(w);
    if (func_0200FB24() != 0 && func_0203D378() == 1 && w->obj != 0
        && w->obj->f0 == 1 && w->f2831 == 0x2a && w->obj->f1 == 0) {
        func_02172D38(w);
        w->obj->f1 = 1;
    }
}
