/*
 * file:     itemmenu_p14.c
 * unit:     yes
 * function: func_021B9AAC, func_021B9AF8, func_021B9BA0, func_021B9BDC, func_021B9DE8, func_021B9E14, func_021B9ED8
 * address:  0x021B9AAC
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
 *   func_021B97E8  0x021B97E8  thumb  ov070
 *   func_020456F8  0x020456F8  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_020452E8  0x020452E8  arm
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_020437AC  0x020437AC  arm
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_0204A5AC  0x0204A5AC  arm
 *   func_02045CAC 0x02045CAC arm
 *   func_021BB6E0 0x021BB6E0 thumb ov070
 *   func_020450F0  0x020450F0  arm
 *   func_02045374  0x02045374  arm
 *   func_020490F4  0x020490F4  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_02049238  0x02049238  arm
 *   func_020355C4  0x020355C4  arm
 *   func_021B9850  0x021B9850  thumb  ov070
 *   func_02020E60  0x02020E60  thumb
 *   func_0204AC18  0x0204AC18  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204B294  0x0204B294  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204A600 0x0204A600 arm
 *   func_02027974 0x02027974 thumb
 */
#include "../../matched/include/Obj20672.h"
#include "../../matched/include/Obj01682.h"
#include "../../matched/include/Obj01516.h"
#include "../../matched/include/Obj00002.h"
#include "../../matched/include/Obj01041.h"
#include "../../matched/include/Obj13157.h"

struct Descriptor;
struct Obj;
struct Bank;
struct Obj020437AC;
struct MsgBank;
struct Cfg;
typedef unsigned int   u32;

typedef unsigned short u16;

typedef short s16;

typedef signed int     s32;

typedef unsigned char  u8;

typedef struct {
    unsigned short a, b, c;
    unsigned char d, e;
} Rect;

extern void func_021B97E8(char *, int);
extern void func_020456F8(struct Descriptor *d);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern unsigned int func_020452E8(struct Descriptor *d);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204A8D4(u32 i);
extern void func_0204ADA4(u32 i);
extern void func_0204AFD8(u32 i);
extern void func_020437AC(struct Obj020437AC *p);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_021BB6E0(int, unsigned *, unsigned, unsigned short, short, unsigned short);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void func_02045374(struct Cfg *cfg);
extern void *func_020490F4(u32 id, u32 heap);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *);
extern u8 func_020355C4(void);
extern void func_021B9850(char *);
extern int func_02020E60(unsigned short, int);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, u16, u16);
extern void func_0204B92C(struct Obj *, u32);
extern void func_0204A600(void);
extern void func_02027974(void *);
void func_021B9AAC(char *p);
void func_021B9AF8(char *p);
void func_021B9BA0(char *p);
void func_021B9BDC(char *p);
void func_021B9DE8(char *p);
void func_021B9E14(char *p, int id);
void func_021B9ED8(char *p);


void func_021B9AAC(char *p)
{
    unsigned i;
    unsigned j;
    func_021B97E8(p, 0);
    func_020456F8((struct Descriptor *)(((struct Obj20672 *)p)->f734));
    for (i = 0; i < 3; i++) {
        func_0204B3DC((struct Obj *)*(int *)(p + i * 4 + 0x6C0), 0);
    }
    for (j = 0; j < 0x11; j++) {
        func_0204B3DC((struct Obj *)*(int *)(p + j * 4 + 0x6CC), 0);
    }
}


void func_021B9AF8(char *p)
{
    int i;
    func_020452E8((struct Descriptor *)(((struct Obj01682 *)p)->f73C));
    func_020452E8((struct Descriptor *)(((struct Obj01682 *)p)->f74C));
    func_020452E8((struct Descriptor *)(((struct Obj01682 *)p)->f744));
    func_020452E8((struct Descriptor *)(((struct Obj01682 *)p)->f734));
    func_020452E8((struct Descriptor *)(((struct Obj01682 *)p)->f754));
    func_020452E8((struct Descriptor *)(((struct Obj01682 *)p)->f76C));
    func_020452E8((struct Descriptor *)(((struct Obj01682 *)p)->f774));
    func_0204B3B4((struct Obj *)(((struct Obj01682 *)p)->f6A8));
    if (((struct Obj01682 *)p)->f6A0 != 0) {
        func_0204B3B4((struct Obj *)(((struct Obj01682 *)p)->f6A0));
        func_0204A8D4(((struct Obj01682 *)p)->f54C);
        func_0204ADA4(((struct Obj01682 *)p)->f548);
    }
    func_0204AFD8(((struct Obj01682 *)p)->f550);
    for (i = 0; i < 8; i++) {
        func_020437AC((struct Obj020437AC *)(*(int *)(p + i * 4 + 0x614)));
    }
    func_0204B1CC((struct Bank *)(((struct Obj01682 *)p)->f69C));
    func_0204A5AC();
}

void func_021B9BA0(char *p) { func_02045CAC((struct MsgBank *)(((struct Obj01516 *)p)->f51C), 0x87, (void *)(((struct Obj01516 *)p)->f524)); func_021BB6E0((int)p, (unsigned *)(p + 0x774), *(unsigned *)&((struct Obj01516 *)p)->f524, 0, 4, 0x3DC0); }


void func_021B9BDC(char *p)
{
    void *bg;

    ((struct Obj00002 *)p)->f774 = func_020450F0(3, 0x12, 9, 0xc, 3, 3, 1);
    func_021B9BA0(p);
    func_020456F8((struct Descriptor *)(((struct Obj00002 *)p)->f774));
    ((struct Obj00002 *)p)->f754 = func_020450F0(3, 0x11, 0xd, 0xb, 2, 3, 1);
    ((struct Obj00002 *)p)->f76C = func_020450F0(3, 0x11, 0xf, 0xb, 2, 3, 1);
    ((struct Obj00002 *)p)->f734 = func_020450F0(6, 0, 0x13, 0x20, 5, 0, 1);
    ((struct Obj00002 *)p)->f73C = func_020450F0(6, 7, 5, 0x12, 3, 0, 1);
    *(int *)&((struct Obj00002 *)p)->f744 = func_020450F0(6, 0x14, 8, 6, 3, 0, 1);
    ((struct Obj00002 *)p)->f74C = func_020450F0(6, 2, 0xc, 0x1d, 7, 0, 1);
    func_02045374((struct Cfg *)(((struct Obj00002 *)p)->f73C));
    func_02045374((struct Cfg *)(*(int *)&((struct Obj00002 *)p)->f744));
    func_02045374((struct Cfg *)(((struct Obj00002 *)p)->f74C));
    func_02045374((struct Cfg *)(((struct Obj00002 *)p)->f734));
    bg = func_020490F4(0x19, ((struct Obj00002 *)p)->f544);
    ((struct Obj00002 *)p)->f550 = func_0204AF28(bg, 1, 0, ((struct Obj00002 *)p)->f544);
    func_02049238(bg);
    func_02045CAC((struct MsgBank *)(*(u32 *)&((struct Obj00002 *)p)->f51C), 0x66, (void *)(((struct Obj00002 *)p)->f524));
    func_021BB6E0((int)p, (u32 *)(p + 0x734), ((struct Obj00002 *)p)->f524, 8, 4, 0x3DC0);
    func_02045CAC((struct MsgBank *)(*(u32 *)&((struct Obj00002 *)p)->f51C), 0x5d, (void *)(((struct Obj00002 *)p)->f524));
    func_021BB6E0((int)p, (u32 *)(p + 0x734), ((struct Obj00002 *)p)->f524, 8, 0x18, 0x3DC0);
    func_02045CAC((struct MsgBank *)(*(u32 *)&((struct Obj00002 *)p)->f51C), 0x5b, (void *)(((struct Obj00002 *)p)->f524));
    func_021BB6E0((int)p, (u32 *)(p + 0x734), ((struct Obj00002 *)p)->f524, 0x70, 4, 0x3DC0);
    func_02045CAC((struct MsgBank *)(*(u32 *)&((struct Obj00002 *)p)->f51C), 0x5c, (void *)(((struct Obj00002 *)p)->f524));
    func_021BB6E0((int)p, (u32 *)(p + 0x734), ((struct Obj00002 *)p)->f524, 0x70, 0x18, 0x3DC0);
    func_02045CAC((struct MsgBank *)(*(u32 *)&((struct Obj00002 *)p)->f51C), 0x5a, (void *)(((struct Obj00002 *)p)->f524));
    func_021BB6E0((int)p, (u32 *)(p + 0x734), ((struct Obj00002 *)p)->f524, 0xd0, 4, 0x3DC0);
    if (func_020355C4() == 0) {
        func_021B9850(p);
    }
}

void func_021B9DE8(char *p) { if (((struct Obj01041 *)p)->f6A0) { func_0204B3B4(((struct Obj01041 *)p)->f6A0); func_0204A8D4(*(unsigned *)&((struct Obj01041 *)p)->f54C); func_0204ADA4(*(unsigned *)&((struct Obj01041 *)p)->f548); ((struct Obj01041 *)p)->f6A0 = 0; } }


void func_021B9E14(char *p, int id)
{
    void *bg;
    Rect r;
    if (*(int *)&((struct Obj01041 *)p)->f6A0 != 0) {
        func_021B9DE8(p);
    }
    bg = func_020490F4(0x19, ((struct Obj01041 *)p)->f544);
    ((struct Obj01041 *)p)->f548 = func_0204AC18(bg, func_02020E60(id, 2), 1, 0, 0, 1, ((struct Obj01041 *)p)->f544);
    ((struct Obj01041 *)p)->f54C = func_0204A6C8(bg, func_02020E60(id, 1), 0, 1, ((struct Obj01041 *)p)->f544);
    func_02049238(bg);
    r.a = 0x84;
    r.b = 0x50;
    r.c = 0;
    r.d = 0;
    r.e = 0;
    *(int *)&((struct Obj01041 *)p)->f6A0 = (int)func_0204B294((void *)((struct Obj01041 *)p)->f69C, ((struct Obj01041 *)p)->f54C, ((struct Obj01041 *)p)->f548, ((struct Obj01041 *)p)->f550, &r, 1, ((struct Obj01041 *)p)->f544);
    func_0204B92C((struct Obj *)*(int *)&((struct Obj01041 *)p)->f6A0, 1);
    func_0204B3DC((struct Obj *)*(int *)&((struct Obj01041 *)p)->f6A0, 1);
}

void func_021B9ED8(char *p) { func_0204A600(); if (((struct Obj13157 *)p)->f77C) func_02027974(((struct Obj13157 *)p)->f77C); }
