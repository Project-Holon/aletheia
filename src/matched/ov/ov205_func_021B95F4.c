/*
 * function: func_021B95F4
 * address: 0x021B95F4
 * packet: pkt_ov205_021B95F4
 * region: ov205
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: Case3 early nonzero break restores the branch stub; case9 separate calls in if/else restore its independent fade BL. Fixed one EXACT, 624 bytes, 43/43 resolved.
 * volatile: DISPCNT 0x04000000 read at 021B9650 and written at 021B965A.
 * symbols:
 *   init 0x021B9E50 data a2
 *   KEY_GetTrg 0x020362DC arm
 *   func_021B9874 0x021B9874 thumb ov205
 *   GPOWER_GetSpecialPowerId 0x020111E8 thumb
 *   func_0207E468 0x0207E468 arm
 *   FADE_Start 0x0204E720 arm
 *   FADE_IsActive 0x0204E804 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   func_021B99E4 0x021B99E4 thumb ov205
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   GAME_DATA_SaveStart 0x02012DAC thumb
 *   func_021B9A68 0x021B9A68 thumb ov205
 *   func_021B9A94 0x021B9A94 thumb ov205
 *   func_021B9B04 0x021B9B04 thumb ov205
 *   func_021B9AD8 0x021B9AD8 thumb ov205
 *   func_021B9B20 0x021B9B20 thumb ov205
 *   TIME_ICON_CreateNode 0x0202EE8C thumb
 *   func_021B9B78 0x021B9B78 thumb ov205
 *   GAME_DATA_SaveMain 0x02012DD0 thumb
 *   TIME_ICON_Delete 0x0202F038 thumb
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   func_021B9928 0x021B9928 thumb ov205
 *   func_02028484 0x02028484 thumb
 *   TCBL_Main 0x020310C4 arm
 *   TIME_ICON_Update 0x0202F0B0 thumb
 */
#include "../include/Obj00419.h"
#include "../include/Obj25393.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct {u16 value;} Init;
extern const Init init;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct Tcbl;
extern u32 KEY_GetTrg(void);
extern void func_021B9874(char *,const char *);
extern u32 GPOWER_GetSpecialPowerId(void);
extern void func_0207E468(void *,u32,u32);
extern void FADE_Start(u32,int,int,int);
extern int FADE_IsActive(void);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern void func_021B99E4(char *,u32,u32,u16);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern int GAME_DATA_SaveStart(int);
extern void func_021B9A68(char *);
extern void func_021B9A94(char *);
extern void func_021B9B04(char *);
extern void func_021B9AD8(char *);
extern void func_021B9B20(char *);
extern u8 *TIME_ICON_CreateNode(u32 a, void *b, u8 c, u8 d, u16 e);
extern void func_021B9B78(char *);
extern int GAME_DATA_SaveMain(u8 *p);
extern void TIME_ICON_Delete(u8 *p);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void func_021B9928(char *);
typedef signed int     s32;
struct Blk;
extern s32 func_02028484(struct Blk *blk, void *h);
extern void TCBL_Main(struct Tcbl *p);
extern void TIME_ICON_Update(u8 *p);
typedef enum { ST0=0,ST13=13 } State;
int func_021B95F4(void *unused,State *state,const char *context,char *p)
{
    Init local;
    void *obj;
    enum { M3=3,M12=12 } mode;
    local=init;
    KEY_GetTrg();
    switch(*state){
    case 0:func_021B9874(p,context);(*state)++;break;
    case 1:
    {
        enum { Z0,Z1 } zero;
        zero=0;
        *(u16 *)0x04000050=zero;
        *(volatile u32 *)0x04000000=(*(volatile u32 *)0x04000000&0xffffe0ff)|256;
        if(GPOWER_GetSpecialPowerId()==21)mode=3;
        else {func_0207E468(&local,zero,2);mode=12;}
        FADE_Start(mode,16,zero,zero);(*state)++;break;
    }
    case 2:if(!FADE_IsActive())*state=3;break;
    case 3:
        if(((struct Obj00419 *)p)->f40!=0){ (*state)++; break; }
        {
            GFL_USE_PlaySeDefaultVolume(0x54c);func_021B99E4(p,3,0,0);
            obj=((struct Obj00419 *)p)->f1C;BMP_WIN_TransferChars(obj);BMP_WIN_MakeScreen(obj);func_020409B4(BMP_WIN_GetBgLayer(obj));
            ((struct Obj00419 *)p)->f44=4;*state=13;GAME_DATA_SaveStart(*(int *)&((struct Obj00419 *)p)->f4);
        }
        break;
    case 4:
        if(((struct Obj00419 *)p)->f40==0){
            if(((struct Obj25393 *)context)->f4==0){func_021B9A68(p);func_021B9A94(p);}
            else {func_021B9B04(p);func_021B9AD8(p);func_021B9B20(p);}
        }
        ((struct Obj00419 *)p)->f30=TIME_ICON_CreateNode(*(u32 *)&((struct Obj00419 *)p)->f24,((struct Obj00419 *)p)->f1C,15,16,((struct Obj00419 *)p)->f0);
        (*state)++;break;
    case 5:
        if(((struct Obj00419 *)p)->f40==0 && ((struct Obj00419 *)p)->f38!=0){
            func_021B9B78(p);
            if(((struct Obj00419 *)p)->f3C!=0)(*state)++;
        }else (*state)++;
        break;
    case 6:
        if(((struct Obj00419 *)p)->f40==0){
            switch(GAME_DATA_SaveMain(((struct Obj00419 *)p)->f4)){
            case 0:case 1:break;
            case 2:((struct Obj00419 *)p)->f34=1;(*state)++;break;
            case 3:((struct Obj00419 *)p)->f34=0;(*state)++;break;
            }
        }else (*state)++;
        break;
    case 7:
        TIME_ICON_Delete(((struct Obj00419 *)p)->f30);
        if(((struct Obj00419 *)p)->f40==0 && ((struct Obj00419 *)p)->f34!=0){
            func_021B99E4(p,4,0,0);
            obj=((struct Obj00419 *)p)->f1C;BMP_WIN_TransferChars(obj);BMP_WIN_MakeScreen(obj);func_020409B4(BMP_WIN_GetBgLayer(obj));
            ((struct Obj00419 *)p)->f44=8;*state=13;GFL_USE_PlaySeDefaultVolume(0x558);
        }else{
            func_021B99E4(p,5,0,0);
            obj=((struct Obj00419 *)p)->f1C;BMP_WIN_TransferChars(obj);BMP_WIN_MakeScreen(obj);func_020409B4(BMP_WIN_GetBgLayer(obj));
            ((struct Obj00419 *)p)->f44=8;*state=13;
        }
        break;
    case 8:
        if(((struct Obj00419 *)p)->f48>120)(*state)++;
        (((struct Obj00419 *)p)->f48)++;break;
    case 9:
        if(GPOWER_GetSpecialPowerId()==21){ FADE_Start(3,0,16,0); }
        else { FADE_Start(12,0,16,0); }
        (*state)++;break;
    case 10:
        if(!FADE_IsActive()){BMP_Clear(BMP_WIN_GetBmp(((struct Obj00419 *)p)->f1C),15);(*state)++;}
        break;
    case 11:func_021B9928(p);(*state)++;break;
    case 12:return 1;
    case 13:
        if(func_02028484((struct Blk *)(p+40),((struct Obj00419 *)p)->f20))*state=((struct Obj00419 *)p)->f44;
        break;
    }
    if(((struct Obj00419 *)p)->f24)TCBL_Main(((struct Obj00419 *)p)->f24);
    if(((struct Obj00419 *)p)->f30)TIME_ICON_Update(((struct Obj00419 *)p)->f30);
    return 0;
}
