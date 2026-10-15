/*
 * function: ZUKAN_TOROKU_GRAPHIC_ExitBg
 * address: 0x0220B4A8
 * packet: pkt_ov207_0220B4A8
 * region: ov207
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020403F4 0x020403F4 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   d_0220BB18 0x0220BB18 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_020403F4(u32 i);
extern void BMP_WIN_Exit(void);
extern void BG_SYS_Delete(void);
extern void MI_CpuFill8(void*,int,u32);
extern const u8 d_0220BB18[];
void ZUKAN_TOROKU_GRAPHIC_ExitBg(void*p){u32 i;for(i=0;i<4;i++)func_020403F4((u8)(*(u32*)(d_0220BB18+i*44)));BMP_WIN_Exit();BG_SYS_Delete();MI_CpuFill8(p,0,4);}
