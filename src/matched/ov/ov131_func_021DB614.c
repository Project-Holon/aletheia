/*
 * function: P_STA_SKILL_SetNewMoveHeld
 * address: 0x021DB614
 * packet: pkt_ov131_021DB614
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B878 0x0204B878 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   P_STA_OAM_SetBitmapActorsEnabled 0x021DBCA4 thumb ov131
 *   P_STA_OAM_TransferBitmap 0x021DBCF4 thumb ov131
 *   P_STA_SKILL_SetSlotAnim 0x021DBA78 thumb ov131
 */
#include "../include/Obj00026.h"
#include "../include/Obj06486.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct Obj;
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void P_STA_OAM_SetBitmapActorsEnabled(u8 *p, int v);
extern void P_STA_OAM_TransferBitmap(u8 *p);
extern void P_STA_SKILL_SetSlotAnim(u8 *,int);
void P_STA_SKILL_SetNewMoveHeld(void *a,u8 *b,int c) {
    u8 *p=b+272;
    if(c==1) {
        func_0204B878(((struct Obj06486 *)p)->f8,16);
        P_STA_OAM_SetBitmapActorsEnabled(((struct Obj06486 *)p)->f14,0);
        func_0204B3DC(((struct Obj06486 *)p)->fC,0);
        P_STA_OAM_TransferBitmap(((struct Obj00026 *)b)->fAC);
        P_STA_OAM_SetBitmapActorsEnabled(((struct Obj00026 *)b)->fAC,1);
    } else {
        P_STA_OAM_SetBitmapActorsEnabled(((struct Obj00026 *)b)->fAC,0);
        func_0204B3DC(((struct Obj06486 *)p)->fC,1);
        if(b[41]==4) P_STA_SKILL_SetSlotAnim(p,1); else P_STA_SKILL_SetSlotAnim(p,0);
        P_STA_OAM_SetBitmapActorsEnabled(((struct Obj06486 *)p)->f14,1);
    }
}
