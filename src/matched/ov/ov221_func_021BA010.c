/*
 * function: CHIHOU_ZUKAN_AWARD_GRAPHIC_CleanupBg
 * address: 0x021BA010
 * packet: pkt_ov221_021BA010
 * region: ov221
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * shape: unsigned table address is bound before the unsigned loop counter; raw stride remains 44 bytes.
 * symbols:
 *   func_020403F4 0x020403F4 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   d_021BA250 0x021BA250 data a4
 */
extern unsigned char d_021BA250[];extern void func_020403F4(unsigned char);extern void BMP_WIN_Exit(void),BG_SYS_Delete(void);extern void MI_CpuFill8(void *,int,unsigned);
void CHIHOU_ZUKAN_AWARD_GRAPHIC_CleanupBg(void *p){unsigned base=(unsigned)d_021BA250;unsigned i;for(i=0;i<2;i++)func_020403F4(*(unsigned *)(base+i*44));BMP_WIN_Exit();BG_SYS_Delete();MI_CpuFill8(p,0,4);}
