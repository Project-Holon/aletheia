/*
 * function: func_0217D244
 * address: 0x0217D244
 * packet: pkt_ov176_0217D244
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of zero alignment padding follow.
 * symbols:
 *   func_021E5548 0x021E5548 thumb ov177
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   BATTLE_BOX_GetFromSave 0x0200BAC8 thumb
 *   func_021E7E3C 0x021E7E3C thumb ov177
 */
#include "../include/Obj00053.h"
struct Big;
extern int func_021E5548(int *p);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *BATTLE_BOX_GetFromSave(void *p);
extern int func_021E7E3C(int,int,int,int,int,int,unsigned short);
void func_0217D244(char *p)
{
    int a;
    if (((struct Obj00053 *)p)->f18 == 0) {
        a = func_021E5548((int *)(*(int *)&((struct Obj00053 *)p)->f1B4));
        ((struct Obj00053 *)p)->f18 = func_021E7E3C((int)BATTLE_BOX_GetFromSave(GAME_DATA_GetSaveControl((struct Big *)(*(int *)&((struct Obj00053 *)p)->f1B8))), a,
            ((struct Obj00053 *)p)->f1B0, ((struct Obj00053 *)p)->f28, *(int *)&((struct Obj00053 *)p)->f1AC, *(int *)&((struct Obj00053 *)p)->f24, ((struct Obj00053 *)p)->f1C8);
    }
}
