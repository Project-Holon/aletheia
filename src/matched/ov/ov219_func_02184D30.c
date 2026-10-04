/*
 * function: func_02184D30
 * address: 0x02184D30
 * packet: pkt_ov219_02184D30
 * region: ov219
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_0201C6FC 0x0201C6FC thumb
 */
#include "../include/Obj02934.h"
typedef unsigned char u8;
struct Descriptor;struct PrintSys;
struct Record {struct Descriptor *descriptor;u8 active;};
extern void *func_02045770(struct Descriptor *);
extern void func_0201C6FC(struct PrintSys *,unsigned,unsigned,unsigned,void *,unsigned);
void func_02184D30(char *p,struct Record *out,struct Descriptor *d,void *text,u8 x,u8 y)
{
    struct PrintSys *print;
    out->descriptor=d;out->active=0;
    print=*(struct PrintSys * *)&((struct Obj02934 *)p)->fC080;
    func_0201C6FC(print,(unsigned)func_02045770(d),x,y,text,((struct Obj02934 *)p)->fC06C);
    out->active=1;
}
