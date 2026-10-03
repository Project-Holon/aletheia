/*
 * function: func_021FE794
 * address: 0x021FE794
 * packet: pkt_ov186_021FE794
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FED08 0x021FED08 thumb ov186
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_021FED08(u32);
void func_021FE794(char *p,u32 index,u32 a,u32 b,u32 c) { *(u32 *)(p+4)=a; *(u32 *)(p+0x18)=c; *(u32 *)(p+8)=b; *(void **)(p+0x1c)=func_021FED08(index); *(u32 *)p=0; *(u32 *)(p+0xc)=0; }
