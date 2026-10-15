/*
 * function: GTSNEGO_MSG_PrintList
 * address: 0x021D81E0
 * packet: pkt_ov120_021D81E0
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GTSNEGO_MSG_CreateRow 0x021D7C48 thumb ov120
 *   GTSNEGO_DISP_GetEntry 0x021D4F70 thumb ov120
 *   GTSNEGO_MSG_PrintListEntry 0x021D8118 thumb ov120
 *   func_02041B6C 0x02041B6C arm
 *   GF_FONT_SetTextColor  0x0201DD78  thumb  arm9
 */
typedef unsigned int   u32;
extern void GF_FONT_SetTextColor(u32 r, u32 g, u32 b);
typedef unsigned char  u8;
extern int GTSNEGO_MSG_CreateRow(u8 *p, int n, int a, int b, int c, int d);
extern void *GTSNEGO_DISP_GetEntry(void **p, int i);
extern int GTSNEGO_MSG_PrintListEntry(char *p, void *r, int n);
extern void func_02041B6C(u32 bit);
void GTSNEGO_MSG_PrintList(char *p,void *q)
{
    int i;
    void *r;
    GF_FONT_SetTextColor(15,2,0);
    GTSNEGO_MSG_CreateRow((u8 *)p,30,0,0,20,5);
    for(i=0;i<3;i++) {
        r=GTSNEGO_DISP_GetEntry(q,i);
        if(r) GTSNEGO_MSG_PrintListEntry(p,r,i+2);
    }
    func_02041B6C(5);
}
