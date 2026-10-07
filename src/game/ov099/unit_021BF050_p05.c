/*
 * file:     unit_021BF050_p05.c
 * unit:     yes
 * function: func_021C0140, func_021C017C, func_021C01A0, func_021C01CC, func_021C0254
 * address:  0x021C0140
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020362DC 0x020362DC arm
 *   func_021BAAB8 0x021BAAB8 thumb ov099
 *   func_021B9B64  0x021B9B64  thumb  ov099
 *   func_021BA928  0x021BA928  thumb  ov099
 *   func_021BA828  0x021BA828  thumb  ov099
 *   func_021BA858 0x021BA858 thumb ov099
 *   func_02156B8C 0x02156B8C thumb ov009
 *   func_0201FEF4 0x0201FEF4 thumb
 *   func_021C18C8 0x021C18C8 thumb ov099
 *   func_0203C554 0x0203C554 arm
 *   func_021BDD0C 0x021BDD0C thumb ov099
 *   func_021C2408 0x021C2408 thumb ov099
 *   func_021BAADC 0x021BAADC thumb ov099
 *   func_021BAD50  0x021BAD50  thumb  ov099
 */
#include "../../matched/include/Obj07959.h"
#include "../../matched/include/Obj18264.h"
#include "../../matched/include/Obj00008.h"
#include "../../matched/include/Obj18265.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned long  u32_021C017C;

typedef signed char    s8;

typedef signed short   s16;

typedef signed long    s32;

typedef int BOOL;

typedef unsigned long  u32_021C01A0;

typedef unsigned int   u32_021C01CC;

typedef unsigned long  u32_021C0254;

extern unsigned int func_020362DC(void);
extern void func_021BAAB8(char *,int,int);
extern void func_021B9B64(char *p);
extern int func_021BA928(void *p);
extern void func_021BA828(char *p);
extern u32_021C01CC func_021BA858(char *p);
extern int func_02156B8C(void);
extern void func_0201FEF4(u8 *o);
extern void func_021C18C8(char *p, int kind, int value);
extern void func_0203C554(u32_021C01CC a);
extern void func_021BDD0C(void *p, int on);
extern void func_021C2408(char *);
extern void func_021BAADC(char *,int,int);
extern void func_021BAD50(int a);
int func_021C0140(char *p,int ret);
int func_021C017C(char *p, int v);
int func_021C01A0(char *p, int v);
int func_021C01CC(char *p,int ret);
int func_021C0254(char *p, int v);

int func_021C0140(char *p,int ret) {
 if (((struct Obj07959 *)p)->f1E0>0) { --((struct Obj07959 *)p)->f1E0; return ret; }
 if (func_020362DC()&3) {
  func_021BAAB8(p,26,1);
  ((struct Obj07959 *)p)->f1CC=51;
  ((struct Obj07959 *)p)->f1E0=1;
 }
 return ret;
}


int func_021C017C(char *p, int v)
{
    func_021B9B64(p + 0x274);
    func_021BAAB8(p, 7, 0);
    ((struct Obj18264 *)p)->f1CC = 0x20;
    return v;
}


/*
 * Re-arms the block 0x274 bytes in, then runs the setup and stamps selector
 * 0x21 when the guard answers true; returns the selector.
 */
int func_021C01A0(char *p, int v)
{
    func_021B9B64(p + 0x274);

    if (func_021BA928(p) != 0) {
        func_021BA828(p);
        *(u32_021C01A0 *)&((struct Obj00008 *)p)->f1CC = 0x21;
    }

    return v;
}

int func_021C01CC(char *p,int ret) {
    int r=func_021BA858(p);
    func_021B9B64(p+0x274);
    if(((struct Obj00008 *)p)->f1F0==-1 && func_02156B8C()!=-1){
        if(r==-1){func_0201FEF4((u8 *)(*(int *)&((struct Obj00008 *)p)->f108)); *(int *)&((struct Obj00008 *)p)->f108=0;}
        r=1;
    }
    if(r==-1)return ret;
    if(r==0){
        func_021C18C8(p,1,2);
        func_0203C554(1);
        func_021BDD0C(p,0);
        func_021C2408(p);
        ((struct Obj00008 *)p)->f1CC=11;
    }else {
        func_021BAADC(p,6,0);
        ((struct Obj00008 *)p)->f1CC=158;
    }
    return ret;
}


/*
 * Runs the setup, stamps selector 0x83 and re-arms the block 0x274 bytes in.
 */
int func_021C0254(char *p, int v)
{
    func_021BAD50((int)p);
    ((struct Obj18265 *)p)->f1CC = 0x83;
    func_021B9B64(p + 0x274);
    return v;
}
