/*
 * function: func_021B87BC
 * address: 0x021B87BC
 * packet: pkt_ov102_021B87BC
 * region: ov102
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
extern void MI_CpuFill8(void *, int, u32);
void func_021B87BC(void *p) { MI_CpuFill8(p,0,28); }
