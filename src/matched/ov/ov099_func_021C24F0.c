/*
 * function: WIFICLUB_ProcInit
 * address: 0x021C24F0
 * packet: pkt_ov099_021C24F0
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: 3064C preserves caller-loaded r2; 3159C returns the live allocator pointer.
 * symbols:
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   GFL_NET_SetUserArg 0x0203D668 arm
 *   WIFICLUB_LoadSavedRegulation 0x021BCB8C thumb ov099
 *   func_02012934 0x02012934 thumb
 *   func_0201283C 0x0201283C thumb
 *   func_0200873C 0x0200873C thumb
 *   WIFICLUB_InitBgmVolume 0x021C24D4 thumb ov099
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   WIFICLUB_CreateTextBuffers 0x021BB1A8 thumb ov099
 *   WIFICLUB_InitScreen 0x021BDE94 thumb ov099
 *   WIFICLUB_BuildOwnStatus 0x021BE6F0 thumb ov099
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   WIFICLUBACTOR_AddNetCommands 0x021BA7D8 thumb ov099
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 */
#include "../include/Obj01386.h"
#include "../include/Obj02804.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct BigObj;
extern void GFL_HEAP_CreateChildHeap(u32, u32, u32);
struct Obj0203159C;
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *, int, int);
extern void GFL_NET_SetUserArg(u32);
extern int WIFICLUB_LoadSavedRegulation(void *);
extern void *func_02012934(const struct BigObj *p);
extern u32 func_0201283C(const struct BigObj *);
struct Sub02008700Obj;
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern void WIFICLUB_InitBgmVolume(u8 *p, int v);
extern void BG_SYS_SetMainPlaneVisible(u32, u32);
extern void BG_SYS_SetSubPlaneVisible(u32, u32);
extern void WIFICLUB_CreateTextBuffers(char *);
extern void WIFICLUB_InitScreen(char *);
extern void WIFICLUB_BuildOwnStatus(char *, int, int);
extern int GFL_NET_GetRunState(void);
extern void WIFICLUBACTOR_AddNetCommands(void *p);
extern void GFL_NET_RestartWithDefaultTimeout(u32, u32);
int WIFICLUB_ProcInit(void *obj, int unused, char *args)
{
    char *p;
    GFL_HEAP_CreateChildHeap(1, 0x8021, 0xa4000);
    p = PROCSYS_AllocProcWork(obj, 0x1360, 0x21);
    MI_CpuFill8(p, 0, 0x1360);
    GFL_NET_SetUserArg((u32)p);
    ((struct Obj01386 *)p)->f8 = ((struct Obj02804 *)args)->f0;
    ((struct Obj01386 *)p)->fC0 = ((struct Obj02804 *)args)->f8;
    *(u32 *)&((struct Obj01386 *)p)->fC4 = ((struct Obj02804 *)args)->f4;
    ((struct Obj01386 *)p)->fCC = WIFICLUB_LoadSavedRegulation(((struct Obj01386 *)p)->fC4);
    ((struct Obj01386 *)p)->fC8 = func_02012934(*(struct BigObj * *)&((struct Obj01386 *)p)->fC4);
    ((struct Obj01386 *)p)->f4 = func_0201283C(*(struct BigObj * *)&((struct Obj01386 *)p)->fC4);
    ((struct Obj01386 *)p)->fD8 = (u32)func_0200873C((void *)(((struct Obj02804 *)args)->f8));
    ((struct Obj01386 *)p)->f1D8 = *(u32 *)&((struct Obj02804 *)args)->fC;
    ((struct Obj01386 *)p)->f135C = ((struct Obj02804 *)args)->f49;
    if (((struct Obj02804 *)args)->fC == 1) {
        ((struct Obj02804 *)args)->fC = 0;
        WIFICLUB_InitBgmVolume((u8 *)p, 4);
    } else if (((struct Obj02804 *)args)->fC != 0) {
        WIFICLUB_InitBgmVolume((u8 *)p, 4);
    } else {
        WIFICLUB_InitBgmVolume((u8 *)p, 1);
    }
    ((struct Obj01386 *)p)->f1D0 = 0;
    ((struct Obj01386 *)p)->f1F0 = -1;
    *(char * *)&((struct Obj01386 *)p)->f248 = args;
    BG_SYS_SetMainPlaneVisible(15, 0);
    BG_SYS_SetSubPlaneVisible(15, 0);
    WIFICLUB_CreateTextBuffers(p);
    ((struct Obj01386 *)p)->f1CC = 0;
    WIFICLUB_InitScreen(p);
    if (((struct Obj02804 *)args)->fC == 0) WIFICLUB_BuildOwnStatus(p, 1, 2);
    if (GFL_NET_GetRunState() != 0) {
        WIFICLUBACTOR_AddNetCommands(p);
        GFL_NET_RestartWithDefaultTimeout(1, 0x21);
    }
    return 1;
}
