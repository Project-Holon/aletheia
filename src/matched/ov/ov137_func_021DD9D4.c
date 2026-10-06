/*
 * function: func_021DD9D4
 * address: 0x021DD9D4
 * packet: pkt_ov137_021DD9D4
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02039338 0x02039338 arm
 *   func_021DE7F4 0x021DE7F4 thumb ov137
 *   func_020061E4 0x020061E4 thumb
 *   func_021DD924 0x021DD924 thumb ov137
 *   func_021DE354 0x021DE354 thumb ov137
 *   func_021DCF50 0x021DCF50 thumb ov137
 *   func_021841A4 0x021841A4 thumb ov022
 *   func_0201FEBC 0x0201FEBC thumb
 *   func_02184134 0x02184134 thumb ov022
 *   func_021DD93C 0x021DD93C thumb ov137
 *   func_021DE4B4 0x021DE4B4 thumb ov137
 *   func_02082BCC 0x02082BCC arm
 *   func_021DCBC4 0x021DCBC4 thumb ov137
 */
#include "../include/Obj02867.h"
#include "../include/Obj23717.h"
#include "../include/Obj23718.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern u16 func_02039338(void);
extern unsigned func_021DE7F4(void);
extern void func_020061E4(u32 a);
extern void func_021DD924(char *);
extern int func_021DE354(void *p);
extern void *func_021DCF50(u8 *p);
extern int func_021841A4(unsigned char *p);
extern u32 func_0201FEBC(u8 *p);
extern void func_02184134(u8 *p);
extern void func_021DD93C(char *,int);
extern void func_021DE4B4(char *,int,int);
extern void func_02082BCC(void *,int,unsigned);
extern int func_021DCBC4(void *,int,void *,int);
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
