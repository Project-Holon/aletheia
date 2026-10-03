/*
 * function: func_021B9A94
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
 *   func_02082D44 0x02082D44 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_02082D44(int,int,int);
void func_021B9A94(int p,int a,int b,int n) { func_02082D44(a,p+b*n,b); }
