/*
 * function: func_021BA010
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
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_02082BCC 0x02082BCC arm
 *   d_021BA250 0x021BA250 data a4
 */
extern unsigned char d_021BA250[];extern void func_020403F4(unsigned char);extern void BMP_WIN_Exit(void),func_0203F9B4(void);extern void func_02082BCC(void *,int,unsigned);
void func_021BA010(void *p){unsigned base=(unsigned)d_021BA250;unsigned i;for(i=0;i<2;i++)func_020403F4(*(unsigned *)(base+i*44));BMP_WIN_Exit();func_0203F9B4();func_02082BCC(p,0,4);}
