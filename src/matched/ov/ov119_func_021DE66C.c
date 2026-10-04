/*
 * function: func_021DE66C
 * address: 0x021DE66C
 * packet: pkt_ov119_021DE66C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021E770C 0x021E770C data a4
 *   func_021E1410 0x021E1410 thumb ov119
 *   func_021B6558 0x021B6558 thumb ov067
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DE5C4 0x021DE5C4 thumb ov119
 */
#include "../include/Obj22744.h"
typedef struct { int a,b,c; } Triple;
extern const Triple d_021E770C;
extern void func_021E1410(void *,Triple *,int);
extern void func_021B6558(unsigned char *p, unsigned int id, unsigned int v);
extern void func_021D8E84(void *,int);
extern void func_021DE5C4(char *p);
void func_021DE66C(char *p)
{
    Triple t=d_021E770C;
    func_021E1410(p,&t,3);
    func_021B6558((unsigned char *)(((struct Obj22744 *)p)->f9C0),1,0);
    func_021D8E84(p,(int)func_021DE5C4);
}
