/*
 * file:     zukan_detail_graphic_p05.c
 * unit:     yes
 * function: func_021C0714, func_021C0740, func_021C0788, func_021C0898, func_021C08E8, func_021C0950, func_021C0968, func_021C0980, func_021C0A88, func_021C0A8C, func_021C0B10, func_021C0B58, func_021C0B6C, func_021C0C00
 * address:  0x021C0714
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
 *   func_021BDC48 0x021BDC48 thumb ov208
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_02045770  0x02045770  arm
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 *   data_021C8570  0x021C8570  data
 *   data_021C85A4  0x021C85A4  data
 *   func_02049B90  0x02049B90  arm
 *   func_020450F0  0x020450F0  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045B38  0x02045B38  arm
 *   func_02045C04 0x02045C04 arm
 *   func_020452E8 0x020452E8 arm
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_020490F4  0x020490F4  arm
 *   func_02049BDC  0x02049BDC  arm
 *   func_02049740  0x02049740  arm
 *   func_02049990  0x02049990  arm
 *   func_02049238  0x02049238  arm
 *   func_0203FB44  0x0203FB44  arm
 *   func_02040804  0x02040804  arm
 *   func_02041EE4  0x02041EE4  arm
 *   func_0204B404  0x0204B404  arm
 *   func_0204B454  0x0204B454  arm
 *   ov208_func_021BC3B4  0x021BC3B4  thumb  ov208
 *   func_0204B98C  0x0204B98C  arm
 *   func_0204B878  0x0204B878  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0201BC3C  0x0201BC3C  thumb
 *   func_0204ACEC  0x0204ACEC  arm
 *   func_0201BC78  0x0201BC78  thumb
 *   func_0201BCEC  0x0201BCEC  thumb
 *   func_0204AF28  0x0204AF28  arm
 *   func_0201BABC  0x0201BABC  thumb
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204B294  0x0204B294  arm
 *   func_0201BB5C  0x0201BB5C  thumb
 *   func_0204B6F4  0x0204B6F4  arm
 *   func_0204B688  0x0204B688  arm
 */
#include "../../matched/include/Obj14653.h"
#include "../../matched/include/Obj25499.h"
#include "../../matched/include/Obj02346.h"
#include "../../matched/include/Obj06683.h"
#include "../../matched/include/Obj14654.h"
#include "../../matched/include/Obj12127.h"

#define W(o) (*(u32 *)(p + (o)))
#define OBJ(i) (((u32 *)(p + 0xbc))[i])
struct PrintSys;
struct Descriptor;
struct Cfg;
struct CharBuf;
struct MsgBank;
struct Rec;
struct Obj;
struct Vec2;
struct Actor;
struct PtS;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef int            s32_021C0714;

typedef short          s16;

typedef int            s32_021C0788;

struct WinCfg {
    u8 bg;
    u8 x;
    u8 y;
    u8 w;
    u8 h;
    u8 pal;
    u8 base;
};

struct WinCfg2 {
    struct WinCfg e[2];
};

struct WinCfg4 {
    struct WinCfg e[4];
};

typedef int            s32_021C08E8;

typedef int            s32_021C0A8C;

typedef int            s32_021C0B10;

typedef struct {
    u16 x;
    u16 y;
    u16 z;
    u8 pri;
    u8 f7;
} ObjPos;

typedef signed int     s32_021C0B6C;

extern u32 func_0201C4E4(struct PrintSys *ps);
extern void *func_02045770(struct Descriptor *win);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02045334(struct Descriptor *v);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32 bit);
extern void func_02049B90(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern unsigned int func_02045C04(struct Rec *rec);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_0201C6EC(struct PrintSys *);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049BDC(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern u32 func_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);
extern u32 func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void func_02049238(void *h);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern unsigned int func_02040804(unsigned int layer);
extern void func_02041EE4(u32 index, u32 a, u32 b);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern void *ov208_func_021BC3B4(int key);
extern u32 func_0204B98C(struct Actor *a);
extern void func_0204B878(u32 obj, u32 anim);
extern void func_0204B92C(struct Obj *obj, u32 v);
struct Ov208Scene;
extern void func_021BDC48(struct Ov208Scene *s, u32 on);
extern int func_0201BC3C(void);
extern int func_0204ACEC(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern int func_0201BC78(void);
extern int func_0201BCEC(void);
extern s32_021C0B10 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_0204AFD8(u32 i);
extern void func_0204ADA4(u32 i);
extern u32  func_0201BABC(u32 species, u32 form, u32 gender, u32 isEgg);
extern s32_021C0B6C func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern struct Obj *func_0204B294(void *owner, u32 i, u32 j, u32 k, const void *position, u16 f, u16 g);
extern u32  func_0201BB5C(u32 species, u32 form, u32 half, u32 isEgg);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern void func_0204B688(struct Actor *actor, u32 value);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204A8D4(u32 i);
void ov208_func_021C0714(u16 *heap, u8 *p, int key);
void ov208_func_021C0740(u16 *heap, u8 *p, int key, u8 i);
void ov208_func_021C0788(u16 *heap, u8 *p, int key);
void func_021C0898(void *unused, char *p, void *a2);
void ov208_func_021C08E8(u16 *heap, u8 *p, int key);
void func_021C0950(void *unused, u8 *p, void *a2);
void func_021C0968(int a, int b, int c);
void func_021C0980(int a, unsigned char *p, int a2);
void func_021C0A88(int a0, int a1, int a2);
void ov208_func_021C0A8C(u16 *heap, u8 *p, int key);
void ov208_func_021C0B10(u16 *heap, u8 *p, int key);
void func_021C0B58(void *a, char *q, void *a2);
u32 func_021C0B6C(u32 *slot, u32 a, u32 b, u32 res, u16 heap, u32 species, u32 form, u32 gender, u32 isEgg, u8 x, u8 y);
void func_021C0C00(void *a, void *b);
extern const struct WinCfg2 data_021C8570;
extern const struct WinCfg4 data_021C85A4;


void ov208_func_021C0714(u16 *heap, u8 *p, int key)
{
    u8 i;

    for (i = 0; i < 4; i++) {
        func_0201C4E4((struct PrintSys *)(((u32 *)(p + 0x34))[i]));
        ov208_func_021C0740(heap, p, key, i);
    }
}


void ov208_func_021C0740(u16 *heap, u8 *p, int key, u8 i)
{
    u32 w;

    if (((u32 *)(p + 0x24))[i] != 0) {
        if (func_0201C6C4((struct PrintSys *)(((u32 *)(p + 0x34))[i]), (void *)((u32)func_02045770((struct Descriptor *)((u32 *)(p + 0x14))[i]))) == 0) {
            w = ((u32 *)(p + 0x14))[i];
            func_02045334((struct Descriptor *)w);
            func_02045374((struct Cfg *)w);
            func_02041B6C(func_02045730((struct Descriptor *)w));
            ((u32 *)(p + 0x24))[i] = 0;
        }
    }
}


void ov208_func_021C0788(u16 *heap, u8 *p, int key)
{
    struct WinCfg2 a;
    struct WinCfg4 b;
    u8 i;

    a = data_021C8570;
    b = data_021C85A4;
    func_02049B90(0x17, 5, 4, 0, 0x100, 0x20, *heap);
    func_02049B90(0x17, 5, 0, 0, 0, 0x20, *heap);
    for (i = 0; i < 2; i++) {
        *(u32 *)(p + i * 4 + 0x44) = func_020450F0(a.e[i].bg, a.e[i].x, a.e[i].y, a.e[i].w, a.e[i].h, a.e[i].pal, a.e[i].base);
        func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)*(u32 *)(p + i * 4 + 0x44))), 0);
        func_02045334((struct Descriptor *)*(u32 *)(p + i * 4 + 0x44));
    }
    for (i = 0; i < 4; i++) {
        *(u32 *)(p + i * 4 + 0x14) = func_020450F0(b.e[i].bg, b.e[i].x, b.e[i].y, b.e[i].w, b.e[i].h, b.e[i].pal, b.e[i].base);
        func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)*(u32 *)(p + i * 4 + 0x14))), 0);
        func_02045334((struct Descriptor *)*(u32 *)(p + i * 4 + 0x14));
    }
    W(0xc) = (u32)func_02045B38(0, 2, 0xea, *heap);
    W(0x10) = (u32)func_02045B38(0, 2, 0x59, *heap);
}

void func_021C0898(void *unused, char *p, void *a2)
{
    u8 i;
    for (i = 0; i < 2; i++) func_02045C04(*(struct Rec **)(p + i * 4 + 0xc));
    for (i = 0; i < 4; i++) {
        *(unsigned *)(p + i * 4 + 0x24) = 0;
        func_0201C6EC(*(struct PrintSys **)(p + i * 4 + 0x34));
        func_020452E8(*(struct Descriptor **)(p + i * 4 + 0x14));
    }
    for (i = 0; i < 2; i++) func_020452E8(*(struct Descriptor **)(p + i * 4 + 0x44));
}


void ov208_func_021C08E8(u16 *heap, u8 *p, int key)
{
    void *h;

    h = func_020490F4(0x9f, *heap);
    func_02049BDC(h, 2, 4, 0, 0, 0x100, *heap);
    ((struct Obj14653 *)p)->f68 = func_02049740(h, 12, 7, 0, 0, *heap);
    func_02049990(h, 0x26, 7, 0, (u16)((struct Obj14653 *)p)->f68, 0, 0, *heap);
    func_02049238(h);
}


void func_021C0950(void *unused, u8 *p, void *a2)
{
    u32 v = ((struct Obj25499 *)p)->f68;
    func_0203FB44(7, (u16)v, (u16)(v >> 16));
}


void func_021C0968(int a, int b, int c)
{
    func_021C0980(a, (unsigned char *)b, c);
    func_021C0A88(a, b, c);
}


void func_021C0980(int a, unsigned char *p, int a2)
{
    switch (*(unsigned int *)&((struct Obj02346 *)p)->f70) {
    case 0:
        break;
    case 2:
        break;
    case 1:
        if ((int)func_02040804((int)7) >= 0x40) {
            func_02041EE4(7, 3, 0x40);
            ((struct Obj02346 *)p)->f70 = 2;
        } else {
            func_02041EE4(7, 4, 8);
            func_02041EE4(6, 4, 8);
        }
        break;
    case 3:
        if ((int)func_02040804((int)7) <= 0) {
            func_02041EE4(7, 3, 0);
            ((struct Obj02346 *)p)->f70 = 0;
        } else {
            func_02041EE4(7, 5, 8);
            func_02041EE4(6, 5, 8);
        }
        break;
    }
    if (*(int *)(p + 0x5c + 4 * ((struct Obj02346 *)p)->f64) == 0)
        return;
    {
        short v[2];

        switch (*(unsigned int *)&((struct Obj02346 *)p)->f74) {
        case 0:
            break;
        case 2:
            break;
        case 1:
            func_0204B454((struct Actor *)*(int *)(p + 0x5c + 4 * ((struct Obj02346 *)p)->f64), (struct PtS *)v, 1);
            if (v[1] <= 0x70) {
                v[1] = 0x70;
                ((struct Obj02346 *)p)->f74 = 2;
            } else {
                v[1] -= 8;
            }
            func_0204B404((struct Obj *)(*(int *)(p + 0x5c + 4 * ((struct Obj02346 *)p)->f64)), (const struct Vec2 *)v, 1);
            break;
        case 3:
            func_0204B454((struct Actor *)*(int *)(p + 0x5c + 4 * ((struct Obj02346 *)p)->f64), (struct PtS *)v, 1);
            if (v[1] >= 0xb0) {
                v[1] = 0xb0;
                ((struct Obj02346 *)p)->f74 = 0;
            } else {
                v[1] += 8;
            }
            func_0204B404((struct Obj *)(*(int *)(p + 0x5c + 4 * ((struct Obj02346 *)p)->f64)), (const struct Vec2 *)v, 1);
            break;
        }
    }
}

/*
 * Empty stub; the listing pads it with two zero bytes.
 */
void func_021C0A88(int a0, int a1, int a2)
{
}


void ov208_func_021C0A8C(u16 *heap, u8 *p, int key)
{
    void *scene;
    u8 sel;
    u32 anim;
    u32 next;
    u32 nextAnim;

    scene = ov208_func_021BC3B4(key);
    sel = p[0xd8];
    if (sel == 2) {
        anim = 2;
        next = 1;
        nextAnim = 4;
    } else if (sel == 1) {
        anim = 4;
        next = 2;
        nextAnim = 2;
    }
    if (sel != 7 && func_0204B98C((struct Actor *)OBJ(sel)) == 0) {
        func_0204B878(OBJ(p[0xd8]), anim);
        func_0204B92C((struct Obj *)OBJ(next), 1);
        func_0204B878(OBJ(next), nextAnim);
        p[0xd8] = 7;
        if (((struct Obj06683 *)p)->f6C == 0 || ((struct Obj06683 *)p)->f6C == 5)
            func_021BDC48((struct Ov208Scene *)scene, 1);
    }
}


void ov208_func_021C0B10(u16 *heap, u8 *p, int key)
{
    void *h;

    h = func_020490F4(7, *heap);
    ((struct Obj14654 *)p)->f54 = func_0204ACEC(h, func_0201BC3C(), 1, 0, *heap);
    ((struct Obj14654 *)p)->f58 = func_0204AF28(h, func_0201BC78(), func_0201BCEC(), *heap);
    func_02049238(h);
}


/*
 * Calls 0x0204AFD8 on +0x58 and 0x0204ADA4 on +0x54 of the second argument.
 */
void func_021C0B58(void *a, char *q, void *a2)
{
    func_0204AFD8(((struct Obj12127 *)q)->f58);
    func_0204ADA4(((struct Obj12127 *)q)->f54);
}


u32 func_021C0B6C(u32 *slot, u32 a, u32 b, u32 res, u16 heap, u32 species, u32 form,
                  u32 gender, u32 isEgg, u8 x, u8 y)
{
    ObjPos pos;
    void *h;
    u32 obj;

    h = func_020490F4(7, heap);
    pos.x = x;
    pos.y = y;
    pos.z = 1;
    pos.pri = 1;
    pos.f7 = 0;
    *slot = func_0204A6C8(h, func_0201BABC(species, form, gender, isEgg), 0, 1, heap);
    obj = (u32)func_0204B294((void *)res, *slot, a, b, &pos, 1, heap);
    func_0204B92C((struct Obj *)obj, 0);
    func_0204B6F4((struct Obj *)obj, func_0201BB5C(species, form, gender, isEgg), 0);
    func_0204B688((struct Actor *)obj, 0);
    func_02049238(h);
    return obj;
}


/*
 * Calls 0x0204B3B4 on the second argument, then 0x0204A8D4 on the first.
 */
void func_021C0C00(void *a, void *b)
{
    func_0204B3B4(b);
    func_0204A8D4((u32)a);
}
