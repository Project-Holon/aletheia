/*
 * function: func_021DE3E8
 * address: 0x021DE3E8
 * packet: pkt_ov119_021DE3E8
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: 02035C08 return is consumed in r0; full 02035BBC forwarding body returns int, as in matched 021D98AC.
 * symbols:
 *   func_02040588 0x02040588 arm
 *   func_020221A4 0x020221A4 thumb
 *   func_021B63D0 0x021B63D0 thumb ov067
 *   func_021B6448 0x021B6448 thumb ov067
 *   func_021B6470 0x021B6470 thumb ov067
 *   func_0202208C 0x0202208C thumb
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DE2C4 0x021DE2C4 thumb ov119
 *   func_02035C08 0x02035C08 arm
 *   d_021E80C4 0x021E80C4 data a4
 *   func_020355D8 0x020355D8 arm
 *   func_021E68F4 0x021E68F4 thumb ov119
 *   func_021DE1B4 0x021DE1B4 thumb ov119
 *   func_020061E4 0x020061E4 thumb
 *   func_021DE3BC 0x021DE3BC thumb ov119
 *   func_020355C4 0x020355C4 arm
 *   func_020362DC 0x020362DC arm
 *   func_021DE208 0x021DE208 thumb ov119
 */
#include "../include/Obj00251.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct S S;
typedef struct { char pad[0xfd8]; int obj[2][3]; } State;
extern void func_02040588(u32 which, u32 enable);
extern unsigned func_020221A4(void);
extern void func_021B63D0(struct S *p);
extern int func_021B6448(u8 *),func_021B6470(u8 *);
extern void func_0202208C(void *,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned);
extern void func_021D8E84(void *,int);
extern void func_021DE2C4(char *);
extern void func_021DE3BC(char *p);
extern int func_02035C08(const void *);
extern const char d_021E80C4[];
extern void func_020355D8(u8);
extern void func_021E68F4(int,int);
extern void func_021DE1B4(State *,int);
extern void func_020061E4(u32 a);
extern u8 func_020355C4(void);
extern u32 func_020362DC(void);
extern int func_021DE208(char *);
static inline int poll(void) { int v=func_020362DC(); if(v)func_020355D8(0); return v; }
void func_021DE3E8(char *p)
{
    int idx;
    func_02040588(3,1);
    if(func_020221A4()) {
        func_021B63D0(*(S * *)&((struct Obj00251 *)p)->f9C0);
        if(func_021B6448(*(u8 * *)&((struct Obj00251 *)p)->f9C0)==1) {
            func_0202208C((void *)3,0,0,0,6,1,((struct Obj00251 *)p)->f5F4);
            func_021D8E84(p,(int)func_021DE2C4);
            return;
        }
        if(func_021B6470(*(u8 * *)&((struct Obj00251 *)p)->f9C0)==-1) {
            idx=func_02035C08(d_021E80C4);
            if(idx!=-1) {
                func_020355D8(1);
                ((struct Obj00251 *)p)->f10A0=idx;
                func_021E68F4((int)p,-1);
                func_021DE1B4((State *)p,((struct Obj00251 *)p)->f10A0);
                func_020061E4(0x548);
                ((struct Obj00251 *)p)->fF2C=0;
                func_021D8E84(p,(int)func_021DE3BC);
                return;
            }
            if(func_020355C4() && poll()) {
                func_020355D8(0);
                func_021E68F4((int)p,((struct Obj00251 *)p)->f10A0);
                func_020061E4(0x548);
                ((struct Obj00251 *)p)->fF2C=0;
                func_021D8E84(p,(int)func_021DE3BC);
                return;
            }
            if(func_021DE208(p)) {
                func_020061E4(0x548);
                func_021E68F4((int)p,((struct Obj00251 *)p)->f10A0);
                func_021DE1B4((State *)p,((struct Obj00251 *)p)->f10A0);
                ((struct Obj00251 *)p)->fF2C=0;
                func_021D8E84(p,(int)func_021DE3BC);
            }
        }
    }
}
