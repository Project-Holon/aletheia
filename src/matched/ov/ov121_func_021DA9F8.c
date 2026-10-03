/*
 * function: func_021DA9F8
 * address: 0x021DA9F8
 * packet: pkt_ov121_021DA9F8
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_020257D0 0x020257D0 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_0201C6C4(u32,u32);
extern void func_020257D0(void *);
int func_021DA9F8(u8 *p) { if(*(u32 *)(p+8)) { if(func_0201C6C4(*(u32 *)(p+32),*(u32 *)p)==0) { func_020257D0(*(void **)(p+28)); *(u32 *)(p+8)=0; } } if(*(u32 *)(p+8)==0) return 1; return 0; }
