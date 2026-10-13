/*
 * function: func_021B8ADC
 * address: 0x021B8ADC
 * packet: pkt_ov104_021B8ADC
 * region: ov104
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
void func_021B8ADC(void *p) { MI_CpuFill8(p,0,0x534); }
