/*
 * function: func_021B64B8
 * address: 0x021B64B8
 * packet: pkt_ov101_021B64B8
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3F8 0x0203D3F8 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Entry;
extern struct Entry *func_020399A8(void);
extern u32 func_0203D3F8(u32,u32,u32,u32,u32,u32,u32,u32);
u32 func_021B64B8(u32 p,u32 a,u32 b,u32 c,u8 d,u32 e,u32 f,u32 g) {
    if(*(u32 *)(p+0x78)!=0) return 1;
    return func_0203D3F8((u32)func_020399A8(),d,a,b,c,e,f,g);
}
