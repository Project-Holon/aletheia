/*
 * file:     unit_02184D30_p01.c
 * unit:     yes
 * function: func_02184D30, func_02184ECC, func_02185004, func_0218506C
 * address:  0x02184D30
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204B294  0x0204B294  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B878  0x0204B878  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B84C  0x0204B84C  arm
 *   func_0204B800  0x0204B800  arm
 *   func_020434DC  0x020434DC  arm
 *   func_02043598  0x02043598  arm
 *   d_02186BEC     0x02186BEC  data  ov023  a2
 *   func_02045088  0x02045088  arm
 *   func_020450F0  0x020450F0  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_0203101C  0x0203101C  arm
 *   func_0201C440  0x0201C440  thumb
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02185F74  0x02185F74  thumb  ov023
 *   func_0203115C  0x0203115C  arm
 *   func_02031140  0x02031140  arm
 *   func_0201C6EC  0x0201C6EC  thumb
 *   func_0201C4C0  0x0201C4C0  thumb
 *   func_020452E8  0x020452E8  arm
 *   func_020450C8  0x020450C8  arm
 *   func_0204B528 0x0204B528 arm
 */
#include "../../matched/include/Obj03624.h"

struct Obj;
struct Node;
struct Descriptor;
struct Cfg;
struct CharBuf;
struct Tcbl;
struct PrintSys;
struct S02031140;
struct Actor;
struct Pt;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed short   s16;

typedef unsigned int   u32;

typedef struct Pos {
    s16 x;
    s16 y;
    s16 z;
    u8 a;
    u8 b;
} Pos;

typedef struct Ent_02184D30 {
    u16 x;
    u16 y;
    u16 anim;
} Ent_02184D30;

typedef struct Work {
    u8  pad00[0x38];
    u32 f38, f3C, f40, f44, f48, f4C, f50, f54, f58, f5C;
    u32 a60[14];
    u32 a98[14];
    u32 aD0[12];
    u32 f100;
} Work;

typedef struct {
    u32 w;
    u8 f;
} Ent_02184ECC;

typedef struct {
    char pad0[0x104];
    u32 win[7];
    char pad120[0xc];
    Ent_02184ECC ent[7];
    u32 f164;
    u32 f168;
    u32 f16c;
    u32 f170;
} W;

typedef struct { u16 x, y; } Pt;

extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_0204B84C(u32, int);
extern void func_0204B800(struct Node *node, u32 val);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);
extern void func_02045088(u16 heapId);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *a);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern struct Tcbl *func_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
extern u32 func_0201C440(void *p);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 a);
extern void func_02185F74(u32 *a, int b, W *p);
extern void func_0203115C(struct Tcbl *p);
extern void func_02031140(struct S02031140 *p);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_020450C8(void);
extern void func_0204B528(struct Actor *actor, const struct Pt *src);
void func_02184D30(Work *p);
void func_02184ECC(W *p);
void func_02185004(char *p);
void func_0218506C(void *actor, int x, int y);
extern const Ent_02184D30 d_02186BEC[];


void func_02184D30(Work *p)
{
    Pos pos;
    int i;
    int j;

    pos.x = 0;
    pos.y = 0;
    pos.z = 0;
    pos.a = 1;
    pos.b = 1;
    for (i = 0; i < 5; i++) {
        pos.x = i * 0x28 + 0x18;
        pos.y = 0x40;
        p->a60[i] = (u32)func_0204B294((void *)p->f38, p->f40, p->f3C, p->f44, &pos, 0, 0x28);
        func_0204B92C((struct Obj *)p->a60[i], 1);
        func_0204B878((struct Obj *)p->a60[i], i);
        func_0204B3DC((struct Obj *)p->a60[i], 0);
    }
    for (j = 0; j < 12; j++) {
        pos.x = d_02186BEC[j].x;
        pos.y = d_02186BEC[j].y;
        p->aD0[j] = (u32)func_0204B294((void *)p->f38, p->f40, p->f3C, p->f44, &pos, 0, 0x28);
        func_0204B92C((struct Obj *)p->aD0[j], 1);
        func_0204B878((struct Obj *)p->aD0[j], d_02186BEC[j].anim);
        if (j >= 8) {
            func_0204B84C(p->aD0[j], 2);
        }
    }
    func_0204B878((struct Obj *)p->aD0[0], 6);
    for (i = 0; i < 5; i++) {
        pos.x = 0x18;
        pos.y = i * 0x20 + 0x20 + 0x100000u;
        p->a98[i] = (u32)func_0204B294((void *)p->f38, p->f58, p->f54, p->f5C, &pos, 1, 0x28);
        func_0204B92C((struct Obj *)p->a98[i], 1);
        func_0204B878((struct Obj *)p->a98[i], i);
        func_0204B800((struct Node *)p->a98[i], 1);
        func_0204B3DC((struct Obj *)p->a98[i], 0);
    }
    pos.x = 0xD4;
    pos.y = 0xA0;
    p->f100 = (u32)func_0204B294((void *)p->f38, p->f4C, p->f48, p->f50, &pos, 0, 0x28);
    func_0204B92C((struct Obj *)p->f100, 1);
    func_0204B878((struct Obj *)p->f100, 1);
    func_0204B3DC((struct Obj *)p->f100, 1);
    func_020434DC(0x10, 1);
    func_02043598(0x10, 1);
}


void func_02184ECC(W *p)
{
    int i;
    u32 w;

    func_02045088(0x28);
    p->win[6] = func_020450F0(0, 2, (u8)1, 0x1b, (u32)4, (u32)0xd, (u32)1);
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->win[6])), 0xf);
    p->ent[6].w = p->win[6];
    p->ent[6].f = 0;
    p->win[5] = func_020450F0(1, 1, (u8)2, 0x1e, (u32)0xf, (u32)0, (u32)1);
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->win[5])), 2);
    p->f170 = (u32)func_0203101C(0x28, 0x28, 0x20, 0x20);
    p->f164 = func_0201C440((void *)0x28);
    p->f168 = func_0201C440((void *)0x28);
    for (i = 0; i < 5; i++) {
        p->win[i] = func_020450F0(4, 5, (u8)(i * 4 + 3), 0xa, (u32)2, (u32)0xd, (u32)1);
        func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->win[i])), 0);
        p->ent[i].w = p->win[i];
        p->ent[i].f = 0;
        w = p->win[i];
        func_02045334((struct Descriptor *)w);
        func_02045374((struct Cfg *)w);
        func_020409B4(func_02045730((struct Descriptor *)w));
    }
    func_02185F74(p->win, 0x44f, p);
}


void func_02185004(char *p)
{
    int i;

    func_0203115C((struct Tcbl *)(((struct Obj03624 *)p)->f170));
    func_02031140((struct S02031140 *)(((struct Obj03624 *)p)->f170));
    func_0201C6EC((struct PrintSys *)(((struct Obj03624 *)p)->f168));
    func_0201C4C0((struct PrintSys *)(((struct Obj03624 *)p)->f168));
    func_0201C6EC((struct PrintSys *)(((struct Obj03624 *)p)->f164));
    func_0201C4C0((struct PrintSys *)(((struct Obj03624 *)p)->f164));
    for (i = 0; i < 5; i++)
        func_020452E8((struct Descriptor *)(*(u32 *)(p + 0x104 + i * 4)));
    func_020452E8((struct Descriptor *)(((struct Obj03624 *)p)->f118));
    func_020452E8((struct Descriptor *)(((struct Obj03624 *)p)->f11C));
    func_020450C8();
}

void func_0218506C(void *actor, int x, int y)
{
    Pt p;
    p.x = x;
    p.y = y - 8;
    func_0204B528(actor, (const struct Pt *)(&p));
}
