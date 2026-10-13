/*
 * function: C_GEAR_POWER_ONOFF_ResetAndPrintMessage
 * address:  0x021F0298
 * packet:   pkt_ov035_021F0298
 * region:   ov035
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   BMP_WIN_SetDispHeight 0x02045790 arm
 *   func_02045770 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   func_0201F7A8 0x0201F7A8 thumb
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   PRINTSYS_Print 0x0201C7A4 thumb
 *   func_0201F79C 0x0201F79C thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   STRBUF_Delete 0x02045808 arm
 */
#include "../include/Obj09808.h"

typedef signed short   s16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct U16Vec;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void BMP_WIN_SetDispHeight(struct Descriptor *p, u8 v);
struct Descriptor;
extern void *func_02045770(struct Descriptor *);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void func_0201F7A8(void *desc, u32 kind);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void PRINTSYS_Print(void *x, s16 y, s16 z, void *s, void *w);
extern void func_0201F79C(void *desc, u32 kind, u32 base, u32 pal);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void STRBUF_Delete(struct U16Vec *vec);

void C_GEAR_POWER_ONOFF_ResetAndPrintMessage(char *p, int a1, int a2, int a3)
{
    int r7 = (int)func_02045EC0((struct MsgBank *)(((struct Obj09808 *)p)->f38), a2);

    BMP_WIN_SetDispHeight((struct Descriptor *)a1, a3);
    BMP_Clear((struct CharBuf *)((int)func_02045770((struct Descriptor *)a1)), 15);
    func_0201F7A8((void *)a1, 2);
    BMP_WIN_MakeScreen((struct Cfg *)a1);
    PRINTSYS_Print((void *)((int)func_02045770((struct Descriptor *)a1)), 0, 0, (void *)r7, (void *)(((struct Obj09808 *)p)->f34));
    func_0201F79C((void *)a1, 0, ((struct Obj09808 *)p)->f14, 2);
    BMP_WIN_TransferChars((struct Descriptor *)a1);
    STRBUF_Delete((struct U16Vec *)r7);
}
