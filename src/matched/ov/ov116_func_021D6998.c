/*
 * function: WIFI_BSUBWAY_ClearTrainers
 * address: 0x021D6998
 * packet: pkt_ov116_021D6998
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 */
extern void MI_CpuFill8(void *,int,unsigned int);
void WIFI_BSUBWAY_ClearTrainers(void *a) { MI_CpuFill8(a,0,0xa9c); }
