/*
 * function: func_021B97F8
 * address: 0x021B97F8
 * packet: pkt_ov223_021B97F8
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02048A18 0x02048A18 arm
 *   func_02047A60 0x02047A60 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Arg;extern void *func_02048A18(u8 *,int);extern void func_02047A60(void *,struct Arg *);
void func_021B97F8(char *p) { u16 i;for(i=0;i<*(u16 *)(p+58);i++){char *q=(char *)(*(u32 *)(p+60)+(u32)i*68);if(*(u32 *)(q+64))func_02047A60(func_02048A18(*(u8 **)(p+40),*(u16 *)q),(struct Arg *)(q+4));} }
