/*
 * file:     worldtrade_adapter_p27.c
 * unit:     yes
 * function: func_021FF914, func_021FF92C, func_021FF9E0, func_021FFA3C, func_021FFAEC, func_021FFB00, func_021FFB20, func_021FFBC0, func_021FFBC8, func_021FFC18, func_021FFC8C, func_021FFCD4, func_021FFD1C, func_021FFD44, func_021FFD74, func_021FFDA8, func_021FFEB4, func_021FFEC8, func_021FFF10, func_021FFFE8, func_022000E4, func_02200118, func_02200130, func_0220015C, func_022001F4, func_02200290, func_022002A0, func_022003BC, func_0220040C, func_02200434, func_02200450, func_02200490, func_022004A0, func_022004C8, func_022004DC
 * address:  0x021FF914
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
 *   func_0204B98C 0x0204B98C arm
 *   func_020307B0 0x020307B0 arm
 *   func_02030EAC 0x02030EAC arm
 *   func_02030734 0x02030734 arm
 *   func_02030DA8 0x02030DA8 arm
 *   func_02030EE8 0x02030EE8 arm
 *   str_02203E44 0x02203E44 data a1
 *   func_0204B404  0x0204B404  arm
 *   func_02035C08 0x02035C08 arm
 *   d_022038BE 0x022038BE data a2
 *   func_0204B878 0x0204B878 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B898 0x0204B898 arm
 *   func_0204B3F4 0x0204B3F4 arm
 *   func_02049F34  0x02049F34  arm
 *   func_02049E34  0x02049E34  arm
 *   DC_FlushRange  0x020862F0  arm
 *   func_0207E804 0x0207E804 arm
 *   func_0207E5D0 0x0207E5D0 arm
 *   d_02203884 0x02203884 data a2
 *   d_02203892 0x02203892 data a1
 *   tbl_022038A2   0x022038A2  data  a2
 *   func_021F4EA0 0x021F4EA0 thumb ov135
 *   func_0202208C 0x0202208C thumb
 *   func_02200AB4 0x02200AB4 thumb ov135
 *   func_02200B34 0x02200B34 thumb ov135
 *   func_02200BAC 0x02200BAC thumb ov135
 *   func_021F9254 0x021F9254 thumb ov135
 *   func_0220093C 0x0220093C thumb ov135
 *   func_021FF8B0 0x021FF8B0 thumb ov135
 *   func_02040588 0x02040588 arm
 *   func_0207D55C 0x0207D55C arm
 *   g_02203E58  0x02203E58  data  ov135
 *   func_021F4EC8 0x021F4EC8 thumb ov135
 *   func_02043668  0x02043668  arm
 *   func_0203FC28  0x0203FC28  arm
 *   func_020435F4  0x020435F4  arm
 *   func_020434DC  0x020434DC  arm
 *   func_02043598  0x02043598  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_020414EC  0x020414EC  arm
 *   func_02040B94  0x02040B94  arm
 *   g_02203914  0x02203914  data  ov135
 *   g_022039A4  0x022039A4  data  ov135
 *   g_02203984  0x02203984  data  ov135
 *   g_022039C4  0x022039C4  data  ov135
 *   func_02041570  0x02041570  arm
 *   g_02203944  0x02203944  data  ov135
 *   g_02203924  0x02203924  data  ov135
 *   g_02203964  0x02203964  data  ov135
 *   g_022039E4  0x022039E4  data  ov135
 *   func_020403F4 0x020403F4 arm
 *   sub_020403F4  0x020403F4  arm
 *   func_020490F4  0x020490F4  arm
 *   func_02049B68  0x02049B68  arm
 *   func_02049B40  0x02049B40  arm
 *   func_0201F5BC  0x0201F5BC  thumb
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   func_02049238  0x02049238  arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_020355C4 0x020355C4 arm
 *   func_0203D34C 0x0203D34C arm
 *   d_022038E0 0x022038E0 data a2
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   func_022028C8 0x022028C8 thumb ov135
 *   func_02202940 0x02202940 thumb ov135
 *   func_020452E8 0x020452E8 arm
 *   func_021F4EC0  0x021F4EC0  thumb  ov135
 *   func_021F4E98  0x021F4E98  thumb  ov135
 */
#include "../../matched/include/Obj10589.h"
#include "../../matched/include/Obj23436.h"
#include "../../matched/include/Obj04530.h"
#include "../../matched/include/Obj08193.h"
#include "../../matched/include/Obj23438.h"
#include "../../matched/include/Obj23439.h"
#include "../../matched/include/Obj10591.h"
#include "../../matched/include/Obj10592.h"
#include "../../matched/include/Obj00137.h"
#include "../../matched/include/Obj00287.h"
#include "../../matched/include/Obj12225.h"
#include "../../matched/include/Obj23440.h"
#include "../../matched/include/Obj02862.h"
#include "../../matched/include/Obj18604.h"
#include "../../matched/include/Obj03300.h"
#include "../../matched/include/Obj08194.h"
#include "../../matched/include/Obj09242.h"
#include "../../matched/include/Obj12227.h"
#include "../../matched/include/Obj09243.h"
#include "../../matched/include/Obj18605.h"
#include "../../matched/include/Obj18606.h"
#include "../../matched/include/Obj18607.h"

struct Obj;
struct Actor;
struct Node;
struct S02030EE8;
struct Vec2;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct U16Vec;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed short s16;

typedef struct { int state; int y; u8 *p; } Anim;

typedef signed int s32;

typedef struct {
    u8 pad0[0x14];
    void *pixels;
} CharData;

typedef struct {
    u8 pad0[0xE1C];
    void *res[16];
    CharData *chr[16];
    void *pal;
    void *palData;
} Obj_021FFC18;

typedef signed char s8;

typedef struct {
    u8 pad0[0xE18];
    u16 active;
    u8 padE1A[2];
    void *buf[16];
    u8 padE5C[0xE9C - 0xE5C];
    void *main;
} Work;

typedef struct {
    u16 x;
    u16 y;
} Pos;

typedef struct {
    u8 pad0[0xD34];
    u32 spr;
} Obj_021FFD1C;

struct DispConfig {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0c;
};

struct BgTemplate {
    u32 unk_00;
    u32 unk_04;
    u32 bufSize;
    u32 unk_0c;
    u8  unk_10;
    u8  unk_11;
    u8  unk_12;
    u8  unk_13;
    u32 unk_14;
    u8  unk_18;
    u8  unk_19;
    u8  unk_1a;
    u8  unk_1b;
    u32 unk_1c;
};

typedef struct { u16 x, y, z; u8 pri, f7; } ObjPos;

typedef struct { u16 x, y; } Pair;

extern void func_0204B878(struct Obj *p, u16 value);
extern u32 func_0204B98C(struct Actor *a);
extern u32 func_020307B0(void *p);
extern void func_02030EAC(struct Node *n);
extern void func_020061E4(u32 a);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_02030DA8(void *, void (*)(void *, Anim *), void *, int);
extern u32 func_02030EE8(struct S02030EE8 *p);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern int func_02035C08(const void *);
extern void func_0204B3DC(struct Obj *, unsigned int);
extern u16 func_0204B898(struct Obj *p);
extern u32 func_0204B3F4(struct Obj *p);
extern void *func_02049F34(u32 a0, u32 a1, u32 a2, u32 a3);
extern void *func_02049E34(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void DC_FlushRange(void *p, u32 size);
extern void func_0207E804(void *, int, int);
extern void func_0207E5D0(void *, int, int);
extern void func_021F4EA0(void *,int,int);
extern void func_02200AB4(u8 *);
extern void func_02200B34(u8 *);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02200BAC(u8 *,u32);
extern void func_021F9254(u8 *);
extern void func_0220093C(u8 *);
extern void func_0202208C(void *,u32,u32,u32,u32,u32,u32);
extern void func_021FF8B0(u8 *);
extern int func_0207D55C(volatile u16 *reg);
extern void func_021F4EC8(u8 *);
extern u32 func_02043668(void);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_020435F4(u32 a);
extern void func_02043598(u32 mask, u32 enable);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414EC(u32 i);
extern void func_02040B94(u8 layer, u32 size, u32 offset, u32 heapId);
extern void func_02041300(u32 layer, int a1, int a2, int a3, u8 a4, u8 a5, u8 a6);
extern void func_020409B4(u32 layer);
extern void func_02041570(int channel, u16 val);
extern void func_020403F4(unsigned);
extern void sub_020403F4(u32 i);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_0201F5BC(u32 a, u32 b, u32 c, u32 d, u16 e);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02049238(void *h);
extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern void func_0204B92C(struct Obj *p, u32 v);
extern u8 func_020355C4(void);
extern void func_0203D34C(u32 a, u32 b);
extern void func_0204B3B4(struct Obj *p);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern u32 func_022028C8(void *,u32,void *,u32,u32,u32,u16,void *);
extern void func_02202940(struct Obj *p);
extern u32 func_020452E8(struct Descriptor *d);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02045808(struct U16Vec *vec);
extern void func_021F4EC0(u8 *p, u32 a, u32 b);
extern void func_021F4E98(u8 *p, u32 a, u32 b);
extern u32 func_020221A4(void);
void func_021FF914(u32 *p, u32 v);
void func_021FF92C(void *task, Anim *a);
void func_021FF9E0(u8 *p);
void func_021FFA3C(void *task, Anim *a);
void func_021FFAEC(u32 a, int b, int c);
int func_021FFB00(int n);
void func_021FFB20(u8 *p, int count, int flag);
int func_021FFBC0(int i);
void func_021FFBC8(u8 *p);
void func_021FFC18(Obj_021FFC18 *p);
void func_021FFC8C(u8 **p, u8 *q, int k, int n, int a4);
void func_021FFCD4(Work *p);
void func_021FFD1C(Obj_021FFD1C *p, int i, int dy);
void func_021FFD44(char *p);
void func_021FFD74(char *p);
int func_021FFDA8(u8 *p);
void func_021FFEB4(u8 *p);
int func_021FFEC8(u8 *p);
void func_021FFF10(void);
void func_021FFFE8(u8 *p, u32 a, u32 b);
void func_022000E4(char *p);
void func_02200118(void);
void func_02200130(char *p);
void func_0220015C(u8 *a0);
void func_022001F4(u8 *p);
void func_02200290(u8 *p);
void func_022002A0(u8 *p);
void func_022003BC(u8 *p);
void func_0220040C(u8 *p);
void func_02200434(u8 *p);
int func_02200450(u8 *p);
int func_02200490(u8 *p);
int func_022004A0(u8 *p);
int func_022004C8(u8 *p);
int func_022004DC(u8 *p);
extern const char str_02203E44[];
extern char d_022038BE;
extern const u16 d_02203884[];
extern const u8 d_02203892[];
extern const Pos tbl_022038A2[];
extern void *g_02203E58[];
extern struct DispConfig g_02203914;
extern struct BgTemplate g_022039A4;
extern struct BgTemplate g_02203984;
extern struct BgTemplate g_022039C4;
extern struct BgTemplate g_02203944;
extern struct BgTemplate g_02203924;
extern struct BgTemplate g_02203964;
extern struct BgTemplate g_022039E4;
extern const Pair d_022038E0[];


/*
 * Tail call into func_0204B878 with the object at +0xd0c and a u16 value.
 */
void func_021FF914(u32 *p, u32 v)
{
    func_0204B878((struct Obj *)(*(u32 *)(p[2] + 0xd0c)), (u16)v);
}

void func_021FF92C(void *task, Anim *a)
{
    u8 *p;
    p = a->p;
    switch (a->state) {
    case 0:
        if (a->y > 160) {
            a->y = 160;
            a->state = 1;
            func_021FF914((u32 *)a, 1);
        }
        a->y += 2;
        func_021FFAEC(((struct Obj10589 *)p)->fD0C, 128, a->y);
        break;
    case 1:
        if (func_0204B98C((struct Actor *)(((struct Obj10589 *)p)->fD0C)) == 0) {
            func_021FF914((u32 *)a, 2);
            a->state = 2;
        }
        break;
    case 2:
        if (a->y <= 138) {
            a->y = 138;
            a->state = 3;
            func_021FF914((u32 *)a, 3);
        } else {
            a->y--;
        }
        func_021FFAEC(((struct Obj10589 *)p)->fD0C, 128, a->y);
        break;
    case 3:
        func_020061E4(0x55C);
        ((struct Obj23436 *)(a->p))->fE18 = 1;
        func_020307B0(a);
        func_02030EAC(task);
        break;
    }
}

void func_021FF9E0(u8 *p)
{
    Anim *a;
    ((struct Obj04530 *)p)->fF98 = func_02030734(0x48, 12, 0, str_02203E44, 0x150);
    ((struct Obj04530 *)p)->fE14 = func_02030DA8(((struct Obj04530 *)p)->fF94, func_021FFA3C, ((struct Obj04530 *)p)->fF98, 5);
    a = (Anim *)func_02030EE8(((struct Obj04530 *)p)->fE14);
    a->state = 0;
    a->y = 0x8A;
    a->p = p;
    func_021FF914((u32 *)a, 5);
    func_020061E4(0x55D);
}

void func_021FFA3C(void *task, Anim *a)
{
    u8 *p;
    p = a->p;
    switch (a->state) {
    case 0:
        if (a->y > 160) {
            a->y = 160;
            a->state = 1;
            func_021FF914((u32 *)a, 6);
        }
        a->y++;
        func_021FFAEC(((struct Obj08193 *)p)->fD0C, 128, a->y);
        break;
    case 1:
        if (func_0204B98C((struct Actor *)(((struct Obj08193 *)p)->fD0C)) == 0) {
            func_021FF914((u32 *)a, 0);
            a->state = 2;
            func_020061E4(0x791);
        }
        break;
    case 2:
        if (a->y < -20) {
            a->state = 3;
            func_021FF914((u32 *)a, 3);
        }
        a->y -= 2;
        func_021FFAEC(((struct Obj08193 *)p)->fD0C, 128, a->y);
        break;
    case 3:
        ((struct Obj08193 *)p)->fE18 = 1;
        func_020307B0(a);
        func_02030EAC(task);
        break;
    }
}


/*
 * Send a one-entry u16 table {(u16)(b - 8), c} to func_0204B404.
 */
void func_021FFAEC(u32 a, int b, int c)
{
    u16 t[2];

    t[0] = b;
    t[1] = c - 8;
    func_0204B404((struct Obj *)a, (const struct Vec2 *)t, 1);
}

int func_021FFB00(int n) { int r=func_02035C08(&d_022038BE); if(r==-1 || r>=n) return -1; return r; }

/*
 * lever: signed offset locals b then a, with two literal assignments each,
 * reproduce the dead stack stores; compound updates reverse the first pair.
 * note 2026-10-05 (wave D9r lane 131): removed the 2 dead first assignments
 * (`a = 0xE5C;` before `a = 0xEA0;`; `b = 0x302;` before `b = 0x32E;`). Game
 * code has no line table, so these were stand-ins. The plain single
 * assignment gives EXACT in --lang c99 and --lang c: the output bytes do not
 * change. Older text in this header that asks for the double assignment is
 * superseded.
 */
void func_021FFB20(u8 *p, int count, int flag)
{
    int i;
    int b, a;
    if (count != 0 && flag == 1) func_020061E4(0x676);
    a = 0xEA0;
    b = 0x32E;
    for (i = 0; i < 7; i++) {
        if (i < count) {
            func_021FFC8C((u8 **)(p + 0xE5C), *(void **)(p + a), i, *(u8 *)(p + i * 0x128 + b), *(u8 *)(p + i * 0x128 + 0x302));
            if (flag != 0) func_0204B878((struct Obj *)(*(u32 *)(p + i * 4 + 0xD10)), i * 4 + 14);
            else func_0204B878((struct Obj *)(*(u32 *)(p + i * 4 + 0xD10)), i * 4 + 17);
            func_0204B3DC((struct Obj *)*(u32 *)(p + i * 4 + 0xD10), 1);
        } else {
            func_0204B3DC((struct Obj *)*(u32 *)(p + i * 4 + 0xD10), 0);
        }
    }
}

/*
 * Index helper: returns index times 4 plus 0xe.
 */
int func_021FFBC0(int i)
{
    return (i << 2) + 0xe;
}

/*
 * tail: 021FFC16..021FFC18 is two-byte zero alignment padding.
 */
void func_021FFBC8(u8 *p)
{
    int i;
    for (i = 0; i < 7; i++) {
        if (*(u32 *)(p + i * 4 + 0xD10) != 0) {
            int a;
            a = func_0204B898((struct Obj *)(*(u32 *)(p + i * 4 + 0xD10)));
            if (a != func_021FFBC0(i) + 1) {
                if (func_0204B3F4((struct Obj *)(*(u32 *)(p + i * 4 + 0xD10))) != 0) {
                    func_0204B878((struct Obj *)(*(u32 *)(p + i * 4 + 0xD10)), func_021FFBC0(i) + 1);
                }
            }
        }
    }
}


/*
 * Load the palette (archive 0x20, file 0, out at +0xEA0, handle at
 * +0xE9C) and the 16 character files 0x31.. (handles at +0xE1C, char
 * data at +0xE5C) from archive 0x20 on heap 0x48, then flush the first
 * 0x200 bytes of each character block.
 */
void func_021FFC18(Obj_021FFC18 *p)
{
    int i;

    p->pal = func_02049F34(0x20, 0, (u32)(&p->palData), 0x48);
    for (i = 0; i < 16; i++) {
        p->res[i] = func_02049E34(0x20, i + 0x31, 0, (u32)(&p->chr[i]), 0x48);
    }
    for (i = 0; i < 16; i++) {
        DC_FlushRange(p->chr[i]->pixels, 0x200);
    }
}

void func_021FFC8C(u8 **p, u8 *q, int k, int n, int a4)
{
    u8 *dst;
    if (n > 16) n = 16;
    else if (n < 0) n = 0;
    dst = *(u8 * *)&((struct Obj23438 *)q)->fC;
    func_0207E804(((struct Obj23439 *)(p[n]))->f14, d_02203884[k], 512);
    func_0207E5D0(dst + d_02203892[n] * 32, (k + 2) * 32, 32);
}


void func_021FFCD4(Work *p)
{
    int i;

    if (p->active != 0) {
        if (p->main != 0) {
            func_020307B0(p->main);
            p->main = 0;
        }
        for (i = 0; i < 16; i++) {
            if (p->buf[i] != 0) {
                func_020307B0(p->buf[i]);
                p->buf[i] = 0;
            }
        }
    }
}


void func_021FFD1C(Obj_021FFD1C *p, int i, int dy)
{
    func_021FFAEC(p->spr, tbl_022038A2[i].x, dy + (tbl_022038A2[i].y + 0x20));
}

void func_021FFD44(char *p) {int i;for(i=0;i<8;i++) {unsigned a=(unsigned)p+i*4;void *v=((struct Obj10591 *)a)->fD0C;if(v) func_021F4EA0(v,((struct Obj10591 *)a)->fEC4,((struct Obj10591 *)a)->fEC6);}}

void func_021FFD74(char *p) {int i;for(i=0;i<8;i++) {unsigned a=(unsigned)p+i*4;void *v=((struct Obj10592 *)a)->fD0C;if(v) func_021F4EA0(v,((struct Obj10592 *)a)->fEC4,((struct Obj10592 *)a)->fEC6+32);}}

/*
 * volatile: hardware display control 0x04000304 read and written at 0x021FFDB6..0x021FFDBA.
 */
int func_021FFDA8(u8 *p)
{
    u32 control;
    func_0220040C(p);
    control=*(volatile u16 *)0x04000304;
    control &= ~0x8000;
    *(volatile u16 *)0x04000304=control;
    func_021FFF10();
    func_0220015C(p);
    func_022002A0(p);
    func_021FFFE8(p,0,0);
    func_02200AB4(p);
    if(((struct Obj00137 *)p)->f30==0) func_02040588(4,0);
    else {func_02200B34(p);func_02040588(4,1);}
    func_02200BAC(p,0);
    ((struct Obj00137 *)p)->f12E4=0;
    func_022001F4(p);
    func_021F9254(p);
    func_0220093C(p);
    if(((struct Obj00137 *)p)->f30==0) {
        func_02200130((char *)p);
        func_0202208C(0,1,1,0,6,1,0x48);
        ((struct Obj00137 *)p)->f28=0;
        ((struct Obj00137 *)p)->f30=1;
        func_021FF8B0(p);
    } else {
        if(((struct Obj00137 *)p)->fEB4==1 && func_0207D55C((u16 *)0x0400106C)!=0) {
            func_021FFD44((char *)p);
            func_0202208C(0,1,1,0,6,1,0x48);
        } else func_0202208C((void *)3,1,1,0,6,1,0x48);
        ((struct Obj00137 *)p)->f28=5;
    }
    ((struct Obj00137 *)p)->fEB4=0;
    func_021FFBC8(p);
    return 1;
}


/*
 * State-table dispatch through the table at 0x02203E58.
 */
void func_021FFEB4(u8 *p)
{
    ((void (*)(u8 *))g_02203E58[*(u32 *)(p + 0x28)])(p);
}

int func_021FFEC8(u8 *p)
{
    func_02200290(p);
    func_02200434(p);
    func_022003BC(p);
    func_02200118();
    if (((struct Obj00287 *)p)->f14 == 4 || ((struct Obj00287 *)p)->f14 == 5) ((struct Obj00287 *)p)->f12E4 = 1;
    func_022000E4((char *)p);
    func_0204B3DC((struct Obj *)*(u32 *)&((struct Obj00287 *)p)->fD38, 0);
    func_021F4EC8(p);
    return 0;
}


/*
 * Three-layer bring-up with layer 0's tilemap cleared and plane 0x10 turned
 * on through both 020434DC and 02043598.
 */
void func_021FFF10(void)
{
    struct DispConfig c = g_02203914;
    u32 v = func_02043668();

    func_0203FC28(&c);
    func_020435F4(v);
    {
        struct BgTemplate t = g_022039A4;
        func_0203FCA0(0, &t, 0);
    }
    func_020414EC(0);
    func_02040588(0, 1);
    {
        struct BgTemplate t = g_02203984;
        func_0203FCA0(1, &t, 0);
    }
    func_02040588(1, 1);
    {
        struct BgTemplate t = g_022039C4;
        func_0203FCA0(2, &t, 0);
    }
    func_02040588(2, 1);
    func_02040B94(0, 0x20, 0, 0x48);
    func_020434DC(0x10, 1);
    func_02043598(0x10, 1);
}


/*
 * One-shot bring-up of layers 4..7 gated on the field at p+0x12e0: the
 * layer-4 clear, the layer-6 clear only when the second argument is zero,
 * layer 5 with its second word taken from the first argument, layer 7, then
 * the four enables.  The four templates are declared together in use order,
 * which is what fixes the stack slots to 0x60/0x40/0x20/0x00.
 */
void func_021FFFE8(u8 *p, u32 a, u32 b)
{
    if (((struct Obj12225 *)p)->f12E0 == 0) {
        struct BgTemplate t4;
        struct BgTemplate t6;
        struct BgTemplate t5;
        struct BgTemplate t7;

        ((struct Obj12225 *)p)->f12E0 = 1;
        t4 = g_02203944;
        func_0203FCA0(4, &t4, 0);
        func_02041570(4, 0);
        t6 = g_02203924;
        func_0203FCA0(6, &t6, 0);
        if (b == 0) {
            func_02041570(6, 0);
        }
        t5 = g_02203964;
        t5.unk_04 = a;
        func_0203FCA0(5, &t5, 0);
        func_02040B94(4, 0x20, 0, 0x48);
        t7 = g_022039E4;
        func_0203FCA0(7, &t7, 0);
        func_02041570(7, 0);
    }
    func_02040588(4, 1);
    func_02040588(5, 1);
    func_02040588(6, 1);
    func_02040588(7, 1);
}

void func_022000E4(char *p) {if(((struct Obj00287 *)p)->f12E0==1 && ((struct Obj00287 *)p)->f12E4==0) {((struct Obj00287 *)p)->f12E0=0;func_020403F4(6);func_020403F4(5);func_020403F4(4);func_020403F4(7);}}


/*
 * Poke channels 2, 1 and 0 in that order.
 */
void func_02200118(void)
{
    sub_020403F4(2);
    sub_020403F4(1);
    sub_020403F4(0);
}

void func_02200130(char *p) {func_020434DC(1,0);func_020434DC(2,0);func_020434DC(4,0);func_0204B3DC(*(struct Obj * *)&((struct Obj23440 *)p)->fBF4,0);}


/*
 * Straight-line six-argument window setup over a 0x60x0x48 handle: the
 * handle open, three B40/B68 window calls, two F5BC text calls and two
 * 498F4 draws, ending with the 49238 release.  No parameters.
 */
void func_0220015C(u8 *a0)
{
    void *h = func_020490F4(0x60, 0x48);

    func_02049B68(h, 3, 0, 0, 0x60, 0x48);
    func_02049B40(0x17, 5, 0, 0x1a0, 0x20, 0x48);
    func_0201F5BC(0, 1, 0xe, 0, 0x48);
    func_0201F5BC(0, 0x1f, 0xb, 0, 0x48);
    func_02049658(h, 0xd, 1, 0, 0, 1, 0x48);
    func_020498F4(h, 0x20, 1, 0, 0x600, 1, 0x48);
    func_020498F4(h, 0x1f, 2, 0, 0x600, 1, 0x48);
    func_02049238(h);
}

void func_022001F4(u8 *p)
{
    ObjPos pos;
    pos.x = d_022038E0[*(u16 *)(p + 0xC0)].x;
    pos.y = d_022038E0[*(u16 *)(p + 0xC0)].y;
    pos.z = 0;
    pos.pri = 0;
    pos.f7 = 1;
    ((struct Obj02862 *)p)->fBF4 = func_0204B294(((struct Obj02862 *)p)->fBC0, (unsigned int)((struct Obj02862 *)p)->fBE8, (unsigned int)((struct Obj02862 *)p)->fBC8, (unsigned int)((struct Obj02862 *)p)->fBF0, &pos, 0, 0x48);
    func_0204B92C(((struct Obj02862 *)p)->fBF4, 1);
    func_0204B878(((struct Obj02862 *)p)->fBF4, 0);
    if (func_020355C4() == 1) {
        func_0204B3DC(((struct Obj02862 *)p)->fBF4, 0);
    } else {
        func_0204B878(((struct Obj02862 *)p)->fBF4, 0);
        func_0204B3DC(((struct Obj02862 *)p)->fBF4, 1);
    }
    func_0203D34C(0, 0x48);
}


/*
 * Tail call into func_0204B3B4 with the pointer held at +0xbf4.
 */
void func_02200290(u8 *p)
{
    func_0204B3B4((struct Obj *)(((struct Obj18604 *)p)->fBF4));
}

/*
 * lever: full-word int cast on the window-read address breaks the loop register tie; unsigned base/index addition happens before the cast.
 */
void func_022002A0(u8 *p)
{
    int i;
    u32 w;
    ((struct Obj03300 *)p)->fD48=(void *)func_020450F0(1,(u8)2,(u8)1,(u8)0x1C,2,1,(u16)1);
    func_02043B5C(func_02045770(((struct Obj03300 *)p)->fD48),0xA);
    w=*(u32 *)&((struct Obj03300 *)p)->fD48;
    func_02045334((void *)w); func_02045374((void *)w); func_020409B4(func_02045730((void *)w));
    func_022028C8(((struct Obj03300 *)p)->fD48,0,((struct Obj03300 *)p)->fB8C,0,2,0,0x35CA,p+0xFA0);
    for(i=0;i<3;i++) {
        u32 window;
        *(void **)((u32)p+i*4+0xD50)=(void *)func_020450F0(1,(u8)9,(u8)(i*5+6),(u8)0xF,2,1,(u16)1);
        func_02043B5C(func_02045770(*(void **)((int)((u32)p+i*4)+0xD50)),1);
        window=*(u32 *)((u32)p+i*4+0xD50);
        func_02045334((void *)window); func_02045374((void *)window); func_020409B4(func_02045730((void *)window));
    }
    ((struct Obj03300 *)p)->fD40=(void *)func_020450F0(0,(u8)2,(u8)0x15,(u8)0x1B,2,0xD,(u16)1);
    func_02043B5C(func_02045770(((struct Obj03300 *)p)->fD40),0xF);
    ((struct Obj03300 *)p)->fDD0=(void *)func_020450F0(0,(u8)2,(u8)0x13,(u8)0x1B,4,0xD,(u16)1);
    func_02043B5C(func_02045770(((struct Obj03300 *)p)->fDD0),0xF);
}

void func_022003BC(u8 *p)
{
    int i;
    func_02202940((struct Obj *)(p + 0xFA0));
    func_020452E8(((struct Obj08194 *)p)->fDE0);
    func_020452E8(((struct Obj08194 *)p)->fDD0);
    func_020452E8(((struct Obj08194 *)p)->fD40);
    for (i = 0; i < 3; i++) func_020452E8(*(void **)(p + i * 4 + 0xD50));
    func_020452E8(((struct Obj08194 *)p)->fD48);
}


/*
 * Claim the 0xb4/0x48 resource into +0xb88 and the 0x2d transfer into +0xb8c.
 */
void func_0220040C(u8 *p)
{
    ((struct Obj09242 *)p)->fB88 = (u32)func_020457B0(0xb4, 0x48);
    ((struct Obj09242 *)p)->fB8C = (u32)func_02045EC0((struct MsgBank *)(((struct Obj09242 *)p)->fB6C), 0x2d);
}


/*
 * Release the two +0xb88/+0xb8c handles.
 */
void func_02200434(u8 *p)
{
    func_02045808((struct U16Vec *)(((struct Obj12227 *)p)->fB88));
    func_02045808((struct U16Vec *)(((struct Obj12227 *)p)->fB8C));
}


/*
 * When the u16 at +0xe18 is set, kick the three half-shades, set 7/0xb and roll to state 9.
 */
int func_02200450(u8 *p)
{
    if (((struct Obj09243 *)p)->fE18 != 0) {
        func_020434DC(1, 0);
        func_020434DC(2, 0);
        func_020434DC(4, 0);
        func_021F4EC0(p, 7, 0xb);
        ((struct Obj09243 *)p)->f18 = 1;
        ((struct Obj09243 *)p)->f28 = 9;
    }
    return 2;
}


/*
 * Store the 0xa/2 pair and report 2.
 */
int func_02200490(u8 *p)
{
    func_021F4E98(p, 0xa, 2);
    return 2;
}


/*
 * Push the fixed 6/1/0x48 request and stamp 3.
 */
int func_022004A0(u8 *p)
{
    func_0202208C((void *)3, 1, 1, 0, 6, 1, 0x48);
    ((struct Obj18605 *)p)->f28 = 3;
    return 2;
}


/*
 * Probe the parent object; on success stamp 5 into +0x28 and report 2.
 */
int func_022004C8(u8 *p)
{
    if (func_020221A4()) {
        ((struct Obj18606 *)p)->f28 = 5;
    }
    return 2;
}


int func_022004DC(u8 *p)
{
    if (func_020221A4()) {
        ((struct Obj18607 *)p)->f28 = 5;
    }
    return 2;
}
