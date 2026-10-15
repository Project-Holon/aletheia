/*
 * function: MANUAL_COMMON_UpdateDialogInput
 * address: 0x021BB53C
 * packet: pkt_ov225_021BB53C
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Lever: unhinted BF9C data uses this function's own overlay region.
 * symbols:
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   func_020355C4 0x020355C4 arm
 *   func_020355D8 0x020355D8 arm
 *   KEY_GetTrg 0x020362DC arm
 *   KEY_GetRepeat 0x0203633C arm
 *   APP_TASKMENU_WIN_SetActive 0x02028218 thumb
 *   APP_TASKMENU_WIN_SetDecide 0x0202822C thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   gManualCommonDialogHitRects 0x021BBF9C data a4
 */
#include "../include/Obj00740.h"
typedef unsigned char u8;
extern const u8 gManualCommonDialogHitRects[];
extern int TOUCHPANEL_HitTrg(const void *);
extern u8 func_020355C4(void);
extern void func_020355D8(u8);
extern unsigned KEY_GetTrg(void),KEY_GetRepeat(void);
typedef unsigned int   u32;
struct Obj;
extern void APP_TASKMENU_WIN_SetActive(struct Obj *obj, u32 a);
extern void APP_TASKMENU_WIN_SetDecide(char *p, int v);
extern void GFL_USE_PlaySeDefaultVolume(unsigned);
int MANUAL_COMMON_UpdateDialogInput(char *p)
{
    int hit=TOUCHPANEL_HitTrg(gManualCommonDialogHitRects);
    if(func_020355C4()==0) {
        if(hit>=0 && hit<=1) {
            func_020355D8(1);
            APP_TASKMENU_WIN_SetActive(*(void **)(p+**(u8 * *)&((struct Obj00740 *)p)->f0*4+0xc),0);
        }
    } else {
        if(KEY_GetTrg()!=0 && !(KEY_GetTrg()&0x402)) {
            func_020355D8(0);
            APP_TASKMENU_WIN_SetActive(*(void **)(p+**(u8 * *)&((struct Obj00740 *)p)->f0*4+0xc),1);
            GFL_USE_PlaySeDefaultVolume(0x548);
            return 0;
        }
    }
    if(func_020355C4()==0) {
        if(KEY_GetTrg()&1) {
            APP_TASKMENU_WIN_SetDecide(*(void **)(p+**(u8 * *)&((struct Obj00740 *)p)->f0*4+0xc),1);
            GFL_USE_PlaySeDefaultVolume(0x54c);
            return 1;
        } else if(KEY_GetRepeat()&0x40) {
            APP_TASKMENU_WIN_SetActive(*(void **)(p+**(u8 * *)&((struct Obj00740 *)p)->f0*4+0xc),0);
            if(**(u8 * *)&((struct Obj00740 *)p)->f0==0) **(u8 * *)&((struct Obj00740 *)p)->f0=1; else **(u8 * *)&((struct Obj00740 *)p)->f0=0;
            APP_TASKMENU_WIN_SetActive(*(void **)(p+**(u8 * *)&((struct Obj00740 *)p)->f0*4+0xc),1);
            GFL_USE_PlaySeDefaultVolume(0x548);
        } else if(KEY_GetRepeat()&0x80) {
            APP_TASKMENU_WIN_SetActive(*(void **)(p+**(u8 * *)&((struct Obj00740 *)p)->f0*4+0xc),0);
            if(**(u8 * *)&((struct Obj00740 *)p)->f0==1) **(u8 * *)&((struct Obj00740 *)p)->f0=0; else **(u8 * *)&((struct Obj00740 *)p)->f0=1;
            APP_TASKMENU_WIN_SetActive(*(void **)(p+**(u8 * *)&((struct Obj00740 *)p)->f0*4+0xc),1);
            GFL_USE_PlaySeDefaultVolume(0x548);
        } else if(KEY_GetRepeat()&0x220) {
            if(**(u8 * *)&((struct Obj00740 *)p)->f0==1) {
                APP_TASKMENU_WIN_SetActive(*(void **)(p+**(u8 * *)&((struct Obj00740 *)p)->f0*4+0xc),0);
                **(u8 * *)&((struct Obj00740 *)p)->f0=0;
                APP_TASKMENU_WIN_SetActive(*(void **)(p+**(u8 * *)&((struct Obj00740 *)p)->f0*4+0xc),1);
                GFL_USE_PlaySeDefaultVolume(0x548);
            }
        } else if(KEY_GetRepeat()&0x110) {
            if(**(u8 * *)&((struct Obj00740 *)p)->f0==0) {
                APP_TASKMENU_WIN_SetActive(*(void **)(p+**(u8 * *)&((struct Obj00740 *)p)->f0*4+0xc),0);
                **(u8 * *)&((struct Obj00740 *)p)->f0=1;
                APP_TASKMENU_WIN_SetActive(*(void **)(p+**(u8 * *)&((struct Obj00740 *)p)->f0*4+0xc),1);
                GFL_USE_PlaySeDefaultVolume(0x548);
            }
        }
    } else if(hit>=0 && hit<=1) {
        **(u8 * *)&((struct Obj00740 *)p)->f0=hit;
        APP_TASKMENU_WIN_SetActive(*(void **)(p+**(u8 * *)&((struct Obj00740 *)p)->f0*4+0xc),1);
        APP_TASKMENU_WIN_SetDecide(*(void **)(p+**(u8 * *)&((struct Obj00740 *)p)->f0*4+0xc),1);
        GFL_USE_PlaySeDefaultVolume(0x54c);
        return 1;
    }
    return 0;
}
