/*
 * file:     startmenu_p07.c
 * unit:     yes
 * function: func_021BB184, func_021BB328, func_021BB380, func_021BB474, func_021BB484
 * address:  0x021BB184
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   func_0204A48C  0x0204A48C  arm
 *   func_02008550  0x02008550  thumb
 *   func_0204B100  0x0204B100  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204ABF0  0x0204ABF0  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_0204B294  0x0204B294  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_020434DC  0x020434DC  arm
 *   func_02043598  0x02043598  arm
 *   func_02049238  0x02049238  arm
 *   d_021BD688     0x021BD688  data  a4
 *   d_021BD60C     0x021BD60C  data  a4
 *   d_021BD5DC     0x021BD5DC  data  a4
 *   d_021BD5E4     0x021BD5E4  data  a4
 *   d_021BD5D4     0x021BD5D4  data  a4
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_0204A5AC  0x0204A5AC  arm
 *   func_0202C9B4  0x0202C9B4  thumb
 *   func_0202CA3C  0x0202CA3C  thumb
 *   func_0202CEBC  0x0202CEBC  thumb
 *   d_021BD5EC     0x021BD5EC  data  a4
 *   func_0202CA0C  0x0202CA0C  thumb
 *   func_0207D63C  0x0207D63C  arm
 */
#include "../../matched/include/Obj20817.h"
#include "../../matched/include/Obj00014.h"
#include "../../matched/include/Obj20818.h"

struct Bank;
struct Cfg;
struct Sub0200852CObj;
struct Obj;
struct WinMgr;
typedef unsigned short u16;

typedef unsigned int u32;

typedef struct T28 {
    u32 w[7];
} T28;

typedef unsigned char  u8;

typedef signed int     s32;

struct Ent {
    u16 f0;
    u16 f2;
};

extern void *func_020490F4(u32 id, u32 heap);
extern void func_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204ABF0(void *a, u32 b, u32 c, u32 d, u16 g);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern struct Obj *func_0204B294(void *owner, u32 i, u32 j, u32 k, const void *position, u16 space, u16 heap);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B92C(struct Obj *, u32);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);
extern void func_02049238(void *);
extern void func_0204B3B4(struct Obj *p);
extern unsigned int func_0204B1CC(struct Bank *bank);
extern void func_0204A8D4(u32 i);
extern void func_0204ADA4(u32 i);
extern void func_0204AFD8(u32 i);
extern void func_0204A5AC(void);
extern struct WinMgr *func_0202C9B4(u32 a0, u32 a1, u32 heap);
extern void func_0202CA3C(struct WinMgr *mgr, u32 idx, u32 bg, u32 w, u32 h);
extern void func_0202CEBC(struct WinMgr *mgr, u32 idx, void *a);
extern void func_0202CA0C(struct WinMgr *mgr);
extern void func_0207D63C(void *reg, int a, int b, int c, int d);
void func_021BB184(int *p);
void func_021BB328(char *p);
void func_021BB380(char *p);
void func_021BB474(char *p);
void func_021BB484(void);
extern T28 d_021BD688;
extern char d_021BD60C[];
extern char d_021BD5DC[];
extern char d_021BD5E4[];
extern char d_021BD5D4[];
extern const struct Ent d_021BD5EC[];


void func_021BB184(int *p)
{
    T28 t;
    void *h;
    u32 i;

    t = d_021BD688;
    func_0204A48C((const struct Cfg *)(&t), (u32)d_021BD60C, 0xb);
    h = func_020490F4(0x1f, 0x800b);
    if (func_02008550((const struct Sub0200852CObj *)p[1]) == 0) {
        p[13] = func_0204A6C8(h, 5, 0, 0, 0xb);
        p[16] = func_0204ABF0(h, 4, 0, 0, 0xb);
        p[19] = func_0204AF28(h, 0, 1, 0xb);
    } else {
        p[13] = func_0204A6C8(h, 7, 0, 0, 0xb);
        p[16] = func_0204ABF0(h, 6, 0, 0, 0xb);
        p[19] = func_0204AF28(h, 2, 3, 0xb);
    }
    func_02049238(h);
    h = func_020490F4(0x23, 0x800b);
    p[14] = func_0204A6C8(h, 8, 1, 0, 0xb);
    p[17] = func_0204ABF0(h, 9, 0, 0x20, 0xb);
    p[20] = func_0204AF28(h, 0xa, 0xb, 0xb);
    p[15] = func_0204A6C8(h, 0xc, 1, 0, 0xb);
    p[18] = func_0204ABF0(h, 0xd, 0, 0x40, 0xb);
    p[21] = func_0204AF28(h, 0xe, 0xf, 0xb);
    func_02049238(h);
    p[6] = (int)func_0204B100(6, 0, 0xb);
    p[7] = (int)func_0204B294((void *)p[6], p[13], p[16], p[19], d_021BD5DC, 0, 0xb);
    func_0204B3DC((void *)p[7], 0);
    for (i = 1; i <= 4; i++) {
        p[7 + i] = (int)func_0204B294((void *)p[6], p[14], p[17], p[20], d_021BD5E4, 0, 0xb);
        func_0204B92C((struct Obj *)p[7 + i], 1);
        func_0204B3DC((void *)p[7 + i], 0);
    }
    p[12] = (int)func_0204B294((void *)p[6], p[15], p[18], p[21], d_021BD5D4, 0, 0xb);
    func_020434DC(0x10, 1);
    func_02043598(0x10, 1);
}


void func_021BB328(char *p)
{
    unsigned i;
    for (i = 0; i < 6; i++)
        func_0204B3B4(*(void **)(p + 0x1c + i * 4));
    func_0204B1CC(((struct Obj20817 *)p)->f18);
    for (i = 0; i < 3; i++)
        func_0204A8D4((u32)(*(void **)(p + 0x34 + i * 4)));
    for (i = 0; i < 3; i++)
        func_0204ADA4((u32)(*(void **)(p + 0x40 + i * 4)));
    for (i = 0; i < 3; i++)
        func_0204AFD8((u32)(*(void **)(p + 0x4c + i * 4)));
    func_0204A5AC();
}


/*
 * Builds an 8-window bgwinfrm manager at +0x118, initialises each window
 * from a 4-byte table (height from its halfword at +2), then binds the
 * thirteen resources at +0x80..+0xe0 (stride 8) to windows 0,0,0,0,0,0,1..7.
 */
void func_021BB380(char *p)
{
    u32 i;

    ((struct Obj00014 *)p)->f118 = func_0202C9B4(0, 8, 0xb);
    for (i = 0; i < 8; i++)
        func_0202CA3C(((struct Obj00014 *)p)->f118, i, 1, 0x1a, d_021BD5EC[i].f2);
    func_0202CEBC(((struct Obj00014 *)p)->f118, 0, ((struct Obj00014 *)p)->f80);
    func_0202CEBC(((struct Obj00014 *)p)->f118, 0, ((struct Obj00014 *)p)->f88);
    func_0202CEBC(((struct Obj00014 *)p)->f118, 0, ((struct Obj00014 *)p)->f90);
    func_0202CEBC(((struct Obj00014 *)p)->f118, 0, ((struct Obj00014 *)p)->f98);
    func_0202CEBC(((struct Obj00014 *)p)->f118, 0, ((struct Obj00014 *)p)->fA0);
    func_0202CEBC(((struct Obj00014 *)p)->f118, 0, ((struct Obj00014 *)p)->fA8);
    func_0202CEBC(((struct Obj00014 *)p)->f118, 1, ((struct Obj00014 *)p)->fB0);
    func_0202CEBC(((struct Obj00014 *)p)->f118, 2, ((struct Obj00014 *)p)->fB8);
    func_0202CEBC(((struct Obj00014 *)p)->f118, 3, ((struct Obj00014 *)p)->fC0);
    func_0202CEBC(((struct Obj00014 *)p)->f118, 4, ((struct Obj00014 *)p)->fC8);
    func_0202CEBC(((struct Obj00014 *)p)->f118, 5, ((struct Obj00014 *)p)->fD0);
    func_0202CEBC(((struct Obj00014 *)p)->f118, 6, ((struct Obj00014 *)p)->fD8);
    func_0202CEBC(((struct Obj00014 *)p)->f118, 7, ((struct Obj00014 *)p)->fE0);
}


/*
 * Tail-calls the release of the handle kept at +0x118.
 */
void func_021BB474(char *p)
{
    func_0202CA0C(((struct Obj20818 *)p)->f118);
}


void func_021BB484(void)
{
    func_0207D63C((void *)0x04000050, 4, 8, 16, 3);
    func_0207D63C((void *)0x04001050, 2, 4, 16, 3);
}
