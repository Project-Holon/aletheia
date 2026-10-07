/*
 * file:     zukan_p01.c
 * unit:     yes
 * function: func_021C8E80, func_021C8F2C, func_021C8F58
 * address:  0x021C8E80
 * region:   ov212
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02031324 0x02031324 arm
 *   func_021C9288 0x021C9288 thumb ov212
 *   func_021C92EC 0x021C92EC thumb ov212
 *   func_021C9380 0x021C9380 thumb ov212
 *   func_02031330 0x02031330 arm
 *   d_021C9944 0x021C9944 data a4
 *   func_021C8F7C 0x021C8F7C thumb ov212
 */
#include "../../matched/include/Obj00635.h"
#include "../../matched/include/Obj25642.h"
#include "../../matched/include/Obj25643.h"
#include "../../matched/include/Obj25644.h"
#include "../../matched/include/Obj25645.h"
#include "../../matched/include/Obj25646.h"
#include "../../matched/include/Obj25647.h"
#include "../../matched/include/Obj25648.h"
#include "../../matched/include/Obj25649.h"
#include "../../matched/include/Obj25650.h"
#include "../../matched/include/Obj08415.h"
#include "../../matched/include/Obj08416.h"

struct Obj0203159C;
struct Blk37;
struct S020314B8;
struct S020315D4;
typedef unsigned short u16;

typedef unsigned char u8;

typedef unsigned int u32;

extern void func_0203064C(unsigned,unsigned,unsigned);
extern void *func_0203159C(struct Obj0203159C *,unsigned,unsigned);
extern void func_02082BCC(void *,unsigned char,unsigned);
extern void *func_02031324(int);
extern u16 func_021C9288(struct Blk37 *,u16 **,unsigned);
extern void func_021C92EC(void *p, u16 *ids, unsigned count);
extern void func_021C9380(struct Blk37 *,unsigned char *);
extern unsigned func_02031330(void *);
extern void func_021C8F7C(u8 *);
extern void func_0203133C(struct S020314B8 *);
extern void func_020315D4(struct S020315D4 *);
extern void func_020306F0(u32 heap);
int func_021C8E80(struct Obj0203159C *obj,int unused,char *ctx);
int func_021C8F2C(int a,int b,int c,unsigned char *p);
int func_021C8F58(struct S020315D4 *obj, void *b, void *c, u8 *p);
extern unsigned char d_021C9944[];

/*
 * trailing: two zero alignment bytes at 021C8F2A.
 * prototype: caller consumes r0 from legacy void 0203159C and 02031324;
 * 31324 forwards r0 to matched 31354(int), which returns allocation.
 * 3064C visibly receives three inputs here; retain caller's r2 size.
 */
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

int func_021C8F2C(int a,int b,int c,unsigned char *p){if(((struct Obj08415 *)p)->f1C==9)return 1;((struct Obj08415 *)p)->f8=func_02031330(((struct Obj08415 *)p)->f4);((struct Obj08415 *)p)->f1C=(*(unsigned (**)(unsigned char *))(d_021C9944+*(unsigned *)(p+28)*4))(p);return 0;}

int func_021C8F58(struct S020315D4 *obj, void *b, void *c, u8 *p) {
    func_021C8F7C(p);
    func_0203133C(*(struct S020314B8 * *)&((struct Obj08416 *)p)->f4);
    func_020315D4(obj);
    func_020306F0(105);
    return 1;
}
