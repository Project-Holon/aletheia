/*
 * function: STARTMENU_TitleDemoMain
 * address:  0x021B9750
 * packet:   pkt_ov088_021B9750
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   STARTMENU_ResetDisplayState  0x021B98BC  thumb  ov088
 *   STARTMENU_SetupDisplayBanks  0x021B9910  thumb  ov088
 *   STARTMENU_CaptureInit  0x021B997C  thumb  ov088
 *   STARTMENU_LogoInit  0x021B9A1C  thumb  ov088
 *   STARTMENU_Demo3dInit  0x021B9C2C  thumb  ov088
 *   STARTMENU_SpritesInit  0x021B9EC4  thumb  ov088
 *   STARTMENU_TitleDemoUpdateParts  0x021B9928  thumb  ov088
 *   STARTMENU_TitleDemoCheckInput  0x021B965C  thumb  ov088
 *   STARTMENU_TitleDemoUpdateTimer  0x021B95CC  thumb  ov088
 *   STARTMENU_SpritesDelete  0x021B9F70  thumb  ov088
 *   STARTMENU_Demo3dDelete  0x021B9E54  thumb  ov088
 *   STARTMENU_LogoDelete  0x021B9C08  thumb  ov088
 *   STARTMENU_CaptureDelete  0x021B99EC  thumb  ov088
 *   FADE_Start  0x0204E720  arm
 *   FADE_IsActive  0x0204E804  arm
 *   GFL_USE_PlayFanfare  0x02005DAC  thumb
 *   PM_VOICE_IsActive  0x02006BD0  thumb
 *   GFL_USE_FadeOutBgm  0x02005E30  thumb
 *   GFL_USE_IsBgmFading  0x02005E50  thumb
 *   GFL_USE_CancelChangeAndStopBgm  0x02005D28  thumb
 */
#include "../include/Obj00462.h"

typedef unsigned short u16;
typedef unsigned int   u32;

extern void STARTMENU_ResetDisplayState(void);
extern void STARTMENU_SetupDisplayBanks(void);
extern void STARTMENU_CaptureInit(int *p, int heap);
extern void STARTMENU_LogoInit(void *p, int heap);
extern void STARTMENU_Demo3dInit(void *p, int heap);
extern void STARTMENU_SpritesInit(int *p, int heap);
extern void STARTMENU_TitleDemoUpdateParts(unsigned char *p);
typedef signed int     s32;
extern void STARTMENU_TitleDemoCheckInput(char *p);
extern void STARTMENU_TitleDemoUpdateTimer(char *p);
extern void STARTMENU_SpritesDelete(int *p);
extern void STARTMENU_Demo3dDelete(int *p);
extern void STARTMENU_LogoDelete(int *p);
extern void STARTMENU_CaptureDelete(int *p);
extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);
extern int  FADE_IsActive(void);
extern void GFL_USE_PlayFanfare(void *arg);
extern u32  PM_VOICE_IsActive(u32 a);
extern void GFL_USE_FadeOutBgm(u32 a);
extern int  GFL_USE_IsBgmFading(void);
extern void GFL_USE_CancelChangeAndStopBgm(void);

int STARTMENU_TitleDemoMain(int a0, int a1, int a2, char *p)
{
    switch (((struct Obj00462 *)p)->f0) {
    case 0:
        STARTMENU_ResetDisplayState();
        STARTMENU_SetupDisplayBanks();
        ((struct Obj00462 *)p)->f0 = 1;
        break;
    case 1:
        STARTMENU_CaptureInit((int *)(p + 8), ((struct Obj00462 *)p)->f2);
        STARTMENU_LogoInit(p + 0x14, ((struct Obj00462 *)p)->f2);
        STARTMENU_Demo3dInit(p + 0x40, ((struct Obj00462 *)p)->f2);
        STARTMENU_SpritesInit((int *)(p + 0x54), ((struct Obj00462 *)p)->f2);
        FADE_Start(3, 0x10, 0, 2);
        ((struct Obj00462 *)p)->f8C = 0;
        ((struct Obj00462 *)p)->f0 = 2;
        GFL_USE_PlayFanfare((void *)0x3EF);
        break;
    case 2:
        if (FADE_IsActive() == 0) {
            ((struct Obj00462 *)p)->f0 = 3;
        }
        STARTMENU_TitleDemoUpdateParts((unsigned char *)p);
        break;
    case 3:
        STARTMENU_TitleDemoUpdateParts((unsigned char *)p);
        STARTMENU_TitleDemoCheckInput(p);
        STARTMENU_TitleDemoUpdateTimer(p);
        break;
    case 4:
        if (PM_VOICE_IsActive(*(u32 *)&((struct Obj00462 *)p)->f90) == 0) {
            ((struct Obj00462 *)p)->f0 = 5;
        }
        STARTMENU_TitleDemoUpdateParts((unsigned char *)p);
        break;
    case 5:
        FADE_Start(3, 0, 0x10, 2);
        ((struct Obj00462 *)p)->f0 = 6;
        STARTMENU_TitleDemoUpdateParts((unsigned char *)p);
        GFL_USE_FadeOutBgm(0x10);
        break;
    case 6:
        if (FADE_IsActive() == 0 && GFL_USE_IsBgmFading() == 0) {
            GFL_USE_CancelChangeAndStopBgm();
            ((struct Obj00462 *)p)->f0 = 7;
        }
        STARTMENU_TitleDemoUpdateParts((unsigned char *)p);
        break;
    case 7:
        STARTMENU_SpritesDelete((int *)(p + 0x54));
        STARTMENU_Demo3dDelete((int *)(p + 0x40));
        STARTMENU_LogoDelete((int *)(p + 0x14));
        STARTMENU_CaptureDelete((int *)(p + 8));
        return 1;
    case 8:
        return 1;
    }
    return 0;
}
