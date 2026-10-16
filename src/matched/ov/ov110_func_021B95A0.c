/*
 * function: PMS_INPUT_DATA_Create
 * address: 0x021B95A0
 * packet: pkt_ov110_021B95A0
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   PMS_WORD_Create 0x020247A8 thumb
 *   PMS_INPUT_DATA_BuildCategoryWords 0x021B9608 thumb ov110
 *   PMS_INPUT_DATA_BuildInitialWords 0x021B98A0 thumb ov110
 *   d_021C3B80 0x021C3B80 data a1
 */
#include "../include/Obj05283.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
struct PmsWordSys;
extern struct PmsWordSys *PMS_WORD_Create(u32 heapId);
extern void PMS_INPUT_DATA_BuildCategoryWords(void *);
extern void PMS_INPUT_DATA_BuildInitialWords(u8 *p);
extern const char d_021C3B80[];
void *PMS_INPUT_DATA_Create(u32 heap,void *save)
{
    char *p;
    int i;
    p=func_02030734((u16)heap,0x1E50,0,d_021C3B80,88);
    ((struct Obj05283 *)p)->f0=save;
    ((struct Obj05283 *)p)->f4=PMS_WORD_Create(heap);
    for(i=0;i<226;i++) *(u8 *)(p+0x1D6E + i)=0;
    PMS_INPUT_DATA_BuildCategoryWords(p);
    PMS_INPUT_DATA_BuildInitialWords((u8 *)p);
    return p;
}
