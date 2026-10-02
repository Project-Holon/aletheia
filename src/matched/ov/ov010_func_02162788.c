/*
 * function: func_02162788
 * address: 0x02162788
 * packet: pkt_ov010_02162788
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 */
typedef unsigned short u16;
void func_02162788(char *p, unsigned i, u16 v) { if(i < *(u16 *)(p+0x14)) *(u16 *)(*(char **)(p+0x20)+i*0x24+10)=v; }
