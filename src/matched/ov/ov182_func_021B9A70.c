/*
 * unit: no
 * function: THE_END_GRAPHIC_ExitWindows
 * address: 0x021B9A70
 * packet: pkt_ov182_021B9A70
 * region: ov182
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
 *   d_021B9C78 0x021B9C78 data a4
 */
typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
typedef struct {u32 id;u32 v[8];u32 a,b;} Record;
extern const Record d_021B9C78[];
extern void BG_SYS_FreeLayerBuf(u32 i);
extern void BMP_WIN_Exit(void),BG_SYS_Delete(void),MI_CpuFill8(void *,int,int);
void THE_END_GRAPHIC_ExitWindows(void *p){u32 i;for(i=0;i<2;i++)BG_SYS_FreeLayerBuf((u8)d_021B9C78[i].id);BMP_WIN_Exit();BG_SYS_Delete();MI_CpuFill8(p,0,4);}
