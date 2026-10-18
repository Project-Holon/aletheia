/*
 * function: Wf2dmapFriend_ItemKeyInput
 * address: 0x021C7F14
 * packet: pkt_ov128_021C7F14
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   KEY_GetTrg 0x020362DC arm
 *   KEY_GetRepeat 0x0203633C arm
 *   UI_SetInputMode 0x020355D8 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   Wf2dmapFriend_ItemSelect 0x021C7E78 thumb ov128
 *   WF2DMAP_TOUCH_SetItemHighlight 0x021CA2C4 thumb ov128
 */
#include "../include/Obj03810.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern u32 KEY_GetTrg(void);
extern u32 KEY_GetRepeat(void);
extern void UI_SetInputMode(u8 v);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern int Wf2dmapFriend_ItemSelect(s16 *,u8 *,void *,int);
extern void WF2DMAP_TOUCH_SetItemHighlight(u8 *,int,int);
int Wf2dmapFriend_ItemKeyInput(s16 *p, u8 *a, u8 *ctx)
{
    u16 old;
    int moved;
    int page;
    int dir;
    if(KEY_GetTrg() & 2) {
        UI_SetInputMode(0);
        ((struct Obj03810 *)a)->f0=0;
        return Wf2dmapFriend_ItemSelect(p,a,ctx,0);
    }
    if(KEY_GetTrg() & 1024) {
        UI_SetInputMode(0);
        ((struct Obj03810 *)a)->f0=0;
        return Wf2dmapFriend_ItemSelect(p,a,ctx,6);
    }
    if(((struct Obj03810 *)a)->f0==1) {
        if(KEY_GetTrg() & 0xcf3) {
            GFL_USE_PlaySeDefaultVolume(0x548);
            WF2DMAP_TOUCH_SetItemHighlight(ctx,p[2],p[2]);
            UI_SetInputMode(0);
            ((struct Obj03810 *)a)->f0=0;
        }
        return 0;
    }
    if(KEY_GetTrg() & 1) return Wf2dmapFriend_ItemSelect(p,a,ctx,5);
    old=p[2];
    moved=0;
    page=0;
    if(KEY_GetRepeat() & 64) {
        if(p[2]==0) p[2]=3;
        else if(p[2]==4) p[2]=7;
        else --p[2];
        moved=1;
    } else if(KEY_GetRepeat() & 128) {
        if(p[2]==3) p[2]=0;
        else if(p[2]==7) p[2]=4;
        else ++p[2];
        moved=1;
    } else if(KEY_GetRepeat() & 32) {
        if(p[2]<4) {
            p[2]+=4;
            page=1;
            dir=0;
        } else p[2]-=4;
        moved=1;
    } else if(KEY_GetRepeat() & 16) {
        if(p[2]<4) p[2]+=4;
        else {
            p[2]-=4;
            page=1;
            dir=1;
        }
        moved=1;
    } else if(a[14]) {
        if(a[14] && (KEY_GetRepeat() & 512)) {
            page=1;
            dir=0;
        } else if(a[14] && (KEY_GetRepeat() & 256)) {
            page=1;
            dir=1;
        }
    }
    if(page==1) {
        if(dir) {
            p[1]=p[0];
            p[0]=(p[0]+1)%4;
            return Wf2dmapFriend_ItemSelect(p,a,ctx,2);
        } else {
            p[1]=p[0];
            --p[0];
            if(p[0]<0) p[0]+=4;
            return Wf2dmapFriend_ItemSelect(p,a,ctx,1);
        }
    }
    if(moved==1) {
        GFL_USE_PlaySeDefaultVolume(0x548);
        WF2DMAP_TOUCH_SetItemHighlight(ctx,p[2],old);
        p[3]=old;
    }
    return 0;
}
