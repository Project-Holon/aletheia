/*
 * function: func_021F8F58
 * address: 0x021F8F58
 * packet: pkt_ov185_021F8F58
 * region: ov185
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FFE70 0x021FFE70 thumb ov186
 *   func_021FFC6C 0x021FFC6C thumb ov186
 *   func_020409B4 0x020409B4 arm
 *   func_021FD15C 0x021FD15C thumb ov186
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Pair;struct PrintSys;
extern void func_021FFE70(void *);
extern void func_021FFC6C(void *);
extern void func_020409B4(unsigned);
extern void func_021FD15C(void *,int);
void func_021F8F58(char *p,char *q) { if(*(void **)p){func_021FFE70(*(void **)p);func_021FFC6C(*(void **)p);*(void **)p=0;func_020409B4(4);if(*(void **)(p+4)){func_021FD15C(*(void **)(p+4),*(int *)(q+12));*(void **)(p+4)=0;}} }
