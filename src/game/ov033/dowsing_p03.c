/*
 * file:     dowsing_p03.c
 * unit:     yes
 * function: func_021F06AC, func_021F0738, func_021F0760, func_021F07DC, func_021F07F4
 * address:  0x021F06AC
 * region:   ov033
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02040588 0x02040588 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_02040618 0x02040618 arm
 *   func_0204B100 0x0204B100 arm
 *   func_0204B270 0x0204B270 arm
 *   func_02043598 0x02043598 arm
 *   d_021F0DF0 0x021F0DF0 data ov033 a4
 *   func_0204B1CC 0x0204B1CC arm
 *   func_020403F4 0x020403F4 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049BDC 0x02049BDC arm
 *   func_02049740 0x02049740 arm
 *   func_02049990 0x02049990 arm
 *   func_02049238 0x02049238 arm
 *   func_020413B0 0x020413B0 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_0203FB44 0x0203FB44 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B688 0x0204B688 arm
 *   func_0204B404 0x0204B404 arm
 *   d_021F0DBC 0x021F0DBC data ov033 a1
 */
#include "../../matched/include/Obj09802.h"
#include "../../matched/include/G_ov033_021F0DF0.h"
#include "../../matched/include/Obj20474.h"
#include "../../matched/include/Obj13072.h"
#include "../../matched/include/Obj20475.h"

struct BgTemplate;
struct Bank;
struct Obj;
struct Actor;
struct Vec2;
typedef struct {
    unsigned f00;
    unsigned f04[8];
    unsigned f24;
    unsigned f28;
} E;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef struct {
    u16 a;
    u16 b;
    u16 c;
    u8 d;
    u8 e;
} Local;

typedef struct {
    u16 x;
    u16 y;
} Pos;

typedef struct {
    u8 a;
    u8 b;
    u8 c;
} Ids;

typedef struct {
    u32 chr;
    u32 cell;
    u32 obj;
} Rec;

typedef struct {
    u16 heap;
    u16 heap2;
    u8 pad4[0x8];
    u32 fC;
    u8 pad10[0x1C];
    u32 f2C;
    Rec rec[4];
} Obj;

typedef signed int     s32;

extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_0203FCA0(unsigned int bgId, const struct BgTemplate *tmpl, unsigned int type);
extern void func_020414AC(unsigned char);
extern void func_02040618(unsigned char, unsigned, unsigned);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_0204B270(struct Bank *bank);
extern void func_02043598(unsigned, unsigned);
extern unsigned int func_0204B1CC(struct Bank *bank);
extern void func_020403F4(u32 i);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_02049BDC(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern u32 func_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);
extern u32 func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void func_02049238(void *);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_02041B6C(unsigned);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B688(struct Actor *actor, u32 value);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
void func_021F06AC(char *p);
void func_021F0738(char *p);
void func_021F0760(char *p);
void func_021F07DC(char *p);
void func_021F07F4(Obj *p);
extern struct G_ov033_021F0DF0 d_021F0DF0[];
extern const Ids d_021F0DBC[];


void func_021F06AC(char *p)
{
    int i;
    unsigned id;
    E *e;
    unsigned j;
    for (i = 4; i <= 7; i++)
        func_02040588((unsigned char)i, (unsigned char)0);
    for (j = 0; j < 2; j++) {
        e = &((E *)d_021F0DF0)[j];
        id = e->f00;
        func_0203FCA0((unsigned char)id, (const struct BgTemplate *)e->f04, (unsigned char)e->f24);
        func_020414AC(id);
        func_02040588((unsigned char)id, (unsigned char)e->f28);
        func_02040618(id, 0, 0);
        func_02040618(id, 3, 0);
    }
    ((struct Obj09802 *)p)->fC = func_0204B100(8, 0, ((struct Obj09802 *)p)->f0);
    func_0204B270(((struct Obj09802 *)p)->fC);
    func_02043598(0x10, 1);
}

void func_021F0738(char *p) { unsigned i; func_0204B1CC((struct Bank *)(((struct Obj20474 *)p)->fC)); for(i=0;i<2;i++) func_020403F4((unsigned char)d_021F0DF0[i].f00); }


void func_021F0760(char *p)
{
    unsigned h = ((struct Obj13072 *)p)->f2;
    void *a = func_020490F4(0xC3, h);
    unsigned b;
    func_02049BDC(a, 0, 4, 0, 0, 0x40, h);
    b = func_02049740(a, 2, 7, 0, 0, h);
    func_02049990(a, 7, 7, 0, (unsigned short)b, 0, 0, h);
    func_02049238(a);
    func_020413B0(7, 0, 0, 0x20, 0x18, 1);
    func_02041B6C(7);
    ((struct Obj13072 *)p)->f10 = b;
}

void func_021F07DC(char *p) { unsigned v = ((struct Obj20475 *)p)->f10; func_0203FB44(7, (unsigned short)v, (unsigned short)(v>>16)); }


/*
 * note:     the four `strh #0` at the loop top are `Local s = {0};` declared
 *           in the loop body (field-by-field zeroing ends in two strb), and
 *           `pt` lives in its own block after the loop so it takes the
 *           lower slot (sp+0x10) below `s` (sp+0x14).
 */
void func_021F07F4(Obj *p)
{
    void *arc;
    u8 i;

    arc = func_020490F4(0xC3, p->heap2);
    p->f2C = func_0204AC18(arc, 1, 1, 0, 0, 1, p->heap);
    for (i = 0; i < 4; i++) {
        Local s = {0};
        if (i == 1) {
            p->rec[i].chr = p->rec[0].chr;
            p->rec[i].cell = p->rec[0].cell;
        } else {
            p->rec[i].chr = func_0204A6C8(arc, d_021F0DBC[i].a, 0, 1, p->heap);
            p->rec[i].cell = func_0204AF28(arc, d_021F0DBC[i].b, d_021F0DBC[i].c, p->heap);
        }
        s.d = i;
        p->rec[i].obj = (u32)func_0204B294((void *)p->fC, p->rec[i].chr, p->f2C, p->rec[i].cell, &s, 1, p->heap);
        func_0204B92C((struct Obj *)p->rec[i].obj, 1);
        func_0204B688((struct Actor *)p->rec[i].obj, 1);
    }
    func_02049238(arc);
    {
        Pos pt;

        pt.x = 0x50;
        pt.y = 0x60;
        func_0204B404((struct Obj *)p->rec[0].obj, (const struct Vec2 *)(&pt), 1);
        pt.x = 0xB0;
        pt.y = 0x60;
        func_0204B404((struct Obj *)p->rec[1].obj, (const struct Vec2 *)(&pt), 1);
        pt.x = 0x80;
        pt.y = 0x60;
        func_0204B404((struct Obj *)p->rec[3].obj, (const struct Vec2 *)(&pt), 1);
    }
}
