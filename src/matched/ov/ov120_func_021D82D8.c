/*
 * function: GTSNEGO_MSG_PrintListEntryN
 * address: 0x021D82D8
 * packet: pkt_ov120_021D82D8
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent remainder: two-byte zero alignment padding.
 * symbols:
 *   GTSNEGO_DISP_GetEntry 0x021D4F70 thumb ov120
 *   GTSNEGO_MSG_PrintListEntry 0x021D8118 thumb ov120
 *   func_02041B6C 0x02041B6C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *GTSNEGO_DISP_GetEntry(void **p, int i);
extern int GTSNEGO_MSG_PrintListEntry(char *p, void *r, int n);
extern void func_02041B6C(u32 bit);
void GTSNEGO_MSG_PrintListEntryN(char *p,void *q,int n)
{
    GTSNEGO_MSG_PrintListEntry(p,GTSNEGO_DISP_GetEntry(q,n),0);
    func_02041B6C(6);
}
