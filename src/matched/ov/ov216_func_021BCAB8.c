/*
 * function: BEACON_DETAIL_GRA_ExitBgSystem
 * address: 0x021BCAB8
 * packet: pkt_ov216_021BCAB8
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   d_021BDC28 0x021BDC28 data a4
 */
extern const unsigned char d_021BDC28[];
typedef unsigned int   u32;
extern void BG_SYS_FreeLayerBuf(u32 i);
extern void BMP_WIN_Exit(void);
extern void BG_SYS_Delete(void);
extern void MI_CpuFill8(void *,int,int);
void BEACON_DETAIL_GRA_ExitBgSystem(void *p){unsigned base=(unsigned)d_021BDC28;unsigned i;for(i=0;i<8;i++)BG_SYS_FreeLayerBuf((unsigned char)(*(const unsigned *)(base+i*44)));BMP_WIN_Exit();BG_SYS_Delete();MI_CpuFill8(p,0,4);}
