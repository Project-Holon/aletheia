/*
 * function: func_021BC5AC
 * address: 0x021BC5AC
 * packet: pkt_ov223_021BC5AC
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021BC9B0 0x021BC9B0 data a4
 *   func_020403F4 0x020403F4 arm
 *   func_020450C8 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_02082BCC 0x02082BCC arm
 */
extern unsigned char d_021BC9B0[];
extern void func_020403F4(unsigned char),func_020450C8(void),func_0203F9B4(void),func_02082BCC(void *,int,int);
void func_021BC5AC(void *p){unsigned i;for(i=0;i<7;i++)func_020403F4(*(unsigned *)(d_021BC9B0+i*44));func_020450C8();func_0203F9B4();func_02082BCC(p,0,4);}
