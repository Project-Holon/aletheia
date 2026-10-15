/*
 * function: EVENT_COMM_COMMON_ExitMsgBox
 * address:  0x0217F318
 * packet:   pkt_ov018_0217F318
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   EVENT_COMM_COMMON_DeletePrintWin  0x0217F390  thumb
 *   EVENT_COMM_COMMON_DeleteListWindowB  0x0217F58C  thumb
 *   EVENT_COMM_COMMON_DeleteListWindow  0x0217F45C  thumb
 *   FIELD_MSGBG_DeleteSysWin  0x02190E40  thumb  ov021
 *   FIELD_MSGBG_DeleteMsgData  0x021904C8  thumb  ov021
 *   STRBUF_Delete  0x02045808  arm
 *   WORDSET_DeleteStrbufED04  0x0201ED04  thumb
 */

typedef struct {
    void *f00;
    void *f04;
    void *f08;
    void *f0C;
    void *f10;
    void *f14;
    void *f18;
    void *f1C;
    void *f20;
    void *f24;
    unsigned char f28;
    unsigned char pad29[3];
    void *f2C;
} Ov018Obj;

void EVENT_COMM_COMMON_DeletePrintWin(Ov018Obj *p);
void EVENT_COMM_COMMON_DeleteListWindowB(Ov018Obj *p);
void EVENT_COMM_COMMON_DeleteListWindow(Ov018Obj *p);
typedef unsigned int   u32;
int FIELD_MSGBG_DeleteSysWin(u32 a);
struct Rec;
u32 FIELD_MSGBG_DeleteMsgData(struct Rec *a0);
struct U16Vec;
struct WordSet;
void STRBUF_Delete(struct U16Vec *vec);
u32 WORDSET_DeleteStrbufED04(struct WordSet *p);

void EVENT_COMM_COMMON_ExitMsgBox(Ov018Obj *p)
{
    EVENT_COMM_COMMON_DeletePrintWin(p);
    EVENT_COMM_COMMON_DeleteListWindowB(p);
    EVENT_COMM_COMMON_DeleteListWindow(p);
    if (p->f00 != 0) {
        if (p->f18 != 0) {
            FIELD_MSGBG_DeleteSysWin((u32)p->f18);
            p->f18 = 0;
        }
        FIELD_MSGBG_DeleteMsgData(p->f0C);
        FIELD_MSGBG_DeleteMsgData(p->f10);
        FIELD_MSGBG_DeleteMsgData(p->f14);
        STRBUF_Delete(p->f08);
        STRBUF_Delete(p->f04);
        WORDSET_DeleteStrbufED04(p->f00);
        p->f00 = 0;
    }
}
