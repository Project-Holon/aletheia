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
 *   BMP_WIN_Exit 0x020450C8 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   MI_CpuFill8 0x02082BCC arm
 */
extern unsigned char d_021BC9B0[];
typedef unsigned int   u32;
extern void func_020403F4(u32 i);
extern void BMP_WIN_Exit(void);
extern void BG_SYS_Delete(void);
extern void MI_CpuFill8(void *,int,int);
void func_021BC5AC(void *p){unsigned i;for(i=0;i<7;i++)func_020403F4((unsigned char)(*(unsigned *)(d_021BC9B0+i*44)));BMP_WIN_Exit();BG_SYS_Delete();MI_CpuFill8(p,0,4);}
