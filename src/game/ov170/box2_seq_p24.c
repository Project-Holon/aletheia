/*
 * file:     box2_seq_p24.c
 * unit:     yes
 * function: func_021E9CE0, func_021E9D2C, func_021E9D98, func_021E9DF8, func_021E9E7C, func_021E9EC0, func_021E9F3C, func_021E9FA8, func_021EA020, func_021EA064
 * address:  0x021E9CE0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021DD16C 0x021DD16C thumb
 *   func_021EF5E8 0x021EF5E8 thumb
 *   func_021EF57C 0x021EF57C thumb
 *   func_021EBA5C 0x021EBA5C thumb
 *   func_021DD14C 0x021DD14C thumb
 *   func_021EF670 0x021EF670 thumb
 *   func_021E8FC0 0x021E8FC0 thumb
 *   func_021E0128 0x021E0128 thumb
 *   func_021EC768 0x021EC768 thumb
 *   func_021ECB84 0x021ECB84 thumb
 *   func_021ED594 0x021ED594 thumb
 *   func_021EA1C0 0x021EA1C0 thumb
 *   func_021EE038 0x021EE038 thumb
 *   func_021DFA30 0x021DFA30 thumb
 *   func_021E1B1C 0x021E1B1C thumb
 *   func_021ED888  0x021ED888  thumb  ov170
 *   func_021EC61C  0x021EC61C  thumb  ov170
 *   func_021ECB20  0x021ECB20  thumb  ov170
 *   func_021ECB60  0x021ECB60  thumb  ov170
 *   func_021E0470  0x021E0470  thumb  ov170
 *   func_021ED588 0x021ED588 thumb
 *   func_021EF534 0x021EF534 thumb
 *   func_021E8FE0 0x021E8FE0 thumb
 *   func_021E070C 0x021E070C thumb
 *   func_0201AB28 0x0201AB28 thumb
 *   func_021EF68C 0x021EF68C thumb
 *   func_021DF484 0x021DF484 thumb
 *   func_021E0200 0x021E0200 thumb
 */
#include "../../matched/include/Obj00000.h"
#include "../../matched/include/Obj23952.h"
#include "../../matched/include/Obj23953.h"
#include "../../matched/include/Obj23954.h"

#define WORK(p) (*(char **)((p) + 0x2C))
struct WinMgr;
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

typedef unsigned char u8;

typedef unsigned int u32;

typedef struct {
    unsigned char lo : 4;
    unsigned char hi : 4;
} Nib;

extern void func_021DD16C(unsigned char *p, int dir);
extern int func_021EF5E8(struct WinMgr *mgr);
extern void func_021EF57C(struct WinMgr *mgr);
extern void func_021EBA5C(char *w, int v);
extern void func_021DD14C(char *p);
extern void func_021EF670(char *w);
extern int func_021E8FC0(char *p, int a, int b);
extern int func_021E0128(char *p);
extern void func_021EC768(char *p, unsigned i, int flag);
extern void func_021ECB84(char *w, unsigned i);
extern void func_021ED594(char *p, unsigned i);
extern void func_021EA1C0(void *p);
extern void func_021EE038(char *p, int a, int b, int c);
extern int func_021DFA30(unsigned char *p);
extern int func_021E1B1C(unsigned char *p);
extern void func_021ED888(char *p, int a);
extern void func_021EC61C(u8 *p);
extern void func_021ECB20(char *p, int f, int c);
extern void func_021ECB60(char *p, int i, int f);
extern int func_021E0470(unsigned char *p);
extern void func_021ED588(char *p);
extern void func_021EF534(struct WinMgr *mgr);
extern int func_021E8FE0(char *p, int v);
extern int func_021E070C(char *p);
extern void *func_0201AB28(void *party, unsigned i);
extern void func_021EF68C(char *w);
extern int func_021DF484(unsigned char *p);
extern int func_021E0200(unsigned char *p);
int func_021E9CE0(char *p, int a, int n);
void func_021E9D2C(Obj *p, unsigned char i);
void func_021E9D98(Obj *p, unsigned char i);
void func_021E9DF8(u8 *p, u8 a);
void func_021E9E7C(char *p, unsigned char i, int v);
void func_021E9EC0(unsigned char *p, unsigned char i);
void func_021E9F3C(unsigned char *p, unsigned char i);
void func_021E9FA8(unsigned char *p, unsigned char i);
void func_021EA020(char *p, unsigned char i, int v);
int func_021EA064(unsigned char *p, int i, int v);


int func_021E9CE0(char *p, int a, int n)
{
    func_021DD16C((unsigned char *)p, 1);
    if (func_021EF5E8(*(struct WinMgr **)(WORK(p) + 0x74)) == 1) {
        func_021EF57C(*(struct WinMgr **)(WORK(p) + 0x74));
        func_021EBA5C(WORK(p), 0x18);
        func_021DD14C(p);
        if (a == 1)
            func_021EF670(WORK(p));
    }
    return func_021E8FC0(p, (int)func_021E0128, n);
}


void func_021E9D2C(Obj *p, unsigned char i)
{
    p->b1B = 0;
    p->lo = 0;
    p->b16 = i;
    p->b17 = p->b14;
    func_021EC768(p->work, p->b16, 0);
    func_021ECB84(p->work, p->b16);
    func_021ED594((char *)p, 0x24);
    func_021EA1C0(p);
    func_021EE038((char *)p, 2, 2, 1);
    func_021EBA5C(p->work, 0x18);
    func_021DD14C((char *)p);
    func_021EF670(p->work);
    p->next = 0x15;
    p->b1A = 0;
    func_021E8FC0((char *)p, (int)func_021DFA30, 0x12);
}


void func_021E9D98(Obj *p, unsigned char i)
{
    p->b16 = i;
    p->b17 = p->b14;
    p->b1B = 0;
    func_021EC768(p->work, p->b16, 0);
    func_021ECB84(p->work, p->b16);
    func_021ED594((char *)p, 0x24);
    func_021EA1C0(p);
    func_021EE038((char *)p, 2, 2, 1);
    func_021EBA5C(p->work, 0x18);
    func_021DD14C((char *)p);
    p->b1A = 0;
    p->next = 0x20;
    func_021E8FC0((char *)p, (int)func_021E1B1C, 0x24);
}


void func_021E9DF8(u8 *p, u8 a)
{
    u8 old = ((struct Obj00000 *)p)->f14;
    ((struct Obj00000 *)p)->f16 = a;
    ((struct Obj00000 *)p)->f17 = old;
    func_021EC768((char *)(*(u32 *)&((struct Obj00000 *)p)->f2C), ((struct Obj00000 *)p)->f16, 0);
    func_021ECB84((char *)(*(u32 *)&((struct Obj00000 *)p)->f2C), ((struct Obj00000 *)p)->f16);
    func_021ED594((char *)p, 0x24);
    func_021ED888((char *)(*(u32 *)&((struct Obj00000 *)p)->f2C), 0);
    func_021EC61C(p);
    func_021ECB20((char *)p, 1, 1);
    func_021ECB20((char *)p, 2, 1);
    func_021ECB60((char *)(*(u32 *)&((struct Obj00000 *)p)->f2C), 0x24, 0);
    func_021EA1C0(p);
    func_021EE038((char *)p, 2, 2, 1);
    func_021EBA5C((char *)(*(u32 *)&((struct Obj00000 *)p)->f2C), 0x18);
    func_021DD14C((char *)p);
    ((struct Obj00000 *)p)->f1A = 2;
    func_021E8FC0((char *)p, (int)((void (*)(void))func_021E0470), 0x30);
}


void func_021E9E7C(char *p, unsigned char i, int v)
{
    p[0x16] = i;
    *(unsigned char *)(WORK(p) + 0xA172) = 1;
    func_021EC768(WORK(p), (unsigned char)p[0x16], 1);
    func_021ED588(p);
    func_021EF534(*(struct WinMgr **)(WORK(p) + 0x74));
    func_021E8FC0(p, (int)func_021E070C, func_021E8FE0(p, v));
}


void func_021E9EC0(unsigned char *p, unsigned char i)
{
    p[0x16] = i;
    ((Nib *)(p + 0x1C))->lo = 0;
    p[0x17] = p[0x14];
    p[0x1B] = 1;
    func_021EC768(WORK(p), p[0x16], 0);
    func_021ECB84(WORK(p), p[0x16]);
    func_021ED594((char *)p, 0x24);
    func_0201AB28(((struct Obj23952 *)(*(char * *)&((struct Obj00000 *)p)->f0))->f8, i - 0x1E);
    func_021EA1C0(p);
    func_021EE038((char *)p, 2, 2, 1);
    func_021EBA5C(WORK(p), 0x18);
    func_021DD14C((char *)p);
    func_021EF68C(WORK(p));
    ((struct Obj00000 *)p)->f28 = 0x20;
    p[0x1A] = 1;
    func_021E8FC0((char *)p, (int)func_021DF484, 0x1E);
}


void func_021E9F3C(unsigned char *p, unsigned char i)
{
    p[0x17] = p[0x14];
    p[0x16] = i;
    p[0x1B] = 1;
    func_021EC768(WORK(p), p[0x16], 0);
    func_021ECB84(WORK(p), p[0x16]);
    func_021ED594((char *)p, 0x24);
    func_0201AB28(((struct Obj23953 *)(*(char * *)&((struct Obj00000 *)p)->f0))->f8, i - 0x1E);
    func_021EA1C0(p);
    func_021EE038((char *)p, 2, 2, 1);
    func_021EBA5C(WORK(p), 0x18);
    func_021DD14C((char *)p);
    ((struct Obj00000 *)p)->f28 = 0x20;
    p[0x1A] = 1;
    func_021E8FC0((char *)p, (int)func_021DF484, 0x2A);
}


void func_021E9FA8(unsigned char *p, unsigned char i)
{
    p[0x16] = i;
    func_021EC768(WORK(p), p[0x16], 0);
    func_021ECB84(WORK(p), p[0x16]);
    func_021ED594((char *)p, 0x24);
    func_021ECB20((char *)p, 2, 1);
    func_021ECB60(WORK(p), 0x24, 0);
    func_0201AB28(((struct Obj23954 *)(*(char * *)&((struct Obj00000 *)p)->f0))->f8, i - 0x1E);
    func_021EA1C0(p);
    func_021EE038((char *)p, 2, 2, 1);
    func_021EBA5C(WORK(p), 0x18);
    func_021DD14C((char *)p);
    p[0x1A] = 1;
    func_021E8FC0((char *)p, (int)func_021E0200, 0x38);
}


void func_021EA020(char *p, unsigned char i, int v)
{
    p[0x16] = i;
    *(unsigned char *)(WORK(p) + 0xA172) = 1;
    func_021EC768(WORK(p), (unsigned char)p[0x16], 1);
    func_021ED588(p);
    func_021EF534(*(struct WinMgr **)(WORK(p) + 0x74));
    func_021E8FC0(p, (int)func_021E070C, func_021E8FE0(p, v));
}


int func_021EA064(unsigned char *p, int i, int v)
{
    p[0x17] = p[0x14];
    p[0x16] = i;
    *(int *)(WORK(p) + 0xA168) = i;
    func_021ECB84(WORK(p), p[0x16]);
    func_021EC768(WORK(p), 0x24, 0);
    func_021ED594((char *)p, 0x24);
    func_021EE038((char *)p, 2, 1, 2);
    func_021EA1C0(p);
    ((struct Obj00000 *)p)->f28 = v;
    p[0x1A] = 2;
    return func_021E8FC0((char *)p, (int)func_021DFA30, 0x17);
}
