/*
 * file:     pmsiv_menu_p14.c
 * unit:     yes
 * function: func_021BDEF0, func_021BE1B8, func_021BE374, func_021BE3B8, func_021BE4C0, func_021BE580, func_021BE7B8, func_021BE7F0, func_021BE800, func_021BE890, func_021BE8B4, func_021BE934, func_021BEADC, func_021BEB44, func_021BEB60
 * address:  0x021BDEF0
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BABE8 0x021BABE8 thumb ov110
 *   func_02024158 0x02024158 thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_021B9BEC 0x021B9BEC thumb ov110
 *   func_021BD6F8 0x021BD6F8 thumb ov110
 *   func_021BD6B4 0x021BD6B4 thumb ov110
 *   func_021BAC30 0x021BAC30 thumb ov110
 *   func_021BF4F8 0x021BF4F8 thumb ov110
 *   func_021BF608 0x021BF608 thumb ov110
 *   func_021BF53C 0x021BF53C thumb ov110
 *   func_021BF82C 0x021BF82C thumb ov110
 *   func_021BF680 0x021BF680 thumb ov110
 *   func_021B9C90 0x021B9C90 thumb ov110
 *   func_021B9C74 0x021B9C74 thumb ov110
 *   func_021BD7A0 0x021BD7A0 thumb ov110
 *   func_021BDB50 0x021BDB50 thumb ov110
 *   func_021BD740 0x021BD740 thumb ov110
 *   func_021BDAA4 0x021BDAA4 thumb ov110
 *   func_021BD808 0x021BD808 thumb ov110
 *   func_021BD894 0x021BD894 thumb ov110
 *   func_021BB054 0x021BB054 thumb ov110
 *   func_021BD868 0x021BD868 thumb ov110
 *   func_021BAFAC 0x021BAFAC thumb ov110
 *   func_021BAF7C 0x021BAF7C thumb ov110
 *   d_021C392C 0x021C392C data a1
 *   func_02035C08 0x02035C08 arm
 *   d_021C3918 0x021C3918 data a1
 *   d_021C39B0 0x021C39B0 data a1
 *   func_02035C60 0x02035C60 arm
 *   func_02035D20 0x02035D20 arm
 *   func_02035D40 0x02035D40 arm
 *   d_021C39C4 0x021C39C4 data a1
 *   d_021C38F8 0x021C38F8 data a1
 *   func_021BB1F4 0x021BB1F4 thumb ov110
 *   func_021BB224 0x021BB224 thumb ov110
 *   func_021B999C 0x021B999C thumb ov110
 *   func_020362DC 0x020362DC arm
 *   d_021C3910 0x021C3910 data a4
 */
#include "../../matched/include/Obj00012.h"
#include "../../matched/include/Obj00189.h"
#include "../../matched/include/Obj22380.h"
#include "../../matched/include/Obj00586.h"
#include "../../matched/include/Obj13792.h"

struct Ctx;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef short s16;

typedef struct { s16 a; s8 b,c; } State;

typedef int (*Handler)(u8 *,void *);

typedef struct { u8 b[8]; } Box_021BE800;

typedef struct { unsigned char b[16]; } Box_021BE890;

typedef struct { u8 b[8]; } Box_021BE8B4;

extern int func_021BABE8(u8 *p);
extern u32 func_02024158(const u8 *p);
extern void func_020061E4(u32);
extern void func_021B9BEC(u8 *,int);
extern void func_021BD6F8(State *,void *);
extern void func_021BD6B4(State *,void *);
extern void func_021BAC30(u8 *,int);
extern void func_021BF4F8(u8 *,u32);
extern void func_021BF608(u8 *,u32 *);
extern void func_021BF53C(u8 *,u32 *);
extern void func_021BF82C(u8 *);
extern int func_021BF680(u8 *);
extern int func_021B9C90(unsigned int a, int b);
extern int func_021B9C74(unsigned int a);
extern void func_021BD7A0(u8 *,Handler);
extern int func_021BDB50(u32 *);
extern void func_021BD740(u8 *p, void *out, int v);
extern int func_021BDAA4(u8 *);
extern int func_021BD808(u8 *p, void *q);
extern int func_021BD894(u8 *,void *);
extern int func_021BB054(u8 *);
extern void func_021BD868(u8 *);
extern int func_021BAFAC(u32 p);
extern void func_021BAF7C(unsigned p, int v);
extern int func_02035C08(const void *);
extern int func_02035C60(void);
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern u32 func_02035D40(struct Ctx *ctx, u32 a, u32 b);
extern int func_021BB1F4(void);
extern void func_021BB224(unsigned,int *,int *);
extern u32 func_021B999C(u8 *,int);
extern u32 func_020362DC(void);
int func_021BDEF0(u8 *p,u32 *q);
int func_021BE1B8(u8 *p,u32 *q);
int func_021BE374(u8 *p,unsigned *q);
int func_021BE3B8(u8 *p,u32 *q);
int func_021BE4C0(u8 *p,unsigned *q);
void func_021BE580(u8 *p,u32 *q);
int func_021BE7B8(u8 *p);
int func_021BE7F0(void);
int func_021BE800(u8 *a0);
int func_021BE890(void *a0);
int func_021BE8B4(u8 *a0);
void func_021BE934(u8 *p,u32 *q);
void func_021BEADC(u8 *p,void *q);
int func_021BEB44(u8 *p);
int func_021BEB60(u8 *p);
extern const u8 d_021C392C[];
extern const unsigned char d_021C3918[];
extern const Box_021BE800 d_021C39B0;
extern const Box_021BE890 d_021C39C4;
extern const Box_021BE8B4 d_021C38F8;

int func_021BDEF0(u8 *p,u32 *q)
{
    int keys;
    int accept;
    int index;
    switch(*q) {
    case 0:
        p[0x68]=func_021BABE8(*(u8 * *)&((struct Obj00012 *)p)->f14);
        *q=1;
    case 1:
        if(func_02024158((const u8 *)(*(u32 *)&((struct Obj00012 *)p)->f0))) {
            if(((struct Obj00012 *)p)->f38&32) break;
            if(((struct Obj00012 *)p)->f38&16) break;
        }
        keys=((struct Obj00012 *)p)->f34;
        if(keys&64) {
            func_020061E4(1352);
            if(((struct Obj00012 *)p)->f4A==0) {
                ((struct Obj00012 *)p)->f48=1;
                func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,7);
                *q=2;
            } else if(p[0x68]>1 && ((struct Obj00012 *)p)->f4A!=0) {
                (((struct Obj00012 *)p)->f4A)--;
                func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,16);
            }
        } else if(keys&128) {
            func_020061E4(1352);
            if(p[0x68]>1 && ((struct Obj00012 *)p)->f4A<p[0x68]-1) {
                (((struct Obj00012 *)p)->f4A)++;
                func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,16);
            } else {
                ((struct Obj00012 *)p)->f48=0;
                func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,7);
                *q=2;
            }
        } else if((keys&8) || ((accept=keys&1) && p[0x68]==0)) {
            func_020061E4(1352);
            ((struct Obj00012 *)p)->f48=0;
            func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,7);
            *q=2;
        } else if(((struct Obj00012 *)p)->f38&32) {
            func_020061E4(1636);
            ((struct Obj00012 *)p)->f4A=0;
            func_021BD6F8((State *)(p+0x64),p+8);
            func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,3);
            func_021BAC30(*(u8 * *)&((struct Obj00012 *)p)->f14,0);
            *q=3;
        } else if(((struct Obj00012 *)p)->f38&16) {
            func_020061E4(1636);
            ((struct Obj00012 *)p)->f4A=0;
            func_021BD6B4((State *)(p+0x64),p+8);
            func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,3);
            func_021BAC30(*(u8 * *)&((struct Obj00012 *)p)->f14,1);
            *q=3;
        } else if(keys&2) {
            func_020061E4(1361);
            func_021BF4F8(p,(u32)func_021BF608);
        } else if(accept) {
            func_020061E4(1356);
            func_021BF82C(p);
            func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,10);
            *q=8;
        }
        break;
    case 3: if(func_021B9C90((unsigned int)(*(u8 * *)&((struct Obj00012 *)p)->f14),3)) *q=0; break;
    case 2:
        if(func_021B9C74((unsigned int)(*(u8 * *)&((struct Obj00012 *)p)->f14))) {
            if(((struct Obj00012 *)p)->f34&64) {
                func_020061E4(1352);
                if(((struct Obj00012 *)p)->f48) { ((struct Obj00012 *)p)->f48^=1; func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,17); }
                else {
                    index=p[0x68]-1;
                    if(p[0x68]==0) index=0;
                    ((struct Obj00012 *)p)->f4A=index;
                    func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,9); *q=0;
                }
            } else if(((struct Obj00012 *)p)->f34&128) {
                func_020061E4(1352);
                if(((struct Obj00012 *)p)->f48) { ((struct Obj00012 *)p)->f4A=0; func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,9); *q=0; }
                else { ((struct Obj00012 *)p)->f48^=1; func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,17); }
            } else if(((struct Obj00012 *)p)->f34&8) {
                func_020061E4(1352); ((struct Obj00012 *)p)->f48=0; func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,17);
            } else if(((struct Obj00012 *)p)->f34&1) {
                if(((struct Obj00012 *)p)->f48==0) {
                    if(func_021BF680(p)) func_020061E4(1356);
                    else func_020061E4(1367);
                    *q=4;
                } else { func_020061E4(1361); *q=5; }
            } else if(((struct Obj00012 *)p)->f34&2) { func_020061E4(1361); *q=5; }
        }
        break;
    case 4: *q=6; func_021BF4F8(p,(u32)func_021BF53C); break;
    case 5: *q=6; func_021BF4F8(p,(u32)func_021BF608); break;
    case 6: *q=2; break;
    case 7: if(func_021B9C74((unsigned int)(*(u8 * *)&((struct Obj00012 *)p)->f14))) func_021BD7A0(p,(Handler)func_021BE3B8); break;
    case 8: if(func_021B9C74((unsigned int)(*(u8 * *)&((struct Obj00012 *)p)->f14))) func_021BD7A0(p,(Handler)func_021BE4C0); break;
    }
    return 0;
}

int func_021BE1B8(u8 *p,u32 *q)
{
    int hit;
    int index;
    switch(*q) {
    case 0:
        p[0x68]=func_021BABE8(*(u8 * *)&((struct Obj00012 *)p)->f14);
        *q=1;
    case 1:
    case 2:
        index=func_021BDB50((u32 *)p);
        if(index>-1) {
            ((struct Obj00012 *)p)->f4A=0;
            func_021BD740((u8 *)(p+0x64),p+8,index);
            func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,3);
            func_020061E4(1352);
            *q=3;
        } else {
            hit=func_021BDAA4(p);
            switch(hit) {
            case 0:
                if(func_021BF680(p)) func_020061E4(1356);
                else func_020061E4(1367);
                ((struct Obj00012 *)p)->f48=0;
                func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,8);
                *q=hit+4;
                break;
            case 1:
                func_020061E4(1361);
                ((struct Obj00012 *)p)->f48=1;
                func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,8);
                *q=hit+4;
                break;
            case 2:
            case 4:
                func_020061E4(1636);
                ((struct Obj00012 *)p)->f4A=0;
                func_021BD6F8((State *)(p+0x64),p+8);
                func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,3);
                func_021BAC30(*(u8 * *)&((struct Obj00012 *)p)->f14,0);
                *q=3;
                break;
            case 3:
            case 5:
                func_020061E4(1636);
                ((struct Obj00012 *)p)->f4A=0;
                func_021BD6B4((State *)(p+0x64),p+8);
                func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,3);
                func_021BAC30(*(u8 * *)&((struct Obj00012 *)p)->f14,1);
                *q=3;
                break;
            case 6:
            case 7:
                func_020061E4(1356);
                func_021BF82C(p);
                ((struct Obj00012 *)p)->f4A=hit-6;
                func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,10);
                *q=8;
                break;
            }
        }
        break;
    case 3: if(func_021B9C90((unsigned int)(*(u8 * *)&((struct Obj00012 *)p)->f14),3)) *q=0; break;
    case 4: *q=6; func_021BF4F8(p,(u32)func_021BF53C); break;
    case 5: *q=6; func_021BF4F8(p,(u32)func_021BF608); break;
    case 6: *q=2; break;
    case 7: if(func_021B9C74((unsigned int)(*(u8 * *)&((struct Obj00012 *)p)->f14))) func_021BD7A0(p,(Handler)func_021BE3B8); break;
    case 8: if(func_021B9C74((unsigned int)(*(u8 * *)&((struct Obj00012 *)p)->f14))) func_021BD7A0(p,(Handler)func_021BE4C0); break;
    }
    return 0;
}

int func_021BE374(u8 *p,unsigned *q) {
 if(*q<=2 && func_021BD808(p,q) && !((struct Obj00012 *)p)->f70) { func_020061E4(1352); return 0; }
 if(((struct Obj00012 *)p)->f70==0) { return func_021BDEF0(p,q); }
 else { return func_021BE1B8(p,q); }
}

int func_021BE3B8(u8 *p,u32 *q) {
    switch(*q) {
    case 0:
        if(func_021B9C74((unsigned int)(*(u8 * *)&((struct Obj00012 *)p)->f14))) {
            if(((struct Obj00012 *)p)->f34&64) {
                func_020061E4(1352);
                if(((struct Obj00012 *)p)->f48) { ((struct Obj00012 *)p)->f48^=1; func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,17); }
                else { func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,9); *q=0; }
            } else if(((struct Obj00012 *)p)->f34&128) {
                func_020061E4(1352);
                if(((struct Obj00012 *)p)->f48) { func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,9); *q=0; }
                else { ((struct Obj00012 *)p)->f48^=1; func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,17); }
            } else if(((struct Obj00012 *)p)->f34&8) {
                func_020061E4(1352); ((struct Obj00012 *)p)->f48=0; func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,17);
            } else if(((struct Obj00012 *)p)->f34&1) {
                func_020061E4(1356);
                if(((struct Obj00012 *)p)->f48==0) *q=1; else *q=2;
            } else if(((struct Obj00012 *)p)->f34&2) { func_020061E4(1356); *q=2; }
        }
        break;
    case 1: *q=3; func_021BF4F8(p,(u32)func_021BF53C); break;
    case 2: *q=4; func_021BF4F8(p,(u32)func_021BF608); break;
    case 3:
    case 4: *q=0; break;
    case 5: if(func_021B9C74((unsigned int)(*(u8 * *)&((struct Obj00012 *)p)->f14))) func_021BD7A0(p,func_021BD894); break;
    }
    return 0;
}

int func_021BE4C0(u8 *p,unsigned *q) {
 switch(*q) {
 case 0:
  if(func_021B9C90((unsigned int)(*(u8 * *)&((struct Obj00012 *)p)->f14),18) && func_021B9C90((unsigned int)(*(u8 * *)&((struct Obj00012 *)p)->f14),33) && func_021B9C90((unsigned int)(*(u8 * *)&((struct Obj00012 *)p)->f14),32)) func_021BEADC(p,q);
  break;
 case 1:
  if(func_021B9C90((unsigned int)(*(u8 * *)&((struct Obj00012 *)p)->f14),32)) {
   if(((struct Obj00012 *)p)->f50!=253) { ((struct Obj00012 *)p)->f4C=((struct Obj00012 *)p)->f50; func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,18); }
   *q=0;
  }
  break;
 case 2:
  if(func_021B9C74((unsigned int)(*(u8 * *)&((struct Obj00012 *)p)->f14))) { if(*(Handler *)&((struct Obj00012 *)p)->f28==func_021BD894) func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,4); *q=3; }
  break;
 case 3:
  if(func_021B9C74((unsigned int)(*(u8 * *)&((struct Obj00012 *)p)->f14))) func_021BD7A0(p,*(Handler *)&((struct Obj00012 *)p)->f28);
  break;
 case 4:
  if(func_021B9C90((unsigned int)(*(u8 * *)&((struct Obj00012 *)p)->f14),25)) *q=0;
  break;
 }
 return 0;
}

void func_021BE580(u8 *p,u32 *q)
{
    if((((struct Obj00189 *)p)->f34&8) && p[0x69]==1) {
        ((struct Obj00189 *)p)->f4C=252;
        if(func_021BB054(*(u8 * *)&((struct Obj00189 *)p)->f1C)) {
            func_021BD868(p);
            *q=2;
            return;
        }
        func_020061E4(1367);
        func_021B9BEC(*(u8 * *)&((struct Obj00189 *)p)->f14,18);
        return;
    }
    if(((struct Obj00189 *)p)->f3C==0 || (((struct Obj00189 *)p)->f34&4)) {
        func_020061E4(1355);
        p[0x69]^=1;
        func_021BF82C(p);
        func_021B9BEC(*(u8 * *)&((struct Obj00189 *)p)->f14,25);
        *q=4;
        return;
    }
    if(((struct Obj00189 *)p)->f34&2) {
        if(p[0x69]==1 && func_021BAFAC((u32)(*(u8 * *)&((struct Obj00189 *)p)->f1C))) {
            ((struct Obj00189 *)p)->f50=((struct Obj00189 *)p)->f4C;
            *q=1;
            if(((struct Obj00189 *)p)->f4C!=253) {
                ((struct Obj00189 *)p)->f4C=253;
                func_021B9BEC(*(u8 * *)&((struct Obj00189 *)p)->f14,18);
            }
            func_020061E4(1363);
            func_021B9BEC(*(u8 * *)&((struct Obj00189 *)p)->f14,32);
            func_021BB054(*(u8 * *)&((struct Obj00189 *)p)->f1C);
            func_021B9BEC(*(u8 * *)&((struct Obj00189 *)p)->f14,30);
            return;
        }
        if(p[0x69]==1 && ((struct Obj00189 *)p)->f4C!=254) {
            ((struct Obj00189 *)p)->f4C=254;
            func_021B9BEC(*(u8 * *)&((struct Obj00189 *)p)->f14,18);
        }
        func_020061E4(1361);
        func_021B9BEC(*(u8 * *)&((struct Obj00189 *)p)->f14,11);
        *(Handler *)&((struct Obj00189 *)p)->f28=func_021BD894;
        *q=2;
        return;
    }
    if(((struct Obj00189 *)p)->f34&1) {
        if(((struct Obj00189 *)p)->f4C==252) {
            if(func_021BB054(*(u8 * *)&((struct Obj00189 *)p)->f1C)) {
                func_021BD868(p);
                *q=2;
                return;
            }
            func_020061E4(1367);
            return;
        } else if(((struct Obj00189 *)p)->f4C==253) {
            if(p[0x69]==1 && func_021BAFAC((u32)(*(u8 * *)&((struct Obj00189 *)p)->f1C))) {
                ((struct Obj00189 *)p)->f50=((struct Obj00189 *)p)->f4C;
                *q=1;
                func_020061E4(1363);
                func_021B9BEC(*(u8 * *)&((struct Obj00189 *)p)->f14,32);
                func_021BB054(*(u8 * *)&((struct Obj00189 *)p)->f1C);
                func_021B9BEC(*(u8 * *)&((struct Obj00189 *)p)->f14,30);
                return;
            }
            func_020061E4(1367);
            return;
        } else if(((struct Obj00189 *)p)->f4C==254) {
            func_020061E4(1361);
            func_021B9BEC(*(u8 * *)&((struct Obj00189 *)p)->f14,11);
            *(Handler *)&((struct Obj00189 *)p)->f28=func_021BD894;
            *q=2;
            return;
        } else if(p[0x69]==0) {
            func_021B9BEC(*(u8 * *)&((struct Obj00189 *)p)->f14,33);
            if(func_021BEB44(p)) {
                func_021BD868(p);
                *q=2;
                return;
            }
            func_020061E4(1367);
            return;
        } else {
            func_021BAF7C((unsigned int)(*(u8 * *)&((struct Obj00189 *)p)->f1C),((struct Obj00189 *)p)->f4C);
            func_020061E4(1356);
            func_021BB054(*(u8 * *)&((struct Obj00189 *)p)->f1C);
            func_021B9BEC(*(u8 * *)&((struct Obj00189 *)p)->f14,30);
            func_021B9BEC(*(u8 * *)&((struct Obj00189 *)p)->f14,33);
            return;
        }
    }
    if(func_021BEB60(p)) {
        func_020061E4(1352);
        func_021B9BEC(*(u8 * *)&((struct Obj00189 *)p)->f14,18);
    }
}

int func_021BE7B8(u8 *p) {
 int n=func_02035C08(d_021C392C);
 if(n==-1) return 0;
 switch(n) {
 case 0: return 1;
 case 1: if(((struct Obj22380 *)p)->f3C==0) return 2; break;
 }
 return 0;
}

int func_021BE7F0(void) { return func_02035C08(d_021C3918); }

int func_021BE800(u8 *a0) {
 int x,y;
 Box_021BE800 box=d_021C39B0;
 int i,j;
 if(!func_02035C60()) return -1;
 func_02035D20((u32 *)(&x),(u32 *)(&y));
 for(i=0;i<4;i++) {
  box.b[0]=24*i+56; box.b[1]=box.b[0]+16;
  for(j=0;j<3;j++) { box.b[2]=80*j+12; box.b[3]=box.b[2]+72; if(func_02035D40((struct Ctx *)(&box),x,y)!=-1) return j+3*i; }
 }
 return -1;
}

int func_021BE890(void *a0) { Box_021BE890 box=d_021C39C4; return func_02035C08(&box); }

int func_021BE8B4(u8 *a0) {
 Box_021BE8B4 box;
 int x,y;
 Box_021BE8B4 template;
 int i,count;
 count=func_021BB1F4();
 i=0;
 if(count>0) {
  template=d_021C38F8;
  do { box=template; func_021BB224(i,&x,&y); box.b[0]=y+48; box.b[1]=y+64; box.b[2]=x+8; box.b[3]=x+24; if(func_02035C08(&box)!=-1) return i; i++; } while(i<count);
 }
 return -1;
}

void func_021BE934(u8 *p,u32 *q)
{
    int r;
    switch(func_021BE7B8(p)) {
    case 1:
        func_020061E4(1361);
        func_021B9BEC(*(u8 * *)&((struct Obj00586 *)p)->f14,11);
        *(Handler *)&((struct Obj00586 *)p)->f28=func_021BD894;
        *q=2;
        return;
    case 2:
        func_020061E4(1355);
        p[0x69]^=1;
        func_021BF82C(p);
        func_021B9BEC(*(u8 * *)&((struct Obj00586 *)p)->f14,25);
        *q=4;
        return;
    }
    if(p[0x69]==0) {
        r=func_021BE800(p);
        if(r>=0) {
            ((struct Obj00586 *)p)->f4C=r;
            func_021B9BEC(*(u8 * *)&((struct Obj00586 *)p)->f14,33);
            if(r>=12 || !func_021B999C(*(u8 * *)&((struct Obj00586 *)p)->f18,((struct Obj00586 *)p)->f4C)) {
                func_020061E4(1367);
                return;
            }
            func_021BD868(p);
            *q=2;
            return;
        }
    } else {
        r=func_021BE8B4(p);
        if(r>-1) {
            ((struct Obj00586 *)p)->f4C=r;
            func_021BAF7C((unsigned int)(*(u8 * *)&((struct Obj00586 *)p)->f1C),((struct Obj00586 *)p)->f4C);
            func_021BB054(*(u8 * *)&((struct Obj00586 *)p)->f1C);
            func_021B9BEC(*(u8 * *)&((struct Obj00586 *)p)->f14,30);
            func_020061E4(1356);
            func_021B9BEC(*(u8 * *)&((struct Obj00586 *)p)->f14,33);
            return;
        }
        switch(func_021BE890(p)) {
        case 0:
            ((struct Obj00586 *)p)->f4C=252;
            if(func_021BB054(*(u8 * *)&((struct Obj00586 *)p)->f1C)) {
                func_021BD868(p);
                *q=2;
                return;
            } else {
                func_020061E4(1367);
                return;
            }
        case 1:
            ((struct Obj00586 *)p)->f4C=253;
            if(func_021BAFAC((u32)(*(u8 * *)&((struct Obj00586 *)p)->f1C))) {
                ((struct Obj00586 *)p)->f50=((struct Obj00586 *)p)->f4C;
                *q=1;
                func_020061E4(1363);
                func_021B9BEC(*(u8 * *)&((struct Obj00586 *)p)->f14,32);
                func_021BB054(*(u8 * *)&((struct Obj00586 *)p)->f1C);
                func_021B9BEC(*(u8 * *)&((struct Obj00586 *)p)->f14,30);
                return;
            } else {
                func_020061E4(1367);
                return;
            }
        case 2:
            ((struct Obj00586 *)p)->f4C=254;
            func_020061E4(1361);
            func_021B9BEC(*(u8 * *)&((struct Obj00586 *)p)->f14,11);
            *(Handler *)&((struct Obj00586 *)p)->f28=func_021BD894;
            *q=2;
            break;
        case -1:
            break;
        }
    }
}

void func_021BEADC(u8 *p,void *q) {
    if(func_021BD808(p,q)) {
        if(p[105]==0) {
            if(*(u32 *)&((struct Obj00012 *)p)->f70==0 && !(func_020362DC()&2)) { func_020061E4(1352); return; }
        } else {
            if(*(u32 *)&((struct Obj00012 *)p)->f70==0) { func_020061E4(1352); return; }
        }
    }
    if(func_021B9C90((unsigned int)(((struct Obj00012 *)p)->f14),30)) {
        if(*(u32 *)&((struct Obj00012 *)p)->f70==0) func_021BE580(p,q);
        else func_021BE934(p,q);
    }
}

int func_021BEB44(u8 *p) { if(func_021B999C(*(u8 * *)&((struct Obj13792 *)p)->f18,((struct Obj13792 *)p)->f4C)!=0) return 1; return 0; }

extern int (*const d_021C3910[])(u8 *);

/*
 * extent: unlabelled follower 0x021BEB78, filed separately under its own shard.
 */
int func_021BEB60(u8 *p) { return d_021C3910[p[105]](p); }
