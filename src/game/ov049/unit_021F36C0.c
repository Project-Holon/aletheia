/*
 * file:     unit_021F36C0.c
 * unit:     yes
 * function: func_021F36C0, func_021F36EC, func_021F3708, func_021F3714, func_021F3864
 * address:  0x021F36C0
 * region:   ov049
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02188C84 0x02188C84 thumb ov021
 *   func_02189764 0x02189764 thumb ov021
 *   func_021897BC 0x021897BC thumb ov021
 *   func_021F3868 0x021F3868 thumb ov049
 *   func_021897A0 0x021897A0 thumb ov021
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_021BE580  0x021BE580  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_020142E8  0x020142E8  thumb
 *   func_021BE760  0x021BE760  thumb  ov021
 *   func_021BE480  0x021BE480  thumb  ov021
 *   func_021BE700  0x021BE700  thumb  ov021
 *   d_021F3894     0x021F3894  data  ov049  a4
 *   d_021F38A4     0x021F38A4  data  a4
 */
#include "../../matched/include/Obj20549.h"

struct BigObj;
struct Ctx;
typedef unsigned short u16;

typedef unsigned char  u8;

typedef unsigned int u32;

typedef struct {
    int a;
    int b;
    int c;
} V3;

typedef signed int     s32;

extern u16 func_02188C84(u8 *p);
extern void *func_02189764(unsigned char *p,int id,int a,int b);
extern int *func_021897BC(char *p,int idx);
extern void func_021F3868(int *q,char *p);
extern void func_021897A0(unsigned char *p,int id);
extern void *func_02188D2C(void *p);
extern void func_021BE580(void *p);
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u32 func_0201296C(const struct BigObj *p);
extern u32 func_020142E8(void *bitmap, s32 id);
extern void func_021BE760(u32 a, void *b, int c);
extern V3 *func_021BE480(u32 a, int b, u16 c);
extern void func_021BE700(void *p, int i, int j, int k, int flag);
void func_021F36C0(unsigned char *p);
void func_021F36EC(char *p);
void func_021F3708(void *p);
void func_021F3714(u32 a0, u32 a);
void func_021F3864(void *q, unsigned char *p);
extern const V3 d_021F38A4[];
extern char d_021F3894[];



void func_021F36C0(unsigned char *p) { unsigned short h; void *q; h=func_02188C84((u8 *)((int)p)); q=func_02189764(p,0,h,2); ((struct Obj20549 *)q)->f0=h; func_021F3714((unsigned int)q,(unsigned int)p); func_021F3864(q,p); }



void func_021F36EC(char *p) { func_021F3868(func_021897BC(p,0),p); func_021897A0((unsigned char *)p,0); }

void func_021F3708(void *p)
{
    func_021BE580(func_02188D2C(p));
}



void func_021F3714(u32 a0, u32 a)
{
    int f0;
    int f1;
    int f2;
    int f3;
    void *sv;
    u32 s;
    int i;
    V3 *p;

    sv = (void *)func_0201296C(func_020120F4(func_02188C80((void *)a)));
    f0 = func_020142E8(sv, 0x96B);
    f1 = func_020142E8(sv, 0x96A);
    f2 = func_020142E8(sv, 0x969);
    f3 = func_020142E8(sv, 0x96C);
    s = (int)func_02188D2C((int *)a);
    func_021BE760(s, d_021F3894, 0);
    for (i = 0; i < 6; i++) {
        p = func_021BE480(s, 0, i);
        p->a = d_021F38A4[i].a;
        p->b = d_021F38A4[i].b;
        p->c = d_021F38A4[i].c;
    }
    if (f0 && f1 && f2 && f3) {
        func_021BE700((void *)s, 0, 0, 0, 1);
        func_021BE700((void *)s, 0, 1, 0, 1);
    }
    if (f0)
        func_021BE700((void *)s, 0, 2, 1, 1);
    else
        func_021BE700((void *)s, 0, 2, 0, 1);
    if (f1)
        func_021BE700((void *)s, 0, 3, 1, 1);
    else
        func_021BE700((void *)s, 0, 3, 0, 1);
    if (f2)
        func_021BE700((void *)s, 0, 4, 1, 1);
    else
        func_021BE700((void *)s, 0, 4, 0, 1);
    if (f3)
        func_021BE700((void *)s, 0, 5, 1, 1);
    else
        func_021BE700((void *)s, 0, 5, 0, 1);
}


/*
 * Empty function.
 */
void func_021F3864(void *q, unsigned char *p)
{
}
