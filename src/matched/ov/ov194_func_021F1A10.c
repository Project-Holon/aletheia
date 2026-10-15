/*
 * function: NAMEIN_GRAPHIC_ClearCursor
 * address: 0x021F1A10
 * packet: pkt_ov194_021F1A10
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void MI_CpuFill8(void *,int,int);
void NAMEIN_GRAPHIC_ClearCursor(void *p) { MI_CpuFill8(p,0,180); }
