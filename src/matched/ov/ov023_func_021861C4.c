/*
 * function: OEKAKI_PrintMessage
 * address:  0x021861C4
 * packet:   pkt_ov023_021861C4
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   STRBUF_Create  0x020457B0  arm
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   func_0201F250  0x0201F250  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   func_0201F73C  0x0201F73C  thumb
 *   PRINTSYS_PrintStreamDelete  0x0201CE48  thumb
 *   PRINTSYS_PrintQueColor  0x0201C724  thumb
 *   MSG_SPEED_GetWait  0x02012FFC  thumb
 *   PRINTSYS_PrintStream  0x0201CCE4  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 */
#include "../include/Obj00525.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct Rec3;
struct U16Vec;
struct WordSet;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern signed char MSG_SPEED_GetWait(void);
extern void *PRINTSYS_PrintStream(void *a0, u32 a1, u32 a2, void *a3, u32 a4, u32 a5, void *a6, u32 a7, u16 a8, u32 a9);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_020409B4(u32 layer);

void OEKAKI_PrintMessage(u8 *w, u32 msg, int mode)
{
    void *str;
    void *t;
    void *p;

    str = STRBUF_Create(0x50, 0x28);
    MSGDATA_ReadString(((struct Obj00525 *)w)->f14, msg, str);
    func_0201F250(((struct Obj00525 *)w)->f10, ((struct Obj00525 *)w)->f30, str);
    STRBUF_Delete(str);
    BMP_Clear(BMP_WIN_GetBmp(((struct Obj00525 *)w)->f11C), 15);
    func_0201F73C(((struct Obj00525 *)w)->f11C, 0, 1, 10);
    if (((struct Obj00525 *)w)->f16C != 0) {
        PRINTSYS_PrintStreamDelete(((struct Obj00525 *)w)->f16C);
        ((struct Obj00525 *)w)->f16C = 0;
    }
    if (mode == 0) {
        t = ((struct Obj00525 *)w)->f168;
        PRINTSYS_PrintQueColor(t, (u32)BMP_WIN_GetBmp(((struct Obj00525 *)w)->f15C), 0, 0, (u32)(((struct Obj00525 *)w)->f30), ((struct Obj00525 *)w)->fC, 0x44F);
        ((struct Obj00525 *)w)->f160 = 1;
    } else {
        ((struct Obj00525 *)w)->f16C = PRINTSYS_PrintStream(((struct Obj00525 *)w)->f11C, 0, 0, ((struct Obj00525 *)w)->f30,
                                              ((struct Obj00525 *)w)->fC, MSG_SPEED_GetWait(),
                                              ((struct Obj00525 *)w)->f170, 1, 0x28, 0xF0F);
    }
    p = ((struct Obj00525 *)w)->f11C;
    BMP_WIN_TransferChars(p);
    BMP_WIN_MakeScreen(p);
    func_020409B4(BMP_WIN_GetBgLayer(p));
}
