/*
 * function: PARTY_SELECT_LIST_Main
 * address:  0x021CC810
 * packet:   pkt_ov021_021CC810
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Task state machine on the byte at +0xc0. The inner switch on an unsigned
 * result (cases 2, -2, -1) is what gives the compare order 2, -2, -1 and
 * the dead second -1 test.
 *
 * symbols:
 *   PARTY_SELECT_LIST_CreateTextWindow  0x021CCFC0  thumb  ov021
 *   PARTY_SELECT_LIST_PrintText  0x021CCFE4  thumb  ov021
 *   PARTY_SELECT_LIST_IsTextDone  0x021CCFF8  thumb  ov021
 *   PARTY_SELECT_LIST_CreateMenu  0x021CCEFC  thumb  ov021
 *   FIELD_MSGBG_IsPrintQueFinished  0x0219049C  thumb  ov021
 *   PARTY_SELECT_LIST_GetMenuResult  0x021CCF54  thumb  ov021
 *   PARTY_SELECT_LIST_ProcessMenu  0x021CCF48  thumb  ov021
 *   PARTY_SELECT_LIST_HideParty  0x021CD1AC  thumb  ov021
 *   PARTY_SELECT_LIST_DeleteTextWindow  0x021CCFD8  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Obj {
    u8 pad0[0xa4];
    u32 fA4;
    u8 padA8[0xbc - 0xa8];
    u32 fBC;
    u8 fC0;
    u8 fC1;
} Obj;

extern void PARTY_SELECT_LIST_CreateTextWindow(Obj *p);
extern int PARTY_SELECT_LIST_PrintText(u32 a, u32 b);
extern int PARTY_SELECT_LIST_IsTextDone(u8 *p);
extern void PARTY_SELECT_LIST_CreateMenu(u8 *p);
extern int FIELD_MSGBG_IsPrintQueFinished(u8 *p);
extern u32 PARTY_SELECT_LIST_GetMenuResult(u8 *p);
extern void PARTY_SELECT_LIST_ProcessMenu(u8 *p);
extern void PARTY_SELECT_LIST_HideParty(Obj *p);
extern void PARTY_SELECT_LIST_DeleteTextWindow(u8 *p);

int PARTY_SELECT_LIST_Main(Obj *p)
{
    u32 r;

    switch (p->fC0) {
    case 0:
        PARTY_SELECT_LIST_CreateTextWindow(p);
        PARTY_SELECT_LIST_PrintText((u32)p, 3);
        p->fC0 = p->fC0 + 1;
        break;
    case 1:
        if (PARTY_SELECT_LIST_IsTextDone((u8 *)p) == 1) {
            PARTY_SELECT_LIST_CreateMenu((u8 *)p);
            p->fC0 = p->fC0 + 1;
        }
        break;
    case 2:
        if (FIELD_MSGBG_IsPrintQueFinished((u8 *)p->fA4) == 1) {
            r = PARTY_SELECT_LIST_GetMenuResult((u8 *)p);
            if (r == -1)
                break;
            PARTY_SELECT_LIST_ProcessMenu((u8 *)p);
            PARTY_SELECT_LIST_HideParty(p);
            PARTY_SELECT_LIST_DeleteTextWindow((u8 *)p);
            switch (r) {
            case 2:
            case -2:
                p->fBC = 2;
                p->fC0 = p->fC0 + 1;
                break;
            case -1:
                break;
            default:
                p->fBC = r;
                p->fC0 = p->fC0 + 1;
                break;
            }
        }
        break;
    default:
        p->fC1 = 1;
        return 1;
    }
    return 0;
}
