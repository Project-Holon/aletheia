/*
 * function: func_02173420
 * address:  0x02173420
 * packet:   pkt_ov012_02173420
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   func_02183BE0  0x02183BE0  thumb  ov022
 *   func_0217505C  0x0217505C  thumb  ov012
 */

typedef unsigned char u8;

typedef struct {
    struct { int pad[3]; int f0c; } *head;
    u8 pad[0x3528 - 4];
    void *f3528;
    u8 pad2[0x3534 - 0x352C];
    void *f3534;
    void *f3538;
    void *f353C;
    void *f3540;
    void *f3544;
    u8 pad3[0x355C - 0x3548];
    void *f355C;
} Work;

extern void func_020307B0(void *p);
extern void func_02183BE0(void *p);
extern void func_0217505C(int *p, int x);

void func_02173420(Work *w)
{
    w->f353C = 0;
    if (w->f3540 != 0) {
        func_020307B0(w->f3540);
        w->f3540 = 0;
    }
    if (w->f3544 != 0) {
        func_020307B0(w->f3544);
        w->f3544 = 0;
    }
    if (w->f3538 != 0) {
        func_020307B0(w->f3538);
        w->f3538 = 0;
    }
    if (w->f3534 != 0) {
        func_020307B0(w->f3534);
        w->f3534 = 0;
    }
    if (w->f3528 != 0) {
        func_02183BE0(w->f3528);
        w->f3528 = 0;
    }
    if (w->f355C != 0) {
        func_0217505C(w->f355C, w->head->f0c);
        w->f355C = 0;
    }
}
