/*
 * function: func_021B6BAC
 * address: 0x021B6BAC
 * packet: pkt_ov180_021B6BAC
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * trailing: zero halfword alignment padding at 0x021B6F32.
 * Bound: original stack allocation 24 bytes is six output coordinate pairs, each two signed halfwords.
 * Caller evidence: 021B74B4's forwarded r0 is consumed; 021B7268 and 021B723C return their verified state values.
 * symbols:
 *   func_021B7268 0x021B7268 thumb ov180
 *   func_020061E4 0x020061E4 thumb
 *   GFL_USE_IsSeqPlaying 0x02006254 thumb
 *   func_021B654C 0x021B654C thumb ov180
 *   func_021B65A0 0x021B65A0 thumb ov180
 *   func_021B6778 0x021B6778 thumb ov180
 *   func_021B67EC 0x021B67EC thumb ov180
 *   func_021B761C 0x021B761C thumb ov180
 *   func_021B78E0 0x021B78E0 thumb ov180
 *   func_021B7C08 0x021B7C08 thumb ov180
 *   func_021B7750 0x021B7750 thumb ov180
 *   func_021B7210 0x021B7210 thumb ov180
 *   func_021B7438 0x021B7438 thumb ov180
 *   func_021B67C4 0x021B67C4 thumb ov180
 *   func_021B682C 0x021B682C thumb ov180
 *   func_021B7408 0x021B7408 thumb ov180
 *   func_021B727C 0x021B727C thumb ov180
 *   func_021B72B0 0x021B72B0 thumb ov180
 *   PM_VOICE_Start 0x02006A64 thumb
 *   func_021B746C 0x021B746C thumb ov180
 *   func_021B7488 0x021B7488 thumb ov180
 *   func_02006BD0 0x02006BD0 thumb
 *   func_021B74B4 0x021B74B4 thumb ov180
 *   func_021B723C 0x021B723C thumb ov180
 *   func_021B681C 0x021B681C thumb ov180
 *   func_021B67B4 0x021B67B4 thumb ov180
 */
#include "../include/Obj00299.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
extern int func_021B7268(char *,int);
extern int func_021B723C(char *,int,int);
extern int func_021B7210(char *,int);
extern int func_021B72B0(char *,int);
extern int func_021B74B4(int *p, int i);
extern void func_020061E4(u32);
typedef signed short   s16;
extern int GFL_USE_IsSeqPlaying(u32);
extern int PM_VOICE_Start(u32);
extern u32 func_02006BD0(u32 i);
extern void func_021B654C(char *),func_021B65A0(char *),func_021B6778(char *),func_021B67EC(char *),func_021B761C(char *),func_021B78E0(char *),func_021B7C08(char *),func_021B7750(char *),func_021B727C(char *);
extern void func_021B67C4(char *,int);
extern void func_021B682C(int *,int);
extern void func_021B7408(u8 *p, int n, s16 *x, s16 *y);
extern void func_021B7438(u8 *p, int n, int x, int y);
extern void func_021B746C(int *,int,int);
extern void func_021B7488(u8 *p, int n, int v);
extern void func_021B681C(int *);
extern void func_021B67B4(int *);
int func_021B6BAC(char *p) {
    short coords[12];
    int busy;
    switch(((struct Obj00299 *)p)->f9190){
    case 0: ++((struct Obj00299 *)p)->f9190;return func_021B7268(p,32);
    case 1: func_020061E4(0x79B);++((struct Obj00299 *)p)->f9190;break;
    case 2: if(++((struct Obj00299 *)p)->f9188==48){func_020061E4(0x79C);((struct Obj00299 *)p)->f9188=0;++((struct Obj00299 *)p)->f9190;}break;
    case 3: if(GFL_USE_IsSeqPlaying(0x79C)==0){
        func_020061E4(0x79A);func_021B654C(p);func_021B65A0(p);func_021B6778(p);func_021B67EC(p);func_021B761C(p);func_021B78E0(p);func_021B7C08(p);func_021B7750(p);
        ++((struct Obj00299 *)p)->f9190;return func_021B7210(p,5);
    }break;
    case 4: if(((struct Obj00299 *)p)->f9188==22){++((struct Obj00299 *)p)->f9190;return func_021B7268(p,8);}else{func_021B7438((u8 *)p,1,-16,0);++((struct Obj00299 *)p)->f9188;}break;
    case 5: func_021B67C4(p,0);func_021B67C4(p,1);++((struct Obj00299 *)p)->f9190;return func_021B7268(p,8);
    case 6: func_021B682C((int *)p,1);++((struct Obj00299 *)p)->f9190;
    case 7:
        func_021B7408((u8 *)p,2,&coords[11],&coords[10]);
        if(coords[11]!=168)func_021B7438((u8 *)p,2,16,0);
        else{func_020061E4(0x57A);func_021B727C(p);((struct Obj00299 *)p)->f9160=coords[11];((struct Obj00299 *)p)->f9162=coords[10];++((struct Obj00299 *)p)->f9190;}
        func_021B7C08(p);break;
    case 8: func_021B682C((int *)p,0);++((struct Obj00299 *)p)->f9190;
    case 9:
        busy=func_021B72B0(p,2);func_021B7408((u8 *)p,3,&coords[9],&coords[8]);
        if(coords[9]!=88)func_021B7438((u8 *)p,3,-16,0);
        else if(busy==0){func_020061E4(0x57A);func_021B727C(p);((struct Obj00299 *)p)->f9160=coords[9];((struct Obj00299 *)p)->f9162=coords[8];++((struct Obj00299 *)p)->f9190;}
        func_021B7C08(p);break;
    case 10:
        busy=func_021B72B0(p,3);func_021B7408((u8 *)p,0,&coords[7],&coords[6]);
        if(coords[7]!=48)func_021B7438((u8 *)p,0,16,0);
        else if(busy==0){func_020061E4(0x57A);func_021B727C(p);((struct Obj00299 *)p)->f9160=coords[7];((struct Obj00299 *)p)->f9162=coords[6];++((struct Obj00299 *)p)->f9190;}
        func_021B7C08(p);break;
    case 11: if(func_021B72B0(p,0)==0){PM_VOICE_Start(((struct Obj00299 *)p)->f9184);func_021B746C((int *)p,4,1);func_021B7488((u8 *)p,4,6);++((struct Obj00299 *)p)->f9190;return func_021B7268(p,128);}break;
    case 12: if(func_02006BD0(((struct Obj00299 *)p)->f9184)==0 && func_021B74B4((int *)p,4)==0)++((struct Obj00299 *)p)->f9190;break;
    case 13: func_021B7408((u8 *)p,0,&coords[5],&coords[4]);if(coords[5]!=-48)func_021B7438((u8 *)p,0,-16,0);else ++((struct Obj00299 *)p)->f9190;break;
    case 14: func_021B7408((u8 *)p,3,&coords[3],&coords[2]);if(coords[3]!=264)func_021B7438((u8 *)p,3,16,0);else ++((struct Obj00299 *)p)->f9190;func_021B7C08(p);break;
    case 15: func_021B7408((u8 *)p,2,&coords[1],&coords[0]);if(coords[1]!=-8){func_021B7438((u8 *)p,2,-16,0);func_021B7C08(p);}else{++((struct Obj00299 *)p)->f9190;return func_021B723C(p,5,6);}break;
    case 16: func_021B681C((int *)p);func_021B67B4((int *)p);++((struct Obj00299 *)p)->f915D;if(((struct Obj00299 *)p)->f915D==((struct Obj00299 *)p)->f915E){((struct Obj00299 *)p)->f915D=0;((struct Obj00299 *)p)->f9190=0;return 6;}else ((struct Obj00299 *)p)->f9190=3;break;
    }
    return 5;
}
