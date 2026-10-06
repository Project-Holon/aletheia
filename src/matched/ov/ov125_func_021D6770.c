/*
 * function: func_021D6770
 * address: 0x021D6770
 * packet: pkt_ov125_021D6770
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B99B8 0x021B99B8 thumb ov114
 *   func_021B9838 0x021B9838 thumb ov114
 *   func_021D85B4 0x021D85B4 arm ov125
 *   func_02045808 0x02045808 arm
 *   func_02045C04 0x02045C04 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02034A5C 0x02034A5C arm
 *   ov114_id 0x00000072 data
 */
#include "../include/Obj03805.h"
typedef unsigned char  u8;
struct Rec;
struct U16Vec;
struct WordSet;
extern void func_021B99B8(u8 *p);
extern void func_021B9838(u8 *p);
extern void func_021D85B4(void);
extern void func_02045808(struct U16Vec *vec);
extern unsigned int func_0201ED04(struct WordSet *p);
extern unsigned int func_02045C04(struct Rec *rec);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
extern void func_02034A5C(int);
extern char ov114_id[];
void func_021D6770(char *p)
{
    if (((struct Obj03805 *)p)->f404) {
        func_021B99B8(((struct Obj03805 *)p)->f404);
        func_021B9838(((struct Obj03805 *)p)->f404);
    }
    func_021D85B4();
    ((struct Obj03805 *)p)->f3B4 = 0;
    func_02045808(((struct Obj03805 *)p)->f3EC);
    func_0201ED04(((struct Obj03805 *)p)->f3E8);
    func_02045C04(((struct Obj03805 *)p)->f3E4);
    func_020307B0(((struct Obj03805 *)p)->f3AC);
    func_02034A5C((int)ov114_id);
}
