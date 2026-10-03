/*
 * function: func_021DC860
 * address: 0x021DC860
 * packet: pkt_ov137_021DC860
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02031324 0x02031324 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 *func_0203159C(void *,u32,u32);
extern void func_02082BCC(void *,int,u32);
extern void *func_02031324(u32);
int func_021DC860(void *obj,int a,u8 *ctx) { u8 *p=func_0203159C(obj,36,4); func_02082BCC(p,0,36); *(u32 *)(p+16)=*(u32 *)(ctx+4); *(void **)(p+8)=ctx; *(void **)(p+32)=func_02031324(1); return 1; }
