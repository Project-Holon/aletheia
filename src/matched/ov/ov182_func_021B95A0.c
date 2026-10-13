/*
 * function: func_021B95A0
 * address: 0x021B95A0
 * packet: pkt_ov182_021B95A0
 * region: ov182
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * matching: named vp = value before allocation preserves the stack address in r7.
 * symbols:
 *   d_021B9B9C 0x021B9B9C data a2
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021B98E4 0x021B98E4 thumb ov182
 *   GF_FONT_Create 0x0201D7EC thumb
 *   func_0201C440 0x0201C440 thumb
 *   func_0204047C 0x0204047C arm
 *   func_020056A0 0x020056A0 thumb
 *   func_021B9784 0x021B9784 thumb ov182
 *   func_021B9788 0x021B9788 thumb ov182
 *   GPOWER_GetSpecialPowerId 0x020111E8 thumb
 *   func_0207E468 0x0207E468 arm
 *   func_021B9814 0x021B9814 thumb ov182
 */
#include "../include/Obj03328.h"
typedef unsigned short u16;
extern const u16 d_021B9B9C;
extern void GFL_HEAP_CreateChildHeap(unsigned int, unsigned int, unsigned int);
struct Obj0203159C;
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, unsigned int size, unsigned int heap);
extern void func_02082BCC(void *, int, int);
typedef unsigned int   u32;
struct GfFont;
extern char *func_021B98E4(int a, u16 heap);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 func_0201C440(void *p);
extern void func_0204047C(int idx, unsigned short val);
extern void *func_020056A0(void (*)(void), void *, int);
extern void func_021B9784(void);
extern void func_021B9788(u16 *);
extern unsigned GPOWER_GetSpecialPowerId(void);
extern void func_0207E468(void *, int, int);
extern void func_021B9814(void *, void *, void *);
int func_021B95A0(void *task, int b, int c)
{
    u16 value[1];
    char *p;
    u16 *vp;
    value[0] = d_021B9B9C;
    vp = value;
    GFL_HEAP_CreateChildHeap(1, 0x88, 0x30000);
    p = PROCSYS_AllocProcWork(task, 0x1c, 0x88);
    func_02082BCC(p, 0, 0x1c);
    ((struct Obj03328 *)p)->f0 = 0x88;
    ((struct Obj03328 *)p)->f10 = c;
    ((struct Obj03328 *)p)->f4 = func_021B98E4(1, ((struct Obj03328 *)p)->f0);
    ((struct Obj03328 *)p)->f8 = GF_FONT_Create(0x17, 0, 0, 0, ((struct Obj03328 *)p)->f0);
    ((struct Obj03328 *)p)->fC = (void *)func_0201C440((void *)(((struct Obj03328 *)p)->f0));
    func_0204047C(1, 1);
    func_0204047C(2, 0);
    ((struct Obj03328 *)p)->f14 = func_020056A0(func_021B9784, p, 1);
    func_021B9788((u16 *)p);
    if (GPOWER_GetSpecialPowerId() == 0x14)
        func_0207E468(vp, 0, 2);
    func_021B9814((void *)0x10, 0, 0);
    return 1;
}
