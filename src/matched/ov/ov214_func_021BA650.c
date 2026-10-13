/*
 * function: func_021BA650
 * address: 0x021BA650
 * packet: pkt_ov214_021BA650
 * region: ov214
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent-tail: 021BA69E alignment padding (two zero bytes).
 * spelling: Add i*4 before the field offset to retain the in-loop base adds.
 * symbols:
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_02045770 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj25726.h"
typedef unsigned char u8;
struct PrintSys;
extern void func_0201C6EC(struct PrintSys *p);
struct Cfg;
struct CharBuf;
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(unsigned);
void func_021BA650(int unused,char*p)
{
    u8 i;
    void*h;
    for(i=0;i<=1;i++){
        func_0201C6EC((struct PrintSys *)(((struct Obj25726 *)p)->f10));
        BMP_Clear(func_02045770(*(void**)(p+i*4+0x8c)),0);
        h=*(void**)(p+i*4+0x8c);
        BMP_WIN_TransferChars(h);
        BMP_WIN_MakeScreen(h);
        func_02041B6C(func_02045730(h));
        *(int*)(p+i*4+0x9c)=1;
    }
}
