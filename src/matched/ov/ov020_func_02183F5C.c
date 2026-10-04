/*
 * function: func_02183F5C
 * address:  0x02183F5C
 * packet:   pkt_ov020_02183F5C
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_020142E8  0x020142E8  thumb
 *   func_0201433C  0x0201433C  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02008B08  0x02008B08  thumb
 *   func_0201AD0C  0x0201AD0C  thumb
 *   func_02012F08  0x02012F08  thumb
 *   func_02008B4C  0x02008B4C  thumb
 *   func_02008B78  0x02008B78  thumb
 *   func_02008B14  0x02008B14  thumb
 *   func_02008C00  0x02008C00  thumb
 *   func_0216A390  0x0216A390  thumb  ov010
 *   func_0203F524  0x0203F524  arm
 *   func_0200C384  0x0200C384  thumb
 *   func_02008B20  0x02008B20  thumb
 *   func_02012984  0x02012984  thumb
 *   func_0216AAE4  0x0216AAE4  thumb  ov010
 *   func_02183DD4  0x02183DD4  thumb  ov020
 *   func_02183DE4  0x02183DE4  thumb  ov020
 *   func_02021444  0x02021444  thumb
 *   func_0208068C  0x0208068C  arm
 *   func_02082AC0  0x02082AC0  arm
 *   func_02080B98  0x02080B98  arm
 */
#include "../include/Obj02684.h"
#include "../include/Obj19450.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned long long u64;

typedef signed int     s32;
struct Big;
struct BigObj;
struct Blk34;
struct Ctx;
struct Desc;
struct Obj;
struct Sub02008AECObj;
struct Sub02008AECSession;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void *func_020120F4(const struct Ctx *p);
extern u32 func_0201296C(const struct BigObj *p);
extern u32 func_020142E8(void *bitmap, s32 id);
extern void func_0201433C(char *a0, int a1);
extern void *func_02012EBC(struct Big *p);
extern struct Sub02008AECObj *func_02008B08(void *sys);
extern void *func_0201AD0C(void *sys);
extern void *func_02012F08(int *p);
extern int func_02008B4C(const struct Sub02008AECObj *obj);
extern int func_02008B78(const struct Sub02008AECObj *obj);
extern struct Sub02008AECSession *func_02008B14(void *sys);
extern void func_02008C00(struct Sub02008AECSession *s);
extern void func_0216A390(int a, int b);
extern u64 func_0203F524();
extern void func_0200C384(struct Blk34 *p, u32 lo, u32 hi);
extern void func_02008B20(struct Sub02008AECObj *obj);
extern u8 func_02012984(const struct BigObj *p);
extern void func_0216AAE4(void *sys, void *party, int season);
extern void func_02183DD4(void *p);
extern void func_02183DE4(void);
extern void func_02021444(void);
extern void func_0208068C(int a);
extern void func_02082AC0(int v, int dst, int size);
extern void func_02080B98(void);

int func_02183F5C(int a0, u8 *a1)
{
    int t0;
    int *s;
    int r5;
    int r7;
    int r6;
    int h;
    u64 t;

    t0 = (int)func_020122C0((void *)a0, 0, (void *)((int)func_02183DE4), 0x10);
    s = func_020124E8((struct Obj *)t0);
    s[0] = a0;
    s[1] = (int)func_020120F4((const struct Ctx *)a0);
    ((struct Obj02684 *)s)->f8 = ((struct Obj19450 *)a1)->f10;
    r5 = func_0201296C((const struct BigObj *)s[1]);
    s[3] = func_020142E8((void *)r5, 0x966);
    func_0201433C((char *)r5, 0x966);
    r7 = (int)func_02012EBC((struct Big *)s[1]);
    r5 = (int)func_02008B08((void *)r7);
    r6 = (int)func_0201AD0C((void *)r7);
    h = (int)func_02012F08((int *)s[1]);
    if (!func_02008B4C((const struct Sub02008AECObj *)r5) || !func_02008B78((const struct Sub02008AECObj *)r5)) {
        func_02008C00(func_02008B14((void *)r7));
        func_0216A390(s[1], r6);
        t = func_0203F524();
        func_0200C384((struct Blk34 *)h, (u32)t, (u32)(t >> 32));
    }
    func_02008B20((struct Sub02008AECObj *)r5);
    func_0216AAE4((void *)s[1], (void *)r6, func_02012984((const struct BigObj *)s[1]));
    func_02183DD4((void *)a0);
    func_02021444();
    func_0208068C(0x1FF);
    func_02082AC0(0, 0x06800000, 0xA4000);
    func_02080B98();
    return t0;
}
