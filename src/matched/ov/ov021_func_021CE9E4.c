/*
 * function: COMM_ENTRY_MENU_PrintMessage
 * address:  0x021CE9E4
 * packet:   pkt_ov021_021CE9E4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02045EC0  0x02045EC0  arm
 *   func_0201F250  0x0201F250  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   FIELD_MSGBG_ClearSysWin  0x02190F7C  thumb  ov021
 *   FIELD_MSGBG_SysWinPrintStr  0x02190EB8  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00011.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u32 f0, f4, f8, fc, f10, f14, f18;
} S;

struct MsgBank;
struct P;
struct U16Vec;
struct WordSet;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void FIELD_MSGBG_ClearSysWin(struct P *p);
extern void FIELD_MSGBG_SysWinPrintStr(struct P *p, u32 b, u16 c, u32 d);

void COMM_ENTRY_MENU_PrintMessage(S *p, u32 m)
{
    u32 n;

    if (m == 8 && ((struct Obj00011 *)p)->f57A == 8)
        return;
    ((struct Obj00011 *)p)->f57A = m;
    n = (u32)func_02045EC0((struct MsgBank *)p->f8, m);
    func_0201F250((struct WordSet *)p->f4, (void *)p->f18, (void *)n);
    STRBUF_Delete((struct U16Vec *)n);
    FIELD_MSGBG_ClearSysWin((struct P *)p->f14);
    FIELD_MSGBG_SysWinPrintStr((struct P *)p->f14, 0, 0, p->f18);
}
