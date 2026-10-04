/*
 * function: func_021D80D4
 * address: 0x021D80D4
 * packet: pkt_ov120_021D80D4
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * follower: two zero padding bytes at 021D8116.
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_020456F8 0x020456F8 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_020452E8 0x020452E8 arm
 */
#include "../include/Obj05352.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
struct CharBuf;
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_020456F8(struct Descriptor *d);
extern void func_02041B6C(u32 bit);
extern void func_020452E8(struct Descriptor *d);
void func_021D80D4(char *p)
{
    if (((struct Obj05352 *)p)->f84) {
        func_02043B5C(func_02045770(((struct Obj05352 *)p)->f84),0);
        func_02045334(((struct Obj05352 *)p)->f84);
        func_020456F8(((struct Obj05352 *)p)->f84);
        func_02041B6C(1);
        func_020452E8(((struct Obj05352 *)p)->f84);
        ((struct Obj05352 *)p)->f84=0;
    }
}
