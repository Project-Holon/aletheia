/*
 * function: WIFILOGIN_DISP_DeleteDisplay
 * address: 0x021D4E04
 * packet: pkt_ov115_021D4E04
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFILOGIN_DISP_DeleteActors 0x021D584C thumb ov115
 *   func_02030EAC 0x02030EAC arm
 *   BG_SYS_SetTileUnit 0x02040DA8 arm
 *   func_020403F4 0x020403F4 arm
 *   func_02040588 0x02040588 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj02170.h"
typedef unsigned char u8;
extern void WIFILOGIN_DISP_DeleteActors(u8 *);
typedef unsigned int   u32;
struct Node;
extern void func_02030EAC(struct Node *n);
extern void BG_SYS_SetTileUnit(u32 idx, u32 count, u32 tile);
extern void func_020403F4(u32 i);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void BG_SYS_Delete(void);
extern u32 func_020307B0(void *p);
void WIFILOGIN_DISP_DeleteDisplay(u8 *p) {
    if (((struct Obj02170 *)p)->f8 == 1) WIFILOGIN_DISP_DeleteActors(p);
    else if (((struct Obj02170 *)p)->f10) {
        func_02030EAC(((struct Obj02170 *)p)->f10);
        ((struct Obj02170 *)p)->f10 = 0;
        ((struct Obj02170 *)p)->f14 = 0;
    }
    BG_SYS_SetTileUnit(5, 1, 0);
    BG_SYS_SetTileUnit(6, 1, 0);
    func_020403F4(5);
    func_020403F4(4);
    func_02040588(5, 0);
    BG_SYS_Delete();
    func_020307B0(p);
}
