/*
 * function: func_02184FC8
 * address: 0x02184FC8
 * packet: pkt_ov219_02184FC8
 * region: ov219
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: 20CF8 legacy one parameter; original also visibly sets r1
 * to full-width heap, retained as a second input even though body ignores it.
 * symbols:
 *   func_0201DC80 0x0201DC80 thumb
 *   func_0201FF30 0x0201FF30 thumb
 *   func_02020CF8 0x02020CF8 thumb
 *   func_0201F73C 0x0201F73C thumb
 *   func_02045334 0x02045334 arm
 *   func_02184EAC 0x02184EAC thumb ov219
 */
#include "../include/Obj01013.h"
typedef unsigned short u16;
struct Src {unsigned w[13];};
struct Font;struct Obj;struct Descriptor;
extern unsigned func_0201DC80(struct Font *);
typedef unsigned int   u32;
extern struct Obj *func_0201FF30(struct Src *src, u16 a, u16 b, u32 heap);
extern void func_02020CF8(struct Obj *p, int heap);
extern void func_0201F73C(void *,int,int,int);
extern void func_02045334(struct Descriptor *),func_02184EAC(int,int,int);
void func_02184FC8(char *p,const struct Src *source,unsigned count)
{
    struct Src cfg;
    ((struct Obj01013 *)p)->fC078=((struct Obj01013 *)p)->fC018;p[0xc07c]=0;
    cfg=*source;
    cfg.w[0]=*(unsigned *)&((struct Obj01013 *)p)->fC050;
    *(u16 *)((char *)&cfg+16)=count;
    cfg.w[3]=*(unsigned *)&((struct Obj01013 *)p)->fC018;
    cfg.w[1]=(unsigned)func_02184EAC;
    *(u16 *)((char *)&cfg+32)=12;
    *(u16 *)((char *)&cfg+34)=func_0201DC80(*(struct Font * *)&((struct Obj01013 *)p)->fC06C);
    cfg.w[10]=(unsigned)(p+0xc078);
    cfg.w[11]=((struct Obj01013 *)p)->fC080;
    cfg.w[12]=*(unsigned *)&((struct Obj01013 *)p)->fC06C;
    *(struct Obj * *)&((struct Obj01013 *)p)->fC04C=func_0201FF30(&cfg,0,0,(u16)((struct Obj01013 *)p)->f0);
    func_02020CF8(*(struct Obj * *)&((struct Obj01013 *)p)->fC04C,((struct Obj01013 *)p)->f0);
    func_0201F73C(((struct Obj01013 *)p)->fC018,0,34,7);
    func_02045334(*(struct Descriptor * *)&((struct Obj01013 *)p)->fC018);
}
