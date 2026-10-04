/*
 * function: func_021C9024
 * address: 0x021C9024
 * packet: pkt_ov212_021C9024
 * region: ov212
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: 02031348 legacy void(void) forwards r0-r3 to 020314F4,
 * whose matched body reads all four; this caller sets all four.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02031348 0x02031348 arm
 *   func_021C9348 0x021C9348 thumb ov212
 *   func_021C8F90 0x021C8F90 thumb ov212
 *   d_021C99A0 0x021C99A0 data a1
 *   d_021BE794 0x021BE794 data ov209 a4
 *   ov209_id 0x000000D1 data a1
 */
#include "../include/Obj02259.h"
#include "../include/Obj04626.h"
#include "../include/Obj25658.h"
#include "../include/Obj25659.h"
typedef unsigned short u16;
struct Obj020314F4;struct Blk37;
extern void *func_02030734(unsigned,unsigned,int,const char *,u16);
extern void func_02031348(struct Obj020314F4 *,unsigned,unsigned,unsigned);
extern int func_021C9348(struct Blk37 *);
extern int func_021C8F90(char *,int);
extern const char d_021C99A0[];
extern const unsigned d_021BE794[];
extern unsigned char ov209_id[];
void func_021C9024(char *p)
{
    char *q=func_02030734(105,20,0,d_021C99A0,359);
    ((struct Obj02259 *)p)->f28=q;
    ((struct Obj04626 *)q)->f0=**(unsigned * *)&((struct Obj02259 *)p)->f0;
    ((struct Obj04626 *)q)->f4=((struct Obj25658 *)(*(char * *)&((struct Obj02259 *)p)->f0))->f4;
    ((struct Obj04626 *)q)->f8=((struct Obj02259 *)p)->f12;
    if(((struct Obj02259 *)p)->f12==0&&func_021C9348(*(struct Blk37 * *)&((struct Obj25659 *)(*(char * *)&((struct Obj02259 *)p)->f0))->f4)==0){
        *(u16 * *)&((struct Obj04626 *)q)->fC=*(u16 * *)&((struct Obj02259 *)p)->fC+1;
        ((struct Obj04626 *)q)->fA=((struct Obj02259 *)p)->f10-1;
    }else{
        ((struct Obj04626 *)q)->fC=((struct Obj02259 *)p)->fC;
        ((struct Obj04626 *)q)->fA=((struct Obj02259 *)p)->f10;
    }
    func_02031348(*(struct Obj020314F4 * *)&((struct Obj02259 *)p)->f4,(unsigned)ov209_id,(unsigned)d_021BE794,*(unsigned *)&((struct Obj02259 *)p)->f28);
    func_021C8F90(p,4);
}
