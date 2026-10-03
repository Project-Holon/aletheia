/*
 * function: func_021DD570
 * address: 0x021DD570
 * packet: pkt_ov137_021DD570
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02049238 0x02049238 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A5AC 0x0204A5AC arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed short s16;
extern void func_02049238(void *);
extern void func_0204A8D4(u32);
extern void func_0204ADA4(u32);
extern void func_0204AFD8(u32);
extern void func_0204B1CC(void *);
extern void func_0204A5AC(void);
void func_021DD570(u8 *p) {int i;u8 *q;func_02049238(*(void **)(p+52));for(i=0;i<5;i++) {q=(u8 *)((u32)p+i*4);func_0204A8D4(*(u32 *)(q+108));func_0204ADA4(*(u32 *)(q+128));}func_0204AFD8(*(u32 *)(p+148));func_0204B1CC(*(void **)(p+104));func_0204A5AC();}
