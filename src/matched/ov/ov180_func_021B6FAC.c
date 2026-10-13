/*
 * function: func_021B6FAC
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
 *   func_020221A4 0x020221A4 thumb
 *   GFL_USE_IsBgmFading 0x02005E50 thumb
 *   GFL_USE_CancelChangeAndStopBgm 0x02005D28 thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_021B7268 0x021B7268 thumb ov180
 *   func_021B7438 0x021B7438 thumb ov180
 *   func_021B746C 0x021B746C thumb ov180
 *   func_021B7488 0x021B7488 thumb ov180
 *   func_021B74B4 0x021B74B4 thumb ov180
 *   func_021B7C60 0x021B7C60 thumb ov180
 *   func_021B692C 0x021B692C thumb ov180
 *   func_021B699C 0x021B699C thumb ov180
 *   MCSS_ResetAnmStopFlag 0x02015E4C thumb
 *   func_021B69F8 0x021B69F8 thumb ov180
 *   func_021B6984 0x021B6984 thumb ov180
 *   func_021B7F38 0x021B7F38 thumb ov180
 *   func_020362DC 0x020362DC arm
 *   func_02035C60 0x02035C60 arm
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb
 *   func_021B723C 0x021B723C thumb ov180
 */
#include "../include/Obj00242.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
extern u32 func_020221A4(void);
extern u32 func_020362DC(void);
extern int func_02035C60(void);
extern int GFL_USE_IsBgmFading(void);
extern void GFL_USE_CancelChangeAndStopBgm(void),func_020061E4(u32),GFL_USE_FadeOutBgm(u32),MCSS_ResetAnmStopFlag(void *);
extern int func_021B7268(char *,int);
extern int func_021B723C(char *,int,int);
extern int func_021B74B4(int *p, int i);
extern void func_021B7438(u8 *p, int n, int x, int y);
extern void func_021B746C(int *,int,int);
extern void func_021B7488(u8 *p, int n, int v);
extern void func_021B7C60(char *p, int index, unsigned value);
extern void func_021B692C(char *),func_021B699C(char *,int),func_021B69F8(char *),func_021B6984(char *),func_021B7F38(char *);
int func_021B6FAC(char *p) {
    int ready;
    if(((struct Obj00242 *)p)->f9198==1 && func_020221A4()==1 && GFL_USE_IsBgmFading()==0) { GFL_USE_CancelChangeAndStopBgm();return 9; }
    switch(((struct Obj00242 *)p)->f9190) {
    case 0: ++((struct Obj00242 *)p)->f9190;return func_021B7268(p,32);
    case 1: func_020061E4(0x79D);++((struct Obj00242 *)p)->f9190;break;
    case 2:
        if(((struct Obj00242 *)p)->f9188!=51) {func_021B7438((u8 *)p,5,0,8);func_021B7438((u8 *)p,6,0,8);++((struct Obj00242 *)p)->f9188;}
        else {func_020061E4(0x57A);++((struct Obj00242 *)p)->f9190;return func_021B7268(p,32);}break;
    case 3:
        func_021B746C((int *)p,7,1);func_021B746C((int *)p,8,1);func_021B7488((u8 *)p,7,2);func_021B7488((u8 *)p,8,2);++((struct Obj00242 *)p)->f9190;break;
    case 4: if(func_021B74B4((int *)p,7)==0){func_020061E4(0x79E);++((struct Obj00242 *)p)->f9190;return func_021B7268(p,16);}break;
    case 5: func_021B7C60(p,3,1);++((struct Obj00242 *)p)->f9190;return func_021B7268(p,32);
    case 6: func_021B7C60(p,2,1);++((struct Obj00242 *)p)->f9190;break;
    case 7: if(((struct Obj00242 *)p)->f9188==300){((struct Obj00242 *)p)->f9188=0;++((struct Obj00242 *)p)->f9190;}else ++((struct Obj00242 *)p)->f9188;break;
    case 8:
        ready=0;
        if(((struct Obj00242 *)p)->f915D==0) {if(((struct Obj00242 *)p)->f9188==256)ready=1;}
        else {if(((struct Obj00242 *)p)->f9188==128)ready=1;}
        if(ready==1){func_021B692C(p);((struct Obj00242 *)p)->f9188=0;++((struct Obj00242 *)p)->f9190;}else ++((struct Obj00242 *)p)->f9188;break;
    case 9:
        if(((struct Obj00242 *)p)->f9188!=20){func_021B699C(p,-8);++((struct Obj00242 *)p)->f9188;}else{MCSS_ResetAnmStopFlag(((struct Obj00242 *)p)->f1C);((struct Obj00242 *)p)->f9188=0;++((struct Obj00242 *)p)->f9190;}break;
    case 10: if(((struct Obj00242 *)p)->f9188!=128)++((struct Obj00242 *)p)->f9188;else{func_021B69F8(p);((struct Obj00242 *)p)->f9188=0;++((struct Obj00242 *)p)->f9190;}break;
    case 11:
        if(((struct Obj00242 *)p)->f24!=0){
            if(((struct Obj00242 *)p)->f9188!=24){func_021B699C(p,-8);++((struct Obj00242 *)p)->f9188;}
            else{func_021B6984(p);((struct Obj00242 *)p)->f9188=0;++((struct Obj00242 *)p)->f915D;if(((struct Obj00242 *)p)->f915D==((struct Obj00242 *)p)->f915E)((struct Obj00242 *)p)->f915D=0;((struct Obj00242 *)p)->f9190=8;}
        }break;
    }
    if(((struct Obj00242 *)p)->f9190>=6)func_021B7F38(p);
    if(((struct Obj00242 *)p)->f9190>=8 && ((struct Obj00242 *)p)->f9198==0 && ((func_020362DC()&3)!=0 || func_02035C60()==1)){
        ((struct Obj00242 *)p)->f9198=1;GFL_USE_FadeOutBgm(220);func_021B723C(p,9,188);
    }
    return 8;
}
