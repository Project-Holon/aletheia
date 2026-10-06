/*
 * function: func_021F3BF0
 * address: 0x021F3BF0
 * packet: pkt_ov112_021F3BF0
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two-byte padding at 0x021F3C4E.
 * symbols:
 *   func_021F6C7C 0x021F6C7C thumb ov112
 *   func_021F6F4C 0x021F6F4C thumb ov112
 *   func_021F7120 0x021F7120 thumb ov112
 *   func_021F51B0 0x021F51B0 thumb ov112
 *   func_021F4948 0x021F4948 thumb ov112
 *   func_021F3ED0 0x021F3ED0 thumb ov112
 *   func_020452E8 0x020452E8 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj03246.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021F6C7C(char *p);
extern void func_021F6F4C(u8 *p);
struct Descriptor;
extern void func_021F7120(char *p);
extern void func_021F51B0(int a);
extern void func_021F4948(u8 *);
extern void func_021F3ED0(u8 *);
extern u32 func_020452E8(struct Descriptor *d);
extern u32 func_0201D83C(void *ptr);
extern u32 func_020307B0(void *p);
void func_021F3BF0(u8 *p)
{
    u8 i;
    func_021F6C7C((char *)(((struct Obj03246 *)p)->f40));
    func_021F6F4C((u8 *)(((struct Obj03246 *)p)->f28));
    func_021F7120(((struct Obj03246 *)p)->f2C);
    func_021F51B0(((struct Obj03246 *)p)->f20);
    func_021F4948(*(u8 * *)&((struct Obj03246 *)p)->f24);
    func_020452E8(((struct Obj03246 *)p)->f58);
    func_020452E8(((struct Obj03246 *)p)->f54);
    func_0201D83C(((struct Obj03246 *)p)->f60);
    func_0201D83C(((struct Obj03246 *)p)->f5C);
    func_021F3ED0(p);
    for(i=0;i<4;i++) func_020307B0(*(void **)(p+i*4+8));
    func_020307B0(p);
}
