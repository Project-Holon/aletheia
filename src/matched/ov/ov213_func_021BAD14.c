/*
 * function: func_021BAD14
 * address: 0x021BAD14
 * packet: pkt_ov213_021BAD14
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020403F4 0x020403F4 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   d_021BB1F8 0x021BB1F8 data a4
 */
extern const unsigned d_021BB1F8[][11];
typedef unsigned int   u32;
extern void func_020403F4(u32 i);
extern void BMP_WIN_Exit(void);
extern void func_0203F9B4(void);
extern void MI_CpuFill8(void *,unsigned,unsigned);
void func_021BAD14(void *p){unsigned i;for(i=0;i<6;i++)func_020403F4((unsigned char)d_021BB1F8[i][0]);BMP_WIN_Exit();func_0203F9B4();MI_CpuFill8(p,0,4);}
