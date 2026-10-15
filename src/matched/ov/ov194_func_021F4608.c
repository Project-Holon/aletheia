/*
 * function: NAMEIN_GRAPHIC_ClearCallback
 * address: 0x021F4608
 * packet: pkt_ov194_021F4608
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 */
extern void MI_CpuFill8(void *,int,int);
void NAMEIN_GRAPHIC_ClearCallback(void *p){MI_CpuFill8(p,0,16);}
