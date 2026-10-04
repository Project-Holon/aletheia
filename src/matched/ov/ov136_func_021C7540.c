/*
 * function: func_021C7540
 * address: 0x021C7540
 * packet: pkt_ov136_021C7540
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: trailing 021C758A halfword is zero alignment padding.
 * symbols:
 *   func_021C3E00 0x021C3E00 thumb ov136
 *   func_021C3E04 0x021C3E04 thumb ov136
 *   func_021C3E24 0x021C3E24 thumb ov136
 */
#include "../include/Obj03838.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Flags { u8 index : 7; u8 flag : 1; };
extern int func_021C3E00(u8 *);
extern int func_021C3E04(u8 *, void *);
extern void func_021C3E24(u8 *);
struct BigObj;
extern void *func_02012934(const struct BigObj *p);
extern void *func_0201292C(const struct BigObj *p);
extern void *func_0201AB28(void *, u32);
extern u32 func_02007F1C(u8 *base, u16 id, u16 qty, u16 d);
int func_021C7540(u8 *p)
{
    ((struct Obj03838 *)p)->f24 = func_021C3E00(*(u8 * *)&((struct Obj03838 *)p)->f10);
    if (((struct Obj03838 *)p)->f24 == 1) {
        func_021C3E04(*(u8 * *)&((struct Obj03838 *)p)->f10, func_0201AB28(func_02012934(**(void ** *)&((struct Obj03838 *)p)->f4), ((struct Flags *)(p + 0x21))->index));
        func_02007F1C(func_0201292C(**(void ** *)&((struct Obj03838 *)p)->f4), ((struct Obj03838 *)p)->f22, 1, 0x65);
    }
    func_021C3E24(*(u8 * *)&((struct Obj03838 *)p)->f10);
    return 0;
}
