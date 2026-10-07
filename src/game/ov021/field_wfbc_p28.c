/*
 * file:     field_wfbc_p28.c
 * unit:     yes
 * function: func_02196290, func_021962C4, func_021962F4
 * address:  0x02196290
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0202F038  0x0202F038  thumb
 *   func_0202EE8C  0x0202EE8C  thumb
 *   func_0201F7A8  0x0201F7A8  thumb
 *   func_020456F8  0x020456F8  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_020452E8  0x020452E8  arm
 */
#include "../../matched/include/Obj00094.h"

struct Descriptor;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

extern void func_0202F038(u8 *p);
extern u8 *func_0202EE8C(u32 a, void *b, u8 c, u8 d, u16 e);
extern void func_0201F7A8(void *desc, u32 kind);
extern u32 func_02041B6C(u32);
extern void func_020456F8(struct Descriptor *d);
extern u32 func_020452E8(struct Descriptor *d);
void func_02196290(u8 *a);
int func_021962C4(u32 a);
void func_021962F4(u8 *a);


/*
 * Addresses are Black-image addresses.
 */
void func_02196290(u8 *a)
{
    if (((struct Obj00094 *)a)->f2E8 != 0) {
        func_0202F038((u8 *)(((struct Obj00094 *)a)->f2E8));
        ((struct Obj00094 *)a)->f2E8 = 0;
    }
    ((struct Obj00094 *)a)->f2E8 = (u32)func_0202EE8C(((struct Obj00094 *)a)->f2B8, (void *)(*(u32 *)&((struct Obj00094 *)a)->f2B0), 15, 16, ((struct Obj00094 *)a)->f10);
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021962C4(u32 a)
{
if (*(u32 *)((u8 *)(a) + ((186 << 2))) != 0) {
    func_0202F038((u8 *)(*(u32 *)((u8 *)(a) + ((186 << 2)))));
    *(u32 *)((u8 *)(a) + ((186 << 2))) = 0;
}
func_0201F7A8((void *)(*(u32 *)((u8 *)(a) + ((43 << 4)))), 2);
func_020456F8((struct Descriptor *)(*(u32 *)((u8 *)(a) + ((43 << 4)))));
return func_02041B6C(5);
}


void func_021962F4(u8 *a)
{
    func_021962C4((u32)a);
    func_020452E8((struct Descriptor *)(*(u32 *)&((struct Obj00094 *)a)->f2B0));
    *(u32 *)&((struct Obj00094 *)a)->f2B0 = 0;
}
