/*
 * function: func_021BBDE0
 * address: 0x021BBDE0
 * packet: pkt_ov223_021BBDE0
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * ABI: A A84 unused legacy r1 omitted: full own body reads no second input, original has no setup; BB9A4 r1 truncated to u8 at BE C6/CA and parallel sites; 355D8 widened to observed full word without pre-call truncation. 35C60 return consumed as in own-overlay BB0B0.
 * symbols:
 *   func_021B9D4C 0x021B9D4C thumb ov223
 *   func_021BA2B4 0x021BA2B4 thumb ov223
 *   func_021BA8D0 0x021BA8D0 thumb ov223
 *   func_021BB964 0x021BB964 thumb ov223
 *   func_021B9A8C 0x021B9A8C thumb ov223
 *   func_021BAFC4 0x021BAFC4 thumb ov223
 *   func_021BA878 0x021BA878 thumb ov223
 *   func_021BB0B0 0x021BB0B0 thumb ov223
 *   func_021BA8BC 0x021BA8BC thumb ov223
 *   func_021BAA5C 0x021BAA5C thumb ov223
 *   func_020061E4 0x020061E4 thumb
 *   func_021BAA84 0x021BAA84 thumb ov223
 *   func_021B9C90 0x021B9C90 thumb ov223
 *   func_021BA81C 0x021BA81C thumb ov223
 *   func_021BB9A4 0x021BB9A4 thumb ov223
 *   func_020362DC 0x020362DC arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   func_021BB3BC 0x021BB3BC thumb ov223
 *   func_021BB414 0x021BB414 thumb ov223
 *   func_021BB424 0x021BB424 thumb ov223
 *   func_021BB404 0x021BB404 thumb ov223
 *   func_02041B6C 0x02041B6C arm
 *   func_021BB440 0x021BB440 thumb ov223
 *   func_021B9AE4 0x021B9AE4 thumb ov223
 *   func_021B9B80 0x021B9B80 thumb ov223
 *   func_021B9B4C 0x021B9B4C thumb ov223
 *   func_020355D8 0x020355D8 arm
 *   func_021BB450 0x021BB450 thumb ov223
 *   func_021BB4E8 0x021BB4E8 thumb ov223
 *   func_021BB4F8 0x021BB4F8 thumb ov223
 *   func_021BB508 0x021BB508 thumb ov223
 *   func_021BB4D8 0x021BB4D8 thumb ov223
 *   func_020355C4 0x020355C4 arm
 *   func_021BB134 0x021BB134 thumb ov223
 *   func_021B9C00 0x021B9C00 thumb ov223
 *   func_021B9C58 0x021B9C58 thumb ov223
 *   func_021BB274 0x021BB274 thumb ov223
 *   func_021BB18C 0x021BB18C thumb ov223
 *   PM_VOICE_Play 0x02006984 thumb
 *   d_021BC75C 0x021BC75C data a4
 *   d_021BC794 0x021BC794 data a2
 *   d_021BC710 0x021BC710 data a2
 */
#include "../include/Obj00084.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Main;
extern void func_021B9D4C(char *);
extern void func_021BA2B4(struct Main *p);
extern void func_021BA8D0(char *);
extern void func_021BB964(char *);
extern void func_021B9A8C(char *);
extern void func_021BAFC4(char *p, int idx);
extern void func_021BA878(char *);
extern int func_021BB0B0(char *),func_021BA8BC(char *);
extern void func_021BAA5C(char *,int);
extern void func_020061E4(u32);
extern void func_021BAA84(char *);
extern void func_021B9C90(char *,u32);
extern void func_021BA81C(char *,u32);
extern void func_021BB9A4(unsigned char *p, int value);
extern u32 func_020362DC(void);
extern int TOUCHPANEL_GetTrg(void);
extern int TOUCHPANEL_HitTrg(const void *);
extern void func_021BB3BC(char *),func_021BB414(char *),func_021BB424(char *),func_021BB404(char *),func_02041B6C(u32);
extern u32 func_021BB440(char *);
extern void func_021B9AE4(char *,int,int),func_021B9B80(char *);
extern int func_021B9B4C(char *);
extern void func_020355D8(u32);
extern void func_021BB450(char *);
extern void func_021BB4E8(char *);
extern void func_021BB4D8(char *);
extern void func_021BB134(char *);
extern void func_021B9C00(char *,u32);
extern void func_021B9C58(char *);
extern void func_021BB274(char *);
extern void func_021BB18C(char *p, int idx);
extern u32 func_021BB4F8(char *);
extern int func_021BB508(int *);
extern u8 func_020355C4(void);
extern u32 PM_VOICE_Play(u32,u32,u32,u32,u32,u32,u32,u32);
extern const u8 d_021BC75C[];
extern const u16 d_021BC794[],d_021BC710[];
int func_021BBDE0(char *p,u32 *state)
{
    int dirty=0;
    int choice,changed;
    u32 selected;
    func_021B9D4C(p);func_021BA2B4((struct Main *)p);func_021BA8D0(p);func_021BB964(p);
    switch(*state) {
    case 0:func_021B9A8C(p);if(((struct Obj00084 *)p)->f50==78)*state=1;break;
    case 1:((struct Obj00084 *)p)->f24|=4;func_021BAFC4(p,(u32)19);*state=2;func_021BA878(p);break;
    case 2:if(func_021BB0B0(p)&&func_021BA8BC(p)){*state=3;((struct Obj00084 *)p)->f8=1;}break;
    case 3:
        if(((struct Obj00084 *)p)->f8==0){
            if(*(int *)&((struct Obj00084 *)p)->f228==4){dirty=1;*(int *)&((struct Obj00084 *)p)->f228=1;}
            func_021BAA5C(p,1);func_020061E4(1352);func_021BAA84(p);
            func_021B9C90(p,((struct Obj00084 *)p)->f228);func_021BA81C(p,((struct Obj00084 *)p)->f228);
            selected=((struct Obj00084 *)p)->f228;if(selected==4)selected=3;func_021BB9A4((u8 *)p,(u8)selected);
        }else{func_021BAA5C(p,0);func_021B9C90(p,4);func_021BA81C(p,4);func_021BB9A4((u8 *)p,(u8)3);dirty=1;}
        *state=4;break;
    case 4:
        if(((struct Obj00084 *)p)->f8==0){
            if(func_020362DC()!=0){
                changed=0;
                if(func_020362DC()&1){func_020061E4(1356);func_021BAA5C(p,0);*state=8;}
                else if(func_020362DC()&32){if(*(int *)&((struct Obj00084 *)p)->f228>0){--*(int *)&((struct Obj00084 *)p)->f228;changed=1;}}
                else if(func_020362DC()&16){if(*(int *)&((struct Obj00084 *)p)->f228<2){++*(int *)&((struct Obj00084 *)p)->f228;changed=1;}}
                if(changed){func_020061E4(1352);func_021BAA84(p);func_021B9C90(p,((struct Obj00084 *)p)->f228);func_021BA81C(p,((struct Obj00084 *)p)->f228);selected=((struct Obj00084 *)p)->f228;if(selected==4)selected=3;func_021BB9A4((u8 *)p,(u8)selected);dirty=1;}
            }else if(TOUCHPANEL_GetTrg()!=0){choice=TOUCHPANEL_HitTrg(d_021BC75C);if(choice>=0&&choice<=2){if(*(int *)&((struct Obj00084 *)p)->f228!=choice)dirty=1;func_020061E4(1352);func_021BAA5C(p,0);*(int *)&((struct Obj00084 *)p)->f228=choice;func_021B9C90(p,choice);func_021BA81C(p,((struct Obj00084 *)p)->f228);selected=((struct Obj00084 *)p)->f228;if(selected==4)selected=3;func_021BB9A4((u8 *)p,(u8)selected);((struct Obj00084 *)p)->f8=1;*state=5;}}
        }else{
            if(func_020362DC()!=0){((struct Obj00084 *)p)->f8=0;*state=3;}
            else if(TOUCHPANEL_GetTrg()!=0){choice=TOUCHPANEL_HitTrg(d_021BC75C);if(choice>=0&&choice<=2){func_020061E4(1352);*(int *)&((struct Obj00084 *)p)->f228=choice;func_021B9C90(p,choice);func_021BA81C(p,((struct Obj00084 *)p)->f228);selected=((struct Obj00084 *)p)->f228;if(selected==4)selected=3;func_021BB9A4((u8 *)p,(u8)selected);dirty=1;*state=5;}}
        }break;
    case 5:func_021BB3BC(p);*state=6;break;
    case 6:
        func_021BB414(p);
        if(func_020362DC()!=0){((struct Obj00084 *)p)->f8=0;if(func_020362DC()&1){func_020061E4(1356);func_021BB424(p);*state=7;}else{func_021BB404(p);func_02041B6C(3);*state=3;}}
        else if(TOUCHPANEL_GetTrg()!=0){choice=TOUCHPANEL_HitTrg(d_021BC75C);if(choice==3){func_020061E4(1356);func_021BB424(p);*state=7;}else if(choice>=0&&choice<=2&&*(int *)&((struct Obj00084 *)p)->f228!=choice){func_020061E4(1352);*(int *)&((struct Obj00084 *)p)->f228=choice;func_021B9C90(p,choice);func_021BA81C(p,((struct Obj00084 *)p)->f228);selected=((struct Obj00084 *)p)->f228;if(selected==4)selected=3;func_021BB9A4((u8 *)p,(u8)selected);dirty=1;}}break;
    case 7:func_021BB414(p);if(func_021BB440(p)){func_021BB404(p);func_02041B6C(3);*state=8;}break;
    case 8:func_021BAFC4(p,(u32)20);func_021B9AE4(p,*(int *)&((struct Obj00084 *)p)->f228,0);*state=9;break;
    case 9:func_021B9B80(p);if(func_021BB0B0(p)&&func_021B9B4C(p))*state=10;break;
    case 10:func_020355D8(*(u32 *)&((struct Obj00084 *)p)->f8);func_021BB450(p);*state=11;break;
    case 11:func_021BB4E8(p);if(func_021BB4F8(p)){choice=func_021BB508((int *)p);func_021BB4D8(p);*(u32 *)&((struct Obj00084 *)p)->f8=func_020355C4();if(choice){((struct Obj00084 *)p)->f24|=8;func_021BB134(p);*state=14;}else{func_021BAFC4(p,(u32)19);*state=12;}}break;
    case 12:func_021B9AE4(p,*(int *)&((struct Obj00084 *)p)->f228,1);*state=13;break;
    case 13:func_021B9B80(p);if(func_021B9B4C(p))*state=3;break;
    case 14:func_021B9C00(p,((struct Obj00084 *)p)->f228);func_020061E4(1976);*state=15;break;
    case 15:func_021B9C58(p);if(((struct Obj00084 *)p)->f4C==(int)*(const u16 *)((const u8 *)d_021BC794+((struct Obj00084 *)p)->f44*10)-2)*state=16;break;
    case 16:func_021B9C58(p);*(int *)&((struct Obj00084 *)p)->f10=0;return 10;
    }
    if(dirty){((struct Obj00084 *)p)->f24|=32;func_021BB274(p);}
    else if(((struct Obj00084 *)p)->f230!=0){((struct Obj00084 *)p)->f24|=16;func_021BB18C(p,(u32)(((struct Obj00084 *)p)->f228));PM_VOICE_Play(d_021BC710[((struct Obj00084 *)p)->f228],0,64,0,0,0,0,0);}
    ((struct Obj00084 *)p)->f230=0;++((struct Obj00084 *)p)->f10;return 9;
}
