/*
 * file:     unit_021B95A0_p01.c
 * unit:     yes
 * function: func_021B95A0, func_021B9768, func_021B980C, func_021B9850, func_021B98E0
 * address:  0x021B95A0
 * region:   ov068
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02034AC4  0x02034AC4  arm
 *   func_0203064C  0x0203064C  arm
 *   func_0203159C  0x0203159C  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_0201D7EC  0x0201D7EC  thumb
 *   func_0201C440  0x0201C440  thumb
 *   func_02027F60  0x02027F60  thumb
 *   func_02045B38  0x02045B38  arm
 *   func_0203101C  0x0203101C  arm
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200873C  0x0200873C  thumb
 *   func_021BAF5C  0x021BAF5C  thumb  ov068
 *   func_021BB0F8  0x021BB0F8  thumb  ov068
 *   func_021BB148  0x021BB148  thumb  ov068
 *   func_021B9950  0x021B9950  thumb  ov068
 *   func_021BA37C  0x021BA37C  thumb  ov068
 *   func_021BA734  0x021BA734  thumb  ov068
 *   func_021BA024  0x021BA024  thumb  ov068
 *   func_021B995C  0x021B995C  thumb  ov068
 *   func_021BA1C4  0x021BA1C4  thumb  ov068
 *   func_021BAD60  0x021BAD60  thumb  ov068
 *   ov067_id       0x00000043  data
 *   func_021BADFC  0x021BADFC  thumb
 *   func_021BA254  0x021BA254  thumb
 *   func_021BA030  0x021BA030  thumb
 *   func_021BA7B4  0x021BA7B4  thumb
 *   func_021BA410  0x021BA410  thumb
 *   func_021BB114  0x021BB114  thumb
 *   func_021BAF9C  0x021BAF9C  thumb
 *   func_02031140  0x02031140  arm
 *   func_02045C04  0x02045C04  arm
 *   func_020315D4  0x020315D4  arm
 *   func_020306F0  0x020306F0  arm
 *   func_02034A5C  0x02034A5C  arm
 *   func_02027FD8  0x02027FD8  thumb
 *   func_0201C4C0  0x0201C4C0  thumb
 *   func_0201D83C  0x0201D83C  thumb
 *   func_021BB120  0x021BB120  thumb
 *   func_021B9930  0x021B9930  thumb
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_020310C4  0x020310C4  arm
 *   func_021BA644  0x021BA644  thumb
 *   func_021BB134  0x021BB134  thumb
 *   func_0204335C  0x0204335C  arm
 *   func_020433E0  0x020433E0  arm
 *   func_0204363C  0x0204363C  arm
 *   func_0204361C  0x0204361C  arm
 *   func_020434CC  0x020434CC  arm
 *   func_02043588  0x02043588  arm
 *   func_0201DD60  0x0201DD60  thumb
 *   func_0201DD78  0x0201DD78  thumb
 *   func_021B9980  0x021B9980  thumb
 *   func_021B9E28  0x021B9E28  thumb
 *   func_021B996C  0x021B996C  thumb
 *   func_020056A0  0x020056A0  thumb
 *   d_021BB598     0x021BB598  data  a4
 *   func_02030EAC  0x02030EAC  arm
 *   func_021B9F70  0x021B9F70  thumb  ov068
 *   func_021B9B6C  0x021B9B6C  thumb  ov068
 *   func_0201DD68  0x0201DD68  thumb
 */
#include "../../matched/include/Obj05149.h"
#include "../../matched/include/Obj13137.h"
#include "../../matched/include/Obj20634.h"
#include "../../matched/include/Obj20635.h"

struct Obj0203159C;
struct Big;
struct Ctx;
struct GfFont;
struct MsgBank;
struct R;
struct Sub02008700Obj;
struct Tcbl;
struct PrintSys;
struct Rec;
struct S02031140;
struct S020315D4;
struct TaskMenuState;
struct DispVram;
struct Node;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {
    u32 x0;
    u32 x4;
} Args;

typedef struct {
    u8 pad0[0xd4];
    u8 xD4[0x10];
    u8 xE4[0x20];
    u8 x104[0x44];
    u8 x148[0x58];
    u8 x1A0[0x38];
    u8 x1D8[0x70];
    u8 x248[0xc];
    u32 font;
    u32 x258;
    u32 msg;
    u32 x260;
    u32 x264;
    u32 x268;
    Args *args;
} Work;

typedef signed int     s32;

extern int func_02034AC4(s32 handle);
extern void  func_0203064C(u32 a, u32 b, u32 c);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void  func_02082BCC(void *p, u32 v, u32 n);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 func_0201C440(void *p);
extern struct R *func_02027F60(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct Tcbl *func_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern void func_021BAF5C(u8 *p, short unsigned int *a);
extern void  func_021BB148(void *unused, u32 *p);
extern void func_021BB0F8(u8 *p, int value, int callback);
extern int func_021B9950(void *p);
extern void  func_021BA37C(u8 *p, u32 a1, u32 a2, u32 a3, u32 s0, u32 s1, u32 s2, u16 s3);
extern void  func_021BA734(u8 *p, u16 a1, u16 a2, Work *a3, u8 *src, u32 heap);
extern void func_021BA024(void *p, int heap);
extern int func_021B995C(int *p, int i);
extern void  func_021BA1C4(u8 *p, u32 a1, u32 a2, u32 a3, u32 s0, u32 s1, u16 s2);
extern void func_021BAD60(u8 *p, u32 a, u32 b, void *c, u32 s0, u32 s1, u32 s2, u16 s3);
extern void func_021BADFC(u8 *p);
extern void func_021BA254(u8 *p);
extern void func_021BA030(void *p);
extern void func_021BA7B4(void *p);
extern void func_021BA410(u8 *p);
extern void func_021BB114(void *p);
extern void func_021BAF9C(void *p);
extern void func_02031140(struct S02031140 *p);
extern u32 func_02045C04(struct Rec *rec);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int heap);
extern void func_02034A5C(int a);
extern u32 func_02027FD8(struct TaskMenuState *s);
extern void func_0201C4C0(struct PrintSys *p);
extern u32 func_0201D83C(void *ptr);
extern void func_021BB120(u8 *p);
extern void func_021B9930(u8 *p);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_020310C4(struct Tcbl *p);
extern void func_021BA644(u8 *p);
extern int func_021BB134(void *p);
extern void func_0204335C(u32 keep);
extern void func_020433E0(const struct DispVram *c);
extern void func_0204363C(u32 v);
extern void func_0204361C(void);
extern void func_020434CC(void);
extern void func_02043588(void);
extern void func_0201DD60(void);
extern void func_0201DD78(u32 r, u32 g, u32 b);
extern void func_021B9980(void *p, u32 a);
extern void func_021B9E28(int *p, void *res, u32 heap);
extern void func_021B996C(void *task, char *p);
extern u32 func_020056A0(void (*fn)(void), void *arg, u32 z);
extern void func_02030EAC(struct Node *n);
extern void func_021B9F70(u32 *p);
extern void func_021B9B6C(u32 *p);
extern void func_0201DD68(void);
int func_021B95A0(void *proc, int *seq, Args *args);
int func_021B9768(void *a, u32 b, u32 c, u8 *w);
int func_021B980C(u32 a, u32 b, u32 c, u8 *w);
void func_021B9850(u8 *p, u32 a);
void func_021B98E0(u8 *p);
extern u8 ov067_id[];
extern int d_021BB598[];


int func_021B95A0(void *proc, int *seq, Args *args)
{
    Work *w;
    u32 t;

    func_02034AC4((u32)ov067_id);
    func_0203064C(1, 0x1c, 0x21000);
    w = func_0203159C(proc, sizeof(Work), 0x1c);
    func_02082BCC(w, 0, sizeof(Work));
    w->args = args;
    w->args->x0 = 0;
    func_021B9850((u8 *)w, 0x1c);
    w->font = (u32)func_0201D7EC(0x17, 0, 0, 0, 0x1c);
    w->x258 = func_0201C440((void *)0x1c);
    w->x260 = (u32)func_02027F60(0, 0xd, w->font, w->x258, 0x1c);
    w->x264 = (u32)func_02027F60(3, 9, w->font, w->x258, 0x1c);
    w->msg = (u32)func_02045B38(0, 2, 0x1d, 0x1c);
    w->x268 = (u32)func_0203101C(0x1c, 0x1c, 0x20, 0x20);
    func_021BAF5C(w->x248, (short unsigned int *)func_0200873C(func_02012EBC(func_020120F4((const struct Ctx *)w->args->x4))));
    func_021BB0F8(w->xD4, (int)w, (int)func_021BB148);
    t = (u32)func_020120F4((const struct Ctx *)w->args->x4);
    func_021BA37C(w->x104, func_021B9950(w), w->font, w->x258, w->msg, w->x260, t, 0x1c);
    func_021BA734(w->x148, 1, 2, w, w->x248, 0x1c);
    func_021BA024(w->xE4, 0x1c);
    func_021BA1C4(w->x1A0, func_021B995C((int *)w, 0x11), w->font, w->msg, w->x268, w->x258, 0x1c);
    func_021BAD60(w->x1D8, func_021B995C((int *)w, 0x12), w->font, (void *)w->msg, w->x268, w->x264, w->x258, 0x1c);
    return 1;
}


int func_021B9768(void *a, u32 b, u32 c, u8 *w)
{
    func_021BADFC(w + 0x1d8);
    func_021BA254(w + 0x1a0);
    func_021BA030(w + 0xe4);
    func_021BA7B4(w + 0x148);
    func_021BA410(w + 0x104);
    func_021BB114(w + 0xd4);
    func_021BAF9C(w + 0x248);
    func_02031140(((struct Obj05149 *)w)->f268);
    func_02045C04(((struct Obj05149 *)w)->f25C);
    func_02027FD8(((struct Obj05149 *)w)->f264);
    func_02027FD8(((struct Obj05149 *)w)->f260);
    func_0201C4C0(((struct Obj05149 *)w)->f258);
    func_0201D83C(((struct Obj05149 *)w)->f254);
    func_021B98E0(w);
    func_020315D4(a);
    func_020306F0(0x1c);
    func_02034A5C((int)ov067_id);
    return 1;
}


int func_021B980C(u32 a, u32 b, u32 c, u8 *w)
{
    func_021BB120(w + 0xd4);
    func_021B9930(w);
    func_0201C4E4(((struct Obj13137 *)w)->f258);
    func_020310C4(((struct Obj13137 *)w)->f268);
    func_021BA644(w + 0x104);
    if (func_021BB134(w + 0xd4) != 0)
        return 1;
    return 0;
}


void func_021B9850(u8 *p, u32 a)
{
    func_02082BCC(p, 0, 0xd4);
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
    *(volatile u32 *)0x04000000 &= 0xFFFF1FFF;
    *(volatile u32 *)0x04001000 &= 0xFFFF1FFF;
    func_0204335C(0);
    func_020433E0((const struct DispVram *)d_021BB598);
    func_0204363C(0);
    func_0204361C();
    func_020434CC();
    func_02043588();
    func_0201DD60();
    func_0201DD78(0xf, 0xe, 0);
    func_021B9980(p, a);
    func_021B9E28((int *)(p + 0x7c), d_021BB598, a);
    ((struct Obj20634 *)p)->fD0 = func_020056A0((void (*)(void))func_021B996C, p, 0);
}


void func_021B98E0(u8 *p)
{
    func_02030EAC((struct Node *)(((struct Obj20635 *)p)->fD0));
    func_021B9F70((u32 *)(p + 0x7c));
    func_021B9B6C((u32 *)p);
    func_0201DD68();
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
    *(volatile u32 *)0x04000000 &= 0xffff1fff;
    *(volatile u32 *)0x04001000 &= 0xffff1fff;
    func_02082BCC(p, 0, 0xd4);
}
