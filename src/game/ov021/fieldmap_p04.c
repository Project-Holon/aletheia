/*
 * file:     fieldmap_p04.c
 * unit:     yes
 * function: func_021885E8, func_02188758, func_021888C8, func_02188910, func_02188990, func_02188AD4, func_02188B58
 * address:  0x021885E8
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
 *   func_0218CA78  0x0218CA78  thumb  ov021
 *   func_0216CD64  0x0216CD64  thumb  ov010
 *   func_0219C624  0x0219C624  thumb  ov021
 *   func_0219C630  0x0219C630  thumb  ov021
 *   func_021A1B50  0x021A1B50  thumb  ov021
 *   func_021A1AF4  0x021A1AF4  thumb  ov021
 *   func_02189004  0x02189004  thumb  ov021
 *   func_02189084  0x02189084  thumb  ov021
 *   func_021890AC  0x021890AC  thumb  ov021
 *   func_0204A600  0x0204A600  arm
 *   func_021903E0  0x021903E0  thumb  ov021
 *   func_021ABE04  0x021ABE04  thumb  ov021
 *   func_021BB948  0x021BB948  thumb  ov021
 *   func_02012B38  0x02012B38  thumb
 *   func_02014460  0x02014460  thumb
 *   func_02189B04  0x02189B04  thumb  ov021
 *   func_02005C64  0x02005C64  thumb
 *   func_02014458  0x02014458  thumb
 *   func_02158AC8  0x02158AC8  thumb  ov010
 *   func_02014454  0x02014454  thumb
 *   func_02158AD4  0x02158AD4  thumb  ov010
 *   func_0201445C  0x0201445C  thumb
 *   func_02013CC8  0x02013CC8  thumb
 *   func_02013CE0  0x02013CE0  thumb
 *   func_02188CF0  0x02188CF0  thumb  ov021
 *   func_0201209C  0x0201209C  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_020129DC  0x020129DC  thumb
 *   func_0218A0E4  0x0218A0E4  thumb  ov021
 *   func_0218A240  0x0218A240  thumb  ov021
 *   func_0218A4BC  0x0218A4BC  thumb  ov021
 *   func_0218A074  0x0218A074  thumb  ov021
 *   func_02012104  0x02012104  thumb
 *   func_0201447C  0x0201447C  thumb
 *   func_02012E40  0x02012E40  thumb
 *   func_02035648  0x02035648  arm
 *   func_021892CC  0x021892CC  thumb  ov021
 *   func_020120D8  0x020120D8  thumb
 *   func_02168EEC  0x02168EEC  thumb  ov010
 *   func_021BC484  0x021BC484  thumb  ov021
 *   func_021C7FAC  0x021C7FAC  thumb  ov021
 *   func_021A2EB8  0x021A2EB8  thumb  ov021
 *   func_02012138  0x02012138  thumb
 *   func_021737A4  0x021737A4  thumb  ov012
 *   func_0217AE20  0x0217AE20  thumb  ov018
 *   func_021A0D68  0x021A0D68  thumb  ov021
 *   func_021BE258  0x021BE258  thumb  ov021
 *   func_0217F914  0x0217F914  thumb  ov018
 *   func_02030D28  0x02030D28  arm
 *   func_021C6D90  0x021C6D90  thumb  ov021
 *   func_0218D158  0x0218D158  thumb  ov021
 *   func_02012ED0  0x02012ED0  thumb
 *   func_021C8660  0x021C8660  thumb  ov021
 *   func_02047CE4  0x02047CE4  arm
 *   func_0203630C  0x0203630C  arm
 *   func_0218E104  0x0218E104  thumb  ov021
 *   func_02189A80  0x02189A80  thumb  ov021
 *   func_020129F0  0x020129F0  thumb
 *   func_0218CC34  0x0218CC34  thumb
 *   func_021A0E58  0x021A0E58  thumb
 *   func_021BC4F0  0x021BC4F0  thumb
 *   func_021CF480  0x021CF480  thumb  ov021
 *   func_021C1C04  0x021C1C04  thumb  ov021
 *   func_021C1AD0  0x021C1AD0  thumb  ov021
 *   func_021BB90C  0x021BB90C  thumb  ov021
 *   func_020263B0  0x020263B0  thumb
 *   func_021BC424  0x021BC424  thumb  ov021
 *   func_021BE218  0x021BE218  thumb  ov021
 *   func_021BE2E0  0x021BE2E0  thumb  ov021
 *   func_021A9F28  0x021A9F28  thumb  ov021
 *   func_021A0D44  0x021A0D44  thumb  ov021
 *   func_020129B8  0x020129B8  thumb
 *   func_021ABDE8  0x021ABDE8  thumb  ov021
 *   func_0217F8EC  0x0217F8EC  thumb  ov019
 *   func_021A1AAC  0x021A1AAC  thumb  ov021
 *   func_021A0448  0x021A0448  thumb  ov021
 *   func_021A02F4  0x021A02F4  thumb  ov021
 *   func_021A0138  0x021A0138  thumb  ov021
 *   func_021D33E0  0x021D33E0  thumb  ov021
 *   func_021BB240  0x021BB240  thumb  ov021
 *   func_021AB81C  0x021AB81C  thumb  ov021
 *   func_021AB624  0x021AB624  thumb  ov021
 *   func_0218E0E4  0x0218E0E4  thumb  ov021
 *   func_021895DC  0x021895DC  thumb  ov021
 *   func_021892B4  0x021892B4  thumb  ov021
 *   func_021A2E90  0x021A2E90  thumb  ov021
 *   func_0218D05C  0x0218D05C  thumb  ov021
 *   func_02190728  0x02190728  thumb  ov021
 *   func_021902BC  0x021902BC  thumb  ov021
 *   func_02035660  0x02035660  arm
 *   func_021C31FC  0x021C31FC  thumb  ov021
 *   func_021C7F9C  0x021C7F9C  thumb  ov021
 *   func_02030DA4  0x02030DA4  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02030EAC  0x02030EAC  arm
 *   func_0204A5AC  0x0204A5AC  arm
 *   func_020450C8  0x020450C8  arm
 *   func_02034A5C  0x02034A5C  arm
 *   func_021D31A4  0x021D31A4  thumb
 *   func_021C6D5C  0x021C6D5C  thumb
 *   func_0218CA4C  0x0218CA4C  thumb
 *   func_021890C8  0x021890C8  thumb
 *   func_02188E38  0x02188E38  thumb
 *   abs_id_13  0x00000013  data
 *   abs_id_12  0x00000012  data
 *   data_021D36B8  0x021D36B8  data  a4
 */
#include "../../matched/include/Obj00611.h"
#include "../../matched/include/Obj00518.h"
#include "../../matched/include/Obj12555.h"
#include "../../matched/include/Obj04193.h"
#include "../../matched/include/Obj00401.h"
#include "../../matched/include/Obj03103.h"
#include "../../matched/include/Obj02685.h"

struct BigObj;
struct Obj;
struct Ctx;
struct Sub02014444Obj;
struct Obj00020;
struct T;
struct V3;
struct Node;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {
    u32 w[3];
} Rec12;

typedef signed char    s8;

typedef signed short   s16;

typedef signed int     s32;

typedef u32 (*Fn)(void *a, void *b);

extern void func_0218CA78(char *p);
extern int func_0216CD64(int a0);
extern int func_0219C624(void *p);
extern int func_0219C630(void *p);
extern int func_021A1B50(u32 a);
extern void func_021A1AF4(u8 *p, int x);
extern void func_02189004(u8 *p);
extern void func_02189084(u8 *p);
extern void func_021890AC(u8 *p);
extern void func_0204A600(void);
extern void func_021903E0(struct Obj *o);
extern void func_021ABE04(u32 a);
extern void func_021BB948(u8 *p);
extern void *func_02012B38(const struct BigObj *p);
extern u8 func_02014460(struct Sub02014444Obj *o);
extern int func_02189B04(int x);
extern int func_02005C64(void);
extern u8 func_02014458(struct Sub02014444Obj *o);
extern void func_02158AC8(int a, int b);
extern void func_02014454(struct Sub02014444Obj *o, u8 v);
extern void func_02158AD4(int a, int b);
extern void func_0201445C(struct Sub02014444Obj *o, u8 v);
extern u32 func_02013CC8(u32 id);
extern u32 func_02013CE0(u32 id);
extern int func_02188CF0(u32 a);
extern void func_0201209C(void *o, u32 v1, u32 v2);
extern void *func_020120F4(const struct Ctx *p);
extern void func_020129DC(struct BigObj *p, u8 v);
extern int func_0218A0E4(void *sys, struct Obj00020 *pos);
extern int func_0218A240(void *p, struct Obj00020 *pos);
extern int func_0218A4BC(u32 a, u32 b, u32 c, u32 d);
extern int func_0218A074(void *a, int b);
extern u32 func_02012104(const struct Ctx *p);
extern u8 func_0201447C(struct Sub02014444Obj *o, u8 v);
extern u8 func_02012E40(const u8 *o);
extern void func_02035648(void);
extern u32 func_021892CC(u8 *a);
extern int func_020120D8(char *a);
extern void func_02168EEC(int a);
extern void func_021BC484(u32 a);
extern void func_021C7FAC(u32 a);
extern void func_021A2EB8(u32 *a);
extern u32 func_02012138(const struct Ctx *a);
extern void func_021737A4(void *a, int b);
extern void func_0217AE20(u8 *a0, int a1, int a2);
extern void func_021A0D68(u32 *a);
extern void func_021BE258(void *p);
extern void func_0217F914(u32 a);
extern void func_02030D28(struct Ctx *c);
extern void func_021C6D90(u8 *p);
extern void func_0218D158(struct T *dst, const struct V3 *src);
extern u32 *func_02012ED0(u32 a);
extern void func_021C8660(u32 a);
void func_02047CE4(void);
unsigned int func_0203630C(void);
void func_0218E104(u8 *a, u32 b);
int func_02189A80(char *p);
extern void func_020129F0(struct BigObj *p);
extern void func_0218CC34(u32 a);
extern void func_021A0E58(u32 *a);
extern void func_021BC4F0(int a);
extern int func_021CF480(void *a);
extern void func_021C1C04(u32 *p);
extern void func_021C1AD0(u32 a);
extern void func_021BB90C(u32 a);
extern void func_020263B0(struct Obj *p, u32 a);
extern void func_021BC424(u32 a);
extern void func_021BE218(void *arg);
extern void func_021BE2E0(u32 a);
extern void func_021A9F28(u32 a);
extern u8 func_021A0D44(u32 *p);
extern void func_020129B8(struct BigObj *p, u32 v);
extern void func_021ABDE8(u32 a);
extern void func_0217F8EC(char *p);
extern void func_021A1AAC(u8 *p);
extern void func_021A0448(u8 *p);
extern int func_021A02F4(void *a);
extern void func_021A0138(u32 a);
extern void func_021D33E0(u32 *p);
extern int func_021BB240(u32 a);
extern void func_021AB81C(u32 a);
extern void func_021AB624(u8 *p);
extern void func_0218E0E4(u8 *a);
extern int func_021895DC(u32 a);
extern int func_021892B4(u8 *a);
extern int func_021A2E90(void *a);
extern void func_0218D05C(char *p);
extern int func_02190728(void *a);
extern void func_021902BC(struct Obj *o);
extern void func_02035660(u32 a);
extern void func_021C31FC(u32 a);
extern void func_021C7F9C(u8 *p);
extern void func_02030DA4(u32 a);
extern u32 func_020307B0(void *p);
extern void func_02030EAC(struct Node *n);
extern void func_0204A5AC(void);
extern void func_020450C8(void);
extern void func_02034A5C(s32 handle);
extern void func_021D31A4(u32 a);
extern void func_021C6D5C(u32 a);
extern int func_0218CA4C(void *a);
extern void func_021890C8(void *a);
extern void func_02188E38(void *a);
int func_021885E8(void *a, u8 *p);
int func_02188758(void *a, u8 *p);
void func_021888C8(char *o);
u32 func_02188910(void *a, u8 *b);
int func_02188990(void *a, u8 *p);
u32 func_02188AD4(void *a, u8 *b);
u32 func_02188B58(void *a, u8 *b, u32 a2, u32 a3);
extern u8 abs_id_13[];
extern u8 abs_id_12[];
extern Fn data_021D36B8[][2];


/*
 * Addresses are Black-image addresses.
 */
int func_021885E8(void *a, u8 *p)
{
    switch (p[0xC8]) {
    case 0:
        func_0218CA78((char *)(((struct Obj00611 *)p)->f48));
        if (((struct Obj00611 *)p)->f38 != 0) {
            do {
                func_0216CD64(((struct Obj00611 *)p)->f38);
                func_0219C624((void *)(((struct Obj00611 *)p)->f38));
            } while (func_0219C630((void *)(((struct Obj00611 *)p)->f38)) == 1);
        }
        while (func_021A1B50(((struct Obj00611 *)p)->f20) != 0)
            func_021A1AF4((u8 *)(((struct Obj00611 *)p)->f20), 0x92);
        func_02189004(p);
        func_02189084(p);
        func_021890AC(p);
        func_0204A600();
        if (((struct Obj00611 *)p)->f28 != 0)
            func_021903E0((struct Obj *)(((struct Obj00611 *)p)->f28));
        func_021ABE04(((struct Obj00611 *)p)->f94);
        func_021BB948((u8 *)(((struct Obj00611 *)p)->fBC));
        p[0xC8]++;
    case 1:
        if (func_02014460(func_02012B38((const struct BigObj *)(((struct Obj00611 *)p)->f8))) == 1
            && func_02189B04(((struct Obj00611 *)p)->fD0) == 1
            && func_02005C64() != 0)
            return 0;
        if (func_02014458(func_02012B38((const struct BigObj *)(((struct Obj00611 *)p)->f8))) != 0) {
            func_02158AC8(((struct Obj00611 *)p)->f4, ((struct Obj00611 *)p)->f0);
            func_02014454(func_02012B38((const struct BigObj *)(((struct Obj00611 *)p)->f8)), 0);
        } else {
            func_02158AD4(((struct Obj00611 *)p)->f4, ((struct Obj00611 *)p)->f0);
        }
        func_0201445C(func_02012B38((const struct BigObj *)(((struct Obj00611 *)p)->f8)), 0);
        func_0218CA78((char *)(((struct Obj00611 *)p)->f48));
        if (func_02013CC8(((struct Obj00611 *)p)->fD0) == 1 || func_02013CE0(((struct Obj00611 *)p)->fD0) == 1)
            func_0201209C(a, (u32)func_0218A0E4, (u32)p);
        else if (func_02188CF0((u32)p) == 1)
            func_0201209C(a, (u32)func_0218A240, (u32)p);
        else if (func_02188CF0((u32)p) == 2)
            func_0201209C(a, (u32)func_0218A4BC, (u32)p);
        else
            func_0201209C(a, (u32)func_0218A074, (u32)p);
        ((struct Obj00611 *)p)->fC0 = 1;
        func_020129DC(func_020120F4(a), 1);
        break;
    }
    return 1;
}


int func_02188758(void *a, u8 *p)
{
    if (func_02012104((const struct Ctx *)(((struct Obj00518 *)p)->f4)) == 0)
        func_0201447C(func_02012B38((const struct BigObj *)(((struct Obj00518 *)p)->f8)), 0);
    if (func_02012E40((const u8 *)(((struct Obj00518 *)p)->f8)) != 0)
        return 0;
    if (((struct Obj00518 *)p)->f140 != 0) {
        func_021888C8((char *)p);
        func_0204A600();
        return 0;
    }
    func_02035648();
    func_021892CC(p);
    if (func_020120D8(a) == 0) {
        (*(void (**)(u8 *, void *))(*(u8 **)(p + 0x108) + 8))(p, p + 0xF4);
        func_02168EEC(((struct Obj00518 *)p)->f8);
    }
    if (((struct Obj00518 *)p)->f30 != 0)
        func_021BC484(((struct Obj00518 *)p)->f30);
    func_021C7FAC(((struct Obj00518 *)p)->fA0);
    func_021A2EB8((u32 *)(((struct Obj00518 *)p)->f8C));
    if (func_02013CC8(((struct Obj00518 *)p)->fD0) == 1 || func_02013CE0(((struct Obj00518 *)p)->fD0) == 1)
        func_021737A4((void *)((void *)func_02012138(a)), (int)p);
    else
        func_0217AE20((u8 *)p, ((struct Obj00518 *)p)->f4, ((struct Obj00518 *)p)->f8C);
    func_021A0D68((u32 *)(((struct Obj00518 *)p)->f24));
    if (((struct Obj00518 *)p)->f38 != 0) {
        *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 & ~0x8000;
        func_0216CD64(((struct Obj00518 *)p)->f38);
        *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 | 0x8000;
    }
    func_021BE258(p);
    func_021ABE04(((struct Obj00518 *)p)->f94);
    if (((struct Obj00518 *)p)->f98 != 0)
        func_0217F914(((struct Obj00518 *)p)->f98);
    func_021BB948((u8 *)(((struct Obj00518 *)p)->fBC));
    if (((struct Obj00518 *)p)->f28 != 0)
        func_021903E0((struct Obj *)(((struct Obj00518 *)p)->f28));
    func_02030D28((struct Ctx *)(((struct Obj00518 *)p)->f110));
    func_021C6D90((u8 *)(((struct Obj00518 *)p)->f134));
    if (*(Rec12 * *)&((struct Obj00518 *)p)->fF0 != 0)
        *(Rec12 *)(p + 0xF4) = **(Rec12 * *)&((struct Obj00518 *)p)->fF0;
    func_0218D158((struct T *)(((struct Obj00518 *)p)->f48), (const struct V3 *)(p + 0xF4));
    func_02189004(p);
    func_021C8660(*func_02012ED0(((struct Obj00518 *)p)->f8));
    func_0204A600();
    func_021888C8((char *)p);
    return 0;
}


void func_021888C8(char *o)
{
    volatile u16 *r = (volatile u16 *)0x04000204;

    func_02047CE4();
    func_0218E104((u8 *)(((struct Obj12555 *)o)->f10), (u16)func_0203630C());
    ((struct Obj12555 *)o)->f100 = func_02189A80(o);
    *r = *r & 0xFFFF7FFF;
    func_02189084((unsigned char *)o);
    *r = *r | 0x8000;
}


u32 func_02188910(void *a, u8 *b)
{
    if (func_02012E40((const u8 *)(((struct Obj04193 *)b)->f8)) != 0) {
        func_020129F0(func_020120F4(a));
        return 0;
    }
    *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 & ~0x8000;
    func_0218CC34(((struct Obj04193 *)b)->f48);
    *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 | 0x8000;
    func_021A0E58((u32 *)(((struct Obj04193 *)b)->f24));
    if (((struct Obj04193 *)b)->f28 != 0)
        func_021903E0((struct Obj *)((struct Obj04193 *)b)->f28);
    if (((struct Obj04193 *)b)->f30 != 0)
        func_021BC4F0((int)((struct Obj04193 *)b)->f30);
    *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 & ~0x8000;
    func_021890AC(b);
    *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 | 0x8000;
    func_020129F0(func_020120F4(a));
    return 0;
}


int func_02188990(void *a, u8 *p)
{
    func_021CF480((void *)(((struct Obj00401 *)p)->f13C));
    func_021C1C04((u32 *)(((struct Obj00401 *)p)->f124));
    func_021C1AD0(((struct Obj00401 *)p)->f120);
    func_0201209C(a, 0, 0);
    func_021A2EB8((u32 *)(((struct Obj00401 *)p)->f8C));
    func_021BB90C(((struct Obj00401 *)p)->fBC);
    func_020263B0((void *)func_02012138(a), (u32)p);
    if (((struct Obj00401 *)p)->f30 != 0)
        func_021BC424(((struct Obj00401 *)p)->f30);
    func_021BE218(p);
    func_021BE2E0(((struct Obj00401 *)p)->f34);
    func_021A9F28(((struct Obj00401 *)p)->f90);
    func_020129B8(func_020120F4(a), func_021A0D44((u32 *)(((struct Obj00401 *)p)->f24)));
    func_021ABDE8(((struct Obj00401 *)p)->f94);
    if (((struct Obj00401 *)p)->f98 != 0) {
        func_0217F8EC((char *)(((struct Obj00401 *)p)->f98));
        ((struct Obj00401 *)p)->f98 = 0;
    }
    func_021A1AAC((u8 *)(((struct Obj00401 *)p)->f20));
    ((struct Obj00401 *)p)->f20 = 0;
    func_021A0448((u8 *)(((struct Obj00401 *)p)->f14));
    func_021A02F4((void *)(((struct Obj00401 *)p)->f1C));
    func_021A0138(((struct Obj00401 *)p)->f18);
    func_021D33E0((u32 *)(((struct Obj00401 *)p)->f9C));
    func_021BB240(((struct Obj00401 *)p)->f3C);
    func_021AB81C(((struct Obj00401 *)p)->f44);
    func_021AB624((u8 *)(((struct Obj00401 *)p)->f40));
    func_0218E0E4((u8 *)(((struct Obj00401 *)p)->f10));
    (*(void (**)(u8 *))(*(u8 **)(p + 0x108) + 0xC))(p);
    func_021895DC((u32)p);
    func_021892B4(p);
    func_021A2E90((void *)(((struct Obj00401 *)p)->f8C));
    func_0218D05C((char *)(((struct Obj00401 *)p)->f48));
    if (((struct Obj00401 *)p)->f2C != 0)
        func_02190728((void *)(((struct Obj00401 *)p)->f2C));
    if (((struct Obj00401 *)p)->f28 != 0)
        func_021902BC((struct Obj *)(((struct Obj00401 *)p)->f28));
    func_020129DC(func_020120F4(a), 0);
    func_02035660(0x3C);
    func_021C31FC(((struct Obj00401 *)p)->f128);
    func_021C7F9C((u8 *)(((struct Obj00401 *)p)->fA0));
    return 1;
}


u32 func_02188AD4(void *a, u8 *b)
{
    func_02030DA4(((struct Obj03103 *)b)->f110);
    func_020307B0((void *)(((struct Obj03103 *)b)->f114));
    func_021D31A4(((struct Obj03103 *)b)->f14C);
    ((struct Obj03103 *)b)->f14C = 0;
    func_021C6D5C(((struct Obj03103 *)b)->f134);
    func_02030EAC((struct Node *)(((struct Obj03103 *)b)->fAC));
    func_0218CA4C((void *)(((struct Obj03103 *)b)->f48));
    func_021890C8(b);
    func_0204A5AC();
    func_020450C8();
    func_02188E38(b);
    if (func_02013CC8(((struct Obj03103 *)b)->fD0) == 1 || func_02013CE0(((struct Obj03103 *)b)->fD0) == 1)
        func_02034A5C((s32)abs_id_13);
    else
        func_02034A5C((s32)abs_id_12);
    return 2;
}


u32 func_02188B58(void *a, u8 *b, u32 a2, u32 a3)
{
    u32 c = ((struct Obj02685 *)b)->fCC;
    s32 r = 0;
    Fn f;
    Fn *row;

    ((struct Obj02685 *)b)->fCC = c + 1;
    row = data_021D36B8[((struct Obj02685 *)b)->fC4];
    f = row[b[0xC9]];
    if (f != 0)
        r = f(a, b);
    switch (r) {
    case 0:
        b[0xC9] = (b[0xC9] == 0);
        break;
    case 1:
        ((struct Obj02685 *)b)->fC4 = ((struct Obj02685 *)b)->fC4 + 1;
        b[0xC8] = 0;
        b[0xC9] = 0;
        break;
    case 2:
        return 1;
    }
    return 0;
}
