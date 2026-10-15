/*
 * function: BSUBWAY_SCR_LoadPartyCopy
 * address:  0x021CA1E4
 * packet:   pkt_ov021_021CA1E4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Releases the handle at +0x7c8 and allocates a fresh one from the object at +0x6c.
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   BATTLE_BOX_GetFromSave  0x0200BAC8  thumb
 *   func_0200BAF4  0x0200BAF4  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj07584.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_020307B0(void *p);
struct Big;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *BATTLE_BOX_GetFromSave(void *p);
extern void *func_0200BAF4(int a0, int a1);

void BSUBWAY_SCR_LoadPartyCopy(u8 *p)
{
    if (((struct Obj07584 *)p)->f7C8 != 0)
        func_020307B0(((struct Obj07584 *)p)->f7C8);
    ((struct Obj07584 *)p)->f7C8 = func_0200BAF4((int)BATTLE_BOX_GetFromSave(GAME_DATA_GetSaveControl((struct Big *)(((struct Obj07584 *)p)->f6C))), 4);
}
