/*
 * function: GURU2_RECEIPT_StateShowQuitMessage
 * address: 0x021DDE24
 * packet: pkt_ov137_021DDE24
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 *   GURU2_RECEIPT_GetUnionApp 0x021DCF50 thumb ov137
 *   UNION_APP_GetMemberEntry 0x02184180 thumb ov022
 *   WORDSET_SetSlotMyStatus 0x0201F02C thumb
 *   GURU2_RECEIPT_PrintMessage 0x021DE4B4 thumb ov137
 *   GURU2_RECEIPT_SetPendingState 0x021DD93C thumb ov137
 *   GURU2_RECEIPT_Noop 0x021DD924 thumb ov137
 */
#include "../include/Obj14216.h"
typedef unsigned short u16;
typedef unsigned int   u32;
struct WordSet;
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
typedef unsigned char  u8;
extern void *GURU2_RECEIPT_GetUnionApp(u8 *p);
extern char *UNION_APP_GetMemberEntry(unsigned char *p, int i);
extern void WORDSET_SetSlotMyStatus(struct WordSet *p, u32 i, void *a);
extern void GURU2_RECEIPT_PrintMessage(char *, int, int);
extern void GURU2_RECEIPT_SetPendingState(char *, int);
extern void GURU2_RECEIPT_Noop(char *);
int GURU2_RECEIPT_StateShowQuitMessage(char *p, int state) {
    if (GFL_NET_SYSTEM_GetCurrentAid() == 0) {
        GURU2_RECEIPT_PrintMessage(p, 5, 0);
    } else {
        WORDSET_SetSlotMyStatus(((struct Obj14216 *)p)->f3C, 0, UNION_APP_GetMemberEntry(GURU2_RECEIPT_GetUnionApp((u8 *)p), 0));
        GURU2_RECEIPT_PrintMessage(p, 0x10, 0);
    }
    GURU2_RECEIPT_SetPendingState(p, 0xe);
    ((struct Obj14216 *)p)->f124 = 0;
    GURU2_RECEIPT_Noop(p);
    return state;
}
