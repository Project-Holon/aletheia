/*
 * function: WIFILOGIN_MSG_ShowMessage
 * address: 0x021D5CCC
 * packet: pkt_ov115_021D5CCC
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero padding bytes at 0x021D5D3A follow the return.
 * symbols:
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   MSGDATA_ReadString 0x02045CAC arm
 *   PRINTSYS_PrintColor 0x0201C7D0 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj04468.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void PRINTSYS_PrintColor(void *,s16,s16,void *,void *,u16);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void func_02041B6C(u32);
void WIFILOGIN_MSG_ShowMessage(u8 *p, u32 n) {
    void *w;
    if (((struct Obj04468 *)p)->f34==0) ((struct Obj04468 *)p)->f34=(void *)BMP_WIN_Create(1,4,7,24,2,11,1);
    w=((struct Obj04468 *)p)->f34;
    BMP_Clear(BMP_WIN_GetBmp(w),0);
    MSGDATA_ReadString(((struct Obj04468 *)p)->f1C,n,((struct Obj04468 *)p)->f28);
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(w),0,0,((struct Obj04468 *)p)->f28,((struct Obj04468 *)p)->f24,0x3cc0);
    BMP_WIN_TransferChars(w);
    BMP_WIN_MakeScreen(w);
    func_02041B6C(1);
}
