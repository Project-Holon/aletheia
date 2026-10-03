/*
 * function: func_021F8E60
 * address: 0x021F8E60
 * packet: pkt_ov185_021F8E60
 * region: ov185
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FBDA4 0x021FBDA4 thumb ov186
 *   func_021FB494 0x021FB494 thumb ov186
 *   func_021FC734 0x021FC734 thumb ov186
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Pair;struct PrintSys;
extern void func_021FBDA4(int,unsigned);
extern void func_021FB494(void *);
extern void func_021FC734(void *);
void func_021F8E60(char *p,char *q) { if(*(void **)(p+0x1c)){func_021FBDA4(*(int *)(q+12),22);func_021FB494(*(void **)(p+0x18));*(void **)(p+0x18)=0;func_021FC734(*(void **)(p+0x1c));*(void **)(p+0x1c)=0;func_021FBDA4(*(int *)(q+12),22);} }
