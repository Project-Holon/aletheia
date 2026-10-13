/*
 * function: PLIST_MESSAGE_Update
 * address: 0x021BB644
 * packet: pkt_ov091_021BB644
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TCBL_Main 0x020310C4 arm
 *   APP_KEYCURSOR_Update 0x020286C4 thumb
 *   func_02028484 0x02028484 thumb
 *   KEY_GetTrg 0x020362DC arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   APP_KEYCURSOR_Animate 0x0202865C thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   TIME_ICON_CreateNode 0x0202EE8C thumb
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 */
#include "../include/Obj20886.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int     s32;
struct Blk;
struct Bmp;
struct Cfg;
struct Ctx;
struct Descriptor;
struct PrintSys;
struct Rec3;
struct Tcbl;
struct U16Vec;
extern void TCBL_Main(struct Tcbl *p);
extern void APP_KEYCURSOR_Update(struct Ctx *ctx, void *p, void *cell);
extern s32 func_02028484(struct Blk *blk, void *h);
extern u32 KEY_GetTrg(void);
extern int TOUCHPANEL_GetTrg(void);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern void STRBUF_Delete(struct U16Vec *vec);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void APP_KEYCURSOR_Animate(struct Ctx *ctx, const struct Bmp *bmp, u32 color);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_02041B6C(u32 bit);
extern u8 *TIME_ICON_CreateNode(u32 a, void *b, u8 c, u8 d, u16 e);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
#define W(o) (*(u32 *)(s+(o)))
void PLIST_MESSAGE_Update(u8 *p,u8 *s)
{
    TCBL_Main((struct Tcbl *)W(8));
    if (W(0xc) != 0) {
        APP_KEYCURSOR_Update((struct Ctx *)W(0x14),(void *)W(0xc),(void *)W(4));
        if (func_02028484((struct Blk *)(s+0x18),(void *)W(0xc)) == 1) {
            if (W(0x20) == 0 || (KEY_GetTrg() & 3) != 0 || TOUCHPANEL_GetTrg() == 1) {
                if (W(0x20) == 1) GFL_USE_PlaySeDefaultVolume(0x547);
                PRINTSYS_PrintStreamDelete((struct Rec3 *)W(0xc));
                W(0xc)=0;
                STRBUF_Delete((struct U16Vec *)W(0x10));
            } else {
                APP_KEYCURSOR_Animate((struct Ctx *)W(0x14),(const struct Bmp *)((u32)BMP_WIN_GetBmp((struct Descriptor *)W(4))),15);
                BMP_WIN_TransferChars((struct Descriptor *)W(4));
            }
        }
    }
    if (W(0x24) == 1 && PRINTSYS_QUE_IsExistTarget((struct PrintSys *)W(0x28),(void *)((u32)BMP_WIN_GetBmp((struct Descriptor *)W(4)))) == 0) {
        u32 t=W(4);
        W(0x24)=0;
        BMP_WIN_TransferChars((struct Descriptor *)t);
        BMP_WIN_MakeScreen((struct Cfg *)t);
        func_02041B6C(BMP_WIN_GetBgLayer((struct Descriptor *)t));
        if (W(0x30) == 1) {
            W(0x30)=0;
            W(0x34)=(u32)TIME_ICON_CreateNode(W(8),(void *)W(4),15,16,((struct Obj20886 *)p)->f0);
        }
    }
    PRINTSYS_QUE_Main((struct PrintSys *)W(0x28));
}
