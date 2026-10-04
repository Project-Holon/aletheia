/*
 * unit: yes
 * function: func_021DCD14,func_021DCD34,func_021DCD44,func_021DCD5C,func_021DCD6C,func_021DCD7C
 * address: 0x021DCD14
 * packet: pkt_ov137_021DCD14
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 * func_021DE17C 0x021DE17C thumb ov137
 * func_021E172C 0x021E172C thumb ov137
 * func_021E1758 0x021E1758 thumb ov137
 * func_021E168C 0x021E168C thumb ov137
 * func_02039338 0x02039338 arm
 */
#include "../include/Obj14206.h"
#include "../include/Obj23680.h"
#include "../include/Obj23682.h"
#include "../include/Obj23683.h"
#include "../include/Obj23684.h"
#include "../include/Obj23685.h"
#include "../include/Obj23687.h"
#include "../include/Obj23688.h"
#include "../include/Obj23690.h"
#include "../include/Obj23691.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_021DE17C(char *p, int command, int player);
extern u16 func_02039338(void);
extern void func_021E172C(void *,void *),func_021E1758(void *,int),func_021E168C(void *,int);
void func_021DCD14(int a,int b,u8 *c,u8 *p)
{
    func_021DE17C(((struct Obj23680 *)(*(u8 * *)&((struct Obj14206 *)p)->f0))->f20,1,*c);
    if(!func_02039338()) ((struct Obj14206 *)p)->f34=0;
}
void func_021DCD34(int a,int b,u16 *c,u8 *p) { ((struct Obj23682 *)p)->f40|=*c; }
void func_021DCD44(int a,int b,void *c,u8 *p) { ((struct Obj23683 *)p)->f42|=(u16)(1<<a); }
void func_021DCD5C(int a,int b,void *c,u8 *p) { func_021E172C(((struct Obj23685 *)(*(u8 * *)&((struct Obj23684 *)p)->f0))->f1C,c); }
void func_021DCD6C(int a,int b,int *c,u8 *p) { func_021E1758(((struct Obj23688 *)(*(u8 * *)&((struct Obj23687 *)p)->f0))->f1C,*c); }
void func_021DCD7C(int a,int b,u8 *c,u8 *p) { func_021E168C(((struct Obj23691 *)(*(u8 * *)&((struct Obj23690 *)p)->f0))->f1C,*c); }
