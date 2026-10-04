/*
 * function: func_021DAEF0
 * address: 0x021DAEF0
 * packet: pkt_ov121_021DAEF0
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * volatile: index field reread at 021DAF26 and 021DAF30 with no intervening store.
 * symbols:
 *   func_021DA898 0x021DA898 thumb ov121
 *   func_021DD240 0x021DD240 thumb ov121
 *   func_021DDF84 0x021DDF84 thumb ov121
 *   func_021DBF04 0x021DBF04 thumb ov121
 *   func_021DE0AC 0x021DE0AC thumb ov121
 *   func_021DE0DC 0x021DE0DC thumb ov121
 *   func_021DCFA4 0x021DCFA4 thumb ov121
 */
#include "../include/Obj01153.h"
typedef unsigned short u16;
typedef struct Item { char raw[0xdc]; } Item;
typedef struct Obj { char pad[0x28]; Item items[12]; char tail[0xacc-0x28-12*0xdc]; volatile int index; } Obj;
extern void func_021DA898(char *);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern int func_021DD240(void **p);
extern void func_021DDF84(char *);
extern int func_021DBF04(void *);
extern void func_021DE0AC(u8 *p, u32 b);
extern void func_021DE0DC(char *p);
extern void func_021DCFA4(char *,int,int,u16);
void func_021DAEF0(Obj *obj)
{
    char *p=(char *)obj;
    int flag;
    u16 old;
    int angle;
    func_021DA898(*(char * *)&((struct Obj01153 *)p)->fAC4);
    func_021DD240(((struct Obj01153 *)p)->fAB0);
    if(((struct Obj01153 *)p)->fA78) {
        flag=0;
        if(*(char * *)&((struct Obj01153 *)p)->fAAC) {
            func_021DDF84(*(char * *)&((struct Obj01153 *)p)->fAAC);
            *(char * *)&((struct Obj01153 *)p)->fAAC=0;
        }
        if(obj->index<4 && func_021DBF04(&obj->items[obj->index+((struct Obj01153 *)p)->fAC8*4])) {
            flag=1;
            func_021DE0AC(*(void **)(p+0xa7c+(((struct Obj01153 *)p)->fACC+((struct Obj01153 *)p)->fAC8*4)*4),1);
        }
        if(flag==0) func_021DE0DC(((struct Obj01153 *)p)->fAB0);
        ((struct Obj01153 *)p)->fA78=0;
    }
    old=((struct Obj01153 *)p)->fBAC;
    angle=old+0x400;
    if(angle>=0x10000)
        ((struct Obj01153 *)p)->fBAC=old-0xfc00;
    else
        ((struct Obj01153 *)p)->fBAC=angle;
    func_021DCFA4(p+0xbae,14,0,((struct Obj01153 *)p)->fBAC);
    func_021DCFA4(p+0xc0e,14,2,((struct Obj01153 *)p)->fBAC);
}
