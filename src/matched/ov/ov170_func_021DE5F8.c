/*
 * function: func_021DE5F8
 * address: 0x021DE5F8
 * packet: pkt_ov170_021DE5F8
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: slot=a; slot=a-30; preserves the two stores to its stack home.
 * note 2026-10-05 (wave D9r lane 131): removed the dead first assignment
 * (`slot=a;` before `slot=a-30;`). Game code has no line table, so these
 * were stand-ins. The plain single assignment gives EXACT in --lang c99 and
 * --lang c: the output bytes do not change. Older text in this header that
 * asks for the double assignment is superseded.
 *
 * symbols:
 *   func_021DDEFC 0x021DDEFC thumb ov170
 */
#include "../include/Obj00000.h"
#include "../include/Obj23847.h"
typedef struct {
    unsigned short idx,slot,f4,f6;
    int vx,vy;
    short dx,dy,x,y;
} Obj;
extern void func_021DDEFC(unsigned char *,Obj *);
void func_021DE5F8(unsigned char *p,unsigned a)
{
    Obj *o;
    unsigned i;
    unsigned slot;
    o=*(Obj * *)&((struct Obj23847 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f60;
    slot=a-30;
    for(i=0;i<6;i++){
        o[i].idx=i+30;
        o[i].slot=i+30;
        o[i].f4=i+30;
        o[i].f6=0;
    }
    o[i].f6=0;
    for(i=slot+1;i<6;i++){
        o[i].slot=i+29;
        o[i].f6=1;
        func_021DDEFC(p,&o[i]);
    }
    o[slot].slot=35;
    o[slot].f6=1;
    func_021DDEFC(p,&o[slot]);
}
