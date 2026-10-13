/*
 * function: C_GEAR_POWER_ONOFF_PrintMessage
 * address:  0x021F0254
 * packet:   pkt_ov035_021F0254
 * region:   ov035
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   C_GEAR_POWER_ONOFF_PrintMessage 0x021F0254 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   PRINTSYS_Print 0x0201C7A4 thumb
 *   func_0201F79C 0x0201F79C thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   STRBUF_Delete 0x02045808 arm
 */
#include "../include/Obj09807.h"

typedef signed short   s16;
typedef unsigned int   u32;
struct MsgBank;
struct U16Vec;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *);
extern void PRINTSYS_Print(void *x, s16 y, s16 z, void *s, void *w);
extern void func_0201F79C(void *desc, u32 kind, u32 base, u32 pal);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void STRBUF_Delete(struct U16Vec *vec);

void C_GEAR_POWER_ONOFF_PrintMessage(char *p, int a1, int a2)
{
    int r6 = (int)func_02045EC0((struct MsgBank *)(((struct Obj09807 *)p)->f38), a2);
    PRINTSYS_Print((void *)((int)BMP_WIN_GetBmp((struct Descriptor *)a1)), 0, 0, (void *)r6, (void *)(((struct Obj09807 *)p)->f34));
    func_0201F79C((void *)a1, 0, ((struct Obj09807 *)p)->f14, 2);
    BMP_WIN_TransferChars((struct Descriptor *)a1);
    STRBUF_Delete((struct U16Vec *)r6);
}
