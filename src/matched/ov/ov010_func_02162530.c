/*
 * function: func_02162530
 * address: 0x02162530
 * packet: pkt_ov010_02162530
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 */
typedef unsigned short u16;
extern void func_02082BCC(void *, int, int);
void func_02162530(char *p) { *(u16 *)(p+0x2c)=0; *(u16 *)(p+0x2e)=0; *(u16 *)(p+0x30)=0; *(u16 *)(p+0x32)=0; *(u16 *)(p+0x12)=0; *(u16 *)(p+0x14)=0; *(u16 *)(p+0x16)=0; *(u16 *)(p+0x18)=0; *(unsigned *)(p+0x1c)=0; *(unsigned *)(p+0x20)=0; *(unsigned *)(p+0x24)=0; *(unsigned *)(p+0x28)=0; func_02082BCC(p+0x128,0,0x880); }
