/*
 * function: func_021BCAB8
 * address: 0x021BCAB8
 * packet: pkt_ov216_021BCAB8
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020403F4 0x020403F4 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   d_021BDC28 0x021BDC28 data a4
 */
extern const unsigned char d_021BDC28[];
typedef unsigned int   u32;
extern void func_020403F4(u32 i);
extern void BMP_WIN_Exit(void);
extern void func_0203F9B4(void);
extern void MI_CpuFill8(void *,int,int);
void func_021BCAB8(void *p){unsigned base=(unsigned)d_021BDC28;unsigned i;for(i=0;i<8;i++)func_020403F4((unsigned char)(*(const unsigned *)(base+i*44)));BMP_WIN_Exit();func_0203F9B4();MI_CpuFill8(p,0,4);}
