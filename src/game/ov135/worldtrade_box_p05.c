/*
 * file:     worldtrade_box_p05.c
 * unit:     yes
 * function: func_021F4EB4, func_021F4EC0, func_021F4EC8, func_021F4ED4, func_021F4EDC, func_021F4EFC, func_021F4F84, func_021F4F90, func_021F4FA4, func_021F4FC4, func_021F4FF4, func_021F5008, func_021F5034, func_021F5060, func_021F5074, func_021F50EC, func_021F513C, func_021F5154, func_021F51F0
 * address:  0x021F4EB4
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0205CCD8  0x0205CCD8  arm
 *   sub_02012FFC  0x02012FFC  thumb  arm9
 *   func_021F4894  0x021F4894  thumb  ov135
 *   func_021F49F8  0x021F49F8  thumb  ov135
 *   func_021F4BCC  0x021F4BCC  thumb  ov135
 *   g_02202BFC  0x02202BFC  data  ov135
 *   func_021FFCD4  0x021FFCD4  thumb
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_0204A5AC  0x0204A5AC  arm
 *   func_020056BC  0x020056BC  thumb
 *   func_0202F038  0x0202F038  thumb
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 *   func_0204B404  0x0204B404  arm
 *   func_021F49A8  0x021F49A8  thumb
 *   func_021F4864  0x021F4864  thumb
 *   tbl_02202BB8  0x02202BB8  data
 *   func_02030EAC  0x02030EAC  arm
 *   func_020450C8  0x020450C8  arm
 *   func_0203F9B4  0x0203F9B4  arm
 *   func_0200F7C0   0x0200F7C0  thumb
 *   func_021F5980 0x021F5980 thumb ov135
 *   func_021F5250 0x021F5250 thumb ov135
 *   func_021FFFE8 0x021FFFE8 thumb ov135
 *   func_021F5374 0x021F5374 thumb ov135
 *   func_021F57EC 0x021F57EC thumb ov135
 *   func_021F5420 0x021F5420 thumb ov135
 *   func_021FFD44 0x021FFD44 thumb ov135
 *   func_0207D55C 0x0207D55C arm
 *   func_021F68A4 0x021F68A4 thumb ov135
 *   func_021F9254 0x021F9254 thumb ov135
 *   g_02203B0C  0x02203B0C  data  ov135
 */
#include "../../matched/include/Obj00018.h"
#include "../../matched/include/Obj00287.h"
#include "../../matched/include/Obj00996.h"
#include "../../matched/include/Obj12193.h"
#include "../../matched/include/Obj02863.h"
#include "../../matched/include/Obj12194.h"
#include "../../matched/include/Obj05413.h"
#include "../../matched/include/Obj18539.h"
#include "../../matched/include/Obj10575.h"

struct DispVram;
struct Bank;
struct Cfg;
struct Descriptor;
struct Obj;
struct Vec2;
struct Node;
struct Ctx;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int s32;

typedef signed short s16;

typedef signed char s8;

typedef volatile u16 vu16_021F5074;

struct DispConfig {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0c;
};

typedef struct {
    u8 pad0[0xF90];
    void *vblank;
} Work;

typedef volatile unsigned short vu16_021F50EC;

typedef volatile unsigned int vu32;

extern int func_0205CCD8(void);
extern signed char sub_02012FFC(void);
extern void func_021F4894(const struct DispVram *a0);
extern void func_021F49F8(u8 *p, u32 v);
extern void func_021F4BCC(u8 *p);
extern void func_021FFCD4(u8 *p);
extern void func_0204ADA4(u32 v);
extern void func_0204A8D4(u32 v);
extern void func_0204AFD8(u32 v);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern u32 func_020056BC(void);
extern u8 *func_0202EE30(void *owner, void *a1, u8 a2, u8 a3, volatile u16 heap);
extern void func_0202F038(u8 *p);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 v);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_0207D658(u32 addr, int plane, int brightness);
extern void func_020434CC(void);
extern void func_02043588(void);
extern void func_02043534(u32 planes);
extern void func_020435F4(u32 a);
extern void func_0203F8F4(u16 heapId);
extern void func_02045088(u16 heapId);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_021F49A8(void);
extern void *func_020056A0(void *callback, void *ctx, int a2);
extern void func_021F4864(void *unused, Work *p);
extern void func_02030EAC(struct Node *n);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void *func_020120F4(const struct Ctx *p);
extern void func_02012E08(char *p);
extern void func_0200F7C0(u32 c);
extern void func_021F5980(u8 *);
extern void func_021F5250(void);
extern void func_021FFFE8(u8 *, u32, u32);
extern void func_021F5374(u8 *);
extern void func_021F57EC(u8 *);
extern void func_021F5420(u8 *);
extern void func_021FFD44(char *p);
extern int func_0207D55C(volatile u16 *reg);
extern void func_0202208C(void *, u32, u32, u32, u32, u32, u32);
extern void func_021F68A4(u8 *, int);
extern void func_021F9254(u8 *);
int func_021F4EB4(void);
void func_021F4EC0(u8 *p, u32 a, u32 b);
void func_021F4EC8(u8 *p);
int func_021F4ED4(void);
void func_021F4EDC(u8 *p);
void func_021F4EFC(u8 *p);
void func_021F4F84(u8 *p);
void func_021F4F90(u8 *p);
void func_021F4FA4(u8 *p);
void func_021F4FC4(u8 *p);
void func_021F4FF4(u32 a, u32 b, u32 c);
void func_021F5008(u32 x);
void func_021F5034(u32 x);
void func_021F5060(void);
void func_021F5074(Work *p);
void func_021F50EC(u8 *p);
void func_021F513C(u8 *p);
int func_021F5154(u8 *p);
void func_021F51F0(u8 *p);
extern u8 g_02202BFC[];
extern const struct DispConfig tbl_02202BB8;
extern void *g_02203B0C[];


int func_021F4EB4(void)
{
    return 3 - func_0205CCD8();
}

/*
 * Store two words into the object at +0x14 and +0x20.
 */
void func_021F4EC0(u8 *p, u32 a, u32 b)
{
    ((struct Obj00018 *)p)->f14 = a;
    *(u32 *)&((struct Obj00018 *)p)->f20 = b;
}

/*
 * Save the current value at +0x10 into +0x1c and move +0x14 down into +0x10.
 */
void func_021F4EC8(u8 *p)
{
    ((struct Obj00287 *)p)->f1C = ((struct Obj00287 *)p)->f10;
    ((struct Obj00287 *)p)->f10 = ((struct Obj00287 *)p)->f14;
}


int func_021F4ED4(void)
{
    return sub_02012FFC();
}


/*
 * Wire the shared table into the two initialisers and release the channel.
 */
void func_021F4EDC(u8 *p)
{
    func_021F4894((const struct DispVram *)g_02202BFC);
    func_021F49F8(p, (u32)g_02202BFC);
    func_021F4BCC(p);
}


void func_021F4EFC(u8 *p)
{
    func_021FFCD4(p);
    func_0204ADA4(((struct Obj00996 *)p)->fBE0);
    func_0204A8D4(((struct Obj00996 *)p)->fBDC);
    func_0204AFD8(((struct Obj00996 *)p)->fBE4);
    func_0204ADA4(((struct Obj00996 *)p)->fBD4);
    func_0204A8D4(((struct Obj00996 *)p)->fBD0);
    func_0204AFD8(((struct Obj00996 *)p)->fBD8);
    func_0204ADA4(((struct Obj00996 *)p)->fBC8);
    func_0204A8D4(((struct Obj00996 *)p)->fBC4);
    func_0204AFD8(((struct Obj00996 *)p)->fBCC);
    func_0204A8D4(((struct Obj00996 *)p)->fBE8);
    func_0204AFD8(((struct Obj00996 *)p)->fBF0);
    func_0204B1CC((struct Bank *)(((struct Obj00996 *)p)->fBC0));
    ((struct Obj00996 *)p)->fBC0 = 0;
    func_0204A5AC();
}

/*
 * Decrement the u16 counter at +0x36 when it is non-zero.
 */
void func_021F4F84(u8 *p)
{
    u16 v = ((struct Obj12193 *)p)->f36;

    if (v != 0) {
        ((struct Obj12193 *)p)->f36 = v - 1;
    }
}

/*
 * Set the u16 flag at +0xeb2 and clear the one at +0xeb0.
 */
void func_021F4F90(u8 *p)
{
    ((struct Obj02863 *)p)->fEB2 = 1;
    ((struct Obj02863 *)p)->fEB0 = 0;
}


/*
 * blocker resolved: 0x020056BC was matched in arm9 (src/matched/
 * func_020056BC.c, shard pkt_020056BC); the call now attests as `matched`.
 * All 32 bytes are right.
 *
 * Start a frame with the 0x48-byte object held at +0xd40 and keep the result at +0xdf8.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_021F4FA4.c --func func_021F4FA4  *       --addr 0x021F4FA4 --region ov135 --thumb --cc dsi/1.1p1 --diff
 */
void func_021F4FA4(u8 *p)
{
    ((struct Obj12194 *)p)->fDF8 = (u32)func_0202EE30((void *)func_020056BC(), (void *)(((struct Obj12194 *)p)->fD40),
                                        0xf, 0x10, 0x48);
}


void func_021F4FC4(u8 *p)
{
    if (((struct Obj00018 *)p)->fDF8 != 0) {
        func_0202F038((u8 *)(((struct Obj00018 *)p)->fDF8));
        ((struct Obj00018 *)p)->fDF8 = 0;
        func_02045374((struct Cfg *)(((struct Obj00018 *)p)->fD40));
        func_020409B4(func_02045730((struct Descriptor *)(((struct Obj00018 *)p)->fD40)));
    }
}


void func_021F4FF4(u32 a, u32 b, u32 c)
{
    u16 t[2];

    t[0] = b;
    t[1] = c;
    func_0204B404((struct Obj *)a, (const struct Vec2 *)t, 0);
}


/*
 * Pick the 0x04000050 or 0x04001050 hardware register from the flag and write the 0x1e/-7 pair.
 */
void func_021F5008(u32 x)
{
    if (x != 0) {
        func_0207D658(0x04000050, 0x1e, -7);
    } else {
        func_0207D658(0x04001050, 0x1e, -7);
    }
}


/*
 * Pick the 0x04000050 or 0x04001050 hardware register from the flag and write the 0x1b/-7 pair.
 */
void func_021F5034(u32 x)
{
    if (x != 0) {
        func_0207D658(0x04000050, 0x1b, -7);
    } else {
        func_0207D658(0x04001050, 0x1b, -7);
    }
}

/*
 * Clear the two display control registers.
 */
void func_021F5060(void)
{
    *(u16 *)0x04000050 = 0;
    *(u16 *)0x04001050 = 0;
}


void func_021F5074(Work *p)
{
    func_020434CC();
    func_02043588();
    func_02043534(0);
    func_020435F4(0);
    func_021F4EDC((u8 *)p);
    func_0203F8F4(0x48);
    func_02045088(0x48);
    {
        struct DispConfig c = tbl_02202BB8;

        func_0203FC28(&c);
    }
    func_021F49A8();
    *(vu16_021F5074 *)0x04000050 = 0;
    *(vu16_021F5074 *)0x04001050 = 0;
    if (p->vblank == 0) {
        p->vblank = func_020056A0(func_021F4864, p, 0);
    }
}


void func_021F50EC(u8 *p)
{
    if (((struct Obj05413 *)p)->fF90 != 0) {
        func_02030EAC(((struct Obj05413 *)p)->fF90);
        ((struct Obj05413 *)p)->fF90 = 0;
    }
    *(vu16_021F50EC *)0x04000050 = 0;
    *(vu16_021F50EC *)0x04001050 = 0;
    func_021F4EFC(p);
    func_020450C8();
    func_0203F9B4();
    *(vu32 *)0x04000000 &= 0xFFFF1FFF;
    *(vu32 *)0x04001000 &= 0xFFFF1FFF;
}


void func_021F513C(u8 *p)
{
    func_02012E08(func_020120F4((const struct Ctx *)(*(u32 *)(((struct Obj18539 *)p)->f0 + 0x40))));
    func_0200F7C0(0x29);
}

/*
 * volatile: hardware halfword 04000304 read at 021F5162 before masked write.
 */
int func_021F5154(u8 *p)
{
    func_021F5980(p);
    *(volatile u16 *)0x04000304 = (u16)(*(volatile u16 *)0x04000304 & ~0x8000);
    func_021F5250();
    func_021FFFE8(p, 0, 0);
    func_021F5374(p);
    func_021F57EC(p);
    func_021F5420(p);
    func_021FFD44((char *)p);
    if (func_0207D55C((u16 *)0x0400106c) == 0) {
        func_0202208C((void *)3, 1, 1, 0, 6, 1, 0x48);
    } else {
        func_0202208C(0, 1, 1, 0, 6, 1, 0x48);
    }
    func_021F68A4(p, ((struct Obj10575 *)p)->fC4);
    func_021F9254(p);
    ((struct Obj10575 *)p)->f28 = 0;
    ((struct Obj10575 *)p)->f12E4 = 0;
    return 1;
}


/*
 * State-table dispatch through the table at 0x02203B0C.
 */
void func_021F51F0(u8 *p)
{
    ((void (*)(u8 *))g_02203B0C[*(u32 *)(p + 0x28)])(p);
}
