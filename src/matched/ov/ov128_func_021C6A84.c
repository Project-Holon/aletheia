/*
 * function: func_021C6A84
 * address: 0x021C6A84
 * packet: pkt_ov128_021C6A84
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02049EF4 0x02049EF4 arm
 *   d_021CA4F5 0x021CA4F5 data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern const u8 d_021CA4F5[];
extern void *func_02049EF4(void *, u32, u32, void **, u16);
void func_021C6A84(u8 *p,u16 heap) {int i;for(i=0;i<2;i++) *(void **)(p+0x16c+i*4)=func_02049EF4(*(void **)(p+8),d_021CA4F5[i],0,(void **)(p+0x174+i*4),heap);}
