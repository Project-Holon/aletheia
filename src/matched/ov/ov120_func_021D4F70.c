/*
 * function: GTSNEGO_DISP_GetEntry
 * address: 0x021D4F70
 * packet: pkt_ov120_021D4F70
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAME_DATA_GetSaveBlock1F 0x02012F14 thumb
 *   func_02009E8C 0x02009E8C thumb
 *   func_02009E54 0x02009E54 thumb

 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *GAME_DATA_GetSaveBlock1F(void **); extern int func_02009E8C(void *); extern void *func_02009E54(void *,int);
void *GTSNEGO_DISP_GetEntry(void **p,int i) { int n; n=func_02009E8C(GAME_DATA_GetSaveBlock1F(p)); if (i>=n || i<0) return 0; return func_02009E54(GAME_DATA_GetSaveBlock1F(p),i); }
