/*
 * function: GURU2_RECEIPT_CountMembers
 * address: 0x021DE220
 * packet: pkt_ov137_021DE220
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   GURU2_RECEIPT_GetUnionApp 0x021DCF50 thumb ov137
 *   UNION_APP_GetMemberEntry 0x02184180 thumb ov022
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *GURU2_RECEIPT_GetUnionApp(u8 *p);
extern char *UNION_APP_GetMemberEntry(unsigned char *p, int i);
int GURU2_RECEIPT_CountMembers(void *p) {int i,n;n=0;for(i=0;i<5;i++) if(UNION_APP_GetMemberEntry(GURU2_RECEIPT_GetUnionApp(p),(u8)i)) n++;return n;}
