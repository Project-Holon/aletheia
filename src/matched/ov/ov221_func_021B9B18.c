/*
 * unit: yes
 * function: func_021B9B18, func_021B9B64
 * address: 0x021B9B18
 * packet: pkt_ov221_021B9B18
 * region: ov221
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj02558.h"
#include "../include/Obj08453.h"
struct Descriptor; struct Cfg; struct PrintSys;
extern void *func_02045770(struct Descriptor *);
extern unsigned func_0201C6C4(struct PrintSys *,void *);
extern void func_02045334(struct Descriptor *);
extern void func_02045374(struct Cfg *);
extern unsigned char func_02045730(struct Descriptor *);
extern void func_02041B6C(unsigned);
void func_021B9B18(unsigned char *p)
{
    unsigned char i;
    unsigned char *row;
    struct Descriptor *resource;
    for(i=0;i<5;i++) {
        row=p+4*i;
        if(((struct Obj08453 *)row)->f30==0 && func_0201C6C4(*(struct PrintSys * *)&((struct Obj02558 *)p)->f10,func_02045770(*(struct Descriptor * *)&((struct Obj08453 *)row)->f1C))==0) {
            resource=*(struct Descriptor * *)&((struct Obj08453 *)row)->f1C;
            func_02045334(resource);
            func_02045374((struct Cfg *)resource);
            func_02041B6C(func_02045730(resource));
            ((struct Obj08453 *)row)->f30=1;
        }
    }
}
int func_021B9B64(unsigned char *p)
{
    unsigned char i;
    for(i=0;i<5;i++) if(*(int *)(p+0x30+4*i)==0) return 0;
    return 1;
}
