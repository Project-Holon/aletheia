/*
 * function: MYSTERY_UTIL_CreateWindowList
 * address: 0x021DA1BC
 * packet: pkt_ov121_021DA1BC
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: b is u16; const descriptor input and an element slot pointer reproduce scheduling.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   MYSTERY_UTIL_CreateWindow 0x021D99A4 thumb ov121
 *   MYSTERY_UTIL_SetPosition 0x021D9B2C thumb ov121
 *   MYSTERY_UTIL_SetColor 0x021D9B28 thumb ov121
 *   MYSTERY_UTIL_ShowString 0x021D9AC8 thumb ov121
 *   MYSTERY_UTIL_ShowMessage 0x021D9A64 thumb ov121
 *   d_021DFBA0 0x021DFBA0 data a4
 */
#include "../include/Obj02469.h"
#include "../include/Obj04494.h"
#include "../include/Obj08093.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern char d_021DFBA0[];
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MI_CpuFill8(void *,int,int);
extern void *MYSTERY_UTIL_CreateWindow(void *,u16,u8,u8,u8,u8,u16,u16,u16);
extern void MYSTERY_UTIL_SetPosition(char *p, u32 a, u32 b, int c);
extern void MYSTERY_UTIL_SetColor(u8 *p, unsigned v);
extern void MYSTERY_UTIL_ShowString(u8 *p, int a, int b);
extern void MYSTERY_UTIL_ShowMessage(u8 *p, u16 a, int b, int c);
void *MYSTERY_UTIL_CreateWindowList(void *a,const char *desc,u32 n,u16 b,u16 c,u16 d,u16 e,int f,u16 heap)
{
    u32 i;
    int size=n*4+16;
    char *out=func_02030734(heap,size,0,d_021DFBA0,0x374);
    MI_CpuFill8(out,0,size);
    *(const char * *)&((struct Obj04494 *)out)->f0=desc;
    ((struct Obj04494 *)out)->f4=n;
    ((struct Obj04494 *)out)->f8=f;
    ((struct Obj04494 *)out)->fC=e;
    for(i=0;i<((struct Obj04494 *)out)->f4;i++) {
        const char *v=desc+i*24;
        char *slot=out+i*4;
        void *q=MYSTERY_UTIL_CreateWindow(a,b,((struct Obj02469 *)v)->f0,((struct Obj02469 *)v)->f1,((struct Obj02469 *)v)->f2,((struct Obj02469 *)v)->f3,c,d,heap);
        ((struct Obj08093 *)slot)->f10=q;
        MYSTERY_UTIL_SetPosition(q,((struct Obj02469 *)v)->f10,((struct Obj02469 *)v)->f12,((struct Obj02469 *)v)->fC);
        MYSTERY_UTIL_SetColor(((struct Obj08093 *)slot)->f10,((struct Obj02469 *)v)->f14);
        if(((struct Obj02469 *)v)->f8) MYSTERY_UTIL_ShowString(((struct Obj08093 *)slot)->f10,((struct Obj02469 *)v)->f8,((struct Obj04494 *)out)->f8);
        else MYSTERY_UTIL_ShowMessage(((struct Obj08093 *)slot)->f10,e,((struct Obj02469 *)v)->f4,((struct Obj04494 *)out)->f8);
    }
    return out;
}
