/*
 * file:     gtsnego_disp_p07.c
 * unit:     yes
 * function: func_021D4C98, func_021D4CC4, func_021D4D28, func_021D4EC0, func_021D4F70
 * address:  0x021D4C98
 * region:   ov120
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D69F4 0x021D69F4 thumb ov120
 *   func_020355D8 0x020355D8 arm
 *   func_02028230 0x02028230 thumb
 *   func_02028148 0x02028148 thumb
 *   func_02041B6C 0x02041B6C arm
 *   func_021D79F4 0x021D79F4 thumb ov120
 *   func_021D7550 0x021D7550 thumb ov120
 *   func_021D8520 0x021D8520 thumb ov120
 *   func_021D63F4 0x021D63F4 thumb ov120
 *   func_021D4244 0x021D4244 thumb ov120
 *   func_021D4B48 0x021D4B48 thumb ov120
 *   func_021D6988 0x021D6988 thumb ov120
 *   func_021D7AF4 0x021D7AF4 thumb ov120
 *   func_021B6498 0x021B6498 thumb ov067
 *   func_021D7C10 0x021D7C10 thumb ov120
 *   func_020362DC 0x020362DC arm
 *   func_020355C4 0x020355C4 arm
 *   func_021D4474 0x021D4474 thumb ov120
 *   func_021D6A9C 0x021D6A9C thumb ov120
 *   func_02035C08 0x02035C08 arm
 *   d_021D88D0 0x021D88D0 data a4
 *   func_021B63D0 0x021B63D0 thumb ov067
 *   func_021B6448 0x021B6448 thumb ov067
 *   func_02040588 0x02040588 arm
 *   func_021D7EC4 0x021D7EC4 thumb ov120
 *   func_021D68C4 0x021D68C4 thumb ov120
 *   func_021D588C 0x021D588C thumb ov120
 *   func_021B64D0 0x021B64D0 thumb ov067
 *   func_021D7D3C 0x021D7D3C thumb ov120
 *   func_021D6814 0x021D6814 thumb ov120
 *   func_021D444C 0x021D444C thumb ov120
 *   func_021D7DC8 0x021D7DC8 thumb ov120
 *   func_021D7ECC 0x021D7ECC thumb ov120
 *   func_02012F14 0x02012F14 thumb
 *   func_02009E8C 0x02009E8C thumb
 *   func_02009E54 0x02009E54 thumb
 */
#include "../../matched/include/Obj10388.h"
#include "../../matched/include/Obj03258.h"
#include "../../matched/include/Obj22829.h"
#include "../../matched/include/Obj00495.h"
#include "../../matched/include/Obj01253.h"

struct S;
struct Obj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern void func_021D69F4(u8 *,void *,u32);
extern void func_020355D8(int);
extern u32 func_02028230(u8 *p);
extern void func_02028148(u8 *p);
extern void func_02041B6C(u32 bit);
extern void func_021D79F4(u8 *p, u16 n);
extern void func_021D7550(u8 *p);
extern void func_021D8520(char *p, u16 n);
extern void func_021D63F4(u8 *p, int flag, int mode);
extern void func_021D4244(int *p, int v, int a2);
extern void func_021D4B48(u8 *p);
extern u32 func_021D6988(u8 *p);
extern int func_021D7AF4(char *p);
extern int func_021B6498(u8 *);
extern int func_021D7C10(char *p);
extern u32 func_020362DC(void);
extern u8 func_020355C4(void);
extern void func_021D4474(int n, char *p);
extern void func_020061E4(u32 a);
extern int func_021D6A9C(u8 *p, u32 n);
extern void func_0202822C(char *p, int v);
extern int func_02035C08(const void *p);
extern void func_021B63D0(struct S *p);
extern int func_021B6448(u8 *);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_021D7EC4(u8 *p);
extern void func_021D68C4(u8 *);
extern void func_021D588C(u8 *);
extern void func_021B64D0(u8 *, u32);
extern void func_021D7D3C(char *p);
extern void func_021D6814(u8 *p);
extern int func_021D444C(int n, char *p);
extern void func_021D7DC8(char *p, int a, int b, int c, int d, int e);
extern void *func_021D7ECC(char *p, u16 n);
extern void func_02028218(struct Obj *obj, u32 a);
extern void *func_02012F14(void **);
extern int func_02009E8C(void *);
extern void *func_02009E54(void *,int);
void func_021D4C98(void *p,int n,u8 *s);
void func_021D4CC4(u8 *p);
void func_021D4D28(u8 *p);
void func_021D4EC0(u8 *p);
void *func_021D4F70(void **p,int i);
extern const u32 d_021D88D0[];

void func_021D4C98(void *p,int n,u8 *s) { if (n==0 && ((struct Obj10388 *)s)->f4) { func_021D69F4(*(u8 * *)&((struct Obj10388 *)s)->f3C,((struct Obj10388 *)s)->f34,9); func_020355D8(1); if ((*(int (**)(void *,void *))(s+4))(p,s)==0) return; } }

void func_021D4CC4(u8 *p)
{
    if (func_02028230(((struct Obj03258 *)p)->f34)) {
        func_02028148(((struct Obj03258 *)p)->f34);
        *(int *)&((struct Obj03258 *)p)->f34 = 0;
        func_02041B6C(5);
        func_021D79F4(((struct Obj03258 *)p)->f40, 14);
        func_021D7550(((struct Obj03258 *)p)->f3C);
        func_021D8520(((struct Obj03258 *)p)->f40, 13);
        func_021D63F4(((struct Obj03258 *)p)->f3C, 1, 2);
        ((struct Obj22829 *)(*(u8 * *)&((struct Obj03258 *)p)->f48))->f1B0 = 2;
        func_021D69F4(((struct Obj03258 *)p)->f3C, 0, 9);
        func_021D4244((int *)p, (int)((void (*)(int))func_021D4B48), 0x460);
    }
}

void func_021D4D28(u8 *p)
{
    int changed = 0;
    int done = 0;
    u8 *q = (u8 *)func_021D6988(((struct Obj00495 *)p)->f3C);
    if (func_021D7AF4(((struct Obj00495 *)p)->f40)) {
        if (func_021B6498(q) == 0) {
            func_021D7C10((char *)(*(int *)&((struct Obj00495 *)p)->f40));
            if (func_020362DC() != 0 && func_020355C4() == 1) {
                func_021D69F4(((struct Obj00495 *)p)->f3C, ((struct Obj00495 *)p)->f34, ((struct Obj00495 *)p)->f160);
                func_020355D8(changed);
                return;
            }
            if (func_020362DC() == 0x20) func_021D4474(0, (char *)p);
            if (func_020362DC() == 0x10) func_021D4474(1, (char *)p);
            if (func_020362DC() == 0x40) {
                func_020061E4(0x548);
                changed = 1;
                if (((struct Obj00495 *)p)->f160 != 2) --((struct Obj00495 *)p)->f160;
            }
            if (func_020362DC() == 0x80) {
                func_020061E4(0x548);
                changed = 1;
                if (((struct Obj00495 *)p)->f160 != 5) ++((struct Obj00495 *)p)->f160;
            }
            if (func_020362DC() == 1 && ((struct Obj00495 *)p)->f160 == 5) {
                func_020061E4(0x54c);
                func_021D6A9C(((struct Obj00495 *)p)->f3C, ((struct Obj00495 *)p)->f160);
                func_0202822C(((struct Obj00495 *)p)->f34, 1);
                func_021D4244((int *)p, (int)func_021D4CC4, 0x4ca);
                return;
            }
            if (changed)
                func_021D69F4(((struct Obj00495 *)p)->f3C, ((struct Obj00495 *)p)->f34, ((struct Obj00495 *)p)->f160);
            if (func_02035C08(d_021D88D0) == 0) {
                func_020355D8(1);
                func_020061E4(0x54c);
                func_0202822C(((struct Obj00495 *)p)->f34, 1);
                func_021D4244((int *)p, (int)func_021D4CC4, 0x4f2);
                return;
            }
        }
        func_021B63D0((struct S *)func_021D6988(((struct Obj00495 *)p)->f3C));
        if (func_021B6448((u8 *)func_021D6988(((struct Obj00495 *)p)->f3C)) == 1) done = 1;
        if (done) {
            int zero = 0;
            func_02040588(4, 0);
            func_021D69F4(((struct Obj00495 *)p)->f3C, ((struct Obj00495 *)p)->f34, 9);
            func_021D7EC4(((struct Obj00495 *)p)->f40);
            func_021D68C4(*(u8 * *)&((struct Obj00495 *)p)->f3C);
            func_02028148(((struct Obj00495 *)p)->f34);
            *(int *)&((struct Obj00495 *)p)->f34 = zero;
            func_02041B6C(5);
            func_021D4244((int *)p, (int)func_021D588C, 0x50b);
        }
    }
}

void func_021D4EC0(u8 *p)
{
    ((struct Obj01253 *)p)->f138 = 0;
    func_021B64D0((u8 *)func_021D6988(((struct Obj01253 *)p)->f3C), 1);
    func_021D7D3C(((struct Obj01253 *)p)->f40);
    func_021D6814(((struct Obj01253 *)p)->f3C);
    *(void (**)(int))(p + 4) = (void (*)(int))func_021D444C;
    func_021D7DC8(((struct Obj01253 *)p)->f40, (int)func_021D4C98, (int)p, ((struct Obj01253 *)p)->f144, ((struct Obj01253 *)p)->f13C, ((struct Obj01253 *)p)->f140);
    func_021D79F4(((struct Obj01253 *)p)->f40, 20);
    ((struct Obj01253 *)p)->f34 = func_021D7ECC(((struct Obj01253 *)p)->f40, 18);
    if (func_020355C4() == 0) {
        func_021D69F4(((struct Obj01253 *)p)->f3C, 0, ((struct Obj01253 *)p)->f160);
        if (((struct Obj01253 *)p)->f160 == 5)
            func_02028218(((struct Obj01253 *)p)->f34, 1);
    } else {
        func_021D69F4(((struct Obj01253 *)p)->f3C, 0, 9);
    }
    func_02041B6C(6);
    func_021D4244((int *)p, (int)((void (*)(int))func_021D4D28), 0x537);
}

void *func_021D4F70(void **p,int i) { int n; n=func_02009E8C(func_02012F14(p)); if (i>=n || i<0) return 0; return func_02009E54(func_02012F14(p),i); }
