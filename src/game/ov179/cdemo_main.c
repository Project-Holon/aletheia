/*
 * file:     cdemo_main.c
 * unit:     yes
 * function: func_021B6100, func_021B6138, func_021B614C, func_021B615C, func_021B616C, func_021B6220, func_021B622C, func_021B6248, func_021B624C, func_021B6268
 * address:  0x021B6100
 * region:   ov179
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm
 *   PROCSYS_AllocProcWork  0x0203159C  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   func_021B6380  0x021B6380  thumb  ov179
 *   func_020315D4  0x020315D4  arm
 *   func_020306F0  0x020306F0  arm
 *   BG_SYS_SetVramBanks  0x020433E0  arm
 *   func_0207D4B0 0x0207D4B0 arm
 *   BUTTON_MAN_RotScaleMtx22 0x02051E74 arm
 *   func_0207D59C 0x0207D59C arm
 *   func_02030734 0x02030734 arm
 *   func_0207EB78 0x0207EB78 arm
 *   func_0207ECF0 0x0207ECF0 arm
 *   func_020307B0 0x020307B0 arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   d_021B6B00 0x021B6B00 data a4
 *   d_021B68E4  0x021B68E4  data  a4
 *   func_020056A0  0x020056A0  thumb
 *   func_02030EAC  0x02030EAC  arm
 */
#include "../../matched/include/Obj14383.h"
#include "../../matched/include/Obj10716.h"
#include "../../matched/include/Obj24463.h"
#include "../../matched/include/Obj24464.h"
#include "../../matched/include/Obj24465.h"

struct Obj0203159C;
struct S020315D4;
struct DispVram;
struct Mtx22;
struct Node;
typedef unsigned int u32;

typedef struct {int m[4];} Mtx;

typedef unsigned char  u8;

extern void GFL_HEAP_CreateChildHeap(u32 a, u32 b, u32 c);
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *p, u32 v, u32 n);
extern int func_021B6380(char *p);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int heap);
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void func_0207D4B0(int,int,int);
extern void BUTTON_MAN_RotScaleMtx22(struct Mtx22 *mtx, unsigned int ang, const void *v1, const void *v2, u8 mode);
extern void func_0207D59C(void *,const Mtx *,int,int,int,int);
extern void *func_02030734(unsigned int,unsigned int,int,const char *,unsigned short);
extern void func_0207EB78(void *,int,int);
extern void func_0207ECF0(void *,int,int);
extern unsigned int func_020307B0(void *p);
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern int func_020056A0(void *, int *, int);
extern void func_02030EAC(struct Node *n);
int func_021B6100(struct Obj0203159C *p, u32 b, u32 c);
int func_021B6138(int a, int b, int c, int d);
int func_021B614C(void *p);
void func_021B615C(void);
void func_021B616C(char *unused);
void func_021B6220(void);
void func_021B622C(char *p);
void func_021B6248(char *p);
void func_021B624C(int *p);
void func_021B6268(char *p);
extern unsigned char d_021B6B00[];
extern int d_021B68E4[];


int func_021B6100(struct Obj0203159C *p, u32 b, u32 c)
{
    char *r;

    GFL_HEAP_CreateChildHeap(1, 0x7f, 0x80000);
    r = PROCSYS_AllocProcWork(p, (u32)((void *)0x605c), 0x7f);
    MI_CpuFill8(r, 0, 0x605c);
    ((struct Obj14383 *)r)->f0 = c;
    *(u32 *)(r + 0x605c - 4) = 0;
    return 1;
}


int func_021B6138(int a, int b, int c, int d)
{
    if (func_021B6380((char *)d))
        return 0;
    return 1;
}


int func_021B614C(void *p)
{
    func_020315D4(p);
    func_020306F0(0x7f);
    return 1;
}


void func_021B615C(void)
{
    BG_SYS_SetVramBanks((void *)0x021B68F0);
}

void func_021B616C(char *unused)
{
 Mtx m;
 void *p;
 func_0207D4B0(1,5,0);
 *(volatile unsigned short *)0x0400000C=(*(volatile unsigned short *)0x0400000C&0x43)|0x4084;
 *(volatile unsigned short *)0x0400000E=(*(volatile unsigned short *)0x0400000E&0x43)|0x4884;
 BUTTON_MAN_RotScaleMtx22((struct Mtx22 *)(&m),0,(void *)0x1000,(void *)0x1000,0);
 func_0207D59C((void *)0x04000020,&m,0,0,0,0);
 func_0207D59C((void *)0x04000030,&m,0,0,0,0);
 p=func_02030734(0x807F,0x18000,1,(const char *)d_021B6B00,0x5B);
 func_0207EB78(p,0,0x18000);func_0207ECF0(p,0,0x18000);func_020307B0(p);
 BG_SYS_SetMainPlaneVisible(0x13,0);BG_SYS_SetMainPlaneVisible(0xC,1);
}


void func_021B6220(void)
{
    BG_SYS_SetMainPlaneVisible(12, 0);
}


void func_021B622C(char *p)
{
    unsigned short idx = ((struct Obj24463 *)(((struct Obj10716 *)p)->f0))->f0;
    int v = d_021B68E4[idx];

    ((struct Obj10716 *)p)->f6018 = v;
    ((struct Obj10716 *)p)->f601C = v;
}

void func_021B6248(char *p)
{
}


void func_021B624C(int *p)
{
    ((struct Obj24464 *)p)->f6014 = func_020056A0((void *)0x021B6279, p, 0);
}


void func_021B6268(char *p)
{
    func_02030EAC(((struct Obj24465 *)p)->f6014);
}
