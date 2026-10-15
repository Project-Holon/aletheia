/*
 * function: GTSNEGO_MSG_PrintWindowB
 * address: 0x021D7A74
 * packet: pkt_ov120_021D7A74
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of zero alignment padding after the return.
 * symbols:
 *   MSGDATA_ReadString 0x02045CAC arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   PRINTSYS_Print 0x0201C7A4 thumb
 *   BMP_MENUWORK_DrawWindow 0x0201F73C thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj00131.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short   s16;
struct MsgBank;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Cfg;
struct CharBuf;
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void GF_FONT_SetTextColor(u32,u32,u32);
extern void PRINTSYS_Print(void *x, s16 y, s16 z, void *s, void *w);
extern void BMP_MENUWORK_DrawWindow(void *a0, int a1, int a2, int a3);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void func_02041B6C(u32);
void GTSNEGO_MSG_PrintWindowB(u8 *p, int n)
{
    void *q;
    MSGDATA_ReadString(((struct Obj00131 *)p)->fC,n,(void *)(*(int *)&((struct Obj00131 *)p)->f18));
    if (!((struct Obj00131 *)p)->f30) ((struct Obj00131 *)p)->f30=(void *)BMP_WIN_Create(1,1,21,30,2,11,1);
    q=((struct Obj00131 *)p)->f30;
    BMP_Clear(BMP_WIN_GetBmp(q),15);
    GF_FONT_SetTextColor(1,2,15);
    PRINTSYS_Print(BMP_WIN_GetBmp(q),0,0,(void *)(*(int *)&((struct Obj00131 *)p)->f18),(void *)(*(int *)&((struct Obj00131 *)p)->f14));
    BMP_MENUWORK_DrawWindow(q,1,(u16)(((struct Obj00131 *)p)->f4),12);
    BMP_WIN_TransferChars(q);
    BMP_WIN_MakeScreen(q);
    func_02041B6C(1);
}
