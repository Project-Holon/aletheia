/*
 * function: WORLDTRADE_LIST_StateMainInput
 * address: 0x021FD3CC
 * packet: pkt_ov135_021FD3CC
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * prototype: 021FD6F4 retains r2=1,r3=0,sp=0xF0F visibly loaded by this caller.
 * symbols:
 *   KEY_GetTrg 0x020362DC arm
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   WIPE_SYS_Start 0x0202208C thumb
 *   WORLDTRADE_LIST_PrintMessage 0x021FD6F4 thumb ov135
 *   WORLDTRADE_SetNextState 0x021F4E98 thumb ov135
 *   WORLDTRADE_LIST_SelectCursorEntry 0x021FD368 thumb ov135
 *   WORLDTRADE_SUBLCD_CheckButtonTouch 0x021FFB00 thumb ov135
 *   tbl_02203608 0x02203608 data a1
 *   tbl_022035FC 0x022035FC data a1
 */
#include "../include/Obj01063.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct {u8 left,right;} Pair;
extern const Pair tbl_02203608[];
extern const u8 tbl_022035FC[];
extern u32 KEY_GetTrg(void);
extern int TOUCHPANEL_HitTrg(const void *);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern void WIPE_SYS_Start(void *,u32,u32,u32,u32,u32,u32);
extern void WORLDTRADE_LIST_PrintMessage(u8 *p, u32 k, u32 a2, u32 a3, u32 a4);
extern void WORLDTRADE_SetNextState(u8 *p, u32 a, u32 b);
extern void WORLDTRADE_LIST_SelectCursorEntry(u8 *,int);
extern int WORLDTRADE_SUBLCD_CheckButtonTouch(int);
int WORLDTRADE_LIST_StateMainInput(u8 *p)
{
    int next, r;
    if(KEY_GetTrg()&1) {
        WORLDTRADE_LIST_PrintMessage(p,16,1,0,0xF0F);
        WORLDTRADE_SetNextState(p,3,4);
        GFL_USE_PlaySeDefaultVolume(0x54C);
    } else if(KEY_GetTrg()&2) {
        WIPE_SYS_Start(0,0,0,0,16,1,0x48);
        ((struct Obj01063 *)p)->f28=8;
        GFL_USE_PlaySeDefaultVolume(0x551);
    } else if(KEY_GetTrg()&32) {
        next=tbl_02203608[(u32)*(int *)(p+0xD4)].left;
        if(((struct Obj01063 *)p)->fD4!=next && ((struct Obj01063 *)p)->fD0>=next+1)
            WORLDTRADE_LIST_SelectCursorEntry(p,next);
    } else if(KEY_GetTrg()&16) {
        next=tbl_02203608[(u32)*(int *)(p+0xD4)].right;
        if(((struct Obj01063 *)p)->fD4!=next && ((struct Obj01063 *)p)->fD0>=next+1)
            WORLDTRADE_LIST_SelectCursorEntry(p,next);
    } else {
        r=WORLDTRADE_SUBLCD_CheckButtonTouch(((struct Obj01063 *)p)->fD0);
        if(r!=-1) WORLDTRADE_LIST_SelectCursorEntry(p,r);
        r=TOUCHPANEL_HitTrg(tbl_022035FC);
        if(r==0) {
            WORLDTRADE_LIST_PrintMessage(p,16,1,0,0xF0F);
            WORLDTRADE_SetNextState(p,3,4);
            GFL_USE_PlaySeDefaultVolume(0x54C);
        } else if(r==1) {
            WIPE_SYS_Start(0,0,0,0,16,1,0x48);
            ((struct Obj01063 *)p)->f28=8;
            GFL_USE_PlaySeDefaultVolume(0x551);
        }
    }
    return 2;
}
