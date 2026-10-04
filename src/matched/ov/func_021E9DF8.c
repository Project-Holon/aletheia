/*
 * function: func_021E9DF8
 * address:  0x021E9DF8
 * packet:   pkt_021E9DF8
 * region:   ov170
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EC768  0x021EC768  thumb  ov170
 *   func_021ECB84  0x021ECB84  thumb  ov170
 *   func_021ED594  0x021ED594  thumb  ov170
 *   func_021ED888  0x021ED888  thumb  ov170
 *   func_021EC61C  0x021EC61C  thumb  ov170
 *   func_021ECB20  0x021ECB20  thumb  ov170
 *   func_021ECB60  0x021ECB60  thumb  ov170
 *   func_021EA1C0  0x021EA1C0  thumb  ov170
 *   func_021EE038  0x021EE038  thumb  ov170
 *   func_021EBA5C  0x021EBA5C  thumb  ov170
 *   func_021DD14C  0x021DD14C  thumb  ov170
 *   func_021E8FC0  0x021E8FC0  thumb  ov170
 *   func_021E0470  0x021E0470  thumb  ov170
 */
#include "../include/Obj00000.h"
typedef unsigned char u8;
typedef unsigned int u32;

extern void func_021EC768(char *p, unsigned i, int flag);
extern void func_021ECB84(char *w, unsigned i);
extern void func_021ED594(u8 *p, int a);
extern void func_021ED888(char *p, int a);
extern void func_021EC61C(u8 *p);
extern void func_021ECB20(u8 *p, int a, int b);
extern void func_021ECB60(char *p, int i, int f);
extern void func_021EA1C0(void *p);
extern void func_021EE038(u8 *p, int a, int b, int c);
extern void func_021EBA5C(char *p, int i);
extern void func_021DD14C(u8 *p);
extern void func_021E8FC0(u8 *p, void (*cb)(void), int n);
extern int func_021E0470(unsigned char *p);

void func_021E9DF8(u8 *p, u8 a)
{
    u8 old = ((struct Obj00000 *)p)->f14;
    ((struct Obj00000 *)p)->f16 = a;
    ((struct Obj00000 *)p)->f17 = old;
    func_021EC768((char *)(*(u32 *)&((struct Obj00000 *)p)->f2C), ((struct Obj00000 *)p)->f16, 0);
    func_021ECB84((char *)(*(u32 *)&((struct Obj00000 *)p)->f2C), ((struct Obj00000 *)p)->f16);
    func_021ED594(p, 0x24);
    func_021ED888((char *)(*(u32 *)&((struct Obj00000 *)p)->f2C), 0);
    func_021EC61C(p);
    func_021ECB20(p, 1, 1);
    func_021ECB20(p, 2, 1);
    func_021ECB60((char *)(*(u32 *)&((struct Obj00000 *)p)->f2C), 0x24, 0);
    func_021EA1C0(p);
    func_021EE038(p, 2, 2, 1);
    func_021EBA5C((char *)(*(u32 *)&((struct Obj00000 *)p)->f2C), 0x18);
    func_021DD14C(p);
    ((struct Obj00000 *)p)->f1A = 2;
    func_021E8FC0(p, (void (*)(void))func_021E0470, 0x30);
}


