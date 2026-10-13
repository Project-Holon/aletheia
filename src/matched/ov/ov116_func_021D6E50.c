/*
 * function: func_021D6E50
 * address: 0x021D6E50
 * packet: pkt_ov116_021D6E50
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B9800 0x021B9800 thumb ov114
 *   DWC_RAP_SetErrorCallback 0x02156DC4 thumb ov009
 *   func_021B98A0 0x021B98A0 thumb ov114
 *   func_021B98D8 0x021B98D8 thumb ov114
 *   func_021B98F8 0x021B98F8 thumb ov114
 *   func_021B9748 0x021B9748 thumb ov114
 *   func_021D7258 0x021D7258 thumb ov116
 *   func_021D6E3C 0x021D6E3C thumb ov116
 */
#include "../include/Obj04470.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct Sub0200852CObj;
extern u32 func_0200853C(const struct Sub0200852CObj *obj);
extern u8 *func_021B9800(int,int,int);
extern void DWC_RAP_SetErrorCallback(int a0, int a1);
extern void func_021B98A0(u8 *,int,int,int);
extern void func_021B98D8(u8 *p, int a, int n);
extern int func_021B98F8(u8 *p);
extern int func_021B9748(u8 *);
extern void func_021D7258(u8 *);
extern void func_021D6E3C(unsigned char *a);
void func_021D6E50(u8 *p,u8 *q,int a,int b) {
    *(u8 * *)&((struct Obj04470 *)p)->f168=func_021B9800(b,func_0200853C(((struct Obj04470 *)p)->f218),a);
    DWC_RAP_SetErrorCallback((int)func_021D6E3C,(int)p);
    func_021B98A0(*(u8 * *)&((struct Obj04470 *)p)->f168,b,180,4);
    func_021B98D8(*(u8 * *)&((struct Obj04470 *)p)->f168,(int)(p+0x70),180);
    ((struct Obj04470 *)p)->f16C=3;
    func_021B98F8(*(u8 * *)&((struct Obj04470 *)p)->f168);
    func_021B9748(*(u8 * *)&((struct Obj04470 *)p)->f168);
    func_021D7258(q);
}
