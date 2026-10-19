/*
 * function: GURU2_MAIN_RegisterPlayerRecords
 * address: 0x021DEF6C
 * packet: pkt_ov137_021DEF6C
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: two zero alignment bytes at 0x021DEFB2.
 * symbols:
 *   GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 *   MET_TRAINERS_GetFromSave 0x0200ED48 thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb  arm9
 *   MET_TRAINERS_Insert  0x0200ED54  thumb  arm9
 */
#include "../include/Obj10621.h"
#include "../include/Obj23750.h"
#include "../include/Obj23751.h"
typedef unsigned char u8;
typedef struct { u8 pad[0x90]; void *slots[5]; } Obj;
typedef unsigned short u16;
typedef unsigned int   u32;
struct Big;
struct L0200ED54;
struct Sub0200852CObj;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *MET_TRAINERS_GetFromSave(void *);
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern void MET_TRAINERS_Insert(struct L0200ED54 *l, u32 val);
void GURU2_MAIN_RegisterPlayerRecords(Obj *obj)
{
    u8 *p = (u8 *)obj;
    void *q;
    int i;
    q = MET_TRAINERS_GetFromSave(GAME_DATA_GetSaveControl(((struct Obj23751 *)(*(u8 * *)&((struct Obj23750 *)(*(u8 * *)&((struct Obj10621 *)p)->fD8))->f14))->f4));
    for (i = 0; i < 5; i++) {
        if (obj->slots[i] && i != GFL_NET_SYSTEM_GetCurrentAid())
            MET_TRAINERS_Insert(q, func_02008530(obj->slots[i]));
    }
}
