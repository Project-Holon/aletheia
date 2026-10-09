/*
 * file:     wifibattlematch_view_p03.c
 * unit:     yes
 * function: func_021E88B0, func_021E89D0, func_021E8A00, func_021E8A3C, func_021E8A78, func_021E8A80, func_021E8A90, func_021E8AA0, func_021E8AA8, func_021E8AB4, func_021E8AB8
 * address:  0x021E88B0
 * region:   ov177
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_020450F0 0x020450F0 arm
 *   func_0201F73C 0x0201F73C thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   func_0201F81C 0x0201F81C thumb
 *   func_0201F878 0x0201F878 thumb
 *   func_0201FF30 0x0201FF30 thumb
 *   func_02020CF8 0x02020CF8 thumb
 *   func_02020D10 0x02020D10 thumb
 *   d_021E8DD4 0x021E8DD4 data a1
 *   d_021E8D68 0x021E8D68 data a4
 *   func_0202020C  0x0202020C  thumb
 *   func_0201F868  0x0201F868  thumb
 *   func_0201F7A8  0x0201F7A8  thumb
 *   func_020456F8  0x020456F8  arm
 *   func_020452E8  0x020452E8  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02045770  0x02045770  arm
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_020200CC  0x020200CC  thumb
 */
#include "../../matched/include/Obj24452.h"
#include "../../matched/include/Obj24454.h"
#include "../../matched/include/Obj08290.h"

struct Descriptor;
struct Cfg;
struct Obj;
struct Slot;
struct PrintSys;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {u32 word[13];} Config;

typedef struct {void *win;u32 mgr;void *win2;u8 flag,pad[3];void *menu;void *entries;u32 counter;} Work;

typedef struct {u32 x0,x1,x2;u32 items[4];u32 count;u16 a,b,c,d;int enabled;u16 kind,pad;} Desc;

typedef struct {
    int f0;
    char pad0[0xc];
    int f10;
    int f14;
} S_021E89D0;

typedef struct {
    char          pad0[4];
    int           f4;
    int           f8;
    unsigned char fc;
    char          pad1[3];
    int           f10;
    int           f14;
    int           f18;
} S_021E8A00;

typedef signed int     s32;

typedef struct {
    void (*fn)(void *, int *, int);
    int a;
    int b;
} CB;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *,int,u32);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32);
extern void *func_0201F81C(u32,u16);
extern void func_0201F878(struct Slot *table, u32 a, u32 b, u32 tag, u32 heap);
extern void *func_0201FF30(Config *,u16,u16,u16);
extern void func_02020CF8(struct Obj *p, int heap);
extern void func_02020D10(u8 *p, u32 v);
extern void func_0202020C(struct Obj *o, u16 *a, u16 *b);
extern u32 func_0201F868(void *p);
extern void func_0201F7A8(void *desc, u32 kind);
extern void func_020456F8(struct Descriptor *d);
extern u32 func_020452E8(struct Descriptor *d);
extern u32 func_020307B0(void *p);
extern void *func_02045770(struct Descriptor *);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern s32 func_020200CC(struct Obj *o);
Work *func_021E88B0(const Desc *p,u8 x,u8 y,u8 width,u8 height,u16 heap);
void func_021E89D0(S_021E89D0 *p);
int func_021E8A00(S_021E8A00 *p);
int *func_021E8A3C(int a, int b, int c);
void func_021E8A78(void *p);
void func_021E8A80(CB *p);
int func_021E8A90(int **p);
void func_021E8AA0(int *p, int v);
void func_021E8AA8(int a);
void func_021E8AB4(u32 sys, u32 v);
void func_021E8AB8(u32 sys);
extern const char d_021E8DD4[];
extern const Config d_021E8D68;

/*
 * note 2026-10-05 (wP8 W6): EXACT. Twin shape from ov121 021DA038. Lever: heap parameter u16 with u16 heap parameters on 02030734, 0201F81C, 0201F878 (5th), 0201FF30 (4th) and 02020CF8; x/y/width/height u8 with u8 450F0 prototype; if/else for the 02020D10 flag.
 */
Work *func_021E88B0(const Desc *p,u8 x,u8 y,u8 width,u8 height,u16 heap)
{
    Work *out;
    void *q;
    u32 i;
    Config cfg;
    out=func_02030734((u16)heap,28,0,d_021E8DD4,0x1a2);
    func_02082BCC(out,0,28);
    out->mgr=p->x2;
    out->counter=p->kind;
    out->win=(void *)func_020450F0((u8)p->a,(u8)x,(u8)y,(u8)width,height,p->b,1);
    func_0201F73C(out->win,2,p->d,(u8)p->c);
    q=out->win;
    func_02045334(q);
    func_02045374(q);
    func_020409B4(func_02045730(q));
    out->win2=out->win;
    out->flag=0;
    out->entries=func_0201F81C(p->count,heap);
    for(i=0;i<p->count;i++)
        func_0201F878(out->entries,p->x0,p->items[i],i,(u16)heap);
    cfg=d_021E8D68;
    cfg.word[0]=(u32)out->entries;
    *(u16 *)((u8 *)&cfg+0x10)=p->count;
    *(u16 *)((u8 *)&cfg+0x12)=p->count;
    cfg.word[3]=(u32)out->win;
    cfg.word[9]=p->x0;
    cfg.word[10]=(u32)&out->win2;
    cfg.word[11]=p->x2;
    cfg.word[12]=p->x1;
    out->menu=func_0201FF30(&cfg,0,p->pad,heap);
    func_02020CF8(out->menu,(u16)heap);
    if(p->enabled)
        func_02020D10(out->menu,0);
    else
        func_02020D10(out->menu,1);
    return out;
}


void func_021E89D0(S_021E89D0 *p)
{
    func_0202020C((struct Obj *)p->f10, 0, 0);
    func_0201F868((void *)p->f14);
    func_0201F7A8((void *)p->f0, 0);
    func_020456F8((struct Descriptor *)p->f0);
    func_020452E8((struct Descriptor *)p->f0);
    func_020307B0(p);
}


int func_021E8A00(S_021E8A00 *p)
{
    int r4 = p->f4;
    int r;

    if (p->fc != 0) {
        if (func_0201C6C4((struct PrintSys *)r4, (void *)((int)func_02045770((struct Descriptor *)p->f8))) == 0) {
            func_02045334((struct Descriptor *)p->f8);
            p->fc = 0;
        }
    }
    r = func_020200CC((struct Obj *)p->f10);
    if (r == -2) {
        r = p->f18;
    }
    return r;
}


/*
 * Allocate and clear a 0x10-byte record, attach a and b, and return it.
 */
int *func_021E8A3C(int a, int b, int c)
{
    int *p;
    p = func_02030734(c, 0x10, 0, (const char *)d_021E8DD4, 0x246);
    func_02082BCC(p, 0, 0x10);
    ((struct Obj24452 *)p)->f8 = a;
    func_021E8AA0(p, b);
    return p;
}

void func_021E8A78(void *p) {func_020307B0(p);}


void func_021E8A80(CB *p)
{
    void (*fn)(void *, int *, int) = p->fn;

    if (fn != 0) {
        fn(p, &p->a, p->b);
    }
}

/*
 * Unlabelled ov177 leaf hidden in a word run (it follows func_021E8A80):
 * loads the word its argument points at and returns 1 when it is zero.
 * Matched to supply the `matched` witness for the four pending callers.
 */
int func_021E8A90(int **p)
{
    return *p == 0;
}

void func_021E8AA0(int *p, int v)
{
    p[0] = v;
    p[1] = 0;
}


/*
 * Unlabelled ov177 thunk hidden in a word run: tail-calls func_021E8AA0 with
 * its second argument zeroed.  Matched to supply the `matched` witness for the
 * pending ov175 caller func_021D61CC.
 */
void func_021E8AA8(int a)
{
    func_021E8AA0((int *)a, 0);
}


/*
 * Field setter after func_021E8AA8's pool: stores the second argument at
 * +0xc. Called from the ov175 root func_021D7E18 (0x021D7EF6, 0x021D8060,
 * 0x021D8550).
 */
void func_021E8AB4(u32 sys, u32 v)
{
    ((struct Obj24454 *)sys)->fC = v;
}


/*
 * Field copy after func_021E8AB4: the word at +0xc is stored to +4.
 * Called from ov175 at 0x021D5550 and from the root func_021D7E18
 * (0x021D8858).
 */
void func_021E8AB8(u32 sys)
{
    ((struct Obj08290 *)sys)->f4 = ((struct Obj08290 *)sys)->fC;
}
