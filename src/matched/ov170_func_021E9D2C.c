/*
 * function: func_021E9D2C
 * address:  0x021E9D2C
 * packet:   pkt_ov170_021E9D2C
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EC768 0x021EC768 thumb
 *   func_021ECB84 0x021ECB84 thumb
 *   func_021ED594 0x021ED594 thumb
 *   func_021EA1C0 0x021EA1C0 thumb
 *   func_021EE038 0x021EE038 thumb
 *   func_021EBA5C 0x021EBA5C thumb
 *   func_021DD14C 0x021DD14C thumb
 *   func_021EF670 0x021EF670 thumb
 *   func_021E8FC0 0x021E8FC0 thumb
 *   func_021DFA30 0x021DFA30 thumb
 */


typedef struct {
    unsigned char pad[0x14];
    unsigned char b14;
    unsigned char pad15;
    unsigned char b16;
    unsigned char b17;
    unsigned char pad18[2];
    unsigned char b1A;
    unsigned char b1B;
    unsigned char lo : 4;
    unsigned char hi : 4;
    unsigned char pad1D[0x28 - 0x1D];
    int next;
    char *work;
} Obj;

extern void func_021EC768(char *p, unsigned i, int flag);
extern void func_021ECB84(char *w, unsigned i);
extern void func_021ED594(Obj *p, unsigned i);
extern void func_021EA1C0(Obj *p);
extern void func_021EE038(Obj *p, int a, int b, int c);
extern void func_021EBA5C(char *w, int v);
extern void func_021DD14C(Obj *p);
extern void func_021EF670(char *w);
extern void func_021E8FC0(Obj *p, int (*cb)(Obj *), int n);
extern int func_021DFA30(Obj *p);

void func_021E9D2C(Obj *p, unsigned char i)
{
    p->b1B = 0;
    p->lo = 0;
    p->b16 = i;
    p->b17 = p->b14;
    func_021EC768(p->work, p->b16, 0);
    func_021ECB84(p->work, p->b16);
    func_021ED594(p, 0x24);
    func_021EA1C0(p);
    func_021EE038(p, 2, 2, 1);
    func_021EBA5C(p->work, 0x18);
    func_021DD14C(p);
    func_021EF670(p->work);
    p->next = 0x15;
    p->b1A = 0;
    func_021E8FC0(p, func_021DFA30, 0x12);
}
