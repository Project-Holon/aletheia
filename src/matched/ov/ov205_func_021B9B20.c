/*
 * function: func_021B9B20
 * address: 0x021B9B20
 * packet: pkt_ov205_021B9B20
 * region: ov205
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02088864 0x02088864 arm
 *   GAME_DATA_GetMyParty 0x02012934 thumb
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   SAVE_CONTROL_LoadExtraSave 0x0200725C thumb
 *   func_020073D8 0x020073D8 thumb
 *   func_020071F0 0x020071F0 thumb
 *   MISC_SAVEDATA_AppendPartyRecord 0x0200EBD0 thumb
 *   GAME_DATA_PartSaveStart 0x02012E4C thumb
 */
#include "../include/Obj08386.h"
typedef unsigned char u8;
struct RTCDate;
extern int func_02088864(struct RTCDate *date);
typedef unsigned int   u32;
struct Big;
struct BigObj;
struct Ctrl;
struct Obj;
struct Sub020071E4Ctrl;
struct Sub020073D8Ctrl;
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern u32 SAVE_CONTROL_LoadExtraSave(struct Ctrl *ctrl, u32 id, u8 heap);
extern void *func_020073D8(struct Sub020073D8Ctrl *ctrl, u32 id, u32 v);
extern int func_020071F0(struct Sub020071E4Ctrl *ctrl);
extern void MISC_SAVEDATA_AppendPartyRecord(struct Obj *obj, void *a1, void *date, u32 heap);
extern void GAME_DATA_PartSaveStart(u8 *p, u32 a);
void func_021B9B20(char *p)
{
    unsigned date[4];
    void *save,*object,*record;
    func_02088864((struct RTCDate *)date);
    object=GAME_DATA_GetMyParty(((struct Obj08386 *)p)->f4);
    save=GAME_DATA_GetSaveControl(((struct Obj08386 *)p)->f4);
    SAVE_CONTROL_LoadExtraSave(save,8,4);
    record=func_020073D8(save,8,0);
    if(func_020071F0(save)==0) {
        MISC_SAVEDATA_AppendPartyRecord(record,object,date,4);
        GAME_DATA_PartSaveStart(((struct Obj08386 *)p)->f4,8);
        ((struct Obj08386 *)p)->f38=1;
    }
}
