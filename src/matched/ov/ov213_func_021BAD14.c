/*
 * function: COMM_BTL_DEMO_GRAPHIC_DeleteBg
 * address: 0x021BAD14
 * packet: pkt_ov213_021BAD14
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   d_021BB1F8 0x021BB1F8 data a4
 */
extern const unsigned d_021BB1F8[][11];
typedef unsigned int   u32;
extern void BG_SYS_FreeLayerBuf(u32 i);
extern void BMP_WIN_Exit(void);
extern void BG_SYS_Delete(void);
extern void MI_CpuFill8(void *,unsigned,unsigned);
void COMM_BTL_DEMO_GRAPHIC_DeleteBg(void *p){unsigned i;for(i=0;i<6;i++)BG_SYS_FreeLayerBuf((unsigned char)d_021BB1F8[i][0]);BMP_WIN_Exit();BG_SYS_Delete();MI_CpuFill8(p,0,4);}
