/*
 * function: func_021CDF1C
 * address: 0x021CDF1C
 * packet: pkt_ov093_021CDF1C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Prototype: original narrows getter result to u8 before 021B9920;
 * caller extern has u8 second argument; named u8 local keeps shift in r0.
 * symbols:
 *   func_021B8588 0x021B8588 thumb ov093
 *   func_021B86C0 0x021B86C0 thumb ov093
 *   func_021B9064 0x021B9064 thumb ov093
 *   func_021B9920 0x021B9920 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_021B8588(void **);
extern u8 func_021B86C0(u8 **);
extern u32 func_021B9064(u8 *,u8,int);
extern void *func_021B9920(char *,u8,u32);
void *func_021CDF1C(u8 *p) { u8 side; if(func_021B8588(*(void ***)p)==0 && func_021B86C0(*(u8 ***)p)==0) { side=func_021B9064(*(u8 **)p,p[0x1a6],0); return func_021B9920(*(char **)(p+4),side,0); } return 0; }
