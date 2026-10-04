/*
 * function: func_021E9EC0
 * address:  0x021E9EC0
 * packet:   pkt_ov170_021E9EC0
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
 *   func_021EF68C 0x021EF68C thumb
 *   func_021E8FC0 0x021E8FC0 thumb
 *   func_021DF484 0x021DF484 thumb
 */
#include "../include/Obj00000.h"
#include "../include/Obj23952.h"

extern void func_021EC768(char *w, unsigned i, int flag);
extern void func_021ECB84(char *w, unsigned i);
extern void func_021ED594(unsigned char *p, unsigned i);
extern void *func_0201AB28(void *party, unsigned i);
extern void func_021EA1C0(void *p);
extern void func_021EE038(unsigned char *p, int a, int b, int c);
extern void func_021EBA5C(char *w, int v);
extern void func_021DD14C(unsigned char *p);
extern void func_021EF68C(char *w);
extern void func_021E8FC0(unsigned char *p, int (*cb)(unsigned char *), int n);
extern int func_021DF484(unsigned char *p);

typedef struct {
    unsigned char lo : 4;
    unsigned char hi : 4;
} Nib;

#define WORK(p) (*(char **)((p) + 0x2C))

void func_021E9EC0(unsigned char *p, unsigned char i)
{
    p[0x16] = i;
    ((Nib *)(p + 0x1C))->lo = 0;
    p[0x17] = p[0x14];
    p[0x1B] = 1;
    func_021EC768(WORK(p), p[0x16], 0);
    func_021ECB84(WORK(p), p[0x16]);
    func_021ED594(p, 0x24);
    func_0201AB28(((struct Obj23952 *)(*(char * *)&((struct Obj00000 *)p)->f0))->f8, i - 0x1E);
    func_021EA1C0(p);
    func_021EE038(p, 2, 2, 1);
    func_021EBA5C(WORK(p), 0x18);
    func_021DD14C(p);
    func_021EF68C(WORK(p));
    ((struct Obj00000 *)p)->f28 = 0x20;
    p[0x1A] = 1;
    func_021E8FC0(p, func_021DF484, 0x1E);
}
