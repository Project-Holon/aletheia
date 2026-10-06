/*
 * function: func_0217F36C
 * address:  0x0217F36C
 * packet:   pkt_ov018_0217F36C
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0217F3E4  0x0217F3E4  thumb
 *   func_02190F64  0x02190F64  thumb  ov021
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

void func_0217F3E4(Ov018Obj *p);
typedef unsigned int   u32;
struct Fx;
struct Obj2;
struct Obj2 *func_02190F64(struct Fx *a, u32 b);

void func_0217F36C(Ov018Obj *p)
{
    if (p->f18 != 0) {
        if (p->f28 == 1) {
            func_0217F3E4(p);
        }
    } else {
        p->f18 = func_02190F64(p->f24, (u32)p->f0C);
    }
}
