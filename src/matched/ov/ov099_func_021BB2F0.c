/*
 * function: WIFICLUB_OpenPartnerPanelWithBg
 * address:  0x021BB2F0
 * packet:   pkt_ov099_021BB2F0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02009864  0x02009864  thumb
 *   func_02040AF0  0x02040AF0  arm
 *   func_020414AC  0x020414AC  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   WIFICLUB_DrawPartnerPanel  0x021BB528  thumb  ov099
 *   func_02041B6C  0x02041B6C  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BG_SYS_SetSubPlaneVisible  0x02043598  arm
 */
#include "../include/Obj00008.h"
#include "../include/Obj22020.h"

typedef unsigned char u8;

typedef unsigned int   u32;
struct CharBuf;
struct Descriptor;
struct Sub020097BCObj;
extern u32 func_02009864(const struct Sub020097BCObj *obj, u32 i, u32 field);
extern void func_02040AF0(u32 index, const void *src, u32 mode, u32 offset);
extern void func_020414AC(int a);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void WIFICLUB_DrawPartnerPanel(char *p, int v);
extern void func_02041B6C(u32 bit);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);

void WIFICLUB_OpenPartnerPanelWithBg(char *p, int v)
{
    char *q;

    func_02009864(((struct Obj00008 *)p)->f4, ((struct Obj00008 *)p)->f8ED - 1, 9);
    q = *(char * *)&((struct Obj00008 *)p)->f8C0;
    func_02040AF0(6, q + 0xC, (u32)(((struct Obj22020 *)q)->f8), 0);
    func_020414AC(7);
    BMP_Clear(BMP_WIN_GetBmp(((struct Obj00008 *)p)->f95C), 0);
    BMP_Clear(BMP_WIN_GetBmp(((struct Obj00008 *)p)->f958), 0);
    WIFICLUB_DrawPartnerPanel(p, v);
    func_02041B6C(7);
    BMP_WIN_TransferChars(((struct Obj00008 *)p)->f95C);
    BMP_WIN_TransferChars(((struct Obj00008 *)p)->f958);
    BG_SYS_SetSubPlaneVisible(2, 0);
    BG_SYS_SetSubPlaneVisible(8, 1);
}
