/*
 * file:     research_top_p29.c
 * unit:     yes
 * function: func_021BEF98, func_021BEFC0, func_021BEFD4, func_021BEFF8, func_021BF08C, func_021BF100, func_021BF11C, func_021BF13C, func_021BF15C, func_021BF264, func_021BF2FC, func_021BF38C, func_021BF3B4, func_021BF3D8, func_021BF47C, func_021BF4AC, func_021BF55C, func_021BF568, func_021BF574, func_021BF580, func_021BF594, func_021BF5BC, func_021BF5D0, func_021BF5E4, func_021BF600, func_021BF60C, func_021BF658, func_021BF6A4, func_021BF6BC
 * address:  0x021BEF98
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021C2740 0x021C2740 thumb ov217
 *   d_021C3AC8 0x021C3AC8 data a4
 *   func_021C0900 0x021C0900 thumb ov217
 *   func_020490F4 0x020490F4 arm
 *   func_021BF810 0x021BF810 thumb ov217
 *   func_02049250 0x02049250 arm
 *   func_02062B30 0x02062B30 arm
 *   func_02041090 0x02041090 arm
 *   func_020409B4 0x020409B4 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02049238 0x02049238 arm
 *   func_021C0F5C  0x021C0F5C  thumb  ov217
 *   d_021C3628     0x021C3628  data   ov217  a4
 *   func_021BF7CC 0x021BF7CC thumb ov217
 *   d_021C36B8 0x021C36B8 data a1
 *   d_021C369A 0x021C369A data a1
 *   func_021BF76C 0x021BF76C thumb ov217
 *   func_021BF7F4 0x021BF7F4 thumb ov217
 *   func_021BF854 0x021BF854 thumb ov217
 *   func_021C0FF8 0x021C0FF8 thumb ov217
 *   func_021C0F78 0x021C0F78 thumb ov217
 *   func_021C11C8 0x021C11C8 thumb ov217
 *   func_021C11DC 0x021C11DC thumb ov217
 *   func_02045EC0 0x02045EC0 arm
 *   func_020457B0 0x020457B0 arm
 *   func_02045808 0x02045808 arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201EE0C 0x0201EE0C thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_021BF910 0x021BF910 thumb ov217
 *   func_021BFA08 0x021BFA08 thumb ov217
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B92C 0x0204B92C arm
 *   d_021C3850 0x021C3850 data a2
 *   func_021C11FC 0x021C11FC thumb ov217
 *   func_0204B9C4 0x0204B9C4 arm
 *   func_02025774  0x02025774  thumb
 *   func_021C29F8 0x021C29F8 thumb ov217
 *   d_021C3A34 0x021C3A34 data a4
 *   func_021C2A00  0x021C2A00  thumb  ov217
 *   func_021C2A10  0x021C2A10  thumb  ov217
 *   func_021C29F0  0x021C29F0  thumb  ov217
 *   func_021C09D0  0x021C09D0  thumb  ov217
 *   func_0202173C 0x0202173C thumb
 *   func_02021ED8  0x02021ED8  thumb
 */
#include "../../matched/include/Obj25922.h"
#include "../../matched/include/Obj25923.h"
#include "../../matched/include/Obj05561.h"
#include "../../matched/include/Obj00021.h"
#include "../../matched/include/Obj14738.h"
#include "../../matched/include/Obj25924.h"
#include "../../matched/include/Obj25925.h"
#include "../../matched/include/Obj14739.h"
#include "../../matched/include/Obj25928.h"
#include "../../matched/include/Obj08435.h"
#include "../../matched/include/Obj25929.h"
#include "../../matched/include/Obj25930.h"

struct ArcFile;
struct MsgBank;
struct U16Vec;
struct WordSet;
struct Obj;
struct Actor;
struct PalAnmObj;
typedef unsigned int u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef signed int     s32;

struct Row { u8 x,y,w,h; int fields[8]; };

struct Vec2 { short x,y; };

typedef struct S { u32 a; u16 b; u8 pad[14]; } S;

typedef signed short s16;

typedef signed char    s8;

extern void func_021C2740(u32 a, u32 b);
extern unsigned func_021C0900(int);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern u32 func_021BF810(void *p);
extern void *func_02049250(struct ArcFile *,unsigned,unsigned);
extern int func_02062B30(void *,void **);
extern void func_02041090(unsigned,unsigned,unsigned,unsigned,u8,u8);
extern void func_020409B4(unsigned);
extern u32 func_020307B0(void *p);
extern void func_02049238(void *);
extern u32 func_021C0F5C(u32 a0, u32 a1);
extern u32 func_021BF7CC(void *p);
extern u8 *func_021BF76C(void *p);
extern u32 func_021BF7F4(void *p);
extern u32 func_021BF854(char *p);
extern void func_021C0FF8(u8 *p, int visible);
extern void func_021C0F78(u8 *p, struct U16Vec *text);
extern u8 func_021C11C8(u8 *p, u8 key);
extern u8 func_021C11DC(u8 *p, u8 key);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u32 func_021BF910(unsigned char *p);
extern unsigned func_021BFA08(void *,unsigned);
extern void func_0204B3DC(struct Obj *,unsigned);
extern void func_0204B404(struct Obj *,const struct Vec2 *,unsigned);
extern void func_0204B92C(struct Obj *,unsigned);
extern void func_021C11FC(u8 *h, u8 key, s32 *px, s32 *py);
extern void func_0204B9C4(struct Actor *,unsigned);
extern void func_02025774(u8 *g, u32 a);
extern void func_021C29F8(u8 *p, u32 b, u16 c);
extern void func_021C2A00(u32 a0);
extern void func_021C2A10(u32, u32);
extern void func_021C29F0(int);
extern void func_021C09D0(u32);
extern int func_0202173C(struct PalAnmObj *,u16,u16,s16,u8,u8,u16,void *);
extern u32 func_02021ED8(const char *ptr);
extern u32 func_02021D50();
extern u32 func_020419E4();
extern void func_0204A648(void);
void func_021BEF98(char *p);
void func_021BEFC0(u8 *a0, u32 a1);
void func_021BEFD4(char *p);
void func_021BEFF8(u8 *p);
void func_021BF08C(char *p);
void func_021BF100(char *p);
void func_021BF11C(char *p);
void func_021BF13C(char *p);
void func_021BF15C(char *p);
void func_021BF264(char *p);
void func_021BF2FC(char *p);
void func_021BF38C(char *p);
void func_021BF3B4(char *p);
void func_021BF3D8(char *p);
void func_021BF47C(char *p);
void func_021BF4AC(char *p);
void func_021BF55C(void *a0);
void func_021BF568(void *a0);
void func_021BF574(void *a0);
void func_021BF580(u8 *p, u32 i, u32 j);
void func_021BF594(char *p, int i);
void func_021BF5BC(u8 *a0, u32 a1);
void func_021BF5D0(u8 *a0, u32 a1);
void func_021BF5E4(int *p);
void func_021BF600(u8 *a0);
void func_021BF60C(char *p);
void func_021BF658(char *p);
u32 func_021BF6A4(u8 *a0);
u32 func_021BF6BC(u32 a0, u32 a1);
extern const struct Row d_021C3AC8[];
extern unsigned char d_021C3628[];
extern u8 d_021C36B8[];
extern u8 d_021C369A[];
extern const u16 d_021C3850[];
extern S d_021C3A34[];

void func_021BEF98(char *p)
{
    int i;
    u8 z = 0;
    for (i = 0; i < 10; i++) {
        func_021C2740(*(u32 *)(p + i * 4 + 0x2d4), z);
    }
    ((struct Obj25922 *)p)->f2FD = z;
}


/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + (a1)*4 + 724)), 1 to func_021C2740.
 *
 * Addresses are Black-image addresses.
 */
void func_021BEFC0(u8 *a0, u32 a1)
{
    func_021C2740((u32)(*(u32*)(a0 + (a1)*4 + 724)), 1);
}

/*
 * Addresses are Black-image addresses.
 */
void func_021BEFD4(char *p)
{
    int i;
    int n;
    n = ((struct Obj25923 *)p)->f2FC;
    for (i = 0; i < n; i++) {
        func_021BEFC0((u8 *)p, (u8)i);
    }
}

/*
 * lever: pool 021BF088 is 021C3AC8; dropping contested ov217 data hint resolves sole-ref evidence.
 */
void func_021BEFF8(u8 *p)
{
    const struct Row *row;
    u8 *q;
    row=&d_021C3AC8[((struct Obj05561 *)p)->f34];
    q=p+0x2fe;
    q[2]=func_021C0900(row->fields[0]+row->fields[4]-16);
    p[0x2fe]=func_021C0900(row->fields[1]+row->fields[5]-16);
    q[3]=func_021C0900(q[2]+32);
    q[1]=func_021C0900(p[0x2fe]+32);
    row=&d_021C3AC8[((struct Obj05561 *)p)->f34];
    q=p+0x302;
    q[2]=func_021C0900(row->fields[0]+row->fields[6]-16);
    p[0x302]=func_021C0900(row->fields[1]+row->fields[7]-16);
    q[3]=func_021C0900(q[2]+32);
    q[1]=func_021C0900(p[0x302]+32);
}

void func_021BF08C(char *p)
{
    struct ArcFile *arc;
    void *file,*out;
    unsigned id;
    arc=func_020490F4(192,((struct Obj00021 *)p)->f4);
    if (((struct Obj00021 *)p)->f3D0!=0) id=8;
    else if (func_021BF810(p)==0) id=6;
    else {
        id=6;
        if (((struct Obj00021 *)p)->f3C8!=0) id=7;
    }
    file=func_02049250(arc,id,((struct Obj00021 *)p)->f4);
    func_02062B30(file,&out);
    func_02041090(2,(unsigned)out+12,0,0,32,32);
    func_020409B4(2);
    func_020307B0(file);
    func_02049238(arc);
}


/*
 * Tail call through a pool word: bx r3 spends r3 on the target, so only the
 * two argument registers are live (see docs/idioms/a-tail-call-cannot-pass-a-fourth-argument.md).
 *
 * Addresses are Black-image addresses.
 */
void func_021BF100(char *p)
{
    func_021C0F5C(((struct Obj14738 *)p)->f348, d_021C3628[((struct Obj14738 *)p)->f38]);
}

void func_021BF11C(char *p)
{
    u32 i = func_021BF7CC(p);
    func_021C0F5C(((struct Obj25924 *)p)->f34C, d_021C36B8[i]);
}

void func_021BF13C(char *p)
{
    u32 o = ((struct Obj25925 *)p)->f350;
    u32 i = func_021BF7CC(p);
    func_021C0F5C(o, d_021C369A[i]);
}

void func_021BF15C(char *p)
{
    u32 t = ((struct Obj00021 *)p)->f354;
    u8 *o = func_021BF76C(p);
    u32 k;
    u32 a, b, c;
    void *x, *y, *z;
    if (((struct Obj00021 *)p)->f3C8 == 0 || ((struct Obj00021 *)p)->f3D0 == 1) {
        func_021C0FF8((u8 *)t, 0);
        return;
    }
    if (func_021BF810(p) == 0) {
        func_021C0FF8((u8 *)t, 0);
        return;
    }
    k = func_021BF7F4(p);
    a = func_021C11C8(o, (u8)k);

    b = func_021BF854(p);
    c = func_021C11DC(o, (u8)k);
    x = func_02045EC0(((struct Obj00021 *)p)->fC, 0xd);
    y = func_02045EC0(((struct Obj00021 *)p)->f14, k);
    z = func_020457B0(0x80, ((struct Obj00021 *)p)->f4);
    func_0201EFA4(((struct Obj00021 *)p)->f18, 0, a + 1, 2, 1, 1);
    func_0201EE0C(((struct Obj00021 *)p)->f18, 1, y, 0, 1, 2);
    func_0201EFA4(((struct Obj00021 *)p)->f18, 2, b, 5, 1, 1);
    func_0201EFA4(((struct Obj00021 *)p)->f18, 3, c, 3, 1, 1);
    func_0201F250(((struct Obj00021 *)p)->f18, z, x);
    func_021C0F78((u8 *)t, z);
    func_021C0FF8((u8 *)t, 1);
    func_02045808(x);
    func_02045808(z);
    func_02045808(y);
}

/*
 * EE0C: original stores sixth argument 2 at sp+4; preserve visibly supplied trailing input.
 */
void func_021BF264(char *p)
{
    unsigned index;
    struct U16Vec *a,*b,*buf;
    if (((struct Obj00021 *)p)->f3C8==0 || func_021BF810(p)==0) {
        func_021C0FF8((u8 *)(((struct Obj00021 *)p)->f358),0);
        return;
    }
    index=func_021BF910((unsigned char *)p);
    a=func_02045EC0(*(struct MsgBank * *)&((struct Obj00021 *)p)->fC,14);
    b=func_02045EC0(*(struct MsgBank * *)&((struct Obj00021 *)p)->f14,index);
    buf=func_020457B0(128,((struct Obj00021 *)p)->f4);
    func_0201EE0C(*(struct WordSet * *)&((struct Obj00021 *)p)->f18,0,b,0,1,2);
    func_0201F250(*(struct WordSet * *)&((struct Obj00021 *)p)->f18,buf,a);
    func_021C0FF8((u8 *)(((struct Obj00021 *)p)->f358),1);
    func_021C0F78((u8 *)(((struct Obj00021 *)p)->f358),buf);
    func_02045808(a);
    func_02045808(buf);
    func_02045808(b);
}

void func_021BF2FC(char *p)
{
    u32 k;
    u32 x;
    void *a, *b;
    void *c;
    if (((struct Obj00021 *)p)->f3C8 != 0) {
        switch (((struct Obj00021 *)p)->f2CC) {
        case 0:
            k = 0xf;
            break;
        case 1:
            k = 0x11;
            break;
        }
    } else {
        switch (((struct Obj00021 *)p)->f2CC) {
        case 0:
            k = 0x10;
            break;
        case 1:
            k = 0x12;
            break;
        }
    }
    x = func_021BF810(p);
    c = ((struct Obj00021 *)p)->f18;
    a = func_02045EC0(((struct Obj00021 *)p)->fC, k);
    b = func_020457B0(0x80, ((struct Obj00021 *)p)->f4);
    func_0201EFA4(c, 0, x, 6, 1, 1);
    func_0201F250(c, b, a);
    func_021C0F78((u8 *)(((struct Obj00021 *)p)->f35C), b);
    func_02045808(a);
    func_02045808(b);
}

void func_021BF38C(char *p)
{
    if (func_021BF810(p) == 0) {
        func_021C0FF8((u8 *)(((struct Obj14739 *)p)->f360), 1);
    } else {
        func_021C0FF8((u8 *)(((struct Obj14739 *)p)->f360), 0);
    }
}

void func_021BF3B4(char *p)
{
    if (((struct Obj00021 *)p)->f3D0 != 0) {
        func_021C0FF8((u8 *)(((struct Obj00021 *)p)->f364), 1);
    } else {
        func_021C0FF8((u8 *)(((struct Obj00021 *)p)->f364), 0);
    }
}

void func_021BF3D8(char *p)
{
    const struct Row *row;
    struct Obj *a,*b;
    struct Vec2 pos;
    row=&d_021C3AC8[((struct Obj00021 *)p)->f34];
    a=(struct Obj *)func_021BFA08(p,0);
    b=(struct Obj *)func_021BFA08(p,1);
    if (((struct Obj00021 *)p)->f3D0==1 || ((struct Obj00021 *)p)->f34==2 || ((struct Obj00021 *)p)->f34==4) {
        func_0204B3DC(a,0);
        func_0204B3DC(b,0);
        return;
    }
    pos.x=row->fields[0]+row->fields[4];
    pos.y=row->fields[1]+row->fields[5];
    func_0204B404(a,&pos,0);
    pos.x=row->fields[0]+row->fields[6];
    pos.y=row->fields[1]+row->fields[7];
    func_0204B404(b,&pos,0);
    func_0204B3DC(a,1);
    func_0204B3DC(b,1);
    func_0204B92C(a,1);
    func_0204B92C(b,1);
}

void func_021BF47C(char *p)
{
    if (((struct Obj00021 *)p)->f3C8 == 0 || func_021BF810(p) == 0) {
        func_0204B3DC((struct Obj *)((struct Obj00021 *)p)->f39C, 0);
    } else {
        func_0204B3DC((struct Obj *)((struct Obj00021 *)p)->f39C, 1);
    }
}

void func_021BF4AC(char *p)
{
    struct Obj *obj;
    unsigned index;
    s32 x,y;
    struct Vec2 pos;
    const u16 *table;
    obj=*(struct Obj * *)&((struct Obj00021 *)p)->f3A0;
    table=d_021C3850;
    if (((struct Obj00021 *)p)->f3C8==0) { func_0204B3DC(obj,0); return; }
    if (((struct Obj00021 *)p)->f34!=2) { func_0204B3DC(obj,0); return; }
    index=func_021BF910((u8 *)p);
    if (func_021C11DC(func_021BF76C(p),index)==0) { func_0204B3DC(obj,0); return; }
    if (index==0) { func_0204B3DC(obj,0); return; }
    func_021C11FC(func_021BF76C(p),index,&x,&y);

    pos.x=x;
    pos.y=y;
    func_0204B404(obj,&pos,table[12]);
    func_0204B3DC(obj,1);
    func_0204B92C(obj,1);
    func_0204B9C4((struct Actor *)obj,2);
}


void func_021BF55C(void *a0)
{
    func_021BF580((u8 *)a0, 1, 1);
}


/*
 * Tail-call veneer: forwards arg(s) a0, 0, 1 to func_021BF580.
 *
 * Addresses are Black-image addresses.
 */
void func_021BF568(void *a0)
{
    func_021BF580((u8 *)a0, 0, 1);
}


/*
 * Tail-call veneer: forwards arg(s) a0, 0, 0 to func_021BF580.
 *
 * Addresses are Black-image addresses.
 */
void func_021BF574(void *a0)
{
    func_021BF580((u8 *)a0, 0, 0);
}

void func_021BF580(u8 *p, u32 i, u32 j)
{
    func_02025774((u8 *)(*(u32 *)(p + i * 4 + 0x3a8)), j);
}

void func_021BF594(char *p, int i)
{
    func_021C29F8((u8 *)(*(u32 *)(p + i * 4 + 0x324)), d_021C3A34[i].a, d_021C3A34[i].b);
}


/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + (a1)*4 + 804)), (u32)(a0 + (a1)*4) to func_021C2A00.
 *
 * Addresses are Black-image addresses.
 */
void func_021BF5BC(u8 *a0, u32 a1)
{
    func_021C2A00((u32)(*(u32*)(a0 + (a1)*4 + 804)));
}


/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + (a1)*4 + 804)), (u32)(a0 + (a1)*4) to func_021C2A10.
 *
 * Addresses are Black-image addresses.
 */
void func_021BF5D0(u8 *a0, u32 a1)
{
    func_021C2A10((u32)(*(u32*)(a0 + (a1)*4 + 804)), (u32)(a0 + (a1)*4));
}


void func_021BF5E4(int *p)
{
    int i;
    for (i = 0; i < 8; i++)
        func_021C29F0(p[i + 0xC9]);
}


/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0)) to func_021C09D0.
 *
 * Addresses are Black-image addresses.
 */
void func_021BF600(u8 *a0)
{
    func_021C09D0((u32)(((struct Obj25928 *)a0)->f0));
}

void func_021BF60C(char *p)
{
    func_0202173C(*(struct PalAnmObj * *)&((struct Obj08435 *)p)->f3B8,1,0xffff,3,0,7,0xffff,((struct Obj08435 *)p)->f3BC);
    func_0202173C(*(struct PalAnmObj * *)&((struct Obj08435 *)p)->f3B8,4,0xffff,3,0,7,0xffff,((struct Obj08435 *)p)->f3BC);
}

void func_021BF658(char *p)
{
    func_0202173C(*(struct PalAnmObj * *)&((struct Obj00021 *)p)->f3B8,1,0xffff,3,7,0,0xffff,((struct Obj00021 *)p)->f3BC);
    func_0202173C(*(struct PalAnmObj * *)&((struct Obj00021 *)p)->f3B8,4,0xffff,3,7,0,0xffff,((struct Obj00021 *)p)->f3BC);
}

/*
 * Note: the record's +0x3B8 handle is idle.
 *            witness outside 021BF6A4..021BF6BC.  Bytes are exact and 24/24
 *            match the listing extent; file the TARGET first (OV-BRIEF rule
 *            10) and this promotes to EXACT with no source change.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BF6A4(u8 *a0)
{
    if (func_02021ED8((const char *)(((struct Obj25929 *)(((u8*)a0)))->f3B8)) == 0) {
    return 1;
    }
    return 0;
}

/*
 * Reconstructed from the listing (.inst decoded).
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BF6BC(u32 a0, u32 a1)
{
    func_020419E4();
    func_0204A648();
    return func_02021D50(((struct Obj25930 *)(((u8*)a1)))->f3B8);
}
