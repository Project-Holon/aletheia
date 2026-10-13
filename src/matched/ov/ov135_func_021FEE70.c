/*
 * function: func_021FEE70
 * address: 0x021FEE70
 * packet: pkt_ov135_021FEE70
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F99F0 0x021F99F0 thumb ov135
 *   func_021FF570 0x021FF570 thumb ov135
 *   func_0201F7A8 0x0201F7A8 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   BMP_Clear 0x02043B5C arm
 *   func_021F882C 0x021F882C thumb ov135
 *   func_021F8154 0x021F8154 thumb ov135
 */
#include "../include/Obj05417.h"
typedef unsigned short u16;
extern int func_021F99F0(void *);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Cfg;
struct CharBuf;
struct Descriptor;
extern void func_021FF570(u32 v);
extern void func_0201F7A8(void *, unsigned);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern void *func_02045770(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void func_021F882C(u8 *dst, int i, int kind);
extern void func_021F8154(void *, void *, int, unsigned, unsigned, u16, int, void *);
int func_021FEE70(char *p)
{
    unsigned r = func_021F99F0(((struct Obj05417 *)p)->fDE4);
    switch (r) {
    case 11:
    case -2:
        func_021FF570(0);
        ((struct Obj05417 *)p)->f28 = 0;
        break;
    case -1: break;
    default:
        func_021FF570(0);
        func_021F882C((u8 *)(p + 0xb56), r, 1);
        ((struct Obj05417 *)p)->f28 = 0;
        BMP_Clear(func_02045770(((struct Obj05417 *)p)->fDA4), 0);
        func_021F8154(((struct Obj05417 *)p)->fDA4, ((struct Obj05417 *)p)->fB6C, r, 0, 0, 0x3c40, 1, p + 0xfa0);
        break;
    }
    return 2;
}
