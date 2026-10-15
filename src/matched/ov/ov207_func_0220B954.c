/*
 * function: ZUKAN_NICKNAME_InitKeyboard
 * address: 0x0220B954
 * packet: pkt_ov207_0220B954
 * region: ov207
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02034AC4 0x02034AC4 arm
 *   overlay94 0x0000005E data
 *   BTLV_INPUT_CreateDefault 0x02202058 thumb ov094
 *   PALANM_SetAutoTransfer  0x02021EE4  thumb  arm9
 *   PALANM_Create  0x02021518  thumb  arm9
 *   PALANM_AllocSlotBuffers  0x0202155C  thumb  arm9
 */
#include "../include/Obj00174.h"
typedef unsigned short u16;
extern int func_02034AC4(int);
extern char overlay94[];
extern void *PALANM_Create(unsigned);
typedef unsigned int   u32;
struct Obj02021EE4;
struct PalAnmSlot;
extern void PALANM_SetAutoTransfer(struct Obj02021EE4 *o, int v);
extern void PALANM_AllocSlotBuffers(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);
struct Obj;
extern struct Obj *BTLV_INPUT_CreateDefault(int a, int b, int c, int d, int e, u16 k);
void ZUKAN_NICKNAME_InitKeyboard(unsigned *p)
{
    func_02034AC4((int)overlay94);
    p[22]=(unsigned)PALANM_Create(((struct Obj00174 *)p)->f0);
    PALANM_SetAutoTransfer((void *)p[22],1);
    PALANM_AllocSlotBuffers((void *)p[22],1,480,((struct Obj00174 *)p)->f0);
    PALANM_AllocSlotBuffers((void *)p[22],3,480,((struct Obj00174 *)p)->f0);
    p[21]=(unsigned)BTLV_INPUT_CreateDefault((int)((void *)p[8]),0,(int)((void *)p[22]),(int)((void *)p[6]),(int)(p+20),((struct Obj00174 *)p)->f0);
    p[19]=0;
}
