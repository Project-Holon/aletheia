/*
 * function: CTVT_CALL_PrintMessage
 * address:  0x021BD0C4
 * packet:   pkt_021C12F4
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Sets up one whole +0x2c stream: three +0x1c8/+0x1cc/+0x1d0 handles, the
 * 0xf-wide tile window and the 0x440 record, then flags the object busy.
 *
 * symbols:
 *   COMM_TVT_SYS_GetFont  0x021BE034  thumb  ov172
 *   COMM_TVT_SYS_GetMsgData  0x021BE03C  thumb  ov172
 *   COMM_TVT_SYS_GetPrintQue  0x021BE044  thumb  ov172
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   func_02045EC0  0x02045EC0  arm
 *   PRINTSYS_PrintQueColor  0x0201C724  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   BMP_MENUWORK_DrawWindow  0x0201F73C  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00543.h"

typedef unsigned int u32;

extern u32  COMM_TVT_SYS_GetFont(void *p);
extern u32  COMM_TVT_SYS_GetMsgData(void *p);
extern u32  COMM_TVT_SYS_GetPrintQue(void *p);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
typedef unsigned char  u8;
struct CharBuf;
struct MsgBank;
struct U16Vec;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
typedef unsigned short u16;
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void BMP_MENUWORK_DrawWindow(void *a0, int a1, int a2, int a3);

void CTVT_CALL_PrintMessage(void *a0, char *a1, int a2)
{
    u32 x = COMM_TVT_SYS_GetFont(a0);
    u32 y = COMM_TVT_SYS_GetMsgData(a0);
    u32 z = COMM_TVT_SYS_GetPrintQue(a0);
    u32 w;

    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj00543 *)a1)->f2C)), 0xf);
    w = (u32)func_02045EC0((struct MsgBank *)y, a2);
    PRINTSYS_PrintQueColor((void *)z, (u32)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj00543 *)a1)->f2C), 0, 0, w, x, 0x440);
    STRBUF_Delete((struct U16Vec *)w);
    BMP_MENUWORK_DrawWindow((void *)(((struct Obj00543 *)a1)->f2C), 2, 0x140, 9);
    ((struct Obj00543 *)a1)->f20 = 1;
}
