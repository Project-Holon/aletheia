/*
 * function: ZUKAN_DETAIL_INFO_HandleKeyLanguageSelect
 * address: 0x021BF088
 * packet: pkt_ov208_021BF088
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ZUKAN_DETAIL_COMMON_GetWorkPtr 0x021BC3B4 thumb ov208
 *   KEY_GetRepeat 0x0203633C arm
 *   KEY_GetTrg 0x020362DC arm
 *   CLACT_GetActorDrawEnable 0x0204B3F4 arm
 *   ZUKAN_DETAIL_INFO_SelectLanguageButton 0x021BF280 thumb ov208
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   func_020355D8 0x020355D8 arm
 *   ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled 0x021BDC48 thumb ov208
 */
#include "../include/Obj00442.h"
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;
struct Obj;
struct Ov208Scene;
extern int ZUKAN_DETAIL_COMMON_GetWorkPtr(int *p);
extern u32 KEY_GetRepeat(void);
extern u32 KEY_GetTrg(void);
extern u32 CLACT_GetActorDrawEnable(struct Obj *);
extern void ZUKAN_DETAIL_INFO_SelectLanguageButton(void *,char *,void *,int);
extern void CLACT_SetActorAnimSeq(struct Obj *,u16);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern void func_020355D8(u8);
extern void ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled(struct Ov208Scene *,u32);
int ZUKAN_DETAIL_INFO_HandleKeyLanguageSelect(void *first,char *p,int key)
{
    void *scene;
    int changed;
    u32 buttons,press;
    u8 i,next;
    scene=(void *)ZUKAN_DETAIL_COMMON_GetWorkPtr((int *)key);
    changed=0;
    if(((struct Obj00442 *)p)->f94==6) {
        buttons=KEY_GetRepeat();
        press=KEY_GetTrg();
        if(((struct Obj00442 *)p)->f98==6) {
            if((buttons&0x300)||(press&1)) {
                for(i=0;i<6;i++) {
                    if(CLACT_GetActorDrawEnable(*(struct Obj **)((u32)p+(u32)i*20+0x1c))!=0) {
                        ((struct Obj00442 *)p)->f94=i; changed=1; break;
                    }
                }
            }
        } else if((buttons&0x100)||(press&1)) {
            for(i=1;i<6;i++) {
                next=(((struct Obj00442 *)p)->f98+i)%6;
                if(CLACT_GetActorDrawEnable(*(struct Obj **)((u32)p+(u32)next*20+0x1c))!=0) {
                    ((struct Obj00442 *)p)->f94=next; changed=1; break;
                }
            }
        } else if(buttons&0x200) {
            for(i=1;i<6;i++) {
                next=(((struct Obj00442 *)p)->f98+6-i)%6;
                if(CLACT_GetActorDrawEnable(*(struct Obj **)((u32)p+(u32)next*20+0x1c))!=0) {
                    ((struct Obj00442 *)p)->f94=next; changed=1; break;
                }
            }
        }
    }
    if(changed!=0) {
        ZUKAN_DETAIL_INFO_SelectLanguageButton(first,p,(void *)key,((struct Obj00442 *)p)->f94);
        *(u32 *)((u32)p+*(u32 *)&((struct Obj00442 *)p)->f94*20+0x2c)=1;
        CLACT_SetActorAnimSeq(*(struct Obj **)((u32)p+*(u32 *)&((struct Obj00442 *)p)->f94*20+0x1c),*(u16 *)((u32)p+*(u32 *)&((struct Obj00442 *)p)->f94*20+0x26));
        GFL_USE_PlaySeDefaultVolume(0x54a);
        func_020355D8(0);
        ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled(scene,0);
    }
    return changed;
}
