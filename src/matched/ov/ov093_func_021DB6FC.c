/*
 * function: HAND_TOKUSEI_Klutz_NoticeHeldItem
 * address: 0x021DB6FC
 * packet: pkt_ov093_021DB6FC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_SERVER_FLOW_GetPokeParam 0x021C7CF4 thumb ov093
 *   BTL_POKEPARAM_GetItem 0x021D5B40 thumb ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord 0x021C88A4 thumb ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord 0x021C88C8 thumb ov093
 */
extern int BTL_EVENT_GetVar(int);
typedef unsigned short u16;
struct QI;
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern u16 BTL_POKEPARAM_GetItem(struct QI *p);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *,void *);
void HAND_TOKUSEI_Klutz_NoticeHeldItem(int a,void *b,int c) { unsigned char *p; if(c==BTL_EVENT_GetVar(2) && BTL_POKEPARAM_GetItem(BTL_SERVER_FLOW_GetPokeParam(b,c))) { p=BTL_SERVER_FLOW_AllocCmdRecord(b,0x21,c); p[4]=c; BTL_SERVER_FLOW_CommitCmdRecord(b,p); } }
