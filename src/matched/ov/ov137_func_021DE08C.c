/*
 * function: func_021DE08C
 * address: 0x021DE08C
 * packet: pkt_ov137_021DE08C
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DE5C0 0x021DE5C0 thumb ov137
 *   func_021DE4B4 0x021DE4B4 thumb ov137
 *   func_021DE55C 0x021DE55C thumb ov137
 *   func_021DCF50 0x021DCF50 thumb ov137
 *   func_02184180 0x02184180 thumb ov022
 *   func_0201FEF4 0x0201FEF4 thumb
 *   func_0201F02C 0x0201F02C thumb
 *   func_02039338 0x02039338 arm
 *   func_0201CE0C 0x0201CE0C thumb
 */
#include "../include/Obj01261.h"
#include "../include/Obj23728.h"
typedef unsigned char u8;
extern void func_021DE5C0(u8 *);
extern void func_021DE4B4(char *,int,int);
extern int func_021DE55C(char *);
extern void *func_021DCF50(void *);
typedef unsigned short u16;
typedef unsigned int   u32;
struct WordSet;
extern char *func_02184180(unsigned char *p, int i);
extern void func_0201FEF4(u8 *o);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern u16 func_02039338(void);
extern void func_0201CE0C(void *);
void func_021DE08C(char *p,int state,int player) {
    switch(state) {
    case 2:
        func_021DE5C0((u8 *)p);
        break;
    case 13:
        if (((struct Obj01261 *)p)->fE8) {
            func_0201FEF4(((struct Obj01261 *)p)->fE8);
            ((struct Obj01261 *)p)->fE8=0;
        }
        break;
    case 25:
        func_021DE4B4(p,12,0);
        if (((struct Obj01261 *)p)->fE8) {
            func_0201FEF4(((struct Obj01261 *)p)->fE8);
            ((struct Obj01261 *)p)->fE8=0;
        }
        break;
    case 19:
        if (((struct Obj01261 *)p)->f4810==1) return;
        func_0201F02C(((struct Obj01261 *)p)->f3C,0,func_02184180(func_021DCF50(p),player));
        if (player==func_02039338()) return;
        if (((struct Obj01261 *)p)->fE8) {
            func_0201FEF4(((struct Obj01261 *)p)->fE8);
            ((struct Obj01261 *)p)->fE8=0;
        }
        if (func_02039338()==0)
            ((struct Obj23728 *)(*(char * *)&((struct Obj01261 *)p)->f10))->f30&=player^0xffff;
        break;
    case 27:
        if (!func_021DE55C(p)) func_0201CE0C(((struct Obj01261 *)p)->fF0);
        if (((struct Obj01261 *)p)->fE8) {
            func_0201FEF4(((struct Obj01261 *)p)->fE8);
            ((struct Obj01261 *)p)->fE8=0;
        }
        break;
    case 7:
    case 8:
        break;
    default:
        return;
    }
    ((struct Obj01261 *)p)->f118=state;
}
