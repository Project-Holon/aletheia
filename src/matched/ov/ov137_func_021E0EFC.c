/*
 * function: GURU2_MAIN_SettleEffectTask
 * address: 0x021E0EFC
 * packet: pkt_ov137_021E0EFC
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GURU2_MAIN_UpdateSettleEffect 0x021E0EAC thumb ov137
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void GURU2_MAIN_UpdateSettleEffect(int *);
void GURU2_MAIN_SettleEffectTask(void *unused,char *p) { int i; int *q; q=(int *)(p+0xb98); for(i=0;i<5;i++,q+=5) if(*q!=0) GURU2_MAIN_UpdateSettleEffect(q); }
