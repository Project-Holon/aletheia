/*
 * function: func_021B9B78
 * address: 0x021B9B78
 * packet: pkt_ov218_021B9B78
 * region: ov218
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02012FFC 0x02012FFC thumb
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   MSGDATA_ReadString 0x02045CAC arm
 *   func_0201F250 0x0201F250 thumb
 *   PRINTSYS_PrintStream 0x0201CCE4 thumb
 *   func_0201F73C 0x0201F73C thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 * Caller stores the live r0 return of legacy void forwarder 0201CCE4.
 */
#include "../include/Obj02265.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Descriptor;
struct CharBuf;
struct Cfg;
struct MsgBank;
struct WordSet;
extern signed char func_02012FFC(void);
extern void *BMP_WIN_GetBmp(struct Descriptor *);
extern void BMP_Clear(struct CharBuf *, u8);
extern void GF_FONT_SetTextColor(u32, u32, u32);
extern void MSGDATA_ReadString(struct MsgBank *, u32, void *);
extern void func_0201F250(struct WordSet *, void *, void *);
extern u32 PRINTSYS_PrintStream(u32, u32, u32, u32, u32, u32, u32, u32, u16, u16);
extern void func_0201F73C(void *, int, int, int);
extern void BMP_WIN_TransferChars(struct Descriptor *);
extern void BMP_WIN_MakeScreen(struct Cfg *);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *);
extern void func_02041B6C(u32);
void func_021B9B78(char *p, u32 id)
{
    int value = func_02012FFC();
    struct Descriptor *obj = *(struct Descriptor * *)&((struct Obj02265 *)p)->f24;
    BMP_Clear(BMP_WIN_GetBmp(obj), 15);
    GF_FONT_SetTextColor(1, 2, 15);
    MSGDATA_ReadString(*(struct MsgBank * *)&((struct Obj02265 *)p)->f8, id, ((struct Obj02265 *)p)->f18);
    func_0201F250(*(struct WordSet * *)&((struct Obj02265 *)p)->f14, ((struct Obj02265 *)p)->f1C, ((struct Obj02265 *)p)->f18);
    ((struct Obj02265 *)p)->f20 = PRINTSYS_PrintStream((u32)obj, 4, 0, *(u32 *)&((struct Obj02265 *)p)->f1C, ((struct Obj02265 *)p)->fC, value, ((struct Obj02265 *)p)->f4, 65535, ((struct Obj02265 *)p)->f0, 15);
    func_0201F73C(((struct Obj02265 *)p)->f24, 2, 1, 15);
    BMP_WIN_TransferChars(obj);
    BMP_WIN_MakeScreen((struct Cfg *)obj);
    func_02041B6C(BMP_WIN_GetBgLayer(obj));
}
