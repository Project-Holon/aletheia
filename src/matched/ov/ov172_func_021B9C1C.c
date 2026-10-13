/*
 * function: func_021B9C1C
 * address: 0x021B9C1C
 * packet: pkt_ov172_021B9C1C
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: Two bytes zero alignment padding follow the return.
 * symbols:
 *   func_021BE034 0x021BE034 thumb ov172
 *   func_021BE03C 0x021BE03C thumb ov172
 *   func_021BE044 0x021BE044 thumb ov172
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   func_02045EC0 0x02045EC0 arm
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   func_0201F73C 0x0201F73C thumb
 */
#include "../include/Obj05446.h"
typedef unsigned int u32;
extern u32 func_021BE034(void *);
extern u32 func_021BE03C(void *);
extern u32 func_021BE044(void *);
typedef unsigned char  u8;
struct Cfg;
struct CharBuf;
struct MsgBank;
struct PrintSys;
struct U16Vec;
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
typedef unsigned short u16;
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void BMP_WIN_TransferChars(struct Descriptor *);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
void func_021B9C1C(void *p, char *q, int id)
{
    u32 font = func_021BE034(p);
    u32 msgs = func_021BE03C(p);
    u32 sys = func_021BE044(p);
    u32 text;
    PRINTSYS_QUE_Clear((struct PrintSys *)sys);
    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj05446 *)q)->f7C)), 15);
    text = (u32)func_02045EC0((struct MsgBank *)msgs, id);
    PRINTSYS_PrintQueColor((void *)sys, (u32)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj05446 *)q)->f7C), 0, 0, text, font, 1088);
    STRBUF_Delete((struct U16Vec *)text);
    BMP_WIN_TransferChars((struct Descriptor *)((struct Obj05446 *)q)->f7C);
    BMP_WIN_MakeScreen((struct Cfg *)(((struct Obj05446 *)q)->f7C));
    func_0201F73C((void *)(((struct Obj05446 *)q)->f7C), 1, 320, 9);
    ((struct Obj05446 *)q)->f28 = 1;
}
