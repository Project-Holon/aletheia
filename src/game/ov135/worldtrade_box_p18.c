/*
 * file:     worldtrade_box_p18.c
 * unit:     yes
 * function: func_021F7374, func_021F73DC, func_021F74E4, func_021F74F8, func_021F7538
 * address:  0x021F7374
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021F7338  0x021F7338  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_0220262C  0x0220262C  thumb
 *   func_02007664  0x02007664  thumb
 *   func_020076D0  0x020076D0  thumb
 *   func_020185F4  0x020185F4  thumb
 *   func_0200752C  0x0200752C  thumb
 *   func_021F798C 0x021F798C thumb ov135
 *   func_021F75C0 0x021F75C0 thumb ov135
 *   func_021FFFE8 0x021FFFE8 thumb ov135
 *   func_021F76D8 0x021F76D8 thumb ov135
 *   func_021F777C 0x021F777C thumb ov135
 *   func_021F7878 0x021F7878 thumb ov135
 *   func_0202208C 0x0202208C thumb
 *   func_021F9254 0x021F9254 thumb ov135
 *   func_021F81C8 0x021F81C8 thumb ov135
 *   func_021F8358 0x021F8358 thumb ov135
 *   func_021F9890 0x021F9890 thumb ov135
 *   g_02203BBC  0x02203BBC  data  ov135
 *   func_021F7964 0x021F7964 thumb ov135
 *   func_021F99D0 0x021F99D0 thumb ov135
 *   func_021F79EC 0x021F79EC thumb ov135
 *   func_021F7840 0x021F7840 thumb ov135
 *   func_021F76BC 0x021F76BC thumb ov135
 *   func_022000E4 0x022000E4 thumb ov135
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021F4EC8 0x021F4EC8 thumb ov135
 *   sub_02045EC0   0x02045EC0  arm
 *   func_0201F250  0x0201F250  thumb
 *   sub_02045770   0x02045770  arm
 *   sub_02043B5C   0x02043B5C  arm
 *   sub_02045334   0x02045334  arm
 *   sub_02045374   0x02045374  arm
 *   unit_02045730  0x02045730  arm
 *   sub_020409B4   0x020409B4  arm
 *   func_0201F73C  0x0201F73C  thumb
 *   sub_02045808   0x02045808  arm
 *   func_02202858  0x02202858  thumb  ov135
 */
#include "../../matched/include/Obj01159.h"
#include "../../matched/include/Obj23379.h"
#include "../../matched/include/Obj23380.h"
#include "../../matched/include/Obj23381.h"
#include "../../matched/include/Obj00287.h"
#include "../../matched/include/Obj00018.h"

struct Sub02007454Entry;
struct Obj;
struct Cfg;
struct CharBuf;
struct MsgBank;
struct U16Vec;
struct WordSet;
struct Descriptor;
typedef unsigned char u8;

typedef unsigned int u32;

typedef struct {
    u8 pad0[8];
    void *party;
    u32 storage;
} Ctx;

typedef struct {
    Ctx *ctx;
    u8 pad4[0x20 - 4];
    int kind;
    u8 pad24[0xDC - 0x24];
    u32 box;
    u32 slot;
} Obj;

typedef struct { void *a,*b,*obj,*d,*e,*f,*g,*h,*i; u32 j,k,l; } Init;

typedef unsigned short u16;

typedef signed int s32;

extern u32 func_021F7338(Obj *p, int kind);
extern void *func_0201AB28(void *p, u32 idx);
extern void func_0220262C(u32 a, u32 b);
extern void func_02007664(void *save, u32 box, u32 slot);
extern int func_020076D0(void *save, int *pbox, int *pslot);
extern void *func_020185F4(void *p);
extern int func_0200752C(void **save, u32 box, const struct Sub02007454Entry *src);
extern void func_021F798C(u8 *);
extern void func_021F75C0(void);
extern void func_021FFFE8(u8 *,u32,u32);
extern void func_021F76D8(void *);
extern void func_021F777C(void *);
extern void func_021F7878(u8 *);
extern void func_0202208C(void *,u32,u32,u32,u32,u32,u32);
extern void func_021F9254(u8 *);
extern void func_021F81C8(void *bank, void *names, int unused, u8 *win, u32 index, int mode, int place, void *g);
extern void func_021F8358(void *,void *,void **,void *,void *,void *);
extern void *func_021F9890(Init *,u32,u32);
extern void func_021F7964(u8 *p);
extern void func_021F99D0(u8 *p);
extern void func_021F79EC(char *p);
extern void func_021F7840(char *p);
extern void func_021F76BC(void);
extern void func_022000E4(char *p);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_021F4EC8(u8 *p);
extern void *sub_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void *sub_02045770(struct Descriptor *p);
extern void sub_02043B5C(struct CharBuf *buf, u8 value);
extern void sub_02045334(struct Descriptor *a);
extern void sub_02045374(struct Cfg *cfg);
extern u8 unit_02045730(u32 a);
extern void sub_020409B4(u32 index);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void sub_02045808(struct U16Vec *vec);
extern u32 func_02202858(void *p, u8 b, void *s, u32 x, u32 y, void *out);
void func_021F7374(Obj *p);
int func_021F73DC(u8 *p);
void func_021F74E4(u8 *p);
int func_021F74F8(u8 *p);
void func_021F7538(u8 *p, u32 b, u32 c, u32 d, u32 e);
extern void *g_02203BBC[];


/*
 * Fill the slot record for the current kind (+0x20). A +0xDC source of
 * 0xFF copies party member +0xE0 into it (func_0220262C); otherwise the
 * box/slot pair (+0xDC, +0xE0) is looked up in the storage at +0xC of
 * the context and the found entry is written into the record.
 */
void func_021F7374(Obj *p)
{
    u32 e = func_021F7338(p, p->kind);

    if (p->box == 0xff) {
        func_0220262C(e, (u32)func_0201AB28(p->ctx->party, p->slot));
    } else {
        u32 a;
        u32 b;

        a = 0;
        b = 0;
        func_02007664((void *)p->ctx->storage, p->box, p->slot);
        func_020076D0((void *)p->ctx->storage, (int *)(&a), (int *)(&b));
        func_0200752C((void **)p->ctx->storage, a, (const struct Sub02007454Entry *)((u32)func_020185F4((void *)e)));
    }
}

int func_021F73DC(u8 *p)
{
    Init init;
    func_021F798C(p);
    func_021F75C0();
    func_021FFFE8(p,0,0);
    func_021F76D8(p);
    func_021F777C(p);
    func_021F7878(p);
    func_0202208C((void *)3,1,1,0,6,1,0x48);
    func_021F9254(p);
    func_021F81C8(((struct Obj01159 *)p)->fB6C,((struct Obj01159 *)p)->fB70,(int)(((struct Obj01159 *)p)->fB68),p+0xD90,0,3,-1,p+0xFA0);
    func_021F8358(((struct Obj01159 *)p)->fB6C,((struct Obj01159 *)p)->fB68,(void **)(p+0xD9C),((struct Obj01159 *)p)->fCC,p+0xB4C,p+0xFA0);
    init.a=p+0xD50;
    init.b=p+0xDD4;
    init.obj=((struct Obj01159 *)p)->fBF8;
    init.d=((struct Obj01159 *)p)->fD2C;
    init.e=((struct Obj01159 *)p)->fD30;
    init.f=0;
    init.g=((struct Obj01159 *)p)->fB6C;
    init.h=((struct Obj01159 *)p)->fB70;
    init.i=((struct Obj01159 *)p)->fB7C;
    init.j=((struct Obj23379 *)(*(u8 * *)&((struct Obj01159 *)p)->f0))->f10;
    init.k=((struct Obj23380 *)(*(u8 * *)&((struct Obj01159 *)p)->fE00))->f14;
    init.l=((struct Obj23381 *)(*(u8 * *)&((struct Obj01159 *)p)->f0))->f20;
    ((struct Obj01159 *)p)->fDE4=func_021F9890(&init,2,0);
    ((struct Obj01159 *)p)->f28=0;
    ((struct Obj01159 *)p)->f12E4=0;
    return 1;
}


/*
 * State-table dispatch through the table at 0x02203BBC.
 */
void func_021F74E4(u8 *p)
{
    ((void (*)(u8 *))g_02203BBC[*(u32 *)(p + 0x28)])(p);
}

int func_021F74F8(u8 *p)
{
    func_021F7964(p);
    func_021F99D0(((struct Obj00287 *)p)->fDE4);
    func_021F79EC((char *)p);
    func_021F7840((char *)p);
    func_021F76BC();
    func_022000E4((char *)p);
    func_0204B3DC((struct Obj *)*(unsigned *)&((struct Obj00287 *)p)->fD38, 0);
    func_021F4EC8(p);
    return 0;
}


/*
 * Handle walk: 02045EC0 over the 0xb6c field, the 0xb68/0xb88 pair through
 * 0201F250, then the p+0xd40 window through the 02045334/02045374/
 * 02045730/020409B4 group and a 02202858 redraw with the p+0xfa0 block.
 */
void func_021F7538(u8 *p, u32 b, u32 c, u32 d, u32 e)
{
    u32 v = (u32)sub_02045EC0((struct MsgBank *)(*(u32 *)&((struct Obj00018 *)p)->fB6C), b);
    u32 h;

    func_0201F250((struct WordSet *)(*(u32 *)&((struct Obj00018 *)p)->fB68), (void *)(((struct Obj00018 *)p)->fB88), (void *)v);
    sub_02043B5C((struct CharBuf *)((u32)sub_02045770((struct Descriptor *)((struct Obj00018 *)p)->fD40)), 0xf);
    h = ((struct Obj00018 *)p)->fD40;
    sub_02045334((struct Descriptor *)h);
    sub_02045374((struct Cfg *)h);
    sub_020409B4(unit_02045730(h));
    func_0201F73C((void *)(((struct Obj00018 *)p)->fD40), 0, 1, 0xe);
    func_02202858((void *)(((struct Obj00018 *)p)->fD40), 0, (void *)(((struct Obj00018 *)p)->fB88), 0, 0, p + 0xfa0);
    sub_02045808((struct U16Vec *)v);
}
