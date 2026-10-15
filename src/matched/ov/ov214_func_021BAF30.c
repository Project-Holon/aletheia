/*
 * unit: no
 * function: BTL_REC_SEL_DeletePalanm
 * address: 0x021BAF30
 * packet: pkt_ov214_021BAF30
 * region: ov214
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * evidence: caller explicitly loads r0 for 02021540 and 02030DA4; preserve these pointer arguments despite legacy void declarations. 02021540 forwards unchanged to 020307B0.
 * symbols:
 *   PALANM_FreeSlotBuffers 0x020215A0 thumb
 *   PALANM_Delete 0x02021540 thumb
 *   TCB_Noop 0x02030DA4 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj00636.h"
typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
struct PalAnmSlot;extern void PALANM_FreeSlotBuffers(struct PalAnmSlot *,u32);extern void PALANM_Delete(void *);extern void TCB_Noop(void *);extern void func_020307B0(void *);
void BTL_REC_SEL_DeletePalanm(int unused,u8 *p){PALANM_FreeSlotBuffers(*(struct PalAnmSlot * *)&((struct Obj00636 *)p)->f2E0,0);PALANM_FreeSlotBuffers(*(struct PalAnmSlot * *)&((struct Obj00636 *)p)->f2E0,2);PALANM_Delete(((struct Obj00636 *)p)->f2E0);TCB_Noop(((struct Obj00636 *)p)->f2D8);func_020307B0(((struct Obj00636 *)p)->f2DC);}
