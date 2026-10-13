/*
 * function: PARTY_SELECT_LIST_PrintPartyNames
 * address:  0x021CD050
 * packet:   pkt_ov021_021CD050
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   PARTY_SELECT_LIST_CreateListWindow  0x021CD004  thumb  ov021
 *   FIELD_MSGBG_ClearMsgWin  0x02190788  thumb  ov021
 *   STRBUF_Create  0x020457B0  arm
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F250  0x0201F250  thumb
 *   FIELD_MSGBG_MsgWinPrintStrColorFont  0x02190764  thumb  ov021
 *   FIELD_MSGBG_MsgWinPrintMsg  0x02190740  thumb  ov021
 *   STRBUF_Delete  0x02045808  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8 pad0[0xC];
    u16 heap;
    u8 padE[0xA0 - 0xE];
    u32 fA0;
    u32 fA4;
    u32 fA8;
    u32 fAC;
    u32 fB0;
    u32 fB4;
    u32 fB8;
} Obj;

extern void PARTY_SELECT_LIST_CreateListWindow(Obj *p);
struct MsgBank;
struct WordSet;
extern void FIELD_MSGBG_ClearMsgWin(u8 *p);
struct U16Vec;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern u32 POKEPARTY_GetCount(void *p);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern u32 POKE_TOOL_GetPartyValue(void *mon, u32 id, u32 v);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void FIELD_MSGBG_MsgWinPrintStrColorFont(u32 a, u16 b, u32 c, void *d, u16 e, u32 f);
extern int FIELD_MSGBG_MsgWinPrintMsg(u32 a, u32 b, u32 c, u32 d);
extern void STRBUF_Delete(struct U16Vec *vec);

void PARTY_SELECT_LIST_PrintPartyNames(Obj *p, void *party)
{
    void *buf1;
    void *buf2;
    int n;
    int i;
    void *mon;
    u32 v5;
    u32 v6e;
    u32 v9e;
    u32 vad;
    int x;

    PARTY_SELECT_LIST_CreateListWindow(p);
    FIELD_MSGBG_ClearMsgWin((u8 *)p->fB4);
    buf1 = STRBUF_Create(0x40, p->heap);
    buf2 = STRBUF_Create(0x40, p->heap);
    n = POKEPARTY_GetCount(party);
    for (i = 0; i < n; i++) {
        mon = POKEPARTY_GetMember(party, i);
        if (POKE_TOOL_GetPartyValue(mon, 0x4c, 0) != 0) {
            continue;
        }
        v5 = POKE_TOOL_GetPartyValue(mon, 5, 0);
        vad = POKE_TOOL_GetPartyValue(mon, 0xad, 0);
        v9e = POKE_TOOL_GetPartyValue(mon, 0x9e, 0);
        v6e = POKE_TOOL_GetPartyValue(mon, 0x6e, 0);
        MSGDATA_ReadString((struct MsgBank *)p->fA8, 4, buf2);
        func_0201EFA4((struct WordSet *)p->fA0, 0, v9e, 3, 0, 1);
        func_0201F250((struct WordSet *)p->fA0, buf1, buf2);
        x = i * 0x28;
        FIELD_MSGBG_MsgWinPrintStrColorFont(p->fB4, x, 0x20, buf1, 0x440, p->fB8);
        if (v6e == 2) {
            continue;
        }
        if ((v5 == 0x1d || v5 == 0x20) && vad == 0) {
            continue;
        }
        if (v6e == 0) {
            FIELD_MSGBG_MsgWinPrintMsg(p->fB4, (u16)(x + 0x1f), 0x10, 5);
        } else {
            FIELD_MSGBG_MsgWinPrintMsg(p->fB4, (u16)(x + 0x1f), 0x10, 6);
        }
    }
    STRBUF_Delete(buf1);
    STRBUF_Delete(buf2);
}
