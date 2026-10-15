/*
 * function: ZUKAN_NICKNAME_DeleteKeyboard
 * address: 0x0220B9B0
 * packet: pkt_ov207_0220B9B0
 * region: ov207
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: pooled FS overlay ID is the overlay94 linker symbol address, as in matched ov207 0220B048; literal 94 compiles as movs.
 * symbols:
 *   BTLV_INPUT_Delete 0x022021F4 thumb ov094
 *   PALANM_FreeSlotBuffers 0x020215A0 thumb
 *   PALANM_Delete 0x02021540 thumb
 *   func_02034A5C 0x02034A5C arm
 *   overlay94 0x0000005E data
 */
#include "../include/Obj01975.h"
typedef struct Obj Obj;struct PalAnmSlot;extern void BTLV_INPUT_Delete(Obj *);extern void PALANM_FreeSlotBuffers(struct PalAnmSlot *,unsigned);extern void PALANM_Delete(struct PalAnmSlot *);extern void func_02034A5C(int);
extern char overlay94[];
void ZUKAN_NICKNAME_DeleteKeyboard(char *p){BTLV_INPUT_Delete(*(Obj * *)&((struct Obj01975 *)p)->f54);PALANM_FreeSlotBuffers(*(struct PalAnmSlot * *)&((struct Obj01975 *)p)->f58,1);PALANM_FreeSlotBuffers(*(struct PalAnmSlot * *)&((struct Obj01975 *)p)->f58,3);PALANM_Delete(*(struct PalAnmSlot * *)&((struct Obj01975 *)p)->f58);*(unsigned *)&((struct Obj01975 *)p)->f58=0;func_02034A5C((int)overlay94);}
