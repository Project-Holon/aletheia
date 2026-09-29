/*
 * function: func_02167080
 * address:  0x02167080
 * packet:   pkt_ov010_02167080
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02167154  0x02167154  thumb  ov010
 *   func_02167178  0x02167178  thumb  ov010
 *   func_021671DC  0x021671DC  thumb  ov010
 *   func_021671FC  0x021671FC  thumb  ov010
 *   func_0219077C  0x0219077C  thumb  ov021
 *   func_020362DC  0x020362DC  arm
 *   func_021672B4  0x021672B4  thumb  ov010
 *   func_021671EC  0x021671EC  thumb  ov010
 *   func_021671CC  0x021671CC  thumb  ov010
 *   func_02167168  0x02167168  thumb  ov010
 */

typedef unsigned int u32;

struct O {
    u32 pad[5];
    int f14;
};

extern void func_02167154(struct O *o);
extern void func_02167178(struct O *o);
extern void func_021671DC(struct O *o);
extern void func_021671FC(struct O *o);
extern int func_0219077C(int a);
extern u32 func_020362DC(void);
extern void func_021672B4(struct O *o);
extern void func_021671EC(struct O *o);
extern void func_021671CC(struct O *o);
extern void func_02167168(struct O *o);

int func_02167080(void *a, int *st, struct O *o)
{
    switch (*st) {
    case 0:
        func_02167154(o);
        func_02167178(o);
        func_021671DC(o);
        func_021671FC(o);
        *st = *st + 1;
        break;
    case 1:
        if (func_0219077C(o->f14) == 1)
            *st = *st + 1;
        break;
    case 2:
        if (func_020362DC() & 0xf3)
            *st = *st + 1;
        break;
    case 3:
        func_021672B4(o);
        func_021671EC(o);
        func_021671CC(o);
        func_02167168(o);
        return 1;
    }
    return 0;
}
