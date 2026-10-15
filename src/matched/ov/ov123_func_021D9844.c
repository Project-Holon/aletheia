/*
 * function: PDWACC_MESSAGE_PrintNumberWindows
 * address: 0x021D9844
 * packet: pkt_ov123_021D9844
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PDWACC_MESSAGE_FormatNumber 0x021D97CC thumb ov123
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   MSGDATA_ReadString 0x02045CAC arm
 *   func_02041B6C 0x02041B6C arm
 *   PRINTSYS_Print  0x0201C7A4  thumb  arm9
 *   GF_FONT_SetTextColor  0x0201DD78  thumb  arm9
 *   BMP_MENUWORK_DrawWindow  0x0201F73C  thumb  arm9
 */
#include "../include/Obj01737.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern void PDWACC_MESSAGE_FormatNumber(int,void *);
extern unsigned int BMP_WIN_Create(unsigned int layer, unsigned int a, unsigned int b, unsigned int tiles, u8 c, u8 d, u8 slot);
typedef unsigned int   u32;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void GF_FONT_SetTextColor(unsigned int,unsigned int,unsigned int);
extern void PRINTSYS_Print(void *,short,short,void *,void *);
extern void BMP_MENUWORK_DrawWindow(void *a0, int a1, int a2, int a3);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void func_02041B6C(u32 bit);
void PDWACC_MESSAGE_PrintNumberWindows(char *p, int n, int a2)
{
    void *q;
    PDWACC_MESSAGE_FormatNumber(n,((struct Obj01737 *)p)->f2C);
    if (!((struct Obj01737 *)p)->f40) ((struct Obj01737 *)p)->f40=(void *)BMP_WIN_Create((int)1,(int)1,(u8)8,(int)30,4,11,1);
    q=((struct Obj01737 *)p)->f40;
    BMP_Clear(BMP_WIN_GetBmp(q),15);
    GF_FONT_SetTextColor(1,2,15);
    PRINTSYS_Print(BMP_WIN_GetBmp(q),0,0,((struct Obj01737 *)p)->f2C,((struct Obj01737 *)p)->f28);
    BMP_MENUWORK_DrawWindow(q,1,(u16)(((struct Obj01737 *)p)->f0),12);
    BMP_WIN_TransferChars(q);
    BMP_WIN_MakeScreen(q);
    if (!((struct Obj01737 *)p)->f44) ((struct Obj01737 *)p)->f44=(void *)BMP_WIN_Create((int)1,(int)3,(u8)3,(int)22,2,11,1);
    q=((struct Obj01737 *)p)->f44;
    GF_FONT_SetTextColor(1,2,0);
    MSGDATA_ReadString(((struct Obj01737 *)p)->f20,10,((struct Obj01737 *)p)->f2C);
    PRINTSYS_Print(BMP_WIN_GetBmp(q),0,0,((struct Obj01737 *)p)->f2C,((struct Obj01737 *)p)->f28);
    BMP_WIN_TransferChars(q);
    BMP_WIN_MakeScreen(q);
    func_02041B6C(5);
}
