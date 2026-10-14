/*
 * function: GURU2_RECEIPT_StateInit
 * address: 0x021DD79C
 * packet: pkt_ov137_021DD79C
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 *   GFL_NET_SetAutoExit 0x0203D7B0 arm
 *   GURU2_RECEIPT_GetUnionApp 0x021DCF50 thumb ov137
 *   UNION_APP_GetMemberCount 0x021841A4 thumb ov022
 *   GURU2_RECEIPT_PrintMessage 0x021DE4B4 thumb ov137
 *   GURU2_RECEIPT_SetPendingState 0x021DD93C thumb ov137
 */
typedef unsigned short u16;
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
extern void GFL_NET_SetAutoExit(unsigned char a0);
typedef unsigned char  u8;
extern void *GURU2_RECEIPT_GetUnionApp(u8 *p);
extern int UNION_APP_GetMemberCount(unsigned char *p);
extern void GURU2_RECEIPT_PrintMessage(char *, int, int);
extern void GURU2_RECEIPT_SetPendingState(char *, int);
int GURU2_RECEIPT_StateInit(char *p, int state) {
    if (GFL_NET_SYSTEM_GetCurrentAid() == 0) {
        int zero = 0;
        GFL_NET_SetAutoExit(0);
        if ((unsigned)UNION_APP_GetMemberCount(GURU2_RECEIPT_GetUnionApp((u8 *)p)) >= 2)
            GURU2_RECEIPT_PrintMessage(p, 2, zero);
    } else {
        GFL_NET_SetAutoExit(1);
        GURU2_RECEIPT_PrintMessage(p, 8, 0);
    }
    GURU2_RECEIPT_SetPendingState(p, 3);
    return state;
}
