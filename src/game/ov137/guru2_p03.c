/*
 * file:     guru2_p03.c
 * unit:     yes
 * function: func_021DCB04, func_021DCB60, func_021DCB78, func_021DCB90, func_021DCB94
 * address:  0x021DCB04
 * region:   ov137
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   func_0203A574 0x0203A574 arm
 *   d_021E1A68 0x021E1A68 data a4
 *   func_020399A8 0x020399A8 arm
 *   func_02082D44 0x02082D44 arm
 *   func_0203D3A8 0x0203D3A8 arm
 */
#include "../../matched/include/Obj14204.h"

struct Entry;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

extern void *func_02030734(u16,u32,int,const void *,int);
extern void func_02082BCC(void *,int,u32);
extern u32 func_020307B0(void *p);
extern void func_0203A574(u32,u32,u32,u32);
extern struct Entry *func_020399A8(void);
extern void func_02082D44(const void *,void *,u32);
extern int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);
u32 *func_021DCB04(u32 a,int heap);
void func_021DCB60(u8 *p);
void func_021DCB78(u32 a);
void func_021DCB90(void *p);
void func_021DCB94(u8 *p,u32 id,const void *data,u32 size);
extern const unsigned char d_021E2268[];
extern const u8 d_021E1A68[];

/*
 * func_02030734 0x02030734 arm
 * func_02082BCC 0x02082BCC arm
 * d_021E2268 0x021E2268 data a4
 */
u32 *func_021DCB04(u32 a,int heap)
{
    u32 *p;
    p=func_02030734(heap,88,0,d_021E2268,152);
    func_02082BCC(p,0,88);
    p[0]=a;
    p[19]=(u32)func_02030734(heap,0x1be4,0,d_021E2268,159);
    p[20]=(u32)func_02030734(heap,0x1be4,0,d_021E2268,161);
    return p;
}

void func_021DCB60(u8 *p) {func_020307B0(((struct Obj14204 *)p)->f4C);func_020307B0(((struct Obj14204 *)p)->f50);func_020307B0(p);}

void func_021DCB78(u32 a) {func_0203A574(0x2800,(u32)d_021E1A68,16,a);}

void func_021DCB90(void *p) { }

/*
 * lever: separate q=(u8 *)((u32)p+4) keeps the updated buffer base;
 *   assigning p+=4 or retaining an integer parameter gave 50 bytes/DIFF.
 */
void func_021DCB94(u8 *p,u32 id,const void *data,u32 size) {u8 *q;void *v;v=func_020399A8();q=(u8 *)((u32)p+4);func_02082D44(data,q+4,size);func_0203D3A8(v,(u16)id,(u16)(size+4),(u32)q+4);}
