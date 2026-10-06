/*
 * function: func_021DD810
 * address: 0x021DD810
 * packet: pkt_ov170_021DD810
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: the repeated third-argument truncations require a u16 extern parameter.
 * symbols:
 *   func_021DD25C 0x021DD25C thumb ov170
 *   func_021DD2D0 0x021DD2D0 thumb ov170
 *   func_021DD6E8 0x021DD6E8 thumb ov170
 *   func_021DD8A8 0x021DD8A8 thumb ov170
 *   func_021EC48C 0x021EC48C thumb ov170
 *   func_021DEFEC 0x021DEFEC thumb ov170
 */
#include "../include/Obj00000.h"
extern unsigned func_021DD25C(void ***,unsigned short,unsigned short,unsigned,unsigned);
extern int func_021DD2D0(void ***p, int a, unsigned b);
extern void func_021DD6E8(void **,void *,unsigned);
typedef unsigned int   u32;
extern void func_021DD8A8(void **pp, u32 idx);
extern void func_021EC48C(unsigned char *p, int box, int pos, int win);
extern void func_021DEFEC(char *p, int b);
void func_021DD810(unsigned char *p,unsigned a,unsigned b,unsigned box)
{
    if(a<30 && b<30) return;
    if(a>=30 && b>=30) return;
    if(a>=30) a=b;
    if(func_021DD25C((void ***)p,a,box,5,0)!=492) return;
    if(func_021DD25C((void ***)p,a,box,0x6f,0)==0) return;
    func_021DD6E8((void **)p,(void *)func_021DD2D0((void ***)p,box,a),0);
    func_021DD8A8((void **)p,a);
    if(box==p[0x14])
        func_021EC48C(p,box,a,*(unsigned char *)(*(char * *)&((struct Obj00000 *)p)->f2C+a+0x3dd2));
    if(p[0x16]==a) func_021DEFEC((char *)p,a);
}
