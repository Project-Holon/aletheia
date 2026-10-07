/*
 * file:     guru2_main_p03.c
 * unit:     yes
 * function: func_021DD924, func_021DD928, func_021DD93C, func_021DD94C, func_021DD970, func_021DD99C, func_021DD9D4, func_021DDAEC, func_021DDB04, func_021DDB90, func_021DDBB0, func_021DDBE8, func_021DDC7C, func_021DDCB4, func_021DDCEC
 * address:  0x021DD924
 * region:   ov137
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021DE55C 0x021DE55C thumb ov137
 *   func_02039338 0x02039338 arm
 *   func_021DCF50 0x021DCF50 thumb ov137
 *   func_02184134 0x02184134 thumb ov022
 *   func_0201FDA0 0x0201FDA0 thumb
 *   d_021E1AE8 0x021E1AE8 data a2
 *   func_021DE7F4 0x021DE7F4 thumb ov137
 *   func_020061E4 0x020061E4 thumb
 *   func_021DE354 0x021DE354 thumb ov137
 *   func_021841A4 0x021841A4 thumb ov022
 *   func_0201FEBC 0x0201FEBC thumb
 *   func_021DE4B4 0x021DE4B4 thumb ov137
 *   func_02082BCC 0x02082BCC arm
 *   func_021DCBC4 0x021DCBC4 thumb ov137
 *   func_0203D7BC 0x0203D7BC arm
 */
#include "../../matched/include/Obj23715.h"
#include "../../matched/include/Obj01414.h"
#include "../../matched/include/Obj14209.h"
#include "../../matched/include/Obj23716.h"
#include "../../matched/include/Obj14210.h"
#include "../../matched/include/Obj02867.h"
#include "../../matched/include/Obj23717.h"
#include "../../matched/include/Obj23718.h"
#include "../../matched/include/Obj23719.h"
#include "../../matched/include/Obj03303.h"
#include "../../matched/include/Obj23720.h"
#include "../../matched/include/Obj23721.h"
#include "../../matched/include/Obj23722.h"
#include "../../matched/include/Obj14211.h"
#include "../../matched/include/Obj05426.h"
#include "../../matched/include/Obj14212.h"
#include "../../matched/include/Obj10617.h"
#include "../../matched/include/Obj14213.h"
#include "../../matched/include/Obj23723.h"

struct BmpMenu;
typedef unsigned char u8;

typedef signed char s8;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned int u32;

typedef signed int s32;

typedef struct {u8 frame,x,y,pal;u16 chr;} WinDat;

extern int func_021DE55C(char *);
extern u16 func_02039338(void);
extern void *func_021DCF50(u8 *p);
extern void func_02184134(u8 *);
extern struct BmpMenu *func_0201FDA0(const WinDat *,u16,u8,u8,u16);
extern unsigned func_021DE7F4(void);
extern void func_020061E4(u32 a);
extern int func_021DE354(void *p);
extern int func_021841A4(unsigned char *p);
extern u32 func_0201FEBC(u8 *p);
extern void func_021DE4B4(char *,int,int);
extern void func_02082BCC(void *,int,unsigned);
extern int func_021DCBC4(void *,int,void *,int);
extern void func_0203D7BC(u8 a0);
void func_021DD924(char *p);
int func_021DD928(char *p,int state);
void func_021DD93C(char *p, int v);
int func_021DD94C(char *p,int state);
int func_021DD970(char *p,int state);
int func_021DD99C(char *p,int state);
int func_021DD9D4(char *p,int state);
int func_021DDAEC(char *p,int state);
int func_021DDB04(char *p, int state);
int func_021DDB90(char *p,int state);
int func_021DDBB0(char *p,int state);
int func_021DDBE8(char *p, int state);
int func_021DDC7C(char *p,int state);
int func_021DDCB4(char *p,int state);
int func_021DDCEC(char *p,int state);
extern const WinDat d_021E1AE8;

void func_021DD924(char *p) {}

/*
 * prototype: original r0 holds p at the call to func_021DD924; retain that
 * explicit input despite the pending empty callee's no-argument declaration.
 */
int func_021DD928(char *p,int state) {((struct Obj23715 *)p)->f118=2;func_021DD924(p);return state;}


void func_021DD93C(char *p, int v)
{
    ((struct Obj01414 *)p)->f118 = 0x1A;
    ((struct Obj01414 *)p)->f11C = v;
}

int func_021DD94C(char *p,int state) {if(func_021DE55C(p)) ((struct Obj14209 *)p)->f118=((struct Obj14209 *)p)->f11C;func_021DD924(p);return state;}

/*
 * extent: two zero alignment bytes follow the compiled function.
 * prototype: original r0 holds p at the call to func_021DD924; retain that
 * explicit input despite the pending empty callee's no-argument declaration.
 */
int func_021DD970(char *p,int state) {if(func_02039338()==0)func_02184134(func_021DCF50((u8 *)p));((struct Obj23716 *)p)->f118=3;func_021DD924(p);return state;}

int func_021DD99C(char *p,int state) {*(struct BmpMenu * *)&((struct Obj14210 *)p)->fE8=func_0201FDA0(&d_021E1AE8,31,11,0,114);((struct Obj14210 *)p)->f118=5;func_021DD924(p);return state;}

int func_021DD9D4(char *p,int state) {
    unsigned count;
    unsigned result;
    u8 msg[4];
    if (func_02039338()!=0) {
        if (((struct Obj23717 *)(*(char * *)&((struct Obj02867 *)p)->f10))->f28!=0) {
            if (func_021DE7F4()&0xc3) func_020061E4(0x548);
            func_021DD924(p);
            return state;
        }
    } else {
        if (((struct Obj23718 *)(*(char * *)&((struct Obj02867 *)p)->f10))->f30!=0) {
            if (func_021DE7F4()&0xc3) func_020061E4(0x548);
            func_021DD924(p);
            return state;
        }
    }
    count=func_021DE354(p);
    if (count!=func_021841A4(func_021DCF50((u8 *)p))) {
        func_021DD924(p);
        return state;
    }
    result=func_0201FEBC(((struct Obj02867 *)p)->fE8);
    if (result!=-1) {
        if (result==-2) {
            if (func_02039338()==0) func_02184134(func_021DCF50((u8 *)p));
            ((struct Obj02867 *)p)->f118=0;
        } else {
            if (func_02039338()==0) {
                func_021DD93C(p,11);
                func_021DE4B4(p,14,0);
            } else {
                func_02082BCC(msg,0,4);
                msg[2]=0;
                msg[0]=func_02039338();
                if (func_021DCBC4(((struct Obj02867 *)p)->f10,0x2801,msg,4)) {
                    ((struct Obj02867 *)p)->f4810=1;
                    ((struct Obj02867 *)p)->f4820=0;
                    ((struct Obj02867 *)p)->f118=6;
                } else ((struct Obj02867 *)p)->f118=0;
            }
        }
        ((struct Obj02867 *)p)->fE8=0;
    }
    func_021DD924(p);
    return state;
}

int func_021DDAEC(char *p,int state) {((struct Obj23719 *)p)->f4820=0;func_021DD924(p);return state;}

int func_021DDB04(char *p, int state) {
    unsigned char buf[4];
    if (((struct Obj23720 *)(*(char * *)&((struct Obj03303 *)p)->f10))->f38 != func_021841A4(func_021DCF50((u8 *)p)) ||
        ((struct Obj23721 *)(*(char * *)&((struct Obj03303 *)p)->f10))->f38 != func_021DE354(p)) {
        ((struct Obj03303 *)p)->f4820 = 0;
        ((struct Obj03303 *)p)->f118 = 8;
        func_021DD924(p);
        return state;
    }
    ++*(volatile s16 *)&((struct Obj03303 *)p)->f4820;
    if (*(volatile s16 *)&((struct Obj03303 *)p)->f4820 > 30) {
        int zero = 0;
        func_02082BCC(buf, 0, 4);
        buf[2] = 1;
        buf[0] = func_02039338();
        func_021DCBC4(((struct Obj03303 *)p)->f10, 0x2801, buf, 4);
        ((struct Obj03303 *)p)->f4820 = zero;
        ((struct Obj03303 *)p)->f118 = 9;
    }
    func_021DD924(p);
    return state;
}

int func_021DDB90(char *p,int state) {((struct Obj23722 *)p)->f4810=0;func_021DD93C(p,0);func_021DD924(p);return state;}

int func_021DDBB0(char *p,int state) {*(struct BmpMenu * *)&((struct Obj14211 *)p)->fE8=func_0201FDA0(&d_021E1AE8,31,11,0,114);((struct Obj14211 *)p)->f118=23;func_021DD924(p);return state;}

int func_021DDBE8(char *p, int state) {
    char *q = *(char * *)&((struct Obj05426 *)p)->f10;
    unsigned result;
    if (((struct Obj14212 *)q)->f2C != func_021DE354(p) || ((struct Obj14212 *)q)->f30 != 0) {
        if (func_021DE7F4() & 0xc3) func_020061E4(0x548);
        func_021DD924(p);
        return state;
    }
    result = func_0201FEBC(((struct Obj05426 *)p)->fE8);
    if (result != -1) {
        if (result == -2) {
            func_02184134(func_021DCF50((u8 *)p));
            ((struct Obj05426 *)p)->f118 = 0;
        } else {
            if (func_02039338() == 0) {
                ((struct Obj05426 *)p)->f118 = 0x18;
                ((struct Obj05426 *)p)->f4812 = func_021DE354(p);
            }
        }
        ((struct Obj05426 *)p)->fE8 = 0;
    }
    func_021DD924(p);
    return state;
}

/*
 * prototype: original cmp r0,#1 at 021DDC96 uses func_021DCBC4's return;
 * retain int return despite the pending void tail-forwarder. Original 021DDCA2
 * supplies r0=1 to func_0203D7BC despite its filed no-argument prototype.
 */
int func_021DDC7C(char *p,int state) {if(((struct Obj10617 *)p)->f4813==0) {if(func_021DCBC4(((struct Obj10617 *)p)->f10,0x2804,0,0)==1) {((struct Obj10617 *)p)->f118=27;func_0203D7BC(1);}}return state;}

/*
 * extent: two zero alignment bytes follow the compiled function.
 */
int func_021DDCB4(char *p,int state) {if(func_02039338()==0)func_021841A4(func_021DCF50((u8 *)p));if(((struct Obj23723 *)(*(char * *)&((struct Obj14213 *)p)->f10))->f20==func_021841A4(func_021DCF50((u8 *)p))) ((struct Obj14213 *)p)->f118=27;return state;}

int func_021DDCEC(char *p,int state) {func_021DE4B4(p,5,0);func_021DD93C(p,10);func_021DD924(p);return state;}
