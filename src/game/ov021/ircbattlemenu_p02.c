/*
 * file:     ircbattlemenu_p02.c
 * unit:     yes
 * function: func_02197798, func_021977C0, func_02197800, func_021978AC, func_021978D4, func_021978DC, func_02197AAC, func_02197B5C, func_02197C4C, func_02197C78, func_02197C9C, func_02197CCC, func_02197D3C, func_02197DA0, func_02197DAC, func_02197DCC
 * address:  0x02197798
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021975D0  0x021975D0  thumb  ov021
 *   func_02012DAC  0x02012DAC  thumb
 *   func_02196034  0x02196034  thumb  ov021
 *   func_02197738  0x02197738  thumb  ov021
 *   func_02035C60  0x02035C60  arm
 *   func_02196228  0x02196228  thumb  ov021
 *   func_020414EC  0x020414EC  arm
 *   func_021962F4  0x021962F4  thumb  ov021
 *   func_02196A4C  0x02196A4C  thumb  ov021
 *   func_020279E8  0x020279E8  thumb
 *   func_02027A04  0x02027A04  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_020071F0  0x020071F0  thumb
 *   func_02045CAC  0x02045CAC  arm
 *   func_02197644  0x02197644  thumb  ov021
 *   func_02196290  0x02196290  thumb  ov021
 *   func_02027858  0x02027858  thumb
 *   func_02197534  0x02197534  thumb  ov021
 *   func_0204A648  0x0204A648  arm
 *   func_0203064C  0x0203064C  arm
 *   func_0203159C  0x0203159C  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_0203F8F4  0x0203F8F4  arm
 *   func_02045088  0x02045088  arm
 *   func_0201DD60  0x0201DD60  thumb
 *   func_020433E0  0x020433E0  arm
 *   d_021DDB14     0x021DDB14  data   ov021  a4
 *   d_021D4090     0x021D4090  data   ov021  a4
 *   func_0203FC28  0x0203FC28  arm
 *   func_02043534  0x02043534  arm
 *   func_020435F4  0x020435F4  arm
 *   d_020A1448     0x020A1448  data   a4
 *   func_0204A48C  0x0204A48C  arm
 *   func_0204B100  0x0204B100  arm
 *   func_020056A0  0x020056A0  thumb
 *   func_0219603C  0x0219603C  thumb  ov021
 *   func_02196538  0x02196538  thumb  ov021
 *   d_021DDBC4     0x021DDBC4  data   ov021  a4
 *   func_02030734  0x02030734  arm
 *   func_0203101C  0x0203101C  arm
 *   func_02028590  0x02028590  thumb
 *   func_0201C440  0x0201C440  thumb
 *   func_02027F60  0x02027F60  thumb
 *   func_02196FFC  0x02196FFC  thumb  ov021
 *   func_0219749C  0x0219749C  thumb  ov021
 *   func_0202208C  0x0202208C  thumb
 *   func_021966F0  0x021966F0  thumb  ov021
 *   func_02155A90  0x02155A90  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_0207D63C  0x0207D63C  arm
 *   func_0203D34C  0x0203D34C  arm
 *   func_0201283C  0x0201283C  thumb
 *   func_0201058C  0x0201058C  thumb
 *   func_02027974  0x02027974  thumb
 *   func_02028178  0x02028178  thumb
 *   func_02040618  0x02040618  arm
 *   func_020310C4  0x020310C4  arm
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_0204A600  0x0204A600  arm
 *   func_020121CC  0x020121CC  thumb
 *   func_020221A4  0x020221A4  thumb
 *   func_02012204  0x02012204  thumb
 *   func_0202223C  0x0202223C  thumb
 *   func_02196768  0x02196768  thumb  ov021
 *   func_02155A8C  0x02155A8C  thumb  ov010
 *   func_0202F038  0x0202F038  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_021974A0  0x021974A0  thumb  ov021
 *   func_0201CE48  0x0201CE48  thumb
 *   func_02028604  0x02028604  thumb
 *   func_02031140  0x02031140  arm
 *   func_020403F4  0x020403F4  arm
 *   func_0201C6EC  0x0201C6EC  thumb
 *   func_0201C4C0  0x0201C4C0  thumb
 *   func_020452E8  0x020452E8  arm
 *   func_02028148  0x02028148  thumb
 *   func_02027FD8  0x02027FD8  thumb
 *   func_02030EAC  0x02030EAC  arm
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_0204A5AC  0x0204A5AC  arm
 *   func_020450C8  0x020450C8  arm
 *   func_0203F9B4  0x0203F9B4  arm
 *   func_020315D4  0x020315D4  arm
 *   func_020306F0  0x020306F0  arm
 *   func_0216D520  0x0216D520  thumb  ov010
 *   func_0219C5D0  0x0219C5D0  thumb  ov021
 *   func_0216D528  0x0216D528  thumb
 *   func_0219D488  0x0219D488  thumb  ov021
 *   func_0216D95C  0x0216D95C  thumb  ov010
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D4D4  0x0216D4D4  thumb  ov010
 *   func_0216DAA0  0x0216DAA0  thumb  ov010
 *   func_0216D758  0x0216D758  thumb  ov010
 *   func_0216DB10  0x0216DB10  thumb  ov010
 *   func_0216DC4C  0x0216DC4C  thumb  ov010
 *   func_0216D55C  0x0216D55C  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_0216D8B0  0x0216D8B0  thumb  ov010
 *   func_0216D8D0  0x0216D8D0  thumb  ov010
 *   func_0216D8F0  0x0216D8F0  thumb  ov010
 *   func_0216D92C  0x0216D92C  thumb  ov010
 *   func_0216D4F8  0x0216D4F8  thumb  ov010
 *   func_0216D4F4  0x0216D4F4  thumb  ov010
 *   func_0216D514  0x0216D514  thumb  ov010
 *   func_02030DA8  0x02030DA8  arm
 *   d_021DDBE0     0x021DDBE0  data  a4
 *   func_02030EE8  0x02030EE8  arm
 *   func_0216D480  0x0216D480  thumb  ov010
 *   d_021D4A50     0x021D4A50  data  a4
 */
#include "../../matched/include/Obj00094.h"
#include "../../matched/include/Obj00150.h"
#include "../../matched/include/Obj01495.h"
#include "../../matched/include/Obj19637.h"
#include "../../matched/include/Obj17950.h"

struct Big;
struct MsgBank;
struct TaskMenu;
struct Obj;
struct Obj0203159C;
struct DispConfig;
struct DispVram;
struct Bank;
struct Cfg;
struct R;
struct Tcbl;
struct Ctx;
struct BigObj;
struct IcaAnime;
struct PrintSys;
struct Descriptor;
struct Node;
struct Rec3;
struct S02031140;
struct TaskMenuState;
struct S020315D4;
struct Actor;
struct VecFx32;
struct S02030EE8;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef signed int     s32;

typedef struct { u32 w[4]; } Q16;

extern int func_021975D0(u8 *p);
extern int func_02012DAC(int a0);
extern void func_02196034(u8 *, void (*)(), u32);
extern void func_02197738(u8 *a);
extern int func_02035C60(void);
extern void func_02196228(u8 *p, int flag);
extern void func_020414EC(u32);
extern void func_021962F4(u8 *);
extern void func_02196A4C(u8 *a);
extern u32 func_020279E8(struct TaskMenu *m);
extern u8 func_02027A04(const u8 *p);
extern void *func_02012EBC(struct Big *p);
extern u32 func_020071F0(void);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_02197644(u8 *, u32);
extern void func_02196290(u8 *);
extern void func_02027858(struct TaskMenu *m);
extern void func_02197534(struct Obj *a);
extern void func_0204A648(void);
extern void func_0203064C(u32, u32, u32);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *, u32, u32);
extern void func_0203F8F4(u16 heapId);
extern void func_02045088(u16 heapId);
extern void func_0201DD60(void);
extern void func_020433E0(const struct DispVram *c);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_02043534(u32);
extern void func_020435F4(u32);
extern void func_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern u32 func_020056A0(void (*)(void), void *, u32);
extern void func_0219603C(void *a0);
extern void func_02196538(u8 *);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct Tcbl *func_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
extern u32 func_02028590(u32, u32, u32, u32);
extern u32 func_0201C440(void *p);
extern struct R *func_02027F60(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern void func_02196FFC(u8 *);
extern void func_0219749C(u8 *, u32, u32, u32, u32);
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void func_021966F0(u8 *p);
extern u32 func_02155A90(u8 *);
extern void *func_020120F4(const struct Ctx *);
extern void func_0207D63C(u32, u32, u32, u32, u32);
extern void func_0203D34C(u32, u32);
extern u32 func_0201283C(const struct BigObj *p);
extern u32 func_0201058C(void *key);
extern void func_02027974(u32);
extern void func_02028178(u8 *p);
extern void func_02040618(u32, u32, u32);
extern void func_020310C4(struct Tcbl *p);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_0204A600(void);
extern u32 func_020121CC(struct IcaAnime *p);
extern u32 func_020221A4(void);
extern u32 func_02012204(const struct Ctx *p);
extern void func_0202223C(u32, u32);
extern void func_02196768(u8 *p);
extern void func_02155A8C(u8 *, u32);
extern void func_0202F038(u8 *p);
extern u32 func_020307B0(void *p);
extern void func_021974A0(struct Obj *o);
extern void func_0201CE48(struct Rec3 *p);
extern int func_02028604(int a0);
extern void func_02031140(struct S02031140 *p);
extern void func_020403F4(u32);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_02028148(u8 *p);
extern u32 func_02027FD8(struct TaskMenuState *s);
extern void func_02030EAC(struct Node *n);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void func_020315D4(struct S020315D4 *);
extern void func_020306F0(u32);
extern u32 func_0216D520(void *p);
extern u32 func_0216D528(u32);
extern u32 func_0216D95C(u32, u32);
extern void func_0219C5D0(u32 a);
extern void func_0219D488(u32 a);
extern void *func_0216D67C(void *a0);
extern int func_0216D4D4(int a0, int a1);
extern int func_0216DAA0(void *a0);
extern void func_0216D758(void *a0);
extern int func_0216D55C(int a0, int a1);
extern int func_0216DB10(void *a0);
extern int func_0216DC4C(void *a0);
extern void func_0216D88C(const struct Actor *, struct VecFx32 *);
extern void func_0216D8B0(u8 *p, u8 *q);
extern void func_0216D8D0(u8 *p, u8 *q);
extern void func_0216D8F0(u8 *p, u8 *q);
extern void func_0216D92C(u8 *, s32 *);
extern u32 func_0216D4F8(u8 *p);
extern u16 func_0216D4F4(void *p);
extern u32 func_0216D514(void *p);
extern void func_02030DA8(u32, void (*)(), u32 *, u32);
extern u32 func_02030EE8(struct S02030EE8 *p);
extern int func_0216D480(char *p);
void func_02197798(u8 *a);
void func_021977C0(u8 *a);
void func_02197800(u8 *a);
void func_021978AC(u8 *a);
void func_021978D4(void);
int func_021978DC(struct Obj0203159C *a, u32 b, u32 c);
u32 func_02197AAC(u32 r0, u32 r1, u32 r2, u8 *a);
int func_02197B5C(u32 a, u32 b, u8 *c, u32 *d);
int func_02197C4C(u32 a, u32 b, u32 c, u32 d);
void func_02197C78(u32 a);
int func_02197C9C(u32 a);
void func_02197CCC(u8 *p, s32 *out);
void func_02197D3C(u32 p0, u32 p1);
int func_02197DA0(u32 a);
void func_02197DAC(void *a);
void func_02197DCC(void *a, int *b);
extern u8 d_021DDB14[];
extern const Q16 d_021D4090;
extern u8 d_020A1448[];
extern u8 d_021DDBC4[];
extern u8 d_021DDBE0;




/*
 * Addresses are Black-image addresses.
 */
void func_02197798(u8 *a)
{
    if (func_021975D0(a) != 0) {
        func_02012DAC(((struct Obj00094 *)a)->f30);
        func_02196034(a, func_02197738, 0x78E);
    }
}




void func_021977C0(u8 *a)
{
    if (func_021975D0(a) != 0 && func_02035C60() != 0) {
        func_02196228(a, 0);
        func_020414EC(3);
        func_021962F4(a);
        ((struct Obj00094 *)a)->f8 = 12;
        func_02196034(a, func_02196A4C, 0x7a2);
    }
}




void func_02197800(u8 *a)
{
    if (func_020279E8((struct TaskMenu *)(((struct Obj00094 *)a)->f2C0)) != 0) {
        if (func_02027A04((const u8 *)(((struct Obj00094 *)a)->f2C0)) == 0) {
            func_02012EBC((struct Big *)(((struct Obj00094 *)a)->f30));
            if (func_020071F0() != 0) {
                func_02045CAC((struct MsgBank *)(((struct Obj00094 *)a)->f28), 0x2d, (void *)(((struct Obj00094 *)a)->f38));
                func_02197644(a, 0);
                func_02196034(a, func_021977C0, 0x7b9);
            } else {
                func_02045CAC((struct MsgBank *)(((struct Obj00094 *)a)->f28), 0x1c, (void *)(((struct Obj00094 *)a)->f38));
                func_02197644(a, 1);
                func_02196290(a);
                func_02196034(a, func_02197798, 0x7bf);
            }
        } else {
            func_02196228(a, 0);
            func_020414EC(3);
            func_021962F4(a);
            ((struct Obj00094 *)a)->f8 = 12;
            func_02196034(a, func_02196A4C, 0x7c7);
        }
        func_02027858((struct TaskMenu *)(((struct Obj00094 *)a)->f2C0));
        ((struct Obj00094 *)a)->f2C0 = 0;
    }
}




void func_021978AC(u8 *a)
{
    if (func_021975D0(a) != 0) {
        func_02197534((struct Obj *)a);
        func_02196034(a, func_02197800, 0x7DC);
    }
}




/*
 * Untraced thunk: tail call into the ARM9 image.
 *
 * Addresses are Black-image addresses.
 */
void func_021978D4(void)
{
    func_0204A648();
}




int func_021978DC(struct Obj0203159C *a, u32 b, u32 c)
{
    u8 *w;

    func_0203064C(1, 0x1f, 0x18000);
    w = func_0203159C(a, 0x308, 0x1f);
    func_02082BCC(w, 0, 0x308);
    ((struct Obj00150 *)w)->f10 = 0x1f;
    func_0203F8F4(((struct Obj00150 *)w)->f10);
    func_02045088(((struct Obj00150 *)w)->f10);
    func_0201DD60();
    func_020433E0((const struct DispVram *)d_021DDB14);
    {
        Q16 q = d_021D4090;
        func_0203FC28((struct DispConfig *)(&q));
    }
    func_02043534(0);
    func_020435F4(0);
    func_0204A48C((const struct Cfg *)d_020A1448, (u32)d_021DDB14, ((struct Obj00150 *)w)->f10);
    ((struct Obj00150 *)w)->f26C = (u32)func_0204B100(0x28, 0, ((struct Obj00150 *)w)->f10);
    ((struct Obj00150 *)w)->f268 = func_020056A0(func_021978D4, w, 0);
    func_0219603C(w);
    func_02196538(w);
    ((struct Obj00150 *)w)->f2EC = (unsigned int)func_02030734(((struct Obj00150 *)w)->f10, 0x200, 0, (const char *)d_021DDBC4, 0x829);
    ((struct Obj00150 *)w)->f2F0 = (unsigned int)func_02030734(((struct Obj00150 *)w)->f10, 0x200, 0, (const char *)d_021DDBC4, 0x82A);
    ((struct Obj00150 *)w)->f2B8 = (u32)func_0203101C(((struct Obj00150 *)w)->f10, ((struct Obj00150 *)w)->f10, 2, 0);
    ((struct Obj00150 *)w)->f2A8 = func_02028590(0xf, 0, 1, ((struct Obj00150 *)w)->f10);
    ((struct Obj00150 *)w)->f2BC = func_0201C440((void *)(((struct Obj00150 *)w)->f10));
    ((struct Obj00150 *)w)->f2DC = (u32)func_02027F60(5, 9, *(u32 *)&((struct Obj00150 *)w)->f2C, ((struct Obj00150 *)w)->f2BC, ((struct Obj00150 *)w)->f10);
    func_02196FFC(w);
    func_0219749C(w, 0x39, 0x9a, 0, 10);
    func_0219749C(w, 0xc8, 0x26, 1, 11);
    func_0202208C(0, 1, 1, 0, 6, 1, ((struct Obj00150 *)w)->f10);
    func_02196034(w, (void (*)(void))func_021966F0, 0x83B);
    ((struct Obj00150 *)w)->f2E4 = c;
    ((struct Obj00150 *)w)->f30 = (u32)func_020120F4((const struct Ctx *)func_02155A90((u8 *)((struct Obj00150 *)w)->f2E4));
    func_0207D63C(0x04001050, 4, 1, 0xf, 4);
    func_0203D34C(0, ((struct Obj00150 *)w)->f10);
    func_02043534(0x13);
    func_020435F4(0x17);
    func_0207D63C(0x04000050, 0x10, 3, 9, 0xe);
    return 1;
}




u32 func_02197AAC(u32 r0, u32 r1, u32 r2, u8 *a)
{
    u32 ret;
    void (*cb)(u8 *);

    cb = *(void (**)(u8 *))a;
    ret = 1;
    func_0201058C((void *)func_0201283C((const struct BigObj *)(((struct Obj01495 *)a)->f30)));
    if (cb != 0) {
        cb(a);
        ret = 0;
    }
    if (((struct Obj01495 *)a)->f2C0 != 0) {
        func_02027974(((struct Obj01495 *)a)->f2C0);
    }
    if (((struct Obj01495 *)a)->f2E0 != 0) {
        func_02028178((u8 *)(((struct Obj01495 *)a)->f2E0));
    }
    func_02040618(4, 3, ((struct Obj01495 *)a)->f2AC);
    ((struct Obj01495 *)a)->f2AC = ((struct Obj01495 *)a)->f2AC - 1;
    func_020310C4((struct Tcbl *)(((struct Obj01495 *)a)->f2B8));
    func_0201C4E4((struct PrintSys *)(((struct Obj01495 *)a)->f2BC));
    func_0204A600();
    if (((struct Obj01495 *)a)->f306 == 0) {
        func_020121CC((struct IcaAnime *)func_02155A90((u8 *)(((struct Obj01495 *)a)->f2E4)));
    }
    if (func_020221A4() != 0) {
        if (func_02012204((const struct Ctx *)func_02155A90((u8 *)(((struct Obj01495 *)a)->f2E4))) != 0) {
            ((struct Obj01495 *)a)->f8 = 12;
            ret = 1;
            func_0202223C(0, 0);
            func_0202223C(1, 0);
        }
    }
    return ret;
}




int func_02197B5C(u32 a, u32 b, u8 *c, u32 *d)
{
    if (!func_020221A4()) {
        return 0;
    }
    func_02196768((u8 *)d);
    func_02155A8C(c, d[2]);
    ((struct Obj19637 *)c)->f58 = d[3];
    if (d[0xBA] != 0) {
        func_0202F038((u8 *)d[0xBA]);
        d[0xBA] = 0;
    }
    func_020307B0((void *)d[0xBB]);
    func_020307B0((void *)d[0xBC]);
    func_021974A0((struct Obj *)d);
    if (d[0xAD] != 0) {
        func_0201CE48((struct Rec3 *)d[0xAD]);
    }
    func_02028604(d[0xAA]);
    func_02031140((struct S02031140 *)d[0xAE]);
    func_020403F4(7);
    func_0201C6EC((struct PrintSys *)d[0xAF]);
    func_0201C4C0((struct PrintSys *)d[0xAF]);
    if (d[0xAC] != 0) {
        func_020452E8((struct Descriptor *)d[0xAC]);
    }
    if (d[0xB0] != 0) {
        func_02027858((struct TaskMenu *)d[0xB0]);
        d[0xB0] = 0;
    }
    if (d[0xB8] != 0) {
        func_02028148((u8 *)d[0xB8]);
    }
    func_02027FD8((struct TaskMenuState *)d[0xB7]);
    func_02030EAC((struct Node *)d[0x9A]);
    func_0204B1CC((struct Bank *)d[0x9B]);
    func_0204A5AC();
    func_020450C8();
    func_0203F9B4();
    func_020315D4((struct S020315D4 *)a);
    func_020306F0(0x1f);
    return 1;
}




/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_02197C4C(u32 a, u32 b, u32 c, u32 d)
{
if (func_0216D520((void *)a) != 0) {
    func_0219C5D0(a);
}
if (func_0216D528(a) != 0) {
    func_0219D488(a);
}
return func_0216D95C(a, 0);
}




void func_02197C78(u32 a)
{
    if (func_0216D4D4((int)func_0216D67C((void *)a), 4) == 0 && func_0216DAA0((void *)a) != 0) {
        func_0216D758((void *)a);
    }
}




int func_02197C9C(u32 a)
{
if (func_0216DB10((void *)a) != 0) {
    if (func_0216DC4C((void *)a) == 0) {
        return 1;
    }
}
if (func_0216D55C(a, 16) != 0) {
    return 1;
}
return 0;
}




/*
 * Sums five 12-byte records fetched from the actor at p into out.
 *
 * Addresses are Black-image addresses.
 */
void func_02197CCC(u8 *p, s32 *out)
{
    s32 a[3];
    s32 b[3];
    s32 c[3];
    s32 d[3];
    s32 e[3];

    func_0216D88C((const struct Actor *)p, (struct VecFx32 *)a);
    func_0216D8B0(p, (u8 *)b);
    func_0216D8D0(p, (u8 *)c);
    func_0216D8F0(p, (u8 *)d);
    func_0216D92C(p, e);
    out[0] = a[0] + b[0] + c[0] + d[0] + e[0];
    out[1] = a[1] + b[1] + c[1] + d[1] + e[1];
    out[2] = a[2] + b[2] + c[2] + d[2] + e[2];
}




void func_02197D3C(u32 p0, u32 p1)
{
    u32 h;
    u32 *r;
    u32 n;

    h = (u32)func_0216D67C((void *)p0);
    r = func_02030734((u16)(0x8000 | (func_0216D4F8((u8 *)h) & 0x7fff)), 0x14, 1, (const char *)&d_021DDBE0, 0x115);
    n = func_0216D4F4(func_0216D67C((void *)p0)) - 2;
    func_02030DA8(func_0216D514((void *)h), func_02197DCC, r, n);
    r[3] = p0;
    r[4] = p1;
}




int func_02197DA0(u32 a)
{
return ((struct Obj17950 *)((u8 *)(func_02030EE8((struct S02030EE8 *)a))))->f4;
}




void func_02197DAC(void *a)
{
    u32 *p;

    p = (u32 *)func_02030EE8(a);
    func_0216D480((char *)p[3]);
    func_020307B0(p);
    func_02030EAC(a);
}


extern int (*const d_021D4A50[])(int *);


/*
 * Byte-correct (2026-10-01).  Sole blocker: the ABS32 pool word for the
 * ov021 table is a data start that another overlay mapped over the same
 * window also starts an object at, so the symbols hint is contested.  No C
 * change needed to promote.
 *
 * 2026-10-01: the own-overlay data hint is dropped from symbols: so the
 *   own-window rule (code running in ov021 can only see ov021's bytes in its
 *   window) fixes the overlay; with the hint the tool refused it as contested.
 *
 * Addresses are Black-image addresses.
 */
void func_02197DCC(void *a, int *b)
{
    while (d_021D4A50[*b](b) == 1) {
    }
}
