/*
 * function: P_STA_SUB_Create
 * address: 0x021D65D8
 * packet: pkt_ov131_021D65D8
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   P_STA_SUB_FileName 0x021DC818 data a1
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern const char P_STA_SUB_FileName[];
void P_STA_SUB_Create(u16 *a) {
 u32 *p=func_02030734(*a,0x9c,1,P_STA_SUB_FileName,0x10d);
 p[0]=0;
 p[1]=0;
 p[27]=0;
 p[3]=1;
 p[2]=0;
 p[23]=0;
}
