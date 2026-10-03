/*
 * function: func_021B89B8
 * address: 0x021B89B8
 * packet: pkt_ov102_021B89B8
 * region: ov102
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B8868 0x021B8868 thumb ov102
 *   func_02082BCC 0x02082BCC arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021B8868(void *);
extern void func_02082BCC(void *,int,u32);
void func_021B89B8(u8 *p) { int i; for(i=0;i<*(u16 *)(p+846);i++)func_021B8868(p+i*28); func_02082BCC(p,0,848); }
