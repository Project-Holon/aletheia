/*
 * function: WIFICLUB_CreateTitleWindows
 * address: 0x021BEDA0
 * packet: pkt_ov099_021BEDA0
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_WIN_Delete 0x020452E8 arm
 *   func_02049B40 0x02049B40 arm
 *   WIFICLUB_DeleteWindow 0x021BA8BC thumb ov099
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_MENUWORK_DrawWindow 0x0201F73C thumb
 */
#include "../include/Obj02156.h"
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct CharBuf;
struct Descriptor;
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern int WIFICLUB_DeleteWindow(void *p);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_MENUWORK_DrawWindow(void *a0, int a1, int a2, int a3);
void WIFICLUB_CreateTitleWindows(char *p)
{
    if (((struct Obj02156 *)p)->f194) BMP_WIN_Delete(((struct Obj02156 *)p)->f194);
    func_02049B40(0x17, 5, 0, 0x1e0, 0x20, 0x21);
    ((struct Obj02156 *)p)->f198 = (void *)WIFICLUB_DeleteWindow(((struct Obj02156 *)p)->f198);
    ((struct Obj02156 *)p)->f194 = (void *)BMP_WIN_Create(3, 1, 1, 0x1c, 2, 0xf, 1);
    ((struct Obj02156 *)p)->f198 = (void *)BMP_WIN_Create(2, 1, 1, 0x1c, 2, 0xf, 1);
    BMP_Clear(BMP_WIN_GetBmp(((struct Obj02156 *)p)->f194), 0xff);
    BMP_WIN_TransferChars(((struct Obj02156 *)p)->f194);
    BMP_Clear(BMP_WIN_GetBmp(((struct Obj02156 *)p)->f198), 0xff);
    BMP_WIN_TransferChars(((struct Obj02156 *)p)->f198);
    BMP_MENUWORK_DrawWindow(((struct Obj02156 *)p)->f198, 1, (u16)(((struct Obj02156 *)p)->f1334), 0xe);
}
