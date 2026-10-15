/*
 * function: func_021B9E48
 * address: 0x021B9E48
 * packet: pkt_ov218_021B9E48
 * region: ov218
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * prototype: 0203159C leaves allocator r0 live through final store/pop; original consumes that return despite legacy void source.
 * symbols:
 *   ov067_id 0x43 data
 *   func_02034AC4 0x02034AC4 arm
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   tbl_021BAC80 0x021BAC80 data ov218 a4
 *   func_021BA780 0x021BA780 thumb ov218
 *   GXx_SetMasterBrightness_ 0x0207D534 arm
 *   UN_SELECT_GRAPHIC_Create 0x021BA848 thumb ov218
 *   d_021BAB20 0x021BAB20 data a4
 *   UI_SCENE_Create 0x021B6100 thumb ov067
 *   func_021B96CC 0x021B96CC thumb ov218
 *   func_021B9964 0x021B9964 thumb ov218
 *   UN_SELECT_GRAPHIC_GetActor 0x021BA960 thumb ov218
 *   func_021B9820 0x021B9820 thumb ov218
 *   func_021B9C80 0x021B9C80 thumb ov218
 *   func_021B9C84 0x021B9C84 thumb ov218
 *   APP_TASKMENU_RES_Create 0x02027F60 thumb
 *   func_021BA290 0x021BA290 thumb ov218
 *   func_021B9D48 0x021B9D48 thumb ov218
 *   func_021BA328 0x021BA328 thumb ov218
 *   func_021BA61C 0x021BA61C thumb ov218
 *   func_0207D63C 0x0207D63C arm
 *   UN_SELECT_Callback 0x021BA238 thumb ov218
 *   func_02005624 0x02005624 thumb
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 */
#include "../include/Obj00243.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern int tbl_021BAC80[];
extern char ov067_id[];
extern char d_021BAB20[];
extern int func_02034AC4(int);
extern void GFL_HEAP_CreateChildHeap(u32,u32,u32);
struct Obj0203159C;
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *,u32,u32);
extern u32 func_021BA780(int);
struct R;
extern void GXx_SetMasterBrightness_(volatile u16 *reg, int brightness);
extern char *UN_SELECT_GRAPHIC_Create(unsigned swap, unsigned heap);
extern void *UI_SCENE_Create(u32,void *,u8,u16,void *);
extern void func_021B96CC(u8 *p, u16 heap);
extern void *func_021B9964(u16);
extern u32 UN_SELECT_GRAPHIC_GetActor(char *p);
extern void *func_021B9820(int,int);
extern void *func_021B9C80(u8 *p);
extern void *func_021B9C84(u8 *p);
extern struct R *APP_TASKMENU_RES_Create(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern void func_021BA290(char *),func_021B9D48(char *),func_021BA328(char *),func_021BA61C(char *);
extern void func_0207D63C(u32 *,u32,u32,u32,u32);
extern void UN_SELECT_Callback(void);
extern void *func_02005624(u32 a, u32 b, u32 c);
extern void GFL_NET_RestartWithDefaultTimeout(u32,u32);
char *func_021B9E48(void *owner,char *input)
{
    char *p;
    int i,value;
    u32 a,b;
    func_02034AC4((int)ov067_id);
    GFL_HEAP_CreateChildHeap(1,122,0x30000);
    p=PROCSYS_AllocProcWork(owner,0x330,122);
    MI_CpuFill8(p,0,0x330);
    ((struct Obj00243 *)p)->f0=122;
    *(char * *)&((struct Obj00243 *)p)->f20=input;
    for(i=0;i<130;i++) {
        if(*(u8 *)(input+0x2f+tbl_021BAC80[i]))*(u32 *)(p+0x34+i*4)=1;
        else *(u32 *)(p+0x34+i*4)=0;
    }
    for(i=0;i<20;i++) {
        value=*(u16 *)(input+8+i*2);
        if(value!=0)value=func_021BA780(value);
        else value=65535;
        *(int *)(p+0x2dc+i*4)=value;
    }
    GXx_SetMasterBrightness_((u16 *)0x0400006c,-16);
    GXx_SetMasterBrightness_((u16 *)0x0400106c,-16);
    ((struct Obj00243 *)p)->f4=UN_SELECT_GRAPHIC_Create(0,((struct Obj00243 *)p)->f0);
    ((struct Obj00243 *)p)->f24=UI_SCENE_Create(((struct Obj00243 *)p)->f0,d_021BAB20,3,0,p);
    func_021B96CC((u8 *)p,((struct Obj00243 *)p)->f0);
    ((struct Obj00243 *)p)->f28=func_021B9964(((struct Obj00243 *)p)->f0);
    ((struct Obj00243 *)p)->f8=func_021B9820(UN_SELECT_GRAPHIC_GetActor(((struct Obj00243 *)p)->f4),((struct Obj00243 *)p)->f0);
    a=(u32)func_021B9C80(((struct Obj00243 *)p)->f28);
    b=(u32)func_021B9C84(((struct Obj00243 *)p)->f28);
    ((struct Obj00243 *)p)->f18=APP_TASKMENU_RES_Create(1,11,a,b,((struct Obj00243 *)p)->f0);
    func_021BA290(p);
    func_021B9D48(p);
    func_021BA328(p);
    func_021BA61C(p);
    func_0207D63C((u32 *)0x04001050,4,8,6,10);
    ((struct Obj00243 *)p)->f23C=func_02005624((u32)UN_SELECT_Callback,(u32)p,0);
    GFL_NET_RestartWithDefaultTimeout(1,((struct Obj00243 *)p)->f0);
    return p;
}
