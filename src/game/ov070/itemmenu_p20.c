/*
 * file:     itemmenu_p20.c
 * unit:     yes
 * function: func_021BB08C, func_021BB0BC, func_021BB0F8, func_021BB1AC, func_021BB1C4, func_021BB260, func_021BB368, func_021BB398, func_021BB3F4, func_021BB580, func_021BB5A4, func_021BB5DC, func_021BB690, func_021BB6E0, func_021BB724
 * address:  0x021BB08C
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204B3DC 0x0204B3DC arm
 *   func_020456F8 0x020456F8 arm
 *   func_021BAFC4 0x021BAFC4 thumb ov070
 *   func_021BAF38 0x021BAF38 thumb ov070
 *   func_020457B0  0x020457B0  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_02027778  0x02027778  thumb
 *   func_02045808  0x02045808  arm
 *   func_02027858 0x02027858 thumb
 *   func_020490F4  0x020490F4  arm
 *   func_0204A380  0x0204A380  arm
 *   func_02062B30  0x02062B30  arm
 *   func_02041090  0x02041090  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02049238  0x02049238  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_021B619C  0x021B619C  thumb  ov070
 *   func_0204B454  0x0204B454  arm
 *   func_0204B6F4  0x0204B6F4  arm
 *   func_02012BF8  0x02012BF8  thumb
 *   func_020056BC  0x020056BC  thumb
 *   func_0202173C  0x0202173C  thumb
 *   func_020216D4  0x020216D4  thumb
 *   func_0207D658  0x0207D658  arm
 *   func_0204B878  0x0204B878  arm
 *   func_0204B3F4  0x0204B3F4  arm
 *   func_021B61C8 0x021B61C8 thumb ov070
 *   func_0204B404 0x0204B404 arm
 *   d_021BBBCC 0x021BBBCC data a4
 *   func_0201C724  0x0201C724  thumb
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 */
#include "../../matched/include/Obj09883.h"
#include "../../matched/include/Obj06179.h"
#include "../../matched/include/Obj00002.h"
#include "../../matched/include/Obj13159.h"
#include "../../matched/include/Obj20676.h"
#include "../../matched/include/Obj13160.h"
#include "../../matched/include/Obj01516.h"

struct Descriptor;
struct Obj;
struct MsgBank;
struct U16Vec;
struct TaskMenu;
struct TaskMenuTmpl;
struct CharBuf;
struct WordSet;
struct Actor;
struct PtS;
struct PalAnmSlot;
struct Vec2;
struct Cfg;
typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef struct {
    int a;
    u8 b;
    u8 pad[3];
    int c;
    int d;
    u8 e;
    u8 f;
    u8 g;
    u8 h;
} Desc;

typedef struct {
    u16 w;
    u16 h;
    u16 pad[4];
    u16 d[1];
} Img;

typedef struct {
    u8 pad0[0x544];
    u16 f544;
    u8 pad1[0x808 - 0x546];
    int f808;
} Work;

typedef short s16_021BB260;

typedef short s16_021BB3F4;

typedef signed short s16_021BB6E0;

extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_020456F8(struct Descriptor *d);
extern void func_021BAFC4(u8 *p);
extern void func_021BAF38(int, int);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern struct TaskMenu *func_02027778(struct TaskMenuTmpl *tmpl, void *arg1);
extern void func_02045808(struct U16Vec *vec);
extern void func_02027858(struct TaskMenu *m);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void *func_0204A380(void *a0, unsigned int a1, unsigned int a2, unsigned int a3);
extern int func_02062B30(void *file, void **out);
extern void func_02041090(unsigned int index, unsigned int a1, unsigned int a2, unsigned int a3, u8 a4, u8 a5);
extern void func_02041B6C(u32 bit);
extern u32 func_020307B0(void *p);
extern void func_02049238(void *);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern int func_021B619C(int a, int b, unsigned int id);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern int func_02012BF8(int, int);
extern u32 func_020056BC(void);
extern int func_0202173C(int p, u16 mask, u16 col, s16_021BB3F4 step, u8 b, u8 c, u16 d, u32 ctx);
extern void func_020216D4(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
extern void func_0207D658(u32 addr, int plane, int brightness);
extern void func_0204B878(struct Obj *p, u16 value);
extern u32 func_0204B3F4(struct Obj *p);
extern int func_021B61C8(u8 *p);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02045374(struct Cfg *);
extern u8 func_02045730(struct Descriptor *);
void func_021BB08C(char *p);
void func_021BB0BC(char *p);
void func_021BB0F8(int p);
void func_021BB1AC(char *p);
void func_021BB1C4(Work *p);
void func_021BB260(u8 *p, int val);
int func_021BB368(int x);
void func_021BB398(int p, u32 val);
void func_021BB3F4(int p, int mode);
void func_021BB580(char *p, int v);
void func_021BB5A4(char *p);
void func_021BB5DC(int p, int mode);
int func_021BB690(const char *p);
void func_021BB6E0(int p, u32 *obj, u32 str, u16 x, s16_021BB6E0 y, u16 color);
void func_021BB724(void **p);
extern short d_021BBBCC[];

void func_021BB08C(char *p) { func_0204B3DC(((struct Obj09883 *)p)->f710, 0); func_0204B3DC(((struct Obj09883 *)p)->f714, 0); func_020456F8(((struct Obj09883 *)p)->f504); func_021BAFC4((u8 *)p); }

void func_021BB0BC(char *p) { func_0204B3DC(((struct Obj06179 *)p)->f710, 1); func_0204B3DC(((struct Obj06179 *)p)->f714, 1); func_020456F8(((struct Obj06179 *)p)->f764); func_020456F8(((struct Obj06179 *)p)->f75C); func_021BAF38((int)p, ((struct Obj06179 *)p)->f80C); }


void func_021BB0F8(int p)
{
    Desc s;
    int h;
    int r;

    h = ((struct Obj00002 *)p)->f544;
    s.a = h;
    s.b = 2;
    s.c = p + 0x780;
    s.d = 1;
    s.e = 0x20;
    s.f = 0xC;
    s.g = 8;
    s.h = 3;
    r = (int)func_020457B0(0x64, h);
    ((struct Obj00002 *)p)->f780 = r;
    func_02045CAC((struct MsgBank *)(*(int *)&((struct Obj00002 *)p)->f51C), 0x84, (void *)r);
    ((struct Obj00002 *)p)->f784 = 0x39E0;
    ((struct Obj00002 *)p)->f788 = 0;
    r = (int)func_020457B0(0x64, ((struct Obj00002 *)p)->f544);
    ((struct Obj00002 *)p)->f78C = r;
    func_02045CAC((struct MsgBank *)(*(int *)&((struct Obj00002 *)p)->f51C), 0x85, (void *)r);
    ((struct Obj00002 *)p)->f790 = 0x39E0;
    ((struct Obj00002 *)p)->f794 = 0;
    *(int *)&((struct Obj00002 *)p)->f77C = (int)func_02027778((struct TaskMenuTmpl *)(&s), (void *)(((struct Obj00002 *)p)->f7E0));
    func_02045808((struct U16Vec *)(((struct Obj00002 *)p)->f780));
    func_02045808((struct U16Vec *)(((struct Obj00002 *)p)->f78C));
    func_021BB580((char *)p, 0);
    func_021BB3F4(p, 0);
}

void func_021BB1AC(char *p) { func_02027858(((struct Obj13159 *)p)->f77C); ((struct Obj13159 *)p)->f77C = 0; }


void func_021BB1C4(Work *p)
{
    void *arc;
    int tex;
    Img *img;
    int i;
    u16 *d;
    int n;

    arc = func_020490F4(0x58, p->f544);
    tex = (int)func_0204A380(arc, 0x23, 0, p->f544);
    i = 0;
    if (func_02062B30((void *)tex, (void **)(&img))) {
        d = img->d;
        n = ((unsigned)img->w >> 3) * ((unsigned)img->h >> 3);
        for (; i < n; i++) {
            d[i] += (u16)((u16)p->f808 | 0x3000);
        }
        func_02041090(3, (unsigned int)img->d, 0x10, 0xC, (unsigned)img->w >> 3, (unsigned)img->h >> 3);
        func_02041B6C(3);
    }
    func_020307B0((void *)tex);
    func_02049238(arc);
}


void func_021BB260(u8 *p, int val)
{
    int v;
    u32 *win2;
    u32 *win;

    win = (u32 *)(p + 0x754);

    func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)*win)), 5);
    func_02045CAC((struct MsgBank *)(*(int *)&((struct Obj00002 *)p)->f51C), 0x83, (void *)(*(int *)&((struct Obj00002 *)p)->f524));
    func_0201EFA4((struct WordSet *)(*(int *)&((struct Obj00002 *)p)->f520), 0, val, 3, 0, 1);
    func_0201F250((struct WordSet *)(*(int *)&((struct Obj00002 *)p)->f520), (void *)(*(int *)&((struct Obj00002 *)p)->f528), (void *)(*(int *)&((struct Obj00002 *)p)->f524));
    func_021BB6E0((int)p, win, *(u32 *)&((struct Obj00002 *)p)->f528, 0, 0, 0x3DC5);
    func_021BB724((void **)win);
    if (((struct Obj00002 *)p)->f7EC == 2) {
        win2 = (u32 *)(p + 0x76C);
        v = func_021B619C(((struct Obj00002 *)p)->f84C, ((struct Obj00002 *)p)->f7F4, ((struct Obj00002 *)p)->f544);
        func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)*win2)), 5);
        func_02045CAC((struct MsgBank *)(*(int *)&((struct Obj00002 *)p)->f51C), 0x54, (void *)(*(int *)&((struct Obj00002 *)p)->f524));
        func_0201EFA4((struct WordSet *)(*(int *)&((struct Obj00002 *)p)->f520), 0, v, 7, 0, 1);
        func_0201F250((struct WordSet *)(*(int *)&((struct Obj00002 *)p)->f520), (void *)(*(int *)&((struct Obj00002 *)p)->f528), (void *)(*(int *)&((struct Obj00002 *)p)->f524));
        func_021BB6E0((int)p, win2, *(u32 *)&((struct Obj00002 *)p)->f528, 0, 0, 0x3DC5);
        func_021BB724((void **)win2);
    }
}

int func_021BB368(int x)
{
    switch (x) {
    case 0:
        return 10;
    case 3:
        return 13;
    case 1:
        return 11;
    case 2:
        return 12;
    case 4:
        return 14;
    }
    return x;
}


void func_021BB398(int p, u32 val)
{
    short b[2];
    short a[2];
    unsigned i;

    func_0204B454((struct Actor *)((struct Obj20676 *)p)->f6A4, (struct PtS *)b, 0);
    for (i = 0; i < 8; i++) {
        func_0204B454((struct Actor *)*(int *)(p + i * 4 + 0x634), (struct PtS *)a, 0);
        if (a[1] == b[1]) {
            break;
        }
    }
    func_0204B6F4((struct Obj *)(*(int *)(p + i * 4 + 0x634)), (u8)val, 0);
}


void func_021BB3F4(int p, int mode)
{
    int r;

    if (((struct Obj00002 *)p)->f858 == mode) {
        return;
    }
    ((struct Obj00002 *)p)->f858 = mode;
    r = func_02012BF8(*(int *)&((struct Obj00002 *)p)->f0, func_021BB368(((struct Obj00002 *)p)->f80C));
    if (mode == 1) {
        func_0202173C(((struct Obj00002 *)p)->f854, 4, 0x23CF, 0, 0, 0, 0, func_020056BC());
        func_0202173C(((struct Obj00002 *)p)->f854, 1, 1, 0, 0, 0, 0, func_020056BC());
        func_0207D658(0x04000050, 6, 0);
        func_021BB5A4((char *)p);
        func_0204B878((struct Obj *)(((struct Obj00002 *)p)->f710), 4);
        func_0204B878((struct Obj *)(((struct Obj00002 *)p)->f714), 5);
        func_0204B878((struct Obj *)(((struct Obj00002 *)p)->f71C), 0);
        if (r == 1) {
            func_0204B878((struct Obj *)(((struct Obj00002 *)p)->f718), 7);
        } else {
            func_0204B878((struct Obj *)(((struct Obj00002 *)p)->f718), 6);
        }
        func_021BB580((char *)p, 1);
    } else {
        func_020216D4((struct PalAnmSlot *)(((struct Obj00002 *)p)->f854), 2, 0, 0x200);
        func_0202173C(((struct Obj00002 *)p)->f854, 4, 0x23CF, 0, 8, 8, 0, func_020056BC());
        func_0202173C(((struct Obj00002 *)p)->f854, 1, 1, 0, 8, 8, 0, func_020056BC());
        if (((struct Obj00002 *)p)->f10 == 4 && func_0204B3F4((struct Obj *)(((struct Obj00002 *)p)->f710)) == 0) {
            func_0207D658(0x04000050, 2, -8);
        } else {
            func_0207D658(0x04000050, 6, -8);
        }
        func_0204B878((struct Obj *)(*(int *)&((struct Obj00002 *)p)->f72C), 4);
        func_0204B878((struct Obj *)(((struct Obj00002 *)p)->f710), 0x12);
        func_0204B878((struct Obj *)(((struct Obj00002 *)p)->f714), 0x13);
        func_0204B878((struct Obj *)(((struct Obj00002 *)p)->f71C), 0xE);
        if (r == 1) {
            func_0204B878((struct Obj *)(((struct Obj00002 *)p)->f718), 0x16);
        } else {
            func_0204B878((struct Obj *)(((struct Obj00002 *)p)->f718), 0x15);
        }
    }
}

void func_021BB580(char *p, int v) { if (v == 1) func_0204B878(((struct Obj13160 *)p)->f720, 1); else func_0204B878(((struct Obj13160 *)p)->f720, 15); }

void func_021BB5A4(char *p) { if (((struct Obj00002 *)p)->f80C == 2 || ((struct Obj00002 *)p)->f80C == 3 || func_021B61C8((u8 *)p) <= 1) func_0204B878(((struct Obj00002 *)p)->f72C, 4); else func_0204B878(((struct Obj00002 *)p)->f72C, 0); }


void func_021BB5DC(int p, int mode)
{
    int r = func_02012BF8(*(int *)&((struct Obj00002 *)p)->f0, func_021BB368(((struct Obj00002 *)p)->f80C));

    if (mode == 1) {
        func_021BB5A4((char *)p);
        func_0204B878((struct Obj *)(((struct Obj00002 *)p)->f710), 4);
        func_0204B878((struct Obj *)(((struct Obj00002 *)p)->f714), 5);
        func_0204B878((struct Obj *)(((struct Obj00002 *)p)->f71C), 0);
        if (r == 1) {
            func_0204B878((struct Obj *)(((struct Obj00002 *)p)->f718), 7);
        } else {
            func_0204B878((struct Obj *)(((struct Obj00002 *)p)->f718), 6);
        }
    } else {
        func_0204B878((struct Obj *)(*(int *)&((struct Obj00002 *)p)->f72C), 4);
        func_0204B878((struct Obj *)(((struct Obj00002 *)p)->f710), 0x12);
        func_0204B878((struct Obj *)(((struct Obj00002 *)p)->f714), 0x13);
        func_0204B878((struct Obj *)(((struct Obj00002 *)p)->f71C), 0xE);
        if (r == 1) {
            func_0204B878((struct Obj *)(((struct Obj00002 *)p)->f718), 0x16);
        } else {
            func_0204B878((struct Obj *)(((struct Obj00002 *)p)->f718), 0x15);
        }
    }
}

/*
 * lever: expand q at the first call but retain q for the second call.
 */
int func_021BB690(const char *p)
{
    unsigned i;
    short v[2];
    const char *q;
    int off;
    for (i = 0; i < 5; i++) {
        off = i * 4;
        q = p + off;
        func_0204B454((struct Actor *)*((int *)((p + off) + 0x6AC)), (struct PtS *)v, 0xFFFF);
        if (v[0] == *((short *)(((char *)d_021BBBCC) + off))) {
            return 0;
        }
        v[0] = v[0] + 4;
        func_0204B404((struct Obj *)(*((int *)(q + 0x6AC))), (const struct Vec2 *)v, 0xFFFF);
    }
    return 1;
}


void func_021BB6E0(int p, u32 *obj, u32 str, u16 x, s16_021BB6E0 y, u16 color)
{
    u32 print = ((struct Obj01516 *)p)->f50C;

    func_0201C724((void *)print, (u32)func_02045770((struct Descriptor *)*obj), (s16_021BB6E0)x, y, str, ((struct Obj01516 *)p)->f530, color);
    *((unsigned char *)obj + 4) = 1;
}

void func_021BB724(void **p)
{
    func_02045374(*p);
    func_02041B6C(func_02045730(*p));
}
