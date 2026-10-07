/*
 * file:     pokemontrade_demo_common_p01.c
 * unit:     yes
 * function: func_021D4240, func_021D4290, func_021D434C, func_021D43C8, func_021D4434
 * address:  0x021D4240
 * region:   ov118
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
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 */
#include "../../matched/include/Obj22647.h"
#include "../../matched/include/Obj00001.h"
#include "../../matched/include/Obj22648.h"
#include "../../matched/include/Obj22649.h"
#include "../../matched/include/Obj22650.h"
#include "../../matched/include/Obj22651.h"
#include "../../matched/include/Obj22652.h"
#include "../../matched/include/Obj01723.h"
#include "../../matched/include/Obj22653.h"
#include "../../matched/include/Obj22654.h"
#include "../../matched/include/Obj22655.h"

struct Personal;
struct Sub0200852CObj;
struct Obj;
struct Actor;
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

extern void func_0207D658(u32 addr, int plane, int brightness);
extern int func_021D8AA8(void *p);
extern void *func_021D8FA4(void *p, int which);
extern u32 func_02017E1C(void *mon, u32 id, u32 arg);
extern void *func_0201ADE4(unsigned int a, int b, unsigned int heap);
extern u32 func_0201AE1C(const struct Personal *p, u32 field);
extern void func_0201AE14(void *p);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern void func_0204B92C(struct Obj *, u32);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_0204B9A0(struct Actor *a);
extern void *func_020490F4(u32 id, u32 heap);
extern s32_021D43C8 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32_021D43C8 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32_021D43C8 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204A8D4(u32 i);
extern void func_0204ADA4(u32 i);
extern void func_0204AFD8(u32 i);
void func_021D4240(s8 *fade);
void func_021D4290(u8 *p, u8 *outSame, u8 *outFlag, u32 key, int enemy);
void func_021D434C(void *p);
void func_021D43C8(void *p);
void func_021D4434(void *p);


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
        h = (u32)func_0201ADE4((u16)a, (u16)b, ((struct Obj22647 *)p)->f5F4);
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
    u32 v = ((struct Obj22648 *)((char *)((struct Obj00001 *)p)->fC))->fB0;
    if (v == 0) {
        Local s;
        s.a = 0x80;
        s.b = 0x63;
        s.c = 0;
        s.d = 0;
        s.e = 0;
        ((struct Obj22649 *)((char *)((struct Obj00001 *)p)->fC))->fB0 =
            (u32)func_0204B294((void *)*(u32 *)&((struct Obj00001 *)p)->f9C4,
                          ((struct Obj00001 *)p)->f8A8,
                          ((struct Obj00001 *)p)->f88C,
                          ((struct Obj00001 *)p)->f8BC,
                          &s, 0, ((struct Obj00001 *)p)->f5F4);
        func_0204B92C((struct Obj *)((struct Obj22650 *)((char *)((struct Obj00001 *)p)->fC))->fB0, 1);
        func_0204B3DC((struct Obj *)((struct Obj22651 *)((char *)((struct Obj00001 *)p)->fC))->fB0, 1);
    } else {
        func_0204B9A0((struct Actor *)v);
    }
}


void func_021D43C8(void *p)
{
    void *h = func_020490F4(0x67, ((struct Obj00001 *)p)->f5F4);
    ((struct Obj00001 *)p)->f8A8 = func_0204A6C8(h, 2, 0, 0, ((struct Obj00001 *)p)->f5F4);
    ((struct Obj00001 *)p)->f88C = func_0204AC18(h, 3, 0, 0xE0, 0, 1, ((struct Obj00001 *)p)->f5F4);
    ((struct Obj00001 *)p)->f8BC = func_0204AF28(h, 1, 0, ((struct Obj00001 *)p)->f5F4);
    func_02049238(h);
    ((struct Obj22652 *)((char *)((struct Obj00001 *)p)->fC))->fB0 = 0;
}


void func_021D4434(void *p)
{
    u8 *b = p;

    if (((struct Obj22653 *)((u8 *)((struct Obj01723 *)b)->fC))->fB0 != 0)
        func_0204B3B4(((struct Obj22654 *)((u8 *)((struct Obj01723 *)b)->fC))->fB0);
    if (((struct Obj01723 *)b)->f8A8 != 0) {
        func_0204A8D4((u32)(((struct Obj01723 *)b)->f8A8));
        func_0204ADA4((u32)(((struct Obj01723 *)b)->f88C));
        func_0204AFD8((u32)(((struct Obj01723 *)b)->f8BC));
    }
    ((struct Obj01723 *)b)->f8A8 = 0;
    ((struct Obj01723 *)b)->f88C = 0;
    ((struct Obj01723 *)b)->f8BC = 0;
    ((struct Obj22655 *)((u8 *)((struct Obj01723 *)b)->fC))->fB0 = 0;
}
