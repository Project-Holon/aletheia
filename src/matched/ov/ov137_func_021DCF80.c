/*
 * function: func_021DCF80
 * address: 0x021DCF80
 * packet: pkt_ov137_021DCF80
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Table callbacks receive the switch value as their second argument.
 * symbols:
 * func_02039338 0x02039338 arm
 * func_021DCF50 0x021DCF50 thumb ov137
 * func_021841A0 0x021841A0 thumb ov022
 * func_02184134 0x02184134 thumb ov022
 * func_021840FC 0x021840FC thumb ov022
 * func_02184174 0x02184174 thumb ov022
 * func_0218417C 0x0218417C thumb ov022
 * func_021DCF58 0x021DCF58 thumb ov137
 * func_021DCF7C 0x021DCF7C thumb ov137
 * func_021DE248 0x021DE248 thumb ov137
 * func_021DE5D0 0x021DE5D0 thumb ov137
 * func_021DE738 0x021DE738 thumb ov137
 * func_021DD1B4 0x021DD1B4 thumb ov137
 * func_0203A5E4 0x0203A5E4 arm
 * func_0204A600 0x0204A600 arm
 * func_020221A4 0x020221A4 thumb
 * func_0200FB24 0x0200FB24 thumb
 * d_021E1C20 0x021E1C20 data a4
 */
#include "../include/Obj00170.h"
#include "../include/Obj23706.h"
#include "../include/Obj23707.h"
#include "../include/Obj23708.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef void (*Cb)(void);
extern u16 func_02039338(void);
extern int func_020221A4(void);
extern int func_0200FB24(void);
extern void *func_021DCF50(u8 *p);
extern unsigned char func_021841A0(unsigned char *p);
extern void func_02184134(void *),func_02184174(void *);
extern u32 func_0218417C(u8 *);
extern void func_021840FC(u8 *,Cb,Cb,void *);
extern void func_021DCF58(int a, int b, u8 *p);
extern void func_021DCF7C(void);
extern int (*const d_021E1C20[])(u8 *,u32);
extern int func_021DE248(void *,int,u16,void *);
extern void func_021DE5D0(void *);
extern int func_021DE738(void *,int);
extern void func_021DD1B4(u8 *);
extern void func_0203A5E4(unsigned),func_0204A600(void);
int func_021DCF80(int a,int b,int c,u8 *p)
{
    int v;
    if(func_02039338()==0 && ((struct Obj23706 *)(*(u8 * *)&((struct Obj00170 *)p)->f10))->f30!=0)
        ((struct Obj23707 *)(*(u8 * *)&((struct Obj00170 *)p)->f10))->f30&=func_021841A0(func_021DCF50(p));
    switch(((struct Obj00170 *)p)->f0) {
    case 0:
        if(func_020221A4()) {
            ((struct Obj00170 *)p)->f0=1;
            func_02184134(func_021DCF50(p));
            func_021840FC(func_021DCF50(p),(Cb)func_021DCF58,func_021DCF7C,p);
        }
        break;
    case 1:
        if(d_021E1C20[((struct Obj00170 *)p)->f118]) ((struct Obj00170 *)p)->f0=d_021E1C20[*(u32 *)(p+280)](p,((struct Obj00170 *)p)->f0);
        if(((struct Obj23708 *)(*(u8 * *)&((struct Obj00170 *)p)->f10))->f24==0) func_021DE248(((struct Obj00170 *)p)->fD0,0,1152,p);
        func_021DE5D0(p);
        if(func_02039338()==0) {
            v=func_021DE738(p,1);
            if(((struct Obj00170 *)p)->f0==1) ((struct Obj00170 *)p)->f0=v;
        }
        break;
    case 2:
        if(d_021E1C20[((struct Obj00170 *)p)->f118]) ((struct Obj00170 *)p)->f0=d_021E1C20[*(u32 *)(p+280)](p,((struct Obj00170 *)p)->f0);
        break;
    case 3:
        if(func_020221A4()) {
            if(((struct Obj00170 *)p)->f8) return 1;
            func_0203A5E4(10240);
            func_02184174(func_021DCF50(p));
            ((struct Obj00170 *)p)->f0=4;
        }
        break;
    case 4:
        if(func_0218417C(func_021DCF50(p))) return 1;
        break;
    }
    if(func_020221A4() && func_0200FB24()) return 1;
    func_0204A600(); func_021DD1B4(p);
    return 0;
}
