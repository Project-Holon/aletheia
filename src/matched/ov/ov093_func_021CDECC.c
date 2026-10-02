/*
 * function: func_021CDECC
 * address: 0x021CDECC
 * packet: pkt_ov093_021CDECC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021CDF1C 0x021CDF1C thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_021CDF1C(u8 *);
extern int func_021D59B4(void *,int);
void func_021CDECC(u8 *p) { void *a; a=func_021CDF1C(p); if(a) *(u16 *)(p+0x19c)=func_021D59B4(a,13); }
