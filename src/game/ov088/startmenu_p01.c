/*
 * file:     startmenu_p01.c
 * unit:     yes
 * function: func_021B95A0, func_021B95CC, func_021B965C, func_021B9750, func_021B9874, func_021B98BC, func_021B9910, func_021B9928, func_021B9954, func_021B997C
 * address:  0x021B95A0
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203064C  0x0203064C  arm
 *   func_0203159C  0x0203159C  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_0204E720  0x0204E720  arm
 *   func_0204363C  0x0204363C  arm
 *   func_02040588  0x02040588  arm
 *   func_02043598  0x02043598  arm
 *   func_020434DC  0x020434DC  arm
 *   func_0201160C  0x0201160C  thumb
 *   func_021B9E7C  0x021B9E7C  thumb  ov088
 *   func_020362DC  0x020362DC  arm
 *   func_0203630C  0x0203630C  arm
 *   func_02006984  0x02006984  thumb
 *   func_02005E30  0x02005E30  thumb
 *   func_021B9A14  0x021B9A14  thumb  ov088
 *   func_021B9A1C  0x021B9A1C  thumb  ov088
 *   func_021B9C2C  0x021B9C2C  thumb  ov088
 *   func_021B9EC4  0x021B9EC4  thumb  ov088
 *   func_021B9F70  0x021B9F70  thumb  ov088
 *   func_021B9E54  0x021B9E54  thumb  ov088
 *   func_021B9C08  0x021B9C08  thumb  ov088
 *   func_021B99EC  0x021B99EC  thumb  ov088
 *   func_0204E804  0x0204E804  arm
 *   func_02005DAC  0x02005DAC  thumb
 *   func_02006BD0  0x02006BD0  thumb
 *   func_02005E50  0x02005E50  thumb
 *   func_02005D28  0x02005D28  thumb
 *   func_020315D4  0x020315D4  arm
 *   func_020306F0  0x020306F0  arm
 *   func_020312F8  0x020312F8  arm
 *   d_021BD66C     0x021BD66C  data  a4
 *   d_021BD974     0x021BD974  data  a4
 *   d_02184904     0x02184904  data  a4  ov168
 *   ov088_id       0x00000058  data  a1
 *   ov168_id       0x000000A8  data  a1
 *   func_0207D534  0x0207D534  arm
 *   func_02043534  0x02043534  arm
 *   func_020435F4  0x020435F4  arm
 *   func_020433E0  0x020433E0  arm
 *   func_0203FC28  0x0203FC28  arm
 *   d_021BD508     0x021BD508  data  a4  ov088
 *   d_021BD420     0x021BD420  data  a4  ov088
 *   func_021B99E0  0x021B99E0  thumb  ov088
 *   func_021B9BD4  0x021B9BD4  thumb  ov088
 *   func_021B9DD0  0x021B9DD0  thumb  ov088
 *   func_021B9F68  0x021B9F68  thumb  ov088
 *   func_0204A648  0x0204A648  arm
 *   func_0203F8F4  0x0203F8F4  arm
 *   func_02045088  0x02045088  arm
 *   func_02046440  0x02046440  arm
 *   func_0201DD60  0x0201DD60  thumb
 *   func_0203101C  0x0203101C  arm
 *   func_020056A0  0x020056A0  thumb
 *   func_0204361C  0x0204361C  arm
 */
#include "../../matched/include/Obj20810.h"
#include "../../matched/include/Obj00462.h"
#include "../../matched/include/Obj07719.h"

struct Obj0203159C;
struct Obj11245;
struct S020315D4;
struct DispConfig;
struct DispVram;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

typedef unsigned char  u8;

extern void func_0203064C(unsigned int a, unsigned int heap, unsigned int size);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void  func_02082BCC(void *p, int v, int n);
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern void func_0204363C(u32 swap);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02043598(u32 mask, u32 enable);
extern void func_020434DC(u32 mask, u32 enable);
extern u32 func_0201160C(struct Obj11245 *p);
extern void func_021B9E7C(int *p, int x);
extern u32   func_020362DC(void);
extern unsigned int func_0203630C(void);
extern u32 func_02006984(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);
extern void func_02005E30(u32 a);
extern void  func_021B9A14(u16 *p, u16 a, u16 b);
extern void func_021B9A1C(void *p, int heap);
extern void func_021B9C2C(void *p, int heap);
extern void func_021B9EC4(int *p, int heap);
extern void func_021B9F70(int *p);
extern void func_021B9E54(int *p);
extern void func_021B9C08(int *p);
extern void func_021B99EC(int *p);
extern int  func_0204E804(void);
extern void func_02005DAC(void *arg);
extern u32  func_02006BD0(u32 a);
extern int  func_02005E50(void);
extern void func_02005D28(void);
extern void func_020315D4(struct S020315D4 *a);
extern void func_020306F0(unsigned int a);
extern void func_020312F8(u32 a1, u32 a2, u32 a3);
extern void func_0207D534(volatile u16 *reg, int brightness);
extern void func_02043534(u32 planes);
extern void func_020435F4(u32 planes);
extern void func_020433E0(const struct DispVram *c);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_021B99E0(void *, unsigned short);
extern void func_021B9BD4(void *, unsigned short);
extern void func_021B9DD0(void *, unsigned short);
extern void func_021B9F68(void *, unsigned short);
extern void func_0204A648(void);
extern void func_0203F8F4(int);
extern void func_02045088(int);
extern void func_02046440(int, int, int, int, int, int, int);
extern void func_0201DD60(void);
extern void *func_0203101C(int, int, int, int);
extern void *func_020056A0(void *, void *, int);
extern void func_0204361C(void);
int func_021B95A0(struct Obj0203159C *a0);
void func_021B95CC(char *p);
void func_021B965C(char *p);
int func_021B9750(int a0, int a1, int a2, char *p);
int func_021B9874(int a0, int a1, int a2, int *a3);
void func_021B98BC(void);
void func_021B9910(void);
void func_021B9928(unsigned char *p);
void func_021B9954(void *task, short *p);
void func_021B997C(int *p, int heap);
extern char d_021BD66C[];
extern char d_021BD974[];
extern char d_02184904[];
extern char ov088_id[];
extern char ov168_id[];
extern char d_021BD508[];
extern char d_021BD420[];


int func_021B95A0(struct Obj0203159C *a0)
{
    char *p;

    func_0203064C(1, 0x16, 0x120000);
    p = func_0203159C(a0, 0x98, 0x16);
    func_02082BCC(p, 0, 0x98);
    ((struct Obj20810 *)p)->f2 = 0x16;
    return 1;
}


void func_021B95CC(char *p)
{
    if (((struct Obj00462 *)p)->f8C == 0x29A) {
        func_0204E720(12, 16, 0, 3);
        func_0204363C(1);
        func_02040588(6, 0);
        func_02043598(16, 0);
        func_020434DC(8, 0);
        ((struct Obj00462 *)p)->f94 = 1;
    }
    if (((struct Obj00462 *)p)->f94 == 2 && func_0201160C((struct Obj11245 *)(((struct Obj00462 *)p)->f4C)) == 0x015F3000)
        func_021B9E7C((int *)(p + 0x40), 0x14B5);
    ((struct Obj00462 *)p)->f8C += 1;
    if (((struct Obj00462 *)p)->f8C > 0x1248) {
        ((struct Obj00462 *)p)->f4 = 1;
        ((struct Obj00462 *)p)->f0 = 5;
    }
}


void func_021B965C(char *p)
{
    if ((func_020362DC() & 0xB) && ((struct Obj00462 *)p)->f94 == 1) {
        func_0204363C(0);
        func_02040588(6, 1);
        func_02040588(3, 1);
        func_02043598(0x10, 1);
        func_021B9E7C((int *)(p + 0x40), 0x14B5);
        ((struct Obj00462 *)p)->f94 = 2;
        return;
    }
    if (func_020362DC() & 9) {
        ((struct Obj00462 *)p)->f4 = 0;
        ((struct Obj00462 *)p)->f0 = 4;
        ((struct Obj00462 *)p)->f90 = (void *)func_02006984(0x283, 0, 0x40, 0, 0, 0, 0, 0);
        func_021B9E7C((int *)(p + 0x40), 0x1389);
        func_0204363C(0);
        func_02040588(6, 1);
        func_02043598(0x10, 0);
        func_0204E720(0xC, 0x10, 0, 3);
        func_02005E30(4);
        func_021B9A14((u16 *)(p + 8), 8, 8);
        return;
    }
    if (func_0203630C() == 0x46) {
        ((struct Obj00462 *)p)->f4 = 2;
        ((struct Obj00462 *)p)->f0 = 5;
    } else if (func_0203630C() == 0xC80) {
        ((struct Obj00462 *)p)->f4 = 3;
        ((struct Obj00462 *)p)->f0 = 5;
    }
}


int func_021B9750(int a0, int a1, int a2, char *p)
{
    switch (((struct Obj00462 *)p)->f0) {
    case 0:
        func_021B98BC();
        func_021B9910();
        ((struct Obj00462 *)p)->f0 = 1;
        break;
    case 1:
        func_021B997C((int *)(p + 8), ((struct Obj00462 *)p)->f2);
        func_021B9A1C(p + 0x14, ((struct Obj00462 *)p)->f2);
        func_021B9C2C(p + 0x40, ((struct Obj00462 *)p)->f2);
        func_021B9EC4((int *)(p + 0x54), ((struct Obj00462 *)p)->f2);
        func_0204E720(3, 0x10, 0, 2);
        ((struct Obj00462 *)p)->f8C = 0;
        ((struct Obj00462 *)p)->f0 = 2;
        func_02005DAC((void *)0x3EF);
        break;
    case 2:
        if (func_0204E804() == 0) {
            ((struct Obj00462 *)p)->f0 = 3;
        }
        func_021B9928((unsigned char *)p);
        break;
    case 3:
        func_021B9928((unsigned char *)p);
        func_021B965C(p);
        func_021B95CC(p);
        break;
    case 4:
        if (func_02006BD0(*(u32 *)&((struct Obj00462 *)p)->f90) == 0) {
            ((struct Obj00462 *)p)->f0 = 5;
        }
        func_021B9928((unsigned char *)p);
        break;
    case 5:
        func_0204E720(3, 0, 0x10, 2);
        ((struct Obj00462 *)p)->f0 = 6;
        func_021B9928((unsigned char *)p);
        func_02005E30(0x10);
        break;
    case 6:
        if (func_0204E804() == 0 && func_02005E50() == 0) {
            func_02005D28();
            ((struct Obj00462 *)p)->f0 = 7;
        }
        func_021B9928((unsigned char *)p);
        break;
    case 7:
        func_021B9F70((int *)(p + 0x54));
        func_021B9E54((int *)(p + 0x40));
        func_021B9C08((int *)(p + 0x14));
        func_021B99EC((int *)(p + 8));
        return 1;
    case 8:
        return 1;
    }
    return 0;
}


int func_021B9874(int a0, int a1, int a2, int *a3)
{
    int t = a3[1];

    func_020315D4((struct S020315D4 *)a0);
    func_020306F0(0x16);
    if (t == 0) {
        func_020312F8((u32)ov088_id, (u32)d_021BD66C, 0);
    } else if (t == 2) {
        func_020312F8((u32)ov088_id, (u32)d_021BD974, 0);
    } else if (t == 3) {
        func_020312F8((u32)ov168_id, (u32)d_02184904, 0);
    }
    return 1;
}


void func_021B98BC(void)
{
    func_0207D534((volatile u16 *)0x0400006C, -16);
    func_0207D534((volatile u16 *)0x0400106C, -16);
    func_02043534(0);
    func_020435F4(0);
    *(u16 *)0x04000050 = 0;
    *(u16 *)0x04001050 = 0;
    *(u32 *)0x04000000 &= 0xFFFF1FFF;
    *(u32 *)0x04001000 &= 0xFFFF1FFF;
}


void func_021B9910(void)
{
    func_020433E0((const struct DispVram *)d_021BD508);
    func_0203FC28((struct DispConfig *)d_021BD420);
}


void func_021B9928(unsigned char *p)
{
    func_021B99E0(p + 0x08, ((struct Obj07719 *)p)->f2);
    func_021B9BD4(p + 0x14, ((struct Obj07719 *)p)->f2);
    func_021B9DD0(p + 0x40, ((struct Obj07719 *)p)->f2);
    func_021B9F68(p + 0x54, ((struct Obj07719 *)p)->f2);
}


void func_021B9954(void *task, short *p)
{
    func_0204A648();
    *(volatile unsigned int *)0x04000064 = p[4] | (0xC0330000 | (p[5] << 8));
}


void func_021B997C(int *p, int heap)
{
    func_0203F8F4(heap);
    func_02045088(heap);
    func_02046440(0, 2, 0, 2, 0x1000, heap, 0);
    func_0201DD60();
    p[0] = (int)func_0203101C(heap, heap, 4, 0x20);
    p[1] = (int)func_020056A0((void *)func_021B9954, p, 5);
    func_0204363C(0);
    func_0204361C();
    ((unsigned short *)p)[4] = 12;
    ((unsigned short *)p)[5] = 4;
}
