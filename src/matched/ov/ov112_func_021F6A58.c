/*
 * function: STA_ACT_OBJ_Update
 * address: 0x021F6A58
 * packet: pkt_ov112_021F6A58
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Load adds the index before offset eight; the call adds offset eight before the index.
 * symbols:
 *   STA_ACT_OBJ_UpdateEntry 0x021F6A80 thumb ov112
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void STA_ACT_OBJ_UpdateEntry(char *,u32 *);
void STA_ACT_OBJ_Update(char *p) {int i;for(i=0;i<5;i++)if(*(u32 *)(p+i*28+8)==1)STA_ACT_OBJ_UpdateEntry(p,(u32 *)(p+8+i*28));}
