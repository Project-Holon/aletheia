/*
 * function: SHINKA_DEMO_Create
 * address: 0x02203FA0
 * packet: pkt_ov195_02203FA0
 * region: ov195
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * ABI: 0203159C and 02031324 own files return void; caller consumes r0.
 * ABI: 02031324 also receives the heap in r0, preserved in this extern.
 * symbols:
 *   sub_0203064C 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   POKEPARTY_GetMember 0x0201AB28 thumb
 *   STRBUF_Create 0x020457B0 arm
 *   func_02017E1C 0x02017E1C thumb
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   FADE_Start 0x0204E720 arm
 *   SHINKA_DEMO_StartBgm 0x02204DC4 thumb ov195
 *   GFL_USE_AddMainTask 0x020056A0 thumb
 *   SHINKA_DEMO_MainTask 0x022051A8 thumb ov195
 *   PROCSYS_Create 0x02031324 arm
 *   SHINKA_DEMO_SetupScene 0x02204C24 thumb ov195
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   d_02208F40 0x02208F40 data a4
 */
#include "../include/Obj00734.h"
#include "../include/Obj05515.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
struct Obj0203159C;
struct U16Vec;
struct App;
struct Scene;
extern void sub_0203064C(u32 src, u32 dst, u32 size);
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *,u32,u32);
extern void *POKEPARTY_GetMember(void *,u32);
extern struct U16Vec *STRBUF_Create(u32,u32);
extern u32 func_02017E1C(void *,u32,u32);
extern void *GFL_HEAP_Alloc(u32,u32,int,const char *,u16);
extern void FADE_Start(u32,int,int,int);
extern void SHINKA_DEMO_StartBgm(u8 *,u8 *);
extern void *GFL_USE_AddMainTask(u32,u32,u32);
extern void SHINKA_DEMO_MainTask(int task, char *p);
extern void *PROCSYS_Create(int a0);
extern void SHINKA_DEMO_SetupScene(struct App *,struct Scene *);
extern void GFL_NET_RestartWithDefaultTimeout(u32,u32);
extern const char d_02208F40[];
int SHINKA_DEMO_Create(struct Obj0203159C *owner,int unused,u8 *app)
{
    char *p;
    sub_0203064C(1,0x94,0x10000);
    p=PROCSYS_AllocProcWork(owner,0x120,0x94);
    MI_CpuFill8(p,0,0x120);
    ((struct Obj00734 *)p)->f0=0x94;
    ((struct Obj00734 *)p)->f28=0;
    ((struct Obj00734 *)p)->f2C=5;
    ((struct Obj00734 *)p)->f30=0;
    ((struct Obj00734 *)p)->f10=POKEPARTY_GetMember(((struct Obj05515 *)app)->f4,app[0xa]);
    *(struct U16Vec * *)&((struct Obj00734 *)p)->f14=STRBUF_Create(0x100,((struct Obj00734 *)p)->f0);
    func_02017E1C(((struct Obj00734 *)p)->f10,0x73,*(u32 *)&((struct Obj00734 *)p)->f14);
    ((struct Obj00734 *)p)->f24=0;
    ((struct Obj00734 *)p)->fA0=0;
    ((struct Obj00734 *)p)->fA4=0;
    ((struct Obj00734 *)p)->fA8=0;
    ((struct Obj00734 *)p)->fAC=0;
    ((struct Obj00734 *)p)->f100=GFL_HEAP_Alloc(((struct Obj00734 *)p)->f0,0x28,1,d_02208F40,0x242);
    FADE_Start(3,16,16,-16);
    SHINKA_DEMO_StartBgm(app,(u8 *)p);
    ((struct Obj00734 *)p)->f38=GFL_USE_AddMainTask((u32)SHINKA_DEMO_MainTask,(u32)p,1);
    ((struct Obj00734 *)p)->f10C=0;
    ((struct Obj00734 *)p)->f110=0;
    ((struct Obj00734 *)p)->f114=0;
    ((struct Obj00734 *)p)->f118=0;
    ((struct Obj00734 *)p)->f11C=(unsigned int)PROCSYS_Create(((struct Obj00734 *)p)->f0);
    SHINKA_DEMO_SetupScene((struct App *)app,(struct Scene *)p);
    GFL_NET_RestartWithDefaultTimeout(0,((struct Obj00734 *)p)->f0);
    return 1;
}
