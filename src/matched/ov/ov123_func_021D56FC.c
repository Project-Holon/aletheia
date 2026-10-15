/*
 * function: GSYNC_MESSAGE_PrintStream
 * address: 0x021D56FC
 * packet: pkt_ov123_021D56FC
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   func_02041B6C 0x02041B6C arm
 *   PRINTSYS_Print  0x0201C7A4  thumb  arm9
 *   PRINTSYS_PrintStream  0x0201CCE4  thumb  arm9
 *   GF_FONT_SetTextColor  0x0201DD78  thumb  arm9
 *   MSG_SPEED_GetWait  0x02012FFC  thumb  arm9
 *   BMP_MENUWORK_DrawWindow  0x0201F73C  thumb  arm9
 */
#include "../include/Obj01933.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern unsigned int BMP_WIN_Create(unsigned int layer, unsigned int a, unsigned int b, unsigned int tiles, u8 c, u8 d, u8 slot);
typedef unsigned int   u32;
struct Cfg;
struct CharBuf;
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void GF_FONT_SetTextColor(unsigned int,unsigned int,unsigned int);
extern void PRINTSYS_Print(void *,short,short,void *,void *);
extern void *PRINTSYS_PrintStream(void *,int,int,void *,void *,int,void *,int,u16,u16);
extern signed char MSG_SPEED_GetWait(void);
extern void func_02028470(u8 *p, u32 v);
extern void BMP_MENUWORK_DrawWindow(void *a0, int a1, int a2, int a3);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void func_02041B6C(u32 bit);
void GSYNC_MESSAGE_PrintStream(char *p,int mode)
{
    void *q;
    if (!((struct Obj01933 *)p)->f44) ((struct Obj01933 *)p)->f44=(void *)BMP_WIN_Create((int)5,(int)1,(u8)1,(int)30,4,11,1);
    q=((struct Obj01933 *)p)->f44;
    BMP_Clear(BMP_WIN_GetBmp(q),15);
    GF_FONT_SetTextColor(1,2,15);
    if (mode) {
        PRINTSYS_Print(BMP_WIN_GetBmp(q),0,0,((struct Obj01933 *)p)->f2C,((struct Obj01933 *)p)->f28);
    } else {
        ((struct Obj01933 *)p)->f80=PRINTSYS_PrintStream(q,(int)0,(int)0,((struct Obj01933 *)p)->f2C,((struct Obj01933 *)p)->f28,(int)MSG_SPEED_GetWait(),((struct Obj01933 *)p)->f84,(int)2,((struct Obj01933 *)p)->fB0,15);
        func_02028470((u8 *)(p+0xa8),(int)6);
    }
    BMP_MENUWORK_DrawWindow(q,1,(u16)(((struct Obj01933 *)p)->f8),12);
    BMP_WIN_TransferChars(q);
    BMP_WIN_MakeScreen(q);
    func_02041B6C(5);
}
