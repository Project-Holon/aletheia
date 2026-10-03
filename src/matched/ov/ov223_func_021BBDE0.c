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
 *   func_02035C60 0x02035C60 arm
 *   func_02035C08 0x02035C08 arm
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
 *   func_02006984 0x02006984 thumb
 *   d_021BC75C 0x021BC75C data a4
 *   d_021BC794 0x021BC794 data a2
 *   d_021BC710 0x021BC710 data a2
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021B9D4C(char *),func_021BA2B4(char *),func_021BA8D0(char *),func_021BB964(char *),func_021B9A8C(char *);
extern void func_021BAFC4(char *,u32),func_021BA878(char *);
extern int func_021BB0B0(char *),func_021BA8BC(char *);
extern void func_021BAA5C(char *,int),func_020061E4(u32),func_021BAA84(char *),func_021B9C90(char *,u32),func_021BA81C(char *,u32),func_021BB9A4(u8 *,u8);
extern u32 func_020362DC(void),func_02035C60(void);
extern int func_02035C08(const void *);
extern void func_021BB3BC(char *),func_021BB414(char *),func_021BB424(char *),func_021BB404(char *),func_02041B6C(u32);
extern u32 func_021BB440(char *);
extern void func_021B9AE4(char *,int,int),func_021B9B80(char *);
extern int func_021B9B4C(char *);
extern void func_020355D8(u32),func_021BB450(char *),func_021BB4E8(char *),func_021BB4D8(char *),func_021BB134(char *),func_021B9C00(char *,u32),func_021B9C58(char *),func_021BB274(char *),func_021BB18C(char *,u32);
extern u32 func_021BB4F8(char *);
extern int func_021BB508(int *);
extern u8 func_020355C4(void);
extern u32 func_02006984(u32,u32,u32,u32,u32,u32,u32,u32);
extern const u8 d_021BC75C[];
extern const u16 d_021BC794[],d_021BC710[];
int func_021BBDE0(char *p,u32 *state)
{
    int dirty=0;
    int choice,changed;
    u32 selected;
    func_021B9D4C(p);func_021BA2B4(p);func_021BA8D0(p);func_021BB964(p);
    switch(*state) {
    case 0:func_021B9A8C(p);if(*(int *)(p+0x50)==78)*state=1;break;
    case 1:*(u32 *)(p+0x24)|=4;func_021BAFC4(p,19);*state=2;func_021BA878(p);break;
    case 2:if(func_021BB0B0(p)&&func_021BA8BC(p)){*state=3;*(int *)(p+8)=1;}break;
    case 3:
        if(*(int *)(p+8)==0){
            if(*(int *)(p+0x228)==4){dirty=1;*(int *)(p+0x228)=1;}
            func_021BAA5C(p,1);func_020061E4(1352);func_021BAA84(p);
            func_021B9C90(p,*(u32 *)(p+0x228));func_021BA81C(p,*(u32 *)(p+0x228));
            selected=*(u32 *)(p+0x228);if(selected==4)selected=3;func_021BB9A4((u8 *)p,selected);
        }else{func_021BAA5C(p,0);func_021B9C90(p,4);func_021BA81C(p,4);func_021BB9A4((u8 *)p,3);dirty=1;}
        *state=4;break;
    case 4:
        if(*(int *)(p+8)==0){
            if(func_020362DC()!=0){
                changed=0;
                if(func_020362DC()&1){func_020061E4(1356);func_021BAA5C(p,0);*state=8;}
                else if(func_020362DC()&32){if(*(int *)(p+0x228)>0){--*(int *)(p+0x228);changed=1;}}
                else if(func_020362DC()&16){if(*(int *)(p+0x228)<2){++*(int *)(p+0x228);changed=1;}}
                if(changed){func_020061E4(1352);func_021BAA84(p);func_021B9C90(p,*(u32 *)(p+0x228));func_021BA81C(p,*(u32 *)(p+0x228));selected=*(u32 *)(p+0x228);if(selected==4)selected=3;func_021BB9A4((u8 *)p,selected);dirty=1;}
            }else if(func_02035C60()!=0){choice=func_02035C08(d_021BC75C);if(choice>=0&&choice<=2){if(*(int *)(p+0x228)!=choice)dirty=1;func_020061E4(1352);func_021BAA5C(p,0);*(int *)(p+0x228)=choice;func_021B9C90(p,choice);func_021BA81C(p,*(u32 *)(p+0x228));selected=*(u32 *)(p+0x228);if(selected==4)selected=3;func_021BB9A4((u8 *)p,selected);*(int *)(p+8)=1;*state=5;}}
        }else{
            if(func_020362DC()!=0){*(int *)(p+8)=0;*state=3;}
            else if(func_02035C60()!=0){choice=func_02035C08(d_021BC75C);if(choice>=0&&choice<=2){func_020061E4(1352);*(int *)(p+0x228)=choice;func_021B9C90(p,choice);func_021BA81C(p,*(u32 *)(p+0x228));selected=*(u32 *)(p+0x228);if(selected==4)selected=3;func_021BB9A4((u8 *)p,selected);dirty=1;*state=5;}}
        }break;
    case 5:func_021BB3BC(p);*state=6;break;
    case 6:
        func_021BB414(p);
        if(func_020362DC()!=0){*(int *)(p+8)=0;if(func_020362DC()&1){func_020061E4(1356);func_021BB424(p);*state=7;}else{func_021BB404(p);func_02041B6C(3);*state=3;}}
        else if(func_02035C60()!=0){choice=func_02035C08(d_021BC75C);if(choice==3){func_020061E4(1356);func_021BB424(p);*state=7;}else if(choice>=0&&choice<=2&&*(int *)(p+0x228)!=choice){func_020061E4(1352);*(int *)(p+0x228)=choice;func_021B9C90(p,choice);func_021BA81C(p,*(u32 *)(p+0x228));selected=*(u32 *)(p+0x228);if(selected==4)selected=3;func_021BB9A4((u8 *)p,selected);dirty=1;}}break;
    case 7:func_021BB414(p);if(func_021BB440(p)){func_021BB404(p);func_02041B6C(3);*state=8;}break;
    case 8:func_021BAFC4(p,20);func_021B9AE4(p,*(int *)(p+0x228),0);*state=9;break;
    case 9:func_021B9B80(p);if(func_021BB0B0(p)&&func_021B9B4C(p))*state=10;break;
    case 10:func_020355D8(*(u32 *)(p+8));func_021BB450(p);*state=11;break;
    case 11:func_021BB4E8(p);if(func_021BB4F8(p)){choice=func_021BB508((int *)p);func_021BB4D8(p);*(u32 *)(p+8)=func_020355C4();if(choice){*(u32 *)(p+0x24)|=8;func_021BB134(p);*state=14;}else{func_021BAFC4(p,19);*state=12;}}break;
    case 12:func_021B9AE4(p,*(int *)(p+0x228),1);*state=13;break;
    case 13:func_021B9B80(p);if(func_021B9B4C(p))*state=3;break;
    case 14:func_021B9C00(p,*(u32 *)(p+0x228));func_020061E4(1976);*state=15;break;
    case 15:func_021B9C58(p);if(*(u32 *)(p+0x4c)==(int)*(const u16 *)((const u8 *)d_021BC794+*(u32 *)(p+0x44)*10)-2)*state=16;break;
    case 16:func_021B9C58(p);*(int *)(p+0x10)=0;return 10;
    }
    if(dirty){*(u32 *)(p+0x24)|=32;func_021BB274(p);}
    else if(*(int *)(p+0x230)!=0){*(u32 *)(p+0x24)|=16;func_021BB18C(p,*(u32 *)(p+0x228));func_02006984(d_021BC710[*(u32 *)(p+0x228)],0,64,0,0,0,0,0);}
    *(int *)(p+0x230)=0;++*(u32 *)(p+0x10);return 9;
}
