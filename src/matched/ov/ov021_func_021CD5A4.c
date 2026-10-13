/*
 * function: COMM_ENTRY_MENU_Delete
 * address:  0x021CD5A4
 * packet:   pkt_ov021_021CD5A4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   COMM_ENTRY_MENU_GetAcceptedMask  0x021CE760  thumb  ov021
 *   COMM_ENTRY_MENU_CloseWindows  0x021CE81C  thumb  ov021
 *   FIELD_MSGBG_DeleteMenuFunc  0x021909BC  thumb  ov021
 *   STRBUF_Delete  0x02045808  arm
 *   FIELD_MSGBG_DeleteSysWin  0x02190E40  thumb  ov021
 *   FIELD_MSGBG_DeleteMsgData  0x021904C8  thumb  ov021
 *   func_0201ED04  0x0201ED04  thumb
 *   GFL_NET_GetRunState  0x0203CD98  arm
 *   COMM_ENTRY_EndNetCommands  0x021CF17C  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

typedef unsigned char  u8;
extern u32 COMM_ENTRY_MENU_GetAcceptedMask(u8 *p);
extern void COMM_ENTRY_MENU_CloseWindows(u32 *p);
struct Rec;
extern int FIELD_MSGBG_DeleteMenuFunc(void *a);
struct U16Vec;
struct WordSet;
extern void STRBUF_Delete(struct U16Vec *vec);
extern int FIELD_MSGBG_DeleteSysWin(u32 a);
extern u32 FIELD_MSGBG_DeleteMsgData(struct Rec *a0);
extern u32 func_0201ED04(struct WordSet *p);
extern int GFL_NET_GetRunState(void);
extern void COMM_ENTRY_EndNetCommands(void);
extern u32 func_020307B0(void *p);

u32 COMM_ENTRY_MENU_Delete(u32 *p)
{
    u32 r;

    r = COMM_ENTRY_MENU_GetAcceptedMask((u8 *)p);
    COMM_ENTRY_MENU_CloseWindows(p);
    if (p[0x4c]) {
        FIELD_MSGBG_DeleteMenuFunc((void *)p[0x4c]);
        p[0x4c] = 0;
    }
    STRBUF_Delete((struct U16Vec *)p[10]);
    STRBUF_Delete((struct U16Vec *)p[9]);
    STRBUF_Delete((struct U16Vec *)p[8]);
    STRBUF_Delete((struct U16Vec *)p[7]);
    STRBUF_Delete((struct U16Vec *)p[6]);
    FIELD_MSGBG_DeleteSysWin(p[5]);
    FIELD_MSGBG_DeleteMsgData((struct Rec *)p[2]);
    func_0201ED04((struct WordSet *)p[1]);
    if (GFL_NET_GetRunState() == 1) {
        COMM_ENTRY_EndNetCommands();
    }
    func_020307B0(p);
    return r;
}
