/*
 * function: GURU2_RECEIPT_StateShowTimeoutMessage
 * address: 0x021DDF84
 * packet: pkt_ov137_021DDF84
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GURU2_RECEIPT_PrintMessage 0x021DE4B4 thumb ov137
 *   GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 *   GURU2_RECEIPT_GetUnionApp 0x021DCF50 thumb ov137
 *   UNION_APP_GetMemberCount 0x021841A4 thumb ov022
 *   GURU2_RECEIPT_Noop 0x021DD924 thumb ov137
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void GURU2_RECEIPT_PrintMessage(char *, int, int);
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
extern void *GURU2_RECEIPT_GetUnionApp(u8 *);
extern int UNION_APP_GetMemberCount(u8 *);
extern void GURU2_RECEIPT_Noop(char *);
int GURU2_RECEIPT_StateShowTimeoutMessage(char *p, int state) {
    GURU2_RECEIPT_PrintMessage(p, 15, 1);
    *(int *)(p + 0x118) = 20;
    GFL_NET_SYSTEM_GetCurrentAid();
    *(int *)(p + 0x481C) = UNION_APP_GetMemberCount(GURU2_RECEIPT_GetUnionApp((u8 *)p));
    *(int *)(p + 0x4818) = 300;
    GURU2_RECEIPT_Noop(p);
    return state;
}
