/*
 * function: func_021C24F0
 * address: 0x021C24F0
 * packet: pkt_ov099_021C24F0
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: 3064C preserves caller-loaded r2; 3159C returns the live allocator pointer.
 * symbols:
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0203D668 0x0203D668 arm
 *   func_021BCB8C 0x021BCB8C thumb ov099
 *   func_02012934 0x02012934 thumb
 *   func_0201283C 0x0201283C thumb
 *   func_0200873C 0x0200873C thumb
 *   func_021C24D4 0x021C24D4 thumb ov099
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   func_021BB1A8 0x021BB1A8 thumb ov099
 *   func_021BDE94 0x021BDE94 thumb ov099
 *   func_021BE6F0 0x021BE6F0 thumb ov099
 *   func_0203CD98 0x0203CD98 arm
 *   func_021BA7D8 0x021BA7D8 thumb ov099
 *   func_0203D34C 0x0203D34C arm
 */
#include "../include/Obj01386.h"
#include "../include/Obj02804.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct BigObj;
extern void func_0203064C(u32, u32, u32);
struct Obj0203159C;
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *, int, int);
extern void func_0203D668(u32);
extern int func_021BCB8C(void *);
extern void *func_02012934(const struct BigObj *p);
extern u32 func_0201283C(const struct BigObj *);
struct Sub02008700Obj;
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern void func_021C24D4(u8 *p, int v);
extern void func_020434DC(u32, u32);
extern void func_02043598(u32, u32);
extern void func_021BB1A8(char *);
extern void func_021BDE94(char *);
extern void func_021BE6F0(char *, int, int);
extern int func_0203CD98(void);
extern void func_021BA7D8(void *p);
extern void func_0203D34C(u32, u32);
int func_021C24F0(void *obj, int unused, char *args)
{
    char *p;
    func_0203064C(1, 0x8021, 0xa4000);
    p = func_0203159C(obj, 0x1360, 0x21);
    func_02082BCC(p, 0, 0x1360);
    func_0203D668((u32)p);
    ((struct Obj01386 *)p)->f8 = ((struct Obj02804 *)args)->f0;
    ((struct Obj01386 *)p)->fC0 = ((struct Obj02804 *)args)->f8;
    *(u32 *)&((struct Obj01386 *)p)->fC4 = ((struct Obj02804 *)args)->f4;
    ((struct Obj01386 *)p)->fCC = func_021BCB8C(((struct Obj01386 *)p)->fC4);
    ((struct Obj01386 *)p)->fC8 = func_02012934(*(struct BigObj * *)&((struct Obj01386 *)p)->fC4);
    ((struct Obj01386 *)p)->f4 = func_0201283C(*(struct BigObj * *)&((struct Obj01386 *)p)->fC4);
    ((struct Obj01386 *)p)->fD8 = (u32)func_0200873C((void *)(((struct Obj02804 *)args)->f8));
    ((struct Obj01386 *)p)->f1D8 = *(u32 *)&((struct Obj02804 *)args)->fC;
    ((struct Obj01386 *)p)->f135C = ((struct Obj02804 *)args)->f49;
    if (((struct Obj02804 *)args)->fC == 1) {
        ((struct Obj02804 *)args)->fC = 0;
        func_021C24D4((u8 *)p, 4);
    } else if (((struct Obj02804 *)args)->fC != 0) {
        func_021C24D4((u8 *)p, 4);
    } else {
        func_021C24D4((u8 *)p, 1);
    }
    ((struct Obj01386 *)p)->f1D0 = 0;
    ((struct Obj01386 *)p)->f1F0 = -1;
    *(char * *)&((struct Obj01386 *)p)->f248 = args;
    func_020434DC(15, 0);
    func_02043598(15, 0);
    func_021BB1A8(p);
    ((struct Obj01386 *)p)->f1CC = 0;
    func_021BDE94(p);
    if (((struct Obj02804 *)args)->fC == 0) func_021BE6F0(p, 1, 2);
    if (func_0203CD98() != 0) {
        func_021BA7D8(p);
        func_0203D34C(1, 0x21);
    }
    return 1;
}
