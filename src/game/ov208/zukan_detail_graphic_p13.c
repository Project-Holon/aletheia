/*
 * file:     zukan_detail_graphic_p13.c
 * unit:     yes
 * function: func_021BDD48, func_021BDD98, func_021BDFA8
 * address:  0x021BDD48
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
 *   func_0204B53C 0x0204B53C arm
 *   func_0204B528 0x0204B528 arm
 *   func_020490F4  0x020490F4  arm
 *   func_0204AC18  0x0204AC18  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_02049238  0x02049238  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_021BD148  0x021BD148  thumb
 *   func_021BD3C0  0x021BD3C0  thumb
 *   func_021BD3CC  0x021BD3CC  thumb
 *   func_021BD378  0x021BD378  thumb
 *   func_021BD368  0x021BD368  thumb
 *   func_021BE300  0x021BE300  thumb
 *   func_021BE128  0x021BE128  thumb
 *   func_021BE170  0x021BE170  thumb
 *   data_021C8440  0x021C8440  data
 *   data_021C83A4  0x021C83A4  data
 *   func_021BE1BC 0x021BE1BC thumb
 *   func_021BE16C 0x021BE16C thumb
 *   func_021BD208 0x021BD208 thumb
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 */
#include "../../matched/include/Obj25442.h"

struct Ov208Mgr;
typedef unsigned short u16;

struct Pt { u16 x,y; };

struct Actor { char pad[0xc]; struct Pt pos; };

typedef unsigned char  u8;

typedef unsigned int   u32;

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

struct Ov208Eff { char pad[0x30]; struct Ov208Mgr *mgr; char pad2[0x10]; void *f44; void *f48; void *f4c; };

extern void func_0204B53C(const struct Actor *,struct Pt *);
extern void func_0204B528(struct Actor *,const struct Pt *);
extern void *func_020490F4(u32 id, u32 heap);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *h);
extern void func_02082BCC(void *p, u32 v, u32 n);
extern u32  func_021BD148(struct Ov208ActList *list, u32 heap);
extern int func_021BD3C0(void *mgr, int key);
extern void func_021BD3CC(u32 mgr, int key, u16 *pos);
extern void func_021BD378(int a, int b, int c);
extern void func_021BD368(int a, int b, int c);
extern int func_021BE300(int kind);
extern void func_021BE128(struct Ov208Scene *p);
extern void func_021BE170(struct Ov208Scene *p);
extern void func_021BE1BC(struct Ov208Eff *e);
extern void func_021BE16C(struct Ov208Eff *e);
extern void func_021BD208(struct Ov208Mgr *m);
extern void func_0204ADA4(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
void func_021BDD48(char *p,short offset);
void ov208_func_021BDD98(struct Ov208Scene *p);
void func_021BDFA8(struct Ov208Eff *e);
extern struct Ov208ActSrc data_021C8440[];
extern u16 data_021C83A4[][2];

void func_021BDD48(char *p,short offset)
{
    unsigned char i;
    struct Pt pt;
    for(i=0;i<((struct Obj25442 *)p)->f68;i++) {
        func_0204B53C(*(struct Actor **)(p+i*8+0x70),&pt);
        pt.y=*(short *)(*(char **)(p+i*8+0x6c)+6);
        pt.y=(short)pt.y+offset;
        func_0204B528(*(struct Actor **)(p+i*8+0x70),&pt);
    }
}


void ov208_func_021BDD98(struct Ov208Scene *p)
{
    struct Ov208ActList list;
    struct Ov208ActDesc descs[9];
    void *h;
    u8 i;
    int v;

    h = func_020490F4(0x9f, p->heap);
    p->f44 = func_0204AC18(h, 3, 0, 0x160, 0, 3, p->heap);
    p->f48 = func_0204A6C8(h, 0xd, 0, 0, p->heap);
    p->f4c = func_0204AF28(h, 0x1b, 0x2c, p->heap);
    func_02049238(h);
    p->count = 9;
    for (i = 0; i < p->count; i++)
        p->slots[i].src = &data_021C8440[i];
    for (i = 0; i < p->count; i++) {
        descs[i].f0 = p->slots[i].src->id;
        descs[i].x = p->slots[i].src->x;
        descs[i].y = p->slots[i].src->y;
        descs[i].h8 = p->slots[i].src->h8;
    }
    descs[3].ha = p->f48;
    descs[3].hc = p->f44;
    descs[3].he = p->f4c;
    descs[3].h10 = 3;
    descs[3].h12 = 3;
    descs[3].h14 = 7;
    descs[3].f18 = 0;
    descs[3].f1c = 0x54a;
    descs[4].ha = p->f48;
    descs[4].hc = p->f44;
    descs[4].he = p->f4c;
    descs[4].h10 = 2;
    descs[4].h12 = 2;
    descs[4].h14 = 6;
    descs[4].f18 = 0;
    descs[4].f1c = 0x54a;
    descs[5].ha = p->f48;
    descs[5].hc = p->f44;
    descs[5].he = p->f4c;
    descs[5].h10 = 1;
    descs[5].h12 = 1;
    descs[5].h14 = 5;
    descs[5].f18 = 0;
    descs[5].f1c = 0x54a;
    descs[6].ha = p->f48;
    descs[6].hc = p->f44;
    descs[6].he = p->f4c;
    descs[6].h10 = 0;
    descs[6].h12 = 0;
    descs[6].h14 = 4;
    descs[6].f18 = 0;
    descs[6].f1c = 0x54a;
    func_02082BCC(&list, 0, sizeof(list));
    list.descs = descs;
    list.count = 9;
    list.f8 = p->f28;
    list.fc = 1;
    list.f10 = 0xd;
    list.f14 = 8;
    list.f18 = 2;
    p->mgr = func_021BD148(&list, p->heap);
    for (i = 0; i < p->count; i++)
        p->slots[i].obj = func_021BD3C0((void *)p->mgr, p->slots[i].src->id);
    if (p->f4 == 0) {
        for (i = 0; i < 9; i++)
            func_021BD3CC(p->mgr, p->slots[i].src->id, data_021C83A4[i]);
        func_021BD378(p->mgr, p->slots[3].src->id, 0);
    }
    v = func_021BE300(p->f18);
    if (v != 9)
        func_021BD368(p->mgr, p->slots[v].src->id, 0);
    func_021BE128(p);
    func_021BE170(p);
    if (p->f40 == 0) {
        func_021BD378(p->mgr, p->slots[8].src->id, 0);
        func_021BD378(p->mgr, p->slots[7].src->id, 0);
    }
}

void func_021BDFA8(struct Ov208Eff *e)
{
    if (e->mgr != 0) {
        func_021BE1BC(e);
        func_021BE16C(e);
        func_021BD208(e->mgr);
        func_0204ADA4((u32)e->f44);
        func_0204A8D4((u32)e->f48);
        func_0204AFD8((u32)e->f4c);
    }
    e->mgr = 0;
}
