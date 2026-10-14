/*
 * function: WORLDTRADE_TITLE_CreateWindows
 * address: 0x022002A0
 * packet: pkt_ov135_022002A0
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: full-word int cast on the window-read address breaks the loop register tie; unsigned base/index addition happens before the cast.
 * symbols:
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   WORLDTRADE_ADAPTER_PrintQueColor 0x022028C8 thumb ov135
 */
#include "../include/Obj03300.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Cfg;
struct CharBuf;
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_020409B4(u32);
extern u32 WORLDTRADE_ADAPTER_PrintQueColor(void *,u32,void *,u32,u32,u32,u16,void *);
void WORLDTRADE_TITLE_CreateWindows(u8 *p)
{
    int i;
    u32 w;
    ((struct Obj03300 *)p)->fD48=(void *)BMP_WIN_Create(1,(u8)2,(u8)1,(u8)0x1C,2,1,(u16)1);
    BMP_Clear(BMP_WIN_GetBmp(((struct Obj03300 *)p)->fD48),0xA);
    w=*(u32 *)&((struct Obj03300 *)p)->fD48;
    BMP_WIN_TransferChars((void *)w); BMP_WIN_MakeScreen((void *)w); func_020409B4(BMP_WIN_GetBgLayer((void *)w));
    WORLDTRADE_ADAPTER_PrintQueColor(((struct Obj03300 *)p)->fD48,0,((struct Obj03300 *)p)->fB8C,0,2,0,0x35CA,p+0xFA0);
    for(i=0;i<3;i++) {
        u32 window;
        *(void **)((u32)p+i*4+0xD50)=(void *)BMP_WIN_Create(1,(u8)9,(u8)(i*5+6),(u8)0xF,2,1,(u16)1);
        BMP_Clear(BMP_WIN_GetBmp(*(void **)((int)((u32)p+i*4)+0xD50)),1);
        window=*(u32 *)((u32)p+i*4+0xD50);
        BMP_WIN_TransferChars((void *)window); BMP_WIN_MakeScreen((void *)window); func_020409B4(BMP_WIN_GetBgLayer((void *)window));
    }
    ((struct Obj03300 *)p)->fD40=(void *)BMP_WIN_Create(0,(u8)2,(u8)0x15,(u8)0x1B,2,0xD,(u16)1);
    BMP_Clear(BMP_WIN_GetBmp(((struct Obj03300 *)p)->fD40),0xF);
    ((struct Obj03300 *)p)->fDD0=(void *)BMP_WIN_Create(0,(u8)2,(u8)0x13,(u8)0x1B,4,0xD,(u16)1);
    BMP_Clear(BMP_WIN_GetBmp(((struct Obj03300 *)p)->fDD0),0xF);
}
