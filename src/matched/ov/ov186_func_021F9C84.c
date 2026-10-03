/*
 * function: func_021F9C84
 * address: 0x021F9C84
 * packet: pkt_ov186_021F9C84
 * region: ov186
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
struct Pair;struct PrintSys;
extern void func_02082BCC(void *,int,unsigned);
void func_021F9C84(char *p,int a,int b) { int zero=0;func_02082BCC(p,0,16);*(int *)p=1;*(int *)(p+4)=zero;*(int *)(p+12)=a;*(int *)(p+8)=b; }
