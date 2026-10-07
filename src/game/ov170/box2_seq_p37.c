/*
 * file:     box2_seq_p37.c
 * unit:     yes
 * function: func_021EBCB4, func_021EBD1C, func_021EBD50, func_021EBD78, func_021EBD94, func_021EBDD8, func_021EBDF4, func_021EBE24, func_021EBE4C, func_021EBEAC, func_021EBEE0, func_021EBF34, func_021EBF50, func_021EBF74, func_021EBFA8, func_021EBFCC, func_021EBFEC, func_021EC000, func_021EC01C, func_021EC030
 * address:  0x021EBCB4
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
 *   func_0201EF40 0x0201EF40 thumb
 *   func_021EBA84 0x021EBA84 thumb
 *   func_021DD2D0 0x021DD2D0 thumb ov170
 *   func_0201EF14 0x0201EF14 thumb
 *   func_021EE038 0x021EE038 thumb ov170
 *   func_021EE120 0x021EE120 thumb ov170
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   func_021EE200  0x021EE200  thumb  ov170
 *   func_021DC9D8 0x021DC9D8 thumb ov170
 *   func_0204A48C 0x0204A48C arm
 *   d_021EFD64 0x021EFD64 data a4
 *   func_021EC0DC 0x021EC0DC thumb ov170
 *   func_021EC1E8 0x021EC1E8 thumb ov170
 *   func_021EC254 0x021EC254 thumb ov170
 *   func_021ED058 0x021ED058 thumb ov170
 *   func_021ECCA4 0x021ECCA4 thumb ov170
 *   func_021ECDF4 0x021ECDF4 thumb ov170
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204B100 0x0204B100 arm
 *   func_021ED824 0x021ED824 thumb ov170
 *   func_021EC2A0 0x021EC2A0 thumb ov170
 *   func_021ED370 0x021ED370 thumb ov170
 *   func_021ECF78 0x021ECF78 thumb ov170
 *   func_0204B294 0x0204B294 arm
 *   func_0204BA20 0x0204BA20 arm
 *   func_0204B98C  0x0204B98C  arm  arm9
 *   func_0204B3F4  0x0204B3F4  arm  arm9
 */
#include "../../matched/include/Obj00000.h"
#include "../../matched/include/Obj23995.h"
#include "../../matched/include/Obj23996.h"
#include "../../matched/include/Obj23997.h"
#include "../../matched/include/Obj07238.h"

#define WORK(p) (*(char **)((p) + 0x2C))
struct WordSet;
struct Bank;
struct Obj;
struct Actor;
struct S;
typedef unsigned int u32;

typedef struct {unsigned a,b,c,d,e,f,g;} Template;

typedef unsigned char  u8;

typedef struct {
    int pad0;
    int pad4;
    int a;
    int b;
    int c;
    unsigned short pad14;
    unsigned short d;
} Desc;

struct S { char pad[0x9E74]; int arr[1]; };

typedef unsigned short u16;

extern void func_0201EF40(struct WordSet *p, u32 i, u32 v);
extern void func_021EBA84(unsigned char *p, int msg, int i);
extern int func_021DD2D0(void ***,int,unsigned);
extern void func_0201EF14(void *,unsigned,void *);
extern void func_021EE038(char *, int, int, int);
extern void func_021EE120(char *p);
extern void func_020434DC(unsigned, unsigned);
extern void func_02043598(unsigned, unsigned);
extern void func_021EE200(char *);
extern void func_0204A5AC(void);
extern unsigned func_021DC9D8(void);
extern void func_0204A48C(Template *,unsigned,unsigned);
extern void func_021EC0DC(char *);
extern void func_021EC1E8(char *);
extern void func_021EC254(char *);
extern void func_021ED058(char *);
extern void func_021ECCA4(char *);
extern void func_021ECDF4(char *);
extern void func_0204A8D4(u32 i);
extern void func_0204ADA4(u32 i);
extern void func_0204AFD8(u32 i);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_021ED824(char *);
extern void func_021EC2A0(char *);
extern void func_021ED370(unsigned char *);
extern void func_021ECF78(char *);
extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern void func_0204BA20(struct Actor *a, u32 v);
extern void func_0204B3B4(struct Obj *p);
extern u32 func_0204B1CC(struct Bank *bank);
extern u32 func_0204B944(struct Obj *p);
extern void func_0204B8D4(struct Obj *p, u32 arg);
extern void func_0204A600(void);
extern void func_0204B8C4(struct Obj *p, u32 value);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B92C(struct Obj *, unsigned int);
extern u32 func_0204B98C(struct Actor *a);
extern void func_0204B3DC(struct Obj *, unsigned int);
extern u32 func_0204B3F4(struct Obj *p);
extern void func_0204B84C(int, int);
void func_021EBCB4(unsigned char *p, int kind, int i);
void func_021EBD1C(char *p, int row, int b);
void func_021EBD50(unsigned char *p);
void func_021EBD78(char *p, int b);
void func_021EBD94(unsigned char *p);
void func_021EBDD8(char *p);
void func_021EBDF4(void *a0);
void func_021EBE24(char *p);
void func_021EBE4C(char *p);
void func_021EBEAC(unsigned char *p);
void *func_021EBEE0(char *w, const Desc *s);
void func_021EBF34(struct S *p, int i);
void func_021EBF50(char *p);
void func_021EBF74(char *p);
void func_021EBFA8(char *p, int i, int v);
void func_021EBFCC(char *p, int i, int v);
u32 func_021EBFEC(char *p, int i);
void func_021EC000(char *p, int i, int v);
u32 func_021EC01C(char *p, int i);
void func_021EC030(char *p, int i, int c);
extern const Template d_021EFD64;


/*
 * Item-menu prompt for a kind; kinds 1 to 3 name the held item first.  An
 * out-of-range kind prints whatever msg holds; the image does not initialise it.
 */
void func_021EBCB4(unsigned char *p, int kind, int i)
{
    int msg;
    switch (kind) {
    case 0:
        msg = 0x1A;
        break;
    case 1:
        msg = 0x17;
        func_0201EF40(*(void **)(WORK(p) + 0x84), 0, *(unsigned short *)(WORK(p) + 0xA16C));
        break;
    case 2:
        msg = 0x18;
        func_0201EF40(*(void **)(WORK(p) + 0x84), 0, *(unsigned short *)(WORK(p) + 0xA16C));
        break;
    case 3:
        msg = 0x19;
        func_0201EF40(*(void **)(WORK(p) + 0x84), 0, *(unsigned short *)(WORK(p) + 0xA16C));
        break;
    case 4:
        msg = 0x16;
        break;
    case 5:
        msg = 0x1F;
        break;
    case 6:
        msg = 0xD;
        break;
    case 7:
        msg = 0x2F;
        break;
    }
    func_021EBA84(p, msg, i);
}


/*
 * Maps a menu row to its message index, then tail-calls the printer.
 */
void func_021EBD1C(char *p, int row, int b)
{
    switch (row) {
    case 2:
        row = 0x2d;
        break;
    case 3:
        row = 0x2e;
        break;
    case 4:
        row = 0x31;
        break;
    case 6:
        row = 0x33;
        break;
    }
    func_021EBA84((unsigned char *)p, row, b);
}

void func_021EBD50(unsigned char *p){void *m=(void *)func_021DD2D0((void ***)p,p[20],p[22]);func_0201EF14(((struct Obj23995 *)(*(unsigned char * *)&((struct Obj00000 *)p)->f2C))->f84,0,m);func_021EBA84(p,50,27);}

/*
 * Index 0x35 when the flag is clear, 0x36 when set.
 */
void func_021EBD78(char *p, int b)
{
    if (b == 0)
        func_021EBA84((unsigned char *)p, 0x35, 0x1b);
    else
        func_021EBA84((unsigned char *)p, 0x36, 0x1b);
}

/*
 * trailing: two-byte zero alignment padding at 0x021EBDD6.
 */
void func_021EBD94(unsigned char *p)
{
    func_021EBDF4(((struct Obj00000 *)p)->f2C);
    func_021EBE24(((struct Obj00000 *)p)->f2C);
    func_021EBEAC(p);
    func_021EE038((char *)p, p[0x1f], p[0x20], p[0x21]);
    func_021EE120(((struct Obj00000 *)p)->f2C);
    func_020434DC(16, 1);
    func_02043598(16, 1);
}

/*
 * Three teardown steps then the SDK pool release.
 */
void func_021EBDD8(char *p)
{
    func_021EE200(p);
    func_021EBF50(p);
    func_021EBE4C(p);
    func_0204A5AC();
}

void func_021EBDF4(void *a0){Template t=d_021EFD64;unsigned n=func_021DC9D8();func_0204A48C(&t,n,76);}

void func_021EBE24(char *p){func_021EC0DC(p);func_021EC1E8(p);func_021EC254(p);func_021ED058(p);func_021ECCA4(p);func_021ECDF4(p);}

void func_021EBE4C(char *p)
{
    unsigned i;
    for (i = 0; i < 0x45; i++)
        if (*(int *)(p + i * 4 + 0x9FF4) != -1)
            func_0204A8D4(*(int *)(p + i * 4 + 0x9FF4));
    for (i = 0; i < 0xB; i++)
        if (*(int *)(p + i * 4 + 0xA108) != -1)
            func_0204ADA4(*(int *)(p + i * 4 + 0xA108));
    for (i = 0; i < 0xC; i++)
        if (*(int *)(p + i * 4 + 0xA134) != -1)
            func_0204AFD8(*(int *)(p + i * 4 + 0xA134));
}

void func_021EBEAC(unsigned char *p){((struct Obj23996 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f9E70=func_0204B100(180,0,76);func_021ED824(*(char * *)&((struct Obj00000 *)p)->f2C);func_021EC2A0(*(char * *)&((struct Obj00000 *)p)->f2C);func_021ED370(p);func_021ECF78(*(char * *)&((struct Obj00000 *)p)->f2C);}


void *func_021EBEE0(char *w, const Desc *s)
{
    void *r = func_0204B294(((struct Obj23997 *)w)->f9E70, (unsigned int)*(void **)(w + s->a * 4 + 0x9FF4),
                            (unsigned int)*(void **)(w + s->b * 4 + 0xA108), (unsigned int)*(void **)(w + s->c * 4 + 0xA134),
                            s, s->d, 0x4C);
    func_0204BA20(r, 0);
    return r;
}

/*
 * Release slot i of the 0x9E74 array when non-null.
 *   CLOSES the register-order residue: `struct S { char pad[0x9E74]; int arr[1]; }`
 *   with `p->arr[i]` gives the image's r4 = p+0x9E74 / r5 = i*4; a plain
 *   `char *p` plus `p + i * 4 + 0x9E74` puts the index in r1 and the constant
 *   in r5 instead.
 */
void func_021EBF34(struct S *p, int i)
{
    if (p->arr[i] != 0) {
        func_0204B3B4((struct Obj *)p->arr[i]);
        p->arr[i] = 0;
    }
}

/*
 * Release all 0x60 slots of the 0x9E70 pool, then release the pool
 *   head itself.
 */
void func_021EBF50(char *p)
{
    unsigned i;
    for (i = 0; i < 0x60; i++)
        func_021EBF34((struct S *)p, i);
    func_0204B1CC((struct Bank *)(((struct Obj07238 *)p)->f9E70));
}

/*
 * Sweep 0x2d slots of the 0x9E74 array, restarting each live one.
 *   The element address must be a named `int *row = (int *)(p + i*4)`
 *   and the offset written as the WORD index row[0x279d]: that is what
 *   puts i in r4, the row in r5 and 0x9E74 in r7 (the flat spelling
 *   swaps r4/r5).
 */
void func_021EBF74(char *p)
{
    unsigned i;
    for (i = 0; i < 0x2d; i++) {
        int *row = (int *)(p + i * 4);
        if (row[0x279d] != 0 && func_0204B944((struct Obj *)row[0x279d]) != 1)
            func_0204B8D4((struct Obj *)row[0x279d], 0x1000);
    }
    func_0204A600();
}

/*
 * Stop and re-issue slot i of the 0x9E74 array; the word is
 *   re-read for the second call.  Writing the array offset before the index
 *   term is what puts the pool constant in r2 and the index in r6.
 */
void func_021EBFA8(char *p, int i, int v)
{
    func_0204B8C4((struct Obj *)(*(int *)(p + 0x9E74 + i * 4)), 0);
    func_0204B878((struct Obj *)(*(int *)(p + 0x9E74 + i * 4)), (unsigned short)v);
}

/*
 * Release-and-flag slot i of the 0x9E74 array.
 */
void func_021EBFCC(char *p, int i, int v)
{
    func_021EBFA8(p, i, v);
    func_0204B92C((struct Obj *)*(int *)(p + i * 4 + 0x9E74), 1);
}


/*
 * Forward the i-th word of the pooled table.
 */
u32 func_021EBFEC(char *p, int i)
{
    return func_0204B98C((struct Actor *)(*(int *)(p + i * 4 + 0x9E74)));
}

/*
 * Release slot i of the 0x9E74 array when it is non-null.
 */
void func_021EC000(char *p, int i, int v)
{
    int x = *(int *)(p + i * 4 + 0x9E74);
    if (x != 0)
        func_0204B3DC((struct Obj *)x, v);
}


u32 func_021EC01C(char *p, int i)
{
    return func_0204B3F4((struct Obj *)(*(int *)(p + i * 4 + 0x9E74)));
}

/*
 * Tail call with the table word at the pooled offset.
 */
void func_021EC030(char *p, int i, int c)
{
    func_0204B84C(*(int *)(p + i * 4 + 0x9E74), (unsigned char)c);
}
