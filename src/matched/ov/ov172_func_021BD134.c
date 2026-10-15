/*
 * function: CTVT_CALL_PrintTimeMessage
 * address:  0x021BD134
 * packet:   pkt_ov172_021BD134
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
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
 *   COMM_TVT_SYS_DeleteTimeIcon  0x021BE34C  thumb  ov172
 *
 * Prints message msgId into the text window at +0x30: clears it, draws the string with the context's font and colour 0x440, frees the string, schedules the window transfer and marks the window shown (+0x24) with no pending wait (+0x38).
 */
#include "../include/Obj01266.h"

typedef unsigned long u32;

extern u32 COMM_TVT_SYS_GetFont(void *p);
extern u32 COMM_TVT_SYS_GetMsgData(void *p);
extern u32 COMM_TVT_SYS_GetPrintQue(void *p);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *win);
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
extern void COMM_TVT_SYS_DeleteTimeIcon(void *p);

void CTVT_CALL_PrintTimeMessage(void *ctx, char *st, u32 msgId)
{
    u32 font = COMM_TVT_SYS_GetFont(ctx);
    u32 msgs = COMM_TVT_SYS_GetMsgData(ctx);
    u32 sys = COMM_TVT_SYS_GetPrintQue(ctx);
    u32 str;

    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj01266 *)st)->f30)), 0xf);
    str = (u32)func_02045EC0((struct MsgBank *)msgs, msgId);
    PRINTSYS_PrintQueColor((void *)sys, (u32)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj01266 *)st)->f30), 0, 0, str, font, 0x440);
    STRBUF_Delete((struct U16Vec *)str);
    BMP_MENUWORK_DrawWindow((void *)(((struct Obj01266 *)st)->f30), 2, 0x140, 9);
    ((struct Obj01266 *)st)->f24 = 1;
    ((struct Obj01266 *)st)->f38 = 0;
    COMM_TVT_SYS_DeleteTimeIcon(ctx);
}
