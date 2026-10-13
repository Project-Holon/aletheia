/*
 * function: func_021FEF50
 * address: 0x021FEF50
 * packet: pkt_ov135_021FEF50
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
 *   func_021F88B0 0x021F88B0 thumb ov135
 *   func_021F8010 0x021F8010 thumb ov135
 *   d_02202EAC 0x02202EAC data a4
 */
#include "../include/Obj02204.h"
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
extern const int d_02202EAC;
extern void func_021F88B0(u8 *p, u32 n);
extern void func_021F8010(void *, void *, void *, unsigned, unsigned, unsigned, u16, void *);
int func_021FEF50(char *p)
{
    int r;
    void *w;
    r = func_021F99F0(((struct Obj02204 *)p)->fDE4);
    if (r == -1) {
    } else if (r == -2 || r == d_02202EAC + 1) {
        func_021FF570(0);
        func_0201F7A8(((struct Obj02204 *)p)->fD40, 0);
        w = ((struct Obj02204 *)p)->fD40;
        BMP_WIN_TransferChars(w);
        BMP_WIN_MakeScreen(w);
        func_020409B4(func_02045730(w));
        ((struct Obj02204 *)p)->f28 = 0;
    } else {
        func_021FF570(0);
        func_021F88B0((u8 *)p, r);
        ((struct Obj02204 *)p)->f28 = 0;
        BMP_Clear(func_02045770(((struct Obj02204 *)p)->fDDC), 0);
        func_021F8010(((struct Obj02204 *)p)->fDDC, ((struct Obj02204 *)p)->fB7C, ((struct Obj02204 *)p)->fB6C, ((struct Obj02204 *)p)->fF84, 0, 0, 0x3c40, p + 0xfa0);
    }
    return 2;
}
