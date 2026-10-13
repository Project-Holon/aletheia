/*
 * file:     pokemontrade_demo_common.c
 * unit:     yes
 * function: func_021D4240, func_021D4290, func_021D434C, func_021D43C8, func_021D4434, func_021D4480, func_021D4484, func_021D4490, func_021D449C, func_021D4520, func_021D4544
 * address:  0x021D4240
 * region:   ov117
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0207D658  0x0207D658  arm
 *   _s32_div_f     0x0209C0A4  arm
 *   func_021D8AA8  0x021D8AA8  thumb  ov119
 *   func_021D8FA4  0x021D8FA4  thumb  ov119
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0201ADE4  0x0201ADE4  thumb
 *   func_0201AE1C  0x0201AE1C  thumb
 *   func_0201AE14  0x0201AE14  thumb
 *   func_02008530  0x02008530  thumb
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm
 *   CLACT_ReleasePalette  0x0204ADA4  arm
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm
 *   func_021E3BB0  0x021E3BB0  thumb  ov119
 *   func_021E3230  0x021E3230  thumb  ov119
 *   func_021D8A24  0x021D8A24  thumb  ov119
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   func_02039C68  0x02039C68  arm
 *   func_021D8E84  0x021D8E84  thumb  ov119
 *   func_02039CB4  0x02039CB4  arm
 *   func_02030734  0x02030734  arm
 *   func_021DFD24  0x021DFD24  thumb  ov119
 *   func_021DFB84  0x021DFB84  thumb  ov119
 *   func_02015F2C  0x02015F2C  thumb
 *   func_021DFD0C  0x021DFD0C  thumb  ov119
 *   MCSS_SetPaletteFade  0x02015F50  thumb
 *   func_021E106C  0x021E106C  thumb  ov119
 *   func_02040EBC  0x02040EBC  arm
 *   func_021D4664  0x021D4664  thumb  ov117
 *   d_021D55B0     0x021D55B0  data
 *   d_021D51F4     0x021D51F4  data
 *   d_021D51E8     0x021D51E8  data
 *   ARC_TOOL_DeleteHandle  0x02049238  arm  arm9
 *   CLACT_RegisterCharacter  0x0204A6C8  arm  arm9
 *   CLACT_RegisterPaletteEx  0x0204AC18  arm  arm9
 *   CLACT_RegisterCellAnim  0x0204AF28  arm  arm9
 *   CLACT_CreateActor  0x0204B294  arm  arm9
 *   CLACT_RestartActorAnim  0x0204B9A0  arm  arm9
 */
#include "../../matched/include/Obj22634.h"
#include "../../matched/include/Obj03253.h"
#include "../../matched/include/Obj22635.h"
#include "../../matched/include/Obj22636.h"
#include "../../matched/include/Obj22637.h"
#include "../../matched/include/Obj22638.h"
#include "../../matched/include/Obj03768.h"
#include "../../matched/include/Obj22639.h"
#include "../../matched/include/Obj01722.h"
#include "../../matched/include/Obj22640.h"
#include "../../matched/include/Obj22641.h"
#include "../../matched/include/Obj22642.h"
#include "../../matched/include/Obj22643.h"
#include "../../matched/include/Obj22644.h"
#include "../../matched/include/Obj00001.h"

#define OBJ(i) (((u32 *)(p + 0x844))[i])
#define HEAP (*(u16 *)(p + 0x5F4))
#define SLOT0 (*(u32 *)(p + 0x85C))
#define SLOT1 (*(u32 *)(p + 0x860))
#define FADE (*(s8 **)(p + 0x818))
struct Personal;
struct Sub0200852CObj;
struct Obj;
struct Actor;
struct Entry;
struct Link;
struct McssFade;
typedef signed char s8;

typedef int s32_021D4240;

typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

typedef struct {
    u16 a;
    u16 b;
    u16 c;
    u8 d;
    u8 e;
} Local;

typedef signed int     s32_021D43C8;

typedef short s16;

typedef int s32;

typedef struct {
    s32 x, y, z;
} Vec;

extern void func_0207D658(u32 addr, int plane, int brightness);
extern int func_021D8AA8(void *p);
extern void *func_021D8FA4(void *p, int which);
extern u32 func_02017E1C(void *mon, u32 id, u32 arg);
extern void *func_0201ADE4(u32 a, int b, u32 heap);
extern u32 func_0201AE1C(const struct Personal *p, u32 field);
extern void func_0201AE14(void *p);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern struct Obj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void CLACT_RestartActorAnim(struct Actor *a);
extern void *func_020490F4(u32 id, u32 heap);
extern s32_021D43C8 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32_021D43C8 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32_021D43C8 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void ARC_TOOL_DeleteHandle(void *);
extern void CLACT_DeleteActor(struct Obj *p);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
extern void func_021E3BB0(char *p);
extern void func_021E3230(void *p);
extern int func_021D8A24(void *p);
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern void func_02039C68(struct Link *h, u32 a, u32 b);
extern void func_021D8E84(void *p, int next);
extern u32 func_02039CB4(struct Link *h, u32 a, u32 b);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_021DFD24(u32 *p);
extern void *func_021DFB84(void *a0, void *a1, void *a2, u32 heapId);
extern void func_02015F2C(u32 obj, void *arg, void (*cb)(void), int a);
extern void func_021DFD0C(char *p);
extern void MCSS_SetPaletteFade(struct McssFade *w, u32 cur, u32 target, s32 step, u32 e);
extern void func_021E106C(char *p);
extern void func_02040EBC(u32 a0, u32 a1);
extern void func_021D4664(u8 *p);
void func_021D4240(s8 *fade);
void func_021D4290(u8 *p, u8 *outSame, u8 *outFlag, u32 key, int enemy);
void func_021D434C(void *p);
void func_021D43C8(void *p);
void func_021D4434(void *p);
int func_021D4480(int a);
void func_021D4484(u8 *p, u32 v);
void func_021D4490(u8 *p);
void func_021D449C(u8 *p);
void func_021D4520(u8 *p);
void func_021D4544(u8 *p);
extern const char d_021D55B0[];
extern const Vec d_021D51F4;
extern const Vec d_021D51E8;




void func_021D4240(s8 *fade)
{
    s32_021D4240 value;

    if (fade == 0) {
        return;
    }
    if (fade[0] >= fade[1]) {
        fade[1]++;
        value = ((fade[3] - fade[2]) << 12) / fade[0];
        value = value * fade[1] / 4096;
        func_0207D658(0x04000050, 0x1E, value);
        func_0207D658(0x04001050, 0x1F, value);
    }
}




void func_021D4290(u8 *p, u8 *outSame, u8 *outFlag, u32 key, int enemy)
{
    int which;
    void *mon;
    u32 id;
    u32 a;
    u32 b;
    u32 egg;
    u32 h;
    u32 flag;

    if (enemy != 0) {
        if (func_021D8AA8(p) != 0) {
            which = 1;
        } else {
            which = 0;
        }
    } else {
        if (func_021D8AA8(p) != 0) {
            which = 0;
        } else {
            which = 1;
        }
    }
    mon = func_021D8FA4(p, which);
    id = func_02017E1C(mon, 7, 0);
    a = func_02017E1C(mon, 0xAB, 0);
    b = func_02017E1C(mon, 0x6F, 0);
    egg = func_02017E1C(mon, 0x4C, 0);
    if (egg == 0) {
        h = (u32)func_0201ADE4((u16)a, (int)(u16)b, ((struct Obj22634 *)p)->f5F4);
        flag = func_0201AE1C((const struct Personal *)h, 0x10);
        func_0201AE14((void *)h);
    }
    if (egg != 0) {
        *outFlag = 1;
    } else if (flag != 0) {
        *outFlag = 1;
    } else {
        *outFlag = 0;
    }
    if (id != func_02008530((const struct Sub0200852CObj *)key)) {
        *outSame = 0;
    } else {
        *outSame = 1;
    }
}




void func_021D434C(void *p)
{
    u32 v = ((struct Obj22635 *)((char *)((struct Obj03253 *)p)->fC))->fB0;
    if (v == 0) {
        Local s;
        s.a = 0x80;
        s.b = 0x63;
        s.c = 0;
        s.d = 0;
        s.e = 0;
        ((struct Obj22636 *)((char *)((struct Obj03253 *)p)->fC))->fB0 =
            (u32)CLACT_CreateActor((void *)((struct Obj03253 *)p)->f9C4,
                          ((struct Obj03253 *)p)->f8A8,
                          ((struct Obj03253 *)p)->f88C,
                          ((struct Obj03253 *)p)->f8BC,
                          &s, 0, ((struct Obj03253 *)p)->f5F4);
        func_0204B92C((struct Obj *)((struct Obj22637 *)((char *)((struct Obj03253 *)p)->fC))->fB0, 1);
        func_0204B3DC((struct Obj *)((struct Obj22638 *)((char *)((struct Obj03253 *)p)->fC))->fB0, 1);
    } else {
        CLACT_RestartActorAnim((struct Actor *)v);
    }
}




void func_021D43C8(void *p)
{
    void *h = func_020490F4(0x67, ((struct Obj03768 *)p)->f5F4);
    ((struct Obj03768 *)p)->f8A8 = CLACT_RegisterCharacter(h, 2, 0, 0, ((struct Obj03768 *)p)->f5F4);
    ((struct Obj03768 *)p)->f88C = CLACT_RegisterPaletteEx(h, 3, 0, 0xE0, 0, 1, ((struct Obj03768 *)p)->f5F4);
    ((struct Obj03768 *)p)->f8BC = CLACT_RegisterCellAnim(h, 1, 0, ((struct Obj03768 *)p)->f5F4);
    ARC_TOOL_DeleteHandle(h);
    ((struct Obj22639 *)((char *)((struct Obj03768 *)p)->fC))->fB0 = 0;
}




void func_021D4434(void *p)
{
    u8 *b = p;

    if (((struct Obj22640 *)((u8 *)((struct Obj01722 *)b)->fC))->fB0 != 0)
        CLACT_DeleteActor(((struct Obj22641 *)((u8 *)((struct Obj01722 *)b)->fC))->fB0);
    if (((struct Obj01722 *)b)->f8A8 != 0) {
        CLACT_ReleaseCharacter((u32)(((struct Obj01722 *)b)->f8A8));
        CLACT_ReleasePalette((u32)(((struct Obj01722 *)b)->f88C));
        CLACT_ReleaseCellAnim((u32)(((struct Obj01722 *)b)->f8BC));
    }
    ((struct Obj01722 *)b)->f8A8 = 0;
    ((struct Obj01722 *)b)->f88C = 0;
    ((struct Obj01722 *)b)->f8BC = 0;
    ((struct Obj22642 *)((u8 *)((struct Obj01722 *)b)->fC))->fB0 = 0;
}




int func_021D4480(int a) { return a; }




void func_021D4484(u8 *p, u32 v) { ((struct Obj22643 *)p)->fF2C = v; }




void func_021D4490(u8 *p) { ((struct Obj22644 *)p)->f1094 = 1; }



void func_021D449C(u8 *p)
{
    func_021E3BB0((char *)p);
    if (((struct Obj00001 *)p)->f854 == 1) {
        func_021D4290(p, p + 0x11ED, p + 0x11EF, ((struct Obj00001 *)p)->f834, 1);
        func_021D4290(p, p + 0x11EE, p + 0x11F0, ((struct Obj00001 *)p)->f830, 0);
        func_021E3230(p);
        if (func_021D8A24(p) != 0) {
            func_02039C68((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x11, 8);
            func_021D8E84(p, (int)func_021D4520);
        } else {
            func_021D8E84(p, (int)func_021D4544);
        }
    }
}



void func_021D4520(u8 *p)
{
    if (func_02039CB4((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x11, 8) != 0) {
        func_021D8E84(p, (int)func_021D4544);
    }
}



void func_021D4544(u8 *p)
{
    Vec a;
    Vec b;

    func_021D4484(p, 0);
    FADE = func_02030734(HEAP, 4, 1, d_021D55B0, 0xF5);
    FADE[0] = func_021D4480(0xE);
    FADE[1] = 0;
    FADE[2] = 0;
    FADE[3] = -0x10;
    a = d_021D51F4;
    func_021DFD24((u32 *)SLOT0);
    SLOT0 = (u32)func_021DFB84((void *)OBJ(0), (void *)func_021D4480(0x2A), &a, HEAP);
    b = d_021D51E8;
    func_021DFD24((u32 *)SLOT1);
    SLOT1 = (u32)func_021DFB84((void *)OBJ(1), (void *)func_021D4480(0x54), &b, HEAP);
    func_02015F2C(OBJ(0), p, (void (*)(void))func_021DFD0C, 1);
    MCSS_SetPaletteFade((struct McssFade *)OBJ(1), 0, 0x10, (s8)(func_021D4480(0xE) / 16), 0);
    func_021E106C((char *)p);
    func_02040EBC(1, 0);
    func_02040EBC(5, 0);
    func_021D4484(p, 0);
    func_021D8E84(p, (int)func_021D4664);
}
