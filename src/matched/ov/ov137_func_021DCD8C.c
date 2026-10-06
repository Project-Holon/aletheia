/*
 * unit: yes
 * function: func_021DCD8C,func_021DCDA0,func_021DCDB0,func_021DCDC0,func_021DCDD8,func_021DCDF0
 * address: 0x021DCD8C
 * packet: pkt_ov137_021DCD8C
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 * func_021E1694 0x021E1694 thumb ov137
 * func_021E180C 0x021E180C thumb ov137
 * func_021E1814 0x021E1814 thumb ov137
 */
#include "../include/Obj23692.h"
#include "../include/Obj23693.h"
#include "../include/Obj23695.h"
#include "../include/Obj23696.h"
#include "../include/Obj23697.h"
#include "../include/Obj23698.h"
#include "../include/Obj23699.h"
#include "../include/Obj23700.h"
#include "../include/Obj23701.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_021E1694(void *,void *);
extern void func_021E1814(unsigned char *p, u16 *q);
extern void func_021E180C(int *p, int a, int b);
void func_021DCD8C(int a,int b,void *c,u8 *p) { if(a==0) func_021E1694(((struct Obj23693 *)(*(u8 * *)&((struct Obj23692 *)p)->f0))->f1C,c); }
void func_021DCDA0(int a,int b,int *c,u8 *p) { func_021E180C(((struct Obj23696 *)(*(u8 * *)&((struct Obj23695 *)p)->f0))->f1C,a,*c); }
void func_021DCDB0(int a,int b,void *c,u8 *p) { func_021E1814(((struct Obj23698 *)(*(u8 * *)&((struct Obj23697 *)p)->f0))->f1C,c); }
void func_021DCDC0(int a,int b,void *c,u8 *p) { ((struct Obj23699 *)p)->f48|=(u16)(1<<a); }
void func_021DCDD8(int a,int b,void *c,u8 *p) { ((struct Obj23700 *)p)->f4A|=(u16)(1<<a); }
void *func_021DCDF0(int a,u8 *p) { return *(u8 * *)&((struct Obj23701 *)p)->f4C+a*0x594; }
