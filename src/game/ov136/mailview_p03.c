/*
 * file:     mailview_p03.c
 * unit:     yes
 * function: func_021C5268, func_021C52F8, func_021C5360, func_021C5420, func_021C5470, func_021C5480, func_021C54C8, func_021C54DC, func_021C54FC, func_021C5508
 * address:  0x021C5268
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045808 0x02045808 arm
 *   func_020456F8 0x020456F8 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   func_020452E8 0x020452E8 arm
 *   func_020450C8 0x020450C8 arm
 *   func_02024450 0x02024450 thumb
 *   func_0202DC48 0x0202DC48 thumb
 *   func_02045770 0x02045770 arm
 *   func_0201C724 0x0201C724 thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_0204A48C 0x0204A48C arm
 *   func_0204B100 0x0204B100 arm
 *   func_0204B270 0x0204B270 arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   func_0203D34C 0x0203D34C arm
 *   d_020A1448 0x020A1448 data a4
 *   d_021C77C4 0x021C77C4 data a4
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A5AC 0x0204A5AC arm
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082AC0 0x02082AC0 arm
 *   func_02008FEC 0x02008FEC thumb
 *   func_02031324 0x02031324 arm
 *   func_021C68A0 0x021C68A0 thumb
 *   func_0203133C 0x0203133C arm
 *   func_020315D4 0x020315D4 arm
 *   func_0203084C 0x0203084C arm
 *   func_020306F0 0x020306F0 arm
 *   func_020419E4 0x020419E4 arm
 *   func_0204A648 0x0204A648 arm
 *   func_020433E0 0x020433E0 arm
 *   d_021C78E0 0x021C78E0 data a1
 */
#include "../../matched/include/Obj00160.h"
#include "../../matched/include/Obj01751.h"
#include "../../matched/include/Obj14187.h"
#include "../../matched/include/Obj23499.h"
#include "../../matched/include/Obj06526.h"
#include "../../matched/include/Obj23500.h"
#include "../../matched/include/Obj06527.h"

struct MsgBank;
struct Descriptor;
struct PrintSys;
struct U16Vec;
struct Cfg;
struct Bank;
struct Obj0203159C;
struct Sub02008F80Obj;
struct S020314B8;
struct S020315D4;
struct DispVram;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 func_02027FEC(u32 a0, u32 a1, u32 a2, u32 a3, u8 a4, u16 a5);
extern void func_02028148(u8 *p);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_020456F8(struct Descriptor *d);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_020450C8(void);
extern int func_02024450(const u16 *p);
extern void func_0202DC48(u32 a, u32 b, u32 c, u32 d);
extern void *func_02045770(struct Descriptor *p);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern void func_0204A48C(const struct Cfg *cfg, unsigned int arg, unsigned int heapId);
extern struct Bank *func_0204B100(int count, u8 flag, unsigned int heapId);
extern void func_0204B270(struct Bank *bank);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);
extern void func_0203D34C(u32 a, u32 b);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void func_0203064C(unsigned int,unsigned int,unsigned int);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082AC0(int,void *,int);
extern struct Sub02008F80Obj *func_02008FEC(void *sys);
extern void *func_02031324(int);
extern int func_021C68A0(u8 *p, int *st);
extern void func_0203133C(struct S020314B8 *p);
extern void func_020315D4(struct S020315D4 *p);
extern void *func_0203084C(u32 heapId);
extern void func_020306F0(u32 v);
extern void func_020419E4(void);
extern void func_0204A648(void);
extern void func_020433E0(const struct DispVram *c);
void func_021C5268(u8 *p);
void func_021C52F8(u8 *p);
void func_021C5360(u8 *p);
void func_021C5420(u8 *p);
void func_021C5470(u8 *p);
int func_021C5480(void *a, int unused, void **arg);
int func_021C54C8(void *a, void *b, void *c, void *p);
int func_021C54DC(void *a, void *b, void *c, u32 *p);
void func_021C54FC(void);
void func_021C5508(void);
extern u8 d_020A1448[],d_021C77C4[];
extern const char d_021C78E0[];

void func_021C5268(u8 *p)
{
    if (p[0xB] == 1) {
        ((struct Obj00160 *)p)->f130 = (u32)func_02045EC0(((struct Obj00160 *)p)->f20, 0);
        ((struct Obj00160 *)p)->f134 = 0x39E3;
        ((struct Obj00160 *)p)->f138 = 0;
        ((struct Obj00160 *)p)->f13C = (u32)func_02045EC0(((struct Obj00160 *)p)->f20, 1);
        ((struct Obj00160 *)p)->f140 = 0x39E3;
        ((struct Obj00160 *)p)->f144 = 1;
        ((struct Obj00160 *)p)->f128 = func_02027FEC(*(u32 *)&((struct Obj00160 *)p)->f108, (u32)(p + 0x130), 21, 18, 10, (u16)((struct Obj00160 *)p)->f0);
        ((struct Obj00160 *)p)->f12C = func_02027FEC(*(u32 *)&((struct Obj00160 *)p)->f108, (u32)(p + 0x13C), 21, 21, 10, (u16)((struct Obj00160 *)p)->f0);
    }
}

/*
 * lever: base + i * 4 + 0x44 keeps the base-plus-index inside the loop;
 * base + 0x44 + i * 4 hoists the field address and changes the loads.
 */
void func_021C52F8(u8 *p)
{
    int i;
    void *q;
    if (p[0xB] == 1) {
        func_02028148(((struct Obj01751 *)p)->f128);
        func_02028148(((struct Obj01751 *)p)->f12C);
        func_02045808(((struct Obj01751 *)p)->f130);
        func_02045808(((struct Obj01751 *)p)->f13C);
    }
    func_0201C4C0(((struct Obj01751 *)p)->f98);
    ((struct Obj01751 *)p)->f98 = 0;
    for (i = 0; i < 7; i++) {
        q = *(void **)(p + i * 4 + 0x44);
        func_020456F8(q);
        func_020409B4(func_02045730(q));
        func_020452E8(*(void **)(p + i * 4 + 0x44));
    }
    func_020450C8();
}


/*
 * note: 2026-10-02 byte-exact; waiting on arm9 witness shard for func_02024450
 */
void func_021C5360(u8 *p)
{
    int i;
    u8 *q;
    u32 t;
    for (i = 0; i < 3; i++) {
        if (func_02024450((u16 *)(*(u8 * *)&((struct Obj00160 *)p)->f1C + 0x16 + i * 8))) {
            func_0202DC48(*(u32 *)&((struct Obj00160 *)p)->f148, *(u32 *)(p + i * 4 + 0x48), (u32)(*(u8 * *)&((struct Obj00160 *)p)->f1C + 0x16 + i * 8), (u8)i);
        }
    }
    q = *(u8 * *)&((struct Obj00160 *)p)->f1C;
    if (((struct Obj14187 *)q)->f32 != 0xFFFF) {
        ((struct Obj00160 *)p)->f14C = 6;
        ((struct Obj00160 *)p)->f14E = 0;
        ((struct Obj00160 *)p)->f150 = ((struct Obj14187 *)q)->f32;
        func_0202DC48(*(u32 *)&((struct Obj00160 *)p)->f148, ((struct Obj00160 *)p)->f54, (u32)(p + 0x14C), (u8)3);
    }
    if (p[0xB] == 0) {
        u32 a = *(u32 *)&((struct Obj00160 *)p)->f98;
        func_0201C724((void *)a, (u32)func_02045770((struct Descriptor *)((struct Obj00160 *)p)->f88), 0, 2, (u32)(((struct Obj23499 *)(*(u8 * *)&((struct Obj00160 *)p)->f1C))->fC), *(u32 *)&((struct Obj00160 *)p)->f24, 0x440);
        p[0x8C] = 1;
        t = ((struct Obj00160 *)p)->f58;
        func_02045334((struct Descriptor *)t);
        func_02045374((struct Cfg *)t);
        func_020409B4(func_02045730((struct Descriptor *)t));
    }
}

void func_021C5420(u8 *p)
{
    func_0204A48C((const struct Cfg *)d_020A1448,(unsigned int)d_021C77C4,(u16)(((struct Obj06526 *)p)->f0));
    ((struct Obj06526 *)p)->fA0 = func_0204B100(4,(int)0,(u16)(((struct Obj06526 *)p)->f0));
    func_0204B270(((struct Obj06526 *)p)->fA0);
    func_020434DC(16,1);
    func_02043598(16,1);
    func_0203D34C((int)0,(u16)(((struct Obj06526 *)p)->f0));
}

void func_021C5470(u8 *p)
{
    func_0204B1CC(((struct Obj23500 *)p)->fA0);
    func_0204A5AC();
}

int func_021C5480(void *a, int unused, void **arg)
{
    u8 *p;
    func_0203064C(1,101,65536);
    p = func_0203159C(a,52,101);
    func_02082AC0(0,p,52);
    ((struct Obj06527 *)p)->f4 = arg;
    ((struct Obj06527 *)p)->f0 = func_02008FEC(*arg);
    ((struct Obj06527 *)p)->f28 = 8;
    ((struct Obj06527 *)p)->f2C = 0;
    ((struct Obj06527 *)p)->f30 = func_02031324(101);
    return 1;
}

int func_021C54C8(void *a, void *b, void *c, void *p)
{
    if (func_021C68A0(p, b) == 0) return 1;
    return 0;
}

int func_021C54DC(void *a, void *b, void *c, u32 *p)
{
    func_0203133C((struct S020314B8 *)p[12]);
    func_020315D4(a);
    func_0203084C(0x65);
    func_020306F0(0x65);
    return 1;
}

void func_021C54FC(void)
{
    func_020419E4();
    func_0204A648();
}

void func_021C5508(void)
{
    func_020433E0((const struct DispVram *)d_021C78E0);
}
