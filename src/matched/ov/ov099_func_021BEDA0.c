/*
 * function: func_021BEDA0
 * address: 0x021BEDA0
 * packet: pkt_ov099_021BEDA0
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020452E8 0x020452E8 arm
 *   func_02049B40 0x02049B40 arm
 *   func_021BA8BC 0x021BA8BC thumb ov099
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_0201F73C 0x0201F73C thumb
 */
#include "../include/Obj02156.h"
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct CharBuf;
struct Descriptor;
extern u32 func_020452E8(struct Descriptor *d);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern int func_021BA8BC(void *p);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
void func_021BEDA0(char *p)
{
    if (((struct Obj02156 *)p)->f194) func_020452E8(((struct Obj02156 *)p)->f194);
    func_02049B40(0x17, 5, 0, 0x1e0, 0x20, 0x21);
    ((struct Obj02156 *)p)->f198 = (void *)func_021BA8BC(((struct Obj02156 *)p)->f198);
    ((struct Obj02156 *)p)->f194 = (void *)func_020450F0(3, 1, 1, 0x1c, 2, 0xf, 1);
    ((struct Obj02156 *)p)->f198 = (void *)func_020450F0(2, 1, 1, 0x1c, 2, 0xf, 1);
    func_02043B5C(func_02045770(((struct Obj02156 *)p)->f194), 0xff);
    func_02045334(((struct Obj02156 *)p)->f194);
    func_02043B5C(func_02045770(((struct Obj02156 *)p)->f198), 0xff);
    func_02045334(((struct Obj02156 *)p)->f198);
    func_0201F73C(((struct Obj02156 *)p)->f198, 1, (u16)(((struct Obj02156 *)p)->f1334), 0xe);
}
