/*
 * function: func_021FC6A4
 * address: 0x021FC6A4
 * packet: pkt_ov186_021FC6A4
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   STRBUF_Create 0x020457B0 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   d_02200D5C 0x02200D5C data a1
 */
#include "../include/Obj02901.h"
extern const char d_02200D5C[];
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct CharBuf;
struct Descriptor;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MI_CpuFill8(void *,int,int);
extern void *STRBUF_Create(unsigned,unsigned short);
struct Cfg;
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_020409B4(u32 index);
void *func_021FC6A4(unsigned short plane,unsigned a,unsigned short b,unsigned short c,unsigned char d,unsigned char e,void *owner,unsigned short heap)
{
    char *p;
    void *bmp;
    p=func_02030734(heap,0x24,0,d_02200D5C,0x5f);
    MI_CpuFill8(p,0,0x24);
    ((struct Obj02901 *)p)->f14=0;
    ((struct Obj02901 *)p)->f8=owner;
    ((struct Obj02901 *)p)->f16=plane;
    ((struct Obj02901 *)p)->f10=STRBUF_Create(0xff,heap);
    bmp=(void *)BMP_WIN_Create((unsigned char)plane,a,b,c,d,e,1);
    ((struct Obj02901 *)p)->fC=bmp;
    ((struct Obj02901 *)p)->f0=bmp;
    p[4]=0;
    BMP_Clear(BMP_WIN_GetBmp(bmp),((struct Obj02901 *)p)->f14);
    bmp=((struct Obj02901 *)p)->fC;
    BMP_WIN_TransferChars(bmp);
    BMP_WIN_MakeScreen(bmp);
    func_020409B4(BMP_WIN_GetBgLayer(bmp));
    return p;
}
