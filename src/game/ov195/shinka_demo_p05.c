/*
 * file:     shinka_demo_p05.c
 * unit:     yes
 * function: func_02205010, func_0220506C, func_02205070, func_02205100, func_02205138, func_02205168, func_022051A8, func_022051FC, func_022052E8, func_02205340, func_02205360
 * address:  0x02205010
 * region:   ov195
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049238 0x02049238 arm
 *   func_020409B4 0x020409B4 arm
 *   d_02208C4C 0x02208C4C data a4
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02205A28 0x02205A28 thumb ov195
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204B908  0x0204B908  arm
 *   func_0204B98C  0x0204B98C  arm
 *   func_02040588 0x02040588 arm
 *   func_02021D50 0x02021D50 thumb
 *   func_02049B40 0x02049B40 arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_0201F5DC 0x0201F5DC thumb
 *   func_02045B38 0x02045B38 arm
 *   func_0203101C 0x0203101C arm
 *   func_0201DD78 0x0201DD78 thumb
 *   func_02028590 0x02028590 thumb
 *   func_02028604 0x02028604 thumb
 *   func_0201CE48 0x0201CE48 thumb
 *   func_02031140 0x02031140 arm
 *   func_02045808 0x02045808 arm
 *   func_02045C04 0x02045C04 arm
 *   func_0203FB44 0x0203FB44 arm
 *   func_020452E8 0x020452E8 arm
 *   func_020310C4 0x020310C4 arm
 *   func_020286C4 0x020286C4 thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_02006238 0x02006238 thumb
 */
#include "../../matched/include/Obj08347.h"
#include "../../matched/include/Obj01971.h"
#include "../../matched/include/Obj14528.h"
#include "../../matched/include/Obj04593.h"
#include "../../matched/include/Obj04594.h"
#include "../../matched/include/Obj00844.h"
#include "../../matched/include/Obj02240.h"
#include "../../matched/include/Obj06642.h"

struct Obj;
struct Actor;
struct S02021D50;
struct Descriptor;
struct Cfg;
struct CharBuf;
struct MsgBank;
struct Tcbl;
struct Rec3;
struct S02031140;
struct U16Vec;
struct Rec;
struct Ctx;
typedef unsigned short u16;

typedef unsigned int u32;

typedef unsigned char u8;

typedef signed int     s32;

extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02049238(void *);
extern void func_020409B4(u32 index);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern int func_02205A28(char *a);
extern struct Obj *func_0204B294(void *, u32, u32, u32, const void *, u16, u16);
extern void func_0204B92C(struct Obj *, u32);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204AFD8(u32);
extern void func_0204A8D4(u32);
extern void func_0204ADA4(u32);
extern void func_0204B908(int, int);
extern u32 func_0204B98C(struct Actor *a);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02021D50(struct S02021D50 *p);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32);
extern void *func_0201F5DC(void *a0, u32 a1, u32 a2, u32 a3);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct Tcbl *func_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
extern void func_0201DD78(u32 r, u32 g, u32 b);
extern u32 func_02028590(int, int, int, u16);
extern int func_02028604(int);
extern void func_0201CE48(struct Rec3 *p);
extern void func_02031140(struct S02031140 *p);
extern void func_02045808(struct U16Vec *vec);
extern unsigned int func_02045C04(struct Rec *rec);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_020310C4(struct Tcbl *p);
extern void func_020286C4(struct Ctx *ctx, void *p, void *cell);
extern void func_020061E4(u32 a);
extern int func_02006238(void);
void func_02205010(int a, char *b);
void func_0220506C(int a0, int *a1);
void func_02205070(int a, char *b);
void func_02205100(void *unused,char *p);
void func_02205138(int a, int *p);
int func_02205168(int a, int *p);
void func_022051A8(int task, char *p);
void func_022051FC(int a, char *b);
void func_022052E8(int task, int *p);
void func_02205340(int a, char *b);
int func_02205360(int a);
extern u8 d_02208C4C[];


void func_02205010(int a, char *b)
{
    void *h = func_020490F4(0xb6, ((struct Obj08347 *)b)->f2);

    func_02049B68(h, 3, 0, 0, 0x20, ((struct Obj08347 *)b)->f2);
    func_02049658(h, 5, 2, 0, 0, 0, ((struct Obj08347 *)b)->f2);
    func_020498F4(h, 4, 2, 0, 0, 0, ((struct Obj08347 *)b)->f2);
    func_02049238(h);
    func_020409B4(2);
}

void func_0220506C(int a0, int *a1) {}


void func_02205070(int a, char *b)
{
    void *h;
    u8 i;
    int z;

    h = func_020490F4(0xb6, ((struct Obj01971 *)b)->f2);
    i = 0;
    ((struct Obj01971 *)b)->f40 = func_0204AC18(h, 3, 0, 0, i, 1, ((struct Obj01971 *)b)->f2);
    ((struct Obj01971 *)b)->f3C = func_0204A6C8(h, 2, 0, 0, ((struct Obj01971 *)b)->f2);
    ((struct Obj01971 *)b)->f44 = func_0204AF28(h, 1, 0, ((struct Obj01971 *)b)->f2);
    func_02049238(h);
    for (z = i; i < 6; i++) {
        char *e = b + i * 4;
        ((struct Obj14528 *)e)->f48 = (u32)func_0204B294((void *)func_02205A28((char *)(((struct Obj01971 *)b)->f4)), ((struct Obj01971 *)b)->f3C, ((struct Obj01971 *)b)->f40,
                                           ((struct Obj01971 *)b)->f44, d_02208C4C + i * 8, z, ((struct Obj01971 *)b)->f2);
        func_0204B92C((struct Obj *)((struct Obj14528 *)e)->f48, z);
    }
    ((struct Obj01971 *)b)->f60 = 1;
}

void func_02205100(void *unused,char *p) {u8 i;if(((struct Obj04593 *)p)->f60){for(i=0;i<6;i++)func_0204B3B4((struct Obj *)(*(u32 *)(p+0x48+i*4)));func_0204AFD8(((struct Obj04593 *)p)->f44);func_0204A8D4(((struct Obj04593 *)p)->f3C);func_0204ADA4(((struct Obj04593 *)p)->f40);((struct Obj04593 *)p)->f60=0;}}


/*
 * Leaf of the func_022040E0 dependency tree: when the scene object has the
 * +0x60 pointer set, tear down the six +0x48 handles.
 */
void func_02205138(int a, int *p)
{
    unsigned char i;

    if (p[0x18] == 0)
        return;
    for (i = 0; i < 6; i++) {
        func_0204B908(p[0x12 + i], 0);
        func_0204B92C((struct Obj *)p[0x12 + i], 1);
    }
}


/*
 * Leaf of the func_022040E0 dependency tree: probe all six +0x48 handles;
 * if every one is idle, hand the scene object to func_02205100.  A missing
 * +0x60 pointer reports success without probing.
 */
int func_02205168(int a, int *p)
{
    unsigned char i;

    if (p[0x18] != 0) {
        int ok = 1;

        for (i = 0; i < 6; i++) {
            if (func_0204B98C((struct Actor *)p[0x12 + i]) != 0) {
                ok = 0;
                break;
            }
        }
        if (ok)
            func_02205100((void *)a, (char *)p);
        return ok;
    }
    return 1;
}

/*
 * extent: 82 code bytes followed by two zero alignment bytes at 0x022051FA.
 */
void func_022051A8(int task, char *p)
{
    switch (((struct Obj04594 *)p)->f88) {
    case 1:
        func_02040588(1, 1);
        ((struct Obj04594 *)p)->f8C = 1;
        ((struct Obj04594 *)p)->f88 = 0;
        break;
    case 2:
        func_02040588(1, 0);
        ((struct Obj04594 *)p)->f8C = 0;
        ((struct Obj04594 *)p)->f88 = 0;
        break;
    }
    if (((struct Obj04594 *)p)->fA8)
        func_02021D50(((struct Obj04594 *)p)->fA8);
}


void func_022051FC(int a, char *b)
{
    u32 p;

    func_02049B40(0x17, 5, 0, 0x20, 0x20, ((struct Obj00844 *)b)->f2);
    ((struct Obj00844 *)b)->f70 = func_020450F0(1, 0, 0, 1, 1, 1, 0);
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)((struct Obj00844 *)b)->f70)), 0);
    func_02045334((struct Descriptor *)((struct Obj00844 *)b)->f70);
    ((struct Obj00844 *)b)->f6C = func_020450F0(1, 1, 0x13, 0x1e, 4, 1, 1);
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)((struct Obj00844 *)b)->f6C)), 0);
    p = ((struct Obj00844 *)b)->f6C;
    func_02045334((struct Descriptor *)p);
    func_02045374((struct Cfg *)p);
    func_02041B6C(func_02045730((struct Descriptor *)p));
    ((struct Obj00844 *)b)->f74 = (u32)func_0201F5DC((void *)1, 2, 0, ((struct Obj00844 *)b)->f2);
    ((struct Obj00844 *)b)->f78 = (u32)func_02045B38(0, 2, 0xac, ((struct Obj00844 *)b)->f2);
    ((struct Obj00844 *)b)->f7C = (u32)func_02045B38(0, 2, 0xcc, ((struct Obj00844 *)b)->f2);
    ((struct Obj00844 *)b)->f68 = (u32)func_0203101C(((struct Obj00844 *)b)->f2, ((struct Obj00844 *)b)->f2, 1, 0);
    func_0201DD78(1, 2, 0xf);
    ((struct Obj00844 *)b)->f80 = 0;
    ((struct Obj00844 *)b)->f64 = 0;
    ((struct Obj00844 *)b)->f84 = func_02028590(0xf, 1, 1, ((struct Obj00844 *)b)->f2);
    ((struct Obj00844 *)b)->f88 = 0;
    func_02040588(1, 0);
    ((struct Obj00844 *)b)->f8C = 0;
}

void func_022052E8(int task, int *p)
{
    func_02028604(((struct Obj02240 *)p)->f84);
    if (((struct Obj02240 *)p)->f64) func_0201CE48((struct Rec3 *)(((struct Obj02240 *)p)->f64));
    func_02031140((struct S02031140 *)(((struct Obj02240 *)p)->f68));
    if (((struct Obj02240 *)p)->f80) func_02045808((struct U16Vec *)(((struct Obj02240 *)p)->f80));
    func_02045C04(((struct Obj02240 *)p)->f78);
    func_02045C04(((struct Obj02240 *)p)->f7C);
    func_0203FB44(1, (unsigned short)(((struct Obj02240 *)p)->f74), (unsigned short)(((struct Obj02240 *)p)->f74 >> 16));
    func_020452E8((struct Descriptor *)(((struct Obj02240 *)p)->f6C));
    func_020452E8((struct Descriptor *)(((struct Obj02240 *)p)->f70));
}


void func_02205340(int a, char *b)
{
    func_020310C4((struct Tcbl *)(((struct Obj06642 *)b)->f68));
    if (((struct Obj06642 *)b)->f64 != 0)
        func_020286C4((struct Ctx *)(((struct Obj06642 *)b)->f84), (void *)(((struct Obj06642 *)b)->f64), (void *)(((struct Obj06642 *)b)->f6C));
}


int func_02205360(int a)
{
    switch (a) {
    case 3:
        func_020061E4(0x56b);
        break;
    case 5:
        return func_02006238();
    }
    return 0;
}
