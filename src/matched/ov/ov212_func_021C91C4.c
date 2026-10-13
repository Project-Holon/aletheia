/*
 * function: func_021C91C4
 * address: 0x021C91C4
 * packet: pkt_ov212_021C91C4
 * region: ov212
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: 02031348 forwards all four original inputs to 020314F4;
 * the matched forwarding target reads each, overriding legacy void(void).
 * symbols:
 *   func_0200CA1C 0x0200CA1C thumb
 *   func_0200CA8C 0x0200CA8C thumb
 *   func_02030734 0x02030734 arm
 *   PROCSYS_Push 0x02031348 arm
 *   func_021C8F90 0x021C8F90 thumb ov212
 *   d_021C99A0 0x021C99A0 data a1
 *   d_021C8108 0x021C8108 data ov208 a4
 *   ov208_id 0x000000D0 data a1
 */
#include "../include/Obj04628.h"
#include "../include/Obj04629.h"
typedef unsigned short u16;
struct Blk37;struct Obj020314F4;
extern void *func_0200CA1C(void *);
extern u16 func_0200CA8C(struct Blk37 *);
extern void *func_02030734(unsigned,unsigned,int,const char *,u16);
extern void PROCSYS_Push(struct Obj020314F4 *,unsigned,unsigned,unsigned);
extern int func_021C8F90(char *,int);
extern const char d_021C99A0[];
extern const unsigned d_021C8108[];
extern unsigned char ov208_id[];
void func_021C91C4(char *p)
{
    char *q;
    u16 selected,i;
    selected=func_0200CA8C(func_0200CA1C(*(void **)*(char * *)&((struct Obj04628 *)p)->f0));
    q=func_02030734(105,20,0,d_021C99A0,530);
    ((struct Obj04629 *)q)->f0=**(unsigned * *)&((struct Obj04628 *)p)->f0;
    ((struct Obj04629 *)q)->f4=((struct Obj04628 *)p)->f24;
    ((struct Obj04629 *)q)->f8=((struct Obj04628 *)p)->fC;
    ((struct Obj04629 *)q)->fC=((struct Obj04628 *)p)->f10;
    ((struct Obj04629 *)q)->fE=0;
    for(i=0;i<((struct Obj04629 *)q)->fC;i++){
        if((*(u16 **)(q+8))[i]==selected){((struct Obj04629 *)q)->fE=i;break;}
    }
    PROCSYS_Push(*(struct Obj020314F4 * *)&((struct Obj04628 *)p)->f4,(unsigned)ov208_id,(unsigned)d_021C8108,(unsigned)q);
    ((struct Obj04628 *)p)->f28=q;
    func_021C8F90(p,6);
}
