/*
 * function: func_021EA064
 * address:  0x021EA064
 * packet:   pkt_ov170_021EA064
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021ECB84 0x021ECB84 thumb
 *   func_021EC768 0x021EC768 thumb
 *   func_021ED594 0x021ED594 thumb
 *   func_021EE038 0x021EE038 thumb
 *   func_021EA1C0 0x021EA1C0 thumb
 *   func_021E8FC0 0x021E8FC0 thumb
 *   func_021DFA30 0x021DFA30 thumb
 */
#include "../include/Obj00000.h"


extern void func_021ECB84(char *w, unsigned i);
extern void func_021EC768(char *p, unsigned i, int flag);
extern void func_021ED594(unsigned char *p, unsigned i);
extern void func_021EE038(unsigned char *p, int a, int b, int c);
extern void func_021EA1C0(void *p);
extern void func_021E8FC0(unsigned char *p, int (*cb)(unsigned char *), int n);
extern int func_021DFA30(unsigned char *p);

#define WORK(p) (*(char **)((p) + 0x2C))

void func_021EA064(unsigned char *p, int i, int v)
{
    p[0x17] = p[0x14];
    p[0x16] = i;
    *(int *)(WORK(p) + 0xA168) = i;
    func_021ECB84(WORK(p), p[0x16]);
    func_021EC768(WORK(p), 0x24, 0);
    func_021ED594(p, 0x24);
    func_021EE038(p, 2, 1, 2);
    func_021EA1C0(p);
    ((struct Obj00000 *)p)->f28 = v;
    p[0x1A] = 2;
    func_021E8FC0(p, func_021DFA30, 0x17);
}
