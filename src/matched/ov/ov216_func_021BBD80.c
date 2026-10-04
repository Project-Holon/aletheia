/*
 * function: func_021BBD80
 * address: 0x021BBD80
 * packet: pkt_ov216_021BBD80
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: 3159C allocator result remains live in r0 and is consumed here;
 * 3064C receives visibly loaded r2 beyond legacy two-argument declaration.
 * symbols:
 *   func_02034AC4 0x02034AC4 arm
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021BC930 0x021BC930 thumb ov216
 *   func_021BBFEC 0x021BBFEC thumb ov216
 *   func_021BC0C8 0x021BC0C8 thumb ov216
 *   func_021BC1E4 0x021BC1E4 thumb ov216
 *   func_021BC6D8 0x021BC6D8 thumb ov216
 *   func_021BC454 0x021BC454 thumb ov216
 *   func_021BC650 0x021BC650 thumb ov216
 *   func_021BC70C 0x021BC70C thumb ov216
 *   func_021BCA38 0x021BCA38 thumb ov216
 *   func_021BC398 0x021BC398 thumb ov216
 *   ov067_id 0x00000043 data
 *   ov072_id 0x00000048 data
 */
#include "../include/Obj00366.h"
struct Obj0203159C;
extern unsigned char ov067_id[],ov072_id[];
extern int func_02034AC4(int);
extern void func_0203064C(unsigned,unsigned,unsigned);
extern char *func_0203159C(struct Obj0203159C *,unsigned,unsigned);
extern void func_02082BCC(void *,int,int);
extern void *func_021BC930(int,int);
extern void func_021BBFEC(char *);
extern void func_021BC0C8(char *);
typedef unsigned short u16;
extern void func_021BC1E4(char *p, u16 heap);
extern void func_021BC6D8(char *);
typedef unsigned int   u32;
extern void func_021BC454(char *p, u32 handle);
extern void func_021BC650(char *);
extern void func_021BC70C(char *);
extern void *func_021BCA38(char *p);
extern void *func_021BC398(void *,unsigned);
int func_021BBD80(struct Obj0203159C *obj,int unused1,void *config)
{
    char *p;
    func_02034AC4((int)ov067_id);
    func_02034AC4((int)ov072_id);
    func_0203064C(1,119,3<<16);
    p=func_0203159C(obj,620,119);
    func_02082BCC(p,0,620);
    ((struct Obj00366 *)p)->f14=config;
    ((struct Obj00366 *)p)->f0=119;
    ((struct Obj00366 *)p)->f2=0x8077;
    ((struct Obj00366 *)p)->f50=func_021BC930(0,((struct Obj00366 *)p)->f0);
    func_021BBFEC(p);
    func_021BC0C8(p);
    func_021BC1E4(p,((struct Obj00366 *)p)->f0);
    func_021BC6D8(p);
    func_021BC454(p,(u32)(((struct Obj00366 *)p)->f54));
    func_021BC650(p);
    func_021BC70C(p);
    ((struct Obj00366 *)p)->f124=func_021BC398(func_021BCA38(((struct Obj00366 *)p)->f50),((struct Obj00366 *)p)->f0);
    return 1;
}
