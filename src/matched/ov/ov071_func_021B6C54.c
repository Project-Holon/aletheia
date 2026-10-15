/*
 * function: MONOLITH_TOOL_ResetHighlights
 * address: 0x021B6C54
 * packet: pkt_ov071_021B6C54
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 */
extern void MI_CpuFill8(void *, int, int);
void MONOLITH_TOOL_ResetHighlights(char *p) { int i; for(i=0;i<4;i++) MI_CpuFill8(p+12+i*8,0,8); }
