/*
 * function: func_021BF758
 * address: 0x021BF758
 * packet: pkt_ov203_021BF758
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * volatile: 021BF77E writes MMIO halfword at 04000050.
 * symbols:
 *   memset 0x02082BCC arm
 *   func_02040588 0x02040588 arm
 *   BG_SYS_SetVisibleLayer 0x0204047C arm
 *   BG_SYS_FreeSlot 0x020414AC arm
 */
extern void *memset(void *,int,unsigned);
typedef unsigned int   u32;
extern void func_02040588(unsigned char which, unsigned char enable);
extern void BG_SYS_SetVisibleLayer(int,unsigned short);
extern void BG_SYS_FreeSlot(unsigned char);
void func_021BF758(void *p){unsigned z=0;memset(p,0,0x2c);func_02040588(1,0);BG_SYS_SetVisibleLayer(0,0);BG_SYS_SetVisibleLayer(1,1);*(volatile unsigned short *)0x04000050=z;BG_SYS_FreeSlot(1);}
