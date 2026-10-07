/*
 * file:     event_pdc_return.c
 * unit:     yes
 * function: func_021B95A0, func_021B95C8, func_021B95D0, func_021B9610
 * address:  0x021B95A0
 * region:   ov227
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   d_021B98C0 0x021B98C0 data a4
 *   func_020307B0 0x020307B0 arm
 *   func_0203064C  0x0203064C  arm
 *   func_0203159C  0x0203159C  arm
 *   func_020457B0  0x020457B0  arm
 *   func_02031324  0x02031324  arm
 *   func_0203133C 0x0203133C arm
 *   func_02045808 0x02045808 arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 */
#include "../../matched/include/Obj04655.h"
#include "../../matched/include/Obj08473.h"

struct Obj0203159C;
struct U16Vec;
struct S020314B8;
struct S020315D4;
typedef unsigned int u32;

typedef unsigned short u16;

struct s { char pad[0x38]; };

extern void *func_02030734(u32 heap,u32 size,int clear,const char *site,u16 tag);
extern u32 func_020307B0(void *p);
extern void func_0203064C(unsigned int src, unsigned int dst, unsigned int size);
extern void *func_0203159C(struct Obj0203159C *obj, unsigned int size, unsigned int heap);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void *func_02031324(int a0);
extern void func_0203133C(struct S020314B8 *p);
extern void func_02045808(struct U16Vec *p);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int heap);
void *func_021B95A0(u32 a, int b, u32 c, u32 heap);
void func_021B95C8(void *p);
int func_021B95D0(struct Obj0203159C *a);
int func_021B9610(struct S020315D4 *a,void *b,void *c,char *p);
extern const char d_021B98C0[];

void *func_021B95A0(u32 a, int b, u32 c, u32 heap){u32 *p; p=func_02030734(heap,12,0,d_021B98C0,94);p[0]=a;p[1]=b;p[2]=c;return p;}

void func_021B95C8(void *p){func_020307B0(p);}


int func_021B95D0(struct Obj0203159C *a)
{
    struct s *p;

    func_0203064C(1, 0x8b, 0x1000);
    p = (struct s *)func_0203159C(a, 0x38, 0x8b);
    ((struct Obj04655 *)p)->f4 = (int)func_020457B0(0x20, 0x8b);
    ((struct Obj04655 *)p)->f0 = 0;
    ((struct Obj04655 *)p)->f28 = 0;
    ((struct Obj04655 *)p)->f2C = 0;
    ((struct Obj04655 *)p)->f30 = 0x8b;
    ((struct Obj04655 *)p)->f34 = (int)func_02031324(((struct Obj04655 *)p)->f30);
    return 1;
}

int func_021B9610(struct S020315D4 *a,void *b,void *c,char *p){func_0203133C(*(struct S020314B8 * *)&((struct Obj08473 *)p)->f34);if(*(struct U16Vec * *)&((struct Obj08473 *)p)->f28)func_02045808(*(struct U16Vec * *)&((struct Obj08473 *)p)->f28);func_02045808(*(struct U16Vec * *)&((struct Obj08473 *)p)->f4);func_020315D4(a);func_020306F0(139);return 1;}
