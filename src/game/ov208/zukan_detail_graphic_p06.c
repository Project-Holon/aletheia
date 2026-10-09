/*
 * file:     zukan_detail_graphic_p06.c
 * unit:     yes
 * function: func_021BE4DC, func_021BE504, func_021BE680, func_021BE6A8, func_021BE710, func_021BE778, func_021BE7A4
 * address:  0x021BE4DC
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BD208 0x021BD208 thumb
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_020490F4  0x020490F4  arm
 *   func_0204AC18  0x0204AC18  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_02049238  0x02049238  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_021BD148  0x021BD148  thumb
 *   func_021BD3C0  0x021BD3C0  thumb
 *   func_021BD394  0x021BD394  thumb
 *   func_021BD378  0x021BD378  thumb
 *   data_021C83C8  0x021C83C8  data
 *   func_020362DC 0x020362DC arm
 *   func_0203633C 0x0203633C arm
 *   func_021BD3F8 0x021BD3F8 thumb ov208
 *   func_02030734 0x02030734 arm
 *   func_02040618 0x02040618 arm
 *   func_0204047C 0x0204047C arm
 *   func_021BE868 0x021BE868 thumb ov208
 *   func_021BE920 0x021BE920 thumb ov208
 *   func_021BE864 0x021BE864 thumb ov208
 *   func_020056A0 0x020056A0 thumb
 *   func_0201C440 0x0201C440 thumb
 *   d_021C8DFC 0x021C8DFC data a1
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_02030EAC 0x02030EAC arm
 *   func_021BE9C8 0x021BE9C8 thumb
 *   func_021BE8FC 0x021BE8FC thumb
 *   func_020307B0 0x020307B0 arm
 *   func_02040804 0x02040804 arm
 *   func_02041EE4 0x02041EE4 arm
 *   func_021BE9CC 0x021BE9CC thumb ov208
 *   func_0201C4E4 0x0201C4E4 thumb
 */
#include "../../matched/include/Obj01081.h"
#include "../../matched/include/Obj03931.h"

struct Ov208Mgr;
struct Ov208Gfx;
struct Node;
struct PrintSys;
struct Ov208Eff { char pad[0x30]; struct Ov208Mgr *mgr; char pad2[0x1c]; void *f50; void *f54; void *f58; };

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed short   s16;

struct Ov208ActDesc {
    int f0;
    s16 x;
    s16 y;
    u16 h8;
    u16 ha;
    u16 hc;
    u16 he;
    u16 h10;
    u16 h12;
    u16 h14;
    u16 h16;
    u32 f18;
    u32 f1c;
};

struct Ov208ActList {
    struct Ov208ActDesc *descs;
    u32 count;
    u32 f8;
    u32 fc;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
};

struct Ov208ActSrc {
    int id;
    u16 x;
    u16 y;
    u16 h8;
    u16 pad;
    u32 fc;
    u32 f10;
};

struct Ov208Slot {
    struct Ov208ActSrc *src;
    u32 obj;
};

struct Ov208Scene {
    u16 heap;
    u16 pad2;
    u32 f4;
    u32 f8;
    u32 fc;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u32 f28;
    u32 f2c;
    u32 mgr;
    u32 f34;
    u32 f38;
    u32 f3c;
    u32 f40;
    u32 f44;
    u32 f48;
    u32 f4c;
    u32 f50;
    u32 f54;
    u32 f58;
    u32 f5c;
    u32 f60;
    u32 f64;
    u8  count;
    u8  pad69[3];
    struct Ov208Slot slots[10];
};

typedef signed int     s32;

struct Ov208Icon_021BE710 { u16 heap,pad2; unsigned f4,f8; int fc; unsigned pad10[2],f18,f1c,f20,f24,f28,f2c,f30; };

struct Ov208Mgr { char pad[0x28]; void *f28; void *f2c; };

struct Ov208Icon_021BE7A4 { u16 heap,pad2; unsigned f4,f8; int fc; unsigned char count,pad11[7]; unsigned f18,f1c,f20,f24,f28,f2c,f30; };

extern void func_021BD208(struct Ov208Mgr *m);
extern void func_0204ADA4(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
extern void *func_020490F4(u32 id, u32 heap);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *h);
extern void func_02082BCC(void *p, u32 v, u32 n);
extern u32  func_021BD148(struct Ov208ActList *list, u32 heap);
extern int func_021BD3C0(void *mgr, int key);
extern void func_021BD394(int a, int b, int c);
extern void func_021BD378(int a, int b, int c);
extern u32 func_020362DC(void);
extern unsigned int func_0203633C(void);
extern void func_021BD3F8(void *,int);
extern void *func_02030734(unsigned,unsigned,int,const char *,u16);
extern void func_02040618(unsigned,unsigned,unsigned);
extern void func_0204047C(int,u16);
extern void func_021BE868(struct Ov208Gfx *g);
extern void func_021BE920(struct Ov208Icon_021BE710 *);
extern void func_021BE864(void *);
extern void *func_020056A0(unsigned,unsigned,unsigned);
extern unsigned func_0201C440(void *);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_02030EAC(struct Node *n);
extern void func_021BE9C8(struct Ov208Mgr *m);
extern void func_021BE8FC(char *p);
extern u32 func_020307B0(void *p);
extern u32 func_02040804(u32 layer);
extern void func_02041EE4(unsigned,unsigned,unsigned);
extern void func_021BE9CC(struct Ov208Icon_021BE7A4 *);
extern unsigned func_0201C4E4(struct PrintSys *);
void func_021BE4DC(struct Ov208Eff *e);
void ov208_func_021BE504(struct Ov208Scene *p);
void func_021BE680(char *p);
void func_021BE6A8(char *p);
struct Ov208Icon_021BE710 *func_021BE710(u16 heap,unsigned arg);
void func_021BE778(struct Ov208Mgr *m);
void func_021BE7A4(struct Ov208Icon_021BE7A4 *p);
extern struct Ov208ActSrc data_021C83C8[];
extern const char d_021C8DFC[];

void func_021BE4DC(struct Ov208Eff *e)
{
    if (e->mgr != 0) {
        func_021BD208(e->mgr);
        func_0204ADA4((u32)e->f50);
        func_0204A8D4((u32)e->f54);
        func_0204AFD8((u32)e->f58);
    }
    e->mgr = 0;
}


void ov208_func_021BE504(struct Ov208Scene *p)
{
    struct Ov208ActList list;
    struct Ov208ActDesc descs[6];
    struct Ov208ActDesc *d;
    void *h;
    u8 i;

    h = func_020490F4(0x9f, p->heap);
    p->f5c = func_0204AC18(h, 3, 0, 0x160, 0, 3, p->heap);
    p->f60 = func_0204A6C8(h, 0xd, 0, 0, p->heap);
    p->f64 = func_0204AF28(h, 0x1b, 0x2c, p->heap);
    func_02049238(h);
    p->count = 6;
    for (i = 0; i < p->count; i++)
        p->slots[i].src = &data_021C83C8[i];
    for (i = 0; i < p->count; i++) {
        descs[i].f0 = p->slots[i].src->id;
        descs[i].x = p->slots[i].src->x;
        descs[i].y = p->slots[i].src->y;
        descs[i].h8 = p->slots[i].src->h8;
    }
    d = &descs[3];
    d->ha = p->f60;
    d->hc = p->f5c;
    d->he = p->f64;
    d->h10 = 0xe;
    d->h12 = 0xe;
    d->h14 = 0x14;
    d->f18 = 1;
    d->f1c = 0x54c;
    func_02082BCC(&list, 0, sizeof(list));
    list.descs = descs;
    list.count = 6;
    list.f8 = p->f28;
    list.fc = 1;
    list.f10 = 0xd;
    list.f14 = 8;
    list.f18 = 2;
    p->mgr = func_021BD148(&list, p->heap);
    for (i = 0; i < p->count; i++)
        p->slots[i].obj = func_021BD3C0((void *)p->mgr, p->slots[i].src->id);
    func_021BD394(p->mgr, p->slots[1].src->id, 0x110);
    func_021BD394(p->mgr, p->slots[2].src->id, 0x220);
    if (p->f40 == 0) {
        func_021BD378(p->mgr, p->slots[5].src->id, 0);
        func_021BD378(p->mgr, p->slots[4].src->id, 0);
    }
}


void func_021BE680(char *p)
{
    if (*(int *)&((struct Obj01081 *)p)->f30 != 0) {
        func_021BD208((struct Ov208Mgr *)(*(int *)&((struct Obj01081 *)p)->f30));
        func_0204ADA4(((struct Obj01081 *)p)->f5C);
        func_0204A8D4(((struct Obj01081 *)p)->f60);
        func_0204AFD8(((struct Obj01081 *)p)->f64);
    }
    *(int *)&((struct Obj01081 *)p)->f30 = 0;
}

void func_021BE6A8(char *p)
{
    unsigned held=func_020362DC();
    unsigned keys=func_0203633C();
    if(!(held&0x3f0)) {
        if(keys&0x40) func_021BD3F8(((struct Obj03931 *)p)->f30,**(int * *)&((struct Obj03931 *)p)->f94);
        else if(keys&0x80) func_021BD3F8(((struct Obj03931 *)p)->f30,**(int * *)&((struct Obj03931 *)p)->f8C);
        else if(keys&0x220) func_021BD3F8(((struct Obj03931 *)p)->f30,**(int * *)&((struct Obj03931 *)p)->f7C);
        else if(keys&0x110) func_021BD3F8(((struct Obj03931 *)p)->f30,**(int * *)&((struct Obj03931 *)p)->f74);
    }
}

struct Ov208Icon_021BE710 *func_021BE710(u16 heap,unsigned arg)
{
    struct Ov208Icon_021BE710 *p=func_02030734(heap,0x34,1,d_021C8DFC,120);
    p->heap=heap;p->f4=arg;p->f8=0;p->fc=5;
    func_02040618(5,3,24);
    func_0204047C(5,0);
    func_021BE868((struct Ov208Gfx *)p);
    func_021BE920(p);
    p->f28=(unsigned)func_020056A0((unsigned)func_021BE864,(unsigned)p,1);
    p->f2c=func_0201C440((void *)(unsigned)p->heap);
    p->f30=0;
    return p;
}

/*
 * tail: two zero alignment bytes after the function (listing extent is 2 bytes longer).
 */
void func_021BE778(struct Ov208Mgr *m)
{
    func_0201C6EC(m->f2c);
    func_0201C4C0(m->f2c);
    func_02030EAC(m->f28);
    func_021BE9C8(m);
    func_021BE8FC((char *)m);
    func_020307B0(m);
}

/*
 * matching: direct byte field access avoids a persistent extracted pointer register.
 */
void func_021BE7A4(struct Ov208Icon_021BE7A4 *p)
{
    switch(p->f8) {
    case 0: case 2: break;
    case 1:
        if(p->count==0) {
            if((int)func_02040804(5)<=0) {
                func_02041EE4(5,3,0);p->f8=2;
            } else {func_02041EE4(5,5,3);p->count=0;}
        } else --p->count;
        break;
    case 3:
        if(p->count==0) {
            if((int)func_02040804(5)>=24) {
                func_02041EE4(5,3,24);p->f8=0;
            } else {func_02041EE4(5,4,3);p->count=0;}
        } else --p->count;
        break;
    }
    func_021BE9CC(p);
    func_0201C4E4((struct PrintSys *)p->f2c);
}
