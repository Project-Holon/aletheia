/*
 * function: BR_GRAPHIC_ExitBgWindows
 * address: 0x021FC55C
 * packet: pkt_ov186_021FC55C
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   d_0220099C 0x0220099C data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {u32 id;u8 rest[40];} Record;
extern const Record d_0220099C[];
extern void BG_SYS_FreeLayerBuf(u32),BMP_WIN_Exit(void),BG_SYS_Delete(void),MI_CpuFill8(void*,int,u32);
void BR_GRAPHIC_ExitBgWindows(void*p){u32 i;for(i=0;i<7;i++)BG_SYS_FreeLayerBuf((u8)d_0220099C[i].id);BMP_WIN_Exit();BG_SYS_Delete();MI_CpuFill8(p,0,4);}
