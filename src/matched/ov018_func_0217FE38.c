/*
 * function: func_0217FE38
 * address:  0x0217FE38
 * packet:   pkt_ov018_0217FE38
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * note:     the call to 0x02175368 attests through src/matched/ov011_func_02175368.c
 *           (seeded in function_starts.txt). The star is the two bytes of
 *           alignment padding before func_0217FE6C, not a byte difference.
 * symbols:
 *   func_0217F4C4  0x0217F4C4  thumb
 *   func_0217F318  0x0217F318  thumb
 *   func_02174E14  0x02174E14  thumb  ov011
 *   func_0217538C  0x0217538C  thumb  ov011
 *   func_02175368  0x02175368  thumb  ov011
 */

typedef struct {
    void *f00;
    void *f04;
    void *f08;
    void *f0C;
    void *f10;
    void *f14;
    void *f18;
    void *f1C;
    void *f20;
    void *f24;
    unsigned char f28;
    unsigned char pad29[3];
    void *f2C;
} Ov018Obj;

typedef struct {
    unsigned char pad00[0x10];
    Ov018Obj obj;
} Ov018Outer;

void func_0217F4C4(Ov018Obj *p);
void func_0217F318(Ov018Obj *p);
void func_02174E14(void *, int);
void func_0217538C(void *, int);
void func_02175368(void *);

void func_0217FE38(void *v, Ov018Outer *c)
{
    func_0217F4C4(&c->obj);
    func_0217F318(&c->obj);
    if (v != 0) {
        func_02174E14(v, 0);
        func_0217538C(v, 4);
        func_02175368(v);
    }
}
