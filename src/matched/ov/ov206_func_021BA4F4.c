/*
 * unit: yes
 * function: func_021BA4F4,func_021BA514,func_021BA51C,func_021BA524,func_021BA534,func_021BA544
 * address: 0x021BA4F4
 * packet: pkt_ov206_021BA4F4
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BAF50 0x021BAF50 thumb ov206
 *   func_021BBBD8 0x021BBBD8 thumb ov206
 *   func_021BB92C 0x021BB92C thumb ov206
 */
#include "../include/Obj14635.h"
#include "../include/Obj14636.h"
#include "../include/Obj25395.h"
#include "../include/Obj25396.h"
#include "../include/Obj25397.h"
#include "../include/Obj25398.h"
extern void func_021BAF50(char *p);
extern void func_021BBBD8(void *,int);
extern void func_021BB92C(char *p, int index);
void func_021BA4F4(char *p)
{
    func_021BAF50(p);
    func_021BBBD8(p,((struct Obj14635 *)p)->f190);
    func_021BB92C(p,((struct Obj14635 *)p)->fE0);
}
void func_021BA514(char *p)
{
    ((struct Obj25395 *)p)->f58=1;
}
void func_021BA51C(char *p)
{
    ((struct Obj25396 *)p)->f5C=1;
}
int func_021BA524(char *p)
{
    int result=0;
    if(((struct Obj25397 *)p)->f54==4) result=1;
    return result;
}
int func_021BA534(char *p)
{
    int result=0;
    if(((struct Obj25398 *)p)->f54==6) result=1;
    return result;
}
void func_021BA544(char *p)
{
    if(((struct Obj14636 *)p)->f54==0) ((struct Obj14636 *)p)->f54=1;
}
