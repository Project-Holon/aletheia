/*
 * file:     ringtone_sys.c
 * unit:     yes
 * function: func_0202918C, func_020291A8, func_020291C4, func_020291E8, func_0202920C, func_02029228, func_02029250, func_02029288, func_020292C0, func_020292E8, func_0202930C, func_02029324, func_02029344, func_02029348, func_02029354, func_02029364, func_02029374, func_0202938C, func_0202939C, func_020293D8, func_02029408, func_02029434, func_0202945C, func_0202947C, func_02029488, func_020294C0, func_020294F4, func_0202952C, func_02029560, func_020295A4, func_020295D8, func_02029620, func_02029658, func_02029690, func_020296C8, func_0202972C, func_02029760, func_020297AC, func_020297EC, func_02029830, func_02029868, func_020298A0, func_020298E0, func_02029938, func_02029984, func_020299B8, func_02029A04, func_02029A3C, func_02029A74, func_02029AA8, func_02029AF4, func_02029B28, func_02029B5C, func_02029BCC, func_02029C00, func_02029C38, func_02029C64, func_02029C94, func_02029CC0, func_02029CF0, func_02029D44, func_02029D7C, func_02029D8C, func_02029DBC, func_02029DD8, func_02029DF4, func_02029DFC, func_02029E08, func_02029E20, func_02029E58, func_02029E64, func_02029E74, func_02029EB4, func_02029F14, func_02029F44, func_02029F4C, func_02029F54, func_02029F60, func_02029F6C, func_02029F8C, func_02029FD0, func_02029FE4, func_02029FF8, func_0202A01C, func_0202A02C, func_0202A084, func_0202A0E8
 * address:  0x0202918C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02012E40  0x02012E40  thumb
 *   func_020289F8  0x020289F8  thumb
 *   func_020289B8  0x020289B8  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02012A30  0x02012A30  thumb
 *   func_02012984  0x02012984  thumb
 *   d_020A75A8  0x020A75A8  data
 *   func_02013BDC  0x02013BDC  thumb
 *   g_0209FE94  0x0209FE94  data
 *   g_0209FE98  0x0209FE98  data
 *   func_02013C30  0x02013C30  thumb
 *   func_02030734  0x02030734  arm
 *   g_020A76BC     0x020A76BC  data
 *   g_02146944     0x02146944  data
 *   func_020307B0  0x020307B0  arm
 *   func_0203508C  0x0203508C  arm
 *   func_02006224  0x02006224  thumb
 *   func_020061F8  0x020061F8  thumb
 *   func_0200616C  0x0200616C  thumb
 *   tbl_0209FED4   0x0209FED4  data  a1
 *   func_02072788  0x02072788  arm
 */
#include "../../matched/include/Obj00164.h"
#include "../../matched/include/Obj05724.h"
#include "../../matched/include/Obj01618.h"
#include "../../matched/include/Obj17256.h"
#include "../../matched/include/Obj01618.h"
#include "../../matched/include/Obj04741.h"
#include "../../matched/include/Obj04742.h"
#include "../../matched/include/Obj15804.h"
#include "../../matched/include/Obj11297.h"
#include "../../matched/include/Obj11298.h"
#include "../../matched/include/Obj11300.h"
#include "../../matched/include/Obj11301.h"
#include "../../matched/include/Obj11302.h"
#include "../../matched/include/Obj11303.h"
#include "../../matched/include/Obj11304.h"
#include "../../matched/include/Obj15806.h"
#include "../../matched/include/Obj15807.h"
#include "../../matched/include/Obj04055.h"

struct T;
struct S;
struct Sys;
struct Ctx;
struct Desc;
struct Obj;
struct BigObj;
struct SoundSys;
typedef unsigned char u8;

typedef unsigned int  u32;

typedef unsigned short u16;

struct T {
    u32 pad00;
    u32 f04;
    u32 f08;
    u8  pad0c[0x14];
    int f20;
    u32 f24;
};

struct Work {
    void *unk00;
    void *unk04;
    u32   unk08;
    u16   unk0C;
    u16   unk0E;
};

typedef u32 (*TaskFn)(void *task, u32 *state, struct Work *work);

typedef signed char    s8;

typedef int            s32;

typedef struct { u16 key; u16 val; } Pair;

extern int func_02005E50(void);
extern void func_02029344(void *obj, u32 value);
extern void func_02005D28(void);
extern void func_02029348(void *obj);
extern void func_02005DF8(u32 v);
extern void func_02005DE4(void *p);
extern void func_02005E30(u32 v);
extern void func_02028BA0(u8 *o, u32 v);
extern int func_02005E64(void);
extern int func_02005E9C(void);
extern void func_02028BDC(struct S *s, u32 mask);
extern u32 func_020063B4(u8 *a0, u32 *a1, u32 a2);
extern void func_0203D12C(int a);
extern void func_02005D90(u32 a, u32 b);
extern u8 func_02012E40(const u8 *o);
extern void func_020289F8(struct Sys *s, u32 a, u32 b, u16 c, u16 d);
extern void *func_020120F4(const struct Ctx *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern unsigned int func_02012A30(const struct BigObj *p);
extern u32 func_020289B8(struct Sys *s);
extern s32 func_020288C4(struct Sys *s);
extern void  func_02028A50(void *sys, void *res);
extern u32 func_02028988(struct Sys *s);
extern u32 func_020289D4(struct Sys *s);
extern u8 func_02012984(const struct BigObj *p);
extern u32 func_0202B57C(void *obj);
extern void func_0202B914(struct Obj *o, u32 v);
extern void func_02028A58(struct SoundSys *sys, u8 level, u16 frames);
extern void *func_02028900(void *p);
extern u32 func_02013BDC(u32 id, u32 which);
extern u32 func_0201296C(const struct BigObj *p);
extern u32 func_020142E8(void *bitmap, s32 id);
extern u32 func_02013C30(u32 id);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern void func_0203508C(u32 a, u32 b, u32 c);
extern int func_02006224(u32 a0);
extern void func_020061F8(int a);
extern void func_0200616C(void *arg, int i);
extern int func_020127A4(void *a);
extern int func_02012B28(int a);
extern void func_02072788(int vol);
extern void func_02072D98(int ch, int vol);
extern int func_020287A8(int a, int b);
void func_0202918C(u8 *p);
void func_020291A8(u8 *p);
void func_020291C4(u8 *p);
void func_020291E8(u8 *p);
int func_0202920C(u8 *p);
void func_02029228(u8 *p);
void func_02029250(u8 *p);
void func_02029288(u8 *p);
void func_020292C0(u8 *p);
void func_020292E8(u8 *p);
void func_0202930C(u8 *p);
void func_02029324(void *obj);
void sub_02029344(void *obj, u32 value);
void sub_02029348(void *obj);
void func_02029354(void *obj);
void func_02029364(u8 *p);
void func_02029374(u8 *p);
void func_0202938C(u8 *p);
void func_0202939C(struct T *p);
void func_020293D8(struct T *p);
u32 func_02029408(u8 *p);
u32 func_02029434(u8 *p);
void func_0202945C(u8 *p);
u32 func_0202947C(u8 *p);
int func_02029488(u32 unused, u32 *state, u8 *cfg);
u8 *func_020294C0(u8 *p, u32 a);
int func_020294F4(u32 unused, u32 *state, u8 *cfg);
u8 *func_0202952C(u8 *p, u32 a);
int func_02029560(u32 unused, u32 *state, u8 *cfg);
u8 *func_020295A4(u8 *p, u32 a);
u32 func_020295D8(void *task, u32 *state, struct Work *work);
void *func_02029620(void *a, u32 b, u32 c);
u32 func_02029658(void *task, u32 *state, struct Work *work);
void *func_02029690(void *a, u32 b, u32 c);
u32 func_020296C8(void *task, u32 *state, struct Work *work);
void *func_0202972C(void *a, u16 b);
u32 func_02029760(void *task, u32 *state, struct Work *work);
void *func_020297AC(void *a, u32 b, u32 c, u32 d);
u32 func_020297EC(void *task, u32 *state, struct Work *work);
void *func_02029830(void *a, u32 b);
u32 func_02029868(void *task, u32 *state, struct Work *work);
void *func_020298A0(void *a, u32 b, u32 c, u32 d);
u32 func_020298E0(void *task, u32 *state, struct Work *work);
u32 func_02029938(void *task, u32 *state, struct Work *work);
void *func_02029984(void *a, u32 b);
u32 func_020299B8(void *task, u32 *state, struct Work *work);
void *func_02029A04(void *a, u32 b, u16 c);
u32 func_02029A3C(void *task, u32 *state, struct Work *work);
void *func_02029A74(void *a, u16 b);
u32 func_02029AA8(void *task, u32 *state, struct Work *work);
void *func_02029AF4(void *a, u32 b);
void *func_02029B28(void *a, u16 b);
u32 func_02029B5C(void *task, u32 *state, struct Work *work);
void *func_02029BCC(void *a, u32 b);
void *func_02029C00(void *a);
u32 func_02029C38(void *task, u32 *state, struct Work *work);
void *func_02029C64(void *a);
u32 func_02029C94(void *task, u32 *state, struct Work *work);
void *func_02029CC0(void *a);
void func_02029CF0(void *sys, void *a, void *b);
void func_02029D44(u32 a, u32 b, u16 c, u8 d);
void func_02029D7C(u32 a);
void func_02029D8C(u32 a0, u32 a1, u32 a2);
void func_02029DBC(u8 *a, u32 b);
void func_02029DD8(void *a, void *b);
unsigned int func_02029DF4(void *a, unsigned int id, unsigned int which);
void *func_02029DFC(const void *p);
int func_02029E08(u32 a, u32 b);
u16 func_02029E20(u32 k);
int func_02029E58(void *a);
u32 func_02029E64(void *unused, u32 id, u32 which);
u32 func_02029E74(u32 a0, u32 a1);
u32 func_02029EB4(void *a, u32 id, u32 which);
u32 *func_02029F14(u32 a0, u32 a1);
void func_02029F44(void *ptr);
void func_02029F4C(void *p);
void func_02029F54(void *p);
void func_02029F60(void *p);
void func_02029F6C(void);
int func_02029F8C(u16 *p);
void func_02029FD0(void);
void func_02029FE4(void);
void func_02029FF8(u16 *p);
int func_0202A01C(void *obj);
int func_0202A02C(void *obj, u32 flag);
void func_0202A084(u32 *p, int event);
void func_0202A0E8(u32 *p);
extern Pair d_020A75A8[];
extern u8  g_0209FE94[];
extern u8  g_0209FE98[];
extern char   g_020A76BC[];
extern u32   *g_02146944;
extern const u8 tbl_0209FED4[][4];










/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202918C.c \
 *       --func func_0202918C --addr 0x0202918C --thumb --cc 1.1p1
 */
void func_0202918C(u8 *p)
{
    if (func_02005E50() != 0) {
        return;
    }
    func_02029344(p, 2);
    func_02029364(p);
}










/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020291A8.c \\
 *       --func func_020291A8 --addr 0x020291A8 --thumb --cc 1.1p1
 */
void func_020291A8(u8 *p)
{
    if (func_02005E50() != 0) {
        return;
    }
    func_02029344(p, 1);
    func_02029364(p);
}










/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020291C4.c \
 *       --func func_020291C4 --addr 0x020291C4 --thumb --cc 1.1p1
 */
void func_020291C4(u8 *p)
{
    if (func_02005E50() != 0) {
        return;
    }
    func_0202939C((struct T *)p);
    func_02029344(p, 0);
    func_02029364(p);
}










/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020291E8.c \\
 *       --func func_020291E8 --addr 0x020291E8 --thumb --cc 1.1p1
 */
void func_020291E8(u8 *p)
{
    if (func_02005E50() != 0) {
        return;
    }
    func_020293D8((struct T *)p);
    func_02029374(p);
    func_02029344(p, 7);
}









int func_0202920C(u8 *p)
{
    int r = func_02005E50();

    if (r != 0) {
        return r;
    }
    func_02029344(p, 1);
    func_02029364(p);
}










/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02029228.c \\
 *       --func func_02029228 --addr 0x02029228 --thumb --cc 1.1p1
 */
void func_02029228(u8 *p)
{
    if (func_02005E50() != 0) {
        return;
    }
    if (func_0202947C(p) != 0) {
        return;
    }
    func_02029408(p);
    func_02029344(p, 9);
}











void func_02029250(u8 *p)
{
    if (func_02029434(p) == 0) {
        return;
    }
    if (((struct Obj00164 *)p)->fC != 0 && ((struct Obj00164 *)p)->fC != ((struct Obj00164 *)p)->f8) {
        func_02005D28();
        func_02029344(p, 8);
        return;
    }
    func_02029374(p);
    func_02029344(p, 0xa);
}











void func_02029288(u8 *p)
{
    if (func_02005E50() != 0) {
        return;
    }
    if (((struct Obj05724 *)p)->fC != 0 && ((struct Obj05724 *)p)->fC != ((struct Obj05724 *)p)->f8) {
        func_0202938C(p);
        func_02029344(p, 8);
        return;
    }
    func_02029344(p, 1);
    func_02029364(p);
}











void func_020292C0(u8 *p)
{
    if (func_02005E50() != 0) {
        return;
    }
    if (func_0202947C(p) != 0) {
        return;
    }
    func_02029408(p);
    func_02029344(p, 0xc);
}










/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020292E8.c \\
 *       --func func_020292E8 --addr 0x020292E8 --thumb --cc 1.1p1
 */
void func_020292E8(u8 *p)
{
    if (func_02029434(p) == 0) {
        return;
    }
    func_0202939C((struct T *)p);
    func_02029344(p, 0);
    func_02029364(p);
}










/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202930C.c \\
 *       --func func_0202930C --addr 0x0202930C --thumb --cc 1.1p1
 */
void func_0202930C(u8 *p)
{
    if (func_02005E50() != 0) {
        return;
    }
    func_02029344(p, 0xe);
}








void func_02029324(void *obj)
{
    func_0202945C(obj);
    func_02005DE4((void *)1);
    func_02029344(obj, 2);
    func_02029364(obj);
}









/*
 * A whole translation unit, matched as one byte range.
 *
 * Two leaf helpers on the same object as the six checker/trampoline pairs of
 * pkt_0202918C's neighbour packets: sub_02029344 is a plain word setter at
 * offset 4, and sub_02029348 clears four fields (two words at +0xc/+0x1c,
 * two halfwords at +0x18/+0x1a) that the checker wrappers elsewhere test and
 * arm. Neither function has a relocation of any kind.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02029344.c \
 *       --addr 0x02029344 --thumb
 */
void sub_02029344(void *obj, u32 value)
{
    ((struct Obj17256 *)obj)->f4 = value;
}









void sub_02029348(void *obj)
{
    ((struct Obj01618 *)obj)->f1C = 0;
    ((struct Obj01618 *)obj)->fC = 0;
    ((struct Obj01618 *)obj)->f18 = 0;
    ((struct Obj01618 *)obj)->f1A = 0;
}








void func_02029354(void *obj)
{
    if (((struct Obj01618 *)obj)->f1C != 0) {
        sub_02029348(obj);
    }
}










/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02029364.c \\
 *       --func func_02029364 --addr 0x02029364 --thumb --cc 1.1p1
 */
void func_02029364(u8 *p)
{
    if (((struct Obj01618 *)p)->f1C != 0) {
        func_02029348(p);
    }
}











/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02029374.c \\
 *       --func func_02029374 --addr 0x02029374 --thumb --cc 1.1p1
 */
void func_02029374(u8 *p)
{
    if (((struct Obj00164 *)p)->f8 == 0) {
        return;
    }
    func_02005DF8(((struct Obj00164 *)p)->f18);
    func_02005DE4(0);
}











/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202938C.c \\
 *       --func func_0202938C --addr 0x0202938C --thumb --cc 1.1p1
 */
void func_0202938C(u8 *p)
{
    if (((struct Obj05724 *)p)->f8 != 0) {
        func_02005E30(((struct Obj05724 *)p)->f1A);
    }
}











void func_0202939C(struct T *p)
{
    if (p->f08 == 0) {
        return;
    }
    if (p->f20 >= 1) {
        return;
    }
    if (p->f20 == 0) {
        func_02028BA0((u8 *)p, 1);
    }
    func_02005DE4((void *)1);
    func_02005E64();
    *(u32 *)((char *)p + 0x24 + p->f20 * 4) = p->f08;
    p->f20 = p->f20 + 1;
    p->f08 = 0;
}








void func_020293D8(struct T *p)
{
    u32 n;

    if (p->f20 <= 0) {
        return;
    }
    func_02005E9C();
    func_02005DE4(0);
    n = p->f20 - 1;
    p->f20 = n;
    p->f08 = *(u32 *)((char *)p + 0x24 + n * 4);
    if (n == 0) {
        func_02028BDC((struct S *)p, 1);
    }
}







/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02029408.c \\
 *       --func func_02029408 --addr 0x02029408 --thumb --cc 1.1p1
 */
u32 func_02029408(u8 *p)
{
    if (((struct Obj04741 *)p)->fC == 0) {
        return 0;
    }
    func_020063B4((u8 *)(((struct Obj04741 *)p)->fC), (u32 *)((u32)(p + 0x14)), 1);
    ((struct Obj04741 *)p)->f10 = ((struct Obj04741 *)p)->fC;
    ((struct Obj04741 *)p)->fC = 0;
    ((struct Obj04741 *)p)->f8 = 0;
    func_0203D12C(2);
    return 1;
}







/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02029434.c \\
 *       --func func_02029434 --addr 0x02029434 --thumb --cc 1.1p1
 */
u32 func_02029434(u8 *p)
{
    u32 r = func_020063B4((u8 *)(((struct Obj00164 *)p)->f10), (u32 *)((u32)(p + 0x14)), 0);

    func_0203D12C(2);
    if (r != 0) {
        ((struct Obj00164 *)p)->f8 = ((struct Obj00164 *)p)->f10;
        ((struct Obj00164 *)p)->f10 = 0;
    }
    return r;
}







/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202945C.c \\
 *       --func func_0202945C --addr 0x0202945C --thumb --cc 1.1p1
 */
void func_0202945C(u8 *p)
{
    if (((struct Obj04742 *)p)->fC != 0) {
        func_02005D90(((struct Obj04742 *)p)->fC, 0xffff);
        ((struct Obj04742 *)p)->f8 = ((struct Obj04742 *)p)->fC;
        ((struct Obj04742 *)p)->fC = 0;
        ((struct Obj04742 *)p)->f10 = 0;
    }
}







/*
 * The callee is an unlabelled Thumb leaf, so its ISA has to be declared here;
 * without the `symbols:` line the name convention defaults it to ARM and the
 * `matched` class refuses the EXACT entry at 0x02012E40 on the ISA mismatch.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202947C.c \\
 *       --func func_0202947C --addr 0x0202947C --thumb --cc 1.1p1
 */
u32 func_0202947C(u8 *p)
{
    return func_02012E40((const u8 *)(((struct Obj15804 *)p)->f0));
}







/*
 * closed:   blocker func_02029488.c is now a manifest entry (matched class)
 *
 * Two-state stepper.  State 0 emits the descriptor (kind 1, selector from the
 * config block) and advances; state 1 reports done.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02029488.c \
 *       --func func_02029488 --addr 0x02029488 --thumb --cc 1.1p1
 */
int func_02029488(u32 unused, u32 *state, u8 *cfg)
{
    u32 v = ((struct Obj11297 *)cfg)->f4;

    switch (*state) {
    case 0:
        func_020289F8((struct Sys *)v, 1, 0, 0, ((struct Obj11297 *)cfg)->fC);
        (*state)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}







/*
 * closed:   blocker func_020294C0.c is now a manifest entry (matched class)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020294C0.c \\
 *       --func func_020294C0 --addr 0x020294C0 --thumb --cc 1.1p1
 */
u8 *func_020294C0(u8 *p, u32 a)
{
    u32 r7 = (u32)func_020120F4((const struct Ctx *)p);
    u8 *r6 = (u8 *)func_020122C0(p, 0, (void *)((u32)func_02029488), 0x10);
    u8 *r4 = func_020124E8((struct Obj *)r6);

    ((struct Obj11298 *)r4)->f4 = func_02012A30((const struct BigObj *)r7);
    ((struct Obj11298 *)r4)->fC = (u16)a;
    return r6;
}







/*
 * closed:   blocker func_02029488.c is now a manifest entry (matched class)
 *
 * Two-state stepper, kind 2 variant: state 0 emits the descriptor with the
 * selector on the register argument instead of the stack one.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_020294F4.c \
 *       --func func_020294F4 --addr 0x020294F4 --thumb --cc 1.1p1
 */
int func_020294F4(u32 unused, u32 *state, u8 *cfg)
{
    u32 v = ((struct Obj11300 *)cfg)->f4;

    switch (*state) {
    case 0:
        func_020289F8((struct Sys *)v, 2, 0, ((struct Obj11300 *)cfg)->fE, 0);
        (*state)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}







/*
 * closed:   blocker func_020294C0.c is now a manifest entry (matched class)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202952C.c \\
 *       --func func_0202952C --addr 0x0202952C --thumb --cc 1.1p1
 */
u8 *func_0202952C(u8 *p, u32 a)
{
    u32 r7 = (u32)func_020120F4((const struct Ctx *)p);
    u8 *r6 = (u8 *)func_020122C0(p, 0, (void *)((u32)func_020294F4), 0x10);
    u8 *r4 = func_020124E8((struct Obj *)r6);

    ((struct Obj11301 *)r4)->f4 = func_02012A30((const struct BigObj *)r7);
    ((struct Obj11301 *)r4)->fE = (u16)a;
    return r6;
}







/*
 * closed:   blocker func_02029488.c is now a manifest entry (matched class)
 *
 * Three-state stepper, kind 3 variant: state 0 emits the descriptor and
 * advances, state 1 advances only once func_020289B8 reports the channel is
 * idle, state 2 reports done.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02029560.c \
 *       --func func_02029560 --addr 0x02029560 --thumb --cc 1.1p1
 */
int func_02029560(u32 unused, u32 *state, u8 *cfg)
{
    u32 v = ((struct Obj11302 *)cfg)->f4;

    switch (*state) {
    case 0:
        func_020289F8((struct Sys *)v, 3, 0, ((struct Obj11302 *)cfg)->fE, 0);
        (*state)++;
        break;
    case 1:
        if (func_020289B8((struct Sys *)v) == 0) {
            (*state)++;
        }
        break;
    case 2:
        return 1;
    }
    return 0;
}







/*
 * closed:   blocker func_020294C0.c is now a manifest entry (matched class)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020295A4.c \\
 *       --func func_020295A4 --addr 0x020295A4 --thumb --cc 1.1p1
 */
u8 *func_020295A4(u8 *p, u32 a)
{
    u32 r7 = (u32)func_020120F4((const struct Ctx *)p);
    u8 *r6 = (u8 *)func_020122C0(p, 0, (void *)((u32)func_02029560), 0x10);
    u8 *r4 = func_020124E8((struct Obj *)r6);

    ((struct Obj11303 *)r4)->f4 = func_02012A30((const struct BigObj *)r7);
    ((struct Obj11303 *)r4)->fE = (u16)a;
    return r6;
}







/*
 * One of the sixteen (task body, task spawner) pairs that make up the tail of
 * field_sound_system.c.  Every pair has the same shape: a small state machine
 * driven by the counter the task system hands it, and a spawner that allocates
 * the 0x10 byte work block, parks the body's address in it and fills in the
 * parameters the body will read.
 *
 * The pair is one file on purpose.  The spawner's only reference to the body
 * is the ABS32 pool word at 0x02029654, and a pool word is not a branch, so
 * the body has no `label` witness anywhere in the image; with the two in
 * separate files the spawner caps at MATCH.  In one object the body is a
 * `local` symbol and the relocation needs no image evidence at all.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020295D8.c \
 *       --addr 0x020295D8 --thumb
 */
u32 func_020295D8(void *task, u32 *state, struct Work *work)
{
    void *sys = work->unk04;

    switch (*state) {
    case 0:
        func_020289F8(sys, 4, 0, work->unk0E, work->unk0C);
        (*state)++;
        break;
    case 1:
        if (func_020289B8(sys) == 0) {
            (*state)++;
        }
        break;
    case 2:
        return 1;
    }
    return 0;
}










void *func_02029620(void *a, u32 b, u32 c)
{
    void *x = func_020120F4(a);
    void *task = func_020122C0(a, 0, func_020295D8, 0x10);
    struct Work *work = func_020124E8(task);

    work->unk04 = (void *)func_02012A30(x);
    work->unk0C = c;
    work->unk0E = b;
    return task;
}










/*
 * One of the (task body, task spawner) pairs that make up the tail of
 * field_sound_system.c.  The body issues one command 4 and then reports done on the next tick.
 *
 * The pair is one file on purpose.  The spawner's only reference to the body
 * is an ABS32 pool word, and a pool word is not a branch, so the body has no
 * `label` witness anywhere in the image; with the two in separate files the
 * spawner caps at MATCH.  In one object the body is a `local` symbol and the
 * relocation needs no image evidence at all.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02029658.c  *       --addr 0x02029658 --thumb
 */
u32 func_02029658(void *task, u32 *state, struct Work *work)
{
    void *sys = work->unk04;

    switch (*state) {
    case 0:
        func_020289F8(sys, 4, 0, work->unk0E, work->unk0C);
        (*state)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}






void *func_02029690(void *a, u32 b, u32 c)
{
    void *x = func_020120F4(a);
    void *task = func_020122C0(a, 0, func_02029658, 0x10);
    struct Work *work = func_020124E8(task);

    work->unk04 = (void *)func_02012A30(x);
    work->unk0C = c;
    work->unk0E = b;
    return task;
}







/*
 * One of the (task body, task spawner) pairs that make up the tail of
 * field_sound_system.c.  The body asks the sound system how many entries it holds and issues one
 * command 4 per entry, the last of them carrying the parameter the spawner
 * stored.
 *
 * The pair is one file on purpose.  The spawner's only reference to the body
 * is an ABS32 pool word, and a pool word is not a branch, so the body has no
 * `label` witness anywhere in the image; with the two in separate files the
 * spawner caps at MATCH.  In one object the body is a `local` symbol and the
 * relocation needs no image evidence at all.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020296C8.c  *       --addr 0x020296C8 --thumb
 */
u32 func_020296C8(void *task, u32 *state, struct Work *work)
{
    void *sys = work->unk04;
    s32 n;
    s32 m;
    s32 i;

    switch (*state) {
    case 0:
        n = func_020288C4(sys);
        if (n > 0) {
            m = n - 1;
            for (i = 0; i < m; i++) {
                func_020289F8(sys, 4, 0, 0, 0);
            }
            func_020289F8(sys, 4, 0, 0, work->unk0C);
        }
        (*state)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}






void *func_0202972C(void *a, u16 b)
{
    void *x = func_020120F4(a);
    void *task = func_020122C0(a, 0, func_020296C8, 0x10);
    struct Work *work = func_020124E8(task);

    work->unk04 = (void *)func_02012A30(x);
    work->unk0C = b;
    return task;
}







/*
 * One of the (task body, task spawner) pairs that make up the tail of
 * field_sound_system.c.  The body issues a command 3 and a command 5 in the same tick.
 *
 * The pair is one file on purpose.  The spawner's only reference to the body
 * is an ABS32 pool word, and a pool word is not a branch, so the body has no
 * `label` witness anywhere in the image; with the two in separate files the
 * spawner caps at MATCH.  In one object the body is a `local` symbol and the
 * relocation needs no image evidence at all.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02029760.c  *       --addr 0x02029760 --thumb
 */
u32 func_02029760(void *task, u32 *state, struct Work *work)
{
    void *sys = work->unk04;

    switch (*state) {
    case 0:
        func_020289F8(sys, 3, 0, work->unk0E, 0);
        func_020289F8(sys, 5, work->unk08, 0, work->unk0C);
        (*state)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}






void *func_020297AC(void *a, u32 b, u32 c, u32 d)
{
    void *x = func_020120F4(a);
    void *task = func_020122C0(a, 0, func_02029760, 0x10);
    struct Work *work = func_020124E8(task);

    work->unk04 = (void *)func_02012A30(x);
    work->unk08 = b;
    work->unk0C = d;
    work->unk0E = c;
    return task;
}







/*
 * One of the (task body, task spawner) pairs that make up the tail of
 * field_sound_system.c.  The body issues a command 3 with a literal 6 and a command 7 in the same
 * tick.
 *
 * The pair is one file on purpose.  The spawner's only reference to the body
 * is an ABS32 pool word, and a pool word is not a branch, so the body has no
 * `label` witness anywhere in the image; with the two in separate files the
 * spawner caps at MATCH.  In one object the body is a `local` symbol and the
 * relocation needs no image evidence at all.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020297EC.c  *       --addr 0x020297EC --thumb
 */
u32 func_020297EC(void *task, u32 *state, struct Work *work)
{
    void *sys = work->unk04;

    switch (*state) {
    case 0:
        func_020289F8(sys, 3, 0, 6, 0);
        func_020289F8(sys, 7, work->unk08, 0, 0);
        (*state)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}






void *func_02029830(void *a, u32 b)
{
    void *x = func_020120F4(a);
    void *task = func_020122C0(a, 0, func_020297EC, 0x10);
    struct Work *work = func_020124E8(task);

    work->unk04 = (void *)func_02012A30(x);
    work->unk08 = b;
    work->unk0E = 0;
    return task;
}







/*
 * Part of the (task body, task spawner) family that makes up the tail of
 * field_sound_system.c.  The body issues one command 5 carrying all three stored parameters.
 *
 * The pair is one file on purpose.  The spawner's only reference to the body
 * is an ABS32 pool word, and a pool word is not a branch, so the body has no
 * `label` witness anywhere in the image; with the two in separate files the
 * spawner caps at MATCH.  In one object the body is a `local` symbol and the
 * relocation needs no image evidence at all.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02029868.c  *       --addr 0x02029868 --thumb
 */
u32 func_02029868(void *task, u32 *state, struct Work *work)
{
    void *sys = work->unk04;

    switch (*state) {
    case 0:
        func_020289F8(sys, 5, work->unk08, work->unk0E, work->unk0C);
        (*state)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}










void *func_020298A0(void *a, u32 b, u32 c, u32 d)
{
    void *x = func_020120F4(a);
    void *task = func_020122C0(a, 0, func_02029868, 0x10);
    struct Work *work = func_020124E8(task);

    work->unk04 = (void *)func_02012A30(x);
    work->unk08 = b;
    work->unk0C = d;
    work->unk0E = c;
    return task;
}










/*
 * Part of the (task body, task spawner) family that makes up the tail of
 * field_sound_system.c.  A four state body: it issues a command 2, waits for the system to go idle,
 * hands a resource off through func_02028A50 and then reports done.  The
 * resource is resolved from work->unk00 before the switch, even though only
 * the third state uses it.
 *
 * This body has no spawner inside the packet: nothing in
 * 0x020295D8..0x02029D44 holds its address, so it stands as its own file and
 * carries no self-reference to attest.
 *
 * What capped it: the call to func_02028A50 is the only branch to that
 * address in the image, so the `label` class had no witness outside this one
 * function and no cut helped.  Wave 26 closed it the honest way, by giving
 * 0x02028A50 an entry: func_02028D2C, func_02029F54 and func_02029F60 are now
 * EXACT, src/matched/unit_02028A50.c graduated with them, and this call site
 * resolves `matched`.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020298E0.c  *       --addr 0x020298E0 --thumb
 */
u32 func_020298E0(void *task, u32 *state, struct Work *work)
{
    void *res = func_020120F4(work->unk00);
    void *sys = work->unk04;

    switch (*state) {
    case 0:
        func_020289F8(sys, 2, 0, work->unk0E, 0);
        (*state)++;
        break;
    case 1:
        if (func_020289B8(sys) == 0) {
            (*state)++;
        }
        break;
    case 2:
        func_02028A50(sys, res);
        (*state)++;
        break;
    case 3:
        return 1;
    }
    return 0;
}








/*
 * Part of the (task body, task spawner) family that makes up the tail of
 * field_sound_system.c.  The body issues a command 2 with a literal 6 and a command 7, then waits
 * for the system to go idle before reporting done.
 *
 * The pair is one file on purpose.  The spawner's only reference to the body
 * is an ABS32 pool word, and a pool word is not a branch, so the body has no
 * `label` witness anywhere in the image; with the two in separate files the
 * spawner caps at MATCH.  In one object the body is a `local` symbol and the
 * relocation needs no image evidence at all.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02029938.c  *       --addr 0x02029938 --thumb
 */
u32 func_02029938(void *task, u32 *state, struct Work *work)
{
    void *sys = work->unk04;

    switch (*state) {
    case 0:
        func_020289F8(sys, 2, 0, 6, 0);
        func_020289F8(sys, 7, work->unk08, 0, 0);
        (*state)++;
        break;
    case 1:
        if (func_020289B8(sys) == 0) {
            return 1;
        }
        break;
    }
    return 0;
}









void *func_02029984(void *a, u32 b)
{
    void *x = func_020120F4(a);
    void *task = func_020122C0(a, 0, func_02029938, 0x10);
    struct Work *work = func_020124E8(task);

    work->unk04 = (void *)func_02012A30(x);
    work->unk08 = b;
    return task;
}









/*
 * Part of the (task body, task spawner) family that makes up the tail of
 * field_sound_system.c.  The same shape as unit_02029938.c with the command 2's third argument taken
 * from the work block instead of the literal 6.
 *
 * The pair is one file on purpose.  The spawner's only reference to the body
 * is an ABS32 pool word, and a pool word is not a branch, so the body has no
 * `label` witness anywhere in the image; with the two in separate files the
 * spawner caps at MATCH.  In one object the body is a `local` symbol and the
 * relocation needs no image evidence at all.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020299B8.c  *       --addr 0x020299B8 --thumb
 */
u32 func_020299B8(void *task, u32 *state, struct Work *work)
{
    void *sys = work->unk04;

    switch (*state) {
    case 0:
        func_020289F8(sys, 2, 0, work->unk0E, 0);
        func_020289F8(sys, 7, work->unk08, 0, 0);
        (*state)++;
        break;
    case 1:
        if (func_020289B8(sys) == 0) {
            return 1;
        }
        break;
    }
    return 0;
}









void *func_02029A04(void *a, u32 b, u16 c)
{
    void *x = func_020120F4(a);
    void *task = func_020122C0(a, 0, func_020299B8, 0x10);
    struct Work *work = func_020124E8(task);

    work->unk04 = (void *)func_02012A30(x);
    work->unk08 = b;
    work->unk0E = c;
    return task;
}









/*
 * Part of the (task body, task spawner) family that makes up the tail of
 * field_sound_system.c.  A one shot body: it issues both commands on the first tick and reports done
 * immediately.  The second command's 1001 is a pool word because it does not
 * fit a Thumb `movs` immediate, not because it is a relocation.
 *
 * VERSION SENSITIVITY: 1001 is a content id in the same space as the other
 * command 7 arguments in this family, so it is one to re-read for a Pokemon
 * White build; nothing else in this file is version dependent.
 *
 * The pair is one file on purpose.  The spawner's only reference to the body
 * is an ABS32 pool word, and a pool word is not a branch, so the body has no
 * `label` witness anywhere in the image; with the two in separate files the
 * spawner caps at MATCH.  In one object the body is a `local` symbol and the
 * relocation needs no image evidence at all.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02029A3C.c  *       --addr 0x02029A3C --thumb
 */
u32 func_02029A3C(void *task, u32 *state, struct Work *work)
{
    void *sys = work->unk04;

    if (*state == 0) {
        func_020289F8(sys, 2, 0, work->unk0E, 0);
        func_020289F8(sys, 7, 1001, 0, 0);
        return 1;
    }
    return 0;
}









void *func_02029A74(void *a, u16 b)
{
    void *x = func_020120F4(a);
    void *task = func_020122C0(a, 0, func_02029A3C, 0x10);
    struct Work *work = func_020124E8(task);

    work->unk04 = (void *)func_02012A30(x);
    work->unk0E = b;
    return task;
}









/*
 * Part of the (task body, task spawner) family that makes up the tail of
 * field_sound_system.c.  The body issues a command 3 with a literal 6 and a command 7, then waits
 * for the system to go idle before reporting done.
 *
 * The pair is one file on purpose.  The spawner's only reference to the body
 * is an ABS32 pool word, and a pool word is not a branch, so the body has no
 * `label` witness anywhere in the image; with the two in separate files the
 * spawner caps at MATCH.  In one object the body is a `local` symbol and the
 * relocation needs no image evidence at all.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02029AA8.c  *       --addr 0x02029AA8 --thumb
 */
u32 func_02029AA8(void *task, u32 *state, struct Work *work)
{
    void *sys = work->unk04;

    switch (*state) {
    case 0:
        func_020289F8(sys, 3, 0, 6, 0);
        func_020289F8(sys, 7, work->unk08, 0, 0);
        (*state)++;
        break;
    case 1:
        if (func_020289B8(sys) == 0) {
            return 1;
        }
        break;
    }
    return 0;
}









void *func_02029AF4(void *a, u32 b)
{
    void *x = func_020120F4(a);
    void *task = func_020122C0(a, 0, func_02029AA8, 0x10);
    struct Work *work = func_020124E8(task);

    work->unk04 = (void *)func_02012A30(x);
    work->unk08 = b;
    return task;
}









/*
 * Part of the (task body, task spawner) family that makes up the tail of
 * field_sound_system.c.  The spawner for the four state body at 0x020298E0, which sits far enough
 * away in the packet that the two cannot share a translation unit.
 *
 * What capped it: the ABS32 pool word naming func_020298E0 is the only
 * reference to that address anywhere in the image, and a pool word is not a
 * branch, so the `label` class had no witness.  Wave 26 closed the chain
 * underneath it (func_02028D2C, func_02029F54, func_02029F60 ->
 * unit_02028A50 -> unit_020298E0), and the site now resolves `matched`.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02029B28.c  *       --addr 0x02029B28 --thumb
 */
void *func_02029B28(void *a, u16 b)
{
    void *x = func_020120F4(a);
    void *task = func_020122C0(a, 0, func_020298E0, 0x10);
    struct Work *work = func_020124E8(task);

    work->unk00 = a;
    work->unk04 = (void *)func_02012A30(x);
    work->unk0E = b;
    return task;
}









/*
 * Part of the (task body, task spawner) family that makes up the tail of
 * field_sound_system.c.  A four state body whose first state picks command 2 or command 3 by asking
 * the queue depth.  Both arms of that choice write out the whole call and the
 * compiler cross-jumps all of it but the `movs r3, #6`
 * (docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md).
 *
 * The pair is one file on purpose.  The spawner's only reference to the body
 * is an ABS32 pool word, and a pool word is not a branch, so the body has no
 * `label` witness anywhere in the image; with the two in separate files the
 * spawner caps at MATCH.  In one object the body is a `local` symbol and the
 * relocation needs no image evidence at all.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02029B5C.c  *       --addr 0x02029B5C --thumb
 */
u32 func_02029B5C(void *task, u32 *state, struct Work *work)
{
    void *sys = work->unk04;

    switch (*state) {
    case 0:
        if (func_020288C4(sys) == 0) {
            func_020289F8(sys, 3, 0, 6, 0);
        } else {
            func_020289F8(sys, 2, 0, 6, 0);
        }
        (*state)++;
        break;
    case 1:
        if (func_020289B8(sys) == 0) {
            (*state)++;
        }
        break;
    case 2:
        func_020289F8(sys, 7, work->unk08, 0, 0);
        (*state)++;
        break;
    case 3:
        return 1;
    }
    return 0;
}









void *func_02029BCC(void *a, u32 b)
{
    void *x = func_020120F4(a);
    void *task = func_020122C0(a, 0, func_02029B5C, 0x10);
    struct Work *work = func_020124E8(task);

    work->unk04 = (void *)func_02012A30(x);
    work->unk08 = b;
    return task;
}









/*
 * Part of the (task body, task spawner) family that makes up the tail of
 * field_sound_system.c.  A second spawner for the body at 0x02029658, this one with the two command
 * parameters fixed at 60 and 30 instead of taken from its caller.
 *
 * It is a file of its own because the body it parks, func_02029658, already
 * has a manifest entry of its own (src/matched/unit_02029658.c), so the ABS32
 * pool word here is carried by the `matched` class and needs no merge.
 *
 * VERSION SENSITIVITY: 60 and 30 are frame counts rather than content ids, so
 * they are structure for porting purposes; nothing here is version dependent.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02029C00.c  *       --addr 0x02029C00 --thumb
 */
void *func_02029C00(void *a)
{
    void *x = func_020120F4(a);
    void *task = func_020122C0(a, 0, func_02029658, 0x10);
    struct Work *work = func_020124E8(task);

    work->unk04 = (void *)func_02012A30(x);
    work->unk0C = 0x3C;
    work->unk0E = 0x1E;
    return task;
}









/*
 * Part of the (task body, task spawner) family that makes up the tail of
 * field_sound_system.c.  The body waits until the system's mode word leaves the set
 * src/matched/func_02028988.c accepts, then reports done.
 *
 * The pair is one file on purpose.  The spawner's only reference to the body
 * is an ABS32 pool word, and a pool word is not a branch, so the body has no
 * `label` witness anywhere in the image; with the two in separate files the
 * spawner caps at MATCH.  In one object the body is a `local` symbol and the
 * relocation needs no image evidence at all.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02029C38.c  *       --addr 0x02029C38 --thumb
 */
u32 func_02029C38(void *task, u32 *state, struct Work *work)
{
    void *sys = work->unk04;

    switch (*state) {
    case 0:
        if (func_02028988(sys) == 0) {
            (*state)++;
        }
        break;
    case 1:
        return 1;
    }
    return 0;
}









void *func_02029C64(void *a)
{
    void *x = func_020120F4(a);
    void *task = func_020122C0(a, 0, func_02029C38, 0x10);
    struct Work *work = func_020124E8(task);

    work->unk04 = (void *)func_02012A30(x);
    return task;
}









/*
 * Part of the (task body, task spawner) family that makes up the tail of
 * field_sound_system.c.  The body waits until src/matched/func_020289D4.c says the system will take
 * another request, then reports done.
 *
 * The pair is one file on purpose.  The spawner's only reference to the body
 * is an ABS32 pool word, and a pool word is not a branch, so the body has no
 * `label` witness anywhere in the image; with the two in separate files the
 * spawner caps at MATCH.  In one object the body is a `local` symbol and the
 * relocation needs no image evidence at all.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02029C94.c  *       --addr 0x02029C94 --thumb
 */
u32 func_02029C94(void *task, u32 *state, struct Work *work)
{
    void *sys = work->unk04;

    switch (*state) {
    case 0:
        if (func_020289D4(sys) == 1) {
            (*state)++;
        }
        break;
    case 1:
        return 1;
    }
    return 0;
}









void *func_02029CC0(void *a)
{
    void *x = func_020120F4(a);
    void *task = func_020122C0(a, 0, func_02029C94, 0x10);
    struct Work *work = func_020124E8(task);

    work->unk04 = (void *)func_02012A30(x);
    return task;
}







/*
 * The last function of pkt_020295D8, and not a task at all: it resolves a
 * sequence id for the request and issues one command 5 for it, with the fifth
 * argument 60 or 0 depending on a mode query.  func_02029E74 answers 0xFFFFFFFF
 * when it has no id of its own and func_02029E64 is the fallback.
 *
 * The mode test's two arms leave `movs r3, #0x3c` duplicated and cross-jump
 * everything after it, which is what says both the fourth and the fifth
 * argument are locals assigned in each arm, and that the fourth is assigned
 * the same 60 in both.  Passing the literal 60 at a single call site after the
 * `if` hoists that `movs` out of the arms; writing the whole call in each arm
 * duplicates the call as well
 * (docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md).
 *
 * VERSION SENSITIVITY: 60 is a frame count, not a content id.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02029CF0.c \
 *       --addr 0x02029CF0 --thumb
 */
void func_02029CF0(void *sys, void *a, void *b)
{
    void *pri = (void *)func_02012984(a);
    u32 id = func_02029E74((u32)a, (u32)b);
    u16 c;
    u16 v;

    if (id == 0xFFFFFFFF) {
        id = func_02029E64(a, (u32)b, (u32)pri);
    }
    if (func_02029E58(a) == 1) {
        c = 0x3C;
        v = 0x3C;
    } else {
        c = 0x3C;
        v = 0;
    }
    func_020289F8(sys, 5, id, c, v);
}





void func_02029D44(u32 a, u32 b, u16 c, u8 d)
{
    u32 r = func_02029E74(b, c);

    if (r == ~0u) {
        r = func_02029E64((void *)b, c, d);
    }

    func_020289F8((struct Sys *)a, 6, r, 0x3C, 0);
}






void func_02029D7C(u32 a)
{
    func_020289F8((struct Sys *)a, 1, 0, 0, 0);
}






void func_02029D8C(u32 a0, u32 a1, u32 a2)
{
    u32 temp = func_02012984((const struct BigObj *)a1);
    u32 res = func_02029EB4((void *)a1, a2, temp);
    func_020289F8((struct Sys *)a0, 5, res, 0x1e, 0);
}





/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02029DBC.c \
 *       --func func_02029DBC --addr 0x02029DBC --thumb --cc 1.1p1
 */
void func_02029DBC(u8 *a, u32 b)
{
    u32 r = func_0202B57C((void *)b);

    func_0202B914((struct Obj *)r, 0);
    func_02028A58((struct SoundSys *)a, 0x40, 6);
}







void func_02029DD8(void *a, void *b)
{
    u32 r = func_0202B57C(b);

    func_0202B914((struct Obj *)r, 0x7f);
    func_02028A58((struct SoundSys *)a, 0x7f, 6);
}









/*
 * Plain forwarder to func_02029EB4 (ldr r3, =target; bx r3).  Seeded in
 * layout/function_starts.txt from the bl sites in ov020 and ov021
 * (w6_fix18).
 */
unsigned int func_02029DF4(void *a, unsigned int id, unsigned int which)
{
    return func_02029EB4(a, id, which);
}









void *func_02029DFC(const void *p)
{
    return func_02028900((void *)func_02012A30(p));
}








int func_02029E08(u32 a, u32 b)
{
    if (func_02029E74(a, b) != 0xffffffff) {
        return 1;
    }
    return 0;
}








u16 func_02029E20(u32 k)
{
    int i;
    for (i = 0; d_020A75A8[i].key != 0x69; i++) {
        if (k == d_020A75A8[i].key)
            return d_020A75A8[i].val;
    }
    return 0x45A;
}







int func_02029E58(void *a)
{
    return func_02012B28(func_020127A4(a));
}








u32 func_02029E64(void *unused, u32 id, u32 which)
{
    return func_02013BDC((u16)id, which);
}








/*
 * 2026-09-21, FAMILY wave.  Re-verified in a fresh process: still MATCH,
 * every concrete byte identical.  Evidence worked to exhaustion:
 *   - `--suggest-split` reports "witnesses image wide: 1, of them inside
 *     this range: 1"; a single-function file has nothing to cut against.
 *   - No sibling in field_sound_system.c (0x02028844..0x02029EB4) references
 *     the object: the only other listing hits are the rodata DEFINITION in
 *     asm/arm9/src/030_*.s, which is a referent, not a referrer.
 *   - sole-ref/data was probed directly.  in_data_section = True and the
 *     layout/data_objects.txt row IS an object start when the range is
 *     ignored, but `_map_attests(addr, lo, hi)` = False once the range is
 *     applied, because that row's sole referrer is this function's own pool
 *     word.  This is the documented "a lone reference never contributes its
 *     own start" rule firing correctly, not a tooling gap.
 * Declarations cross-checked against docs/families/field_sound_system.h.
 */
u32 func_02029E74(u32 a0, u32 a1)
{
    u32 v = func_0201296C((const struct BigObj *)a0);
    u32 i;

    for (i = 0; i < 8; i++) {
        if (a1 == *(u16 *)(g_0209FE94 + i * 8 + 2)) {
            if (func_020142E8((void *)v, *(u16 *)(g_0209FE94 + i * 8)) == 1) {
                return *(u32 *)(g_0209FE98 + i * 8);
            }
        }
    }
    return 0xffffffff;
}







u32 func_02029EB4(void *a, u32 id, u32 which)
{
    int mode;

    u32 r;

    mode = func_02029E58(a);
    func_02012A30(a);
    r = func_02029E74((u32)a, id);
    if (r == (u32)-1) {
        if (mode == 2) {
            if (func_02013C30((u16)id)) {
                return 0x3f5;
            }
        }
        if (mode == 1) {
            if (func_02013C30((u16)id)) {
                return 0x3f4;
            }
        }
        return func_02029E64(a, id, which);
    }
    return r;
}







u32 *func_02029F14(u32 a0, u32 a1)
{
    u32 *p = func_02030734(a0, 0xc, 1, g_020A76BC, 0x72);

    ((struct Obj11304 *)p)->f4 = 0;
    p[2] = a1;
    g_02146944 = p;
    func_02029F6C();
    return p;
}







void func_02029F44(void *ptr)
{
    func_020307B0(ptr);
}







void func_02029F4C(void *p)
{
    func_0202A0E8(p);
}







/*
 * A twelve-byte forwarding thunk that pins the second argument to 1: a pool
 * word and a `bx` (docs/idioms/tail-call-is-a-pool-word-and-bx.md) with the
 * constant materialised before the branch.  It saves no `lr`, so `disasm.py`
 * never labels it and it prints as a run of `.word`s in the listing
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md); 0x02029F54 is
 * a seed for layout/function_starts.txt.
 *
 * Kept in its own file rather than folded in with func_02029F60 so that the
 * sibling's pool word stays outside this range.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02029F54.c \
 *       --addr 0x02029F54 --thumb
 */
void func_02029F54(void *p)
{
    func_0202A084(p, 1);
}






/*
 * A twelve-byte forwarding thunk that pins the second argument to 0: a pool
 * word and a `bx` (docs/idioms/tail-call-is-a-pool-word-and-bx.md) with the
 * constant materialised before the branch.  It saves no `lr`, so `disasm.py`
 * never labels it and it prints as a run of `.word`s in the listing
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md); 0x02029F60 is
 * a seed for layout/function_starts.txt.
 *
 * Kept in its own file rather than folded in with func_02029F54 so that the
 * sibling's pool word stays outside this range.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02029F60.c \
 *       --addr 0x02029F60 --thumb
 */
void func_02029F60(void *p)
{
    func_0202A084(p, 0);
}






void func_02029F6C(void)
{
    if (g_02146944 != 0) {
        func_0203508C((u32)((void *)func_02029FD0), (u32)((void *)func_02029FE4), (u32)g_02146944);
    }
}





int func_02029F8C(u16 *p)
{
    if (p[2] != 0) {
        p[2] = p[2] - 1;
    }
    if (p[2] == 0) {
        if (func_02006224(4) == 1) {
            func_020061F8(4);
        }
        return 0;
    }
    if (func_02006224(4) == 0) {
        func_0200616C((void *)0x662, 4);
    }
    return 1;
}





/*
 * ringtone_sys.c: forward the global ringtone state (g_02146944, set by
 * func_02029F14) to func_0202A084 with event 3, a pool-word tail call.
 * The two thunks 0x02029FD0 / 0x02029FE4 differ only in the event id.
 */
void func_02029FD0(void)
{
    func_0202A084(g_02146944, 3);
}





/*
 * ringtone_sys.c: forward the global ringtone state (g_02146944, set by
 * func_02029F14) to func_0202A084 with event 2, a pool-word tail call.
 * The two thunks 0x02029FD0 / 0x02029FE4 differ only in the event id.
 */
void func_02029FE4(void)
{
    func_0202A084(g_02146944, 2);
}



void func_02029FF8(u16 *p)
{
    if (func_02006224(4) == 0) {
        func_0200616C((void *)0x662, 4);
    }
    p[2] = 0x384;
}



int func_0202A01C(void *obj)
{
    func_020061F8(4);
    ((struct Obj15806 *)obj)->f4 = 0;
    return 0;
}



int func_0202A02C(void *obj, u32 flag)
{
    if (flag == 1) {
        func_02072D98(1, 0);
        func_02072D98(2, 0);
        func_02072D98(3, 0);
        func_02072D98(4, 0);
    } else {
        func_02072D98(1, 0x7f);
        func_02072D98(2, 0x7f);
        func_02072D98(3, 0x7f);
        func_02072D98(4, 0x7f);
    }
    return func_020287A8(((struct Obj15807 *)obj)->f8, flag);
}



/*
 * ringtone_sys.c: the ringtone state machine.  The next state is a byte of
 * the 4-column transition table at 0x0209FED4, tbl[state][event]; a plain
 * 2D subscript is the addressing the image has (base + state * 4, then
 * `ldrb [event, base]`), which the byte-offset spellings of
 * docs/notes/pkt_0202A084.c.txt never gave.  Case 1 and case 3 are written
 * out separately with the same body: the image's case 1 is a lone `b` into
 * case 3 (cross-jumped), not a shared label.
 */
void func_0202A084(u32 *p, int event)
{
    u8 v = tbl_0209FED4[*p][event];

    switch (v) {
    case 0:
        func_02072788(0x7f);
        func_0202A02C(p, 0);
        func_0202A01C(p);
        break;
    case 1:
        func_02072788(0x7f);
        func_0202A02C(p, 1);
        func_02029FF8((u16 *)p);
        break;
    case 2:
        func_02072788(0);
        func_0202A01C(p);
        break;
    case 3:
        func_02072788(0x7f);
        func_0202A02C(p, 1);
        func_02029FF8((u16 *)p);
        break;
    }
    *p = v;
}



void func_0202A0E8(u32 *p)
{
    int r = func_02029F8C((u16 *)p);

    switch (((struct Obj04055 *)p)->f0) {
    case 0:
        break;
    case 1:
        if (r == 0) {
            func_0202A084(p, 0);
        }
        break;
    case 2:
        break;
    case 3:
        if (r == 0) {
            func_0202A084(p, 2);
        }
        break;
    }
}
