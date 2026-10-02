/*
 * function: func_021BAF74
 * address: 0x021BAF74
 * packet: pkt_ov072_021BAF74
 * region: ov072
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_02082BCC(void *,int,int);
void func_021BAF74(u8 *p,u8 a,u8 b) { u16 z=0; func_02082BCC(p,0,0x38); p[0]=a; p[1]=b; *(u32 *)(p+0x14)=0x1000; *(u16 *)(p+4)=z; *(u16 *)(p+6)=z; *(u16 *)(p+8)=z; *(u16 *)(p+10)=z; }
