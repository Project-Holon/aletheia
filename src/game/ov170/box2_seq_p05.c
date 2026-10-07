/*
 * file:     box2_seq_p05.c
 * unit:     yes
 * function: func_021E21A0, func_021E22B8, func_021E22E0, func_021E2334, func_021E24EC
 * address:  0x021E21A0
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
 *   func_020061E4 0x020061E4 thumb
 *   func_021EA784 0x021EA784 thumb ov170
 *   func_021ED888 0x021ED888 thumb ov170
 *   func_021ECB20 0x021ECB20 thumb ov170
 *   func_021DEFEC 0x021DEFEC thumb ov170
 *   func_021EF670 0x021EF670 thumb ov170
 *   func_0201AA18 0x0201AA18 thumb
 *   func_021EE364 0x021EE364 thumb ov170
 *   func_021EF68C 0x021EF68C thumb ov170
 *   func_021EE038 0x021EE038 thumb ov170
 *   func_021E8F60  0x021E8F60  thumb  ov170
 *   func_020307B0 0x020307B0 arm
 *   func_021EBCB4 0x021EBCB4 thumb ov170
 *   func_021EBC58 0x021EBC58 thumb ov170
 *   func_021EA878 0x021EA878 thumb
 *   func_021EBA5C 0x021EBA5C thumb
 *   func_021EB988 0x021EB988 thumb
 *   func_021EF534 0x021EF534 thumb
 *   func_021E8FC0 0x021E8FC0 thumb
 *   func_021E0190 0x021E0190 thumb
 *   func_021ED55C 0x021ED55C thumb
 *   func_021ED508 0x021ED508 thumb
 *   d_021EF9B4 0x021EF9B4 data
 *   d_021EF950 0x021EF950 data
 *   d_021EFA10 0x021EFA10 data
 *   d_021EF918 0x021EF918 data
 *   d_021EF8EC 0x021EF8EC data
 *   func_021EF1FC 0x021EF1FC thumb
 *   func_021DD1C4 0x021DD1C4 thumb
 *   func_021E19D4 0x021E19D4 thumb
 *   func_021E1A78 0x021E1A78 thumb
 *   func_021E1A28 0x021E1A28 thumb
 *   func_021E1ACC 0x021E1ACC thumb
 */
#include "../../matched/include/Obj00000.h"
#include "../../matched/include/Obj23887.h"
#include "../../matched/include/Obj23888.h"
#include "../../matched/include/Obj06548.h"
#include "../../matched/include/Obj23889.h"
#include "../../matched/include/Obj23890.h"
#include "../../matched/include/Obj23891.h"

#define W(p) (*(char **)((p)+0x2C))
#define NEXT(p) (*(int *)(W(p)+0xA198))
#define WORK(p) (*(char **)((p) + 0x2C))
#define MGR(p) (*(struct WinMgr **)(WORK(p) + 0x74))
#define STEP(p) (*(int *)(WORK(p) + 0xA194))
#define TOP(p) (*(char **)(p))
#define MODE(p) (*(int *)(TOP(p) + 0x24))
#define SUB(p) (*(s16 *)(WORK(p) + 0xA16C))
#define STATE(p) (*(int *)((p) + 0x28))
#define SCROLL(p) (*(Scroll **)(WORK(p) + 0xA190))
#define LASTY(p) (*(unsigned *)(WORK(p) + 0xA184))
#define ABS(x) ((x) < 0 ? -(x) : (x))
struct PrintSys;
struct WinMgr;
typedef unsigned char u8;

typedef unsigned int   u32;

typedef short s16;

typedef struct {
    short left;
    short dir;
} Scroll;

extern void func_020061E4(unsigned);
extern void func_021EA784(int p);
extern void func_021ED888(char *,int);
extern void func_021ECB20(char *p, int f, int c);
extern void func_021DEFEC(char *p, int b);
extern void func_021EF670(char *);
extern u32 func_0201AA18(void *p);
extern void func_021EE364(char **,int,int);
extern void func_021EF68C(char *);
extern void func_021EE038(char *p, int a, int b, int c);
extern u32 func_0201C6B4(const struct PrintSys *p);
extern int func_021E8F60(void *p, int a);
extern u32 func_020307B0(void *p);
extern void func_021EBCB4(unsigned char *, int, int);
extern void func_021EBC58(unsigned char *, int, int, int);
extern void func_021EA878(unsigned char *p, int v);
extern void func_021EBA5C(char *w, int v);
extern void func_021EB988(unsigned char *p, const void *e, unsigned n);
extern void func_021EF534(struct WinMgr *mgr);
extern int func_021E8FC0(char *p, int a, int b);
extern int func_021E0190(char *p);
extern void func_021ED55C(char **p, int flag);
extern void func_021ED508(unsigned char *p, int a, int b);
extern int func_021EF1FC(unsigned *a, unsigned *b);
extern void func_021DD1C4(char *p, int a);
extern int func_021E19D4(char *p);
extern int func_021E1A78(char *p);
extern int func_021E1A28(char *p);
extern int func_021E1ACC(char *p);
int func_021E21A0(u8 *p);
int func_021E22B8(int p);
int func_021E22E0(unsigned char *p);
int func_021E2334(unsigned char *p);
int func_021E24EC(unsigned char *p);
extern const unsigned char d_021EF9B4[];
extern const unsigned char d_021EF950[];
extern const unsigned char d_021EFA10[];
extern const unsigned char d_021EF918[];
extern const unsigned char d_021EF8EC[];

int func_021E21A0(u8 *p)
{
    func_020061E4(0x55C);
    switch(((struct Obj23887 *)(*(char * *)&((struct Obj00000 *)p)->f0))->f24) {
    case 0:
        func_021EA784((int)p);
        func_021ED888(W(p),0);
        func_021ECB20((char *)p,1,1);
        func_021DEFEC((char *)p,30);
        NEXT(p)=0x31;
        break;
    case 1:
        func_021DEFEC((char *)p,0);
        NEXT(p)=0x2C;
        break;
    case 2:
        func_021DEFEC((char *)p,0);
        func_021EF670(W(p));
        NEXT(p)=0x11;
        break;
    case 3:
        func_021ECB20((char *)p,0x81,1);
        func_021DEFEC((char *)p,0);
        func_021EF670(W(p));
        NEXT(p)=0x39;
        break;
    case 4:
        if(func_0201AA18(((struct Obj23888 *)(*(char * *)&((struct Obj00000 *)p)->f0))->f8)==0) {
            func_021EF670(W(p));
            func_021DEFEC((char *)p,0);
            func_021EE364((char **)p,13,0);
            NEXT(p)=0x23;
        } else {
            func_021EA784((int)p);
            func_021ED888(W(p),0);
            func_021ECB20((char *)p,1,1);
            func_021EF68C(W(p));
            func_021DEFEC((char *)p,30);
            func_021EE364((char **)p,14,0);
            NEXT(p)=0x27;
        }
        break;
    case 5:
        func_021DEFEC((char *)p,0);
        func_021ECB20((char *)p,0x81,1);
        func_021EE038((char *)p,0,1,1);
        NEXT(p)=0x4B;
        break;
    }
    return func_021E22B8((int)p);
}

/*
 * candidate func_021E22B8: guard then dispatch
 */
int func_021E22B8(int p)
{
    if (func_0201C6B4((const struct PrintSys *)(*(int *)(*(int *)&((struct Obj00000 *)p)->f2C + 0x8c))) == 0)
        return 0xc;
    func_021E8F60((void *)p, *(int *)(*(int *)&((struct Obj00000 *)p)->f2C + 0xA198));
}

int func_021E22E0(unsigned char *p)
{
    func_020307B0(((struct Obj23889 *)(*(char * *)&((struct Obj06548 *)p)->f2C))->f60);
    if ((*(unsigned char **)(p + 0x2C))[0xA172] == 1) {
        if (((struct Obj23890 *)(*(char * *)&((struct Obj06548 *)p)->f0))->f24 == 3) {
            if (((struct Obj23891 *)(*(char * *)&((struct Obj06548 *)p)->f2C))->fA16C == 0)
                func_021EBCB4(p, 0, 0x18);
            else
                func_021EBCB4(p, 1, 0x18);
        } else {
            func_021EBC58(p, p[0x16], 1, 0x18);
        }
        (*(char **)(p + 0x2C))[0xA172] = 0;
    }
    return ((struct Obj06548 *)p)->f28;
}


/*
 * Two-step machine on the work word at 0xA194: step 0 opens the menu for
 * the current mode and fades, step 1 picks the next state from the mode.
 */
int func_021E2334(unsigned char *p)
{
    switch (STEP(p)) {
    case 0:
        switch (MODE(p)) {
        case 1:
            func_021EB988(p, d_021EF9B4, 5);
            break;
        case 0:
            func_021EB988(p, d_021EF950, 5);
            break;
        case 2:
            func_021EB988(p, d_021EFA10, 6);
            break;
        case 3:
            func_021EA878(p, SUB(p));
            break;
        case 4:
            func_021EB988(p, d_021EF918, 4);
            break;
        case 5:
            func_021EBA5C(WORK(p), 0x1B);
            func_021EB988(p, d_021EF8EC, 2);
            break;
        }
        if (*(unsigned char *)(WORK(p) + 0xA170) == 1) {
            *(unsigned char *)(WORK(p) + 0xA170) = 0;
            if (MODE(p) == 3) {
                if (p[0x16] >= 0x1E) {
                    func_021ECB20((char *)p, 0x82, 0);
                } else {
                    func_021ED888(WORK(p), 1);
                    func_021ECB20((char *)p, 0x81, 0);
                }
            } else {
                if (p[0x16] >= 0x1E) {
                    func_021ECB20((char *)p, 2, 0);
                } else {
                    func_021ED888(WORK(p), 1);
                    func_021ECB20((char *)p, 1, 0);
                }
            }
        }
        func_021EF534(MGR(p));
        STEP(p)++;
        return func_021E8FC0((char *)p, (int)func_021E0190, 0xE);
    case 1:
        STEP(p) = 0;
        func_021ED55C((char **)p, 1);
        func_021ED508(p, 0xE, 1);
        switch (MODE(p)) {
        case 1:
            func_021EBC58(p, p[0x16], 1, 0x18);
            return 0x2C;
        case 0:
            func_021EBC58(p, p[0x16], 1, 0x18);
            return 0x31;
        case 2:
            func_021EBC58(p, p[0x16], 1, 0x18);
            if (p[0x16] < 0x1E)
                return 0x11;
            return 0x1B;
        case 3:
            if (*(unsigned short *)(WORK(p) + 0xA16C) == 0)
                func_021EBCB4(p, 0, 0x18);
            else
                func_021EBCB4(p, 1, 0x18);
            if (p[0x16] < 0x1E)
                return 0x39;
            return 0x46;
        case 4:
            func_021EBC58(p, p[0x16], 1, 0x18);
            if (p[0x16] < 0x1E)
                return 0x23;
            return 0x27;
        case 5:
            func_021EBC58(p, p[0x16], 1, 0x18);
            return 0x4B;
        }
        break;
    }
    return 0xE;
}


/*
 * Touch-drag paging of the box list: a drag of three or more pixels
 * starts a scroll of |d| / 8 steps in its direction; each later call
 * spends one step until the count runs out.
 */
int func_021E24EC(unsigned char *p)
{
    unsigned x, y;
    Scroll *s;
    unsigned old;
    int d;

    if (func_021EF1FC(&x, &y) == 0) {
        func_020307B0(SCROLL(p));
        return STATE(p);
    }
    s = SCROLL(p);
    old = LASTY(p);
    LASTY(p) = y;
    d = old - y;
    if (ABS(d) >= 3) {
        s->left = ABS(d) / 8;
        if (y < old) {
            s->dir = 1;
            func_021DD1C4((char *)p, 1);
            func_020061E4(0x548);
            if (STATE(p) == 0x15)
                return func_021E8FC0((char *)p, (int)func_021E19D4, 0xF);
            return func_021E8FC0((char *)p, (int)func_021E1A78, 0xF);
        }
        if (y > old) {
            s->dir = -1;
            func_021DD1C4((char *)p, -1);
            func_020061E4(0x548);
            if (STATE(p) == 0x15)
                return func_021E8FC0((char *)p, (int)func_021E1A28, 0xF);
            return func_021E8FC0((char *)p, (int)func_021E1ACC, 0xF);
        }
    }
    if (s->left != 0) {
        s->left--;
        if (s->dir == 1) {
            func_021DD1C4((char *)p, 1);
            func_020061E4(0x548);
            if (STATE(p) == 0x15)
                return func_021E8FC0((char *)p, (int)func_021E19D4, 0xF);
            return func_021E8FC0((char *)p, (int)func_021E1A78, 0xF);
        }
        if (s->dir == -1) {
            func_021DD1C4((char *)p, -1);
            func_020061E4(0x548);
            if (STATE(p) == 0x15)
                return func_021E8FC0((char *)p, (int)func_021E1A28, 0xF);
            return func_021E8FC0((char *)p, (int)func_021E1ACC, 0xF);
        }
    }
    return 0xF;
}
