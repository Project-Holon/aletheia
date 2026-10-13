/*
 * function: func_021B70D8
 * address: 0x021B70D8
 * packet: pkt_ov173_021B70D8
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_021B6FDC 0x021B6FDC thumb ov173
 *   func_021B7968 0x021B7968 thumb ov173
 */
#include "../include/Obj00837.h"
#include "../include/Obj24161.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Cfg;
struct CharBuf;
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_02041B6C(u32);
extern void func_021B6FDC(char *, u8, u8);
extern void func_021B7968(char *);
void func_021B70D8(char *p)
{
    u32 i;
    void *q;
    BMP_Clear(BMP_WIN_GetBmp(((struct Obj00837 *)p)->f30), 0);
    for (i = 0; i < 4; i++)
        func_021B6FDC(p, ((struct Obj24161 *)(*(char * *)&((struct Obj00837 *)p)->f0))->f16, i);
    q = ((struct Obj00837 *)p)->f30;
    BMP_WIN_TransferChars(q);
    BMP_WIN_MakeScreen(q);
    func_02041B6C(BMP_WIN_GetBgLayer(q));
    func_02041B6C(7);
    func_021B7968(p);
}
