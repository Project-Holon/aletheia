/*
 * file:     plist_battle_p15.c
 * unit:     yes
 * function: func_021BCEAC, func_021BD058, func_021BD05C, func_021BD18C, func_021BD1BC
 * address:  0x021BCEAC
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049BDC 0x02049BDC arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049238 0x02049238 arm
 *   func_020275E4 0x020275E4 thumb
 *   func_02027694 0x02027694 thumb
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_02027698 0x02027698 thumb
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0202769C 0x0202769C thumb
 *   func_020276A0 0x020276A0 thumb
 *   func_0204AF28 0x0204AF28 arm
 *   func_02027624 0x02027624 thumb
 *   func_02027628 0x02027628 thumb
 *   func_0202762C 0x0202762C thumb
 *   func_020413B0 0x020413B0 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_0201BC3C 0x0201BC3C thumb
 *   func_0204ACEC 0x0204ACEC arm
 *   func_02082A60 0x02082A60 arm
 *   func_02030734 0x02030734 arm
 *   func_0201AA18 0x0201AA18 thumb
 *   func_0201AB28 0x0201AB28 thumb
 *   func_021BD218 0x021BD218 thumb ov091
 *   func_020450F0 0x020450F0 arm
 *   func_020457B0 0x020457B0 arm
 *   func_02045924 0x02045924 arm
 *   func_02045770 0x02045770 arm
 *   func_0201C724 0x0201C724 thumb
 *   func_02045808 0x02045808 arm
 *   d_021BED48 0x021BED48 data ov091 a1
 *   func_021BD454 0x021BD454 thumb ov091
 *   func_020452E8 0x020452E8 arm
 *   func_020307B0 0x020307B0 arm
 *   func_021BD480  0x021BD480  thumb  ov091
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 */
#include "../../matched/include/Obj20920.h"
#include "../../matched/include/Obj09934.h"

#define H (*(u16 *)p)
#define W(o) (*(u32 *)(p + (o)))
#define F(o) (*(int *)(W(0x280) + (o)))
struct Descriptor;
struct Strbuf;
struct U16Vec;
struct PrintSys;
struct Cfg;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int     s32;

typedef short s16;

extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049BDC(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02049238(void *);
extern u32 func_020275E4(void);
extern u32 func_02027694(void);
extern s32 func_0204ABF0(void *a, u32 b, u32 c, u32 d, u16 g);
extern u32 func_02027698(void);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern u32 func_0202769C(u32);
extern u32 func_020276A0(u32);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern u32 func_02027624(void);
extern u32 func_02027628(void);
extern u32 func_0202762C(void);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_02041B6C(u32);
extern int func_0201BC3C(void);
extern int func_0204ACEC(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void func_02082A60(void *, void *, unsigned long);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_0201AA18(void *list);
extern void *func_0201AB28(void *list, u32 i);
extern u32 *func_021BD218(u8 *p, void *mon, s16 x, u16 y);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045924(struct Strbuf *o, const u16 *src);
extern void *func_02045770(struct Descriptor *p);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02045808(struct U16Vec *vec);
extern void func_021BD454(char *,char *);
extern unsigned int func_020452E8(struct Descriptor *d);
extern u32 func_020307B0(void *p);
extern unsigned int func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_021BD480(char *a, int *b);
void func_021BCEAC(u8 *p);
void func_021BD058(char *a);
u32 *func_021BD05C(u8 *p, u32 *list, u8 x, u8 y, u8 w);
void func_021BD18C(char *a,char *p);
void func_021BD1BC(char *a, int *b);
extern const char d_021BED48[];

void func_021BCEAC(u8 *p)
{
    void *h, *h2;
    h = func_020490F4(0x4c, H);
    func_02049BDC((void *)((u32)h), 1, 4, 0x20, 0x20, 0x20, H);
    func_02049B68(h, 0, 4, 0x1a0, 0x20, H);
    func_02049658((void *)((u32)h), 9, 6, 0, 0, 0, H);
    if (F(0x8c) == 1) {
        switch (F(0x64)) {
        case 1: func_020498F4((void *)((u32)h), 0x11, 6, 0, 0, 0, H); break;
        case 2: func_020498F4((void *)((u32)h), 0x10, 6, 0, 0, 0, H); break;
        }
    }
    func_02049238(h);
    h2 = func_020490F4(func_020275E4(), H);
    W(0x184) = func_0204ABF0((void *)h, func_02027694(), 1, 0x60, H);
    W(0x1a8) = func_0204A6C8((void *)((u32)h), func_02027698(), 0, 1, H);
    W(0x1c4) = func_0204AF28((void *)((u32)h), func_0202769C(2), func_020276A0(2), H);
    if (F(0x90) == 1) {
        func_02049B68(h, func_02027624(), 4, 0x40, 0x20, H);
        func_02049658((void *)((u32)h), func_02027628(), 5, 0, 0, 0, H);
        func_020498F4((void *)((u32)h), func_0202762C(), 5, 0, 0, 0, H);
        func_020413B0(5, 0, 0, 0x20, 0x20, 2);
        func_02041B6C(5);
    }
    func_02049238(h2);
    h = func_020490F4(7, H);
    W(0x194) = func_0204ACEC((void *)((u32)h), func_0201BC3C(), 1, 0xc0, H);
    func_02049238(h);
    func_02082A60((void *)0x05000440, p + 0x20e, 0x20);
}

/*
 * note:     listing extent (4) runs 2 bytes past the compiled function (2);
 *           trailing alignment padding, no byte difference.
 */
void func_021BD058(char *a)
{
}


u32 *func_021BD05C(u8 *p, u32 *list, u8 x, u8 y, u8 w)
{
    u32 *r;
    u8 n;
    u8 i;
    u32 bmp;
    u32 flag;

    r = (u32 *)func_02030734(*(u16 *)p, 0x20, 0, d_021BED48, 0x143);
    n = func_0201AA18((void *)list[0]);
    for (i = 0; i < 6; i++) {
        if (i < n) {
            int par = i % 2;
            u8 xx = x + par * (w + 5);
            u8 yy = y + (i / 2) * 6 + 4;
            int col = 4;
            if (par != 0) col = 0;
            r[2 + i] = (u32)func_021BD218(p, func_0201AB28((void *)list[0], i), (u8)((u8)col + (xx << 3)), (u8)(yy << 3));
        } else {
            r[2 + i] = 0;
        }
    }
    flag = 1;
    r[1] = func_020450F0(4, (u8)(x + 1 + ((u32)w >> 1)), (u8)(y + 1), 10, 2, 0xe, flag);
    bmp = (u32)func_020457B0(0x10, *(u16 *)p);
    func_02045924((struct Strbuf *)bmp, (const u16 *)list[1]);
    func_0201C724((void *)(*(u32 *)(p + 0x140)), (u32)func_02045770((struct Descriptor *)r[1]), 0, 0, bmp, *(u32 *)(p + 0x138), 0x3c40);
    func_02045808((struct U16Vec *)bmp);
    r[0] = flag;
    return r;
}

void func_021BD18C(char *a,char *p) { u8 i; for(i=0;i<6;i++) { char *q=*(char **)(p+i*4+8); if(q)func_021BD454(a,q); } func_020452E8(*(struct Descriptor * *)&((struct Obj20920 *)p)->f4); func_020307B0(p); }


void func_021BD1BC(char *a, int *b)
{
    u8 i;
    int q;
    for (i = 0; i < 6; i++) {
        if (b[2 + i] != 0)
            func_021BD480(a, (int *)b[2 + i]);
    }
    if (b[0] == 1 && func_0201C6C4((struct PrintSys *)(((struct Obj09934 *)a)->f140), (void *)func_02045770((struct Descriptor *)b[1])) == 0) {
        q = b[1];
        b[0] = 0;
        func_02045334((struct Descriptor *)q);
        func_02045374((struct Cfg *)q);
        func_02041B6C(func_02045730((struct Descriptor *)q));
    }
}
