/*
 * function: PMSI_SEARCH_Create
 * address: 0x021BAEDC
 * packet: pkt_ov110_021BAEDC
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: int index declared before allocation pointer; table has no region hint.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   PMSI_SEARCH_ClearInput 0x021BAFE4 thumb ov110
 *   func_02045B38 0x02045B38 arm
 *   MSGSEARCH_Create 0x021B6C74 thumb ov067
 *   STRBUF_Create 0x020457B0 arm
 *   sPmsiSearchAllocSite 0x021C3C34 data ov110 a1
 *   sPmsiSearchBankFileIds 0x021C3770 data a2
 */
#include "../include/Obj03750.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_02030734(u32,u32,int,const char *,u16);
extern void PMSI_SEARCH_ClearInput(u32 p);
struct MsgBank;
struct U16Vec;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 *MSGSEARCH_Create(u32 *src, u32 n, u16 heap);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern const char sPmsiSearchAllocSite[];
extern const u16 sPmsiSearchBankFileIds[];
u8 *PMSI_SEARCH_Create(void *p,void *q,u16 heap) {
    int i;
    u8 *result;
    result=func_02030734(heap,0xaf4,1,sPmsiSearchAllocSite,137);
    ((struct Obj03750 *)result)->f0=p;
    ((struct Obj03750 *)result)->f4=q;
    ((struct Obj03750 *)result)->f8=heap;
    PMSI_SEARCH_ClearInput((u32)result);
    for(i=0;i<27;i++) *(void **)(result+12+i*4)=func_02045B38(1,2,sPmsiSearchBankFileIds[i],heap);
    ((struct Obj03750 *)result)->f78=MSGSEARCH_Create((u32 *)(result+12),27,((struct Obj03750 *)result)->f8);
    ((struct Obj03750 *)result)->fAD0=STRBUF_Create(27,heap);
    return result;
}
