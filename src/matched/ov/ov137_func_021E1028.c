/*
 * function: GURU2_MAIN_WobbleEffectTask
 * address: 0x021E1028
 * packet: pkt_ov137_021E1028
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GURU2_MAIN_UpdateWobbleEffect 0x021E0FAC thumb ov137
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void GURU2_MAIN_UpdateWobbleEffect(int *);
void GURU2_MAIN_WobbleEffectTask(void *unused,char *p) { int i; int *q; q=(int *)(p+0xbfc); for(i=0;i<5;i++,q+=6) if(*q!=0) GURU2_MAIN_UpdateWobbleEffect(q); }
