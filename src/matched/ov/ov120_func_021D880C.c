/*
 * function: GTSNEGO_MSG_PrintSummary
 * address: 0x021D880C
 * packet: pkt_ov120_021D880C
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GTSNEGO_MSG_PrintSingle 0x021D8784 thumb ov120
 *   GTSNEGO_MSG_PrintPair 0x021D8684 thumb ov120
 *   GTSNEGO_MSG_PrintTooltip 0x021D7F5C thumb ov120
 *   GTSNEGO_MSG_PrintEntry 0x021D7FD0 thumb ov120
 *   GTSNEGO_MSG_PrintWindowB 0x021D7A74 thumb ov120
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void GTSNEGO_MSG_PrintSingle(char *p, void *n);
extern void GTSNEGO_MSG_PrintPair(char *,int,u32);
extern void GTSNEGO_MSG_PrintTooltip(char *,u16);
extern void GTSNEGO_MSG_PrintEntry(char *,void *);
extern void GTSNEGO_MSG_PrintWindowB(u8 *p, int n);
void GTSNEGO_MSG_PrintSummary(char *p,void *q,u32 n)
{
    GTSNEGO_MSG_PrintSingle(p,(void *)q);
    GTSNEGO_MSG_PrintPair(p,36,n);
    GTSNEGO_MSG_PrintTooltip(p,41);
    GTSNEGO_MSG_PrintEntry(p,q);
    GTSNEGO_MSG_PrintWindowB((u8 *)p,17);
}
