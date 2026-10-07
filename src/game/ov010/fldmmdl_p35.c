/*
 * file:     fldmmdl_p35.c
 * unit:     yes
 * function: func_0216E204, func_0216E280, func_0216E290, func_0216E29C
 * address:  0x0216E204
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D948  0x0216D948  thumb  ov010
 *   func_0216DAA0  0x0216DAA0  thumb  ov010
 *   func_0216D76C  0x0216D76C  thumb  ov010
 *   func_0216D594  0x0216D594  thumb  ov010
 *   func_0216E39C  0x0216E39C  thumb  ov010
 *   func_0216DA94  0x0216DA94  thumb  ov010
 *   func_0216E190  0x0216E190  thumb  ov010
 *   func_0216E114  0x0216E114  thumb  ov010
 *   func_020490F4  0x020490F4  arm
 *   func_02049238  0x02049238  arm
 *   func_02048F4C  0x02048F4C  arm
 */
#include "../../matched/include/Obj00113.h"
#include "../../matched/include/Obj05908.h"
#include "../../matched/include/Obj17855.h"
#include "../../matched/include/Obj19134.h"

typedef unsigned char u8;

typedef signed char s8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct Obj {
    char pad[0x44];
    void *f44;
} Obj;

extern void *func_0216D67C(void *a);
extern int func_0216D948(int a0);
extern int func_0216DAA0(void *a);
extern void func_0216D76C(void *a);
extern void func_0216D594(void *p, u32 v);
extern void func_0216E39C(int a0, int a1, int a2);
extern void func_0216DA94(void *a);
extern void func_0216E190(void *a);
extern int func_0216E114(int a0);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_02049238(void *p);
void func_02048F4C(void *dst, u32 archive_id, u32 member);
void func_0216E204(char *a, u32 v);
void *func_0216E280(int a0, int a1);
void func_0216E290(char *p);
void func_0216E29C(Obj *o, int v);


void func_0216E204(char *a, u32 v)
{
    void *ctx;
    char *p;

    ctx = func_0216D67C(a);
    if (func_0216D948((int)ctx) == 1 && func_0216DAA0(a) == 1)
        func_0216D76C(a);
    func_0216D594(a, v);
    func_0216E39C((int)ctx, v, (int)a);
    p = a + 0xe4;
    ((struct Obj00113 *)a)->f7C = ((struct Obj05908 *)p)->fB;
    ((struct Obj00113 *)a)->f7D = ((struct Obj05908 *)p)->fC;
    *(s8 *)&((struct Obj00113 *)a)->f7E = ((struct Obj05908 *)p)->fD;
    *(s8 *)&((struct Obj00113 *)a)->f7F = ((struct Obj05908 *)p)->fE;
    *(s8 *)&((struct Obj00113 *)a)->f80 = ((struct Obj05908 *)p)->fF;
    func_0216DA94(a);
    func_0216E190(a);
    func_0216E114((int)a);
}


/*
 * blocked:  listing 16 compiled 14
 */
void *func_0216E280(int a0, int a1)
{
    int t4;
    void *p;

t4 = a0 + 0;
    p = func_020490F4(0x30, a1);
loc_0216E28A:
((struct Obj17855 *)t4)->f14 = p;
    return p;}


/*
 * Forwards the pointer at +0x14 to the arm9 routine at 0x02049238.
 */
void func_0216E290(char *p)
{
    func_02049238(((struct Obj19134 *)p)->f14);
}


/*
 * Unlabelled leaf (saves no lr, so disasm.py prints it as .word data):
 * a tail call through a pool word, the sole blocker of ov020 func_021857C0.
 */
void func_0216E29C(Obj *o, int v)
{
    func_02048F4C(o->f44, 0x3a, v);
}
