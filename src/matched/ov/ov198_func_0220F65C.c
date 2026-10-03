/*
 * function: func_0220F65C
 * address: 0x0220F65C
 * packet: pkt_ov198_0220F65C
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_0202208C 0x0202208C thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct PrintSys;
extern u32 func_0201C6B4(const struct PrintSys *);
extern void func_0202208C(void *,u32,u32,u32,u32,u32,u32);
int func_0220F65C(u8 *p) { if(func_0201C6B4(*(const struct PrintSys **)(p+0x1eac))==1){func_0202208C((void *)4,1,1,0,6,1,*(u16 *)(*(u8 **)p+16));return 2;}return 1; }
