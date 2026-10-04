/*
 * function: func_02185580
 * address: 0x02185580
 * packet: pkt_ov219_02185580
 * region: ov219
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02046DB8 0x02046DB8 arm
 *   func_02046FF8 0x02046FF8 arm
 *   func_02047400 0x02047400 arm
 *   func_0204767C 0x0204767C arm
 *   func_02185728 0x02185728 thumb ov219
 *   func_02185824 0x02185824 thumb ov219
 *   d_02185E18 0x02185E18 data a2
 */
#include "../include/Obj04645.h"
#include "../include/Obj04646.h"
typedef unsigned short u16;
typedef struct {u16 index,member;} Entry;
extern const Entry d_02185E18[];
extern void *func_02046DB8(unsigned,unsigned),*func_02047400(void *,unsigned,void *),*func_0204767C(unsigned,unsigned *,int);
extern int func_02046FF8(int *);
extern void func_02185728(void *),func_02185824(void *);
void func_02185580(char *p)
{
    unsigned i;
    char *row;
    ((struct Obj04645 *)p)->fC374=func_02046DB8(197,0);
    func_02046FF8(*(int * *)&((struct Obj04645 *)p)->fC374);
    ((struct Obj04645 *)p)->fC38C=func_02047400(((struct Obj04645 *)p)->fC374,0,((struct Obj04645 *)p)->fC374);
    ((struct Obj04645 *)p)->fC3A4=func_0204767C(*(unsigned *)&((struct Obj04645 *)p)->fC38C,0,0);
    for(i=0;i<4;i++) {
        row=p+d_02185E18[i].index*4;
        ((struct Obj04646 *)row)->fC378=func_02046DB8(197,d_02185E18[i].member);
        func_02046FF8(*(int * *)&((struct Obj04646 *)row)->fC378);
        ((struct Obj04646 *)row)->fC390=func_02047400(((struct Obj04646 *)row)->fC378,0,((struct Obj04646 *)row)->fC378);
        ((struct Obj04646 *)row)->fC3A8=func_0204767C(*(unsigned *)&((struct Obj04646 *)row)->fC390,0,0);
    }
    func_02185728(p);
    func_02185824(p);
}
