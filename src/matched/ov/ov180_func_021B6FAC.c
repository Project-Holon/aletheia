/*
 * function: HALL_OF_FAME_StateTrainerScene
 * address: 0x021B6FAC
 * packet: pkt_ov180_021B6FAC
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Caller evidence: 021B74B4 leaves its forwarded return in r0, read here; 02005E50 is the matched zero-argument GFL_USE_IsBgmFading.
 * symbols:
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   GFL_USE_IsBgmFading 0x02005E50 thumb
 *   GFL_USE_CancelChangeAndStopBgm 0x02005D28 thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   HALL_OF_FAME_BeginCountdown 0x021B7268 thumb ov180
 *   HALL_OF_FAME_MoveActorRelative 0x021B7438 thumb ov180
 *   HALL_OF_FAME_SetActorVisible 0x021B746C thumb ov180
 *   HALL_OF_FAME_PlayActorAnim 0x021B7488 thumb ov180
 *   HALL_OF_FAME_IsActorAnimActive 0x021B74B4 thumb ov180
 *   HALL_OF_FAME_SetPlateEnabled 0x021B7C60 thumb ov180
 *   HALL_OF_FAME_AddMonSprite 0x021B692C thumb ov180
 *   HALL_OF_FAME_MoveMonSpriteX 0x021B699C thumb ov180
 *   MCSS_ResetAnmStopFlag 0x02015E4C thumb
 *   HALL_OF_FAME_StartMonAnimCallback 0x021B69F8 thumb ov180
 *   HALL_OF_FAME_DeleteMonSprite 0x021B6984 thumb ov180
 *   HALL_OF_FAME_SpawnSparkles 0x021B7F38 thumb ov180
 *   KEY_GetTrg 0x020362DC arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb
 *   HALL_OF_FAME_BeginFadeOut 0x021B723C thumb ov180
 */
#include "../include/Obj00242.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
extern u32 WIPE_SYS_EndCheck(void);
extern u32 KEY_GetTrg(void);
extern int TOUCHPANEL_GetTrg(void);
extern int GFL_USE_IsBgmFading(void);
extern void GFL_USE_CancelChangeAndStopBgm(void),GFL_USE_PlaySeDefaultVolume(u32),GFL_USE_FadeOutBgm(u32),MCSS_ResetAnmStopFlag(void *);
extern int HALL_OF_FAME_BeginCountdown(char *,int);
extern int HALL_OF_FAME_BeginFadeOut(char *,int,int);
extern int HALL_OF_FAME_IsActorAnimActive(int *p, int i);
extern void HALL_OF_FAME_MoveActorRelative(u8 *p, int n, int x, int y);
extern void HALL_OF_FAME_SetActorVisible(int *,int,int);
extern void HALL_OF_FAME_PlayActorAnim(u8 *p, int n, int v);
extern void HALL_OF_FAME_SetPlateEnabled(char *p, int index, unsigned value);
extern void HALL_OF_FAME_AddMonSprite(char *),HALL_OF_FAME_MoveMonSpriteX(char *,int),HALL_OF_FAME_StartMonAnimCallback(char *),HALL_OF_FAME_DeleteMonSprite(char *),HALL_OF_FAME_SpawnSparkles(char *);
int HALL_OF_FAME_StateTrainerScene(char *p) {
    int ready;
    if(((struct Obj00242 *)p)->f9198==1 && WIPE_SYS_EndCheck()==1 && GFL_USE_IsBgmFading()==0) { GFL_USE_CancelChangeAndStopBgm();return 9; }
    switch(((struct Obj00242 *)p)->f9190) {
    case 0: ++((struct Obj00242 *)p)->f9190;return HALL_OF_FAME_BeginCountdown(p,32);
    case 1: GFL_USE_PlaySeDefaultVolume(0x79D);++((struct Obj00242 *)p)->f9190;break;
    case 2:
        if(((struct Obj00242 *)p)->f9188!=51) {HALL_OF_FAME_MoveActorRelative((u8 *)p,5,0,8);HALL_OF_FAME_MoveActorRelative((u8 *)p,6,0,8);++((struct Obj00242 *)p)->f9188;}
        else {GFL_USE_PlaySeDefaultVolume(0x57A);++((struct Obj00242 *)p)->f9190;return HALL_OF_FAME_BeginCountdown(p,32);}break;
    case 3:
        HALL_OF_FAME_SetActorVisible((int *)p,7,1);HALL_OF_FAME_SetActorVisible((int *)p,8,1);HALL_OF_FAME_PlayActorAnim((u8 *)p,7,2);HALL_OF_FAME_PlayActorAnim((u8 *)p,8,2);++((struct Obj00242 *)p)->f9190;break;
    case 4: if(HALL_OF_FAME_IsActorAnimActive((int *)p,7)==0){GFL_USE_PlaySeDefaultVolume(0x79E);++((struct Obj00242 *)p)->f9190;return HALL_OF_FAME_BeginCountdown(p,16);}break;
    case 5: HALL_OF_FAME_SetPlateEnabled(p,3,1);++((struct Obj00242 *)p)->f9190;return HALL_OF_FAME_BeginCountdown(p,32);
    case 6: HALL_OF_FAME_SetPlateEnabled(p,2,1);++((struct Obj00242 *)p)->f9190;break;
    case 7: if(((struct Obj00242 *)p)->f9188==300){((struct Obj00242 *)p)->f9188=0;++((struct Obj00242 *)p)->f9190;}else ++((struct Obj00242 *)p)->f9188;break;
    case 8:
        ready=0;
        if(((struct Obj00242 *)p)->f915D==0) {if(((struct Obj00242 *)p)->f9188==256)ready=1;}
        else {if(((struct Obj00242 *)p)->f9188==128)ready=1;}
        if(ready==1){HALL_OF_FAME_AddMonSprite(p);((struct Obj00242 *)p)->f9188=0;++((struct Obj00242 *)p)->f9190;}else ++((struct Obj00242 *)p)->f9188;break;
    case 9:
        if(((struct Obj00242 *)p)->f9188!=20){HALL_OF_FAME_MoveMonSpriteX(p,-8);++((struct Obj00242 *)p)->f9188;}else{MCSS_ResetAnmStopFlag(((struct Obj00242 *)p)->f1C);((struct Obj00242 *)p)->f9188=0;++((struct Obj00242 *)p)->f9190;}break;
    case 10: if(((struct Obj00242 *)p)->f9188!=128)++((struct Obj00242 *)p)->f9188;else{HALL_OF_FAME_StartMonAnimCallback(p);((struct Obj00242 *)p)->f9188=0;++((struct Obj00242 *)p)->f9190;}break;
    case 11:
        if(((struct Obj00242 *)p)->f24!=0){
            if(((struct Obj00242 *)p)->f9188!=24){HALL_OF_FAME_MoveMonSpriteX(p,-8);++((struct Obj00242 *)p)->f9188;}
            else{HALL_OF_FAME_DeleteMonSprite(p);((struct Obj00242 *)p)->f9188=0;++((struct Obj00242 *)p)->f915D;if(((struct Obj00242 *)p)->f915D==((struct Obj00242 *)p)->f915E)((struct Obj00242 *)p)->f915D=0;((struct Obj00242 *)p)->f9190=8;}
        }break;
    }
    if(((struct Obj00242 *)p)->f9190>=6)HALL_OF_FAME_SpawnSparkles(p);
    if(((struct Obj00242 *)p)->f9190>=8 && ((struct Obj00242 *)p)->f9198==0 && ((KEY_GetTrg()&3)!=0 || TOUCHPANEL_GetTrg()==1)){
        ((struct Obj00242 *)p)->f9198=1;GFL_USE_FadeOutBgm(220);HALL_OF_FAME_BeginFadeOut(p,9,188);
    }
    return 8;
}
