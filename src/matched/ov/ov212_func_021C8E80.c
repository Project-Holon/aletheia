/*
 * function: func_021C8E80
 * address: 0x021C8E80
 * packet: pkt_ov212_021C8E80
 * region: ov212
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: two zero alignment bytes at 021C8F2A.
 * prototype: caller consumes r0 from legacy void 0203159C and 02031324;
 * 31324 forwards r0 to matched 31354(int), which returns allocation.
 * 3064C visibly receives three inputs here; retain caller's r2 size.
 * symbols:
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02031324 0x02031324 arm
 *   func_021C9288 0x021C9288 thumb ov212
 *   func_021C92EC 0x021C92EC thumb ov212
 *   func_021C9380 0x021C9380 thumb ov212
 */
#include "../include/Obj00635.h"
#include "../include/Obj25642.h"
#include "../include/Obj25643.h"
#include "../include/Obj25644.h"
#include "../include/Obj25645.h"
#include "../include/Obj25646.h"
#include "../include/Obj25647.h"
#include "../include/Obj25648.h"
#include "../include/Obj25649.h"
#include "../include/Obj25650.h"
typedef unsigned short u16;
struct Obj0203159C;struct Blk37;
extern void func_0203064C(unsigned,unsigned,unsigned);
extern void *func_0203159C(struct Obj0203159C *,unsigned,unsigned);
extern void func_02082BCC(void *,unsigned char,unsigned);
extern void *func_02031324(int);
extern u16 func_021C9288(struct Blk37 *,u16 **,unsigned);
extern void func_021C92EC(void *p, u16 *ids, unsigned count);
extern void func_021C9380(struct Blk37 *,unsigned char *);
int func_021C8E80(struct Obj0203159C *obj,int unused,char *ctx)
{
    char *p;
    func_0203064C(1,105,0x8000);
    p=func_0203159C(obj,44,105);
    func_02082BCC(p,0,44);
    ((struct Obj00635 *)p)->f0=ctx;
    ((struct Obj00635 *)p)->f4=func_02031324(105);
    ((struct Obj00635 *)p)->f10=func_021C9288(*(struct Blk37 * *)&((struct Obj25642 *)(*(char * *)&((struct Obj00635 *)p)->f0))->f4,(u16 **)(p+12),105);
    ((struct Obj00635 *)p)->f12=0;
    func_021C92EC(*(struct Blk37 * *)&((struct Obj25643 *)(*(char * *)&((struct Obj00635 *)p)->f0))->f4,*(u16 * *)&((struct Obj00635 *)p)->fC,((struct Obj00635 *)p)->f10);
    func_021C9380(*(struct Blk37 * *)&((struct Obj25644 *)(*(char * *)&((struct Obj00635 *)p)->f0))->f4,(unsigned char *)(p+20));
    if(((struct Obj25645 *)(*(char * *)&((struct Obj00635 *)p)->f0))->fC==0){((struct Obj00635 *)p)->f1C=1;}
    else if(((struct Obj25646 *)(*(char * *)&((struct Obj00635 *)p)->f0))->fC==1){((struct Obj00635 *)p)->f1C=3;}
    else if(((struct Obj25647 *)(*(char * *)&((struct Obj00635 *)p)->f0))->fC==2){((struct Obj00635 *)p)->f1C=5;((struct Obj00635 *)p)->f24=1;}
    else if(((struct Obj25648 *)(*(char * *)&((struct Obj00635 *)p)->f0))->fC==3){((struct Obj00635 *)p)->f1C=5;((struct Obj00635 *)p)->f24=2;}
    else if(((struct Obj25649 *)(*(char * *)&((struct Obj00635 *)p)->f0))->fC==4){((struct Obj00635 *)p)->f1C=5;((struct Obj00635 *)p)->f24=3;}
    else if(((struct Obj25650 *)(*(char * *)&((struct Obj00635 *)p)->f0))->fC==5){((struct Obj00635 *)p)->f1C=5;((struct Obj00635 *)p)->f24=4;}
    else {((struct Obj00635 *)p)->f1C=7;}
    return 1;
}
