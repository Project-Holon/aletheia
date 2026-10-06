/*
 * function: func_021D7A3C
 * address: 0x021D7A3C
 * packet: pkt_ov116_021D7A3C
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02009860 0x02009860 thumb
 *   func_02009CC0 0x02009CC0 thumb
 *   func_02008540 0x02008540 thumb
 *   func_0200853C 0x0200853C thumb
 *   func_0205994C 0x0205994C arm
 *   func_021C8F2C 0x021C8F2C arm ov114
 *   func_021C96CC 0x021C96CC arm ov114
 *   func_021D70E4 0x021D70E4 thumb ov116
 */
#include "../include/Obj00671.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
extern void *func_02009860(void *);
extern int func_02009CC0(void *a0);
struct Sub0200852CObj;
extern void func_02008540(struct Sub0200852CObj *obj, u32 value);
extern u32 func_0200853C(const struct Sub0200852CObj *obj);
struct DWCstAccUserData;
extern unsigned long long func_0205994C(struct DWCstAccUserData *userdata);
extern void func_021C8F2C(unsigned a, unsigned b, unsigned c, unsigned mode);
extern void func_021C96CC(void);
extern void func_021D70E4(u8 *p);
void func_021D7A3C(u8 *p) {
    void *a=func_02009860(((struct Obj00671 *)p)->f184C);
    void *b;
    u64 value;
    func_02008540(((struct Obj00671 *)p)->f1850,(u32)func_02009CC0(((struct Obj00671 *)p)->f184C));
    b=(void *)func_0200853C(((struct Obj00671 *)p)->f1850);
    value=func_0205994C(a);
    func_021C8F2C((unsigned int)b,(u32)value,(u32)(value>>32),0);
    func_021C96CC();
    func_021D70E4(p+0x182c);
    ((struct Obj00671 *)p)->fB68=1;
}
