/*
 * file:     box2_seq_p36.c
 * unit:     yes
 * function: func_021EB85C, func_021EB874, func_021EB90C, func_021EB95C, func_021EB988, func_021EBA30, func_021EBA5C, func_021EBA70, func_021EBA84, func_021EBADC, func_021EBAF8, func_021EBB1C, func_021EBB28, func_021EBB34, func_021EBB58, func_021EBB64, func_021EBBBC, func_021EBBC8, func_021EBC28, func_021EBC58
 * address:  0x021EB85C
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
 *   func_021EB7E8  0x021EB7E8  thumb  ov170
 *   func_02045EC0 0x02045EC0 arm
 *   func_020078C4 0x020078C4 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_02043B5C 0x02043B5C arm
 *   func_0201C7D0 0x0201C7D0 thumb
 *   func_02045808 0x02045808 arm
 *   func_020257D0 0x020257D0 thumb
 *   func_021EB6D8 0x021EB6D8 thumb ov170
 *   func_0202CE50 0x0202CE50 thumb
 *   func_0202CEBC 0x0202CEBC thumb
 *   func_0202CFC0 0x0202CFC0 thumb
 *   func_02045770 0x02045770 arm
 *   func_021EAAE4 0x021EAAE4 thumb
 *   func_0201F73C 0x0201F73C thumb
 *   func_0201F7A8  0x0201F7A8  thumb  ov170
 *   func_021EAC98 0x021EAC98 thumb
 *   func_021EAC28 0x021EAC28 thumb
 *   func_021EABA0 0x021EABA0 thumb
 *   func_02045C04 0x02045C04 arm
 *   func_021EE0FC 0x021EE0FC thumb
 *   func_0201EF40 0x0201EF40 thumb
 *   func_0202136C 0x0202136C thumb
 *   func_021DD2D0 0x021DD2D0 thumb ov170
 *   func_0201EF14 0x0201EF14 thumb
 */
#include "../../matched/include/Obj23975.h"
#include "../../matched/include/Obj23977.h"
#include "../../matched/include/Obj23978.h"
#include "../../matched/include/Obj23979.h"
#include "../../matched/include/Obj23980.h"
#include "../../matched/include/Obj23981.h"
#include "../../matched/include/Obj23982.h"
#include "../../matched/include/Obj23983.h"
#include "../../matched/include/Obj01558.h"
#include "../../matched/include/Obj23984.h"
#include "../../matched/include/Obj23985.h"
#include "../../matched/include/Obj23986.h"
#include "../../matched/include/Obj23987.h"
#include "../../matched/include/Obj23988.h"
#include "../../matched/include/Obj23989.h"
#include "../../matched/include/Obj18517.h"
#include "../../matched/include/Obj18518.h"
#include "../../matched/include/Obj00000.h"
#include "../../matched/include/Obj23990.h"
#include "../../matched/include/Obj23991.h"
#include "../../matched/include/Obj23992.h"
#include "../../matched/include/Obj23993.h"
#include "../../matched/include/Obj23994.h"

#define WORK(p) (*(char **)((p) + 0x2C))
#define MGR(p) (*(struct WinMgr **)(WORK(p) + 0x74))
struct CharBuf;
struct MsgBank;
struct Obj;
struct U16Vec;
struct WordSet;
struct WinMgr;
struct Descriptor;
struct Rec;
typedef unsigned int   u32;

typedef unsigned char  u8;

typedef signed int s32;

typedef struct {
    unsigned short a;
    unsigned short b;
} Ent;

typedef unsigned short u16;

extern void func_021EB7E8(char **p, unsigned box, int i);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern int func_020078C4(void *save, u32 box);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201C7D0(void *x, short y, short z, void *s, void *w, unsigned short v);
extern void func_02045808(struct U16Vec *vec);
extern void func_020257D0(struct Obj *o);
extern void func_021EB6D8(int a, int b, int c, int d);
extern void func_0202CE50(struct WinMgr *mgr, u32 idx, s32 x, s32 y, u8 w, u8 h, u8 pal);
extern void func_0202CEBC(struct WinMgr *mgr, u32 idx, void *a);
extern void func_0202CFC0(struct WinMgr *mgr, u32 idx, u16 *w, u16 *h);
extern void *func_02045770(struct Descriptor *p);
extern void func_021EAAE4(unsigned char *p, unsigned i);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void func_0201F7A8(void *, int);
extern void *func_021EAC98(void);
extern void func_021EAC28(char *w, int i, void *bank, u32 idx, int x, int y, u32 font, u16 color);
extern void func_021EABA0(void **win);
extern u32 func_02045C04(struct Rec *rec);
extern void func_021EE0FC(char *p);
extern void func_0201EF40(struct WordSet *p, u32 i, u32 v);
extern unsigned func_0202136C(unsigned short);
extern int func_021DD2D0(void ***p, int a, unsigned b);
extern void func_0201EF14(struct WordSet *p, u32 i, void *mon);
void func_021EB85C(unsigned char *p, int i);
void func_021EB874(char **p, unsigned a, int i);
void func_021EB90C(char *p);
void func_021EB95C(char *p);
void func_021EB988(char *p, Ent *e, unsigned n);
void func_021EBA30(unsigned char *p, void *win);
void func_021EBA5C(char *p, int i);
void func_021EBA70(char *p, int i);
void func_021EBA84(unsigned char *p, int msg, int i);
void func_021EBADC(char *p, int b);
void func_021EBAF8(unsigned char *p, u32 v, int i);
void func_021EBB1C(unsigned char *p, int i);
void func_021EBB28(char *p, int b);
void func_021EBB34(char *p, int a, int b);
void func_021EBB58(char *p, int b);
void func_021EBB64(unsigned char *p, unsigned v, int i);
void func_021EBBBC(char *p, int b);
void func_021EBBC8(unsigned char *p, unsigned kind, int i);
void func_021EBC28(unsigned char *p,int n,int i);
void func_021EBC58(unsigned char *p, int sel, int kind, int i);

/*
 * Wrap the 0x19 counter and forward it with p.
 */
void func_021EB85C(unsigned char *p, int i)
{
    unsigned v = i + p[0x19];
    if (v >= p[0x15])
        v -= p[0x15];
    func_021EB7E8((char **)p, v, 0);
}


void func_021EB874(char **p, unsigned a, int i)
{
    void *s = func_02045EC0(((struct Obj23975 *)(p[11]))->f80, 0x1E);
    unsigned n = func_020078C4((void *)(((unsigned *)p[0])[1]), a);
    func_0201EFA4(((struct Obj23977 *)(p[11]))->f84, 0, n, 2, 0, 1);
    func_0201F250(((struct Obj23978 *)(p[11]))->f84, ((struct Obj23979 *)(p[11]))->f88, s);
    func_02043B5C(*(void **)(p[11] + i * 8 + 8), 0);
    if (n == 0x1E)
        func_0201C7D0(*(void **)(p[11] + i * 8 + 8), 0, 0, ((struct Obj23980 *)(p[11]))->f88, ((struct Obj23981 *)(p[11]))->f7C, 0x1480);
    else
        func_0201C7D0(*(void **)(p[11] + i * 8 + 8), 0, 0, ((struct Obj23982 *)(p[11]))->f88, ((struct Obj23983 *)(p[11]))->f7C, 0x440);
    func_02045808(s);
    func_020257D0(*(void **)(p[11] + i * 8 + 4));
}

/*
 * trailing: two-byte zero alignment padding at 0x021EB95A.
 */
void func_021EB90C(char *p)
{
    func_021EB6D8((int)p, 20, 84, 0);
    func_021EB6D8((int)p, 21, 85, 1);
    func_0202CE50(*(struct WinMgr * *)&((struct Obj23984 *)(*(char * *)&((struct Obj01558 *)p)->f2C))->f74, 7, 0, 9, 11, 3, 12);
    func_0202CE50(*(struct WinMgr * *)&((struct Obj23985 *)(*(char * *)&((struct Obj01558 *)p)->f2C))->f74, 7, 0, 12, 11, 3, 12);
}

void func_021EB95C(char *p){func_0202CEBC((struct WinMgr *)(((struct Obj23986 *)(*(char * *)&((struct Obj01558 *)p)->f2C))->f74),7,(void *)(((struct Obj23987 *)(*(char * *)&((struct Obj01558 *)p)->f2C))->f134));func_0202CEBC((struct WinMgr *)(((struct Obj23988 *)(*(char * *)&((struct Obj01558 *)p)->f2C))->f74),7,(void *)(((struct Obj23989 *)(*(char * *)&((struct Obj01558 *)p)->f2C))->f13C));func_021EB90C(p);}


void func_021EB988(char *p, Ent *e, unsigned n)
{
    unsigned short w;
    unsigned short h;
    unsigned i = 0;
    func_0202CFC0(MGR(p), 0, &w, &h);
    for (i = 0; i < n; i++) {
        Ent *x = &e[n - 1 - i];
        if (x->b == 0)
            func_021EB6D8((int)p, 0x13 - i, x->a, 0);
        else
            func_021EB6D8((int)p, 0x13 - i, x->a, 1);
        func_0202CE50(MGR(p), 5 - i, 0, 0, w, h, 0xC);
    }
    for (; n < 6; n++) {
        unsigned k = 0x13 - n;
        func_02043B5C(func_02045770(*(void **)(WORK(p) + k * 8 + 0x94)), 0);
        func_021EAAE4((unsigned char *)WORK(p), k);
    }
}


/*
 * Clears a message window to colour 15 and draws its frame.
 */
void func_021EBA30(unsigned char *p, void *win)
{
    func_02043B5C(func_02045770(win), 0xF);
    func_0201F73C(win, 2, (unsigned short)*(int *)(WORK(p) + 0x178), 10);
}


/*
 * Forward the i-th entry word with flag 1.
 */
void func_021EBA5C(char *p, int i)
{
    func_0201F7A8(*(void **)(p + i * 8 + 0x94), 1);
}


/*
 * Forward the i-th entry word with flag 0.
 */
void func_021EBA70(char *p, int i)
{
    func_0201F7A8(*(void **)(p + i * 8 + 0x94), 0);
}


/*
 * Prints message msg of the box-menu bank into message window i.
 */
void func_021EBA84(unsigned char *p, int msg, int i)
{
    void *bank = func_021EAC98();
    func_021EBA30(p, *(void **)(WORK(p) + i * 8 + 0x94));
    func_021EAC28(WORK(p), i, bank, msg, 0, 0, *(u32 *)(WORK(p) + 0x78), 0x44F);
    func_021EABA0((void **)(WORK(p) + 0x94 + i * 8));
    func_02045C04(bank);
    func_021EE0FC((char *)p);
}

/*
 * Sibling of func_021EBB28: index 0x34 when state is 5, else 0xb.
 */
void func_021EBADC(char *p, int b)
{
    if (*(int *)(((struct Obj18517 *)p)->f0 + 0x24) == 5)
        func_021EBA84((unsigned char *)p, 0x34, b);
    else
        func_021EBA84((unsigned char *)p, 0xb, b);
}


/*
 * Puts item v into word slot 0 and prints message 0x15 into window i.
 */
void func_021EBAF8(unsigned char *p, u32 v, int i)
{
    func_0201EF40(*(void **)(WORK(p) + 0x84), 0, v);
    func_021EBA84(p, 0x15, i);
}


/*
 * Prints message 0x16 into window i.
 */
void func_021EBB1C(unsigned char *p, int i)
{
    func_021EBA84(p, 0x16, i);
}


/*
 * Forward with index 43.
 */
void func_021EBB28(char *p, int b)
{
    func_021EBA84((unsigned char *)p, 0x2b, b);
}

/*
 * Stage 0x84 of the p+0x2c object with (0, arg1), then index 0xe
 *   with the third argument.
 */
void func_021EBB34(char *p, int a, int b)
{
    func_0201EF40((struct WordSet *)(*(int *)(((struct Obj18518 *)p)->f2C + 0x84)), 0, a);
    func_021EBA84((unsigned char *)p, 0xe, b);
}


/*
 * Forward with index 13.
 */
void func_021EBB58(char *p, int b)
{
    func_021EBA84((unsigned char *)p, 0xd, b);
}

void func_021EBB64(unsigned char *p, unsigned v, int i)
{
    if (v == 0) {
        func_0201EF40(((struct Obj23990 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f84, 0, 0x70);
        func_021EBA84(p, 0x2c, i);
    } else if (func_0202136C(v) == 1) {
        func_021EBA84(p, 0x30, i);
    } else {
        func_0201EF40(((struct Obj23991 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f84, 0, v);
        func_021EBA84(p, 15, i);
    }
}


/*
 * Forward with index 32.
 */
void func_021EBBBC(char *p, int b)
{
    func_021EBA84((unsigned char *)p, 0x20, b);
}

/*
 * The image leaves the message undefined for kinds above six.
 */
void func_021EBBC8(unsigned char *p, unsigned kind, int i)
{
    int msg;
    switch (kind) {
    case 0: msg = 2; break;
    case 1: msg = 3;
        func_0201EF14(((struct Obj23992 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f84, 0, (void *)func_021DD2D0((void ***)p, p[0x14], p[0x16]));
        break;
    case 2: msg = 4;
        func_0201EF14(((struct Obj23993 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f84, 0, (void *)func_021DD2D0((void ***)p, p[0x14], p[0x16]));
        break;
    case 3: msg = 0x1c; break;
    case 4: msg = 0x1d;
        func_0201EF14(((struct Obj23994 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f84, 0, (void *)func_021DD2D0((void ***)p, p[0x14], p[0x16]));
        break;
    case 5: msg = 0x1e; break;
    case 6: msg = 6; break;
    }
    func_021EBA84(p, msg, i);
}

void func_021EBC28(unsigned char *p,int n,int i){switch(n){case 0:n=7;break;case 1:n=8;break;case 2:n=9;break;case 3:n=10;break;}func_021EBA84(p,n,i);}


/*
 * Picks the prompt for a menu kind (kind 1 first names the Pokemon in the
 * current slot) and prints it into window i.  An out-of-range kind prints
 * whatever msg holds; the image does not initialise it.
 */
void func_021EBC58(unsigned char *p, int sel, int kind, int i)
{
    int msg;
    switch (kind) {
    case 0:
        msg = 0x10;
        break;
    case 1:
        msg = 0;
        func_0201EF14(*(void **)(WORK(p) + 0x84), 0, (void *)func_021DD2D0((void ***)p, p[0x14], p[0x16]));
        break;
    case 2:
        msg = 5;
        break;
    case 3:
        msg = 0x11;
        break;
    case 4:
        msg = 0xC;
        break;
    case 5:
        msg = 0x1B;
        break;
    }
    func_021EBA84(p, msg, i);
}
