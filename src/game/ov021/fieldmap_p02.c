/*
 * file:     fieldmap_p02.c
 * unit:     yes
 * function: func_02188030, func_021880A4
 * address:  0x02188030
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
 *   func_02030734  0x02030734  arm
 *   func_020120F4  0x020120F4  thumb
 *   func_020120F8  0x020120F8  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_02013B38  0x02013B38  thumb
 *   func_0202E83C  0x0202E83C  thumb
 *   func_0201407C  0x0201407C  thumb
 *   func_02189BA8  0x02189BA8  thumb  ov021
 *   d_021DD9C0     0x021DD9C0  data  a4
 *   func_020140B4  0x020140B4  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_02012110  0x02012110  thumb
 *   func_020371AC  0x020371AC  arm
 */
#include "../../matched/include/Obj03102.h"

struct Ctx;
struct Rec44;
typedef unsigned short u16;

typedef unsigned int   u32;

void *func_02030734(unsigned int heapId, unsigned int size, int clear, const char *site, u16 tag);
void *func_020120F4(const struct Ctx *p);
unsigned char *func_020120F8(const struct Ctx *p);
unsigned short func_02012AC8(const struct Rec44 *p);
u32 func_02013B38(u32 id);
int func_0202E83C(void *a0);
int func_0201407C(int a, int b, int c);
int func_02189BA8(int x);
u32 func_020140B4(void *a);
u32 func_020307B0(void *p);
void func_02012110(struct Ctx *p, void *v);
void func_020371AC(unsigned short a, unsigned int b);
void *func_02188030(int a, int b);
void func_021880A4(int *p);
extern int d_021DD9C0;


void *func_02188030(int a, int b)
{
    char *p = (char *)func_02030734(b, 0x154, 1, (const char *)(&d_021DD9C0), 0x209);

    ((struct Obj03102 *)p)->f0 = b;
    ((struct Obj03102 *)p)->fC0 = 0;
    ((struct Obj03102 *)p)->f4 = a;
    ((struct Obj03102 *)p)->f8 = (int)func_020120F4((const struct Ctx *)a);
    ((struct Obj03102 *)p)->fD0 = func_02012AC8((const struct Rec44 *)func_020120F8((const struct Ctx *)a));
    {
        int r7 = func_02013B38(((struct Obj03102 *)p)->fD0);
        ((struct Obj03102 *)p)->fC = func_0201407C(b, r7, func_0202E83C((void *)a));
    }
    ((struct Obj03102 *)p)->f108 = func_02189BA8(((struct Obj03102 *)p)->fD0);
    return p;
}


void func_021880A4(int *p)
{
    int q = p[1];
    func_020140B4((void *)p[3]);
    func_020307B0(p);
    func_02012110((void *)q, 0);
    func_020371AC(0, 0);
}
