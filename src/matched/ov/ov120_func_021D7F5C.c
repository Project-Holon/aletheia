/*
 * function: func_021D7F5C
 * address: 0x021D7F5C
 * packet: pkt_ov120_021D7F5C
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MSGDATA_ReadString 0x02045CAC arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   PRINTSYS_Print  0x0201C7A4  thumb  arm9
 *   GF_FONT_SetTextColor  0x0201DD78  thumb  arm9
 */
#include "../include/Obj00131.h"
typedef unsigned char u8;
typedef unsigned short u16;
struct MsgBank;
extern void MSGDATA_ReadString(struct MsgBank *bank, unsigned int index, void *dest);
extern unsigned int BMP_WIN_Create(unsigned int layer, unsigned int a, unsigned int b, unsigned int tiles, u8 c, u8 d, u8 slot);
typedef unsigned int   u32;
struct Cfg;
struct CharBuf;
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void GF_FONT_SetTextColor(u32 r, u32 g, u32 b);
typedef signed short   s16;
extern void PRINTSYS_Print(void *x, s16 y, s16 z, void *s, void *w);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
void func_021D7F5C(char *p,u16 n)
{
    void *q;
    MSGDATA_ReadString(((struct Obj00131 *)p)->fC,n,(void *)(*(int *)&((struct Obj00131 *)p)->f18));
    if(!((struct Obj00131 *)p)->f94) ((struct Obj00131 *)p)->f94=(void *)BMP_WIN_Create(1,1,13,14,3,4,1);
    q=((struct Obj00131 *)p)->f94;
    BMP_Clear(BMP_WIN_GetBmp(q),0);
    GF_FONT_SetTextColor(15,14,0);
    PRINTSYS_Print(BMP_WIN_GetBmp(q),2,3,(void *)(*(int *)&((struct Obj00131 *)p)->f18),(void *)(*(int *)&((struct Obj00131 *)p)->f14));
    BMP_WIN_TransferChars(q);
    BMP_WIN_MakeScreen(q);
}
