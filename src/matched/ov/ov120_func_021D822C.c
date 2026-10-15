/*
 * function: GTSNEGO_MSG_PrintListEntryAt
 * address: 0x021D822C
 * packet: pkt_ov120_021D822C
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing 2-byte alignment padding only.
 * symbols:
 *   GTSNEGO_DISP_GetEntry 0x021D4F70 thumb ov120
 *   GTSNEGO_MSG_PrintListEntry 0x021D8118 thumb ov120
 *   func_02041B6C 0x02041B6C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void *GTSNEGO_DISP_GetEntry(void **p, int i);
extern int GTSNEGO_MSG_PrintListEntry(char *p, void *r, int n);
extern void func_02041B6C(u32);
void GTSNEGO_MSG_PrintListEntryAt(char *p,void *q,int index) { GTSNEGO_MSG_PrintListEntry(p,GTSNEGO_DISP_GetEntry(q,index),5); func_02041B6C(6); }
