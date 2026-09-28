/*
 * function: func_021EA514
 * address:  0x021EA514
 * packet:   pkt_ov170_021EA514
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EC0B0 0x021EC0B0 thumb
 *   func_021EC08C 0x021EC08C thumb
 *   func_021ED6E4 0x021ED6E4 thumb
 *   func_021EA4DC 0x021EA4DC thumb
 *   func_021DDE80 0x021DDE80 thumb
 *   func_021E8FC0 0x021E8FC0 thumb
 *   func_021E1458 0x021E1458 thumb
 */

typedef struct {
    unsigned char pad0[0x16];
    unsigned char b16;
    unsigned char pad17;
    unsigned char b18;
    unsigned char pad19[0x2C - 0x19];
    char *work;
} Obj;

extern void func_021EC0B0(char *p, int i, short *a, short *b, unsigned short space);
extern void func_021EC08C(char *p, int i, short a, short b, short c);
extern void func_021ED6E4(Obj *p, int v);
extern int func_021EA4DC(Obj *p);
extern int func_021DDE80(Obj *p, unsigned a, unsigned b);
extern int func_021E8FC0(Obj *p, int (*cb)(Obj *), int n);
extern int func_021E1458(Obj *p);

#define SEL(p) (*(unsigned char *)((p)->work + 0xA17E))

int func_021EA514(Obj *p, unsigned i)
{
    short t[2];
    SEL(p) = i;
    p->b18 = 0;
    func_021EC0B0(p->work, 4, &t[1], &t[0], 0);
    func_021EC08C(p->work, 10, t[1], t[0] + 8, 0);
    func_021ED6E4(p, 0);
    if (SEL(p) == 0xFF)
        return func_021EA4DC(p);
    if (func_021DDE80(p, p->b16, i) == 0)
        return func_021EA4DC(p);
    return func_021E8FC0(p, func_021E1458, 0x45);
}
