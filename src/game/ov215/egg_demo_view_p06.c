/*
 * file:     egg_demo_view_p06.c
 * unit:     yes
 * function: func_021F6F24, func_021F6F64
 * address:  0x021F6F24
 * region:   ov215
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02048A18 0x02048A18 arm
 *   func_02047A60 0x02047A60 arm
 *   func_02047E88 0x02047E88 arm
 *   func_021F66C8 0x021F66C8 thumb ov215
 *   func_020489F4 0x020489F4 arm
 *   func_020477A4 0x020477A4 arm
 *   func_0204784C 0x0204784C arm
 *   d_021F7330 0x021F7330 data a4
 */
#include "../../matched/include/Obj06708.h"
#include "../../matched/include/Obj14714.h"
#include "../../matched/include/Obj00317.h"
#include "../../matched/include/Obj06709.h"

struct Arg;
struct Util;
struct Setup;
struct Record;
struct G3dSys;
struct AnmCtl;
typedef unsigned short u16;

typedef signed int     s32;

typedef unsigned int   u32;

extern unsigned func_02048A18(unsigned char *,int);
extern void func_02047A60(void *,struct Arg *);
extern u16 func_02047E88(struct Util *,const struct Setup *);
extern struct Record *func_021F66C8(unsigned,unsigned);
extern unsigned func_020489F4(unsigned char *,int);
extern unsigned func_020477A4(struct G3dSys *,unsigned);
extern u32 func_0204784C(struct AnmCtl *c, u16 idx, s32 *frame);
void func_021F6F24(char *p);
void func_021F6F64(char *p);
extern const struct Setup d_021F7330;

void func_021F6F24(char *p)
{
    unsigned short i;
    for(i=0;i<((struct Obj06708 *)p)->f50;i++) {
        char *entry=*(char * *)&((struct Obj06708 *)p)->f54+i*0x44;
        if(((struct Obj14714 *)entry)->f40)
            func_02047A60((void *)func_02048A18(*(unsigned char * *)&((struct Obj06708 *)p)->f48,((struct Obj14714 *)entry)->f0),(struct Arg *)(entry+4));
    }
}

void func_021F6F64(char *p)
{
    unsigned id;
    char *entry;
    u16 i;
    void *q;
    int frame;
    ((struct Obj00317 *)p)->f4C=func_02047E88(*(struct Util * *)&((struct Obj00317 *)p)->f48,&d_021F7330);
    ((struct Obj00317 *)p)->f50=1;
    *(struct Record * *)&((struct Obj00317 *)p)->f54=func_021F66C8(((struct Obj00317 *)p)->f0,((struct Obj00317 *)p)->f50);
    id=func_020489F4(*(unsigned char * *)&((struct Obj00317 *)p)->f48,((struct Obj00317 *)p)->f4C);
    ((struct Obj00317 *)p)->f4E=0;
    entry=*(char * *)&((struct Obj00317 *)p)->f54;
    ((struct Obj06709 *)entry)->f0=id;
    ((struct Obj06709 *)entry)->f4=0;
    ((struct Obj06709 *)entry)->f8=0;
    ((struct Obj06709 *)entry)->fC=0;
    ((struct Obj06709 *)entry)->f40=1;
    for(i=0;i<((struct Obj00317 *)p)->f50;i++)
        func_020477A4((struct G3dSys *)func_02048A18(*(unsigned char * *)&((struct Obj00317 *)p)->f48,*(u16 *)(*(char * *)&((struct Obj00317 *)p)->f54+i*68)),0);
    ((struct Obj00317 *)p)->f58=0;
    q=(void *)func_02048A18(*(unsigned char * *)&((struct Obj00317 *)p)->f48,*(u16 *)(*(char * *)&((struct Obj00317 *)p)->f54+((struct Obj00317 *)p)->f4E*68));
    frame=0;
    ((struct Obj00317 *)p)->f5C=0;
    func_020477A4((struct G3dSys *)q,1);
    func_020477A4((struct G3dSys *)q,2);
    func_0204784C((struct AnmCtl *)q,1,&frame);
    func_0204784C((struct AnmCtl *)q,2,&frame);
}
