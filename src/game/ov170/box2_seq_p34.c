/*
 * file:     box2_seq_p34.c
 * unit:     yes
 * function: func_021EACFC, func_021EADB4, func_021EAE20, func_021EAE74, func_021EAF20, func_021EAFBC, func_021EB098, func_021EB114, func_021EB190, func_021EB208
 * address:  0x021EACFC
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
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_021EABD0  0x021EABD0  thumb  ov170
 *   func_0201EEA4 0x0201EEA4 thumb
 *   func_021EAC28 0x021EAC28 thumb ov170
 *   func_021EAAE4 0x021EAAE4 thumb ov170
 *   func_021EABA0 0x021EABA0 thumb ov170
 *   func_0201EF14 0x0201EF14 thumb
 *   func_0201D304 0x0201D304 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201EF98 0x0201EF98 thumb
 *   func_0201EF8C 0x0201EF8C thumb
 *   func_0201EF40 0x0201EF40 thumb
 *   func_02045B38 0x02045B38 arm
 *   func_02045C04 0x02045C04 arm
 */
#include "../../matched/include/Obj02053.h"
#include "../../matched/include/Obj18510.h"
#include "../../matched/include/Obj00414.h"
#include "../../matched/include/Obj08243.h"
#include "../../matched/include/Obj06549.h"
#include "../../matched/include/Obj08244.h"

#define WORK(p) (*(char **)((p)+0x2C))
#define W(p) (*(char **)((p)+44))
struct Descriptor;
struct CharBuf;
struct WordSet;
struct StrObj;
struct MsgBank;
struct Rec;
typedef unsigned char u8;

typedef unsigned int u32;

typedef struct { unsigned value; unsigned char pad[14]; unsigned char low:7; unsigned char flag:1; } Entry_021EADB4;

typedef unsigned short u16;

typedef struct { unsigned char pad[18]; unsigned char low : 7; unsigned char flag : 1; unsigned char kind : 4; unsigned char enabled : 1; unsigned char rest : 3; } Entry_021EAE74;

typedef struct { unsigned char pad[18]; unsigned char low : 7; unsigned char flag : 1; unsigned char kind : 4; unsigned char enabled : 1; unsigned char rest : 3; } Entry_021EAF20;

typedef struct { unsigned char pad[18]; unsigned char low:7,high:1; } Entry_021EAFBC;

typedef struct { unsigned char pad[18]; unsigned char low : 7; unsigned char flag : 1; } Entry_021EB098;

typedef struct { unsigned char pad[18]; unsigned char low : 7; unsigned char flag : 1; } Entry_021EB114;

typedef struct { unsigned char pad[18]; unsigned char low : 7; unsigned char flag : 1; } Entry_021EB190;

typedef struct { unsigned char pad[18]; unsigned char low : 7; unsigned char flag : 1; unsigned char kind : 4; unsigned char enabled : 1; unsigned char rest : 3; } Entry_021EB208;

extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_021EABD0(unsigned char *w, int i, void *bank, unsigned idx, int x, int y, unsigned font, unsigned short color);
extern void func_0201EEA4(struct WordSet *p, u32 i, void *mon);
extern void func_021EAC28(char *w, int i, void *bank, u32 idx, int x, int y, u32 font, u16 color);
extern void func_021EAAE4(unsigned char *,unsigned);
extern void func_021EABA0(void **);
extern void func_0201EF14(struct WordSet *p, u32 i, void *mon);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201EF98(struct WordSet *p, u32 i, u32 v);
extern void func_0201EF8C(struct WordSet *p, u32 i, u32 v);
extern void func_0201EF40(struct WordSet *p, u32 i, u32 v);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 func_02045C04(struct Rec *rec);
void func_021EACFC(u8 *p);
void func_021EADB4(unsigned char *w,Entry_021EADB4 *e,unsigned i);
void func_021EAE20(char *p, void **q, int i);
void func_021EAE74(char *p, Entry_021EAE74 *e, unsigned i);
void func_021EAF20(char *p, Entry_021EAF20 *e, unsigned i);
void func_021EAFBC(char *p,const Entry_021EAFBC *e,u32 i);
void func_021EB098(char *p, unsigned char *e, int i);
void func_021EB114(char *p, unsigned char *e, int i);
void func_021EB190(char *p, unsigned char *e, int i);
void func_021EB208(char *p, Entry_021EB208 *e, int i);


void func_021EACFC(u8 *p)
{
    u8 *q = *(u8 * *)&((struct Obj18510 *)p)->f2C;

    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)((struct Obj02053 *)q)->fE4)), 0);
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)((struct Obj02053 *)q)->fEC)), 0);
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)((struct Obj02053 *)q)->fF4)), 0);
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)((struct Obj02053 *)q)->fFC)), 0);
    func_021EABD0(q, 0xa, (void *)(((struct Obj02053 *)q)->f80), 0x6d, 0, 0, ((struct Obj02053 *)q)->f78, 0x440);
    func_021EABD0(q, 0xb, (void *)(((struct Obj02053 *)q)->f80), 0x64, 0, 0, ((struct Obj02053 *)q)->f78, 0x440);
    func_021EABD0(q, 0xc, (void *)(((struct Obj02053 *)q)->f80), 0x65, 0, 0, ((struct Obj02053 *)q)->f78, 0x440);
    func_021EABD0(q, 0xd, (void *)(((struct Obj02053 *)q)->f80), 0x66, 0, 0, ((struct Obj02053 *)q)->f78, 0x440);
}

void func_021EADB4(unsigned char *w,Entry_021EADB4 *e,unsigned i) {
 void **windows;
 windows=(void **)(w+0x94);
 func_02043B5C(func_02045770(windows[i*2]),0);
 if(!e->flag) {
  func_0201EEA4(((struct Obj00414 *)w)->f84,0,(void *)e->value);
  func_021EAC28((char *)w,i,((struct Obj00414 *)w)->f80,0,0,0,((struct Obj00414 *)w)->f78,0x440);
 } else { func_021EAAE4(w,i); return; }
 func_021EABA0(windows+i*2);
}

void func_021EAE20(char *p, void **q, int i)
{
    func_02043B5C(func_02045770(*(void **)(p + 0x94 + i * 8)), 0);
    func_0201EF14(((struct Obj00414 *)p)->f84, 0, *q);
    func_021EAC28(p, i, ((struct Obj00414 *)p)->f80, 1, 0, 0, ((struct Obj00414 *)p)->f78, 0x440);
    func_021EABA0((void **)(p + 0x94 + i * 8));
}

void func_021EAE74(char *p, Entry_021EAE74 *e, unsigned i)
{
    unsigned n;
    func_02043B5C(func_02045770(*(void **)(p + 0x94 + i * 8)), 0);
    if (!e->flag) {
        func_021EAC28(p, i, ((struct Obj00414 *)p)->f80, 107, 0, 0, ((struct Obj00414 *)p)->f78, 0x440);
        n = func_0201D304(((struct Obj00414 *)p)->f88, ((struct Obj00414 *)p)->f78, 0);
        func_0201EFA4(((struct Obj00414 *)p)->f84, 0, e->low, 3, 0, 1);
        func_021EAC28(p, i, ((struct Obj00414 *)p)->f80, 103, n, 0, ((struct Obj00414 *)p)->f78, 0x440);
    } else {
        func_021EAAE4((unsigned char *)p, i); return;
    }
    func_021EABA0((void **)(p + 0x94 + i * 8));
}

/*
 * trailing: two-byte zero alignment padding at 0x021EAFBA.
 */
void func_021EAF20(char *p, Entry_021EAF20 *e, unsigned i)
{
    func_02043B5C(func_02045770(*(void **)(p + 0x94 + i * 8)), 0);
    if (!e->flag && e->enabled == 1) {
        if (e->kind == 0) {
            func_021EABD0((unsigned char *)p, i, ((struct Obj08243 *)p)->f80, 95, 0, 0, ((struct Obj08243 *)p)->f78, 0x14c0);
        } else if (e->kind == 1) {
            func_021EABD0((unsigned char *)p, i, ((struct Obj08243 *)p)->f80, 96, 0, 0, ((struct Obj08243 *)p)->f78, 0xc80);
        } else {
            func_021EAAE4((unsigned char *)p, i); return;
        }
    } else {
        func_021EAAE4((unsigned char *)p, i); return;
    }
    func_021EABA0((void **)(p + 0x94 + i * 8));
}

void func_021EAFBC(char *p,const Entry_021EAFBC *e,u32 i)
{
    u16 n;
    u32 text;
    func_02043B5C(func_02045770(*(void **)(W(p)+i*8+148)),0);
    if (e->high == 0) {
        if (*(u32 *)(W(p)+380) == 1)
            n = ((struct Obj06549 *)e)->f4;
        else
            n = *(u16 *)(*(char **)(W(p)+384)+((struct Obj06549 *)e)->f4*2);
        if (n != 999) {
            func_021EAC28(W(p),i,*(void **)(W(p)+128),108,0,0,*(u32 *)(W(p)+120),1088);
            text=func_0201D304(*(void **)(W(p)+136),*(u32 *)(W(p)+120),0);
            func_0201EFA4(*(void **)(W(p)+132),0,n,3,2,1);
            func_021EAC28(W(p),i,*(void **)(W(p)+128),104,text,0,*(u32 *)(W(p)+120),1088);
        } else { func_021EAAE4((unsigned char *)W(p),i); return; }
    } else { func_021EAAE4((unsigned char *)W(p),i); return; }
    func_021EABA0((void **)(W(p)+148+i*8));
}

void func_021EB098(char *p, unsigned char *e, int i)
{
    func_02043B5C(func_02045770(*(void **)(p + 0x94 + i * 8)), 0);
    if (!((Entry_021EB098 *)e)->flag) {
        func_0201EF98(((struct Obj00414 *)p)->f84, 0, e[15]);
        func_021EAC28(p, i, ((struct Obj00414 *)p)->f80, 98, 0, 0, ((struct Obj00414 *)p)->f78, 0x440);
    } else {
        func_021EABD0((unsigned char *)p, i, ((struct Obj00414 *)p)->f80, 106, 0, 0, ((struct Obj00414 *)p)->f78, 0x440);
    }
    func_021EABA0((void **)(p + 0x94 + i * 8));
}

void func_021EB114(char *p, unsigned char *e, int i)
{
    func_02043B5C(func_02045770(*(void **)(p + 0x94 + i * 8)), 0);
    if (!((Entry_021EB114 *)e)->flag) {
        func_0201EF8C(((struct Obj00414 *)p)->f84, 0, e[14]);
        func_021EAC28(p, i, ((struct Obj00414 *)p)->f80, 97, 0, 0, ((struct Obj00414 *)p)->f78, 0x440);
    } else {
        func_021EABD0((unsigned char *)p, i, ((struct Obj00414 *)p)->f80, 106, 0, 0, ((struct Obj00414 *)p)->f78, 0x440);
    }
    func_021EABA0((void **)(p + 0x94 + i * 8));
}

void func_021EB190(char *p, unsigned char *e, int i)
{
    func_02043B5C(func_02045770(*(void **)(p + 0x94 + i * 8)), 0);
    if (((struct Obj06549 *)e)->f6 != 0) {
        func_0201EF40(((struct Obj00414 *)p)->f84, 0, ((struct Obj06549 *)e)->f6);
        func_021EAC28(p, i, ((struct Obj00414 *)p)->f80, 99, 0, 0, ((struct Obj00414 *)p)->f78, 0x440);
    } else {
        func_021EABD0((unsigned char *)p, i, ((struct Obj00414 *)p)->f80, 105, 0, 0, ((struct Obj00414 *)p)->f78, 0x440);
    }
    func_021EABA0((void **)(p + 0x94 + i * 8));
}

/*
 * note 2026-10-05 (wave D9r lane 131): removed the dead first assignment
 * (`windows = (void **)p;` before `windows = (void **)(p + 0x94);`). Game
 * code has no line table, so these were stand-ins. The plain single
 * assignment gives EXACT in --lang c99 and --lang c: the output bytes do not
 * change. Older text in this header that asks for the double assignment is
 * superseded.
 */
void func_021EB208(char *p, Entry_021EB208 *e, int i)
{
    void **windows;
    unsigned j;
    void *bank;
    windows = (void **)(p + 0x94);
    func_02043B5C(func_02045770(windows[i * 2]), 0);
    j = 0;
    bank = func_02045B38(0, 2, 203, 0x804c);
    if (!e->flag) {
        for (; j < 4; j++) {
            func_021EABD0((unsigned char *)p, i, bank, *(unsigned short *)((char *)e + 0x14 + j * 2), 0, j * 16, ((struct Obj08244 *)p)->f78, 0x440);
        }
    } else {
        func_021EABD0((unsigned char *)p, i, ((struct Obj08244 *)p)->f80, 106, 0, 0, ((struct Obj08244 *)p)->f78, 0x440);
    }
    func_02045C04(bank);
    func_021EABA0(windows + i * 2);
}
