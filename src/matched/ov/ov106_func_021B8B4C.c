/*
 * function: func_021B8B4C
 * address: 0x021B8B4C
 * packet: pkt_ov106_021B8B4C
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void MI_CpuFill8(void *,int,int);
void func_021B8B4C(void *p) { MI_CpuFill8(p,0,384); }
