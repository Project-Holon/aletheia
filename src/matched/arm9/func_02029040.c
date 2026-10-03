/*
 * function: func_02029040
 * address:  0x02029040
 * packet:   pkt_02028FD0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * A Thumb `add pc, r0` switch on p->f1c with eight arms, the twin of
 * func_02028FE0 in the same packet.  Every callee takes the object pointer,
 * which is why the switch index lives in r1 and r0 keeps holding p.
 */

typedef unsigned int u32;

struct T {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
};

extern void func_02029344(void *obj, u32 value);
extern void func_02029354(struct T *p);
extern void func_02029364(struct T *p);
extern void func_0202938C(struct T *p);
extern void func_0202945C(struct T *p);

void func_02029040(struct T *p)
{
    switch (p->f1c) {
    case 0:
        break;
    case 1:
        func_02029354(p);
        break;
    case 2:
        func_0202938C(p);
        func_02029344(p, 3);
        break;
    case 3:
        func_0202938C(p);
        func_02029344(p, 5);
        break;
    case 4:
        func_0202938C(p);
        func_02029344(p, 6);
        break;
    case 5:
        if (p->f0c == p->f08) {
            func_02029354(p);
        } else {
            func_0202938C(p);
            func_02029344(p, 8);
        }
        break;
    case 6:
        if (p->f0c == p->f08) {
            func_02029354(p);
        } else {
            func_0202938C(p);
            func_02029344(p, 0xd);
        }
        break;
    case 7:
        if (p->f0c == p->f08) {
            func_02029354(p);
        } else {
            func_0202945C(p);
            func_02029344(p, 1);
            func_02029364(p);
        }
        break;
    }
}
