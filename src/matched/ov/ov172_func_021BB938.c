/*
 * function: func_021BB938
 * address: 0x021BB938
 * packet: pkt_ov172_021BB938
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BE034 0x021BE034 thumb ov172
 *   func_021BE03C 0x021BE03C thumb ov172
 *   func_021BE044 0x021BE044 thumb ov172
 *   BMP_WIN_Delete 0x020452E8 arm
 *   BMP_WIN_Create 0x020450F0 arm
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
#include "../include/Obj02881.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 func_021BE034(void *);
extern u32 func_021BE03C(void *);
extern u32 func_021BE044(void *);
struct Descriptor;
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern u32 BMP_WIN_Create(u32, u32, u32, u32, u8, u8, u8);
struct Cfg;
struct CharBuf;
struct MsgBank;
struct PrintSys;
struct U16Vec;
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern void *BMP_WIN_GetBmp(struct Descriptor *);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
typedef unsigned short u16;
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void BMP_WIN_TransferChars(struct Descriptor *);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
void func_021BB938(void *p, u8 *q, int id)
{
    u32 font = func_021BE034(p);
    u32 msgs = func_021BE03C(p);
    u32 sys = func_021BE044(p);
    u32 text;
    if (*(u32 *)&((struct Obj02881 *)q)->f50 != 0) BMP_WIN_Delete(((struct Obj02881 *)q)->f50);
    *(u32 *)&((struct Obj02881 *)q)->f50 = BMP_WIN_Create(0, 1, q[4] == 0 ? 4 : 1, 30, 4, 10, 1);
    PRINTSYS_QUE_Clear((struct PrintSys *)sys);
    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)*(u32 *)&((struct Obj02881 *)q)->f50)), 15);
    text = (u32)func_02045EC0((struct MsgBank *)msgs, id);
    PRINTSYS_PrintQueColor((void *)sys, (u32)BMP_WIN_GetBmp((struct Descriptor *)*(u32 *)&((struct Obj02881 *)q)->f50), 0, 0, text, font, 1088);
    STRBUF_Delete((struct U16Vec *)text);
    BMP_WIN_TransferChars((struct Descriptor *)*(u32 *)&((struct Obj02881 *)q)->f50);
    BMP_WIN_MakeScreen((struct Cfg *)(*(u32 *)&((struct Obj02881 *)q)->f50));
    func_0201F73C((void *)(*(u32 *)&((struct Obj02881 *)q)->f50), 1, 512, 9);
    ((struct Obj02881 *)q)->f44 = 1;
}
