/*
 * function: ZUKAN_DETAIL_COMMON_DeletePaletteAnim
 * address: 0x021BC61C
 * packet: pkt_ov208_021BC61C
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PALANM_FreeSlotBuffers 0x020215A0 thumb
 *   PALANM_Delete 0x02021540 thumb
 *   func_02030DA4 0x02030DA4 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj02544.h"
typedef unsigned int   u32;
struct PalAnmSlot;
extern void PALANM_FreeSlotBuffers(struct PalAnmSlot *slots, u32 idx);
extern u32 PALANM_Delete(void *a0);
extern void func_02030DA4(void *);
extern u32 func_020307B0(void *p);
void ZUKAN_DETAIL_COMMON_DeletePaletteAnim(char *p)
{
    if(((struct Obj02544 *)p)->fC&8)PALANM_FreeSlotBuffers(((struct Obj02544 *)p)->f8,3);
    if(((struct Obj02544 *)p)->fC&2)PALANM_FreeSlotBuffers(((struct Obj02544 *)p)->f8,1);
    if(((struct Obj02544 *)p)->fC&4)PALANM_FreeSlotBuffers(((struct Obj02544 *)p)->f8,2);
    if(((struct Obj02544 *)p)->fC&1)PALANM_FreeSlotBuffers(((struct Obj02544 *)p)->f8,0);
    PALANM_Delete(((struct Obj02544 *)p)->f8);
    func_02030DA4(((struct Obj02544 *)p)->f0);
    func_020307B0((void *)(((struct Obj02544 *)p)->f4));
    func_020307B0((void *)((unsigned)p));
}
