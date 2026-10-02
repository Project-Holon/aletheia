/*
 * function: func_02162774
 * address: 0x02162774
 * packet: pkt_ov010_02162774
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 */
typedef unsigned short u16;
void func_02162774(char *p, unsigned i, u16 v) { if(i < *(u16 *)(p+0x14)) *(u16 *)(*(char **)(p+0x20)+i*0x24+2)=v; }
