/*
 * function: func_0217F3A4
 * address:  0x0217F3A4
 * packet:   pkt_ov018_0217F3A4
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_0217F36C  0x0217F36C  thumb
 *   func_02190EB8  0x02190EB8  thumb  ov021
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

void func_0217F36C(Ov018Obj *p);
typedef unsigned short u16;
typedef unsigned int   u32;
struct P;
void func_02190EB8(struct P *p, u32 b, u16 c, u32 d);

void func_0217F3A4(Ov018Obj *p, void *a)
{
    func_0217F36C(p);
    func_02190EB8(p->f18, 0, 0, (u32)a);
    p->f28 = 1;
}
