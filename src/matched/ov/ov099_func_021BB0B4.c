/*
 * function: func_021BB0B4
 * address: 0x021BB0B4
 * packet: pkt_ov099_021BB0B4
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 242-byte function followed only by 00 00 alignment at 021BB1A6.
 * symbols:
 *   func_021BA8EC 0x021BA8EC thumb ov099
 *   func_021BA8BC 0x021BA8BC thumb ov099
 *   func_020452E8 0x020452E8 arm
 *   func_0202020C 0x0202020C thumb
 *   func_0201F868 0x0201F868 thumb
 *   func_020456F8 0x020456F8 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_0201FEF4 0x0201FEF4 thumb
 */
#include "../include/Obj00008.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Descriptor;
struct Obj;
extern void func_021BA8EC(char *p);
extern int func_021BA8BC(void *);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_0202020C(struct Obj *, u16 *, u16 *);
extern u32 func_0201F868(void *p);
extern void func_020456F8(struct Descriptor *);
extern void func_02041B6C(u32);
extern void func_0201FEF4(u8 *);
void func_021BB0B4(char *p)
{
    func_021BA8EC(p);
    if (((struct Obj00008 *)p)->f1A4) {
        func_020452E8(*(struct Descriptor * *)&((struct Obj00008 *)p)->f1A4);
        func_0202020C(*(struct Obj * *)&((struct Obj00008 *)p)->fBC, 0, 0);
        func_0201F868(((struct Obj00008 *)p)->fB8);
        ((struct Obj00008 *)p)->fB8 = 0;
    }
    if (((struct Obj00008 *)p)->f198) { func_020452E8(*(struct Descriptor * *)&((struct Obj00008 *)p)->f198); ((struct Obj00008 *)p)->f198 = 0; }
    if (((struct Obj00008 *)p)->f190) { func_020452E8(*(struct Descriptor * *)&((struct Obj00008 *)p)->f190); ((struct Obj00008 *)p)->f190 = 0; }
    if (((struct Obj00008 *)p)->f1A8) { func_020452E8(*(struct Descriptor * *)&((struct Obj00008 *)p)->f1A8); ((struct Obj00008 *)p)->f1A8 = 0; }
    if (((struct Obj00008 *)p)->f194) { func_020452E8(*(struct Descriptor * *)&((struct Obj00008 *)p)->f194); ((struct Obj00008 *)p)->f194 = 0; }
    if (((struct Obj00008 *)p)->f1A0) { func_020452E8(*(struct Descriptor * *)&((struct Obj00008 *)p)->f1A0); ((struct Obj00008 *)p)->f1A0 = 0; }
    if (((struct Obj00008 *)p)->f19C) {
        func_020456F8(*(struct Descriptor * *)&((struct Obj00008 *)p)->f19C);
        func_02041B6C(2);
        func_021BA8BC(((struct Obj00008 *)p)->f19C);
        ((struct Obj00008 *)p)->f19C = 0;
    }
    if (((struct Obj00008 *)p)->fB4) { func_0202020C(*(struct Obj * *)&((struct Obj00008 *)p)->fB4, 0, 0); ((struct Obj00008 *)p)->fB4 = 0; }
    if (((struct Obj00008 *)p)->fB0) { func_0201F868(((struct Obj00008 *)p)->fB0); ((struct Obj00008 *)p)->fB0 = 0; }
    if (((struct Obj00008 *)p)->f108) { func_0201FEF4(*(u8 * *)&((struct Obj00008 *)p)->f108); ((struct Obj00008 *)p)->f108 = 0; }
}
