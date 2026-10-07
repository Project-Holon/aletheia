/*
 * file:     zukan_detail_graphic_p17.c
 * unit:     yes
 * function: func_021BE82C, func_021BE840, func_021BE844, func_021BE854, func_021BE864, func_021BE868, func_021BE8FC
 * address:  0x021BE82C
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
 *   func_021BE9C8        0x021BE9C8  thumb
 *   ov208_func_021BE920  0x021BE920  thumb
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_0204384C 0x0204384C arm
 *   func_020437EC 0x020437EC arm
 *   func_020437D4 0x020437D4 arm
 *   func_02040B58 0x02040B58 arm
 *   func_0204994C 0x0204994C arm
 *   func_020413B0 0x020413B0 arm
 *   func_02045B38 0x02045B38 arm
 */
#include "../../matched/include/Obj05867.h"

struct Bmp;
struct Descriptor;
struct CharBuf;
struct MsgBank;
struct Obj020437AC;
struct Rec;
typedef unsigned int u32;

struct Ov208Icon_021BE82C {
    u32 pad0[3];
    int fc;
};

typedef unsigned char u8;

struct Ov208Icon_021BE840 {
    u32 f0;
    u32 f4;
    int state;
    int fc;
    u8  step;
};

struct Ov208Icon_021BE844 {
    u32 f0;
    u32 f4;
    int state;
    int fc;
    u8  step;
};

struct Ov208Icon_021BE854 {
    u32 f0;
    u32 f4;
    int state;
    int fc;
    u8  step;
};

typedef unsigned short u16;

struct Ov208Gfx { u16 heap; u16 pad; int f4; int f8; int fc; int f10; u32 f14; void *f18; int f1c; int f20; int f24; };

extern void func_021BE9C8(void);
extern void ov208_func_021BE920(struct Ov208Icon_021BE82C *p);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *a);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *a);
extern struct Bmp *func_0204384C(u32 arc, u32 member, u32 heap2, u32 heap);
extern u32 func_020437EC(const struct Bmp *bmp);
extern void *func_020437D4(const struct Bmp *bmp);
extern u32 func_02040B58(u32 index, const void *src, u32 size);
extern u32 func_0204994C(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern unsigned int func_02045C04(struct Rec *rec);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern void func_020437AC(struct Obj020437AC *p);
extern u32 func_020452E8(struct Descriptor *d);
void ov208_func_021BE82C(struct Ov208Icon_021BE82C *p, int kind);
int ov208_func_021BE840(struct Ov208Icon_021BE840 *p);
void ov208_func_021BE844(struct Ov208Icon_021BE844 *p);
void ov208_func_021BE854(struct Ov208Icon_021BE854 *p);
void ov208_func_021BE864(void *p);
void func_021BE868(struct Ov208Gfx *g);
void func_021BE8FC(char *p);


void ov208_func_021BE82C(struct Ov208Icon_021BE82C *p, int kind)
{
    p->fc = kind;
    func_021BE9C8();
    ov208_func_021BE920(p);
}


int ov208_func_021BE840(struct Ov208Icon_021BE840 *p)
{
    return p->state;
}


void ov208_func_021BE844(struct Ov208Icon_021BE844 *p)
{
    if (p->state != 2) {
        p->state = 1;
        p->step = 0;
    }
}


void ov208_func_021BE854(struct Ov208Icon_021BE854 *p)
{
    if (p->state != 0) {
        p->state = 3;
        p->step = 0;
    }
}

void ov208_func_021BE864(void *p)
{
}

/*
 * tail: two zero alignment bytes after the function (listing extent is 2 bytes longer).
 */
void func_021BE868(struct Ov208Gfx *g)
{
    g->f14 = func_020450F0(5, 0, 0, 0x10, 1, 13, 0);
    func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)g->f14)), 0);
    func_02045334((struct Descriptor *)g->f14);
    g->f18 = func_0204384C(0x9f, 14, 0, g->heap);
    g->f20 = func_020437EC(g->f18);
    g->f1c = func_02040B58(5, func_020437D4(g->f18), g->f20);
    func_0204994C(0x9f, 0x25, 5, 0, g->f1c, 0xc0, 0, g->heap);
    func_020413B0(5, 0, 0, 0x20, 0x18, 13);
    g->f24 = (int)func_02045B38(0, 2, 0xea, g->heap);
}


void func_021BE8FC(char *p)
{
    func_02045C04((struct Rec *)(((struct Obj05867 *)p)->f24));
    func_0203FB44(5, ((struct Obj05867 *)p)->f1C, ((struct Obj05867 *)p)->f20);
    func_020437AC((struct Obj020437AC *)(((struct Obj05867 *)p)->f18));
    func_020452E8((struct Descriptor *)(((struct Obj05867 *)p)->f14));
}
