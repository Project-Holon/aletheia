/*
 * function: func_021BD484
 * address: 0x021BD484
 * packet: pkt_ov110_021BD484
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02034AC4 0x02034AC4 arm
 *   func_0203064C 0x0203064C arm
 *   func_021BD5C4 0x021BD5C4 thumb ov110
 *   func_021B9BEC 0x021B9BEC thumb ov110
 *   func_021B9C74 0x021B9C74 thumb ov110
 *   func_021BABE8 0x021BABE8 thumb ov110
 *   func_021BD7A0 0x021BD7A0 thumb ov110
 *   func_021BD894 0x021BD894 thumb ov110
 *   func_0203D34C 0x0203D34C arm
 *   func_02030D28 0x02030D28 arm
 *   d_00000043 0x00000043 data a1
 */
#include "../include/Obj03242.h"
typedef unsigned char u8;
typedef signed int     s32;
typedef unsigned int   u32;
struct Ctx;
extern int func_02034AC4(s32 handle);
extern void func_0203064C(unsigned int,unsigned int,unsigned int);
struct Obj0203159C;
extern u8 *func_021BD5C4(struct Obj0203159C *owner, u8 *input);
extern void func_021B9BEC(u8 *p, int id);
extern int func_021B9C74(unsigned int a);
extern int func_021BABE8(void *);
extern void func_021BD7A0(u8 *,int (*)(u8 *,void *));
extern int func_021BD894(u8 *,void *);
extern const u8 d_00000043[];
extern void func_0203D34C(u32 a, u32 b);
extern void func_02030D28(struct Ctx *c);
int func_021BD484(void *a,int *state,int c,void *p) {
    u8 *obj;
    switch(*state) {
    case 0:
        func_02034AC4((int)d_00000043);
        func_0203064C(1,41,0x18000);
        func_0203064C(1,42,0x32000);
        obj=func_021BD5C4(a,(u8 *)c);
        func_021B9BEC(((struct Obj03242 *)obj)->f14,0);
        ++*state;
        break;
    case 1:
        obj=p;
        if(func_021B9C74((unsigned int)(((struct Obj03242 *)obj)->f14))) {
            if(((struct Obj03242 *)obj)->f4==2) obj[0x68]=func_021BABE8(((struct Obj03242 *)obj)->f14);
            else obj[0x68]=0;
            func_021B9BEC(((struct Obj03242 *)obj)->f14,4);
            ++*state;
        }
        break;
    case 2:
        obj=p;
        if(func_021B9C74((unsigned int)(((struct Obj03242 *)obj)->f14))) {
            func_021BD7A0(obj,func_021BD894);
            func_0203D34C(1,42);
            return 1;
        }
        break;
    }
    func_02030D28(((struct Obj03242 *)obj)->f7C);
    return 0;
}
