/*
 * file:     wifi_2dchar_p01.c
 * unit:     yes
 * function: func_021C3EE0, func_021C3F80, func_021C3FDC, func_021C4010, func_021C4044, func_021C4080, func_021C40A0, func_021C40B4, func_021C40BC, func_021C41BC, func_021C41DC
 * address:  0x021C3EE0
 * region:   ov127
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
 *   func_020490F4 0x020490F4 arm
 *   func_021C42FC 0x021C42FC thumb ov127
 *   d_021C6100 0x021C6100 data a1
 *   func_021C4790 0x021C4790 thumb ov127
 *   func_021C4330 0x021C4330 thumb ov127
 *   func_02049238 0x02049238 arm
 *   func_020307B0 0x020307B0 arm
 *   func_021C4358 0x021C4358 thumb ov127
 *   func_021C4354 0x021C4354 thumb ov127
 *   func_021C435C 0x021C435C thumb ov127
 *   func_021C447C 0x021C447C thumb ov127
 *   func_021C4424 0x021C4424 thumb ov127
 *   func_021C4564 0x021C4564 thumb ov127
 *   func_021C45AC 0x021C45AC thumb ov127
 *   func_021C4594 0x021C4594 thumb ov127
 *   func_021C45E0 0x021C45E0 thumb ov127
 *   func_021C4494  0x021C4494  thumb
 *   func_021C4514 0x021C4514 thumb ov127
 *   func_021C4604  0x021C4604  thumb ov127
 *   func_0204B294  0x0204B294  arm
 *   func_0204B84C  0x0204B84C  arm
 *   func_0204B908  0x0204B908  arm
 *   func_021C4550  0x021C4550  thumb ov127
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0204B528 0x0204B528 arm
 */
#include "../../matched/include/Obj02839.h"
#include "../../matched/include/Obj05371.h"
#include "../../matched/include/Obj23013.h"
#include "../../matched/include/Obj03277.h"
#include "../../matched/include/Obj10462.h"
#include "../../matched/include/Obj10463.h"

struct Obj;
struct Actor;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u32 mode, handle, owner, a, b; } Entry;

typedef struct { void *a, *b, *items; u32 count; Entry entries[18]; u8 gap[384]; void *h0, *h1; u8 rest[52]; } Context;

typedef signed short s16;

typedef signed int     s32;

typedef struct { s16 x, y, z; u8 a, b; } Pos;

typedef struct { u32 f0, f4, f8, fC, f10; } Rec;

typedef struct {
    u32 h0;
    u8 pad4[0xC];
    Rec rec[18];        /* +0x010 */
    u8 pad178[0x10];
    Rec res[1];         /* +0x188, indexed by idx */
} Own;

typedef struct Pt {u16 x,y;} Pt;

extern void *func_02030734(u16, u32, int, const char *, u16);
extern void *func_020490F4(unsigned int id, u16 heap);
extern void func_021C42FC(char *p, int unused, u32 heap);
extern int func_021C4790(char *p);
extern void func_021C4330(char *p, int a1);
extern void func_02049238(u32);
extern u32 func_020307B0(void *p);
extern int func_021C4358(int, int);
extern int func_021C4354(int);
extern void func_021C435C(char *p, int i, int a, int b, int c, int mode);
extern int func_021C447C(char *, int);
extern void func_021C4424(char *, int);
extern void func_021C4564(u8 *p, u32 a, u32 b, u32 heap);
extern void func_021C45AC(u8 *p, u32 heap);
extern void func_021C4594(u8 *);
extern void func_021C45E0(u8 *);
extern void func_021C4494(u8 *p, u32 a, u32 heap);
void func_021C4514(char *p);
extern void *func_021C4604(u8 *p);
extern struct Obj *func_0204B294(void *owner, u32 i, u32 j, u32 k, const void *position, u16 f, u16 g);
extern void func_0204B84C(u32, u32);
extern void func_0204B908(int a0, int a1);
extern int func_021C4550(int *p);
extern void func_0204B3B4(struct Obj *);
extern void func_02082BCC(void *, int, int);
extern void func_0204B528(struct Actor *, const struct Pt *);
Context *func_021C3EE0(void *a, void *b, u32 count, u32 heap);
void func_021C3F80(u8 *p);
void func_021C3FDC(u8 *p, int a, int b, int c, int d);
void func_021C4010(u8 *p);
void func_021C4044(u8 *p,int a,int b,int c,int d);
void func_021C4080(u8 *p);
void func_021C40A0(u8 *p, int a, int b, int c);
void func_021C40B4(u8 *p);
u32 *func_021C40BC(Own *owner, const s16 *pos, int idx, u32 heap);
void func_021C41BC(u8 *p);
void func_021C41DC(u8 *p,int x,int y);
extern const char d_021C6100[];

Context *func_021C3EE0(void *a, void *b, u32 count, u32 heap)
{
    Context *p;
    int i;
    p = func_02030734(heap, 820, 1, d_021C6100, 339);
    p->a = a;
    p->b = b;
    p->h0 = func_020490F4(31, heap);
    p->h1 = func_020490F4(32, heap);
    for (i = 0; i < 18; i++) p->entries[i].handle = -1;
    ((struct Obj02839 *)p)->f2E0 = -1;
    ((struct Obj02839 *)p)->f2F4 = -1;
    func_021C42FC((char *)p, 0, heap);
    p->count = count;
    p->items = func_02030734(heap, 24 * p->count, 1, d_021C6100, 379);
    return p;
}

void func_021C3F80(u8 *p)
{
    u32 i;
    for (i = 0; i < ((struct Obj05371 *)p)->fC; i++) {
        if (!func_021C4790((char *)(*(u8 * *)&((struct Obj05371 *)p)->f8 + i * 24)))
            func_021C41BC(*(u8 * *)&((struct Obj05371 *)p)->f8 + i * 24);
    }
    func_021C4330((char *)p, 0);
    func_021C4010(p);
    func_02049238(((struct Obj05371 *)p)->f2F8);
    func_02049238(((struct Obj05371 *)p)->f2FC);
    func_020307B0(((struct Obj05371 *)p)->f8);
    func_020307B0(p);
}

void func_021C3FDC(u8 *p, int a, int b, int c, int d)
{
    func_021C4358(a,c);
    func_021C435C((char *)p,func_021C4354(a),b,c,d,0);
}

void func_021C4010(u8 *p)
{
    int i;
    if (((struct Obj23013 *)p)->f2F4 != (u32)-1) func_021C4080(p);
    for(i=0;i<18;i++) if(func_021C447C((char *)p,i)==1)func_021C4424((char *)p,i);
}

void func_021C4044(u8 *p,int a,int b,int c,int d)
{
    int i;
    func_021C4564(p,a,c,d);
    func_021C45AC(p,d);
    for(i=0;i<16;i++)func_021C435C((char *)p,i,a,b,d,1);
}

void func_021C4080(u8 *p)
{
    int i;
    func_021C4594(p);
    func_021C45E0(p);
    for (i=0; i<16; i++) func_021C4424((char *)p, i);
}


/*
 * Addresses are Black-image addresses.
 */
void func_021C40A0(u8 *p, int a, int b, int c)
{
    func_021C4494(p, a, c);
    ((struct Obj03277 *)p)->f2F0 = b;
}

void func_021C40B4(u8 *p)
{
    func_021C4514((char *)p);
}

/*
 * note (2026-10-05, wD5 lane07): EXACT. Keys: a real record array (stride 0x14 at +0x10) keeps idx*0x14 spilled
 *   and recomputes owner+row per use; the 6/1 argument as a call in each if/else arm keeps the 6 from merging with
 *   the pos[3] offset constant; const pos lets the pos[3] load schedule above the e[1] store; off = 0x2E0 local.
 */
u32 *func_021C40BC(Own *owner, const s16 *pos, int idx, u32 heap)
{
    u32 *e = func_021C4604((u8 *)owner);
    Pos l;
    int off;
    int ta;
    idx = func_021C4354(idx);
    l.x = pos[0];
    l.y = pos[1];
    ta = pos[2];
    l.z = 0;
    l.a = ta;
    l.b = pos[3];
    e[1] = (u32)func_0204B294((void *)owner->h0, owner->rec[idx].f4, owner->rec[idx].f8,
                         owner->res[idx].f0, &l, 0, (u16)heap);
    func_0204B84C(e[1], (u8)pos[3]);
    if (owner->rec[idx].f10 == 1)
        func_0204B908(e[1], 6);
    else
        func_0204B908(e[1], 1);
    e[3] = 9;
    *(u16 *)(e + 5) = 0;
    e[4] = 1;
    e[0] = (u32)&owner->rec[idx];
    off = 0x2E0;
    if (func_021C4550((int *)((u8 *)owner + off))) {
        l.x = pos[0];
        l.y = pos[1];
        l.z = 0;
        l.a = *(u32 *)((u8 *)owner + off + 0x10);
        l.b = 0;
        e[2] = (u32)func_0204B294((void *)owner->h0, *(u32 *)((u8 *)owner + off), *(u32 *)((u8 *)owner + off + 4),
                             *(u32 *)((u8 *)owner + off + 8), &l, 0, (u16)heap);
        func_0204B84C(e[2], (u8)pos[3]);
    } else {
        e[2] = 0;
    }
    return e;
}

void func_021C41BC(u8 *p)
{
    if (((struct Obj10462 *)p)->f8 != 0) func_0204B3B4(*(struct Obj * *)&((struct Obj10462 *)p)->f8);
    func_0204B3B4(*(struct Obj * *)&((struct Obj10462 *)p)->f4);
    func_02082BCC(p, 0, 24);
}

void func_021C41DC(u8 *p,int x,int y)
{
    Pt pos;
    pos.x=x; pos.y=y;
    func_0204B528(*(struct Actor * *)&((struct Obj10463 *)p)->f4, &pos);
    if (((struct Obj10463 *)p)->f8 != 0) {
        pos.x=(s16)pos.x+8;
        pos.y=(s16)pos.y+14;
        func_0204B528(*(struct Actor * *)&((struct Obj10463 *)p)->f8, &pos);
    }
}
