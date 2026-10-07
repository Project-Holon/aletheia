/*
 * file:     psel_p08.c
 * unit:     yes
 * function: func_021BAE00, func_021BAEE0, func_021BAF30, func_021BAF48, func_021BAFC4, func_021BB0B0, func_021BB134, func_021BB18C, func_021BB274, func_021BB2A4, func_021BB35C, func_021BB38C, func_021BB3AC, func_021BB3BC, func_021BB424
 * address:  0x021BAE00
 * region:   ov223
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   table 0x021BC770 data a1
 *   func_02049B40 0x02049B40 arm
 *   func_02045B38 0x02045B38 arm
 *   func_0203101C 0x0203101C arm
 *   func_0201DD78 0x0201DD78 thumb
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_0201CE48 0x0201CE48 thumb
 *   func_02045808 0x02045808 arm
 *   func_020452E8 0x020452E8 arm
 *   func_02031140 0x02031140 arm
 *   func_02045C04 0x02045C04 arm
 *   func_020310C4  0x020310C4  arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201D304 0x0201D304 thumb
 *   func_0201D42C 0x0201D42C thumb
 *   func_020437DC 0x020437DC arm
 *   func_020437E4 0x020437E4 arm
 *   func_02012FFC 0x02012FFC thumb
 *   func_0201CCE4 0x0201CCE4 thumb
 *   func_0203630C  0x0203630C  arm
 *   func_02035C38  0x02035C38  arm
 *   func_020362DC  0x020362DC  arm
 *   func_02035C60  0x02035C60  arm
 *   func_0201EC64 0x0201EC64 thumb
 *   func_020457B0 0x020457B0 arm
 *   func_0201EE60 0x0201EE60 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   func_0201C724 0x0201C724 thumb
 *   d_021BC730 0x021BC730 data a4
 *   d_021BC710 0x021BC710 data a2
 *   func_02027F60 0x02027F60 thumb
 *   func_02027FD8  0x02027FD8  thumb
 *   func_02027FEC 0x02027FEC thumb
 *   func_02028148 0x02028148 thumb
 *   func_02028178 0x02028178 thumb
 *   func_02028218 0x02028218 thumb
 *   func_0202822C 0x0202822C thumb
 *   func_02028230 0x02028230 thumb
 */
#include "../../matched/include/Obj00739.h"
#include "../../matched/include/Obj02266.h"
#include "../../matched/include/Obj08461.h"
#include "../../matched/include/Obj26093.h"
#include "../../matched/include/Obj00084.h"
#include "../../matched/include/Obj03381.h"

struct MsgBank;
struct Tcbl;
struct Descriptor;
struct CharBuf;
struct Rec3;
struct U16Vec;
struct S02031140;
struct Rec;
struct Cfg;
struct PrintSys;
struct StrObj;
struct Bmp;
struct WordSet;
struct R;
struct TaskMenuState;
struct Obj;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

typedef struct {u8 a,b,c,d,e,f,g,h,i;} Entry;

typedef signed short s16;

typedef signed int     s32;

struct Item { void *text; u16 color; unsigned value; };

extern void func_02049B40(u32,u32,u32,u32,u32,u16);
extern struct MsgBank *func_02045B38(u32,u32,u32,u32);
extern struct Tcbl *func_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
extern void func_0201DD78(u32,u32,u32);
extern u32 func_020450F0(u32,u32,u32,u32,u8,u8,u8);
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(struct CharBuf *,u8);
extern void func_02045334(struct Descriptor *);
extern void func_0201CE48(struct Rec3 *);
extern void func_02045808(struct U16Vec *);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_02031140(struct S02031140 *);
extern u32 func_02045C04(struct Rec *rec);
extern void func_020310C4(struct Tcbl *p);
extern unsigned func_0201C6C4(struct PrintSys *, void *);
extern void func_02045374(struct Cfg *);
extern u8 func_02045730(struct Descriptor *);
extern void func_02041B6C(unsigned);
extern void *func_02045EC0(struct MsgBank *, unsigned);
extern unsigned func_0201D304(struct StrObj *, unsigned, unsigned);
extern unsigned func_0201D42C(struct StrObj *, void *);
extern u16 func_020437DC(const struct Bmp *bmp);
extern u16 func_020437E4(const struct Bmp *bmp);
extern signed char func_02012FFC(void);
extern u32 func_0201CCE4(u32, u32, u32, u32, u32, u32, u32, u32, u32, u32);
extern u32 func_0201CE30(void *p);
extern void func_0201CE5C(struct Rec *p, s32 v);
extern void func_0201CE38(void *p);
extern unsigned int func_0203630C(void);
extern int func_02035C38(void);
extern u32 func_020362DC(void);
extern int func_02035C60(void);
extern struct WordSet *func_0201EC64(u32 heap);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_0201EE60(struct WordSet *p, u32 i, u16 v);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u32 func_0201ED04(struct WordSet *p);
extern void func_0201C724(void *, unsigned, unsigned, unsigned, unsigned, unsigned, u16);
extern struct R *func_02027F60(u16,u16,u32,u32,u16);
extern u32 func_02027FD8(struct TaskMenuState *s);
extern unsigned func_02027FEC(unsigned, unsigned, unsigned, unsigned, u8, u16);
extern void func_02028148(u8 *);
extern void func_02028178(u8 *);
extern void func_02028218(struct Obj *,u32);
extern void func_0202822C(char *,int);
extern u32 func_02028230(u8 *);
void func_021BAE00(char *p);
void func_021BAEE0(char *p);
void func_021BAF30(int *p);
int func_021BAF48(char *p);
void func_021BAFC4(char *p, int idx);
int func_021BB0B0(char *a);
void func_021BB134(char *p);
void func_021BB18C(char *p, int idx);
void func_021BB274(char *p);
void func_021BB2A4(char *p);
void func_021BB35C(char *p);
void func_021BB38C(char *p);
int func_021BB3AC(int *p);
void func_021BB3BC(char *p);
void func_021BB404(char *p);
void func_021BB414(char *p);
void func_021BB424(char *p);
u32 func_021BB440(char *p);
extern const Entry table[];
extern const u32 d_021BC730[];
extern const u16 d_021BC710[];

void func_021BAE00(char *p)
{
    u8 i=0;
    func_02049B40(23,5,0,448,32,((struct Obj00739 *)p)->f0);
    func_02049B40(23,5,4,32,32,((struct Obj00739 *)p)->f0);
    *(struct MsgBank * *)&((struct Obj00739 *)p)->f234=func_02045B38(0,3,430,((struct Obj00739 *)p)->f0);
    *(struct Tcbl * *)&((struct Obj00739 *)p)->f254=func_0203101C(((struct Obj00739 *)p)->f0,((struct Obj00739 *)p)->f0,1,0);
    func_0201DD78(15,2,0);
    for(;i<3;i++) {
        *(u32 *)(p+i*4+568)=func_020450F0(table[i].a,table[i].b,table[i].c,table[i].d,table[i].e,table[i].f,table[i].g);
        func_02043B5C(func_02045770(*(struct Descriptor **)(p+i*4+568)),0);
        func_02045334(*(struct Descriptor **)(p+i*4+568));
        *(u32 *)(p+i*4+580)=1;
    }
    ((struct Obj00739 *)p)->f250=0;((struct Obj00739 *)p)->f258=0;
}

void func_021BAEE0(char *p)
{
    u8 i;
    if (*(struct Rec3 * *)&((struct Obj02266 *)p)->f250)
        func_0201CE48(*(struct Rec3 * *)&((struct Obj02266 *)p)->f250);
    if (*(struct U16Vec * *)&((struct Obj02266 *)p)->f258)
        func_02045808(*(struct U16Vec * *)&((struct Obj02266 *)p)->f258);
    for (i = 0; i < 3; i++)
        func_020452E8(*(struct Descriptor **)(p + 0x238 + i * 4));
    func_02031140(*(struct S02031140 * *)&((struct Obj02266 *)p)->f254);
    func_02045C04(*(struct Rec * *)&((struct Obj02266 *)p)->f234);
}


void func_021BAF30(int *p)
{
    func_020310C4((struct Tcbl *)p[0x95]);
    func_021BAF48((char *)p);
}

/*
 * Trailing AFC2 halfword is zero alignment padding. Forming q = p + i*4
 * before fixed field offsets retains the observed invariant constants;
 * computing p + constant + i*4 instead hoists pointer bases and spills p.
 */
int func_021BAF48(char *p)
{
    int finished = 1;
    u8 i;
    for (i = 0; i < 3; i++) {
        char *q = p + i * 4;
        if (((struct Obj08461 *)q)->f244 == 0) {
            if (func_0201C6C4(*(struct PrintSys * *)&((struct Obj26093 *)p)->f1C,
                            func_02045770(*(struct Descriptor * *)&((struct Obj08461 *)q)->f238)) != 0) {
                finished = 0;
            } else {
                struct Descriptor *d = *(struct Descriptor * *)&((struct Obj08461 *)q)->f238;
                func_02045334(d);
                func_02045374((struct Cfg *)d);
                func_02041B6C(func_02045730(d));
                ((struct Obj08461 *)q)->f244 = 1;
            }
        }
    }
    return finished;
}

void func_021BAFC4(char *p, int idx)
{
    struct Descriptor *desc = *(struct Descriptor **)(p + 0x23C);
    s16 x = 0;
    s16 y = 0;
    unsigned w, h;
    unsigned W, H;
    func_02043B5C((struct CharBuf *)func_02045770(desc), 0);
    if (*(u32 *)(p + 0x250) != 0)
        func_0201CE48(*(struct Rec3 **)(p + 0x250));
    if (*(u32 *)(p + 0x258) != 0)
        func_02045808(*(struct U16Vec **)(p + 0x258));
    *(void **)(p + 0x258) = func_02045EC0(*(struct MsgBank **)(p + 0x234), idx);
    w = (u16)func_0201D304(*(struct StrObj **)(p + 0x258), *(unsigned *)(p + 0x18), 0);
    h = (u16)func_0201D42C(*(struct StrObj **)(p + 0x258), *(void **)(p + 0x18));
    W = func_020437DC(func_02045770(desc));
    H = func_020437E4(func_02045770(desc));
    if (W > w)
        x = ((int)(W - w)) / 2;
    if (H > h)
        y = ((int)(H - h)) / 2;
    *(u32 *)(p + 0x250) = func_0201CCE4((u32)desc, x, y, *(u32 *)(p + 0x258), *(u32 *)(p + 0x18), func_02012FFC(),
                                         *(u32 *)(p + 0x254), 2, *(u16 *)p, 0);
    func_02045334(desc);
    func_02045374((struct Cfg *)desc);
    func_02041B6C(func_02045730(desc));
}


int func_021BB0B0(char *a)
{
    int r = 0;

    switch (func_0201CE30((void *)(*(u32 *)&((struct Obj00084 *)a)->f250))) {
    case 0:
        if ((func_0203630C() & 3) != 0 || func_02035C38() != 0) {
            func_0201CE5C((struct Rec *)(*(u32 *)&((struct Obj00084 *)a)->f250), 0);
            if ((func_0203630C() & 3) != 0)
                ((struct Obj00084 *)a)->f8 = 0;
            else
                ((struct Obj00084 *)a)->f8 = 1;
        }
        break;
    case 1:
        if ((func_020362DC() & 3) != 0 || func_02035C60() != 0) {
            func_0201CE38((void *)(*(u32 *)&((struct Obj00084 *)a)->f250));
            if ((func_020362DC() & 3) != 0)
                ((struct Obj00084 *)a)->f8 = 0;
            else
                ((struct Obj00084 *)a)->f8 = 1;
        }
        break;
    case 2:
        r = 1;
        break;
    }
    return r;
}

void func_021BB134(char *p)
{
    struct Descriptor *d;
    func_02043B5C(func_02045770(*(struct Descriptor * *)&((struct Obj00084 *)p)->f23C), 0);
    d = *(struct Descriptor * *)&((struct Obj00084 *)p)->f23C;
    func_02045334(d);
    func_02045374((struct Cfg *)d);
    func_02041B6C(func_02045730(d));
    if (*(struct Rec3 * *)&((struct Obj00084 *)p)->f250)
        func_0201CE48(*(struct Rec3 * *)&((struct Obj00084 *)p)->f250);
    *(int *)&((struct Obj00084 *)p)->f250 = 0;
    if (*(struct U16Vec * *)&((struct Obj00084 *)p)->f258)
        func_02045808(*(struct U16Vec * *)&((struct Obj00084 *)p)->f258);
    *(int *)&((struct Obj00084 *)p)->f258 = 0;
}

/*
 * note: 2026-10-05 (wD8 lane03): EXACT. The 0x24C slot is a pointer local `flag = (u32 *)(p + 0x24C)`
 *   set right after the desc load and written at the end (`*flag = 0`). mwcc keeps the 0x240 base from
 *   the desc load in r4, derives 0x24C from it at the top, spills only the offset and uses [r5,r0] at the
 *   store. The k/off locals and the enum type of earlier drafts are gone.
 */
void func_021BB18C(char *p, int idx)
{
    struct Descriptor *desc;
    u16 x;
    void *words;
    void *text;
    u32 *flag;
    struct StrObj *buf;
    u16 height;
    unsigned h;
    desc = *(struct Descriptor **)(p + 0x240);
    flag = (u32 *)(p + 0x24C);
    x = 0;
    words = func_0201EC64(*(u16 *)p);
    text = func_02045EC0(*(struct MsgBank **)(p + 0x234), d_021BC730[idx]);
    buf = (struct StrObj *)func_020457B0(0x40, *(u16 *)p);
    func_0201EE60(words, 1, d_021BC710[idx]);
    func_0201F250(words, buf, text);
    func_02045808((struct U16Vec *)text);
    func_0201ED04(words);
    func_02043B5C((struct CharBuf *)func_02045770(desc), 0);
    func_0201D304(buf, *(unsigned *)(p + 0x18), 0);
    height = func_0201D42C(buf, *(void **)(p + 0x18));
    func_020437DC(func_02045770(desc));
    h = func_020437E4(func_02045770(desc));
    if (h > height)
        x = ((int)h - height) / 2;
    func_0201C724(*(void **)(p + 0x1C), (unsigned)func_02045770(desc), 0, (s16)x, (unsigned)buf, *(unsigned *)(p + 0x18), 0x3C40);
    func_02045808((struct U16Vec *)buf);
    *flag = 0;
    func_021BAF48(p);
}

void func_021BB274(char *p) {struct Descriptor *d;u32 off;off=0x240;func_02043B5C(func_02045770(*(struct Descriptor **)(p+off)),0);d=*(struct Descriptor **)(p+off);func_02045334(d);func_02045374((struct Cfg *)d);func_02041B6C(func_02045730(d));}

/*
 * Declare width before the zero x initializer: its store shares the
 * upcoming call's zero r2; const p left the six-byte scheduling diff.
 * The bitmap accessors' own sources return u16. This caller uses each
 * result at full width without truncation, so its declarations widen them.
 */
void func_021BB2A4(char *p)
{
    struct StrObj *text = func_02045EC0(*(struct MsgBank * *)&((struct Obj03381 *)p)->f234, 12);
    u16 width = func_0201D304(text, *(unsigned *)&((struct Obj03381 *)p)->f18, 0);
    u16 x = 0;
    u16 height = func_0201D42C(text, ((struct Obj03381 *)p)->f18);
    unsigned w = func_020437DC(func_02045770(*(struct Descriptor * *)&((struct Obj03381 *)p)->f238));
    unsigned h = func_020437E4(func_02045770(*(struct Descriptor * *)&((struct Obj03381 *)p)->f238));
    u16 y = 0;
    if (w > width)
        x = ((int)w - width) / 2;
    if (h > height)
        y = ((int)h - height) / 2;
    func_0201C724(((struct Obj03381 *)p)->f1C, (unsigned)func_02045770(*(struct Descriptor * *)&((struct Obj03381 *)p)->f238),
                 (s16)x, (s16)y, (unsigned)text, *(unsigned *)&((struct Obj03381 *)p)->f18, 0x3C40);
    func_02045808((struct U16Vec *)text);
    ((struct Obj03381 *)p)->f244 = 0;
    func_021BAF48(p);
}

void func_021BB35C(char *p) {struct Descriptor *d;u32 off;off=0x238;func_02043B5C(func_02045770(*(struct Descriptor **)(p+off)),0);d=*(struct Descriptor **)(p+off);func_02045334(d);func_02045374((struct Cfg *)d);func_02041B6C(func_02045730(d));}

void func_021BB38C(char *p) {*(struct R * *)&((struct Obj00739 *)p)->f25C=func_02027F60(3,11,*(u32 *)&((struct Obj00739 *)p)->f18,((struct Obj00739 *)p)->f1C,((struct Obj00739 *)p)->f0);}


int func_021BB3AC(int *p)
{
    return func_02027FD8((struct TaskMenuState *)p[0x97]);
}

/*
 * The lead's EXACT* ends at BB404; two complete 16-byte load/tail-call
 * followers cover the remaining extent. Parent cleared both starts.
 */
void func_021BB3BC(char *p)
{
    struct Item item;
    item.text = func_02045EC0(*(struct MsgBank * *)&((struct Obj00084 *)p)->f234, 21);
    item.color = 0x39E3;
    item.value = 0;
    *(unsigned *)&((struct Obj00084 *)p)->f260 = func_02027FEC(*(unsigned *)&((struct Obj00084 *)p)->f25C, (unsigned)&item, 9, 21, 14, ((struct Obj00084 *)p)->f0);
    func_02045808(item.text);
}

void func_021BB404(char *p)
{
    func_02028148(*(u8 * *)&((struct Obj00084 *)p)->f260);
}

void func_021BB414(char *p)
{
    func_02028178(*(u8 * *)&((struct Obj00084 *)p)->f260);
}

void func_021BB424(char *p) {u32 off;off=0x260;func_02028218(*(struct Obj **)(p+off),1);func_0202822C(*(char **)(p+off),1);}

u32 func_021BB440(char *p) {return func_02028230(*(u8 * *)&((struct Obj00084 *)p)->f260);}
