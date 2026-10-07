/*
 * file:     pmsiv_menu_p13.c
 * unit:     yes
 * function: func_021BDA94, func_021BDAA4, func_021BDB50, func_021BDB98, func_021BDC70, func_021BDCB4, func_021BDEAC
 * address:  0x021BDA94
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
 *   d_021C3948 0x021C3948 data ov110 a1
 *   func_02035C08 0x02035C08 arm
 *   d_021C38F0 0x021C38F0 data a1
 *   d_021C395C 0x021C395C data a1
 *   func_02035C60 0x02035C60 arm
 *   func_02035D20 0x02035D20 arm
 *   func_02035D40 0x02035D40 arm
 *   func_02024158 0x02024158 thumb
 *   func_021BABE8 0x021BABE8 thumb ov110
 *   func_021BAC00 0x021BAC00 thumb ov110
 *   _u32_div_f 0x0209C2B0 arm
 *   func_021BDA84 0x021BDA84 thumb ov110
 *   func_021BF680 0x021BF680 thumb ov110
 *   func_020061E4 0x020061E4 thumb
 *   func_021BF82C 0x021BF82C thumb ov110
 *   func_021B9BEC 0x021B9BEC thumb ov110
 *   func_021BF4F8 0x021BF4F8 thumb ov110
 *   func_021BF53C 0x021BF53C thumb ov110
 *   func_021BF608 0x021BF608 thumb ov110
 *   func_021B9C74 0x021B9C74 thumb ov110
 *   func_021BD7A0 0x021BD7A0 thumb ov110
 *   func_021BE4C0 0x021BE4C0 thumb ov110
 *   func_021BD808 0x021BD808 thumb ov110
 *   func_021BD8D8 0x021BD8D8 thumb ov110
 *   func_021BE3B8 0x021BE3B8 thumb ov110
 */
#include "../../matched/include/Obj10282.h"
#include "../../matched/include/Obj00012.h"

struct Ctx;
typedef unsigned char u8;

typedef struct { u8 b[8]; } Box;

typedef unsigned int   u32;

typedef unsigned short u16;

typedef int (*Handler)(u8 *,void *);

extern int func_02035C08(const void *p);
extern int func_02035C60(void);
extern unsigned int func_02035D20(unsigned int *outA, unsigned int *outB);
extern unsigned int func_02035D40(struct Ctx *ctx, unsigned int a, unsigned int b);
extern u32 func_02024158(const u8 *p);
extern int func_021BABE8(u8 *p);
extern void func_021BAC00(u8 *p, u8 *b, u8 n);
extern int func_021BDA84(u8 *);
extern int func_021BF680(u8 *);
extern void func_020061E4(u32);
extern void func_021BF82C(u8 *);
extern void func_021B9BEC(u8 *,int);
extern void func_021BF4F8(u8 *,u32);
extern void func_021BF53C(u8 *,u32 *);
extern void func_021BF608(u8 *,u32 *);
extern int func_021B9C74(unsigned int a);
extern void func_021BD7A0(u8 *,Handler);
extern int func_021BE4C0(u8 *,unsigned *);
extern int func_021BD808(u8 *p, void *q);
extern int func_021BD8D8(u8 *,unsigned *);
extern int func_021BE3B8(u8 *,u32 *);
int func_021BDA94(u8 *unused);
int func_021BDAA4(u8 *p);
int func_021BDB50(u32 *p);
int func_021BDB98(u8 *p,u32 *q);
int func_021BDC70(u8 *p,unsigned *q);
int func_021BDCB4(u8 *p,u32 *q);
int func_021BDEAC(u8 *p,unsigned *q);
extern u8 d_021C3948[];
extern const Box d_021C38F0;
extern const Box d_021C395C;

/*
 * input: caller's incoming pointer in r0 is ignored; stub replaces it with the table.
 */
int func_021BDA94(u8 *unused)
{
    return func_02035C08(d_021C3948);
}

int func_021BDAA4(u8 *p) {
 int x,y;
 Box box=d_021C38F0;
 int i,count,result;
 if(!func_02035C60()) return -1;
 result=func_02035C08(&d_021C395C);
 if(result!=-1) {
  if(func_02024158((const u8 *)(((struct Obj10282 *)p)->f0))) { if((unsigned)(result-2)<=3) result=-1; return result; }
  return result;
 }
 count=func_021BABE8(((struct Obj10282 *)p)->f14);
 func_02035D20((unsigned int *)(&x),(unsigned int *)(&y));
 for(i=0;i<count;i++) { func_021BAC00(((struct Obj10282 *)p)->f14,(u8 *)(&box),i); if(func_02035D40((struct Ctx *)(&box),x,y)!=-1) return i+6; }
 return -1;
}

int func_021BDB50(u32 *p) {
 u32 x,y;
 int result;
 if(func_02024158((const u8 *)(*p))) return -1;
 if(!func_02035D20(&x,&y)) return -1;
 if(y>168) { result=x/24U-1; if(result>=0 && result<5) return result; }
 return -1;
}

/*
 * control-flow: inner hits 2/3 reach DC0A; outer states 2/3 preserve p for F4F8.
 * lever: preserve incoming r0 p at DA84/DA94 calls with their ignored pointer argument.
 */
int func_021BDB98(u8 *p,u32 *q)
{
    int hit;
    switch(*q) {
    case 0:
    case 1:
        if(((struct Obj00012 *)p)->f4==0) hit=func_021BDA84(p);
        else hit=func_021BDA94(p);
        switch(hit) {
        case 0:
            if(func_021BF680(p)) func_020061E4(1356);
            else func_020061E4(1367);
            *q=2;
            break;
        case 1:
            func_020061E4(1361);
            *q=3;
            break;
        case 2:
        case 3:
            func_020061E4(1356);
            func_021BF82C(p);
            ((struct Obj00012 *)p)->f4A=hit-2;
            func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,10);
            *q=5;
            break;
        }
        break;
    case 2: *q=4; func_021BF4F8(p,(u32)func_021BF53C); break;
    case 3: *q=4; func_021BF4F8(p,(u32)func_021BF608); break;
    case 4: *q=0; break;
    case 5:
        if(func_021B9C74((unsigned int)(*(u8 * *)&((struct Obj00012 *)p)->f14))) func_021BD7A0(p,(Handler)func_021BE4C0);
        break;
    }
    return 0;
}

int func_021BDC70(u8 *p,unsigned *q) {
 int result;
 if(*q<=1 && func_021BD808(p,q) && !((struct Obj00012 *)p)->f70) { func_020061E4(1352); return 0; }
 if(((struct Obj00012 *)p)->f70==0) { result=func_021BD8D8(p,q); }
 else { result=func_021BDB98(p,q); }
 return result;
}

/*
 * lever: The decoded table assigns the first callback arm to case 6 and the second to case 5.
 */
int func_021BDCB4(u8 *p,u32 *q)
{
    switch(*q) {
    case 0:
        if(func_021B9C74((unsigned int)(*(u8 * *)&((struct Obj00012 *)p)->f14))) {
            if(((struct Obj00012 *)p)->f34&64) {
                func_020061E4(1352);
                ((struct Obj00012 *)p)->f48=1;
                func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,7);
                *q=1;
            } else if(((struct Obj00012 *)p)->f34&136) {
                func_020061E4(1352);
                ((struct Obj00012 *)p)->f48=0;
                func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,7);
                *q=1;
            } else if(((struct Obj00012 *)p)->f34&32) {
                if(((struct Obj00012 *)p)->f4A!=0) {
                    func_020061E4(1352);
                    ((struct Obj00012 *)p)->f4A=0;
                    func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,16);
                }
            } else if(((struct Obj00012 *)p)->f34&16) {
                if(((struct Obj00012 *)p)->f4A==0) {
                    func_020061E4(1352);
                    ((struct Obj00012 *)p)->f4A=1;
                    func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,16);
                }
            } else if(((struct Obj00012 *)p)->f34&2) {
                func_020061E4(1361);
                func_021BF4F8(p,(u32)func_021BF608);
            } else if(((struct Obj00012 *)p)->f34&1) {
                func_020061E4(1356);
                func_021BF82C(p);
                func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,10);
                *q=5;
            }
        }
        break;
    case 1:
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
                if(((struct Obj00012 *)p)->f48==0) {
                    if(func_021BF680(p)) func_020061E4(1356);
                    else func_020061E4(1367);
                    *q=2;
                } else { func_020061E4(1361); *q=3; }
            } else if(((struct Obj00012 *)p)->f34&2) { func_020061E4(1361); *q=3; }
        }
        break;
    case 2: *q=4; func_021BF4F8(p,(u32)func_021BF53C); break;
    case 3: *q=4; func_021BF4F8(p,(u32)func_021BF608); break;
    case 4: *q=1; break;
    case 6: if(func_021B9C74((unsigned int)(*(u8 * *)&((struct Obj00012 *)p)->f14))) func_021BD7A0(p,(Handler)func_021BE3B8); break;
    case 5: if(func_021B9C74((unsigned int)(*(u8 * *)&((struct Obj00012 *)p)->f14))) func_021BD7A0(p,(Handler)func_021BE4C0); break;
    }
    return 0;
}

int func_021BDEAC(u8 *p,unsigned *q) {
 if(*q<=1 && func_021BD808(p,q) && !((struct Obj00012 *)p)->f70) { func_020061E4(1352); return 0; }
 if(((struct Obj00012 *)p)->f70==0) { return func_021BDCB4(p,q); }
 else { return func_021BDB98(p,q); }
}
