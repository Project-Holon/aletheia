/*
 * function: NHTTP_RAP_EvilCheckSetElement
 * address: 0x021B9A94
 * packet: pkt_ov114_021B9A94
 * region: ov114
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: Two zero bytes of alignment padding follow the return.
 * symbols:
 *   MI_CpuCopy8 0x02082D44 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void MI_CpuCopy8(int,int,int);
void NHTTP_RAP_EvilCheckSetElement(int p, int a, u32 b, int n) { MI_CpuCopy8(a,p+b*n,b); }
