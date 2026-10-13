/*
 * function: P_STA_INFO_AllocWork
 * address: 0x021D7B00
 * packet: pkt_ov131_021D7B00
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   POKE_PERSONAL_LoadFormTable 0x0201AF80 thumb
 *   d_021DC824 0x021DC824 data a1
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u16 *POKE_PERSONAL_LoadFormTable(u32 heap, u16 *countOut);
extern const char d_021DC824[];
void **P_STA_INFO_AllocWork(u16 *a) {
 void **p=func_02030734(*a,0x6c,0,d_021DC824,0xc1);
 p[0]=0;
 p[1]=0;
 p[2]=POKE_PERSONAL_LoadFormTable(*a,0);
 return p;
}
