/*
 * function: CTVT_CALL_UpdatePrompt
 * address:  0x021BCEF8
 * packet:   pkt_ov172_021BCEF8
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   COMM_TVT_SYS_GetHeapId  0x021BE00C  thumb  ov172
 *   COMM_TVT_SYS_GetMsgData  0x021BE03C  thumb  ov172
 *   COMM_TVT_SYS_GetTaskMenu  0x021BE04C  thumb  ov172
 *   BMP_WIN_ClearScreen  0x020456F8  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 *   BMP_MENUWORK_DrawWindowBorder  0x0201F7A8  thumb
 *   APP_TASKMENU_WIN_Delete  0x02028148  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   APP_TASKMENU_WIN_Create  0x02027FEC  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   CTVT_CALL_PrintMessage  0x021BD0C4  thumb  ov172
 *
 * Keeps the button prompt (+0x1c, kind at +0x18) in step with the selection: a fourth selected slot shows prompt 0x13 (kind 2), any selected slot shows prompt 0x12 (kind 1), none removes the prompt (kind 0) and reprints message 0x11 when the mode byte at +0x14 is set.
 */
#include "../include/Obj00543.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

struct Prompt {
    u32 str;
    u16 color;
    u16 pad;
    u32 flags;
};

extern u16 COMM_TVT_SYS_GetHeapId(u16 *p);
extern u32 COMM_TVT_SYS_GetMsgData(void *p);
extern u32 COMM_TVT_SYS_GetTaskMenu(void *p);
struct Descriptor;
struct MsgBank;
struct U16Vec;
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_02041B6C(u32 bit);
extern void BMP_MENUWORK_DrawWindowBorder(void *desc, u32 kind);
extern void APP_TASKMENU_WIN_Delete(u8 *p);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 APP_TASKMENU_WIN_Create(u32 a0, u32 a1, u32 a2, u32 a3, u8 a4, u16 a5);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void CTVT_CALL_PrintMessage(void *a0, char *a1, int a2);

static inline u8 func_021BCEF8_show(u32 win)
{
    BMP_WIN_ClearScreen((struct Descriptor *)win);
    return BMP_WIN_GetBgLayer((struct Descriptor *)win);
}

void CTVT_CALL_UpdatePrompt(void *ctx, u8 *st)
{
    u8 n = 0;
    u8 i;
    u16 heap = COMM_TVT_SYS_GetHeapId(ctx);
    u32 msgs = COMM_TVT_SYS_GetMsgData(ctx);
    u32 sys = COMM_TVT_SYS_GetTaskMenu(ctx);

    for (i = 0; i < 3; i++) {
        if (st[i] != 0xff)
            n++;
    }
    if (st[3] != 0xff) {
        if (((struct Obj00543 *)st)->f18 != 2) {
            struct Prompt p = {0};

            func_02041B6C(func_021BCEF8_show(((struct Obj00543 *)st)->f2C));
            BMP_MENUWORK_DrawWindowBorder((void *)(((struct Obj00543 *)st)->f2C), 1);
            if (((struct Obj00543 *)st)->f1C != 0) {
                APP_TASKMENU_WIN_Delete((u8 *)(((struct Obj00543 *)st)->f1C));
                ((struct Obj00543 *)st)->f1C = 0;
            }
            p.str = (u32)func_02045EC0((struct MsgBank *)msgs, 0x13);
            p.color = 0x39e3;
            p.flags = 0;
            ((struct Obj00543 *)st)->f1C = APP_TASKMENU_WIN_Create(sys, (u32)(&p), 0, 0x15, 0x15, heap);
            STRBUF_Delete((struct U16Vec *)p.str);
            ((struct Obj00543 *)st)->f18 = 2;
        }
    } else if (n != 0) {
        if (((struct Obj00543 *)st)->f18 != 1) {
            struct Prompt p = {0};

            func_02041B6C(func_021BCEF8_show(((struct Obj00543 *)st)->f2C));
            BMP_MENUWORK_DrawWindowBorder((void *)(((struct Obj00543 *)st)->f2C), 1);
            if (((struct Obj00543 *)st)->f1C != 0) {
                APP_TASKMENU_WIN_Delete((u8 *)(((struct Obj00543 *)st)->f1C));
                ((struct Obj00543 *)st)->f1C = 0;
            }
            p.str = (u32)func_02045EC0((struct MsgBank *)msgs, 0x12);
            p.color = 0x39e3;
            p.flags = 0;
            ((struct Obj00543 *)st)->f1C = APP_TASKMENU_WIN_Create(sys, (u32)(&p), 0, 0x15, 0x15, heap);
            STRBUF_Delete((struct U16Vec *)p.str);
            ((struct Obj00543 *)st)->f18 = 1;
        }
    } else if (((struct Obj00543 *)st)->f18 != 0) {
        if (((struct Obj00543 *)st)->f1C != 0) {
            APP_TASKMENU_WIN_Delete((u8 *)(((struct Obj00543 *)st)->f1C));
            ((struct Obj00543 *)st)->f1C = 0;
        }
        if (st[0x14] != 0)
            CTVT_CALL_PrintMessage(ctx, (char *)st, 0x11);
        ((struct Obj00543 *)st)->f18 = 0;
    }
}
