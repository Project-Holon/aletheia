/*
 * function: func_021E9FA8
 * address:  0x021E9FA8
 * packet:   pkt_ov170_021E9FA8
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
 *   func_0201AB28 0x0201AB28 thumb
 *   func_021EA1C0 0x021EA1C0 thumb
 *   func_021EE038 0x021EE038 thumb
 *   func_021EBA5C 0x021EBA5C thumb
 *   func_021DD14C 0x021DD14C thumb
 *   func_021ECB20 0x021ECB20 thumb
 *   func_021ECB60 0x021ECB60 thumb
 *   func_021E8FC0 0x021E8FC0 thumb
 *   func_021E0200 0x021E0200 thumb
 */

extern void func_021EC768(char *w, unsigned i, int flag);
extern void func_021ECB84(char *w, unsigned i);
extern void func_021ED594(unsigned char *p, unsigned i);
extern void *func_0201AB28(void *party, unsigned i);
extern void func_021EA1C0(unsigned char *p);
extern void func_021EE038(unsigned char *p, int a, int b, int c);
extern void func_021EBA5C(char *w, int v);
extern void func_021DD14C(unsigned char *p);
extern void func_021ECB20(unsigned char *p, int f, int c);
extern void func_021ECB60(char *w, int i, int f);
extern void func_021E8FC0(unsigned char *p, int (*cb)(unsigned char *), int n);
extern int func_021E0200(unsigned char *p);

#define WORK(p) (*(char **)((p) + 0x2C))

void func_021E9FA8(unsigned char *p, unsigned char i)
{
    p[0x16] = i;
    func_021EC768(WORK(p), p[0x16], 0);
    func_021ECB84(WORK(p), p[0x16]);
    func_021ED594(p, 0x24);
    func_021ECB20(p, 2, 1);
    func_021ECB60(WORK(p), 0x24, 0);
    func_0201AB28(*(void **)(*(char **)p + 8), i - 0x1E);
    func_021EA1C0(p);
    func_021EE038(p, 2, 2, 1);
    func_021EBA5C(WORK(p), 0x18);
    func_021DD14C(p);
    p[0x1A] = 1;
    func_021E8FC0(p, func_021E0200, 0x38);
}
