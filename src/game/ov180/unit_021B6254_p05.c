/*
 * file:     unit_021B6254_p05.c
 * unit:     yes
 * function: func_021B69F8, func_021B6A10, func_021B6A60, func_021B6AB0, func_021B6AFC, func_021B6B34, func_021B6B70, func_021B6BAC, func_021B6F34, func_021B6F80, func_021B6FAC, func_021B7210, func_021B723C, func_021B727C, func_021B72B0, func_021B7300, func_021B7318, func_021B7390, func_021B73B0, func_021B73E4, func_021B7408, func_021B7438, func_021B746C, func_021B7488, func_021B74B4, func_021B74C8, func_021B7510, func_021B7530, func_021B7550, func_021B756C, func_021B75A4, func_021B75E8, func_021B7604, func_021B761C
 * address:  0x021B69F8
 * region:   ov180
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02015F2C  0x02015F2C  thumb
 *   func_021B69E8  0x021B69E8  thumb  ov180
 *   d_021B814C 0x021B814C data a4
 *   func_021B7D5C 0x021B7D5C thumb ov180
 *   func_021B6704 0x021B6704 thumb ov180
 *   func_021B7F30 0x021B7F30 thumb ov180
 *   func_021B66E4 0x021B66E4 thumb ov180
 *   func_02043534 0x02043534 arm
 *   func_020435F4 0x020435F4 arm
 *   func_0207D534 0x0207D534 arm
 *   func_021B6210 0x021B6210 thumb ov180
 *   func_021B6418 0x021B6418 thumb ov180
 *   func_021B64AC 0x021B64AC thumb ov180
 *   func_021B64DC 0x021B64DC thumb ov180
 *   func_021B621C 0x021B621C thumb ov180
 *   func_021B6474 0x021B6474 thumb ov180
 *   func_021B64D0 0x021B64D0 thumb ov180
 *   func_020221A4 0x020221A4 thumb
 *   func_021B61D4 0x021B61D4 thumb ov180
 *   func_021B6224 0x021B6224 thumb ov180
 *   func_021B66A0 0x021B66A0 thumb ov180
 *   func_021B6764 0x021B6764 thumb ov180
 *   func_021B6750 0x021B6750 thumb ov180
 *   func_021B7CF0 0x021B7CF0 thumb ov180
 *   func_021B63E8 0x021B63E8 thumb ov180
 *   func_021B6158 0x021B6158 thumb ov180
 *   func_021B6188 0x021B6188 thumb ov180
 *   func_021B7D44 0x021B7D44 thumb ov180
 *   func_021B675C 0x021B675C thumb ov180
 *   func_021B6770 0x021B6770 thumb ov180
 *   func_021B66D4 0x021B66D4 thumb ov180
 *   func_020061E4 0x020061E4 thumb
 *   func_02006254 0x02006254 thumb
 *   func_021B654C 0x021B654C thumb ov180
 *   func_021B65A0 0x021B65A0 thumb ov180
 *   func_021B6778 0x021B6778 thumb ov180
 *   func_021B67EC 0x021B67EC thumb ov180
 *   func_021B78E0 0x021B78E0 thumb ov180
 *   func_021B7C08 0x021B7C08 thumb ov180
 *   func_021B7750 0x021B7750 thumb ov180
 *   func_021B67C4 0x021B67C4 thumb ov180
 *   func_021B682C 0x021B682C thumb ov180
 *   func_02006A64 0x02006A64 thumb
 *   func_02006BD0 0x02006BD0 thumb
 *   func_021B681C 0x021B681C thumb ov180
 *   func_021B67B4 0x021B67B4 thumb ov180
 *   func_0204363C 0x0204363C arm
 *   func_021B6254 0x021B6254 thumb ov180
 *   func_021B6360 0x021B6360 thumb ov180
 *   func_021B68A8 0x021B68A8 thumb ov180
 *   func_021B7D80 0x021B7D80 thumb ov180
 *   func_021B6170 0x021B6170 thumb ov180
 *   func_021B7F0C 0x021B7F0C thumb ov180
 *   func_021B6340 0x021B6340 thumb ov180
 *   func_021B6914 0x021B6914 thumb ov180
 *   func_02005E50 0x02005E50 thumb
 *   func_02005D28 0x02005D28 thumb
 *   func_021B7C60 0x021B7C60 thumb ov180
 *   func_021B692C 0x021B692C thumb ov180
 *   func_021B699C 0x021B699C thumb ov180
 *   func_02015E4C 0x02015E4C thumb
 *   func_021B6984 0x021B6984 thumb ov180
 *   func_021B7F38 0x021B7F38 thumb ov180
 *   func_020362DC 0x020362DC arm
 *   func_02035C60 0x02035C60 arm
 *   func_02005E30 0x02005E30 thumb
 *   func_0202208C 0x0202208C thumb
 *   func_020056EC 0x020056EC thumb
 *   func_02041F28  0x02041F28  arm
 *   d_021B827C 0x021B827C data a4
 *   d_021B8298 0x021B8298 data a4
 *   func_021B61FC 0x021B61FC thumb ov180
 *   func_0204A48C 0x0204A48C arm
 *   func_0204B100 0x0204B100 arm
 *   func_02025538 0x02025538 thumb
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   func_02025588 0x02025588 thumb
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A5AC 0x0204A5AC arm
 *   func_0204B944 0x0204B944 arm
 *   func_0204B8D4 0x0204B8D4 arm
 *   func_0204A600 0x0204A600 arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B454 0x0204B454 arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B8C4 0x0204B8C4 arm
 *   func_0204B878 0x0204B878 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B98C  0x0204B98C  arm
 *   d_021B90CC     0x021B90CC  data  ov180  a4
 *   d_021B90E4     0x021B90E4  data  ov180  a4
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3B4  0x0204B3B4  arm
 *   d_021B8174 0x021B8174 data ov180 a4
 *   d_021B818C 0x021B818C data a4
 *   func_0202D7C8 0x0202D7C8 thumb
 *   func_020185F0 0x020185F0 thumb
 *   func_02017DBC 0x02017DBC thumb
 *   func_0202D934 0x0202D934 thumb
 *   func_0202D8D0 0x0202D8D0 thumb
 *   func_0202D9A4 0x0202D9A4 thumb
 *   func_02017DE4 0x02017DE4 thumb
 *   func_02049238 0x02049238 arm
 */
#include "../../matched/include/Obj08298.h"
#include "../../matched/include/Obj10719.h"
#include "../../matched/include/Obj24487.h"
#include "../../matched/include/Obj00547.h"
#include "../../matched/include/Obj04569.h"
#include "../../matched/include/Obj00299.h"
#include "../../matched/include/Obj00242.h"
#include "../../matched/include/Obj24488.h"
#include "../../matched/include/Obj24489.h"
#include "../../matched/include/Obj14404.h"
#include "../../matched/include/Obj24490.h"
#include "../../matched/include/Obj03876.h"
#include "../../matched/include/Obj10720.h"
#include "../../matched/include/Obj08299.h"
#include "../../matched/include/Obj24493.h"
#include "../../matched/include/Obj02516.h"

struct Cfg;
struct Bank;
struct Obj;
struct Vec2;
struct Actor;
struct PtS;
struct Sav;
typedef unsigned short u16;

typedef unsigned int   u32_021B6A60;

typedef unsigned int   u32_021B6AB0;

typedef unsigned int u32_021B6AFC;

typedef unsigned char u8;

typedef unsigned int u32_021B6B34;

typedef unsigned int u32_021B6B70;

typedef unsigned long u32_021B6BAC;

typedef signed short   s16_021B6BAC;

typedef unsigned int   u32_021B6F34;

typedef unsigned int u32_021B6F80;

typedef unsigned long u32_021B6FAC;

typedef unsigned int u32_021B7210;

typedef unsigned int   u32_021B723C;

typedef unsigned int u32_021B727C;

typedef unsigned int   u32_021B7300;

typedef struct { unsigned words[7]; } Config;

typedef unsigned int   u32_021B7318;

typedef unsigned int u32_021B7390;

typedef unsigned int u32_021B73B0;

typedef unsigned int u32_021B73E4;

typedef struct {short x,y;} Pair_021B73E4;

typedef short s16_021B7408;

typedef unsigned int u32_021B7408;

typedef struct { s16_021B7408 x,y; } Pair_021B7408;

typedef short s16_021B7438;

typedef unsigned int u32_021B7438;

typedef struct { s16_021B7438 y,x; } Pair_021B7438;

typedef short s16_021B7488;

typedef unsigned int u32_021B7488;

typedef unsigned int   u32_021B74B4;

typedef short s16_021B7510;

typedef unsigned int u32_021B7510;

typedef short s16_021B7530;

typedef unsigned int u32_021B7530;

typedef unsigned int   u32_021B7550;

typedef short s16_021B756C;

typedef unsigned int u32_021B756C;

typedef unsigned long u32_021B761C;

extern void func_02015F2C(int, void *, void *, int);
extern void func_021B69E8(int *p);
extern void func_021B7D5C(void *p);
extern void func_021B6704(char *);
extern void func_021B7F30(void *p);
extern void func_021B66E4(char *);
extern void func_02043534(u32_021B6A60 planes);
extern void func_020435F4(u32_021B6A60 planes);
extern void func_0207D534(volatile u16 *reg, int brightness);
extern void func_021B6210(void);
extern void func_021B6418(char *);
extern void func_021B64AC(char *);
extern void func_021B64DC(unsigned char *p);
extern void func_021B621C(void);
extern void func_021B6474(char *);
extern void func_021B64D0(char *);
extern unsigned func_020221A4(void);
extern void func_021B61D4(int);
extern void func_021B6224(void);
extern void func_021B66A0(char *);
extern void func_021B6764(void);
extern void func_021B6750(void);
extern void func_021B7CF0(char *);
extern void func_021B63E8(void);
extern void func_021B6158(int *);
extern void func_021B6188(u8 *p);
extern void func_021B7D44(int *);
extern void func_021B675C(void);
extern void func_021B6770(void);
extern void func_021B66D4(int *p);
extern void func_020061E4(u32_021B6BAC);
extern int func_02006254(u32_021B6BAC);
extern int func_02006A64(u32_021B6BAC);
extern u32_021B6BAC func_02006BD0(u32_021B6BAC i);
extern void func_021B67C4(char *,int);
extern void func_021B682C(int *,int);
extern void func_021B681C(int *);
extern void func_021B67B4(int *);
extern void func_0204363C(u32_021B6F34 swap);
extern void func_021B6254(void);
extern void func_021B6360(void);
extern void func_021B68A8(char *);
extern void func_021B7D80(char *);
extern void func_021B6170(int *p);
extern void func_021B7F0C(int *p);
extern void func_021B6340(void);
extern void func_021B6914(int *);
extern u32_021B6FAC func_020362DC(void);
extern int func_02035C60(void);
extern int func_02005E50(void);
extern void func_02005D28(void),func_020061E4(u32_021B6FAC),func_02005E30(u32_021B6FAC),func_02015E4C(void *);
extern void func_021B7C60(char *p, int index, unsigned value);
extern void func_021B692C(char *),func_021B699C(char *,int),func_021B69F8(char *),func_021B6984(char *),func_021B7F38(char *);
extern void func_0202208C(void *p1, u32_021B7210 p2, u32_021B7210 p3, u32_021B7210 p4, u32_021B7210 p5, u32_021B7210 p6, u32_021B7210 p7);
extern unsigned func_020056EC(unsigned);
extern void func_02041F28(u32_021B7300 which, u32_021B7300 op, u16 value);
extern int func_021B61FC(int);
extern void func_0204A48C(const struct Cfg *cfg, unsigned int arg, unsigned int heapId);
extern struct Bank *func_0204B100(int count, u8 flag, u32_021B7318 heapId);
extern void *func_02025538(unsigned int a0, void *a1);
extern void func_020434DC(unsigned,unsigned);
extern void func_02043598(unsigned,unsigned);
extern void func_02025588(void *);
extern u32_021B7390 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern u32_021B73B0 func_0204B944(struct Obj *p);
extern void func_0204B8D4(struct Obj *p, u32_021B73B0 arg);
extern void func_0204A600(void);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32_021B73E4 which);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern void func_0204B3DC(struct Obj *,unsigned int);
extern void func_0204B8C4(struct Obj *,u32_021B7488),func_0204B878(struct Obj *,u16),func_0204B92C(struct Obj *,u32_021B7488);
extern u32_021B74B4 func_0204B98C(struct Actor *a);
extern void func_0204A8D4(u32_021B7510);
extern void func_0204ADA4(u32_021B7530);
extern void func_0204AFD8(u32_021B7550 i);
extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern void func_0204B3B4(struct Obj *p);
extern int func_0202D7C8(int);
extern void *func_020185F0(void *);
extern u32_021B761C func_02017DBC(struct Sav *p);
extern u32_021B761C func_02017DE4(struct Sav *p, u32_021B761C f);
extern int func_0202D934(int,void *,int,int,u16),func_0202D8D0(int,void *,int,int,u16,u16);
extern u32_021B761C func_0202D9A4(u32_021B761C,u32_021B761C,u32_021B761C,u32_021B761C,u16);
extern void func_02049238(u8 *);
void func_021B69F8(char *p);
int func_021B6A10(char *p);
int func_021B6A60(char *p);
int func_021B6AB0(char *p);
int func_021B6AFC(char *p);
int func_021B6B18(char *p);
int func_021B6B34(char *p);
int func_021B6B70(char *p);
int func_021B6BAC(char *p);
int func_021B6F34(char *p);
int func_021B6F80(char *p);
int func_021B6FAC(char *p);
int func_021B7210(char *p,int n);
int func_021B723C(char *p,int value,int duration);
int func_021B7268(char *p,int value);
void func_021B727C(char *p);
int func_021B72B0(char *p,int i);
void func_021B7300(char *a0);
void func_021B7318(char *p,int mode);
void func_021B7390(char *p);
void func_021B73B0(char *p);
void func_021B73E4(char *p, int i, short x, short y);
void func_021B7408(u8 *p,int n,s16_021B7408 *x,s16_021B7408 *y);
void func_021B7438(u8 *p,int n,int x,int y);
void func_021B746C(int *p, int i, int a);
void func_021B7488(u8 *p,int n,int v);
int func_021B74B4(int *p, int i);
void func_021B74C8(int *base);
void func_021B7510(char *p,int n);
void func_021B7530(char *p,int n);
void func_021B7550(char *p, int i);
void func_021B756C(char *p);
struct Obj *func_021B75A4(char *p,const char *q);
void func_021B75E8(char *p, int i);
void func_021B7604(int *p);
void func_021B761C(char *p);
extern const Config d_021B827C,d_021B8298;
extern int d_021B90CC[6];
extern int d_021B90E4[7];
extern const char d_021B8174[],d_021B818C[];


void func_021B69F8(char *p)
{
    *(int *)(p + 0x24) = 0;
    func_02015F2C(*(int *)(p + 0x1c), p, (void *)func_021B69E8, 0);
}

extern int (*d_021B814C[])(char *);

int func_021B6A10(char *p) {
    ((struct Obj08298 *)p)->f918C=d_021B814C[*(int *)(p+0x918c)](p);
    if(((struct Obj08298 *)p)->f918C==10) return 0;
    if(((struct Obj08298 *)p)->f8==1) {
        func_021B7D5C(p); func_021B6704(p);
    } else if(((struct Obj08298 *)p)->f8==2) {
        func_021B7F30(p); func_021B66E4(p); func_021B7300(p);
    }
    return 1;
}

int func_021B6A60(char *p) {
    func_02043534(0); func_020435F4(0);
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    func_0207D534((void *)0x0400006c,-16);
    func_0207D534((void *)0x0400106c,-16);
    func_021B6210(); func_021B6418(p); func_021B64AC(p); func_021B64DC((unsigned char *)p);
    return 4;
}

int func_021B6AB0(char *p) {
    func_021B64D0(p); func_021B6474(p); func_021B621C();
    func_0207D534((void *)0x0400006c,-16);
    func_0207D534((void *)0x0400106c,-16);
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    func_02043534(0); func_020435F4(0);
    return 10;
}

int func_021B6AFC(char *p){if(func_020221A4()==1)return ((struct Obj24487 *)p)->f9194;return 2;}

int func_021B6B18(char *p){if(((struct Obj10719 *)p)->f9188==0)return ((struct Obj10719 *)p)->f9194;((struct Obj10719 *)p)->f9188-=1;return 3;}

int func_021B6B34(char *p){func_021B61D4(0);func_021B6224();func_021B66A0(p);func_021B6764();func_021B6750();func_021B7318(p,0);func_021B7CF0(p);func_021B63E8();func_021B6158((int *)p);((struct Obj00547 *)p)->f8=1;return 5;}

int func_021B6B70(char *p){func_021B6188((u8 *)p);*(u16 *)0x04000050=0;*(u16 *)0x04001050=0;func_021B7D44((int *)p);func_021B7390(p);func_021B675C();func_021B6770();func_021B66D4((int *)p);((struct Obj04569 *)p)->f8=0;return 7;}

/*
 * trailing: zero halfword alignment padding at 0x021B6F32.
 * Bound: original stack allocation 24 bytes is six output coordinate pairs, each two signed halfwords.
 * Caller evidence: 021B74B4's forwarded r0 is consumed; 021B7268 and 021B723C return their verified state values.
 */
int func_021B6BAC(char *p) {
    short coords[12];
    int busy;
    switch(((struct Obj00299 *)p)->f9190){
    case 0: ++((struct Obj00299 *)p)->f9190;return func_021B7268(p,32);
    case 1: func_020061E4(0x79B);++((struct Obj00299 *)p)->f9190;break;
    case 2: if(++((struct Obj00299 *)p)->f9188==48){func_020061E4(0x79C);((struct Obj00299 *)p)->f9188=0;++((struct Obj00299 *)p)->f9190;}break;
    case 3: if(func_02006254(0x79C)==0){
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
    case 11: if(func_021B72B0(p,0)==0){func_02006A64(((struct Obj00299 *)p)->f9184);func_021B746C((int *)p,4,1);func_021B7488((u8 *)p,4,6);++((struct Obj00299 *)p)->f9190;return func_021B7268(p,128);}break;
    case 12: if(func_02006BD0(((struct Obj00299 *)p)->f9184)==0 && func_021B74B4((int *)p,4)==0)++((struct Obj00299 *)p)->f9190;break;
    case 13: func_021B7408((u8 *)p,0,&coords[5],&coords[4]);if(coords[5]!=-48)func_021B7438((u8 *)p,0,-16,0);else ++((struct Obj00299 *)p)->f9190;break;
    case 14: func_021B7408((u8 *)p,3,&coords[3],&coords[2]);if(coords[3]!=264)func_021B7438((u8 *)p,3,16,0);else ++((struct Obj00299 *)p)->f9190;func_021B7C08(p);break;
    case 15: func_021B7408((u8 *)p,2,&coords[1],&coords[0]);if(coords[1]!=-8){func_021B7438((u8 *)p,2,-16,0);func_021B7C08(p);}else{++((struct Obj00299 *)p)->f9190;return func_021B723C(p,5,6);}break;
    case 16: func_021B681C((int *)p);func_021B67B4((int *)p);++((struct Obj00299 *)p)->f915D;if(((struct Obj00299 *)p)->f915D==((struct Obj00299 *)p)->f915E){((struct Obj00299 *)p)->f915D=0;((struct Obj00299 *)p)->f9190=0;return 6;}else ((struct Obj00299 *)p)->f9190=3;break;
    }
    return 5;
}

/*
 * trailing: zero halfword alignment padding at 0x021B6F7E.
 */
int func_021B6F34(char *p) {
    func_0204363C(0); func_021B61D4(1); func_021B6224(); func_021B6254(); func_021B6360();
    func_021B66A0(p); func_021B68A8(p); func_021B7318(p,1); func_021B7D80(p); func_021B6170((int *)p);
    ((struct Obj00547 *)p)->f8=2;
    return func_021B7210(p,8);
}

int func_021B6F80(char *p){func_021B6188((u8 *)p);func_021B7F0C((int *)p);func_021B7390(p);func_021B6340();func_021B6914((int *)p);func_021B66D4((int *)p);((struct Obj04569 *)p)->f8=0;return 1;}

/*
 * Caller evidence: 021B74B4 leaves its forwarded return in r0, read here; 02005E50 is the matched zero-argument sub_02005E50.
 */
int func_021B6FAC(char *p) {
    int ready;
    if(((struct Obj00242 *)p)->f9198==1 && func_020221A4()==1 && func_02005E50()==0) { func_02005D28();return 9; }
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
        if(((struct Obj00242 *)p)->f9188!=20){func_021B699C(p,-8);++((struct Obj00242 *)p)->f9188;}else{func_02015E4C(((struct Obj00242 *)p)->f1C);((struct Obj00242 *)p)->f9188=0;++((struct Obj00242 *)p)->f9190;}break;
    case 10: if(((struct Obj00242 *)p)->f9188!=128)++((struct Obj00242 *)p)->f9188;else{func_021B69F8(p);((struct Obj00242 *)p)->f9188=0;++((struct Obj00242 *)p)->f9190;}break;
    case 11:
        if(((struct Obj00242 *)p)->f24!=0){
            if(((struct Obj00242 *)p)->f9188!=24){func_021B699C(p,-8);++((struct Obj00242 *)p)->f9188;}
            else{func_021B6984(p);((struct Obj00242 *)p)->f9188=0;++((struct Obj00242 *)p)->f915D;if(((struct Obj00242 *)p)->f915D==((struct Obj00242 *)p)->f915E)((struct Obj00242 *)p)->f915D=0;((struct Obj00242 *)p)->f9190=8;}
        }break;
    }
    if(((struct Obj00242 *)p)->f9190>=6)func_021B7F38(p);
    if(((struct Obj00242 *)p)->f9190>=8 && ((struct Obj00242 *)p)->f9198==0 && ((func_020362DC()&3)!=0 || func_02035C60()==1)){
        ((struct Obj00242 *)p)->f9198=1;func_02005E30(220);func_021B723C(p,9,188);
    }
    return 8;
}

int func_021B7210(char *p,int n){func_0202208C(0,1,1,0,6,1,141);((struct Obj24488 *)p)->f9194=n;return 2;}

/*
 * follower: 0x021B7268 store-return stub included in this verified unit.
 */
int func_021B723C(char *p,int value,int duration) {
    func_0202208C(0,0,0,0,duration,1,141);
    ((struct Obj24489 *)p)->f9194=value;
    return 2;
}

int func_021B7268(char *p,int value) {
    ((struct Obj00299 *)p)->f9188=value;
    ((struct Obj00299 *)p)->f9194=((struct Obj00299 *)p)->f918C;
    return 3;
}

void func_021B727C(char *p){u32_021B727C i;char *q;((struct Obj24490 *)p)->f915F=0;for(i=0;i<8;i++){q=p+i*2;((struct Obj14404 *)q)->f9164=func_020056EC(8)-4;((struct Obj14404 *)q)->f9174=func_020056EC(8)-4;}}

int func_021B72B0(char *p,int i) {
    if(((struct Obj03876 *)p)->f915F==8) {
        func_021B73E4(p,i,((struct Obj03876 *)p)->f9160,((struct Obj03876 *)p)->f9162);
        return 0;
    }
    func_021B73E4(p,i,((struct Obj03876 *)p)->f9160+*(short *)(p+0x9164+((struct Obj03876 *)p)->f915F*2),((struct Obj03876 *)p)->f9162+*(short *)(p+0x9174+((struct Obj03876 *)p)->f915F*2));
    (((struct Obj03876 *)p)->f915F)++;
    return 1;
}


void func_021B7300(char *a0)
{
    func_02041F28(3, 1, 1);
    func_02041F28(7, 1, 1);
}

void func_021B7318(char *p,int mode) {
    if(mode==0) {
        Config cfg=d_021B827C;
        func_0204A48C((const struct Cfg *)(&cfg),func_021B61FC(mode),141);
    } else {
        Config cfg=d_021B8298;
        func_0204A48C((const struct Cfg *)(&cfg),func_021B61FC(mode),141);
    }
    *(int *)&((struct Obj00547 *)p)->f9044=(int)func_0204B100(249,0,141);
    ((struct Obj00547 *)p)->f911C=func_02025538(141,((struct Obj00547 *)p)->f9044);
    func_021B74C8((int *)p);
    func_020434DC(16,1); func_02043598(16,1);
}

void func_021B7390(char *p){func_02025588(((struct Obj04569 *)p)->f911C);func_0204B1CC(((struct Obj04569 *)p)->f9044);func_0204A5AC();}

void func_021B73B0(char *p){u32_021B73B0 i;char *q;for(i=0;i<33;i++){q=p+i*4;if(((struct Obj10720 *)q)->f9048&&func_0204B944(((struct Obj10720 *)q)->f9048)!=1)func_0204B8D4(((struct Obj10720 *)q)->f9048,4096);}func_0204A600();}

void func_021B73E4(char *p, int i, short x, short y){Pair_021B73E4 v;v.x=x;v.y=y;func_0204B404(*(void **)((u32_021B73E4)p+i*4+36936),(const struct Vec2 *)(&v),0);}

void func_021B7408(u8 *p,int n,s16_021B7408 *x,s16_021B7408 *y) { Pair_021B7408 s; func_0204B454(*(void **)(p+n*4+0x9048),(struct PtS *)&s,0); *x=s.x; *y=s.y; }

void func_021B7438(u8 *p,int n,int x,int y) { Pair_021B7438 s; func_021B7408(p,n,&s.x,&s.y); s.x=s.x+x; s.y=s.y+y; func_021B73E4((char *)p,n,s.x,s.y); }


void func_021B746C(int *p, int i, int a)
{
    int v = *(int *)((char *)p + i * 4 + 0x9048);

    if (v)
        func_0204B3DC((struct Obj *)v, a);
}

void func_021B7488(u8 *p,int n,int v) { func_0204B8C4(*(struct Obj **)(p+0x9048+n*4),0); func_0204B878(*(struct Obj **)(p+0x9048+n*4),v); func_0204B92C(*(struct Obj **)(p+0x9048+n*4),1); }


int func_021B74B4(int *p, int i)
{
    return func_0204B98C((struct Actor *)(*(int *)((char *)p + i * 4 + 0x9048)));
}


void func_021B74C8(int *base)
{
    unsigned i;

    for (i = 0; i < 6; i++) {
        ((int *)base)[i + 0x2433] = -1;
    }
    for (i = 0; i < 7; i++) {
        ((int *)base)[i + 0x2439] = -1;
    }
    for (i = 0; i < 6; i++) {
        ((int *)base)[i + 0x2440] = -1;
    }
}

void func_021B7510(char *p,int n) { if(*(u32_021B7510 *)(p+0x90cc+n*4)!=~0u) { func_0204A8D4(*(u32_021B7510 *)(p+0x90cc+n*4)); *(u32_021B7510 *)(p+0x90cc+n*4)=~0u; } }

void func_021B7530(char *p,int n) { if(*(u32_021B7530 *)(p+0x90e4+n*4)!=~0u) { func_0204ADA4(*(u32_021B7530 *)(p+0x90e4+n*4)); *(u32_021B7530 *)(p+0x90e4+n*4)=~0u; } }


void func_021B7550(char *p, int i)
{
    if (*(int *)(p + 0x9100 + i * 4) != -1) {
        func_0204AFD8(*(int *)(p + 0x9100 + i * 4));
        *(int *)(p + 0x9100 + i * 4) = -1;
    }
}

/*
 * EXACT* tail: two zero alignment bytes after the function.
 */
void func_021B756C(char *p) { u32_021B756C i; for(i=0;i<6;i++) func_021B7510(p,i); for(i=0;i<7;i++) func_021B7530(p,i); for(i=0;i<6;i++) func_021B7550(p,i); }

struct Obj *func_021B75A4(char *p,const char *q) {
    return func_0204B294((void *)((struct Obj24493 *)p)->f9044,*(int *)(p+0x90cc+*(const int *)&((struct Obj08299 *)q)->f8*4),*(int *)(p+0x90e4+*(const int *)&((struct Obj08299 *)q)->fC*4),*(int *)(p+0x9100+*(const int *)&((struct Obj08299 *)q)->f10*4),(void *)q,*(const unsigned short *)&((struct Obj08299 *)q)->f16,141);
}


void func_021B75E8(char *p, int i)
{
    if (*(int *)(p + 0x9048 + i * 4) != 0) {
        func_0204B3B4((struct Obj *)(*(int *)(p + 0x9048 + i * 4)));
        *(int *)(p + 0x9048 + i * 4) = 0;
    }
}


void func_021B7604(int *p)
{
    unsigned int i;

    for (i = 0; i < 0x21; i++)
        func_021B75E8((char *)p, i);
}

void func_021B761C(char *p)
{
    int bank;
    void *mon;
    u32_021B761C lock;
    if(((struct Obj02516 *)p)->f9048) {
        func_021B75E8(p,0);func_021B7510(p,0);func_021B7530(p,0);func_021B7550(p,0);
    }
    if(((struct Obj02516 *)p)->f904C) {
        func_021B75E8(p,1);func_021B7510(p,1);func_021B7530(p,1);func_021B7550(p,1);
    }
    bank=func_0202D7C8(141);
    mon=func_020185F0(*(void **)((u32_021B761C)p+((struct Obj02516 *)p)->f915D*4+0x9140));
    lock=func_02017DBC(mon);
    ((struct Obj02516 *)p)->f90CC=func_0202D934(bank,mon,0,0,141);
    ((struct Obj02516 *)p)->f90E4=func_0202D8D0(bank,mon,0,0,96,141);
    ((struct Obj02516 *)p)->f9100=func_0202D9A4((u32_021B761C)mon,0,2,0,141);
    ((struct Obj02516 *)p)->f90D0=func_0202D934(bank,mon,1,0,141);
    ((struct Obj02516 *)p)->f90E8=func_0202D8D0(bank,mon,1,0,128,141);
    ((struct Obj02516 *)p)->f9104=func_0202D9A4((u32_021B761C)mon,1,2,0,141);
    func_02017DE4(mon,lock);func_02049238((u8 *)bank);
    ((struct Obj02516 *)p)->f9048=(int)func_021B75A4(p,d_021B8174);
    ((struct Obj02516 *)p)->f904C=(int)func_021B75A4(p,d_021B818C);
}
