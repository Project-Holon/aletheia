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
 * Caller evidence: 021B74B4 leaves its forwarded return in r0, read here; 02005E50 is the matched zero-argument sub_02005E50.
 * symbols:
 *   func_020221A4 0x020221A4 thumb
 *   func_02005E50 0x02005E50 thumb
 *   func_02005D28 0x02005D28 thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_021B7268 0x021B7268 thumb ov180
 *   func_021B7438 0x021B7438 thumb ov180
 *   func_021B746C 0x021B746C thumb ov180
 *   func_021B7488 0x021B7488 thumb ov180
 *   func_021B74B4 0x021B74B4 thumb ov180
 *   func_021B7C60 0x021B7C60 thumb ov180
 *   func_021B692C 0x021B692C thumb ov180
 *   func_021B699C 0x021B699C thumb ov180
 *   func_02015E4C 0x02015E4C thumb
 *   func_021B69F8 0x021B69F8 thumb ov180
 *   func_021B6984 0x021B6984 thumb ov180
 *   func_021B7F38 0x021B7F38 thumb ov180
 *   func_020362DC 0x020362DC arm
 *   func_02035C60 0x02035C60 arm
 *   func_02005E30 0x02005E30 thumb
 *   func_021B723C 0x021B723C thumb ov180
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
extern u32 func_020221A4(void),func_020362DC(void),func_02035C60(void);
extern int func_02005E50(void);
extern void func_02005D28(void),func_020061E4(u32),func_02005E30(u32),func_02015E4C(void *);
extern int func_021B7268(char *,int),func_021B723C(char *,int,int),func_021B74B4(char *,int);
extern void func_021B7438(char *,int,short,short),func_021B746C(int *,int,int),func_021B7488(char *,int,u16),func_021B7C60(char *,int,int);
extern void func_021B692C(char *),func_021B699C(char *,int),func_021B69F8(char *),func_021B6984(char *),func_021B7F38(char *);
int func_021B6FAC(char *p) {
    int ready;
    if(*(int *)(p+0x9198)==1 && func_020221A4()==1 && func_02005E50()==0) { func_02005D28();return 9; }
    switch(*(int *)(p+0x9190)) {
    case 0: ++*(int *)(p+0x9190);return func_021B7268(p,32);
    case 1: func_020061E4(0x79D);++*(int *)(p+0x9190);break;
    case 2:
        if(*(int *)(p+0x9188)!=51) {func_021B7438(p,5,0,8);func_021B7438(p,6,0,8);++*(int *)(p+0x9188);}
        else {func_020061E4(0x57A);++*(int *)(p+0x9190);return func_021B7268(p,32);}break;
    case 3:
        func_021B746C((int *)p,7,1);func_021B746C((int *)p,8,1);func_021B7488(p,7,2);func_021B7488(p,8,2);++*(int *)(p+0x9190);break;
    case 4: if(func_021B74B4(p,7)==0){func_020061E4(0x79E);++*(int *)(p+0x9190);return func_021B7268(p,16);}break;
    case 5: func_021B7C60(p,3,1);++*(int *)(p+0x9190);return func_021B7268(p,32);
    case 6: func_021B7C60(p,2,1);++*(int *)(p+0x9190);break;
    case 7: if(*(int *)(p+0x9188)==300){*(int *)(p+0x9188)=0;++*(int *)(p+0x9190);}else ++*(int *)(p+0x9188);break;
    case 8:
        ready=0;
        if(*(u8 *)(p+0x915D)==0) {if(*(int *)(p+0x9188)==256)ready=1;}
        else {if(*(int *)(p+0x9188)==128)ready=1;}
        if(ready==1){func_021B692C(p);*(int *)(p+0x9188)=0;++*(int *)(p+0x9190);}else ++*(int *)(p+0x9188);break;
    case 9:
        if(*(int *)(p+0x9188)!=20){func_021B699C(p,-8);++*(int *)(p+0x9188);}else{func_02015E4C(*(void **)(p+28));*(int *)(p+0x9188)=0;++*(int *)(p+0x9190);}break;
    case 10: if(*(int *)(p+0x9188)!=128)++*(int *)(p+0x9188);else{func_021B69F8(p);*(int *)(p+0x9188)=0;++*(int *)(p+0x9190);}break;
    case 11:
        if(*(int *)(p+36)!=0){
            if(*(int *)(p+0x9188)!=24){func_021B699C(p,-8);++*(int *)(p+0x9188);}
            else{func_021B6984(p);*(int *)(p+0x9188)=0;++*(u8 *)(p+0x915D);if(*(u8 *)(p+0x915D)==*(u8 *)(p+0x915E))*(u8 *)(p+0x915D)=0;*(int *)(p+0x9190)=8;}
        }break;
    }
    if(*(int *)(p+0x9190)>=6)func_021B7F38(p);
    if(*(int *)(p+0x9190)>=8 && *(int *)(p+0x9198)==0 && ((func_020362DC()&3)!=0 || func_02035C60()==1)){
        *(int *)(p+0x9198)=1;func_02005E30(220);func_021B723C(p,9,188);
    }
    return 8;
}
