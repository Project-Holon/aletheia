/*
 * function: func_021F8F88
 * address: 0x021F8F88
 * packet: pkt_ov185_021F8F88
 * region: ov185
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FD12C 0x021FD12C thumb ov186
 *   func_021FD170 0x021FD170 thumb ov186
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Pair;struct PrintSys;
extern void *func_021FD12C(int a, void *owner, u16 heap);
extern void func_021FD170(char *p, char *q, void *text);
void func_021F8F88(char *p,char *q) { if(!*(void **)(p+4))*(void **)(p+4)=func_021FD12C((int)(*(void **)(q+12)),(void *)(*(int *)(p+0x2c)),*(u16 *)(p+0x30));func_021FD170(*(void **)(p+4),*(void **)(q+12),(void *)0x146); }
