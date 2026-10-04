/*
 * function: func_021DBFB4
 * address: 0x021DBFB4
 * packet: pkt_ov175_021DBFB4
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: PC-relative pool audit binds source-line constants 125c/126f/127b to the success/cancel-error/timeout calls, fixing the prior three concrete pool bytes.
 * symbols:
 *   func_021E10CC 0x021E10CC arm ov175
 *   func_021E1464 0x021E1464 arm ov175
 *   func_021E1414 0x021E1414 arm ov175
 *   func_021E1434 0x021E1434 arm ov175
 *   func_021E1454 0x021E1454 arm ov175
 *   func_021E11F0 0x021E11F0 arm ov175
 *   func_021DCE40 0x021DCE40 thumb ov175
 *   func_021DCE08 0x021DCE08 thumb ov175
 *   func_021DCE48 0x021DCE48 thumb ov175
 *   func_021DCE50 0x021DCE50 thumb ov175
 *   func_021DB6A0 0x021DB6A0 thumb ov175
 *   d_021E2F1C 0x021E2F1C data a4
 * prototype: Setters retain caller-loaded line in r2; shutdown receives p where the caller visibly prepares r0.
 */
#include "../include/Obj00629.h"
typedef unsigned long u32;
typedef struct DWCstAccUserData DWCstAccUserData;
extern int func_021E10CC(int,DWCstAccUserData *,int);
extern int func_021E1464(char *,void *,int,int *);
extern void func_021E1414(void);
extern int func_021E1434(void);
extern u32 func_021E1454(void);
extern int func_021E11F0(void);
extern void func_021DCE40(char *,u32,int);
extern void func_021DCE08(char *,u32,int);
extern void func_021DCE48(char *,u32,int);
extern void func_021DCE50(char *,u32,int);
extern void func_021DB6A0(char *);
extern const char d_021E2F1C[];
int func_021DBFB4(char *p)
{
    long r;
    switch(((struct Obj00629 *)p)->f12C) {
    case 0:
        r=func_021E10CC(0xb5f,*(DWCstAccUserData * *)&((struct Obj00629 *)p)->f0,0);
        if(r!=0) {func_021DCE40(p+0x18,r,0x1215);return 2;}
        ((struct Obj00629 *)p)->f12C=1;break;
    case 1:
        r=func_021E1464((char *)d_021E2F1C,((struct Obj00629 *)p)->f190,((struct Obj00629 *)p)->f198,*(int * *)&((struct Obj00629 *)p)->f1464);
        if(r!=0) {func_021DCE40(p+0x18,r,0x1223);return 2;}
        ((struct Obj00629 *)p)->f1A0=0;((struct Obj00629 *)p)->f12C=2;break;
    case 2:
        if((((struct Obj00629 *)p)->f1A0)++>0xe10) {func_021DCE08(p+0x18,1,0x122f);((struct Obj00629 *)p)->f12C=4;break;}
        func_021E1414();r=func_021E1434();
        if(r==0||r==4) {func_021DCE48(p+0x18,r,0x123b);((struct Obj00629 *)p)->f12C=4;}
        else if(r==1)((struct Obj00629 *)p)->f12C=3;
        break;
    case 3:
        r=func_021E1454();
        if(r==0) {func_021DCE50(p+0x18,r,0x124f);((struct Obj00629 *)p)->f12C=4;}
        else if(r!=1) {func_021DB6A0(p);func_021DCE50(p+0x18,r,0x1256);return 2;}
        else {
            if(**(u32 * *)&((struct Obj00629 *)p)->f1464==0)func_021DCE08(p+0x18,2,0x125c);
            func_021DB6A0(p);return 1;
        }
        break;
    case 4:
        r=func_021E11F0();
        if(r==0) {((struct Obj00629 *)p)->f1A0=0;((struct Obj00629 *)p)->f12C=5;}
        else {func_021DCE40(p+0x18,r,0x126f);func_021DB6A0(p);return 2;}
        break;
    case 5:
        if((((struct Obj00629 *)p)->f1A0)++>0xe10) {func_021DCE08(p+0x18,1,0x127b);func_021DB6A0(p);return 2;}
        func_021E1414();r=func_021E1434();
        if(r==0||r==4) {func_021DB6A0(p);return 2;}
        if(r==1)((struct Obj00629 *)p)->f12C=6;
        break;
    case 6:func_021DB6A0(p);return 2;
    }
    return 0;
}
