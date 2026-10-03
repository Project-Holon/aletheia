/*
 * function: func_021E2FE8
 * address: 0x021E2FE8
 * packet: pkt_ov183_021E2FE8
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021FD860 0x021FD860 thumb ov186
 *   func_021FD15C 0x021FD15C thumb ov186
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Pair;struct PrintSys;
extern void func_021FD860(char *,u32,const struct Pair *);
extern void func_021FD15C(void *,int);
void func_021E2FE8(char *p) { int zero=0;func_021FD860(*(char **)(p+0x30),0,0);if(*(void **)(p+8)){func_021FD15C(*(void **)(p+8),*(int *)(*(char **)(p+0x3c)+8));*(int *)(p+8)=zero;} }
