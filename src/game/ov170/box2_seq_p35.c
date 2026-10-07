/*
 * file:     box2_seq_p35.c
 * unit:     yes
 * function: func_021EB2A4, func_021EB324, func_021EB378, func_021EB6D8, func_021EB6F0, func_021EB708, func_021EB744, func_021EB79C, func_021EB7C8, func_021EB7E8
 * address:  0x021EB2A4
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
 *   func_021EADB4  0x021EADB4  thumb  ov170
 *   func_021EAE20  0x021EAE20  thumb  ov170
 *   func_021EAE74  0x021EAE74  thumb  ov170
 *   func_021EAF20  0x021EAF20  thumb  ov170
 *   func_021EAFBC  0x021EAFBC  thumb  ov170
 *   func_021EB098  0x021EB098  thumb  ov170
 *   func_021EB114  0x021EB114  thumb  ov170
 *   func_021EB190  0x021EB190  thumb  ov170
 *   func_021EB208  0x021EB208  thumb  ov170
 *   func_021EABA0  0x021EABA0  thumb  ov170
 *   func_021EABB8 0x021EABB8 thumb
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_021EAAE4 0x021EAAE4 thumb
 *   func_02045730 0x02045730 arm
 *   func_02045758 0x02045758 arm
 *   func_02045760 0x02045760 arm
 *   func_02045738 0x02045738 arm
 *   func_02045740 0x02045740 arm
 *   func_02049DB4 0x02049DB4 arm
 *   func_020436FC 0x020436FC arm
 *   func_020439A0 0x020439A0 arm
 *   func_020437AC 0x020437AC arm
 *   func_020307B0 0x020307B0 arm
 *   func_020275E4 0x020275E4 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   func_021B6AE4 0x021B6AE4 thumb ov067
 *   func_02045808 0x02045808 arm
 *   func_0202CA3C 0x0202CA3C thumb
 *   func_0202CEBC 0x0202CEBC thumb
 *   func_020457B0 0x020457B0 arm
 *   func_0200785C 0x0200785C thumb
 *   func_0201D304 0x0201D304 thumb
 *   func_0201C7D0 0x0201C7D0 thumb
 *   func_020257D0 0x020257D0 thumb
 */
#include "../../matched/include/Obj00000.h"
#include "../../matched/include/Obj02213.h"
#include "../../matched/include/Obj01558.h"
#include "../../matched/include/Obj23969.h"
#include "../../matched/include/Obj23970.h"
#include "../../matched/include/Obj23971.h"
#include "../../matched/include/Obj23973.h"
#include "../../matched/include/Obj23974.h"

#define WORK(p) (*(char **)((p) + 0x2C))
#define HEAP 0x804C
struct CharBuf;
struct Descriptor;
struct Bmp;
struct MsgBank;
struct Obj020437AC;
struct U16Vec;
struct WinMgr;
struct Obj;
struct StrObj;
typedef unsigned char u8;

typedef struct {
    void *obj;
    int pad;
} Item;

typedef struct {
    unsigned char pad[0x94];
    Item items[14];
} Work;

typedef struct {
    unsigned char pad[0x14];
    char *raw;
} Chr;

typedef unsigned short u16;

typedef unsigned int   u32;

extern void func_021EADB4(void *q, int a, int i);
extern void func_021EAE20(char *p, void **q, int i);
extern void func_021EAE74(void *q, int a, int i);
extern void func_021EAF20(void *q, int a, int i);
extern void func_021EAFBC(void *p, int a, int i);
extern void func_021EB098(char *p, unsigned char *e, int i);
extern void func_021EB114(char *p, unsigned char *e, int i);
extern void func_021EB190(char *p, unsigned char *e, int i);
extern void func_021EB208(void *q, int a, int i);
extern void func_021EABA0(void **p);
extern void func_021EABB8(void **p);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_021EAAE4(unsigned char *p, unsigned i);
extern u8 func_02045730(struct Descriptor *p);
extern u8 func_02045758(struct Descriptor *p);
extern u8 func_02045760(struct Descriptor *p);
extern u8 func_02045738(struct Descriptor *p);
extern u8 func_02045740(struct Descriptor *p);
extern void *func_02049DB4(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern struct Bmp *func_020436FC(void *pixels, u32 width, u32 height, u32 depth, u16 heap);
extern void func_020439A0(struct Bmp *dst, struct Bmp *src, u32 x, u32 y, int sx, int sy, u32 w, u32 h, u32 key);
extern void func_020437AC(struct Obj020437AC *p);
extern u32 func_020307B0(void *p);
extern unsigned func_020275E4(void);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_021B6AE4(u8 *p, void *a, u16 b, u16 c, u32 s0, u32 s1, u16 s2, u32 s3);
extern void func_02045808(struct U16Vec *vec);
extern void func_0202CA3C(void *,unsigned,unsigned,unsigned,unsigned);
extern void func_0202CEBC(void *,unsigned,void *);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_0200785C(void *save, unsigned box, void *dest);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void func_0201C7D0(void *x, short y, short z, void *s, void *w, unsigned short v);
extern void func_020257D0(struct Obj *o);
void func_021EB2A4(u8 *p, int a);
void func_021EB324(Work *w);
void func_021EB378(char *p, int idx, unsigned msg, unsigned short frame, unsigned short col, int icon);
void func_021EB6D8(int a, int b, int c, int d);
void func_021EB6F0(int a, int b, int c);
void func_021EB708(void *m,unsigned i,void *d);
void func_021EB744(char *p);
void func_021EB79C(unsigned char *p);
void func_021EB7C8(char *p);
void func_021EB7E8(char **p, unsigned box, int i);


void func_021EB2A4(u8 *p, int a)
{
    func_021EADB4(((struct Obj00000 *)p)->f2C, a, 1);
    func_021EAE20(((struct Obj00000 *)p)->f2C, (void **)a, 2);
    func_021EAE74(((struct Obj00000 *)p)->f2C, a, 3);
    func_021EAF20(((struct Obj00000 *)p)->f2C, a, 4);
    func_021EAFBC(p, a, 5);
    func_021EB098(((struct Obj00000 *)p)->f2C, (unsigned char *)a, 6);
    func_021EB114(((struct Obj00000 *)p)->f2C, (unsigned char *)a, 7);
    func_021EB190(((struct Obj00000 *)p)->f2C, (unsigned char *)a, 8);
    func_021EB208(((struct Obj00000 *)p)->f2C, a, 9);
    func_021EABA0((void **)((u8 *)((struct Obj00000 *)p)->f2C + 0xe4));
    func_021EABA0((void **)((u8 *)((struct Obj00000 *)p)->f2C + 0xec));
    func_021EABA0((void **)((u8 *)((struct Obj00000 *)p)->f2C + 0xf4));
    func_021EABA0((void **)((u8 *)((struct Obj00000 *)p)->f2C + 0xfc));
}


void func_021EB324(Work *w)
{
    unsigned i;
    for (i = 1; i <= 9; i++) {
        func_021EABB8((void **)(&w->items[i]));
        func_02043B5C(func_02045770(w->items[i].obj), 0);
        func_021EAAE4((unsigned char *)w, i);
    }
    func_021EABB8((void **)(&w->items[10]));
    func_021EABB8((void **)(&w->items[11]));
    func_021EABB8((void **)(&w->items[12]));
    func_021EABB8((void **)(&w->items[13]));
}


/*
 * Draws a window frame from 8x8 tiles, then centres a message in it.  The
 * window size locals are u8 like the getters that return them: as int
 * locals the w - 1 and h - 1 loop guards stop sharing the corner offsets'
 * common subexpressions and the function comes out 20 bytes short.
 */
void func_021EB378(char *p, int idx, unsigned msg, unsigned short frame, unsigned short col, int icon)
{
    void *win = *(void **)(WORK(p) + 0x94 + idx * 8);
    void *bmp = func_02045770(win);
    unsigned char w;
    unsigned char h;
    Chr *chr;
    void *res;
    char *raw;
    void *t;
    unsigned char i;
    void *str;

    func_02045730(win);
    func_02045758(win);
    func_02045760(win);
    w = func_02045738(win);
    h = func_02045740(win);
    func_02043B5C(bmp, 4);
    res = func_02049DB4(0x74, 0x3E, 1, (u32)(&chr), HEAP);
    raw = chr->raw;
    frame *= 0x20;

    t = func_020436FC(raw + frame, 8, 8, 0x20, HEAP);
    func_020439A0(t, bmp, 0, 0, 0, 0, 8, 8, 0xFFFF);
    func_020437AC(t);

    t = func_020436FC(raw + (frame + 0x40), 8, 8, 0x20, HEAP);
    func_020439A0(t, bmp, 0, 0, (w - 1) * 8, 0, 8, 8, 0xFFFF);
    func_020437AC(t);

    t = func_020436FC(raw + (frame + 0xC0), 8, 8, 0x20, HEAP);
    func_020439A0(t, bmp, 0, 0, 0, (h - 1) * 8, 8, 8, 0xFFFF);
    func_020437AC(t);

    t = func_020436FC(raw + (frame + 0x100), 8, 8, 0x20, HEAP);
    func_020439A0(t, bmp, 0, 0, (w - 1) * 8, (h - 1) * 8, 8, 8, 0xFFFF);
    func_020437AC(t);

    t = func_020436FC(raw + (frame + 0x60), 8, 8, 0x20, HEAP);
    for (i = 1; i < h - 1; i++)
        func_020439A0(t, bmp, 0, 0, 0, i * 8, 8, 8, 0xFFFF);
    func_020437AC(t);

    t = func_020436FC(raw + (frame + 0xA0), 8, 8, 0x20, HEAP);
    for (i = 1; i < h - 1; i++)
        func_020439A0(t, bmp, 0, 0, (w - 1) * 8, i * 8, 8, 8, 0xFFFF);
    func_020437AC(t);

    t = func_020436FC(raw + (frame + 0x20), 8, 8, 0x20, HEAP);
    for (i = 1; i < w - 1; i++)
        func_020439A0(t, bmp, 0, 0, i * 8, 0, 8, 8, 0xFFFF);
    func_020437AC(t);

    t = func_020436FC(raw + (frame + 0xE0), 8, 8, 0x20, HEAP);
    for (i = 1; i < w - 1; i++)
        func_020439A0(t, bmp, 0, 0, i * 8, (h - 1) * 8, 8, 8, 0xFFFF);
    func_020437AC(t);

    func_020307B0(res);

    if (icon == 1) {
        res = func_02049DB4(func_020275E4(), 0x20, 0, (u32)(&chr), HEAP);
        t = func_020436FC(chr->raw + 0x120, 0x10, 8, 0x20, HEAP);
        func_020439A0(t, bmp, 0, 0, (w - 3) * 8, 8, 0x10, 8, 5);
        func_020437AC(t);
        func_020307B0(res);
    }

    str = func_02045EC0(*(void **)(WORK(p) + 0x80), msg);
    func_021B6AE4((u8 *)(WORK(p) + 0x94 + idx * 8), (void *)(*(void **)(WORK(p) + 0x8C)), w * 8 / 2, 4, (u32)str,
                  *(unsigned *)(WORK(p) + 0x78), col, 2);
    func_02045808(str);
}

/*
 * Range call with a fixed span and the caller's fourth value.
 */
void func_021EB6D8(int a, int b, int c, int d)
{
    func_021EB378((char *)a, b, c, 0, 0x3d80, d);
}

/*
 * Same range call with both tail slots fixed.
 */
void func_021EB6F0(int a, int b, int c)
{
    func_021EB378((char *)a, b, c, 0, 0xf6 << 6, 0);
}

void func_021EB708(void *m,unsigned i,void *d){unsigned bg=func_02045730(d);unsigned w=func_02045738(d);unsigned h=func_02045740(d);func_0202CA3C(m,i,bg,w,h);func_0202CEBC(m,i,d);}

void func_021EB744(char *p)
{
    func_021EB708(*(struct WinMgr * *)&((struct Obj02213 *)p)->f74, 0, ((struct Obj02213 *)p)->f104);
    func_021EB708(*(struct WinMgr * *)&((struct Obj02213 *)p)->f74, 1, ((struct Obj02213 *)p)->f10C);
    func_021EB708(*(struct WinMgr * *)&((struct Obj02213 *)p)->f74, 2, ((struct Obj02213 *)p)->f114);
    func_021EB708(*(struct WinMgr * *)&((struct Obj02213 *)p)->f74, 3, ((struct Obj02213 *)p)->f11C);
    func_021EB708(*(struct WinMgr * *)&((struct Obj02213 *)p)->f74, 4, ((struct Obj02213 *)p)->f124);
    func_021EB708(*(struct WinMgr * *)&((struct Obj02213 *)p)->f74, 5, ((struct Obj02213 *)p)->f12C);
}

void func_021EB79C(unsigned char *p){if(((struct Obj23969 *)(*(unsigned char * *)&((struct Obj01558 *)p)->f0))->f24==4)func_021EB6F0((int)p,22,71);else func_021EB6F0((int)p,22,69);func_021EB708(((struct Obj23970 *)(*(unsigned char * *)&((struct Obj01558 *)p)->f2C))->f74,10,((struct Obj23971 *)(*(unsigned char * *)&((struct Obj01558 *)p)->f2C))->f144);}

/*
 * Stage 0x17/0x46 then hand the 0x14C word over with index 0xb.
 */
void func_021EB7C8(char *p)
{
    func_021EB6F0((int)p, 0x17, 0x46);
    func_021EB708(*(struct WinMgr **)(*(int *)&((struct Obj01558 *)p)->f2C + 0x74), 0xb,
                  (void *)(*(int *)(*(int *)&((struct Obj01558 *)p)->f2C + 0x14C)));
}


void func_021EB7E8(char **p, unsigned box, int i)
{
    void *s = func_020457B0(0x14, 0x804C);
    unsigned n;
    func_0200785C(((void **)p[0])[1], box, s);
    func_02043B5C(*(void **)(p[11] + i * 8 + 8), 0);
    n = func_0201D304(s, ((struct Obj23973 *)(p[11]))->f78, 0);
    n = (0x60 - n) / 2;
    func_0201C7D0(*(void **)(p[11] + i * 8 + 8), n, 0, s, ((struct Obj23974 *)(p[11]))->f78, 0x440);
    func_02045808(s);
    func_020257D0(*(void **)(p[11] + i * 8 + 4));
}
