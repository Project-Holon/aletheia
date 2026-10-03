/*
 * function: func_021B69C4
 * address: 0x021B69C4
 * packet: pkt_ov101_021B69C4
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02005E9C 0x02005E9C thumb
 *   func_02005DE4 0x02005DE4 thumb
 *   func_021B6148 0x021B6148 thumb ov101
 *   func_021B6C08 0x021B6C08 thumb ov101
 *   func_020307B0 0x020307B0 arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_02005E9C(int,int,int,int);
extern void func_02005DE4(void *);
extern void func_021B6148(void *);
extern void func_021B6C08(u8 *);
extern void func_020307B0(void *);
extern void func_020315D4(void *);
extern void func_020306F0(void *);
int func_021B69C4(int a,int b,int c,u8 *d) {
 func_02005E9C(a,b,c,(int)d); func_02005DE4(0); func_021B6148(*(void **)d); func_021B6C08(d+4); func_020307B0(*(void **)(d+60)); func_020315D4((void *)a); func_020306F0((void *)58); return 1;
}
