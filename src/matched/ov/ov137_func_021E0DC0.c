/*
 * function: GURU2_MAIN_BounceEffectTask
 * address: 0x021E0DC0
 * packet: pkt_ov137_021E0DC0
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GURU2_MAIN_UpdateBounceEffect 0x021E0D50 thumb ov137
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void GURU2_MAIN_UpdateBounceEffect(char *,int *);
void GURU2_MAIN_BounceEffectTask(void *unused,char *p) { int i; int *q; q=(int *)(p+0xaf8); for(i=0;i<5;i++,q+=8) if(*q!=0) GURU2_MAIN_UpdateBounceEffect(p,q); }
