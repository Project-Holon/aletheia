/*
 * function: func_021E31AC
 * address: 0x021E31AC
 * packet: pkt_ov183_021E31AC
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FD15C 0x021FD15C thumb ov186
 *   func_021FB494 0x021FB494 thumb ov186
 *   func_021FC0C8 0x021FC0C8 thumb ov186
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Pair;struct PrintSys;
extern void func_021FD15C(void *,int);
extern void func_021FB494(void *);
extern void func_021FC0C8(char *,unsigned);
void func_021E31AC(char *p,char *q) { int i;char *s;if(*(void **)(p+8)){func_021FD15C(*(void **)(p+8),*(int *)(q+8));*(int *)(p+8)=0;}for(i=0;i<4;i++){s=p+i*4;if(*(void **)(s+0x14)){func_021FB494(*(void **)(s+0x14));*(void **)(s+0x14)=0;}}func_021FC0C8(*(char **)(q+8),1); }
