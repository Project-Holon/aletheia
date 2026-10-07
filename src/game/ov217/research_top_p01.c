/*
 * file:     research_top_p01.c
 * unit:     yes
 * function: func_021B95A0, func_021B9600, func_021B9620, func_021B96A0, func_021B96C8, func_021B970C, func_021B9774, func_021B97B8, func_021B97BC, func_021B97F8, func_021B9824, func_021B9850, func_021B9854, func_021B985C, func_021B9874, func_021B9884, func_021B9894, func_021B98A8, func_021B98B8, func_021B990C, func_021B9920, func_021B99EC, func_021B9A24, func_021B9AD0, func_021B9AF8, func_021B9B08, func_021B9B80, func_021B9B90, func_021B9B98
 * address:  0x021B95A0
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02012204 0x02012204 thumb
 *   func_021C09FC 0x021C09FC thumb ov217
 *   func_0201058C  0x0201058C  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_020121CC  0x020121CC  thumb
 *   func_0201283C  0x0201283C  thumb
 *   func_021C09BC  0x021C09BC  thumb  ov217
 *   func_021BABB4 0x021BABB4 thumb ov217
 *   func_021BD61C 0x021BD61C thumb ov217
 *   func_021BAB80 0x021BAB80 thumb ov217
 *   func_021BD5F4 0x021BD5F4 thumb ov217
 *   func_021BABC4  0x021BABC4  thumb  ov217
 *   func_021BAC90  0x021BAC90  thumb  ov217
 *   func_021BAC98  0x021BAC98  thumb  ov217
 *   func_021BD62C  0x021BD62C  thumb  ov217
 *   func_021BD708  0x021BD708  thumb  ov217
 *   func_021BD710  0x021BD710  thumb  ov217
 *   func_021C097C  0x021C097C  thumb  ov217
 *   func_021C099C  0x021C099C  thumb  ov217
 *   func_021C0DC4  0x021C0DC4  thumb  ov217
 *   func_021C0DE4  0x021C0DE4  thumb  ov217
 *   func_021C0DDC  0x021C0DDC  thumb  ov217
 *   func_0203F8F4  0x0203F8F4  arm
 *   func_0203FC28  0x0203FC28  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_02040588  0x02040588  arm
 *   d_021C2E30     0x021C2E30  data  ov217  a4
 *   d_021C2E60     0x021C2E60  data  a4
 *   d_021C2E40     0x021C2E40  data  ov217  a4
 *   d_021C2E80     0x021C2E80  data  ov217  a4
 *   func_020490F4 0x020490F4 arm
 *   func_02049250 0x02049250 arm
 *   func_02062A98 0x02062A98 arm
 *   func_02040E78 0x02040E78 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02062A4C 0x02062A4C arm
 *   func_02040B1C 0x02040B1C arm
 *   func_02062B30 0x02062B30 arm
 *   func_02041090 0x02041090 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02049238 0x02049238 arm
 *   _u32_div_f  0x0209C2B0  arm
 *   sub_020490F4 0x020490F4 arm
 *   sub_020307B0 0x020307B0 arm
 *   sub_020409B4 0x020409B4 arm
 *   func_021C09AC  0x021C09AC  thumb  ov217
 *   func_021BA4E0  0x021BA4E0  thumb  ov217
 *   func_021BA504  0x021BA504  thumb  ov217
 *   func_021BA4D0  0x021BA4D0  thumb  ov217
 *   func_021BA4CC  0x021BA4CC  thumb  ov217
 *   func_021BA4FC  0x021BA4FC  thumb  ov217
 *   func_021BA68C  0x021BA68C  thumb  ov217
 *   func_021B9C54 0x021B9C54 thumb ov217
 *   func_021B9E44 0x021B9E44 thumb ov217
 *   func_021BA078 0x021BA078 thumb ov217
 *   func_021BA094 0x021BA094 thumb ov217
 *   func_021BA0C4 0x021BA0C4 thumb ov217
 *   func_021BA1D4 0x021BA1D4 thumb ov217
 *   func_021BA41C 0x021BA41C thumb ov217
 *   func_021C09D0 0x021C09D0 thumb ov217
 *   func_0204A600 0x0204A600 arm
 *   func_021BA374 0x021BA374 thumb ov217
 *   func_021BA158 0x021BA158 thumb ov217
 *   func_021BA67C 0x021BA67C thumb ov217
 *   func_021BA5BC 0x021BA5BC thumb ov217
 *   func_021BA5F8 0x021BA5F8 thumb ov217
 *   func_021BA63C 0x021BA63C thumb ov217
 *   func_021BA560 0x021BA560 thumb ov217
 *   func_021BA698 0x021BA698 thumb ov217
 *   func_021BA768 0x021BA768 thumb ov217
 *   func_021BA7B8 0x021BA7B8 thumb ov217
 *   func_021BA7E0 0x021BA7E0 thumb ov217
 *   func_021BA830 0x021BA830 thumb ov217
 *   func_021BA86C 0x021BA86C thumb ov217
 *   func_021BA910 0x021BA910 thumb ov217
 *   func_021BA978 0x021BA978 thumb ov217
 *   func_021BA9FC 0x021BA9FC thumb ov217
 *   func_021BAA48 0x021BAA48 thumb ov217
 *   func_021BAAD8 0x021BAAD8 thumb ov217
 *   func_021BAB0C 0x021BAB0C thumb ov217
 *   func_021BAB70 0x021BAB70 thumb ov217
 *   func_021BAB58 0x021BAB58 thumb ov217
 *   func_021BA3B4 0x021BA3B4 thumb ov217
 *   func_021BA2FC 0x021BA2FC thumb ov217
 *   func_021BA19C 0x021BA19C thumb ov217
 *   func_021BA144 0x021BA144 thumb ov217
 *   func_021BA284 0x021BA284 thumb ov217
 *   func_021BA3E8 0x021BA3E8 thumb ov217
 *   func_021BA354 0x021BA354 thumb ov217
 *   func_021BA150 0x021BA150 thumb ov217
 */
#include "../../matched/include/Obj01438.h"
#include "../../matched/include/Obj10952.h"
#include "../../matched/include/Obj25801.h"
#include "../../matched/include/Obj10953.h"
#include "../../matched/include/Obj02554.h"
#include "../../matched/include/Obj25803.h"
#include "../../matched/include/Obj08431.h"
#include "../../matched/include/Obj14724.h"
#include "../../matched/include/Obj25805.h"
#include "../../matched/include/Obj00511.h"
#include "../../matched/include/Obj25806.h"
#include "../../matched/include/Obj25807.h"
#include "../../matched/include/Obj01785.h"

struct DispVram;
struct Obj0203159C;
struct S020315D4;
struct Ctx;
struct BigObj;
struct IcaAnime;
struct BgTemplate;
struct DispConfig;
struct ArcFile;
struct NitroFileHeader;
struct Context;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed char    s8;

typedef signed short   s16;

typedef signed int     s32;

extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_020433E0(const struct DispVram *c);
extern void func_0204363C(u32 swap);
extern void func_020315D4(struct S020315D4 *);
extern u32 func_02012204(const struct Ctx *);
extern void func_021C09FC(void *);
extern u32 func_0201058C(void *key);
extern void *func_020120F4(const struct Ctx *p);
extern u32 func_020121CC(struct IcaAnime *p);
extern u32 func_0201283C(const struct BigObj *p);
extern void func_0203D34C(u32 a, u32 b);
extern void func_021C09BC(void *p, u32 v);
extern u32 func_021BABB4(void *a0);
extern u32 func_021BD61C(void *a0);
extern u32 func_021BAB80(u32, u32);
extern void *func_021BD5F4(void *p);
extern void func_021BABC4(void *self);
extern u32 func_021BAC90(void *p);
extern u32 func_021BAC98(void *p);
extern void func_021BD62C(unsigned char *p);
extern u32 func_021BD708(void *p);
extern u32 func_021BD710(void *p);
extern int func_021C097C(int a0, int a1);
extern u32 func_021C099C(void *a0);
extern u32 func_021C0DC4(u32 a0);
extern void func_021C0DE4(void *p);
extern void func_021C0DDC(void *a0);
extern void func_0203F8F4(unsigned short heapId);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02040588(unsigned char which, unsigned char enable);
extern u32 func_0203F9B4();
extern void func_020403F4(u32 i);
extern void *func_020490F4(unsigned int id, u32 heap);
extern void *func_02049250(struct ArcFile *, u32, u32);
extern int func_02062A98(struct NitroFileHeader *, void **);
extern void func_02040E78(u32, void *, u32, u32);
extern u32 func_020307B0(void *p);
extern int func_02062A4C(struct NitroFileHeader *, void **);
extern void func_02040B1C(int index, const void *src, u32 size, u32 tile);
extern int func_02062B30(void *, void **);
extern void func_02041090(u32, u32, u32, u32, u8, u8);
extern void func_020409B4(u32);
extern void func_02049238(struct ArcFile *);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void *sub_020490F4(u32 id, u32 heap);
extern u32 sub_020307B0(void *p);
extern void sub_020409B4(u32);
extern u32 func_021C09AC(void *);
extern u32 func_021BA4E0(u32);
extern void func_021BA504(char *p);
extern void func_021BA4D0(void *p, u32 v);
extern void func_021BA4CC(void *p, u32 v);
extern u32 func_021BA4FC(void *a0);
extern void func_021BA68C(void *p);
extern void func_021B9C54(char *p);
extern void func_021B9E44(char *p);
extern void func_021BA078(unsigned);
extern void func_021BA094(unsigned);
extern unsigned func_021BA0C4(unsigned);
extern void func_021BA1D4(unsigned);
extern void func_021BA41C(int *);
extern void func_021C09D0(unsigned);
extern void func_0204A600(void);
extern void func_021BA374(void *);
extern void func_021BA158(unsigned);
extern void func_021BA67C(unsigned);
extern void func_021BA5BC(unsigned);
extern void func_021BA5F8(char *self);
extern void func_021BA63C(u8 *self);
extern void func_021BA560(char *);
extern void func_021BA698(char *);
extern void func_021BA768(char *);
extern unsigned func_021BA7B8(void *);
extern void func_021BA7E0(char *);
extern unsigned func_021BA830(void *);
extern void func_021BA86C(char *);
extern void func_021BA910(struct Context *);
extern void func_021BA978(struct Context *);
extern void func_021BA9FC(char *self);
extern void func_021BAA48(char *);
extern void func_021BAAD8(char *);
extern void func_021BAB0C(char *self);
extern void func_021BAB70(unsigned);
extern void func_021BAB58(void *);
extern unsigned func_021BA3B4(unsigned,unsigned);
extern unsigned func_021BA2FC(unsigned);
extern unsigned func_021BA19C(unsigned char *);
extern void func_021BA144(unsigned char *,unsigned);
extern void func_021BA284(int sel);
extern void func_021BA3E8(char *self, int i);
extern void func_021BA354(void);
extern void func_021BA150(void *);
u32 func_021B95A0(u32 a0, u32 a1, u8 *a2, u32 a3);
u32 func_021B9600(u32 a0, u32 a1, u32 a2, u32 a3);
int func_021B9620(void *unused, u32 *state, u32 unused2, u32 *p);
void func_021B96A0(u32 a0);
void func_021B96C8(void *a, int *p, int c);
void func_021B970C(u32 *p, u32 *state);
void func_021B9774(u32 *p, u32 *state, u32 kind);
int func_021B97B8(void *a0);
u32 func_021B97BC(u8 *a0);
u32 func_021B97F8(u32 a0);
u32 func_021B9824(u32 a0);
u32 func_021B9850(const void *p);
void func_021B9854(void *p);
void func_021B985C(void *p, u32 value);
void func_021B9874(u32 a0);
u32 func_021B9884(u32 a0);
void func_021B9894(u32 a0);
u32 func_021B98A8(u32 a0);
void func_021B98B8(unsigned short heapId);
u32 func_021B990C(void);
void func_021B9920(u32 heap);
void func_021B99EC(const void *p);
void func_021B9A24(u32 heap);
u32 func_021B9AD0(void *self);
u32 func_021B9AF8(void *a0);
void func_021B9B08(char *p);
int func_021B9B80(void *p);
u32 func_021B9B90(void *p);
void func_021B9B98(char *p);
extern int d_021C2E30;
extern int d_021C2E60;
extern int d_021C2E40;
extern int d_021C2E80;

u32 func_021B95A0(u32 a0, u32 a1, u8 *a2, u32 a3)
{
    switch (((struct Obj10952 *)((u8*)a1))->f0) {
    case 0:
    func_0203159C((struct Obj0203159C *)a0, 32, 1);
    ((struct Obj10952 *)((u8*)a1))->f0 = (u32)(((struct Obj10952 *)((u8*)a1))->f0 + 1);
    break;
    case 1:
    func_021B985C((void *)a3, ((struct Obj25801 *)((u8*)a2))->f0);
    func_020433E0((const struct DispVram *)0x21C2EA0);
    func_0204363C(0);
    func_021B98B8(((struct Obj01438 *)((u8*)a3))->f0);
    func_021B9A24(((struct Obj01438 *)((u8*)a3))->f0);
    func_021B9920(((struct Obj01438 *)((u8*)a3))->f0);
    func_021B9874(a3);
    func_021B9894(a3);
    return 1;
    }
    return 0;
}

u32 func_021B9600(u32 a0, u32 a1, u32 a2, u32 a3)
{
    func_021B98A8(a3);
    func_021B9884(a3);
    func_021B990C();
    func_020315D4((struct S020315D4 *)a0);
    return 1;
}

/*
 * tail: zero halfword alignment at 021B969E.
 * state domain: procsys 020315F0 resets subseq to 0 before this main callback;
 *   97B8 returns 1, 97BC returns 1..4, 97F8 returns 1/2/4, 9824 returns 1/3/4.
 *   96C8/9774 stores only those new states; state 4 exits immediately.
 *   Full lifecycle/body proof: scratchpad/overlay-goal-20260930-w32/S23/state-proof.md.
 */
int func_021B9620(void *unused, u32 *state, u32 unused2, u32 *p)
{
    u32 next;
    func_021B96A0((u32)p);
    if (func_02012204((const struct Ctx *)p[1]) != 0)
        func_021C09FC((void *)p[3]);
    switch (*state) {
    case 0: next = func_021B97B8(p); break;
    case 1: next = func_021B97BC((u8 *)p); break;
    case 2: next = func_021B97F8((u32)p); break;
    case 3: next = func_021B9824((u32)p); break;
    case 4: return 1;
    }
    func_021B99EC(p);
    func_021B9854(p);
    if (*state != next)
        func_021B96C8(p, (int *)state, next);
    return 0;
}

/*
 * Flushes the +4 handle through three sub-calls, then raises event 1 with
 * the record's leading halfword when the fourth sub-call reports busy.
 *
 * Addresses are Black-image addresses.
 */
void func_021B96A0(u32 a0)
{
    func_0201058C((void *)func_0201283C(func_020120F4(((struct Obj10953 *)(((u8*)a0)))->f4)));
    if (func_020121CC((struct IcaAnime *)(*(u32 *)&((struct Obj10953 *)(((u8*)a0)))->f4)) != 0) {
    func_0203D34C(1, ((struct Obj10953 *)((u8*)a0))->f0);
    }
}


void func_021B96C8(void *a, int *p, int c)
{
    func_021B970C(a, (u32 *)p);
    func_021B9774(a, (u32 *)p, c);
    switch (*p) {
    case 1:
        func_021C09BC((void *)(*(int *)((char *)a + 0xc)), 1);
        break;
    case 2:
        func_021C09BC((void *)(*(int *)((char *)a + 0xc)), 2);
        break;
    case 3:
        func_021C09BC((void *)(*(int *)((char *)a + 0xc)), 3);
        break;
    }
}

/*
 * tail: zero halfword alignment at 021B9772.
 */
void func_021B970C(u32 *p, u32 *state)
{
    switch (*state) {
    case 0: case 4: break;
    case 1: func_021B9AF8((void *)p[4]); break;
    case 2: func_021BABB4((void *)p[5]); break;
    case 3: func_021BD61C((void *)p[6]); break;
    }
    switch (*state) {
    case 0: case 4: break;
    case 1: p[4] = 0; break;
    case 2: p[5] = 0; break;
    case 3: p[6] = 0; break;
    }
}

void func_021B9774(u32 *p, u32 *state, u32 kind)
{
    switch (kind) {
    case 0:
    case 4:
        break;
    case 1:
        p[4] = func_021B9AD0((void *)p[3]);
        break;
    case 2:
        p[5] = func_021BAB80(p[3], p[7]);
        break;
    case 3:
        p[6] = (u32)func_021BD5F4((void *)p[3]);
        break;
    }
    *state = kind;
}

int func_021B97B8(void *a0)
{
    return 1;
}

u32 func_021B97BC(u8 *a0)
{
    func_021B9B08((char *)(((struct Obj02554 *)a0)->f10));
    if (func_021B9B80((void *)(((struct Obj02554 *)a0)->f10)) != 0) {
    switch (func_021B9B90((void *)(((struct Obj02554 *)a0)->f10))) {
    case 0:
    return 2;
    case 1:
    return 3;
    case 2:
    return 4;
    }
    return 4;
    }
    return 1;
}

u32 func_021B97F8(u32 a0)
{
    func_021BABC4((void *)(((struct Obj02554 *)(((u8*)a0)))->f14));
    if (func_021BAC90((void *)(((struct Obj02554 *)(((u8*)a0)))->f14)) != 0) {
    if (func_021BAC98((void *)(((struct Obj02554 *)(((u8*)a0)))->f14)) == 0) {
    return 1;
    }
    return 4;
    }
    return 2;
}

u32 func_021B9824(u32 a0)
{
    func_021BD62C((unsigned char *)(((struct Obj02554 *)(((u8*)a0)))->f18));
    if (func_021BD708((void *)(((struct Obj02554 *)(((u8*)a0)))->f18)) != 0) {
    if (func_021BD710((void *)(((struct Obj02554 *)(((u8*)a0)))->f18)) == 0) {
    return 1;
    }
    return 4;
    }
    return 3;
}


u32 func_021B9850(const void *p)
{
    return *(const u32 *)&((struct Obj25803 *)p)->f8;
}


void func_021B9854(void *p)
{
    u32 *counter = (u32 *)((char *)p + 8);
    *counter += 1;
}


void func_021B985C(void *p, u32 value)
{
    ((struct Obj01438 *)p)->f0 = 1;
    ((struct Obj01438 *)p)->f4 = value;
    ((struct Obj01438 *)p)->f8 = 0;
    ((struct Obj01438 *)p)->fC = 0;
    ((struct Obj01438 *)p)->f10 = 0;
    ((struct Obj01438 *)p)->f14 = 0;
    ((struct Obj01438 *)p)->f18 = 0;
    ((struct Obj01438 *)p)->f1C = 0;
}

void func_021B9874(u32 a0)
{
    ((struct Obj01438 *)(((u8*)a0 + 0)))->fC = func_021C097C(((struct Obj01438 *)((u8*)a0))->f0, ((struct Obj01438 *)(((u8*)a0 + 0)))->f4);
}

/*
 * Reconstructed from the listing (.inst decoded).
 *
 * Addresses are Black-image addresses.
 */
u32 func_021B9884(u32 a0)
{
    func_021C099C((void *)(((struct Obj08431 *)(((u8*)a0)))->fC));
    ((struct Obj08431 *)(((u8*)a0)))->fC = 0;
    return 0;
}

/*
 * Reconstructed from the listing.
 *
 * Addresses are Black-image addresses.
 */
void func_021B9894(u32 a0)
{
    u32 r = func_021C0DC4(((struct Obj01438 *)((u8*)a0))->f0);
    ((struct Obj01438 *)(((u8*)a0 + 0)))->f1C = r;
    func_021C0DE4((void *)r);
}

u32 func_021B98A8(u32 a0)
{
    func_021C0DDC((void *)(((struct Obj08431 *)(((u8*)a0)))->f1C));
    ((struct Obj08431 *)(((u8*)a0)))->f1C = 0;
    return 0;
}


/*
 * Hint note: d_021C2E60 data line carries no overlay token (contested hint).
 */
void func_021B98B8(unsigned short heapId)
{
    func_0203F8F4(heapId);
    func_0203FC28((struct DispConfig *)(&d_021C2E30));
    func_0203FCA0(4, (const struct BgTemplate *)(&d_021C2E60), 0);
    func_0203FCA0(5, (const struct BgTemplate *)(&d_021C2E40), 0);
    func_02040588(4, 1);
    func_02040588(5, 1);
    func_0203FCA0(1, (const struct BgTemplate *)(&d_021C2E80), 0);
    func_02040588(1, 1);
}

u32 func_021B990C(void)
{
    func_020403F4(1);
    func_020403F4(4);
    return func_0203F9B4();
}

void func_021B9920(u32 heap)
{
    void *palette;
    void *character;
    void *screen;
    void *screen2;
    struct ArcFile *arc;
    void *buffer;
    arc = func_020490F4(192, heap);
    buffer = func_02049250(arc, 9, heap);
    func_02062A98(buffer, &palette);
    func_02040E78(4, *(void **)((char *)palette + 12), 512, 0);
    func_020307B0(buffer);
    buffer = func_02049250(arc, 10, heap);
    func_02062A4C(buffer, &character);
    func_02040B1C(4, *(void **)((char *)character + 0x14), *(u32 *)((char *)character + 0x10), 0);
    func_020307B0(buffer);
    buffer = func_02049250(arc, 11, heap);
    func_02062B30(buffer, &screen);
    func_02041090(4, (u32)((char *)screen + 12), 0, 0, 32, 24);
    func_020409B4(4);
    func_020307B0(buffer);
    buffer = func_02049250(arc, 12, heap);
    func_02062B30(buffer, &screen2);
    func_02041090(5, (u32)((char *)screen2 + 12), 0, 0, 32, 24);
    func_020409B4(5);
    func_020307B0(buffer);
    func_02049238(arc);
}


void func_021B99EC(const void *p)
{
    u32 t = func_021B9850(p) / 10;
    u32 m = (u8)(t % 6);
    func_020413B0(5, 0, 0, 0x20, 0x18, (u8)m);
    func_020409B4(5);
}

void func_021B9A24(u32 heap)
{
    void *palette;
    void *character;
    void *screen;
    struct ArcFile *arc;
    void *buffer;
    arc = sub_020490F4(192, (u16)((heap & 0x7fff) | 0x8000));
    buffer = func_02049250(arc, 0, heap);
    func_02062A98(buffer, &palette);
    func_02040E78(1, ((struct Obj25805 *)palette)->fC, 512, 0);
    sub_020307B0(buffer);
    buffer = func_02049250(arc, 1, heap);
    func_02062A4C(buffer, &character);
    func_02040B1C(1, ((struct Obj14724 *)character)->f14, ((struct Obj14724 *)character)->f10, 0);
    sub_020307B0(buffer);
    buffer = func_02049250(arc, 2, heap);
    func_02062B30(buffer, &screen);
    func_02041090(1, (u32)((char *)screen + 12), 0, 0, 32, 24);
    sub_020409B4(1);
    sub_020307B0(buffer);
    func_02049238(arc);
}


u32 func_021B9AD0(void *self)
{
    u32 v = func_021C09AC(self);
    u32 o = func_021BA4E0(v);
    func_021BA504((char *)o);
    func_021BA4D0((void *)o, v);
    func_021BA4CC((void *)o, (u32)self);
    return o;
}

u32 func_021B9AF8(void *a0)
{
    func_021BA68C((void *)a0);
    return func_021BA4FC(a0);
}

void func_021B9B08(char *p)
{
    switch (((struct Obj00511 *)p)->f18) {
    case 0:func_021B9B98(p);break;
    case 1:func_021B9C54(p);break;
    case 2:func_021B9E44(p);break;
    case 3:func_021BA078((unsigned)p);break;
    case 4:func_021BA094((unsigned)p);break;
    case 5:func_021BA0C4((unsigned)p);break;
    case 6:return;
    }
    if (func_021B9B80(p)==0) {
        func_021BA1D4((unsigned)p);func_021BA41C((int *)p);
        func_021C09D0(*(unsigned *)&((struct Obj00511 *)p)->f0);func_0204A600();
    }
    func_021BA374(p);func_021BA158((unsigned)p);
}


int func_021B9B80(void *p)
{
    if (((struct Obj25806 *)p)->f88 != 0) {
        return 1;
    }
    return 0;
}


/*
 * Field getter, u32 at +0x8c.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021B9B90(void *p)
{
    return ((struct Obj25807 *)p)->f8C;
}

void func_021B9B98(char *p)
{
    unsigned kind;
    func_021BA67C((unsigned)p);func_021BA5BC((unsigned)p);
    func_021BA5F8(p);func_021BA63C((u8 *)p);func_021BA560(p);
    func_021BA698(p);func_021BA768(p);func_021BA7B8(p);
    func_021BA7E0(p);func_021BA830(p);func_021BA86C(p);
    func_021BA910((struct Context *)p);func_021BA978((struct Context *)p);
    func_021BA9FC(p);func_021BAA48(p);func_021BAAD8(p);
    func_021BAB0C(p);func_021BAB70((unsigned)p);func_021BAB58(p);
    if (func_021BA3B4((unsigned)p,0)==0)func_021BA2FC((unsigned)p);
    kind=func_021BA19C((unsigned char *)p);
    func_021BA144((unsigned char *)p,func_021BA19C((unsigned char *)p));
    if (kind==2) {func_021BA284(((struct Obj01785 *)p)->f28);func_021BA3E8((char *)((unsigned)p),0);}
    func_021BA354();func_021BA150(p);
}
