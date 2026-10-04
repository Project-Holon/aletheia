/*
 * function: func_021B8728
 * address: 0x021B8728
 * packet: pkt_ov103_021B8728
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: grouped offset sums retain the original off/state colors; signed conversion of an unsigned second offset calculation prevents unwanted common subexpression retention.
 * permuter: historical types300 consumed; never repeated in wave77.
 * behavior: off/tmp/tmp1 assigned before uses; original supported callback order retained; out point fields read only after8D9C success and both initialized by that body. No new volatile or narrowed pointers.
 * symbols:
 *   func_021B7250 0x021B7250 thumb ov101
 *   func_021B727C 0x021B727C thumb ov101
 *   func_021B8358 0x021B8358 thumb ov103
 *   func_021B8D9C 0x021B8D9C thumb ov103
 *   func_021B91B4 0x021B91B4 thumb ov103
 *   func_021B8138 0x021B8138 thumb ov103
 *   func_020061E4 0x020061E4 thumb
 *   func_021B8338 0x021B8338 thumb ov103
 *   func_021B8828 0x021B8828 thumb ov103
 *   func_021B7954 0x021B7954 thumb ov103
 *   func_021B8CA0 0x021B8CA0 thumb ov103
 *   func_021B8CB0 0x021B8CB0 thumb ov103
 *   func_021B91A8 0x021B91A8 thumb ov103
 *   func_021B8364 0x021B8364 thumb ov103
 *   func_021B6480 0x021B6480 thumb ov101
 *   func_021B8A44 0x021B8A44 thumb ov103
 *   d_021B926C 0x021B926C data a4
  */
#include "../include/Obj13737.h"
#include "../include/Obj22202.h"
#include "../include/Obj22203.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef enum { OFFSET_AAC = 0xaac } Offset;
extern int func_021B7250(int *);
extern int func_021B727C(int);
extern void func_021B8358(u8 *);
extern int func_021B8D9C(u32 *,u32 *);
extern int func_021B91B4(u8 *,u32 *);
extern void func_021B8138(u8 *,void *,int,int,short);
extern void func_020061E4(u32);
extern void func_021B8338(u32,u32);
extern void func_021B8828(u8 *,u16 *),func_021B8364(u8 *,u16 *),func_021B8A44(u8 *,u16 *);
extern u8 *func_021B7954(u8 *);
extern void func_021B8CA0(u8 **,int,int);
extern void func_021B8CB0(u8 *,int,int,int);
extern void func_021B91A8(void *);
extern int func_021B6480(int *);
extern u32 d_021B926C[];
void func_021B8728(u8 *p,u16 *state)
{
    struct { int x,y; } point;
    Offset off;
    Offset tmp;
    u8 *tmp1;
    off=OFFSET_AAC;
    if(func_021B7250(*(int **)(p+(off-0x74)))==1) {
        tmp=(Offset)off;
        tmp1=*(u8 **)(p+(tmp+0x60))+12;
        ((struct Obj22202 *)tmp1)->f0=1;
        func_021B8358(p);
    } else if(func_021B727C(*(int *)(p+(int)((u32)off-0x74)))==0) {
        switch(*state) {
        case 0: {
            void *obj;
            if(func_021B8D9C(d_021B926C,(u32 *)&point)) {
                if(func_021B91B4(p+off,d_021B926C)) {
                    func_021B8138(p+0x184,p+0x174,3,0,0);
                    func_020061E4(0x654);
                    func_021B8338((u32)p,(u32)func_021B8828);
                }
                if(off) {}
                obj=func_021B7954(p);
                func_021B8CA0(obj,1,1);
                func_021B8CB0(obj,1,point.x,point.y);
            } else {
                obj=func_021B7954(p);
                func_021B8CA0(obj,1,0);
                func_021B91A8(p+off);
                *state=1;
            }
            break;
        }
        case 1:
            (((struct Obj13737 *)p)->f738)++;
            func_021B8338((u32)p,(u32)func_021B8364);
            break;
        }
    }
    if(func_021B6480(*(int * *)&((struct Obj22203 *)(*(u8 * *)&((struct Obj13737 *)p)->fB0C))->f4))
        func_021B8338((u32)p,(u32)func_021B8A44);
}
