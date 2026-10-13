/*
 * function: func_021B9608
 * address: 0x021B9608
 * region: ov223
 * isa: thumb
 * packet: pkt_ov223_021B9608
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * status: EXACT
 * symbols:
 *   FADE_Start 0x0204E720 arm
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   FADE_GetSpeed 0x0204E6E0 arm
 *   FADE_SetSpeed 0x0204E6F4 arm
 *   func_020355C4 0x020355C4 arm
 * 3159C's r0 return is consumed despite its legacy void declaration.
 * 3064C preserves all three visibly loaded original arguments.
 */
#include "../include/Obj03961.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern void FADE_Start(u32,int,int,int);
extern void GFL_HEAP_CreateChildHeap(u32,u32,u32);
struct Obj0203159C;
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *,u32,u32);
extern u32 FADE_GetSpeed(void);
extern void FADE_SetSpeed(int);
extern u8 func_020355C4(void);
int func_021B9608(void *a,int unused,void *c)
{
    char *p;
    FADE_Start(3,16,16,0);
    GFL_HEAP_CreateChildHeap(1,135,1<<20);
    p=PROCSYS_AllocProcWork(a,2168,135);
    func_02082BCC(p,0,2168);
    ((struct Obj03961 *)p)->f0=135;
    ((struct Obj03961 *)p)->f4=c;
    ((struct Obj03961 *)p)->f874=FADE_GetSpeed();
    FADE_SetSpeed(1);
    ((struct Obj03961 *)p)->f8=func_020355C4();
    ((struct Obj03961 *)p)->f228=4;
    ((struct Obj03961 *)p)->f22C=4;
    ((struct Obj03961 *)p)->f230=0;
    ((struct Obj03961 *)p)->fC=0;
    return 1;
}
