/*
 * file:     unit_021C5518.c
 * unit:     yes
 * function: func_021C5518, func_021C5714, func_021C574C, func_021C5828, func_021C587C, func_021C5918, func_021C5924, func_021C5954, func_021C5974, func_021C59B8, func_021C5AA8, func_021C5AEC
 * address:  0x021C5518
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
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414EC 0x020414EC arm
 *   func_02040B94 0x02040B94 arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   g_7910 0x021C7910 data
 *   g_79E0 0x021C79E0 data
 *   g_79A0 0x021C79A0 data
 *   g_79C0 0x021C79C0 data
 *   g_7980 0x021C7980 data
 *   g_7960 0x021C7960 data
 *   g_7940 0x021C7940 data
 *   g_7A00 0x021C7A00 data
 *   g_7920 0x021C7920 data
 *   func_020403F4 0x020403F4 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049DF4 0x02049DF4 arm
 *   func_02082B0C 0x02082B0C arm
 *   func_020307B0 0x020307B0 arm
 *   func_02049238 0x02049238 arm
 *   func_0201F5BC 0x0201F5BC thumb
 *   func_02049B40 0x02049B40 arm
 *   func_0202C9B4 0x0202C9B4 thumb
 *   func_0202CA3C 0x0202CA3C thumb
 *   func_0202CAE4 0x0202CAE4 thumb
 *   func_0202CF84 0x0202CF84 thumb
 *   func_02082D44 0x02082D44 arm
 *   func_0202CB4C 0x0202CB4C thumb
 *   func_0202CA0C 0x0202CA0C thumb
 *   func_02045B38 0x02045B38 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   func_020457B0 0x020457B0 arm
 *   func_02045808 0x02045808 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_02045C04 0x02045C04 arm
 *   func_02027778 0x02027778 thumb
 *   func_02027F60 0x02027F60 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   g_78C0 0x021C78C0 data
 *   g_78B0 0x021C78B0 data
 *   func_02027FD8 0x02027FD8 thumb
 *   func_02027858 0x02027858 thumb
 */
#include "../../matched/include/Obj14188.h"
#include "../../matched/include/Obj23503.h"
#include "../../matched/include/Obj04533.h"
#include "../../matched/include/Obj23511.h"
#include "../../matched/include/Obj10600.h"
#include "../../matched/include/Obj10601.h"
#include "../../matched/include/Obj08199.h"
#include "../../matched/include/Obj23513.h"
#include "../../matched/include/Obj23514.h"
#include "../../matched/include/Obj02494.h"
#include "../../matched/include/Obj23515.h"
#include "../../matched/include/Obj23516.h"
#include "../../matched/include/Obj23517.h"
#include "../../matched/include/Obj23518.h"
#include "../../matched/include/Obj08201.h"
#include "../../matched/include/Obj23519.h"
#include "../../matched/include/Obj23520.h"
#include "../../matched/include/Obj23521.h"
#include "../../matched/include/Obj10602.h"
#include "../../matched/include/Obj23522.h"
#include "../../matched/include/Obj23523.h"
#include "../../matched/include/Obj23524.h"
#include "../../matched/include/Obj23525.h"

struct WinMgr;
struct MsgBank;
struct U16Vec;
struct WordSet;
struct Rec;
struct TaskMenu;
struct TaskMenuTmpl;
struct R;
struct TaskMenuState;
typedef unsigned short u16;

typedef unsigned int u32;

struct DispConfig { u32 w[4]; };

struct BgTemplate { u32 w[8]; };

typedef unsigned char  u8;

typedef signed char s8;

typedef struct { u32 heap; u8 count; u8 pad[3]; void *items; u32 zero; u8 x,y,w,h; } Template;

struct Pair { u32 a; u32 b; };

extern void func_0203F8F4(u16);
extern void func_0203FC28(struct DispConfig *);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414EC(u32);
extern void func_02040B94(u8 layer, u32 size, u32 offset, u32 heapId);
extern void func_020434DC(u32, u32);
extern void func_02043598(u32, u32);
extern void func_020403F4(u32 bgId);
extern void func_0203F9B4(void);
extern void *func_020490F4(u32 id, u32 heap);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void *func_02049DF4(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void func_02082B0C(void *, const void *, u32);
extern u32 func_020307B0(void *p);
extern void func_02049238(void *);
extern void func_0201F5BC(u32 a, u32 b, u32 c, u32 d, u16 e);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern struct WinMgr *func_0202C9B4(u32 a0, u32 a1, u32 heap);
extern void func_0202CA3C(struct WinMgr *mgr, u32 idx, u32 bg, u32 w, u32 h);
extern void func_0202CAE4(struct WinMgr *mgr, u32 idx, u32 arc, u32 member, u32 alloc);
extern u32 func_0202CF84(struct WinMgr *mgr, u32 idx);
extern void func_02082D44(void *,void *,u32);
extern void func_0202CB4C(struct WinMgr *mgr, u32 idx, s8 x, s8 y);
extern void func_0202CA0C(struct WinMgr *mgr);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_0201ED04(struct WordSet *p);
extern u32 func_02045C04(struct Rec *rec);
extern struct TaskMenu *func_02027778(struct TaskMenuTmpl *tmpl, void *arg1);
extern struct R *func_02027F60(u16, u16, u32, u32, u16);
extern void *func_02045EC0(struct MsgBank *, u32);
extern u32 func_02027FD8(struct TaskMenuState *s);
extern void func_02027858(struct TaskMenu *m);
void func_021C5518(u8 *a0);
void func_021C5714(void *a0);
void func_021C574C(u8 *p);
void func_021C5828(void *a0);
void func_021C587C(u8 *p);
void func_021C5918(u8 *p);
void func_021C5924(u8 *p);
void func_021C5954(u8 *p);
void func_021C5974(u8 *p);
void func_021C59B8(u8 *p);
void func_021C5AA8(u8 *p);
void func_021C5AEC(u8 *p);
void func_021C5B30(u8 *p);
extern const struct DispConfig g_7910;
extern const struct BgTemplate g_79E0;
extern const struct BgTemplate g_79A0;
extern const struct BgTemplate g_79C0;
extern const struct BgTemplate g_7980;
extern const struct BgTemplate g_7960;
extern const struct BgTemplate g_7940;
extern const struct BgTemplate g_7A00;
extern const struct BgTemplate g_7920;
extern const struct Pair g_78C0[];
extern const struct Pair g_78B0[];


void func_021C5518(u8 *a0)
{
    func_0203F8F4(0x66);
    {
        struct DispConfig d = g_7910;
        func_0203FC28(&d);
    }
    {
        struct BgTemplate t = g_79E0;
        func_0203FCA0(4, &t, 0);
        func_020414EC(4);
        func_02040B94(4, 0x20, 0, 0x66);
    }
    {
        struct BgTemplate t = g_79A0;
        func_0203FCA0(5, &t, 0);
        func_020414EC(5);
        func_02040B94(5, 0x20, 0, 0x66);
    }
    {
        struct BgTemplate t = g_79C0;
        func_0203FCA0(6, &t, 0);
        func_020414EC(6);
        func_02040B94(6, 0x20, 0, 0x66);
    }
    {
        struct BgTemplate t = g_7980;
        func_0203FCA0(7, &t, 0);
    }
    {
        struct BgTemplate t = g_7960;
        func_0203FCA0(0, &t, 0);
        func_020414EC(0);
        func_02040B94(0, 0x20, 0, 0x66);
    }
    {
        struct BgTemplate t = g_7940;
        func_0203FCA0(1, &t, 0);
        func_020414EC(1);
        func_02040B94(1, 0x20, 0, 0x66);
    }
    {
        struct BgTemplate t = g_7A00;
        func_0203FCA0(2, &t, 0);
        func_020414EC(2);
    }
    {
        struct BgTemplate t = g_7920;
        func_0203FCA0(3, &t, 0);
    }
    func_020434DC(1, 1);
    func_020434DC(2, 1);
    func_020434DC(4, 1);
    func_020434DC(8, 1);
    func_020434DC(0x10, 1);
    func_02043598(1, 1);
    func_02043598(2, 1);
    func_02043598(4, 1);
    func_02043598(8, 1);
    func_02043598(0x10, 1);
}


void func_021C5714(void *a0)
{
    func_020403F4(3);
    func_020403F4(2);
    func_020403F4(1);
    func_020403F4(0);
    func_020403F4(7);
    func_020403F4(6);
    func_020403F4(5);
    func_020403F4(4);
    func_0203F9B4();
}


void func_021C574C(u8 *p)
{
    void *h;
    void *buf;
    u8 *out;
    u8 *dst;
    h = func_020490F4(0x9B, 0x66);
    func_02049658(h, 0x2A, 7, 0, 0, 1, 0x66);
    func_020498F4(h, 0x29, 7, 0, 0, 1, 0x66);
    func_02049B68(h, 0x2B, 4, 0, 0, 0x66);
    func_02049658(h, 0x26, 3, 0, 0, 1, 0x66);
    func_02049658(h, 0x26, 1, 0, 0, 1, 0x66);
    func_020498F4(h, 0x25, 3, 0, 0, 1, 0x66);
    func_02049B68(h, 0x27, 0, 0, 0, 0x66);
    buf = func_02049DF4(h, 0x26, 1, (u32)(&out), 0x66);
    dst = *(u8 * *)&((struct Obj23503 *)out)->f14;
    func_02082B0C(dst + 0x100, *(u8 * *)&((struct Obj14188 *)p)->f8 + 4, 0x20);
    func_02082B0C(dst + 0x100, *(u8 * *)&((struct Obj14188 *)p)->f8 + 0x24, 0x20);
    func_020307B0(buf);
    func_02049238(h);
}

void func_021C5828(void *a0)
{
    func_0201F5BC(0,994,13,0,102);
    func_02049B40(23,5,0,448,32,102);
    func_02049B40(23,5,4,480,32,102);
    func_02049B40(23,5,0,480,32,102);
}

void func_021C587C(u8 *p)
{
    u32 i;
    void *first;
    **(void ** *)&((struct Obj04533 *)p)->f8 = func_0202C9B4(2,11,102);
    for(i=0;i<10;i++) func_0202CA3C(**(void ** *)&((struct Obj04533 *)p)->f8,i,2,14,4);
    func_0202CA3C(**(void ** *)&((struct Obj04533 *)p)->f8,10,1,14,4);
    func_0202CAE4(**(void ** *)&((struct Obj04533 *)p)->f8,0,155,40,1);
    first = (void *)func_0202CF84(**(void ** *)&((struct Obj04533 *)p)->f8,0);
    for(i=1;i<=10;i++) func_02082D44(first,(void *)func_0202CF84(**(void ** *)&((struct Obj04533 *)p)->f8,i),112);
    for(i=0;i<10;i++) func_0202CB4C(**(void ** *)&((struct Obj04533 *)p)->f8,i,(i%2)*16+1,(i/2)*4);
}

void func_021C5918(u8 *p)
{
    func_0202CA0C(**(struct WinMgr ** *)&((struct Obj23511 *)p)->f8);
}

void func_021C5924(u8 *p)
{
    ((struct Obj10600 *)p)->f1D0 = func_02045B38(0, 2, 0x3b, 0x66);
    ((struct Obj10600 *)p)->f1D4 = func_0201EC64(0x66);
    ((struct Obj10600 *)p)->f1D8 = func_020457B0(0x400, 0x66);
}

void func_021C5954(u8 *p)
{
    func_02045808(((struct Obj10601 *)p)->f1D8);
    func_0201ED04(((struct Obj10601 *)p)->f1D4);
    func_02045C04(((struct Obj10601 *)p)->f1D0);
}

void func_021C5974(u8 *p)
{
    Template t;
    t.heap = 102;
    t.count = 2;
    t.items = *(u8 * *)&((struct Obj08199 *)p)->f8 + 0x344;
    t.zero = 0;
    t.x = 21;
    t.y = 8;
    t.w = 10;
    t.h = 3;
    ((struct Obj23514 *)(*(u8 * *)&((struct Obj08199 *)p)->f8))->f310 = func_02027778((struct TaskMenuTmpl *)(&t), ((struct Obj23513 *)(*(u8 * *)&((struct Obj08199 *)p)->f8))->f30C);
}


/*
 * lever: use the prepared Pair pointer's t->a as the archive index and t->b after the call;
 *   its live address keeps r7 and frees the far-offset constants into the original stack slots.
 * retry: wave77 R24 recovered in 3 scratch runs; own callee prototypes copied before matching.
 */
void func_021C59B8(u8 *p)
{
    u16 i;
    const struct Pair *t;
    ((struct Obj23516 *)(*(u8 * *)&((struct Obj02494 *)p)->f8))->f30C = func_02027F60(0, 5, ((struct Obj02494 *)p)->f18, ((struct Obj23515 *)(*(u8 * *)&((struct Obj02494 *)p)->f8))->f1C4, 0x66);
    for (i = 0; i < 4; i++) {
        t = &g_78C0[i];
        *(u32 *)(*(u8 * *)&((struct Obj02494 *)p)->f8 + i * 12 + 0x314) = (u32)func_02045EC0(((struct Obj23517 *)(*(u8 * *)&((struct Obj02494 *)p)->f8))->f1D0, t->a);
        *(u16 *)(*(u8 * *)&((struct Obj02494 *)p)->f8 + i * 12 + 0x318) = 0x39E3;
        *(u32 *)(*(u8 * *)&((struct Obj02494 *)p)->f8 + i * 12 + 0x31C) = t->b;
    }
    for (i = 0; i < 2; i++) {
        t = &g_78B0[i];
        *(u32 *)(*(u8 * *)&((struct Obj02494 *)p)->f8 + i * 12 + 0x344) = (u32)func_02045EC0(((struct Obj23518 *)(*(u8 * *)&((struct Obj02494 *)p)->f8))->f1D0, t->a);
        *(u16 *)(*(u8 * *)&((struct Obj02494 *)p)->f8 + i * 12 + 0x348) = 0x39E3;
        *(u32 *)(*(u8 * *)&((struct Obj02494 *)p)->f8 + i * 12 + 0x34C) = t->b;
    }
}

void func_021C5AA8(u8 *p)
{
    int i;
    for (i = 0; i < 4; i++)
        func_02045808(*(void **)(*(u8 * *)&((struct Obj08201 *)p)->f8 + 0x314 + i * 12));
    func_02045808(((struct Obj23519 *)(*(u8 * *)&((struct Obj08201 *)p)->f8))->f344);
    func_02045808(((struct Obj23520 *)(*(u8 * *)&((struct Obj08201 *)p)->f8))->f350);
    func_02027FD8(((struct Obj23521 *)(*(u8 * *)&((struct Obj08201 *)p)->f8))->f30C);
}

void func_021C5AEC(u8 *p)
{
    Template t;
    t.heap = 102;
    t.count = 4;
    t.items = *(u8 * *)&((struct Obj10602 *)p)->f8 + 0x314;
    t.zero = 0;
    t.x = 20;
    t.y = 12;
    t.w = 12;
    t.h = 3;
    ((struct Obj23523 *)(*(u8 * *)&((struct Obj10602 *)p)->f8))->f310 = func_02027778((struct TaskMenuTmpl *)(&t), ((struct Obj23522 *)(*(u8 * *)&((struct Obj10602 *)p)->f8))->f30C);
}

void func_021C5B30(u8 *p)
{
    func_02027858(((struct Obj23525 *)(*(u8 * *)&((struct Obj23524 *)p)->f8))->f310);
}
