/*
 * function: LOCAL_TVT_SYS_ProcInit
 * address: 0x021B6BC4
 * packet: pkt_ov174_021B6BC4
 * region: ov174
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   func_02030734 0x02030734 arm
 *   GAME_DATA_Create 0x020124F4 thumb
 *   KEY_GetCont 0x0203630C arm
 *   LOCAL_TVT_SYS_Create 0x021B6100 thumb ov174
 *   d_021B74AC 0x021B74AC data
 */
#include "../include/Obj01167.h"
#include "../include/Obj10673.h"
typedef unsigned short u16;
extern void GFL_HEAP_CreateChildHeap(unsigned int src, unsigned int dst, unsigned int size);
struct Proc;
extern void *PROCSYS_AllocProcWork(struct Proc *obj, unsigned int size, unsigned int heap);
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *GAME_DATA_Create(u16);
extern unsigned int KEY_GetCont(void);
typedef unsigned char  u8;
extern void LOCAL_TVT_SYS_Create(u8 *p);
extern char d_021B74AC[];
int LOCAL_TVT_SYS_ProcInit(void *ctx,int unused,char *arg)
{
    char *p;
    GFL_HEAP_CreateChildHeap(1,0x55,0x40000);
    p=PROCSYS_AllocProcWork(ctx,0x8c,0x55);
    if(arg==0) {
        arg=func_02030734(0x55,8,0,d_021B74AC,0x3b8);
        ((struct Obj10673 *)arg)->f4=GAME_DATA_Create(1);
        ((struct Obj10673 *)arg)->f0=1;
        if(KEY_GetCont() & 0x100) ((struct Obj10673 *)arg)->f0=5;
    }
    ((struct Obj01167 *)p)->f0=0x55;
    *(char * *)&((struct Obj01167 *)p)->f30=arg;
    LOCAL_TVT_SYS_Create((u8 *)p);
    return 1;
}
