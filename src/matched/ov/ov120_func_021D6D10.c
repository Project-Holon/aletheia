/*
 * function: GTSNEGO_MSG_DrawTileRows
 * address: 0x021D6D10
 * packet: pkt_ov120_021D6D10
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two-byte zero alignment padding follows.
 * symbols:
 *   GTSNEGO_DISP_GetEntry 0x021D4F70 thumb ov120
 *   GTSNEGO_MSG_DrawTileRow 0x021D6C7C thumb ov120
 *   GTSNEGO_MSG_FillTileRow 0x021D6CCC thumb ov120
 *   func_02041B6C 0x02041B6C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *GTSNEGO_DISP_GetEntry(void **p, int i);
extern void GTSNEGO_MSG_DrawTileRow(u8 *,int);
extern void GTSNEGO_MSG_FillTileRow(u8 *,int);
extern void func_02041B6C(u32 bit);
void GTSNEGO_MSG_DrawTileRows(u8 *p,void *list,int first){int i;for(i=0;i<6;i++){if(GTSNEGO_DISP_GetEntry(list,first+i))GTSNEGO_MSG_DrawTileRow(p,i);else GTSNEGO_MSG_FillTileRow(p,i);}func_02041B6C(4);}
